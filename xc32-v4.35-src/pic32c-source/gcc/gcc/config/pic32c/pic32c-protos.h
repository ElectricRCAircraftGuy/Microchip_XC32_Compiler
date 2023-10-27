/* Subroutines used for Microchip PIC32C code generation.
   Copyright (C) 1989, 1990, 1991, 1993, 1994, 1995, 1996, 1997, 1998,
   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.
   Contributed by Rathish C, rathish.chamukuttan@microchip.com

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


#ifndef __PIC32C_PROTOS_H
#define __PIC32C_PROTOS_H


/* Function Prototypes*/

extern void pic32c_subtarget_override_options(void);
extern void mchp_override_options_after_change (void);

extern void pic32c_expand_function_start (tree);

extern section *mchp_select_section
                  (tree decl, int reloc, unsigned HOST_WIDE_INT align ATTRIBUTE_UNUSED);

extern void mchp_write_encoded_name(FILE *, const char *);

// TODO: May not need to be exposed.
extern const char *mchp_strip_name_encoding
                  (const char *symbol_name);

extern void mchp_asm_named_section
                  (const char *pszSectionName, SECTION_FLAGS_INT flags, tree decl ATTRIBUTE_UNUSED);

extern int mchp_annotate_section_name_p (const char *sectionName, const char *fnVarName);

extern void mchp_subtarget_encode_section_info
                  (tree decl, rtx rtl, int first_seen ATTRIBUTE_UNUSED);

extern SECTION_FLAGS_INT mchp_section_type_flags
                   (tree decl, const char *name, int reloc ATTRIBUTE_UNUSED);

extern void pic32c_subtarget_encode_section_info
                  (tree decl, rtx rtl, int first_seen ATTRIBUTE_UNUSED);

extern tree mchp_get_smartio_fndecl (int);

extern const char * mchp_text_section_asm_op(void);
extern const char * mchp_data_section_asm_op(void);
extern const char * mchp_bss_section_asm_op(void);
extern const char * mchp_sbss_section_asm_op(void);
extern const char * mchp_sdata_section_asm_op(void);
extern const char * mchp_rdata_section_asm_op(void);

extern void pic32c_expand_function_start (tree);
extern void pic32c_file_end (void);


/* Attribute processing */
extern tree pic32c_address_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_unsupported_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_target_error_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_space_attribute (tree *decl, tree identifier, tree args,
                int flags ATTRIBUTE_UNUSED, bool *no_add_attrs);

extern tree pic32c_persistent_attribute(tree *, tree, tree, int, bool *);

extern tree pic32c_tcm_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_noload_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_nocodecov_attribute (tree *, tree, tree, int, bool *);

extern tree pic32c_nopa_attribute (tree *, tree, tree, int, bool *);

extern bool pic32c_attribute_takes_identifier_p (const_tree attr_id);

extern tree pic32c_keep_attribute(tree *decl, tree identifier ATTRIBUTE_UNUSED,
                                tree args, int flags ATTRIBUTE_UNUSED,
                                bool *no_add_attrs);

extern tree pic32c_ramfunc_attribute(tree *decl, tree identifier ATTRIBUTE_UNUSED,
                                     tree args ATTRIBUTE_UNUSED, int flags ATTRIBUTE_UNUSED,
                                     bool *no_add_attrs ATTRIBUTE_UNUSED);

extern tree pic32c_unique_section_attribute (tree *node, tree name ATTRIBUTE_UNUSED,
                          tree args ATTRIBUTE_UNUSED, int flags ATTRIBUTE_UNUSED,
                          bool *no_add_attrs);

extern void pic32c_set_default_type_attributes (tree type);
extern void pic32c_insert_attributes (tree decl, tree *attrs);
extern bool pic32c_function_attribute_inlinable_p (const_tree decl);

extern tree get_pic32c_tcm_attribute (tree);


/* Builtin functions */
extern void pic32c_subtarget_init_builtins (void);
extern rtx pic32c_subtarget_expand_builtin (unsigned int code,
                                            tree exp, rtx target);
extern tree pic32c_subtarget_builtin_decl (unsigned code);
extern bool pic32c_subtarget_gimple_fold_builtin (gimple_stmt_iterator*);
extern void pretty_tree_with_prototype(tree fndecl);
extern void close_builtins_h();
/* pragmas */
extern void mchp_handle_config_pragma(struct cpp_reader *);
extern void mchp_handle_nocodecov_pragma(struct cpp_reader *);
extern void mchp_handle_nopa_pragma(struct cpp_reader *);
extern void mchp_handle_default_variable_attributes_pragma (struct cpp_reader *pfile);
extern void mchp_handle_default_function_attributes_pragma (struct cpp_reader *pfile);
extern char* mchp_pragma_default_variable_section;
extern char* mchp_pragma_default_function_section;
/* CCI extensions */
extern void mchp_init_cci (struct cpp_reader *);

/* Code Coverage related */
extern void pic32c_reserve_registers (void);
extern void pic32c_cond_reg_usage (void);
extern void pic32c_start_function (tree);
extern rtx_insn *pic32c_adjust_insert_pos (basic_block bb, int prologue_bb, rtx_insn *where);
extern void pic32c_ld_cc_bits (unsigned offset);
extern void pic32c_set_cc_bit (unsigned bitno);
extern void pic32c_begin_cc_instrument (void);
extern void pic32c_end_cc_instrument (void);
extern void pic32c_asm_code_end (void);
extern int  pic32c_licensed_xccov_p (void);
extern void pic32c_emit_cc_section (const char *name);

/* MCHP stack usage related */
extern void pic32c_emit_su_section (const char *name);

extern rtl_opt_pass *make_pass_opt_imm_offset (gcc::context *ctxt);
extern rtl_opt_pass *make_pass_loop_exiting_edges (gcc::context *ctxt);
extern rtl_opt_pass *make_pass_loop_regrename (gcc::context *ctxt);

extern const char *pic32c_libexec_path;

#endif /* __PIC32C_PROTOS_H */
