/* PIC32C/PIC32M stack-usage specific types and functions definitions */
/* Included from both tc-arm.c and tc-mips.c files, after pic32-su-asm.h was included */

# if defined(TARGET_IS_PIC32MX)
#   define PIC32_NUM_REGS        32
#   define S_CHANGE_SECTION      s_change_section
# elif defined(TARGET_IS_PIC32C)
#   define PIC32_NUM_REGS        16
#   define S_CHANGE_SECTION      s_arm_change_section
# else
#   error This file is PIC32M/PIC32C-specific.
# endif

typedef struct stack_usage_info {
  struct stack_usage_info *next;

  unsigned size;   /* stack size (in bytes) */
  int      kind;   /* stack usage kind: static, dyn, dyn bounded */
  unsigned flags;  /* func has indirect calls etc. */
  char     name[]; /* the name of the function */

} stack_usage_info;

/* current stack usage info (updated as we assemble the current function)
 * + the ones for the functions already assembled (note that, as we always add
 * to the end of the list, these two corresp. to the list tail, resp. head */
static stack_usage_info *su_info, *su_infos;

/* tracks the stack allocation and deallocation for the crt function; */
/* su_info->size will be set to the maximum value reached by this; */
/* helps with internal consistency checking */
static int stack_depth, saved_stack_depth;

#define PIC32_STACK_CHECK_1(expr,ret) \
  if (!(su_info && (expr))) { \
    if (flag_debug && pic32_gen_stack_usage == STACK_USAGE_ENABLED) \
      as_warn (_("internal check failed, stack usage info " \
                 "for crt func may be inaccurate")); \
    if (su_info) \
      su_info->flags |= SU_INACCURATE; \
    pic32_su_disable_gen_stack_usage (FALSE); \
    if (ret) return; \
  }

#define PIC32_STACK_CHECK(expr)       PIC32_STACK_CHECK_1(expr,TRUE)
#define PIC32_STACK_CHECK_NORET(expr) PIC32_STACK_CHECK_1(expr,FALSE)

#define DUMP_STACK_DEPTH() \
  if (flag_debug) \
    printf ("\t\tstack_depth: %-4d saved: %-4d %s\n", stack_depth, \
            saved_stack_depth, su_kind_desc[su_info->kind]);

typedef enum {
  SU_OP_DEBUG_MSG,                  /* message               */
  SU_OP_ALTER_STACK_DEPTH,          /* addend                */
  SU_OP_COPY_STACK_DEPTH,           /* back, addend          */
  SU_OP_ALTER_SAVED_STACK_DEPTH,    /* addend                */
  SU_OP_MARK_VARIABLE_ADJUST,       /* (no operands)         */
  SU_OP_MARK_INDIRECT_CALLS,        /* (no operands)         */
  SU_OP_ALTER_STACK_DEPTH_SYM,      /* decrease, sym, addend */
  SU_OP_ALTER_SAVED_STACK_DEPTH_SYM,/* decrease, sym, addend */
} pic32_su_opcode;

typedef struct pic32_su_op {
  struct pic32_su_op *next;
  pic32_su_opcode    opcode;
  intptr_t           operands[3];
} pic32_su_op;

/* head and tail of the su ops for the current function */
static pic32_su_op *pic32_su_ops, *pic32_su_ops_tail;

static void
pic32_su_new_op (pic32_su_opcode opcode,
                 intptr_t operand0, intptr_t operand1, intptr_t operand2)
{
  /* make sure there is an associated SU info (function) for each SU operation
   * (even if a fake/artificial one) */
  if (!su_info)
    pic32_su_start_unknown_function ();

  pic32_su_op *op = XNEW (pic32_su_op);

  op->next        = NULL;
  op->opcode      = opcode;
  op->operands[0] = operand0;
  op->operands[1] = operand1;
  op->operands[2] = operand2;

  pic32_su_ops_tail = *(pic32_su_ops_tail ? &pic32_su_ops_tail->next
                                          : &pic32_su_ops) = op;
}

/* prints an instruction to a heap buffer (associated to a su_op) so that
 * the printing can be delayed until the function is seen completely */
static void
pic32_su_debug_msg (const char *format, ...)
{
  /* only output when -D is specified */
  if (!flag_debug)
    return;

  va_list args;
  char buff[1024];

  va_start (args, format);
  vsnprintf (buff, sizeof (buff), format, args);
  va_end (args);

  pic32_su_new_op (SU_OP_DEBUG_MSG, (intptr_t) xstrdup (buff), 0, 0);
}

