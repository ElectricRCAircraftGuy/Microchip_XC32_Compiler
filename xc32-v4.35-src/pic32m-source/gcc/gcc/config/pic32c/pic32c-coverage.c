#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "rtl.h"
#include "tree.h"
#include "backend.h"
#include "memmodel.h" /* MERGE-NOTES: needed before emit-rtl now */
#include "emit-rtl.h"
#include "df.h"
#include "xc-coverage.h"
#include "bversion.h" /* for BUILDING_GCC_MAJOR, BUILDING_GCC_MINOR etc. */


/* these were declared static in arm.c but we need them for the Thumb-1 code
   so they're no longer static there :) */
rtx emit_multi_reg_push (unsigned long mask, unsigned long dwarf_regs_mask);
void arm_emit_multi_reg_pop (unsigned long saved_regs_mask);
/* similarly, this is needed for -fPIC */
void require_pic_register (void);

#define _XSTR(s) _STR(s)
#define _STR(s) #s

/* the path of the cc1 executable */
const char *pic32c_libexec_path = "/lib/gcc/pic32c/"
                                    _XSTR(BUILDING_GCC_MAJOR) "."
                                    _XSTR(BUILDING_GCC_MINOR) "."
                                    _XSTR(BUILDING_GCC_PATCHLEVEL);

/* the register used exclusively by the RTL CC instrumentation code
 * (must be callee-saved and lower (<8) so any of the r4-r7 regs could be used) */
static const unsigned CC_ADDR_REGNO = 4;
/* a temporary/scratch register will also be needed but this is not reserved up-front */
static unsigned CC_TMP1_REGNO = INVALID_REGNUM;
/* Thumb-1 doesn't have ORR with immediate so we could use an extra scratch register */
static unsigned CC_TMP2_REGNO = INVALID_REGNUM;

void
pic32c_reserve_registers (void)
{
  /* reserve the CC_ADDR_REGNO registers */
  /* NOTE: we can't avoid this for 'nocodecov' functions since this is called only once
   *       per compilation unit - current limitation */
  if (mchp_codecov)
    fixed_regs[CC_ADDR_REGNO] = call_used_regs[CC_ADDR_REGNO] = 1;
}

void
pic32c_start_function (tree ATTRIBUTE_UNUSED)
{
  /* all the functions will require the PIC register to access the "cc_bits" var */
  if (mchp_codecov && flag_pic)
    require_pic_register ();
}

/* a hook that is called from the prologue-generating pass, for all targets
   the return value is a mask with the extra registers to be saved */
unsigned
pic32c_init_save_reg_mask (void)
{
  /* only when the code coverage pass will be used */
  if (xccov_enabled ())
    /* the fixed CC_ADDR_REGNO register needs to be saved (callee-saved per ABI) */
    return (1U << CC_ADDR_REGNO);
  /* no extra regs by default */
  return 0U;
}

/* helper for pic32c_adjust_insert_pos() below;
 * returns a reg number or INVALID_REGNUM if no tmp reg was found */
static unsigned
find_unused_tmp_reg (regset live, unsigned skip_regno)
{
  /* the first of the caller-saved regs r0-r3 (and r12 for Thumb2)
   * that doesn't hold a live value */
  for (unsigned regno = (skip_regno == INVALID_REGNUM) ? 0 : (skip_regno + 1),
                end_regno = TARGET_THUMB1 ? 3 : 12;
       regno <= end_regno; ++regno)
    {
      if ((regno <= 3 || regno == 12)
          && (regno != skip_regno)
          && !REGNO_REG_SET_P (live, regno))
        return regno;
    }

  return INVALID_REGNUM; /* no luck */
}

