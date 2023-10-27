/* Subroutines used for Microchip PIC32C code generation.
   Copyright (C) 1989, 1990, 1991, 1993, 1994, 1995, 1996, 1997, 1998,
   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#define INCLUDE_LIST
#define INCLUDE_SET
#define INCLUDE_MAP
#define INCLUDE_ALGORITHM
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "df.h"
#include "insn-config.h"
#include "recog.h"
#include "tree-pass.h"
#include "cfgloop.h"
#include "dumpfile.h"
#include "cfgrtl.h"
#include "cfghooks.h"
#include "print-rtl.h"

/*
  Loop register renaming optimization

  LO-register - register in range [r0..r7]
  HI-register - register in range [r8..r15]
  In-loop register - register referenced (used or defined) in a loop

  Replace all uses and defines of an in-loop hi-register with an unused-in-loop
    lo-register. The lo-register is saved / restored around the loop (saved in
    the loop preheader and restored in each exit basic block)

  The renaming is done just for those lo-regs that
    * are not callee saved (registers in range [r0..r4])
    * are callee saved (registers in range [r5..r7]) and referenced in the
      cfun => are pushed / popped in the function prologue / epilogue. Trashing
      an "r5" register for example ,that has no uses & defines in the cfun,
      means that additional  push / pop instructions have to be inserted in the
      function prologue / epilogue. But at this point the stack-offsets
      (for the local variables) have already been computed, so any additional
      register pushed into stack will lead to invalid stack location accesses.

  The renaming is done just for those hi-regs that
    * are not live-out in the loop-preheader: there are no definitions outside
      of the loop that reach an use inside the loop.

        Def-r9 (d1)
          |
          V
        Use-r9 (u1) <-
        Def-r9 (d2)  |
        Use-r9 (u2)  |
          |----------^

    * are not live-in in the loop-exit basic block: there are no definitions
      inside the loop that reach an use outside the loop.


        Def-r9 (d1)  <-
        Use-r9 (u1)  |
          |----------^
        Use-r9 (u2)

    After renaming all uses & defs of an hi-reg inside the loop:
      * a "move hi-reg, lo-reg" (save lo-reg into hi-reg) instruction
        is inserted in the loop-preheader bb.
      * a "move lo-reg, hi-reg" (restore lo-reg from hi-reg) instruction is
        inserted in each loop exit basic block. If an exit basic block has no
        loop related incoming edges (e.g function-BB -> loop-exit-bb-2 edge),
        then a new basic block has to be created to restore the lo-register.

                      function-BB
                        Def-r0
                          |
                          |-----------------V
                          V                 |
                      loop-preheader        |
                          |                 |
                          V                 |
                      loop-header <---      |
                        Def-r5 (d1)   ^     |
                          |           |     |
                          V           |     |
                      loop-body-bb1   |     |
                        Use-r5 (u1)   |     |
                        Def-r5 (d2)   |     |
                          |           |     |
loop-exit-bb-1<-----------|           |     |
 Use-r0                   V           |     |
                      loop-body-bb2   |     |
                        Use-r5 (u2)   |     |
                          |           |     |
                          |-----------^     |
                          |                 |
                          V                 V
                      loop-exit-bb-2 <-------
                        Use-r0



                      function-BB
                          Def-r0
                          |-----------------V
                          V                 |
                      loop-preheader        |
                        mov r5,r0           |
                          |                 |
                          V                 |
                      loop-header <---      |
                        Def-r0 (d1)   ^     |
                          |           |     |
                          V           |     |
                      loop-body-bb1   |     |
                        Use-r0 (u1)   |     |
                        Def-r0 (d2)   |     |
                          |           |     |
loop-exit-bb-1<-----------|           |     |
  mov r0, r5              |           |     |
  Use-r0                  V           |     |
                      loop-body-bb2   |     |
                        Use-r0 (u2)   |     |
                          |           |     |
                          |-----------^     |
                          |                 |
                        new-exit-bb         |
                          mov r0, r5        |
                          |                 |
                          |                 |
                          V                 V
                      loop-exit-bb-2 <-------
                        Use-r0

 */