/* these 'note' the reg defs by (a series of) mov and ldr insns */
static int     saved_regs; /* bitmask indicating the regs with known vals */
static int     saved_ino;  /* no. of the last instruction defining a register */
static symbolS *saved_sym[PIC32_NUM_REGS];/* if !NULL, reg is defined by a LDR from the sym */
static int     saved_val[PIC32_NUM_REGS]; /* otherwise, the concrete value (MOV/MOVS) */
static bfd_reloc_code_real_type saved_reloc[PIC32_NUM_REGS]; /* reloc type for sym != NULL */
static bfd_boolean fp_used; /* set if the frame ptr is used by this function */

static void
pic32_su_handle_mov (int reg, int val)
{
  /* reset the set of known regs if any insns were unhandled */
  if (saved_ino + 1 != pic32_insn_no)
    saved_regs = 0;

  gas_assert (reg < PIC32_NUM_REGS);

  saved_ino = pic32_insn_no;
  saved_regs |= 1 << reg;
  saved_sym[reg] = NULL;
  saved_val[reg] = val;
}

static void
pic32_su_handle_ldr (int reg, symbolS *sym, int addend, bfd_reloc_code_real_type reloc)
{
  /* reset the set of known regs if any insns were unhandled */
  if (saved_ino + 1 != pic32_insn_no)
    saved_regs = 0;

  gas_assert (reg < PIC32_NUM_REGS);

  saved_ino = pic32_insn_no;
  saved_regs |= 1 << reg;
  saved_sym[reg] = sym;
  saved_val[reg] = addend;
  saved_reloc[reg] = reloc;
}

#if defined(TARGET_IS_PIC32MX)

static int
pic32_su_gp_or_equ (int reg)
{
  return (reg == REG_GP)
          || (saved_ino + 1 == pic32_insn_no
              && saved_regs & (1 << reg)
              && saved_sym[reg] == GP_SYM
              && saved_reloc[reg] == BFD_RELOC_UNUSED);
}

static void
pic32_su_handle_addiu_reloc (int reg, symbolS *sym, int addend,
                             bfd_reloc_code_real_type reloc)
{
  /* reset the set of known regs if any insns were unhandled */
  if (saved_ino + 1 != pic32_insn_no)
    saved_regs = 0;

  gas_assert (reg < PIC32_NUM_REGS);

  /* this matches a very specific sequence:
        lw     $xx,%got(func_name)($28)
        addiu  $xx,$xx,%lo(func_name)    */
  if (addend == 0 && reloc == (mips_opts.mips16 ? BFD_RELOC_MIPS16_LO16
                                                : BFD_RELOC_LO16)
      && saved_regs & (1 << reg)
      && saved_sym[reg] == sym
      && saved_reloc[reg] == (mips_opts.mips16 ? BFD_RELOC_MIPS16_GOT16
                                               : BFD_RELOC_MIPS_GOT16)
      && saved_val[reg] == 0)
    {
      pic32_su_debug_msg ("\taddiu\t$%d, $%d, %%lo%s(%s)\n", reg, reg,
                          (mips_opts.mips16 ? "" : "16"), S_GET_NAME (sym));
      saved_ino = pic32_insn_no;
      /* not sure if the best solution, but convert the two insns sequence
       * as if a single insn with a similar reloc type */
      saved_reloc[reg] = mips_opts.mips16 ? BFD_RELOC_MIPS16_CALL16
                                          : BFD_RELOC_MIPS_CALL16;
    }
}

#else /* defined(TARGET_IS_PIC32C) */

/* a left-shift can be used to synthesize some larger immediates on Thumb-1 */
static void
pic32_su_handle_lsl (int reg, int val)
{
  /* prev. insn defined this register to an imm value? */
  if (saved_ino + 1 == pic32_insn_no
      && reg < PIC32_NUM_REGS
      && (saved_regs & (1 << reg))
      && !saved_sym[reg])
    {
      /* move last def to the crt insn and apply the shift on the imm value */
      saved_ino = pic32_insn_no;
      saved_val[reg] <<= val;
    }
}

#endif

static void
pic32_su_new_info (const char *func_name)
{
  gas_assert (pic32_su_ops == NULL && pic32_su_ops_tail == NULL);

  if (flag_debug)
    printf ("\npic32_su_new_info (%s)\n", func_name);

  const size_t name_sz = strlen (func_name) + 1;

  stack_usage_info *sui
    = (stack_usage_info *) xcalloc (1, sizeof (stack_usage_info) + name_sz);

  memcpy (sui->name, func_name, name_sz);

  /* all the descriptors generated from the assembler will have this flag set */
  sui->flags = SU_INLINE_ASM;

  su_info = *(su_info ? &su_info->next : &su_infos) = sui;

  /* clear the stack usage-related counters for the new function */
  pic32_insn_no = 0;
  saved_ino = 0;
  saved_regs = 0;
  fp_used = FALSE;

#if defined(TARGET_IS_PIC32MX)
  mips_frame_size = 0;
#endif
}