rtx_insn *
pic32c_adjust_insert_pos (basic_block bb,
                          int         prologue_bb,
                          rtx_insn    *where)
{
  rtx_insn *const end = NEXT_INSN (BB_END (bb));

  /* only bother to adjust WHERE when -fPIC and determining the position
   * for the first (containing the prologue) basic block */
  if (flag_pic && prologue_bb) {
    gcc_assert (where && cfun->machine->pic_reg);

    /* look for the the (SET (pic_reg) (UNSPEC [...] UNSPEC_PIC_BASE))
     * (or UNSPEC_PIC_UNIFIED, on unoptimized builds) insn that inits
     * the PIC register */
    for (; /*debug_rtx(where),*/ where != end; where = NEXT_INSN (where))
      if (INSN_P (where) && GET_CODE (PATTERN (where)) == SET)
        {
          rtx src = SET_SRC (PATTERN (where));
          if (GET_CODE (src) == UNSPEC &&
              (XINT (src, 1) == UNSPEC_PIC_BASE
               || XINT (src, 1) == UNSPEC_PIC_UNIFIED))
            {
              rtx dst = SET_DEST (PATTERN (where));
              gcc_assert (REG_P (dst));
              cfun->machine->pic_reg = dst;
              break;
            }
        }

    /* we *should* find it */
    gcc_assert (where != end);

    where = NEXT_INSN (where);
  }

  /* determine the set of regs live at the insert position (before WHERE) */
  regset live = BITMAP_ALLOC (&reg_obstack);
  simulate_backwards_to_point (bb, live, where ? PREV_INSN (where) : BB_END (bb));

  /* look for an unused caller-saved register */
  CC_TMP1_REGNO = find_unused_tmp_reg (live, INVALID_REGNUM);

  /* for Thumb-1 targets (that can benefit from a second scratch register) */
  if (TARGET_THUMB1) {
    /* look for another unused caller-saved register */
    CC_TMP2_REGNO = find_unused_tmp_reg (live, CC_TMP1_REGNO);
  }

  BITMAP_FREE (live);

  /* the instrumentation code will be inserted before the WHERE insn,
   * with the convention to return NULL if the insertion point is AFTER
   * the last insn in the BB */
  return (where != end) ? where : NULL;
}

void
pic32c_ld_cc_bits (unsigned offset)
{
  /* emit the insn that sets register no. CC_ADDR_REGNO to the (cc_bits + offset) value */
  rtx addr_reg = gen_rtx_REG (SImode, CC_ADDR_REGNO);
  rtx cc_bits_ref = gen_rtx_SYMBOL_REF (Pmode, xccov_cc_bits_name ());

  if (flag_pic) {
      /* taken from legitimize_pic_address() in arm.c */
      rtx pat = gen_calculate_pic_address (addr_reg, cfun->machine->pic_reg, cc_bits_ref);

      /* Make the MEM as close to a constant as possible.  */
      rtx mem = SET_SRC (pat);
      gcc_assert (MEM_P (mem) && !MEM_VOLATILE_P (mem));
      MEM_READONLY_P (mem) = 1;
      MEM_NOTRAP_P (mem) = 1;

      /* load the start of 'cc_bits' into reg CC_ADDR_REGNO */
      emit_insn (pat);
      if (offset) {
        emit_insn (gen_addsi3 (addr_reg, addr_reg, GEN_INT (offset)));
      }
  } else {
    cc_bits_ref = plus_constant (SImode, cc_bits_ref, offset);
    cc_bits_ref = force_const_mem (SImode, cc_bits_ref);
    emit_insn (gen_rtx_SET (addr_reg, cc_bits_ref));
  }
}

