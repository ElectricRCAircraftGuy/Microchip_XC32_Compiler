/*
  Optimization pass to reduce the immediate offset value for a sequence of load
  / store instructions that use the [areg, #offset] addressing mode.

  The optimization tries to reduce the immediate offset to be:
  * in range [0..31]  for load / store of 8bit data size
  * in range [0..62]  for load / store of 16bit data size
  * in range [0..124] for load / store of 32bit data size

  When reducing the offset we have to insert a pair of add/sub instructions
  around the sequence of load / store instructions to be optimized to adjust
  the address in the areg register. There are two possible scenarios:
   1. the sequence to be optimized is formed of consecutive instructions that
  have no uses of areg other than [areg, #offset]

      Before:

      ld dreg, [areg, 104]
      ld dreg, [areg, 106]
      . . .
      ld dreg, [areg, 105]

      After:

      add areg,#104
      ld dreg, [areg, 0]
      ld dreg, [areg, 2]
      . . .
      ld dreg, [areg, 1]
      sub areg,#104

      In this case the overhead is ADD_SUB_16b or ADD_16b if the areg has no
  other uses after ld dreg, [areg, 1]

  2. the sequence to be optimized is formed of non-consecutive instructions

      Before:

      ld dreg, [areg, 104]
      ld dreg, [areg, 10]
      ld dreg, [areg, 106]
      . . .
      ld dreg, [areg, 105]

      After:

      add new_areg,areg, #104
      ld dreg, [new_areg, 0]
      ld dreg, [areg,    10]
      ld dreg, [new_areg, 2]
      . . .
      ld dreg, [new_areg, 1]
      sub new_areg,areg, #104

      In this case the overhead is _32b_ADD_SUB or ADD_32b if the new_areg has
  no other uses after ld dreg, [new_areg, 1]

  The current implementation works at basic-block level, but it can be extended
  to work on low-pressure-regions (regions formed by multiple basic blocks were 
  a specific reg is not used)

  // !!!
  //  what if instead of the add/sub pairs, for those cases where
  //  we can replace all old-base-reg references (and the
  //  old-base-reg reference is loaded thru a load pc relative, so
  //  an addresses known at link time is loaded) we do emit a
  //  relocation with addend as seq.off ???
  //  !!!

*/

#define IN_TARGET_CODE 1

#include "config.h"
#define INCLUDE_VECTOR
#define INCLUDE_MAP
#define INCLUDE_ALGORITHM
#include <functional>

#define INCLUDE_SET
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "tree.h"
#include "function.h"
#include "basic-block.h"
#include "tree-pass.h"
#include "rtl.h"
#include "memmodel.h"
#include "emit-rtl.h"
#include "bitmap.h"
#include "cfg.h"
#include "cfgrtl.h"
#include "df.h"
#include "predict.h"

extern void df_simulate_find_defs (rtx_insn *, bitmap);
extern void df_simulate_find_uses (rtx_insn *, bitmap);
extern rtx emit_multi_reg_push (unsigned long, unsigned long);
extern void arm_emit_multi_reg_pop (unsigned long);

static int32_t ri_am_cost (const int32_t offset, const machine_mode mode);
static bool offset_in_range (const int32_t offset, const machine_mode mode);
static int32_t get_overhead_cost (const int32_t omask);
static int32_t min_overhead_cost ();

enum access_type
{
  REG_MEM_LOAD = (1UL) << 0,
  REG_MEM_STORE = (1UL) << 1,
  REG_MEM = (REG_MEM_LOAD | REG_MEM_STORE),
  REG_USE = (1UL) << 2
};

// overhead that has to be added / subtracted around a ri_seq
enum overhead
{
  ADD_16b = (1UL) << 0,
  SUB_16b = (1UL) << 1,
  ADD_32b = (1UL) << 2,
  SUB_32b = (1UL) << 3,
  PUSH_16b = (1UL) << 4,
  POP_16b = (1UL) << 5,
  ST_TO_IP_16b = (1UL) << 6,
  LD_FROM_IP_16b = (1UL) << 7,
  NO_AREG = (1UL) << 8
};

// [areg, #offset] - reg-imm addressing mode
struct ri_am
{
  // used to determine the size of the memory access
  machine_mode mode;
  // used to determine de access type (LOAD, STORE, REG_USE)
  access_type atype;
  // address of the imm (offset) operand
  rtx *off_loc;
  // address of the address-reg (areg) operand
  rtx *areg_loc;
  // data-reg (dreg) operand
  rtx dreg;
  // insn to update
  rtx_insn *insn;