/*static*/ void
pic32_su_start_function (const char *func_name)
{
  gas_assert (func_name);

  /* if already in this function, do nothing */
  /* (this can happen on MIPS as we call pic32_su_start_function()
   * both on .ent directive and on .type name, @function) */
  if (su_info && strcmp (su_info->name, func_name) == 0)
    return;

#if defined(TARGET_IS_PIC32MX)
  /* init GP_SYM at the first opportunity */
  if (!GP_SYM)
    {
      GP_SYM = symbol_find ("$gp");
      gas_assert (GP_SYM);
    }
#endif

  /* deal with the function that ended (if any) */
  pic32_su_process_ops ();

  /* start collecting the info for the new function */
  pic32_su_new_info (func_name);
}

static const char SU_FN_PREFIX[] = "__su_fn_";

static void
pic32_su_start_unknown_function (void)
{
  static unsigned unknown_no;
  char tmp_name[64];
  const char *func_name = NULL;

  /* use the last/nearest global symbol seen as the function name, if available */
  if (last_global_sym)
    func_name = S_GET_NAME (last_global_sym);

  /* otherwise, use an artificial name */
  if (!func_name)
    {
      snprintf (tmp_name, sizeof (tmp_name), "%s%04X_%02X", SU_FN_PREFIX,
                getpid (), unknown_no++);
      func_name = tmp_name;
    }

  pic32_su_start_function (func_name);

  /* mark the new "not really sure it's a func" with the inaccurate flag*/
  su_info->flags |= SU_INACCURATE;
}

static void
pic32_su_alter_stack_depth (int addend)
{
  pic32_su_new_op (SU_OP_ALTER_STACK_DEPTH, addend, 0, 0);
}

static void
pic32_su_alter_stack_depth_1 (int addend)
{
  /* when the stack usage is increased again after reaching zero */
  /* mark it as inaccurate (multiple control flows) */
  if (addend > 0 && !stack_depth && su_info->size)
    su_info->flags |= SU_INACCURATE;

  stack_depth += addend;

  PIC32_STACK_CHECK (stack_depth >= 0);

  DUMP_STACK_DEPTH ();

  if (addend > 0 && (unsigned)stack_depth > su_info->size)
    su_info->size = stack_depth;
}

static void
pic32_su_copy_stack_depth (bfd_boolean back, int addend)
{
  /* prevent move $fp,$sp (or backwards) from invalidating the 'saved' regs */
  if (saved_ino + 1 == pic32_insn_no)
    saved_ino = pic32_insn_no;

  /* simple heuristic to ignore fp uses as a GPR: we must have a move
   * from the stack pointer to it (w/ or w/o an addend) */
  if (!back)
    fp_used = TRUE;
  else if (!fp_used)
    return pic32_su_new_op (SU_OP_MARK_VARIABLE_ADJUST, 0, 0, 0);

  pic32_su_new_op (SU_OP_COPY_STACK_DEPTH, back, addend, 0);
}

static void
pic32_su_copy_stack_depth_1 (bfd_boolean back, int addend)
{
  if (back)
    {
      PIC32_STACK_CHECK (saved_stack_depth + addend >= 0);

      stack_depth = saved_stack_depth + addend;

      /* it's possible that some extra stack allocation to be done
       * through the frame ptr (seen on MIPS16 code) */
      if ((unsigned)stack_depth > su_info->size)
        su_info->size = stack_depth;
    }
  else
    {
      PIC32_STACK_CHECK (stack_depth + addend >= 0);

      saved_stack_depth = stack_depth + addend;
    }

  DUMP_STACK_DEPTH ();
}

static void
pic32_su_alter_saved_stack_depth (int addend)
{
  if (!fp_used)
    return;

  pic32_su_new_op (SU_OP_ALTER_SAVED_STACK_DEPTH, addend, 0, 0);
}

static void
pic32_su_alter_saved_stack_depth_1 (int addend)
{
  saved_stack_depth += addend;

  PIC32_STACK_CHECK (saved_stack_depth >= 0);

  DUMP_STACK_DEPTH ();
}

static void
pic32_su_mark_variable_adjust (void)
{
  pic32_su_new_op (SU_OP_MARK_VARIABLE_ADJUST, 0, 0, 0);
}