void
pic32c_set_cc_bit (unsigned bit_no)
{
  rtx CC_ADDR_REG = gen_rtx_REG (SImode, CC_ADDR_REGNO);

  /* use r0 for the first scratch register (if no free register was found) */
  rtx CC_TMP1_REG = gen_rtx_REG (SImode,
                                 (CC_TMP1_REGNO != INVALID_REGNUM) ? CC_TMP1_REGNO
                                                                   : 0);
  /* on Thumb-1, a second scratch register is needed, so either use the free one found
   * or pick one adjacent to the first scratch reg (which should be one of r0-r3) */
  rtx CC_TMP2_REG = NULL_RTX;
  if (TARGET_THUMB1)
    CC_TMP2_REG = gen_rtx_REG (SImode,
                               (CC_TMP2_REGNO != INVALID_REGNUM) ? CC_TMP2_REGNO
                                                                 : (REGNO (CC_TMP1_REG) ^ 1));
  /* which byte of the cc_bits array we'll update */
  unsigned byte_no = bit_no / 8;
  const unsigned bit_mask = 1U << (bit_no & 7);
  unsigned tmp_ofs = 0;

  /* the 16-bit LDR/STR instructions (the only ones available on Thumb-1) use 5-bit
     immediate values for their offsets, so a maximum offset of 31 bytes;
     Thumb-2 is less restrictive: its LDRB.W/STRB.W insns have 12-bit offsets
     so the limitation in this case is 4096*8 = 32768 inst. points per function;
     if not able to access the needed byte directly, we'll (temporarily) offset
     the address in CC_ADDR_REG */
  if (TARGET_THUMB1) {
    if (byte_no > 31) {
      /* 510 is the max imm. value the "*thumb1_addsi3" pattern would accept */
      gcc_assert (byte_no < 510+32);
      /* if the offset can be kept <= 255, that would generate a single ADDS...*/
      if (byte_no < 255+32)
        tmp_ofs = byte_no < 255 ? byte_no : 255;
      else /* (byte_no < 510+32) */
        tmp_ofs = byte_no < 510 ? byte_no : 510;
    }
  }
  else {
    if (byte_no > 4095)
      tmp_ofs = byte_no - 4095;
  }
  byte_no -= tmp_ofs;

  /* emit an ADD if 'tmp_ofs' is used */
  if (tmp_ofs)
    emit_insn (gen_addsi3 (CC_ADDR_REG, CC_ADDR_REG, GEN_INT (tmp_ofs)));

  rtx byte_addr = CC_ADDR_REG;
  if (byte_no) byte_addr = gen_rtx_PLUS (SImode, byte_addr, GEN_INT (byte_no));
  rtx byte_ref = gen_rtx_MEM (QImode, byte_addr);

  /* mark the MEM volatile to prevent a possible move of the load/store insns */
  MEM_VOLATILE_P (byte_ref) = 1;

  /* need to save the temp reg(s)? */
  unsigned save_regs_mask = 0U;

  if (CC_TMP1_REGNO == INVALID_REGNUM)
    save_regs_mask |= 1U << REGNO (CC_TMP1_REG);
  if (TARGET_THUMB1 && CC_TMP2_REGNO == INVALID_REGNUM)
    save_regs_mask |= 1U << REGNO (CC_TMP2_REG);
  if (save_regs_mask)
    emit_multi_reg_push (save_regs_mask, 0);

  /* LDRB r5, [r4, #byte_no] */
  emit_insn (gen_rtx_SET (CC_TMP1_REG, gen_rtx_ZERO_EXTEND (SImode, byte_ref)));

  /* Thumb-1 doesn't have an ORR with an immediate value insn */
  rtx bit_mask_rtx = NULL_RTX;
  if (TARGET_THUMB1) {
    /* so use an extra register to hold the immediate value */
    bit_mask_rtx = CC_TMP2_REG;

    /* load the register with the bit mask i.e. MOVS rX, #imm */
    emit_insn (gen_rtx_SET (bit_mask_rtx, GEN_INT (bit_mask)));
  } else { /* Thumb-2 */
    /* use the immediate value directly */
    bit_mask_rtx = GEN_INT (bit_mask);
  }

  /* ORR r5, r5, #imm/reg */
  emit_insn (gen_iorsi3 (CC_TMP1_REG, CC_TMP1_REG, bit_mask_rtx));

  /* STRB r5, [r4, #byte_no] */
  emit_insn (gen_rtx_SET (byte_ref, gen_lowpart_SUBREG (QImode, CC_TMP1_REG)));

  /* need to restore the temp reg(s)? */
  if (save_regs_mask) {
    arm_emit_multi_reg_pop (save_regs_mask);

    /* XC32-1173: it seems that arm_emit_multi_reg_pop() was intended to be used
     * only for the epilogue code and, based on that, it emits a note that
     * makes a gcc_assert() fail (i.e. internal compiler error) in dwarf2cfi.c;
     * as the debug support for code coverage is not added yet, the simplest
     * way to prevent the ICE is to just remove the note afterwards. */
    rtx_insn *insn = get_last_insn ();
    rtx note = find_reg_note (insn, REG_CFA_ADJUST_CFA, NULL_RTX);
    if (note)
      remove_note (insn, note);
  }

  /* if we offseted the address, restore its value
     TODO: can we eliminate this easily? (most of the time the address isn't used afterwards) */
  if (tmp_ofs)
    emit_insn (gen_addsi3 (CC_ADDR_REG, CC_ADDR_REG, GEN_INT (-(int)tmp_ofs)));
}

/* called at the beginning of the instrumentation of the current function
 * TODO: remove it, if not necessary after all */
void
pic32c_begin_cc_instrument (void)
{
}

void
pic32c_end_cc_instrument (void)
{
  /* arm_reorg() assumes that all the insns were split when optimize != 0
   * which wouldn't be the case for the PIC-related ones that we introduce
   * to access the "cc_bits" variable so we need to call this manually */
  if (flag_pic && optimize) {
    split_all_insns_noflow ();

    /* unfortunately, split_all_insns_noflow () would also delete NOP insns
     * looking like this: (SET (rX) (rX)) without properly updating the BB_END
     * fields (if pointing to such a NOP), so a hot patch is in order here... */
    basic_block bb;
    FOR_EACH_BB_FN (bb, cfun)
      /* if the last insn was (marked as) deleted */
      if (BB_END (bb)->deleted ()) {
        /* pick the previous insn in the chain as BB_END */
        BB_END (bb) = PREV_INSN (BB_END (bb));
        /* and this one should be a valid/non-deleted insn */
        gcc_assert (!BB_END (bb)->deleted ());
      }
  }
}