#define AUTODETECT_VALUE 2

bool callee_saved_reg_p (unsigned int reg);

class LowPressureLoop
{
public:
  LowPressureLoop (const struct loop *loop)
  {
    this->loop = loop;
    this->loop_with_complex_edge = false;
    loop_preheader ();
    loop_exit_bbs ();
  }

  std::set<basic_block> &
  get_loop_exit_bbs ()
  {
    return exit_bbs;
  }

  std::list<unsigned> &
  get_lo_regs ()
  {
    return lo_regs;
  }

  std::list<std::pair<unsigned, unsigned> > &
  get_hi_regs ()
  {
    return hi_regs;
  }

  bool
  loop_with_complex_edge_p ()
  {
    return loop_with_complex_edge;
  }

  void
  log ()
  {
    fprintf (dump_file, "\t[LPL]Low Pressure Loop (loop.id %d)\n", loop->num);

    fprintf (dump_file, "\t[LPL]Lo Regs Loop (loop.id %d): [", loop->num);
    for (auto it : lo_regs)
      fprintf (dump_file, "r%d ", it);
    fprintf (dump_file, "]\n");

    fprintf (dump_file, "\t[LPL]Hi Regs Loop (loop.id %d): [", loop->num);
    for (auto it : hi_regs)
      fprintf (dump_file, "r%d (ud:%d) ", it.first, it.second);
    fprintf (dump_file, "]\n");

    fprintf (dump_file, "\t[LPL]Preheader bb (loop.id %d): %d\n", loop->num,
             preheader_bb->index);

    fprintf (dump_file, "\t[LPL]Exiting bb(s) (loop.id %d): [", loop->num);
    for (auto bb : exiting_bbs)
      fprintf (dump_file, "%d ", bb->index);
    fprintf (dump_file, "]\n");

    fprintf (dump_file, "\t[LPL]Exit bb(s) (loop.id %d): [", loop->num);
    for (auto bb : exit_bbs)
      fprintf (dump_file, "%d ", bb->index);
    fprintf (dump_file, "]\n");

    fprintf (dump_file, "\t[LPL]Fwd bb(s) (loop.id %d): [", loop->num);
    for (auto bb : fwd_bbs)
      fprintf (dump_file, "%d->(%d)->%d ", single_pred (bb)->index, bb->index,
               single_succ (bb)->index);
    fprintf (dump_file, "]\n");
  }

  bool loop_lo_regs ();
  bool loop_hi_regs ();

  void replace_all_uses_of (unsigned hi_regno, unsigned lo_regno);
  void replace_all_defs_of (unsigned hi_regno, unsigned lo_regno);

  void save_lo_reg (rtx lo_reg, rtx hi_reg);
  void restore_lo_reg (basic_block exit_bb, rtx lo_reg, rtx hi_reg);

private:
  const struct loop *loop;
  /* TRUE if loop has a complex enter or exit edge.  We don't form a region
   * from such loop */
  bool loop_with_complex_edge;

  /* exiting block: the source of an exiting edge (an edge from inside the loop
   * to a node outside of the loop) */
  std::list<basic_block> exiting_bbs;
  /* exit block: the destination of an exiting edge (an edge from inside the
   * loop to a node outside of the loop) */
  std::set<basic_block> exit_bbs;
  /* forward block: has as unique predecesor an exiting-block and as unique
   * succesor an exit-block*/
  std::list<basic_block> fwd_bbs;
  /* loop preheader */
  basic_block preheader_bb;
  /* remap exit bbs */
  std::map<basic_block, basic_block> remap_bbs;
  /* List of unused lo-regs */
  std::list<unsigned> lo_regs;
  /* List of used hi-regs */
  std::list<std::pair<unsigned, unsigned> > hi_regs;

  void loop_preheader ();
  void loop_exit_bbs ();
  bool is_tmp_work_register (unsigned regno);
};

/* Return the first insn in the basic block bb (non note, label or debug insn)
 */