static void
pic32_su_mark_variable_adjust_1 (void)
{
  su_info->kind = SU_DYNAMIC_UNBOUNDED_T;

  /* this usually incurs an 8 bytes overhead for aligning the SP
   * NOTE: for anything more precise, we'd need some kind of symbolic
   *       execution or at least some complex pattern matching */
  su_info->flags |= SU_INACCURATE;

  /* ...but, since we marked it already as inaccurate, don't add the 8 bytes
   * (GCC's -fstack-usage doesn't do that either) */
  /*pic32_su_alter_stack_depth_1 (8);*/
}

static void
pic32_su_alter_stack_depth_sym (bfd_boolean decrease, symbolS *sym, int addend)
{
  pic32_su_new_op (SU_OP_ALTER_STACK_DEPTH_SYM,
                   decrease, (intptr_t) sym, addend);
}

static void
pic32_su_alter_stack_depth_sym_1 (bfd_boolean decrease, symbolS *sym, int addend)
{
  fragS *frag = symbol_get_frag (sym);

  /* addresses are unsigned, offsets are signed (same size) */
  const addressT frag_ofs = S_GET_VALUE (sym);
  const addressT val_ofs = frag_ofs + (offsetT) addend;
  const addressT end_ofs = frag_now_fix ();

  /* avoid an out-of-bounds access */
  if (val_ofs + 4 <= end_ofs)
    {
      const int val = *(int *)(frag->fr_literal + val_ofs);
      if (flag_debug)
        printf ("\t\t%s val @ %s+%d = %d\n", (decrease ? "add" : "sub"),
                S_GET_NAME (sym), addend, val);
      pic32_su_alter_stack_depth_1 (decrease ? -val : val);
    }
  else
  {
    pic32_su_mark_variable_adjust_1 ();
  }
}

static void
pic32_su_alter_stack_depth_reg (bfd_boolean decrease, int reg)
{
  /* do we have a def for this register? */
  if (saved_ino + 1 == pic32_insn_no
      && reg < PIC32_NUM_REGS
      && (saved_regs & (1 << reg)))
    {
      /* if we have the concrete value */
      if (!saved_sym[reg])
        return pic32_su_alter_stack_depth (decrease ? -saved_val[reg]
                                                    : saved_val[reg]);

      return pic32_su_alter_stack_depth_sym (decrease, saved_sym[reg],
                                             saved_val[reg]);
    }

  /* if not, treat like a variable stack adjustment */
  pic32_su_mark_variable_adjust ();
}

static void
pic32_su_alter_saved_stack_depth_sym (bfd_boolean decrease, symbolS *sym, int addend)
{
  pic32_su_new_op (SU_OP_ALTER_SAVED_STACK_DEPTH_SYM,
                   decrease, (intptr_t) sym, addend);
}

static void
pic32_su_alter_saved_stack_depth_sym_1 (bfd_boolean decrease, symbolS *sym, int addend)
{
  fragS *frag = symbol_get_frag (sym);

  /* addresses are unsigned, offsets are signed (same size) */
  const addressT frag_ofs = S_GET_VALUE (sym);
  const addressT val_ofs = frag_ofs + (offsetT) addend;
  const addressT end_ofs = frag_now_fix ();

  /* avoid an out-of-bounds access */
  if (val_ofs + 4 <= end_ofs)
    {
      const int val = *(int *)(frag->fr_literal + val_ofs);
      if (flag_debug)
        printf ("\t\t%s val @ %s+%d = %d\n", (decrease ? "add" : "sub"),
                S_GET_NAME (sym), addend, val);
      pic32_su_alter_saved_stack_depth_1 (decrease ? -val : val);
    }
}

static void
pic32_su_alter_saved_stack_depth_reg (bfd_boolean decrease, int reg)
{
  if (!fp_used)
    return;

  /* do we have a def for this register? */
  if (saved_ino + 1 == pic32_insn_no
      && reg < PIC32_NUM_REGS
      && (saved_regs & (1 << reg)))
    {
      /* if we have the concrete value */
      if (!saved_sym[reg])
        return pic32_su_alter_saved_stack_depth (decrease ? -saved_val[reg]
                                                          : saved_val[reg]);

      return pic32_su_alter_saved_stack_depth_sym (decrease, saved_sym[reg],
                                                   saved_val[reg]);
    }
}

static void
pic32_su_mark_indirect_calls (void)
{
  pic32_su_new_op (SU_OP_MARK_INDIRECT_CALLS, 0, 0, 0);
}

static void
pic32_su_mark_indirect_calls_1 (void)
{
  PIC32_STACK_CHECK (stack_depth >= 0);

  su_info->flags |= SU_INDIRECT_CALLS;

  if (flag_debug)
    printf ("\t\thas indirect calls\n");
}

