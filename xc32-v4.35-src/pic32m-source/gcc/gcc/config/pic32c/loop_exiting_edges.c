/*
  Adjust the probability of loop exiting edges
  An exiting edge is an edge from inside the loop to a node outside of the 
  loop. The source of such an edge is called an exiting block.

  If an exiting block ends in a conditional jump instruction (with equal 
    probability for the jump to be taken or not), then we do adjust the 
    probability of the two edges as following:
      the edge that stays-in the loop is marked as very likely
      the edge that leaves the loop is marked as very unlikely.

  This should help the basic-block reordering pass to determine the layout of 
  the basic blocks in a loop: the edge that stays-in the loop should be the 
  fallthru one.
*/

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "rtl.h"
#include "tree.h"
#include "gimple.h"
#include "tree-pass.h"
#include "tree-cfg.h"
#include "cfgloop.h"

#define AUTODETECT_VALUE 2

static void
adjust_loop_exiting_edge_probabilities (edge exiting_edge)
{
  edge true_edge, false_edge;
  struct loop *loop_father;

  basic_block exiting_bb = exiting_edge->src;
  if (EDGE_COUNT (exiting_bb->succs) != 2)
    return;

  gimple *stmt = last_stmt (exiting_bb);
  if (!stmt)
    return;
  if (gimple_code (stmt) != GIMPLE_COND)
    return;

  extract_true_false_edges_from_block (exiting_bb, &true_edge, &false_edge);

  if (!true_edge->probability.initialized_p ())
    return;
  if (!false_edge->probability.initialized_p ())
    return;
  if (!(true_edge->probability.to_reg_br_prob_base ()
        == false_edge->probability.to_reg_br_prob_base ()))
    return;

  loop_father = true_edge->src->loop_father;
  gcc_assert (true_edge->src == false_edge->src);
  gcc_assert (true_edge->src->loop_father == false_edge->src->loop_father);

  if (true_edge->dest->loop_father != false_edge->dest->loop_father)
    {
      if (loop_father == true_edge->dest->loop_father)
        {
          true_edge->probability = profile_probability::very_likely ();
          false_edge->probability = profile_probability::very_unlikely ();
          if (dump_file)
            {
              fprintf (dump_file,
                       "\Adjust edge (%d)->(%d) probability to very_likely\n",
                       true_edge->src->index, true_edge->dest->index);
              fprintf (
                  dump_file,
                  "\Adjust edge (%d)->(%d) probability to very_unlikely\n",
                  false_edge->src->index, false_edge->dest->index);
            }
        }
      else if (loop_father == false_edge->dest->loop_father)
        {
          true_edge->probability = profile_probability::very_unlikely ();
          false_edge->probability = profile_probability::very_likely ();
          if (dump_file)
            {
              fprintf (
                  dump_file,
                  "\Adjust edge (%d)->(%d) probability to very_unlikely\n",
                  true_edge->src->index, true_edge->dest->index);
              fprintf (dump_file,
                       "\Adjust edge (%d)->(%d) probability to very_likely\n",
                       false_edge->src->index, false_edge->dest->index);
            }
        }
    }
}

namespace
{

const pass_data pass_data_loop_exiting_edges = {
  GIMPLE_PASS,         /* type */
  "exiting_edges",     /* name */
  OPTGROUP_NONE,       /* optinfo_flags */
  TV_TREE_CLEANUP_CFG, /* tv_id */
  PROP_cfg,            /* properties_required */
  0,                   /* properties_provided */
  0,                   /* properties_destroyed */
  0,                   /* todo_flags_start */
  0,                   /* todo_flags_finish */
};

class pass_loop_exiting_edges : public gimple_opt_pass
{
public:
  pass_loop_exiting_edges (gcc::context *ctxt)
      : gimple_opt_pass (pass_data_loop_exiting_edges, ctxt)
  {
  }

  virtual bool
  gate (function *)
  {
    if (flag_exiting_edge_prob == AUTODETECT_VALUE)
      flag_exiting_edge_prob = (optimize >= 2 && !optimize_size);
    return TARGET_THUMB2 && flag_exiting_edge_prob;
  }

  virtual unsigned int
  execute (function *fun)
  {
    struct loop *loop;

    FOR_EACH_LOOP_FN (fun, loop, LI_FROM_INNERMOST)
    {
      vec<edge> edges;
      unsigned int i;
      edge e;

      if (single_likely_exit (loop))
        continue;

      edges = get_loop_exit_edges (loop);
      FOR_EACH_VEC_ELT (edges, i, e)
      adjust_loop_exiting_edge_probabilities (e);
      edges.release ();
    }

    return 0;
  }

}; // class pass_loop_exiting_edges

} // anon namespace

gimple_opt_pass *
make_pass_loop_exiting_edges (gcc::context *ctxt)
{
  return new pass_loop_exiting_edges (ctxt);
}
