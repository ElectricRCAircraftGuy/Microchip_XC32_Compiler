#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "tree.h"
#include "function.h"
#include "basic-block.h"
#include "tree-pass.h"
#include "rtl.h"
#include "bitmap.h"
#include "cfg.h"
#include "cfgrtl.h"
#include "df.h"


/* Remove all REG_EQUAL and REG_EQUIV notes referring to the registers INSN
   writes to. (copied from dce.c) */

static void
remove_reg_equal_equiv_notes_for_defs (rtx_insn *insn)
{
  df_ref def;

  FOR_EACH_INSN_DEF (def, insn)
    remove_reg_equal_equiv_notes_for_regno (DF_REF_REGNO (def));
}

static unsigned int
xc_remove_unnecessary_sets ()
{
  /* SImode registers with known values & the respective values */
  HARD_REG_SET regs_known_vals;
  int32_t vals[FIRST_PSEUDO_REGISTER];

  basic_block bb;
  rtx_insn *insn, *curr;

  /* each basic block is processed independently */
  FOR_EACH_BB_FN (bb, cfun)
    {
      /* assume no register values are known at the start of BB */
      CLEAR_HARD_REG_SET (regs_known_vals);

      /* use the 'safe' BB insn iterator as we want to delete insns */
      FOR_BB_INSNS_SAFE (bb, insn, curr)
        {
          if (NONDEBUG_INSN_P (insn))
            {
              rtx pat = PATTERN (insn);

              /* deal only with the (set (reg:SI) (const_int)) insns */
              if (GET_CODE (pat) == SET)
                {
                  rtx dest = SET_DEST (pat), src = SET_SRC (pat);
                  if (REG_P (dest)
                      && HARD_REGISTER_P (dest)
                      && GET_MODE (dest) == SImode
                      && CONST_INT_P (src))
                    {
                      const int32_t regno = REGNO (dest);
                      const int32_t val   = INTVAL (src);

                      /* if value of this reg is known to be equal w/ the new val */
                      if (TEST_HARD_REG_BIT (regs_known_vals, regno)
                          && val == vals[regno])
                        {
                          if (dump_file)
                            fprintf (dump_file, "Deleting insn %d (reg %d set to %d)\n",
                                     INSN_UID (insn), regno, val);

                          /* this may not be needed for these simple insns
                           * (copied from dce.c) */
                          remove_reg_equal_equiv_notes_for_defs (insn);

                          /* get rid of the unnecessary insn */
                          delete_insn (insn);
                        }
                      else
                        {
                          /* unknown / different value; record the new value */
                          SET_HARD_REG_BIT (regs_known_vals, regno);
                          vals[regno] = val;
                        }

                      /* done with the (set (reg:SI) (const_int)) */
                      continue;
                    }
                }

              /* the crt insn is not of the ones receiving special treatment */
              HARD_REG_SET regs_set_by_insn;

              /* identify the registers set/clobbered by it */
              find_all_hard_reg_sets (insn, &regs_set_by_insn, true);

              /* if any, remove them from the set of regs with known vals */
              if (!hard_reg_set_empty_p (regs_set_by_insn))
                AND_COMPL_HARD_REG_SET (regs_known_vals, regs_set_by_insn);
            }
        }
    }

  return 0;
}

namespace {

const pass_data pass_data_xc_rm_unn_sets =
{
  RTL_PASS,         /* type */
  "xc_rm_unn_sets", /* name */
  OPTGROUP_NONE,    /* optinfo_flags */
  TV_NONE,          /* tv_id */
  0,                /* properties_required */
  0,                /* properties_provided */
  0,                /* properties_destroyed */
  0,                /* todo_flags_start */
  0                 /* todo_flags_finish */
};

class pass_xc_rm_unn_sets : public rtl_opt_pass {
public:
  pass_xc_rm_unn_sets (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_xc_rm_unn_sets, ctxt) { }
  virtual bool
  gate (function *)
  {
#ifdef TARGET_MCHP_PIC32C
    return optimize && mchp_remove_unnecessary_sets;
#else
    return false; /* ARM-only */
#endif
  }
  virtual unsigned int
  execute (function *)
  {
    return xc_remove_unnecessary_sets ();
  }
};

} /* anon namespace */

rtl_opt_pass *
make_pass_xc_rm_unn_sets (gcc::context *ctxt)
{
  return new pass_xc_rm_unn_sets (ctxt);
}