#if defined(TARGET_IS_PIC32MX)

static void
pic32_su_handle_mips_insn (const struct mips_opcode        *opcode,
                           const struct mips_operand_token *t)
{
  const char *name = opcode->name;

restart:
  /* NOTE: we don't need to verify all the tokens here (e.g. commas) b/c
   *       this function is only called for successfully matched
   *       (i.e. valid) insns */
  if (streq (name, "li"))
    {
      gas_assert (t[0].type == OT_REG && t[2].type == OT_INTEGER);

      if (t[2].u.integer.value.X_op == O_constant)
        {
          /* don't print these as they are a lot and hardly any is pertinent
           * to stack usage analysis) */
          pic32_su_handle_mov (t[0].u.regno & RNUM_MASK,
                               t[2].u.integer.value.X_add_number);
        }
    }
  else if (streq (name, "addiu"))
    {
      gas_assert (t[0].type == OT_REG);

      /* start with the assumption that there are two operands */
      const int dst_regno = (t[0].u.regno & RNUM_MASK);
      int src_regno = dst_regno;
      const struct mips_operand_token *imm_tok = t + 2;
      /* three operands? */
      if (imm_tok->type == OT_REG)
        {
          src_regno = (imm_tok->u.regno & RNUM_MASK);
          imm_tok += 2;
        }
      gas_assert (imm_tok->type == OT_INTEGER);

      /* add immediate value from SP (or subtract, using a negative value) */
      if (src_regno == REG_SP
          && imm_tok->u.integer.value.X_op == O_constant)
        {
          const long amount = imm_tok->u.integer.value.X_add_number;

          if (dst_regno == REG_SP)
            {
              pic32_su_debug_msg ("\t%s\t$sp, $sp, %ld\n", name, amount);
              pic32_su_alter_stack_depth (-amount);
            }
          else if (dst_regno == REG_FP)
            {
              pic32_su_debug_msg ("\t%s\t$%d, $sp, %ld\n",
                                  name, dst_regno, amount);
              pic32_su_copy_stack_depth (/*back*/FALSE, -amount);
            }
        }
      else if (dst_regno == src_regno
               && imm_tok->u.integer.value.X_op == O_symbol
               && imm_tok->u.integer.relocs[0] != BFD_RELOC_UNUSED)
        {
          pic32_su_handle_addiu_reloc (dst_regno,
                                       imm_tok->u.integer.value.X_add_symbol,
                                       imm_tok->u.integer.value.X_add_number,
                                       imm_tok->u.integer.relocs[0]);
        }
    }
  else if (mips_opts.mips16
           && (streq (name, "save") || streq (name, "restore"))) /* MIPS16 only*/
    {
      gas_assert (t[0].type == OT_INTEGER
                  && t[0].u.integer.value.X_op == O_constant);

      const int save = streq (name, "save");
      const long amount = t[0].u.integer.value.X_add_number;

      pic32_su_debug_msg ("\t%s\t%ld, ...\n", name, amount);
      pic32_su_alter_stack_depth (save ? amount : -amount);
    }
  else if (streq (name, "move"))
    {
      gas_assert (t[0].type == OT_REG && t[2].type == OT_REG);

      const int dst_regno = (t[0].u.regno & RNUM_MASK),
                src_regno = (t[2].u.regno & RNUM_MASK);

      /* stack pointer -> frame pointer */
      if (dst_regno == REG_FP && src_regno == REG_SP)
        {
          pic32_su_debug_msg ("\t%s\t$fp, $sp\n", name);
          pic32_su_copy_stack_depth (/*back*/FALSE, 0);
        }
      else if (dst_regno == REG_SP)
        {
          /* frame pointer -> stack pointer */
          if (src_regno == REG_FP)
            {
              pic32_su_debug_msg ("\t%s\t$sp, $fp\n", name);
              pic32_su_copy_stack_depth (/*back*/TRUE, 0);
            }
          else
            {
              /* a move to SP from another register than FP
               * indicates a variable adjustment */
              pic32_su_debug_msg ("\t%s\t$sp, $%d\n", name, src_regno);
              pic32_su_mark_variable_adjust ();
            }
        }
      else if (mips_opts.mips16 && src_regno == REG_GP)
        {
          /* track the move of $gp to another register to help with the
           * detection of calls in MIPS16 pos-independent code */
          /* model it as a 'load register' (i.e. load from $gp symbol) */
          pic32_su_debug_msg ("\t%s\t$%d, $%d\n", name, dst_regno, src_regno);
          pic32_su_handle_ldr (dst_regno, GP_SYM, 0, BFD_RELOC_UNUSED);
        }
    }
  else if (streq (name, "addu") || streq (name, "subu"))
    {
      gas_assert (t[0].type == OT_REG);
      /* hacky way to fix a hacky situation: the assembler accepts
       * also addu/subu with two operands (reg and imm) that actually
       * are addiu/subiu */
      if (t[t[3].type == OT_END ? 2 : 4].type == OT_INTEGER)
        {
          name = *name == 'a' ? "addiu" : "subiu";
          goto restart;
        }
      gas_assert (t[2].type == OT_REG);

      const int is_add = streq (name, "addu");
      const int dst_regno = (t[0].u.regno & RNUM_MASK);
      int src_regno, add_regno;

      /* two operands? */
      if (t[3].type == OT_END)
        {
          src_regno = dst_regno;
          add_regno = (t[2].u.regno & RNUM_MASK);
        }
      else
        {
          src_regno = (t[2].u.regno & RNUM_MASK);
          gas_assert (t[4].type == OT_REG);
          add_regno = (t[4].u.regno & RNUM_MASK);
        }

      /* addu/subu $sp, $sp, $reg */
      if (dst_regno == REG_SP && src_regno == REG_SP)
        {
          pic32_su_debug_msg ("\t%s\t$sp, $sp, $%d\n", name, add_regno);
          pic32_su_alter_stack_depth_reg (/*decrease*/is_add, add_regno);
        }
      /* similarly, but for $fp */
      else if (dst_regno == REG_FP && src_regno == REG_FP)
        {
          pic32_su_debug_msg ("\t%s\t$fp, $fp, $%d\n", name, add_regno);
          pic32_su_alter_saved_stack_depth_reg (/*decrease*/is_add, add_regno);
        }
    }
  else if (streq (name, "lw"))
    {
      gas_assert (t[0].type == OT_REG);

      const int regno = (t[0].u.regno & RNUM_MASK);

      /* lw $xx,.Lbl or lw $xx,%call/got[16](func_name)($gp)*/
      if (t[2].type == OT_INTEGER && t[2].u.integer.value.X_op == O_symbol
          && (t[2].u.integer.relocs[0] == BFD_RELOC_UNUSED
           || ((t[2].u.integer.relocs[0] == (mips_opts.mips16 ? BFD_RELOC_MIPS16_CALL16
                                                              : BFD_RELOC_MIPS_CALL16)
                || t[2].u.integer.relocs[0] == (mips_opts.mips16 ? BFD_RELOC_MIPS16_GOT16
                                                                 : BFD_RELOC_MIPS_GOT16))
                && t[4].type == OT_REG && pic32_su_gp_or_equ (t[4].u.regno & RNUM_MASK))))
        {
          /* print only the loads with call/got[16] relocs (the others are
           * too many and generally not pertinent to stack usage analysis) */
          if (t[2].u.integer.relocs[0] != BFD_RELOC_UNUSED)
            pic32_su_debug_msg ("\t%s\t$%d, %%%s%s(%s)($%d)\n", name, regno,
                                (t[2].u.integer.relocs[0]
                                   == (mips_opts.mips16 ? BFD_RELOC_MIPS16_GOT16
                                                        : BFD_RELOC_MIPS_GOT16) ?
                                "got" : "call"), (mips_opts.mips16 ? "" : "16"),
                                S_GET_NAME (t[2].u.integer.value.X_add_symbol),
                                (t[4].u.regno & RNUM_MASK));

          pic32_su_handle_ldr (regno,
                               t[2].u.integer.value.X_add_symbol,
                               t[2].u.integer.value.X_add_number,
                               t[2].u.integer.relocs[0]);
        }
    }
  else if (streq (name, "jalr") || streq (name, "jr")        /* MIPS32/MIPS16 */
           || streq (name, "jalrs") || streq (name, "jrc"))  /* microMIPS */
    {
      gas_assert (t[0].type == OT_REG);

      const int regno = t[0].u.regno & RNUM_MASK;

      /* ignore jr $ra (i.e. returns) */
      if (!(regno == REG_RA && streq (name, "jr")))
        {
          pic32_su_debug_msg ("\t%s\t$%d\n", name, regno);

          /* if reg value was defined by the prev insn w/ a BFD_RELOC_MIPS_CALL16
           * reloc is not a "real" indirect call, but a regular PIC call */
          if (!(saved_ino + 1 == pic32_insn_no && regno < PIC32_NUM_REGS
                && (saved_regs & (1 << regno)) && saved_sym[regno]
                && saved_reloc[regno] == (mips_opts.mips16 ? BFD_RELOC_MIPS16_CALL16
                                                           : BFD_RELOC_MIPS_CALL16)))
            pic32_su_mark_indirect_calls ();
        }
    }
}