  ri_am (machine_mode mode, access_type atype, rtx *off_loc, rtx *areg_loc,
         rtx dreg, rtx_insn *insn)
      : mode (mode), atype (atype), off_loc (off_loc), areg_loc (areg_loc),
        dreg (dreg), insn (insn)
  {
    if (dump_file)
      {
        char ch_mode = ((mode == QImode) ? 'B' : (mode == HImode) ? 'H' : 'W');
        if (atype & REG_MEM)
          {
            char ch_atype = (atype == REG_MEM_LOAD) ? 'L' : 'S';
            char star = ' ';

            if ((ri_am_cost ((int32_t)INTVAL (*off_loc), mode)) == 2)
              {
                if (REGNO (dreg) <= 7)
                  star = '*';
              }
            fprintf (
                dump_file,
                "\t[%c][r%-4d][BB=%-4d][I UID=%-4d][.%c] offset=%-4d [%c]\n",
                ch_atype, REGNO (*areg_loc), BLOCK_FOR_INSN (insn)->index,
                INSN_UID (insn), ch_mode, (int32_t)INTVAL (*off_loc), star);
          }
        else
          fprintf (dump_file,
                   "\t[%c][%-5c][BB=%-4d][I UID=%-4d][.%c] offset=%-4c [%c]\n",
                   'O', '-', BLOCK_FOR_INSN (insn)->index, INSN_UID (insn),
                   ch_mode, '-', '-');
      }
  }

  int32_t
  get_offset ()
  {
    return (int32_t)INTVAL (*off_loc);
  }
};

template <int v> struct Int2Type
{
  enum
  {
    value = v
  };
};

typedef Int2Type<true> CanUseNewAreg;
typedef Int2Type<false> DoNotUseNewAreg;

static std::vector<ri_am> maccess;

// sequence of ri_am instructions that can be optimized (all sharing the same
// areg)
struct ri_seq
{
  int8_t areg;
  int32_t off;
  int32_t omask;
  int32_t gain;
  bitmap insn_id;

  void find_longest_seq (CanUseNewAreg);
  void find_longest_seq (DoNotUseNewAreg);
  void compute_overhead_and_update_gain (CanUseNewAreg);
  void compute_overhead_and_update_gain (DoNotUseNewAreg);

  ri_seq (int8_t areg, int32_t off = -1)
  {
    this->areg = areg;
    this->off = off;
    this->gain = 0;
    this->insn_id = BITMAP_ALLOC (NULL);
  }
  ~ri_seq () { BITMAP_FREE (insn_id); }

  ri_seq &
  operator= (const ri_seq &seq)
  {
    areg = seq.areg;
    off = seq.off;
    omask = seq.omask;
    gain = seq.gain;
    bitmap_clear (insn_id);
    bitmap_copy (insn_id, seq.insn_id);
    return *this;
  }

  rtx_insn *
  first_insn_in_seq ()
  {
    unsigned idx = bitmap_first_set_bit (insn_id);
    gcc_assert (idx < maccess.size ());
    return maccess[idx].insn;
  }

  rtx_insn *
  last_insn_in_seq ()
  {
    unsigned idx = bitmap_last_set_bit (insn_id);
    gcc_assert (idx < maccess.size ());
    return maccess[idx].insn;
  }

  int32_t
  new_offset_cost (ri_am &macces)
  {
    int32_t old_cost = ri_am_cost (macces.get_offset (), macces.mode);
    int32_t new_cost = ri_am_cost ((macces.get_offset () - off), macces.mode);
    if ((REGNO (macces.dreg) <= 7))
      {
        if ((old_cost == 2) && (new_cost == 1))
          return 1;
        if ((old_cost == 1) && (new_cost == 2))
          return -1;
      }
    return 0;
  }

  void
  align_offset ()
  {
    if (off & 0x3)
      {
        unsigned start = bitmap_first_set_bit (insn_id);
        unsigned end = bitmap_last_set_bit (insn_id);
        for (unsigned idx = start; idx <= end; ++idx)
          {
            if (!bitmap_bit_p (insn_id, idx))
              continue;
            // w_correction_needed
            if ((maccess[idx].mode == SImode) && (off & 0x3))
              off = off & ~(0x3); // we can break here :)
            // h_correction_needed
            if ((maccess[idx].mode == HImode) && (off & 0x1))
              off = off & ~(0x1);
          }
        // after seq.off is aligned we might endup with an invalid ri_am
        start = bitmap_first_set_bit (insn_id);
        for (unsigned idx = start; idx <= end; ++idx)
          {
            if (!bitmap_bit_p (insn_id, idx))
              continue;
            if (offset_in_range (maccess[idx].get_offset () - off,
                                 maccess[idx].mode))
              continue;
            // find an invalid off: update the gain and bail out
            gain -= get_overhead_cost (NO_AREG);
            break;
          }
      }
  }