static rtx_insn *
first_active_insn_in_bb (basic_block bb)
{
  for (rtx_insn *insn = BB_HEAD (bb);; insn = NEXT_INSN (insn))
    {
      if (!(NOTE_P (insn) || LABEL_P (insn) || DEBUG_INSN_P (insn)))
        return insn;
      if (insn == BB_END (bb))
        return NULL;
    }

  gcc_assert (0 && "should not reach this line");
}

/* Return the last insn in the basic block bb (non note, label or debug insn)
 */
static rtx_insn *
last_active_insn_in_bb (basic_block bb)
{
  for (rtx_insn *insn = BB_END (bb);; insn = PREV_INSN (insn))
    {
      if (!(NOTE_P (insn) || LABEL_P (insn) || DEBUG_INSN_P (insn)))
        return insn;
      if (insn == BB_HEAD (bb))
        return NULL;
    }

  gcc_assert (0 && "should not reach this line");
}

/* Emit new instruction */
static inline void
emit_at_position (rtx pattern, basic_block bb, rtx_insn *where)
{
  if (where)
    {
      set_block_for_insn (where, bb);
      emit_insn_before (pattern, where);
    }
  else
    {
      set_block_for_insn (BB_END (bb), bb);
      emit_insn_after (pattern, BB_END (bb));
    }
}

/* Find loop-preaheader basic block */
void
LowPressureLoop::loop_preheader ()
{
  edge_iterator ei;
  edge e;

  gcc_assert (loop->header && "invalid loop header bb");
  gcc_assert (loops_state_satisfies_p (LOOPS_HAVE_PREHEADERS));

  preheader_bb = NULL;
  FOR_EACH_EDGE (e, ei, loop->header->preds)
  {
    if (e->flags & EDGE_COMPLEX)
      loop_with_complex_edge = true;
    if (!flow_bb_inside_loop_p (loop, e->src))
      {
        gcc_assert (preheader_bb == NULL);
        preheader_bb = e->src;
      }
  }

  // Check its only edge is to the header
  gcc_assert (single_succ_p (preheader_bb));
}

/* Find the unique set of loop-exit basic block(s) */
void
LowPressureLoop::loop_exit_bbs ()
{
  edge e;
  int i;

  auto is_exit_bb = [&] (basic_block bb) {
    return (std::find (exit_bbs.begin (), exit_bbs.end (), bb)
            != exit_bbs.end ());
  };

  vec<edge> edges = get_loop_exit_edges (loop);
  FOR_EACH_VEC_ELT (edges, i, e)
  {
    if (e->flags & EDGE_COMPLEX)
      loop_with_complex_edge = true;
    if (e->dest == EXIT_BLOCK_PTR_FOR_FN (cfun))
      loop_with_complex_edge = true;
    exiting_bbs.push_back (e->src);
    exit_bbs.insert (e->dest);
  }

  // Filter-out the fwd-bbs from the set of exit-bss
  for (auto bb : exit_bbs)
    {
      // Make sure we are dealing with:
      //
      //  exiting_bb -> fwd_bb -> exit_bb 
      //
      //  (where fwd_bb is an exit_bb with a single predecessor)
      if (! single_pred_p (bb))
        continue;
      if (forwarder_block_p (bb))
        {
          gcc_assert (single_succ_p (bb));
          if (is_exit_bb (single_succ (bb)))
            fwd_bbs.push_back (bb);
        }
    }

  for (auto it : fwd_bbs)
    exit_bbs.erase (it);

  edges.release ();
}

/* Check if there are registers in range [r0..r7] that are not used / defined
 * inside loop
 */
