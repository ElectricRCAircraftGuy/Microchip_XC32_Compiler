#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "bversion.h" /* for BUILDING_GCC_MAJOR, BUILDING_GCC_VERSION */

/* this header madness affects only GCC 5.x, it seems */
#if (BUILDING_GCC_MAJOR == 5)
#include "hash-set.h"
#include "vec.h"
#include "double-int.h"
#include "input.h"
#include "alias.h"
#include "symtab.h"
#include "inchash.h"
#include "ipa-ref.h"
#include "tree-core.h"
#include "tree-ssa-alias.h"
#include "is-a.h"
#include "predict.h"
#include "function.h"
#include "basic-block.h"
#include "tree.h"
#include "gimple-expr.h"
#include "fold-const.h"
#include "gimple.h"
#include "lto-streamer.h"
#include "dominance.h"
#else
#include "tree.h"
#include "function.h"
#include "basic-block.h"
#endif

/* MERGE-NOTES: I'm guarding this with major version == 8 for now.
   I don't understand the header madness yet. */
#if (BUILDING_GCC_MAJOR >= 8)
#include "stringpool.h"
#include "attribs.h"
#endif

#include "tree-pass.h"
#include "cgraph.h"
#include "toplev.h" /* error() prototype is here on older GCCs */
#include "diagnostic.h" /* for error() on newer versions */
#include "langhooks.h"
#include "cppdefault.h"
#include "rtl.h"
#include "memmodel.h"
#include "emit-rtl.h"
#include "bitmap.h"
#if (BUILDING_GCC_VERSION >= 5000)
#include "cfg.h"
#endif
#include "df.h"
#include "tm_p.h"
#include "output.h"
#include "dwarf2asm.h"
#include "tree-pretty-print.h"

#include "../../binutils/include/pic32-stack-usage.h"

/* Given a CALL_INSN, find and return the nested CALL.
   (copied from final.c)
*/
static rtx
call_from_call_insn (rtx_call_insn *insn)
{
  rtx x;
  gcc_assert (CALL_P (insn));
  x = PATTERN (insn);

  while (GET_CODE (x) != CALL)
    {
      switch (GET_CODE (x))
        {
        default:
          gcc_unreachable ();
        case COND_EXEC:
          x = COND_EXEC_CODE (x);
          break;
        case PARALLEL:
          x = XVECEXP (x, 0, 0);
          break;
        case SET:
          x = XEXP (x, 1);
          break;
        }
    }
  return x;
}

/* if "-v" is specified, this is equiv. to fprintf (stderr, ...);
 * otherwise, it does nothing */
#define dbg_printf(...) __extension__ \
  ({ verbose_flag ? fprintf(stderr, __VA_ARGS__) : 0; })

/* Code to write stack usage information to asm (as calculated/reported by -fstack-usage)
   This file contains code that writes stack usage information to asm into
   ".xc_stack_usage" sections.
   asm output - one per function
    .section    .xc_stack_usage
    .4byte      f1          @ function address
    .ascii      "f1\000"    @ function name
    .4byte      0x100       @ total used stack
    .4byte      0x0         @ flags
    .byte       0x1         @ type of memory
*/
void
xc_output_stack_usage (HOST_WIDE_INT stack_usage, int stack_usage_kind)
{
  const char *name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (current_function_decl));

  const char *su_kind_desc[] = { "static", "dynamic", "dynamic, bounded" };
  dbg_printf ("%s: stack usage: %ld\t%s\n",
              name, stack_usage, su_kind_desc[stack_usage_kind]);

  // scan the function's RTL, looking for inline asm and indirect calls
  bool inline_asm = false, indirect_calls = false;
  uint32_t flags = 0;
  tree a, attr;

  /* check if function has the interrupt attribute */
  attr = DECL_ATTRIBUTES (current_function_decl);
  a = lookup_attribute ("isr", attr);
  if (a == NULL_TREE)
#ifdef TARGET_IS_PIC32C
    a = lookup_attribute ("interrupt", attr);
#else
    a = lookup_attribute ("interrupt", TYPE_ATTRIBUTES (TREE_TYPE(current_function_decl)));
#endif
  if (a != NULL_TREE) {
    flags |= SU_INTERRUPT;
    SU_SET_IPL(flags, 5);
  }

  for (rtx_insn *insn = get_insns (); insn != NULL_RTX; insn = next_insn (insn))
    {
      if (INSN_P (insn))
        {
          rtx body  = PATTERN (insn);
          if (INSN_CODE (insn) < 0
              && (GET_CODE (body) == ASM_INPUT || asm_noperands (body) >= 0))
            {
              inline_asm = true;
              continue;
            }
        }

      rtx call_insn = insn;
      if (NONJUMP_INSN_P (insn) && GET_CODE (PATTERN (insn)) == SEQUENCE)
        call_insn = XVECEXP (PATTERN (insn), 0, 0);

      if (!CALL_P (call_insn))
        continue;

      rtx x = call_from_call_insn ((rtx_call_insn *)call_insn);
      x = XEXP (x, 0);

      const char *callee_name = 0;
      if (x && MEM_P (x) && GET_CODE (XEXP (x, 0)) == SYMBOL_REF)
        {
          rtx sym_ref = XEXP (x, 0);
          if (tree decl = SYMBOL_REF_DECL (sym_ref))
            callee_name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl));
          else
            callee_name = mchp_strip_name_encoding (XSTR (sym_ref, 0));
        }
      if (callee_name)
        {
          // if we want to include this info...
          dbg_printf ("\tcalls: %s\n", callee_name);
        }
      else
        {
          indirect_calls = true;
          // break; // if only this info is needed
        }
    }

  if (inline_asm)
    dbg_printf ("\tinline assembly\n");

  if (indirect_calls) {
    dbg_printf ("\tindirect calls\n");
    flags |= SU_INDIRECT_CALLS;
  }

  // TARGET_STACK_USAGE_SECTION should be defined by the target
  TARGET_STACK_USAGE_SECTION (SU_SECTION);

  // function addr and name
  dw2_asm_output_addr (4, name, "function");
  ASM_OUTPUT_ASCII (asm_out_file, name, strlen (name) + 1);

  // stack usage for this function
  dw2_asm_output_data (4, stack_usage, "size");
  // flags - see xc-stack-usage.h for description
  dw2_asm_output_data (4, flags, "flags");

  // output kind - see xc-stack-usage.h for description
  dw2_asm_output_data (1, stack_usage_kind, "kind");
}

/* Code to write stack usage header to asm.
   This file contains code that writes stack usage information to asm into
  ".xc_stack_usage.hdr" sections.

   e.g. :
   asm output - one per object
    .section    .xc_stack_usage.hdr
    .byte       0xE     @ size
    .4byte      0x1     @ version
    .byte       0       @ reserved
    .4byte      0       @ reserved
    .4byte      0       @ reserved
*/
void xc_output_stack_usage_header(void)
{
  /* emit Stack Usage Header */
  TARGET_STACK_USAGE_SECTION (SU_SECTION_HDR);

  dw2_asm_output_data (1, SU_INFO_HDR_SIZE, "size");
  dw2_asm_output_data (4, SU_VERSION, "version");

  /* not needed now */
  dw2_asm_output_data (1, 0, "reserved");
  dw2_asm_output_data (4, 0, "reserved");
  dw2_asm_output_data (4, 0, "reserved");
}