#endif /* defined(TARGET_IS_PI32MX) */

static void
pic32_su_process_ops (void)
{
  /* execute the delayed ops (also free the memory used by them) */
  pic32_su_op *op, *next;
  for (op = pic32_su_ops; op; op = next)
    {
      /* debug messages are always printed
       * (i.e. even if stack usage was disabled due to an error) */
      if (op->opcode == SU_OP_DEBUG_MSG)
        {
          printf ("%s", (char *) op->operands[0]);
          free ((void *) op->operands[0]);
        }
      else
        /* the rest of operations are executed only if stack usage is enabled */
        if (pic32_gen_stack_usage == STACK_USAGE_ENABLED)
        switch (op->opcode)
          {
            case SU_OP_ALTER_STACK_DEPTH:       /* addend */
              pic32_su_alter_stack_depth_1 ((int) op->operands[0]);
              break;
            case SU_OP_COPY_STACK_DEPTH:        /* back, addend  */
              pic32_su_copy_stack_depth_1 ((bfd_boolean) op->operands[0],
                                          (int) op->operands[1]);
              break;
            case SU_OP_ALTER_SAVED_STACK_DEPTH: /* addend        */
              pic32_su_alter_saved_stack_depth_1 ((int) op->operands[0]);
              break;
            case SU_OP_MARK_VARIABLE_ADJUST:    /* (no operands) */
              pic32_su_mark_variable_adjust_1 ();
              break;
            case SU_OP_MARK_INDIRECT_CALLS:     /* (no operands) */
              pic32_su_mark_indirect_calls_1 ();
              break;
            case SU_OP_ALTER_STACK_DEPTH_SYM:   /* decrease, sym, addend */
              pic32_su_alter_stack_depth_sym_1 ((bfd_boolean) op->operands[0],
                                                (symbolS *) op->operands[1],
                                                op->operands[2]);
              break;
            case SU_OP_ALTER_SAVED_STACK_DEPTH_SYM:/* decrease, sym, addend */
              pic32_su_alter_saved_stack_depth_sym_1 ((bfd_boolean) op->operands[0],
                                                      (symbolS *) op->operands[1],
                                                      op->operands[2]);
              break;
            default:
              PIC32_STACK_CHECK_NORET (0);
          }

      /* always advance to the next op & free the crt op memory */
      next = op->next;
      free (op);
    }

  /* done freeing the list of ops */
  pic32_su_ops = pic32_su_ops_tail = NULL;

  /* a safety measure: if the end stack depth is negative but in abs value
   * is greater than the calculated SU value, use the maximum value
   * (this happens on some optimized code where the stack cleanup is seen
   * before the stack allocation) */
  if (su_info && stack_depth < 0 && (int) su_info->size < -stack_depth)
    {
      if (flag_debug)
        as_warn (_("-stack_depth (%d) > inferred stack size (%u) => "
                 "use it as the stack size of function %s\n"),
                 stack_depth, su_info->size, su_info->name);
      su_info->size = -stack_depth;
      su_info->flags |= SU_INACCURATE;
  }

#if defined(TARGET_IS_PIC32MX)
  /* another safety net (MIPS-only): if the calculated frame size is
   * smaller than the one specified by the .frame directive, use that
   * value and mark the stack usage info as probably inaccurate */
  if (su_info && su_info->size < mips_frame_size)
    {
      if (flag_debug)
        as_warn (_(".frame size (%u) > inferred stack size (%u) => "
                 "use it as the stack size of function %s\n"),
                 mips_frame_size, su_info->size, su_info->name);
      su_info->size = mips_frame_size;
      su_info->flags |= SU_INACCURATE;
    }
#endif

  if (pic32_gen_stack_usage == STACK_USAGE_ENABLED && su_info)
    {
      /* check that the stack usage for the function
       * was calculated correctly */
      PIC32_STACK_CHECK_NORET (stack_depth == 0);
    }

  /* re-enable the stack usage gen flag, if disabled for prev. function */
  if (pic32_gen_stack_usage == STACK_USAGE_DISABLED_CRTFUN)
    {
      pic32_gen_stack_usage = STACK_USAGE_ENABLED;
      stack_depth = saved_stack_depth = 0;
    }
}