bool
LowPressureLoop::loop_lo_regs ()
{
  auto_sbitmap lo_regs_not_used_in_loop (LAST_LO_REGNUM + 1);
  basic_block *bbs = get_loop_body (loop);

  // Assume that all LO regs are not used
  bitmap_ones (lo_regs_not_used_in_loop);
  for (unsigned lnode = 0; lnode < loop->num_nodes; lnode++)
    {
      basic_block bb = bbs[lnode];
      for (unsigned regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
        {
          if (REGNO_REG_SET_P (&DF_LR_BB_INFO (bb)->use, regno)
              || REGNO_REG_SET_P (&DF_LR_BB_INFO (bb)->def, regno)
              || REGNO_REG_SET_P (&DF_LIVE_BB_INFO (bb)->gen, regno))
            CLEAR_REGNO_REG_SET (lo_regs_not_used_in_loop, regno);
        }
    }

  /*
    Filter our the callee-saved low registers that have no uses/defs: thrashing
      one of these registers will mean that PUSH/POP instructions will have to
      be inserted in the prologue & epilogue of the function => the stack
      offsets will be altered.
   */
  for (unsigned regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
    {
      if (callee_saved_reg_p (regno))
        {
          if (!df_regs_ever_live_p (regno))
            CLEAR_REGNO_REG_SET (lo_regs_not_used_in_loop, regno);
        }
    }

  /*
  Consider first all the low registers that are not live-out at the end of the
  loop preheader. These registers don't have to be saved / restored around
  the loop
   */
  for (unsigned regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
    {
      if (REGNO_REG_SET_P (lo_regs_not_used_in_loop, regno))
        {
          if (!REGNO_REG_SET_P (df_get_live_out (preheader_bb), regno))
            {
              lo_regs.push_back (regno);
              CLEAR_REGNO_REG_SET (lo_regs_not_used_in_loop, regno);
            }
        }
    }

  /*
    Then, consider the rest of the unreferenced low registers
   */
  for (unsigned regno = FIRST_LO_REGNUM; regno <= LAST_LO_REGNUM; regno++)
    {
      if (REGNO_REG_SET_P (lo_regs_not_used_in_loop, regno))
        {
          lo_regs.push_back (regno);
        }
    }

  free (bbs);
  return lo_regs.size ();
}

/* Check if there are registers in range [r8..r15] that are used / defined
 * inside loop
 */
bool
LowPressureLoop::loop_hi_regs ()
{

  auto is_tmp_work_register = [&] (unsigned regno) {
    if (REGNO_REG_SET_P (df_get_live_out (preheader_bb), regno))
      return false;
    for (auto bb : exit_bbs)
      {
        if (REGNO_REG_SET_P (df_get_live_in (bb), regno))
          return false;
      }
    return true;
  };

  for (unsigned regno = FIRST_HI_REGNUM; regno <= LAST_ARM_REGNUM; regno++)
    {
      // Filter-out SP and PC registers
      if ((regno == SP_REGNUM) || (regno == PC_REGNUM))
        continue;
      if (!is_tmp_work_register (regno))
        continue;

      int32_t nrefs_in_loop = 0;
      int32_t is_cond_jump = 0;

      df_ref ref;
      for (ref = DF_REG_USE_CHAIN (regno); ref; ref = DF_REF_NEXT_REG (ref))
        {
          if (DF_REF_IS_ARTIFICIAL (ref))
            continue;
          if (!flow_bb_inside_loop_p (loop, DF_REF_BB (ref)))
            continue;
          if ((DF_REF_FLAGS (ref)
               & (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
            gcc_assert (0 && "unexpected ref-flags");
          if ((DF_REF_FLAGS (ref) & DF_REF_MW_HARDREG))
            break;
          if (!(DF_REF_CLASS (ref) == DF_REF_REGULAR))
            break;
          is_cond_jump |= any_condjump_p (DF_REF_INSN (ref));
          nrefs_in_loop += 1;
        }
      // DF_REF_REGULAR ?
      if (ref != NULL)
        continue;

      for (ref = DF_REG_DEF_CHAIN (regno); ref; ref = DF_REF_NEXT_REG (ref))
        {
          if (DF_REF_IS_ARTIFICIAL (ref))
            continue;
          if (!flow_bb_inside_loop_p (loop, DF_REF_BB (ref)))
            continue;
          if ((DF_REF_FLAGS (ref)
               & (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
            break;
          if ((DF_REF_FLAGS (ref) & DF_REF_MW_HARDREG))
            break;
          if (!(DF_REF_CLASS (ref) == DF_REF_REGULAR))
            break;
          is_cond_jump |= any_condjump_p (DF_REF_INSN (ref));
          nrefs_in_loop += 1;
        }
      // DF_REF_REGULAR ?
      if (ref != NULL)
        continue;

      if (!nrefs_in_loop)
        continue;

      if (optimize_function_for_size_p (cfun))
        {
          int32_t n_loads = 1;
          int32_t n_stores = exit_bbs.size ();
          if ((nrefs_in_loop / (n_loads + n_stores)) < 2)
            continue;
        }
      else
        {
          if (!(is_cond_jump || loop_depth (loop) == 1))
            continue;
        }

      hi_regs.push_back (std::make_pair (regno, nrefs_in_loop));
    }

  /*
    For "O3" (speed) this might not be always true because we do not consider
      the is_cond_jump flag here
  */
  hi_regs.sort ([] (const std::pair<unsigned, unsigned> &a,
                    const std::pair<unsigned, unsigned> &b) {
    return a.second > b.second;
  });

  return hi_regs.size ();
}

/*
  Replace in loop uses of register hi_regno with register lo_regno
*/
void
LowPressureLoop::replace_all_uses_of (unsigned hi_regno, unsigned lo_regno)
{
  for (df_ref ref = DF_REG_USE_CHAIN (hi_regno); ref;
       ref = DF_REF_NEXT_REG (ref))
    {
      if (DF_REF_IS_ARTIFICIAL (ref))
        continue;
      if (!flow_bb_inside_loop_p (loop, DF_REF_BB (ref)))
        continue;
      if ((DF_REF_FLAGS (ref) & (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
        gcc_assert (0 && "invalid reg-flags");

      if (dump_file)
        fprintf (dump_file, "\t[LPL]Replace insn.uid %d (r%d with r%d)\n",
                 INSN_UID (DF_REF_INSN (ref)), hi_regno, lo_regno);

      rtx *old_rtx_loc = DF_REF_LOC (ref);
      rtx new_rtx = gen_rtx_REG (GET_MODE (*old_rtx_loc), lo_regno);
      validate_change (DF_REF_INSN (ref), old_rtx_loc, new_rtx, true);
    }
}

/*
  Replace in loop defs of register hi_regno with register lo_regno
*/
void
LowPressureLoop::replace_all_defs_of (unsigned hi_regno, unsigned lo_regno)
{
  for (df_ref ref = DF_REG_DEF_CHAIN (hi_regno); ref;
       ref = DF_REF_NEXT_REG (ref))
    {
      if (DF_REF_IS_ARTIFICIAL (ref))
        continue;
      if (!flow_bb_inside_loop_p (loop, DF_REF_BB (ref)))
        continue;
      if ((DF_REF_FLAGS (ref) & (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
        continue;

      if (dump_file)
        fprintf (dump_file, "\t[LPL]Replace insn.uid %d (r%d with r%d)\n",
                 INSN_UID (DF_REF_INSN (ref)), hi_regno, lo_regno);

      rtx *old_rtx_loc = DF_REF_LOC (ref);
      rtx new_rtx = gen_rtx_REG (GET_MODE (*old_rtx_loc), lo_regno);
      validate_change (DF_REF_INSN (ref), old_rtx_loc, new_rtx, true);
    }
}

/* Add a "move hi_reg, lo_reg" insn in the loop preheader bb (save lo-reg
  before thrashing in inside the loop)
*/
void
LowPressureLoop::save_lo_reg (rtx lo_reg, rtx hi_reg)
{
  basic_block save_bb = NULL;
  rtx_insn *insert_before = last_active_insn_in_bb (preheader_bb);

  if (!insert_before)
    save_bb = preheader_bb;

  if (!save_bb)
    {
      gcc_assert (insert_before);
      if (!reg_mentioned_p (hi_reg, insert_before))
        save_bb = preheader_bb;
    }

  if (!save_bb)
    save_bb = remap_bbs[preheader_bb];

  if (!save_bb)
    {
      save_bb = remap_bbs[preheader_bb]
          = split_edge (single_succ_edge (preheader_bb));
      if (dump_file)
        fprintf (
            dump_file,
            "\t[LPL]Split preheader.uid %d outcoming edge: new bb.uid %d\n",
            preheader_bb->index, save_bb->index);
    }

  insert_before = last_active_insn_in_bb (save_bb);
  rtx save_pat = gen_rtx_SET (hi_reg, lo_reg);
  emit_at_position (save_pat, save_bb, insert_before);

  if (dump_file)
    fprintf (dump_file, "\t[LPL]Save r%d (into r%d) bb.uid %d\n",
             REGNO (lo_reg), REGNO (hi_reg), save_bb->index);
}

/* Add a "move lo_reg, hi_reg" insn in the loop exit bb (restore lo-reg to its
  original value that it has in the preheader bb)
*/
void
LowPressureLoop::restore_lo_reg (basic_block exit_bb, rtx lo_reg, rtx hi_reg)
{
  basic_block restore_bb = NULL;
  edge_iterator ei;
  edge e;

  auto is_exiting_bb = [&] (basic_block bb) {
    return (std::find (exiting_bbs.begin (), exiting_bbs.end (), bb)
            != exiting_bbs.end ());
  };

  auto is_fwd_bb = [&] (basic_block bb) {
    return (std::find (fwd_bbs.begin (), fwd_bbs.end (), bb)
            != fwd_bbs.end ());
  };

  // Are all exit_bb-incoming-edges coming out of the loop?
  FOR_EACH_EDGE (e, ei, exit_bb->preds)
  {
    if (!(is_exiting_bb (e->src) || is_fwd_bb (e->src)))
      break;
  }
  if (e == NULL)
    restore_bb = exit_bb;

  if (!restore_bb)
    restore_bb = remap_bbs[exit_bb];

  if (!restore_bb)
    {
      /* Create new exit-bb and  adjust the predecessor's jump instruction to
       * target our new block.  */
      std::list<edge> redirect;
      FOR_EACH_EDGE (e, ei, exit_bb->preds)
      {
        if (is_exiting_bb (e->src))
          redirect.push_back (e);
      }
      FOR_EACH_EDGE (e, ei, exit_bb->preds)
      {
        if (is_fwd_bb (e->src))
          redirect.push_back (e);
      }

      edge to_split = redirect.front ();
      for (auto edge : redirect)
        {
          if (edge->flags & EDGE_FALLTHRU)
            to_split = edge;
        }

      restore_bb = remap_bbs[exit_bb] = split_edge (to_split);
      redirect.remove (to_split);

      if (dump_file)
        fprintf (dump_file,
                 "\t[LPL]Split exit-bb.uid %d incoming edge: new bb.uid %d\n",
                 exit_bb->index, restore_bb->index);

      for (auto edge : redirect)
        {
          if (dump_file)
            fprintf (dump_file,
                     "\t[LPL]Redirect edge (%d)->(%d) to new bb.uid %d\n",
                     edge->src->index, edge->dest->index, restore_bb->index);
          redirect_jump (as_a<rtx_jump_insn *> (BB_END (edge->src)),
                         block_label (remap_bbs[exit_bb]), 0);
          redirect_edge_succ (edge, remap_bbs[exit_bb]);
        }
    }

  rtx_insn *insert_before = first_active_insn_in_bb (restore_bb);
  rtx restore_pat = gen_rtx_SET (lo_reg, hi_reg);
  emit_at_position (restore_pat, restore_bb, insert_before);

  if (dump_file)
    fprintf (dump_file, "\t[LPL]Restore r%d (from r%d) bb.uid %d\n",
             REGNO (lo_reg), REGNO (hi_reg), restore_bb->index);
}

static void
rrename_in_low_pressure_regions ()
{
  struct loop *loop;

  calculate_dominance_info (CDI_DOMINATORS);
  calculate_dominance_info (CDI_POST_DOMINATORS);
  loop_optimizer_init (LOOPS_HAVE_PREHEADERS | LOOPS_HAVE_RECORDED_EXITS);

  /* Dataflow analysis for use-def chains.  */
  df_set_flags (DF_RD_PRUNE_DEAD_DEFS);
  df_chain_add_problem (DF_DU_CHAIN | DF_UD_CHAIN);
  df_live_add_problem ();
  df_live_set_all_dirty ();
  df_note_add_problem ();
  df_analyze ();
  df_set_flags (DF_DEFER_INSN_RESCAN);

  if (dump_file)
    df_dump (dump_file);

  FOR_EACH_LOOP (loop, 0)
  {
    LowPressureLoop lpl (loop);

    if (lpl.loop_with_complex_edge_p ())
      continue;
    if (!lpl.loop_lo_regs ())
      continue;
    if (!lpl.loop_hi_regs ())
      continue;

    if (dump_file)
      lpl.log ();

    std::list<unsigned> lo_regs = lpl.get_lo_regs ();
    for (auto it : lpl.get_hi_regs ())
      {
        unsigned hi_regno = it.first;
        for (auto lo_regno : lo_regs)
          {
            // Rename hi-regs
            lpl.replace_all_uses_of (hi_regno, lo_regno);
            lpl.replace_all_defs_of (hi_regno, lo_regno);
            if (!apply_change_group ())
              continue;

            // save lo-reg in preheader
            lpl.save_lo_reg (gen_rtx_REG (SImode, lo_regno),
                             gen_rtx_REG (SImode, hi_regno));

            // restore lo-reg in each exit-bb
            for (auto exit_bb : lpl.get_loop_exit_bbs ())
              lpl.restore_lo_reg (exit_bb, gen_rtx_REG (SImode, lo_regno),
                                  gen_rtx_REG (SImode, hi_regno));

            // a lo-reg can be paired with a single hi-reg
            lo_regs.remove (lo_regno);
            break;
          }
      }

    /* Rebuild ud- and du-chains.  */
    df_remove_problem (df_chain);
    df_process_deferred_rescans ();
    df_set_flags (DF_RD_PRUNE_DEAD_DEFS);
    df_chain_add_problem (DF_DU_CHAIN | DF_UD_CHAIN);
    df_live_add_problem ();
    df_live_set_all_dirty ();
    df_note_add_problem ();
    df_analyze ();
    df_set_flags (DF_DEFER_INSN_RESCAN);
  }

  free_dominance_info (CDI_DOMINATORS);
  free_dominance_info (CDI_POST_DOMINATORS);
  loop_optimizer_finalize ();
}

namespace
{

const pass_data pass_data_loop_regrename = {
  RTL_PASS,            /* type */
  "loop_rnreg",        /* name */
  OPTGROUP_NONE,       /* optinfo_flags */
  TV_RENAME_REGISTERS, /* tv_id */
  0,                   /* properties_required */
  0,                   /* properties_provided */
  0,                   /* properties_destroyed */
  0,                   /* todo_flags_start */
  TODO_df_finish,      /* todo_flags_finish */
};

class pass_loop_regrename : public rtl_opt_pass
{
public:
  pass_loop_regrename (gcc::context *ctxt)
      : rtl_opt_pass (pass_data_loop_regrename, ctxt)
  {
  }

  /* opt_pass methods: */
  virtual bool
  gate (function *)
  {
    if (flag_loop_rename_registers == AUTODETECT_VALUE)
      flag_loop_rename_registers = (optimize >= 2 && !optimize_size);
    return TARGET_THUMB2 && flag_loop_rename_registers;
  }

  virtual unsigned int
  execute (function *)
  {
    rrename_in_low_pressure_regions ();
    return 0;
  }

}; // class pass_loop_regrename

} // anon namespace

rtl_opt_pass *
make_pass_loop_regrename (gcc::context *ctxt)
{
  return new pass_loop_regrename (ctxt);
}