  void
  print_seq ()
  {
    if (dump_file)
      {
        fprintf (dump_file, "[r%d, #%d]\n", areg, off);
        fprintf (dump_file, "Overhead-mask      = 0x%x\n", omask);
        fprintf (dump_file, "Overhead-cost      = %d\n",
                 get_overhead_cost (omask));
        fprintf (dump_file, "Gain               = %d\n", gain);

        fprintf (dump_file, "Insns to be updated=[");
        for (unsigned idx = 0; idx < maccess.size (); ++idx)
          {
            if (bitmap_bit_p (insn_id, idx))
              fprintf (dump_file, "%-4d ", INSN_UID (maccess[idx].insn));
          }
        fprintf (dump_file, "]\n");

        fprintf (dump_file, "Imm   to be updated=[");
        for (unsigned idx = 0; idx < maccess.size (); ++idx)
          {
            if (bitmap_bit_p (insn_id, idx))
              fprintf (dump_file, "%-4d ", maccess[idx].get_offset ());
          }
        fprintf (dump_file, "]\n\n");
      }
  }
};

static bool
offset_in_range (const int32_t offset, const machine_mode mode)
{
  if (mode == SImode)
    return ((-252 <= offset) && (offset <= 4092)) ? 1 : 0;
  else if (mode == HImode)
    return ((-254 <= offset) && (offset <= 4094)) ? 1 : 0;
  else if (mode == QImode)
    return ((-255 <= offset) && (offset <= 4095)) ? 1 : 0;

  gcc_assert (0 && "Invalid memory access size");
}

// the cost represents the number of bytes needed to encode the offset constant
static int32_t
ri_am_cost (const int32_t offset, const machine_mode mode)
{
  gcc_assert ((-255 <= offset) && (offset <= 4095));
  // 32-bit word
  if (mode == SImode)
    return ((0 <= offset) && (offset <= 124)) ? 1 : 2;
  // 16-bit halfword
  else if (mode == HImode)
    return ((0 <= offset) && (offset <= 62)) ? 1 : 2;
  // 8-bit byte
  else if (mode == QImode)
    return ((0 <= offset) && (offset <= 31)) ? 1 : 2;

  gcc_assert (0 && "Invalid memory access size");
}

// the cost represents the number of bytes needed to encode the instruction(s)
//  that have to be inserted around a ri_seq
static int32_t
get_overhead_cost (const int32_t omask)
{
  int32_t cost = 0;

  if (omask & ADD_16b)
    {
      gcc_assert (!(omask & (ADD_32b | SUB_32b | NO_AREG)));
      cost += 1;
    }
  if (omask & SUB_16b)
    {
      gcc_assert (!(omask & (ADD_32b | SUB_32b | NO_AREG)));
      cost += 1;
    }
  if (omask & ADD_32b)
    {
      gcc_assert (!(omask & (ADD_16b | SUB_16b | NO_AREG)));
      cost += 2;
    }
  if (omask & SUB_32b)
    {
      gcc_assert (!(omask & (ADD_16b | SUB_16b | NO_AREG)));
      cost += 2;
    }
  if (omask & PUSH_16b)
    {
      gcc_assert (omask & POP_16b);
      gcc_assert (!(omask & (NO_AREG)));
      cost += 2; // PUSH + POP
    }
  if (omask & ST_TO_IP_16b)
    {
      gcc_assert (omask & LD_FROM_IP_16b);
      gcc_assert (!(omask & (NO_AREG)));
      cost += 2; // ST + LD
    }
  if (omask & NO_AREG)
    cost = 0x7FFFFFFF;

  return cost;
}

static int32_t
min_overhead_cost ()
{
  return get_overhead_cost (ADD_16b);
}