static void
pic32_su_disable_gen_stack_usage (bfd_boolean whole_file)
{
  if (whole_file)
    {
      /* if disabling the generation of the stack usage info for the whole
       * file, release all the info gathered until this point */
      stack_usage_info *sui, *next_sui;
      for (sui = su_infos; sui; sui = next_sui)
        {
          next_sui = sui->next;
          free (sui);
        }
      su_infos = NULL;

      /* and disable the stack usage generation completely */
      pic32_gen_stack_usage = STACK_USAGE_DISABLED;
    }
  else
    {
      /* this prevents further processing/warnings for this function */
      pic32_gen_stack_usage = STACK_USAGE_DISABLED_CRTFUN;
    }
}

/*
 * Writes the stack usage header section (one per object):

    .section    .xc_stack_usage.hdr
    .byte       0xE     @ size
    .4byte      0x1     @ version
    .byte       0       @ reserved
    .4byte      0       @ reserved
    .4byte      0       @ reserved
*/
static void
pic32_write_su_hdr_section (void)
{
  /* use a writable line buffer, "big enough" for our purposes */
  const size_t sz = 32 + ((sizeof (SU_SECTION_HDR) + 7) & ~7);
  char *buf = (char *) xmalloc (sz);

  /* .section    .xc_stack_usage.hdr */
  snprintf (buf, sz, "%s", SU_SECTION_HDR);
  input_line_pointer = buf;
  S_CHANGE_SECTION (0);

  /* size */
  snprintf (buf, sz, "0x%x", SU_INFO_HDR_SIZE);
  input_line_pointer = buf;
  cons (1);

  /* version */
  snprintf (buf, sz, "0x%x", SU_VERSION);
  input_line_pointer = buf;
  cons (4);

  /* reserved */
  snprintf (buf, sz, "0");
  input_line_pointer = buf;
  cons (1);

  /* reserved */
  snprintf (buf, sz, "0");
  input_line_pointer = buf;
  cons (4);

  /* reserved */
  snprintf (buf, sz, "0");
  input_line_pointer = buf;
  cons (4);

  free (buf);
}

