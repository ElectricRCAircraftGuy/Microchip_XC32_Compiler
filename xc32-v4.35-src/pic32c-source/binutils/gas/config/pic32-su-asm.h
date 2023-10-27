#ifndef PIC32_SU_ASM_H_
#define PIC32_SU_ASM_H_

/* PIC32C/PIC32M stack-usage specific prototypes */
/* Included from both tc-arm.c and tc-mips.c files, before pic32-su-asm.c is included */

#include "pic32-stack-usage.h"

static const char *su_kind_desc[] = { "static", "dynamic", "dynamic,bounded" };

typedef enum {
  STACK_USAGE_DISABLED_CRTFUN = -1,
  STACK_USAGE_DISABLED = 0,
  STACK_USAGE_ENABLED = 1,
} pic32_gen_stack_usage_t;

/* if STACK_USAGE_ENABLED => gen stack usage info */
/*static*/ int pic32_gen_stack_usage = STACK_USAGE_DISABLED;

/* a counter of each function's instructions handled by md_assemble () */
static int pic32_insn_no;

/* last global symbol seen - used if SU is detected w/o a function symbol */
static symbolS *last_global_sym;

/* helper functions */
static PRINTF_LIKE (pic32_su_debug_msg);

/*static*/ void pic32_su_start_function (const char *func_name);
static void pic32_su_start_unknown_function (void);

/* these ops are delayed until the entire function is seen */
static void pic32_su_alter_stack_depth (int addend);
static void pic32_su_copy_stack_depth (bfd_boolean back, int addend);
static void pic32_su_alter_saved_stack_depth (int addend);
static void pic32_su_mark_variable_adjust (void);
static void pic32_su_mark_indirect_calls (void);

/* these are resolved immediately (directly or to other delayed ones) */
static void pic32_su_handle_mov (int reg, int val);
static void pic32_su_handle_ldr (int reg, symbolS *sym, int addend, bfd_reloc_code_real_type);
static void pic32_su_alter_stack_depth_reg (bfd_boolean decrease, int reg);
static void pic32_su_alter_saved_stack_depth_reg (bfd_boolean decrease, int reg);

#ifdef TARGET_IS_PIC32MX
struct mips_operand_token;
static void pic32_su_handle_mips_insn (const struct mips_opcode *first,
                                       const struct mips_operand_token *tokens);
static int pic32_su_gp_or_equ (int reg);
static void pic32_su_handle_addiu_reloc (int reg, symbolS *sym, int addend,
                                         bfd_reloc_code_real_type reloc);
#endif

#ifdef TARGET_IS_PIC32C
static void pic32_su_handle_lsl (int reg, int val);
#endif

/* this processes the delayed ops after the entire function is seen */
static void pic32_su_process_ops (void);

static void pic32_su_disable_gen_stack_usage (bfd_boolean whole_file);

/* eventually called to write out the su sections */
static void pic32_su_write_stack_usage_sections (void);

#ifdef TARGET_IS_PIC32MX

#define REG_GP 28                           /* global pointer */
#define REG_SP 29                           /* stack pointer  */
#define REG_FP (mips_opts.mips16 ? 17 : 30) /* frame pointer  */
#define REG_RA 31                           /* return address */

static symbolS *GP_SYM;          /* this will be initalized to the '$gp' sym */

static unsigned mips_frame_size; /* the frame size of the current function */
                                 /* (as specified by the .frame directive) */

#endif /* TARGET_IS_PI32MX */

#endif /* PIC32_SU_ASM_H_ */