// the <reg> register is considered dead after <after> insn if:
//
//  (1) <after> insn defines <reg> reg
//
//  (2) there is a <def> of <reg> that follows <after> insn:
//    no uses of <reg> are between <after> insn and this <def> of <reg>
//
//  (3) there is no definition of <reg> that follows <after> insn:
//    no uses of <reg> are between <after> and the last insn in current BB
//    the <reg> is not live_out in current BB (has uses outside of this BB)
static bool
reg_is_dead (const int8_t reg, rtx_insn *after)
{
  basic_block bb = BLOCK_FOR_INSN (after);

  if (df_reg_defined (after, gen_rtx_REG (SImode, reg)))
    return true;

  if (after == BB_END (bb))
    return (!bitmap_bit_p (df_get_live_out (bb), reg));

  rtx_insn *last_def_in_bb = NULL;
  rtx_insn *last_insn = NULL;
  bitmap bmap = BITMAP_ALLOC (NULL);

  df_ref x = df_bb_regno_last_def_find (bb, reg);
  if (x && DF_INSN_LUID (DF_REF_INSN (x)) > DF_INSN_LUID (after))
    last_def_in_bb = DF_REF_INSN (x);
  last_insn = last_def_in_bb ? last_def_in_bb : BB_END (bb);

  for (rtx_insn *it = NEXT_INSN (after);; it = NEXT_INSN (it))
    {
      if (it && NONDEBUG_INSN_P (it))
        {
          gcc_assert (BLOCK_FOR_INSN (it) == bb);
          df_simulate_find_uses (it, bmap);
        }
      if (it == last_insn)
        break;
    }

  int reg_used_between = bitmap_bit_p (bmap, reg);
  BITMAP_FREE (bmap);

  // reg is used between [after..last_def] => reg is not dead
  if (reg_used_between)
    return 0;

  return (last_def_in_bb) ? 1 : (!bitmap_bit_p (df_get_live_out (bb), reg));
}

// check if mpat is of the form [areg, #imm]
static bool
is_ri_mem_pattern (const_rtx mpat, machine_mode &mode, rtx *&off_loc,
                   rtx *&areg_loc)
{
  if (GET_CODE (mpat) == MEM)
    {
      if ((GET_CODE (XEXP (mpat, 0)) == PLUS))
        {
          rtx plus = XEXP (mpat, 0);
          if (REG_P (XEXP (plus, 0)) && CONST_INT_P (XEXP (plus, 1)))
            {
              off_loc = &(XEXP (plus, 1));
              areg_loc = &(XEXP (plus, 0));
              mode = GET_MODE (mpat);
              return true;
            }
        }
      else if (REG_P (XEXP (mpat, 0)))
        return false;
    }

  const char *fmt = GET_RTX_FORMAT (GET_CODE (mpat));
  for (int i = 0; i < GET_RTX_LENGTH (GET_CODE (mpat)); i++, fmt++)
    {
      if (*fmt == 'e')
        {
          if (is_ri_mem_pattern (XEXP (mpat, i), mode, off_loc, areg_loc))
            return 1;
        }
      else if (*fmt == 'E')
        {
          for (int j = 0; j < XVECLEN (mpat, i); j++)
            if (is_ri_mem_pattern (XVECEXP (mpat, i, j), mode, off_loc,
                                   areg_loc))
              return 1;
        }
    }

  return false;
}

// check if pat is a reg operand
static bool
is_r_pattern (rtx pat, rtx &rloc)
{
  if (REG_P (pat))
    {
      rloc = pat;
      return true;
    }
  else if (GET_CODE (pat) == UNSPEC)
    {
      uint8_t unalligned_ld_st = false;
      unalligned_ld_st |= (XINT (pat, 1) == UNSPEC_UNALIGNED_LOAD);
      unalligned_ld_st |= (XINT (pat, 1) == UNSPEC_UNALIGNED_STORE);

      if (!unalligned_ld_st)
        return false;

      gcc_assert (XVECLEN (pat, 0) == 1);
      gcc_assert (REG_P (XVECEXP (pat, 0, 0)));
      rloc = XVECEXP (pat, 0, 0);
      return true;
    }

  return false;
}

static void
analyze_use (df_ref ref, access_type &atype, rtx &dreg, rtx *&areg_loc,
             rtx *&off_loc, machine_mode &mode, int32_t &gain)
{
  atype = REG_USE;

  if (DF_REF_REG_MEM_P (ref))
    {
      rtx pat;
      if (!(pat = single_set (DF_REF_INSN (ref))))
        return;

      if (DF_REF_REG_MEM_LOAD_P (ref))
        {
          if (!is_ri_mem_pattern (XEXP (pat, 1), mode, off_loc, areg_loc))
            return;
          if (!is_r_pattern (XEXP (pat, 0), dreg))
            return;
          atype = REG_MEM_LOAD;
        }
      else
        {
          gcc_assert (DF_REF_REG_MEM_STORE_P (ref));
          if (!is_ri_mem_pattern (XEXP (pat, 0), mode, off_loc, areg_loc))
            return;
          if (!is_r_pattern (XEXP (pat, 1), dreg))
            return;
          atype = REG_MEM_STORE;
        }
      // consider just the .B, .H and .W mem-accesses
      if ((SImode != mode) && (HImode != mode) && (QImode != mode))
        atype = REG_USE;
      // let's ignore .H mem-accesses to odd_imm_offset
      if ((mode == HImode) && (INTVAL (*off_loc) & 0x1))
        atype = REG_USE;
      // let's ignore .W mem-accesses to odd_imm_offset
      if ((mode == SImode) && (INTVAL (*off_loc) & 0x3))
        atype = REG_USE;
      if (atype & REG_MEM)
        {
          if ((ri_am_cost ((int32_t)INTVAL (*off_loc), mode)) == 2)
            {
              if (REGNO (dreg) <= 7)
                gain += 1;
            }
        }
      gcc_assert (*areg_loc == *DF_REF_LOC (ref));
    }
}