/*
 * Writes the stack usage for a function using the following format:

    .section    .xc_stack_usage
    .4byte      f1          @ function address
    .ascii      "f1\000"    @ function name
    .4byte      0x100       @ total used stack
    .4byte      0x0         @ flags
    .byte       0x1         @ type of memory
*/
static void
pic32_write_su_section (stack_usage_info *sui)
{
  /* ignore any "artificial functions" */
  if (!strncmp (sui->name, SU_FN_PREFIX, strlen (SU_FN_PREFIX)))
    {
      as_warn (_("discarded stack usage info for artificial function"));
      return;
    }

  /* use a "big enough" (for our purposes) line buffer */
  const size_t sz = 32 + ((strlen (sui->name) + 7) & ~7);
  char *buf = (char *) xmalloc (sz);

  /* .section    .xc_stack_usage */
  snprintf (buf, sz, "%s", SU_SECTION);
  input_line_pointer = buf;
  S_CHANGE_SECTION (0);

  /* function address */
  snprintf (buf, sz, "%s", sui->name);
  input_line_pointer = buf;
  cons (4);

  /* function name */
  snprintf (buf, sz, "\"%s\"", sui->name);
  input_line_pointer = buf;
  stringer (8+1);

  /* stack size */
  snprintf (buf, sz, "0x%x", sui->size);
  input_line_pointer = buf;
  cons (4);

  /* flags */
  snprintf (buf, sz, "0x%x", sui->flags);
  input_line_pointer = buf;
  cons (4);

  /* kind of allocation */
  snprintf (buf, sz, "0x%x", (unsigned) sui->kind);
  input_line_pointer = buf;
  cons (1);

  free (buf);
}

static void
pic32_su_write_stack_usage_sections (void)
{
  stack_usage_info *sui;

  /* process the su ops for the last function */
  pic32_su_process_ops ();

  /* if debugging, dump the gathered info at stdout */
  if (flag_debug)
    {
      printf ("mchp-stack-usage begin\n");
      for (sui = su_infos; sui; sui = sui->next)
        {
          printf ("%-20s\t%u\t%-16s", sui->name, sui->size,
                  su_kind_desc[sui->kind]);
          if (sui->flags & SU_INDIRECT_CALLS)
            printf ("\t(icalls)");
          if (sui->flags & SU_INACCURATE)
            printf ("\t(inaccu)");
          printf ("\n");
        }
      printf ("mchp-stack-usage end\n");
    }

  /* at least one function was found in the source file */
  if (su_infos)
    {
      /* turn off the stack usage flag so that the new sections we're about */
      /* to generate are not interpreted as existing in the original source */
      pic32_gen_stack_usage = STACK_USAGE_DISABLED;

      pic32_write_su_hdr_section ();

      for (sui = su_infos; sui; sui = sui->next)
        pic32_write_su_section (sui);
    }

  pic32_su_disable_gen_stack_usage (TRUE);
}