// find the overhead (insn) that will have to be inserted around ri_seq
void ri_seq::compute_overhead_and_update_gain (DoNotUseNewAreg)
{
  // ADDS <Rdn>,#<imm8>
  bool _16b_encoding = ((0 <= off) && (off <= 255));
  if (reg_is_dead (areg, last_insn_in_seq ()))
    omask = _16b_encoding ? ADD_16b : ADD_32b;
  else
    omask = _16b_encoding ? (ADD_16b | SUB_16b) : (ADD_32b | SUB_32b);

  gain -= get_overhead_cost (omask);
}

void ri_seq::compute_overhead_and_update_gain (CanUseNewAreg)
{
  bitmap bmap = BITMAP_ALLOC (NULL);
  bitmap_clear (bmap);

  for (rtx_insn *it = first_insn_in_seq ();; it = NEXT_INSN (it))
    {
      if (it && NONDEBUG_INSN_P (it))
        {
          df_simulate_find_defs (it, bmap);
          df_simulate_find_uses (it, bmap);
        }
      if (it == last_insn_in_seq ())
        break;
    }

  omask = NO_AREG;
  // ADDS <Rd>,<Rn>,#<imm3>
  bool _16b_encoding = ((0 <= off) && (off <= 7));
  for (int regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
    {
      // [r0..r3] registers are caller saved: we can modify these without
      // having to save/restore them.
      //
      // [r4..r7] registers are callee saved: we have to PUSH / POP them
      //  around seq
      bool caller_saved = ((0 <= regno) && (regno <= 3));

      if (bitmap_bit_p (bmap, regno))
        continue;
      gcc_assert (regno != areg);

      areg = regno;
      if (reg_is_dead (regno, last_insn_in_seq ()) && caller_saved)
        {
          omask = _16b_encoding ? ADD_16b : ADD_32b;
          // there is no overhead to be found with a smaller-cost
          break;
        }
      else
        {
          /*
            Even if the SP register is not used directly by some load/store insns, 
            it is not safe to assume that the load/store insns are not using any 
            stack memory

              void test_pinit(int *p, int cond)
              {
                  int arr1[256];

                  if (cond)
                    p = arr1;
                  // NOT SAFE TO INSERT PUSH/POP insn around these store insns.
                  p[200] = 0xABCDABCD;
                  p[201] = 0xCDEFCDEF;
                  p[202] = 0xEFABEFAB;
              }
           */
          #define PUSH_POP_INSNS_UNSAFE 1
          // PUSH & POP instructions will alter the SP
          if (!bitmap_bit_p (bmap, SP_REGNUM) && !PUSH_POP_INSNS_UNSAFE)
            {
              // we should check if the only use is the POP insn from epilogue
              // if this is the case we have to update the PUSH & POP insns
              // from prologue and epilogue bbs
              omask = PUSH_16b | POP_16b;
              omask |= _16b_encoding ? ADD_16b : ADD_32b;
            }
          // if the R12 (IP) register is unused, then we can use this to
          // temporary save the new areg register
          else if (!bitmap_bit_p (bmap, IP_REGNUM) && reg_is_dead (IP_REGNUM, last_insn_in_seq ()))
            {
              omask = ST_TO_IP_16b | LD_FROM_IP_16b;
              omask |= _16b_encoding ? ADD_16b : ADD_32b;
            }
        }
    }
  BITMAP_FREE (bmap);

  gain -= get_overhead_cost (omask);
}

//  For the accesses below
//
//    ld dreg, [areg, 102]
//    ld dreg, [areg, 100]
//    use areg
//    ld dreg, [areg, 104]
//    ld dreg, [areg, 105]
//    ld dreg, [areg, 106]
//    use areg
//    ld dreg, [areg, 101]
//
//  find_longest_seq(CanUseNewAreg) will return the sequence
//    [102, 100, 104, 105, 106, 101]
//  this sequence will have to 'allocate' a new areg to opt the mem accesses
//  (if there is a free register to be allocated)
void
ri_seq::find_longest_seq (CanUseNewAreg dummy)
{
  // areg changes during compute_overhead_and_update_gain
  int8_t regno = this->areg;

  for (unsigned i = 0; i < maccess.size (); i++)
    {
      if (!(maccess[i].atype & REG_MEM))
        continue;
      gcc_assert (offset_in_range (maccess[i].get_offset (), maccess[i].mode));
      ri_seq tmp (regno, maccess[i].get_offset ());
      for (unsigned j = 0; j < maccess.size (); j++)
        {
          if (!(maccess[j].atype & REG_MEM))
            continue;
          if (!offset_in_range (maccess[j].get_offset () - tmp.off,
                                maccess[j].mode))
            continue;
          if (tmp.new_offset_cost (maccess[j]) > 0)
            {
              tmp.gain += 1;
              bitmap_set_bit (tmp.insn_id, j);
            }
        }
      if (!tmp.gain)
        continue;
      tmp.align_offset ();
      tmp.compute_overhead_and_update_gain (dummy);
      if (tmp.gain > this->gain)
        *this = tmp;
    }
}

//  For the accesses below
//
//    ld dreg, [areg, 102]
//    ld dreg, [areg, 100]
//    use areg
//    ld dreg, [areg, 104]
//    ld dreg, [areg, 105]
//    ld dreg, [areg, 106]
//    use areg
//    ld dreg, [areg, 101]
//
//  find_longest_seq(CanUseNewAreg) will return the sequence
//    [104, 105, 106]
//  this sequence will use the current areg to opt the mem accesses
//
//  This is similar to kandane alg to find the largest sum for a contiguous
//  subarray
void
ri_seq::find_longest_seq (DoNotUseNewAreg dummy)
{
  for (unsigned i = 0, jstart = 0; i < maccess.size (); i++)
    {
      if (!(maccess[i].atype & REG_MEM))
        {
          jstart = i + 1; // jump over non-reg-mem insns
          continue;
        }
      gcc_assert (offset_in_range (maccess[i].get_offset (), maccess[i].mode));
      ri_seq tmp (this->areg, maccess[i].get_offset ());
      int32_t max_gain = 0;
      unsigned left = 0, right = 0;
      for (unsigned j = jstart, seq_start = jstart; j < maccess.size (); j++)
        {
          if (!(maccess[j].atype & REG_MEM))
            break;
          if (!offset_in_range (maccess[j].get_offset () - tmp.off,
                                maccess[j].mode))
            break;
          int32_t cost = tmp.new_offset_cost (maccess[j]);
          max_gain += cost;
          if (max_gain <= cost)
            {
              max_gain = cost; // start a new sequence
              seq_start = j;
            }
          if (tmp.gain < max_gain)
            {
              left = seq_start;
              right = j;
              tmp.gain = max_gain;
            }
        }
      if (!tmp.gain)
        continue;
      gcc_assert (bitmap_empty_p (tmp.insn_id));
      for (unsigned idx = left; idx <= right; ++idx)
        bitmap_set_bit (tmp.insn_id, idx);
      tmp.align_offset ();
      tmp.compute_overhead_and_update_gain (dummy);
      if (tmp.gain > this->gain)
        *this = tmp;
    }
}

// Find a constant value to be added/substracted from seq.areg in such a way
// that
//  as many as possible of the ri_am memory accesses will use a smaller offset
bool
find_seq_to_optimize (int8_t regno)
{

  if (dump_file)
    fprintf (dump_file, "Check For Sequence To Optimize\n");

  ri_seq seq (regno);
  seq.find_longest_seq (Int2Type<false> ());
  seq.find_longest_seq (Int2Type<true> ());

  if (!(seq.gain > min_overhead_cost ()))
    return 0;

  seq.print_seq ();

  rtx rtx_old_areg = gen_rtx_REG (SImode, regno);
  rtx rtx_new_areg = gen_rtx_REG (SImode, seq.areg);
  rtx rtx_off;
  unsigned push_pop_mask = (1U << (seq.areg));

  // Sequence prologue
  // [ PUSH {areg} ]
  if (seq.omask & PUSH_16b)
    {
      gcc_assert (seq.omask & POP_16b);
      start_sequence ();
      emit_multi_reg_push (push_pop_mask, 0);
      rtx_insn *insns = get_insns ();
      end_sequence ();
      emit_insn_before (insns, seq.first_insn_in_seq ());
    }
  if (seq.omask & ST_TO_IP_16b)
    {
      gcc_assert (seq.omask & LD_FROM_IP_16b);
      start_sequence ();
      emit_insn (gen_rtx_SET (gen_rtx_REG (SImode, IP_REGNUM), rtx_new_areg));
      rtx_insn *insns = get_insns ();
      end_sequence ();
      emit_insn_before (insns, seq.first_insn_in_seq ());
    }
  // ADD areg, regno, #off
  rtx_off = gen_int_mode (seq.off, SImode);
  start_sequence ();
  emit_insn (gen_rtx_SET (rtx_new_areg,
                          gen_rtx_PLUS (SImode, rtx_old_areg, rtx_off)));
  rtx_insn *insns = get_insns ();
  end_sequence ();
  emit_insn_before (insns, seq.first_insn_in_seq ());

  // Sequence epilogue
  if (seq.omask & (SUB_16b | SUB_32b))
    {
      // [ ADD areg, #-off ]
      rtx_off = gen_int_mode (-seq.off, SImode);
      start_sequence ();
      emit_insn (gen_rtx_SET (rtx_new_areg,
                              gen_rtx_PLUS (SImode, rtx_old_areg, rtx_off)));
      rtx_insn *insns = get_insns ();
      end_sequence ();
      emit_insn_after (insns, seq.last_insn_in_seq ());
    }
  // [ POP {areg} ]
  else if (seq.omask & POP_16b)
    {
      start_sequence ();
      arm_emit_multi_reg_pop (push_pop_mask);
      rtx_insn *insns = get_insns ();
      end_sequence ();
      emit_insn_after (insns, seq.last_insn_in_seq ());
    }
  else if (seq.omask & LD_FROM_IP_16b)
    {
      start_sequence ();
      emit_insn (gen_rtx_SET (rtx_new_areg, gen_rtx_REG (SImode, IP_REGNUM)));
      rtx_insn *insns = get_insns ();
      end_sequence ();
      emit_insn_after (insns, seq.last_insn_in_seq ());
    }

  // Update [areg, #off]
  unsigned start = bitmap_first_set_bit (seq.insn_id);
  unsigned end = bitmap_last_set_bit (seq.insn_id);
  for (unsigned idx = start; idx <= end; ++idx)
    {
      if (!bitmap_bit_p (seq.insn_id, idx))
        continue;
      rtx_off = gen_int_mode (maccess[idx].get_offset () - seq.off, SImode);
      // check the alignment
      if (maccess[idx].mode == SImode)
        gcc_assert ((INTVAL (rtx_off) & 0x3) == 0);
      else if (maccess[idx].mode == HImode)
        gcc_assert ((INTVAL (rtx_off) & 0x1) == 0);
      *maccess[idx].off_loc = rtx_off;
      *maccess[idx].areg_loc = rtx_new_areg;
    }

  return 1;
}

// make sure the LUIDs are allocated in increasing order
static void
sanity_check (basic_block bb)
{
  rtx_insn *insn;
  int32_t prev_luid = -1;

  FOR_BB_INSNS (bb, insn)
  {
    if (!NONDEBUG_INSN_P (insn))
      continue;
    if (prev_luid != -1)
      gcc_assert (DF_INSN_LUID (insn) > prev_luid);
    prev_luid = DF_INSN_LUID (insn);
  }
}

struct ri_df_ref
{
  df_ref du_ref;
  bool is_def;

  ri_df_ref (df_ref du_ref, bool is_def) : du_ref (du_ref), is_def (is_def) {}
};

struct less_than_key
{
  inline bool
  operator() (const ri_df_ref left, const ri_df_ref right)
  {
    int32_t lluid = DF_INSN_LUID (DF_REF_INSN (left.du_ref));
    int32_t rluid = DF_INSN_LUID (DF_REF_INSN (right.du_ref));

    if ((lluid == rluid) && ((left.is_def != right.is_def)))
      return (!left.is_def);

    return lluid < rluid;
  }
};

static bool
find_mem_accesses_to_optimize (int regno)
{
  typedef std::vector<ri_df_ref> ud_lst_t;
  typedef std::map<basic_block, ud_lst_t> bb_defs_uses_t;
  static df_ref_d MARKER_SEQ_END;
  bb_defs_uses_t bb_df_refs;

  // for each reg-def
  for (df_ref ref = DF_REG_DEF_CHAIN (regno); ref; ref = DF_REF_NEXT_REG (ref))
    {
      if (DF_REF_IS_ARTIFICIAL (ref))
        continue;
      if (!NONDEBUG_INSN_P (DF_REF_INSN (ref)))
        continue;
      bb_df_refs[DF_REF_BB (ref)].push_back (ri_df_ref (ref, 1));
    }

  // for each reg-use
  for (df_ref ref = DF_REG_USE_CHAIN (regno); ref; ref = DF_REF_NEXT_REG (ref))
    {
      if (DF_REF_IS_ARTIFICIAL (ref))
        continue;
      if (!NONDEBUG_INSN_P (DF_REF_INSN (ref)))
        continue;
      bb_df_refs[DF_REF_BB (ref)].push_back (ri_df_ref (ref, 0));
    }

  // order reg-uses/reg-defs
  for (bb_defs_uses_t::iterator it = bb_df_refs.begin ();
       it != bb_df_refs.end (); ++it)
    {
      sanity_check ((*it).first);
      ud_lst_t &ud_lst = (*it).second;
      std::sort (ud_lst.begin (), ud_lst.end (), less_than_key ());
      ud_lst.push_back (ri_df_ref (&MARKER_SEQ_END, 1));
    }

  int32_t gain = 0;
  bool opt = false;

  // optimize all uses between two defs
  for (bb_defs_uses_t::iterator it = bb_df_refs.begin ();
       it != bb_df_refs.end (); ++it)
    {
      ud_lst_t &ud_lst = (*it).second;
      // needed to recompute LUIDs
      bool seq_found = false;

      for (ud_lst_t::iterator use = ud_lst.begin (); use != ud_lst.end ();
           ++use)
        {

          if ((*use).is_def)
            {
              if (gain > min_overhead_cost ())
                seq_found |= find_seq_to_optimize (regno);
              maccess.clear ();
              gain = 0;
              continue;
            }

          rtx *off_loc = NULL, *areg_loc = NULL;
          rtx dreg = NULL;
          machine_mode mode;
          access_type atype;

          analyze_use ((*use).du_ref, atype, dreg, areg_loc, off_loc, mode,
                       gain);
          maccess.push_back (ri_am (mode, atype, off_loc, areg_loc, dreg,
                                    DF_REF_INSN ((*use).du_ref)));
        }

      if (seq_found)
        df_recompute_luids ((*it).first);
      opt |= seq_found;
    }

  return opt;
}

void
offset_addressing ()
{
  const int n_max_iterations = 5;

  /* Dataflow analysis for use-def chains.  */
  df_set_flags (DF_RD_PRUNE_DEAD_DEFS);
  df_chain_add_problem (DF_UD_CHAIN + DF_DU_CHAIN);
  df_analyze ();
  df_set_flags (DF_DEFER_INSN_RESCAN);

  basic_block bb;
  FOR_EACH_BB_FN (bb, cfun) { df_recompute_luids (bb); }

  for (int regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
    {
      /* Depending on how far away the imm-offsets are it is possible to
        have multiple solutions within a BB.
        Limit the number of searches (solutions) to n_max_iterations.
       */
      for (int it = 0; it < n_max_iterations; ++it)
        {
          if (!find_mem_accesses_to_optimize (regno))
            break;
          /* Rebuild ud- and du-chains.  */
          df_remove_problem (df_chain);
          df_process_deferred_rescans ();

          df_set_flags (DF_RD_PRUNE_DEAD_DEFS);
          df_chain_add_problem (DF_DU_CHAIN | DF_UD_CHAIN);
          df_analyze ();
          df_set_flags (DF_DEFER_INSN_RESCAN);
        }
    }

  df_finish_pass (true);
  df_scan_alloc (NULL);
  df_scan_blocks ();
}

namespace
{

const pass_data pass_data_opt_base_reg_offset = {
  RTL_PASS,         /* type */
  "opt_imm_offset", /* name */
  OPTGROUP_NONE,    /* optinfo_flags */
  TV_FWPROP,        /* tv_id */
  0,                /* properties_required */
  0,                /* properties_provided */
  0,                /* properties_destroyed */
  0,                /* todo_flags_start */
  ( TODO_df_verify | TODO_df_finish ),   /* todo_flags_finish */
};

class pass_opt_imm_offset : public rtl_opt_pass
{
public:
  pass_opt_imm_offset (gcc::context *ctxt)
      : rtl_opt_pass (pass_data_opt_base_reg_offset, ctxt)
  {
  }

  /* opt_pass methods: */
  virtual bool
  gate (function *)
  {
    return opt_imm_offset && TARGET_THUMB
           && optimize_function_for_size_p (cfun);
  }

  virtual unsigned int
  execute (function *)
  {
    offset_addressing ();
    return false;
  }

}; // class pass_opt_imm_offset

} // anon namespace

rtl_opt_pass *
make_pass_opt_imm_offset (gcc::context *ctxt)
{
  return new pass_opt_imm_offset (ctxt);
}
