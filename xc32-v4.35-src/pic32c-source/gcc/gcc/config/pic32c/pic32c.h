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

#ifndef __PIC32C_H
#define __PIC32C_H

#ifndef _BUILD_XC32_
#warning _BUILD_XC32_ should be defined in CXXFLAGS
#define _BUILD_XC32_ 1
#endif

#undef TARGET_MCHP_PIC32C
#define TARGET_MCHP_PIC32C 1

#undef _BUILD_MCHP_
#define _BUILD_MCHP_ 1

/* Include after _BUILD_MCHP_DEVEL_ set */
#include "pic32c-debug.h"

#include <stdint.h>
#undef SECTION_FLAGS_INT
#define SECTION_FLAGS_INT uint64_t

/* For version_string */
#include "version.h"

/* PIC32C specific definitions */
//macro to disable mpa by default//
#define Os_WITH_MPA "%{mprocessor=*: -mprocessor=%:last_of(-mprocessor %{mprocessor=*: %*} "     \
  "%<mprocessor=*)} ",                                                         \
    "%{mdfp=*: -mdfp=%:last_of(-mdfp %{mdfp=*: %*} %<mdfp=*)} "                \
  "%{mchp-stack-usage: -Wa,-mchp-stack-usage -Wl,--mchp-stack-usage} "         \
  "%{mchp-stack-usage: -Wa,-mchp-stack-usage -Wl,--mchp-stack-usage} "        \
  "%{Os:%{!mno-pa:-mpa}}"
#define Os_NO_MPA "%{mprocessor=*: -mprocessor=%:last_of(-mprocessor %{mprocessor=*: %*} "     \
  "%<mprocessor=*)} ",                                                         \
    "%{mdfp=*: -mdfp=%:last_of(-mdfp %{mdfp=*: %*} %<mdfp=*)} "                \
  "%{mchp-stack-usage: -Wa,-mchp-stack-usage -Wl,--mchp-stack-usage} "         \
  "%{mchp-stack-usage: -Wa,-mchp-stack-usage -Wl,--mchp-stack-usage} " 


#define PIC32C_SUBTARGET_OVERRIDE_OPTIONS pic32c_subtarget_override_options ()

#undef PIC32C_SUBTARGET_OPTION_OPTIMIZATION_TABLE
#define PIC32C_SUBTARGET_OPTION_OPTIMIZATION_TABLE \
   { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fpartial_inlining, NULL, 1 },

#define MCHP_EXTENDED_FLAG "|"
#define MCHP_PROG_FLAG MCHP_EXTENDED_FLAG "pm" MCHP_EXTENDED_FLAG
#define MCHP_DATA_FLAG MCHP_EXTENDED_FLAG "dm" MCHP_EXTENDED_FLAG
#define MCHP_CONST_FLAG MCHP_EXTENDED_FLAG "rd" MCHP_EXTENDED_FLAG
#define MCHP_SERIALMEM_FLAG MCHP_EXTENDED_FLAG "sm" MCHP_EXTENDED_FLAG
#define MCHP_RAMFUNC_FLAG MCHP_EXTENDED_FLAG "rf" MCHP_EXTENDED_FLAG
#define MCHP_PRST_FLAG MCHP_EXTENDED_FLAG "persist" MCHP_EXTENDED_FLAG
#define MCHP_BSS_FLAG MCHP_EXTENDED_FLAG "bss" MCHP_EXTENDED_FLAG
#define MCHP_MERGE_FLAG MCHP_EXTENDED_FLAG "mrg" MCHP_EXTENDED_FLAG
#define MCHP_NOLOAD_FLAG MCHP_EXTENDED_FLAG "nl" MCHP_EXTENDED_FLAG
#define MCHP_ALGN_FLAG MCHP_EXTENDED_FLAG "a" MCHP_EXTENDED_FLAG
#define MCHP_RALGN_FLAG MCHP_EXTENDED_FLAG "ra" MCHP_EXTENDED_FLAG
#define MCHP_ADDR_FLAG MCHP_EXTENDED_FLAG "addr" MCHP_EXTENDED_FLAG
#define MCHP_FCNN_FLAG MCHP_EXTENDED_FLAG "Nf" MCHP_EXTENDED_FLAG
#define MCHP_FCNS_FLAG MCHP_EXTENDED_FLAG "Sf" MCHP_EXTENDED_FLAG
#define MCHP_SFR_FLAG MCHP_EXTENDED_FLAG "sfr" MCHP_EXTENDED_FLAG
#define MCHP_NEAR_FLAG MCHP_EXTENDED_FLAG "near" MCHP_EXTENDED_FLAG
#define MCHP_KEEP_FLAG MCHP_EXTENDED_FLAG "keep" MCHP_EXTENDED_FLAG
#define MCHP_COHERENT_FLAG MCHP_EXTENDED_FLAG "coherent" MCHP_EXTENDED_FLAG
#define MCHP_REGION_FLAG MCHP_EXTENDED_FLAG "region" MCHP_EXTENDED_FLAG
#define MCHP_ITCM_FLAG MCHP_EXTENDED_FLAG "itcm" MCHP_EXTENDED_FLAG
#define MCHP_DTCM_FLAG MCHP_EXTENDED_FLAG "dtcm" MCHP_EXTENDED_FLAG
#define MCHP_NOPA_FLAG MCHP_EXTENDED_FLAG "nopa" MCHP_EXTENDED_FLAG

#define MCHP_IS_NAME_P(NAME, IS) (strncmp (NAME, IS, sizeof (IS) - 1) == 0)
#define MCHP_HAS_NAME_P(NAME, HAS) (strstr (NAME, HAS))

#define ENCODED_NAME_P(SYMBOL_NAME)                                            \
  ((SYMBOL_NAME[0] == MCHP_EXTENDED_FLAG[0])                                   \
     ? (strrchr (SYMBOL_NAME, MCHP_EXTENDED_FLAG[0]) - SYMBOL_NAME) + 1        \
     : 0)

/* Option definitions */

/* Check if smart-io is enabled */
#define TARGET_MCHP_SMARTIO_ENABLED (TARGET_MCHP_SMARTIO != 0)

/* Get the smart-io level (0 if disabled) */
#define TARGET_MCHP_SMARTIO_LEVEL (TARGET_MCHP_SMARTIO)

/* Definitions for smart-io implementation. */

#define SMARTIO_FORMAT_ID get_identifier ("smartio-fmt")
#define SMARTIO_SPEC_ID get_identifier ("smartio-spec")

/* True if tree is a smart-io encoded format. */
#define SMARTIO_FORMAT_P(NODE)                                                 \
  (TREE_CODE (NODE) == TREE_LIST                                               \
   && TREE_PURPOSE (NODE) == SMARTIO_FORMAT_ID)

/* True if tree is a smart-io encoded spec string. */
#define SMARTIO_SPEC_P(NODE)                                                   \
  (TREE_CODE (NODE) == TREE_LIST                                               \
   && TREE_PURPOSE (NODE) == SMARTIO_SPEC_ID)

/* Get operands of a smart-io spec. */
#define SMARTIO_FORMAT(NODE) (TREE_VALUE (NODE))
#define SMARTIO_SPEC(NODE) (TREE_VALUE (TREE_CHAIN (NODE)))
#define SMARTIO_SPEC_STRING(NODE)                                              \
  TREE_STRING_POINTER (TREE_OPERAND (TREE_OPERAND (SMARTIO_SPEC (NODE), 0), 0))

extern tree build_smartio_format (tree, tree);

/* Target Hooks definitions */

/*
** This is how to output a reference to a user-level label named NAME.
** `assemble_name_raw' uses this.
*/
#undef ASM_OUTPUT_LABELREF
#define ASM_OUTPUT_LABELREF(FILE, NAME)                                        \
  mchp_write_encoded_name ((FILE), (NAME))

#undef SUBTARGET_OVERRIDE_OPTIONS
#define SUBTARGET_OVERRIDE_OPTIONS PIC32C_SUBTARGET_OVERRIDE_OPTIONS

#undef TEXT_SECTION_ASM_OP
#define TEXT_SECTION_ASM_OP mchp_text_section_asm_op ()

#undef READONLY_DATA_SECTION_ASM_OP
#define READONLY_DATA_SECTION_ASM_OP                                           \
  mchp_rdata_section_asm_op () /* read-only data */

#undef DATA_SECTION_ASM_OP
#define DATA_SECTION_ASM_OP mchp_data_section_asm_op ()

#undef BSS_SECTION_ASM_OP
#define BSS_SECTION_ASM_OP mchp_bss_section_asm_op ()

#undef SBSS_SECTION_ASM_OP
#define SBSS_SECTION_ASM_OP mchp_sbss_section_asm_op ()

#undef SDATA_SECTION_ASM_OP
#define SDATA_SECTION_ASM_OP mchp_sdata_section_asm_op ()

/* The EABI specifies that constructors should go in .init_array.
   Other targets use .ctors for compatibility. For XC32, use the code attribute.
 */
#undef ARM_EABI_CTORS_SECTION_OP
#define ARM_EABI_CTORS_SECTION_OP "\t.section\t.init_array, code"
#define INIT_ARRAY_CONST 1
#undef ARM_EABI_DTORS_SECTION_OP
#define ARM_EABI_DTORS_SECTION_OP "\t.section\t.fini_array, code"
#define FINI_ARRAY_CONST 1
#undef ARM_CTORS_SECTION_OP
#define ARM_CTORS_SECTION_OP "\t.section\t.ctors, code"
#undef ARM_DTORS_SECTION_OP
#define ARM_DTORS_SECTION_OP "\t.section\t.dtors, code"

/* Define CTORS_SECTION_ASM_OP.  */
#undef CTORS_SECTION_ASM_OP

#undef DTORS_SECTION_ASM_OP
#ifndef IN_LIBGCC2
#define CTORS_SECTION_ASM_OP                                                   \
  (TARGET_AAPCS_BASED ? ARM_EABI_CTORS_SECTION_OP : ARM_CTORS_SECTION_OP)

#define DTORS_SECTION_ASM_OP                                                   \
  (TARGET_AAPCS_BASED ? ARM_EABI_DTORS_SECTION_OP : ARM_DTORS_SECTION_OP)
#else /* !defined (IN_LIBGCC2) */
/* In libgcc, CTORS_SECTION_ASM_OP must be a compile-time constant,
   so we cannot use the definition above.  */
#ifdef __ARM_EABI__
/* The .ctors section is not part of the EABI, so we do not define
   CTORS_SECTION_ASM_OP when in libgcc; that prevents crtstuff
   from trying to use it.  We do define it when doing normal
   compilation, as .init_array can be used instead of .ctors.  */
/* There is no need to emit begin or end markers when using
   init_array; the dynamic linker will compute the size of the
   array itself based on special symbols created by the static
   linker.  However, we do need to arrange to set up
   exception-handling here.  */
#undef CTOR_LIST_BEGIN
#undef CTOR_LIST_END
#define CTOR_LIST_BEGIN asm(ARM_EABI_CTORS_SECTION_OP)
#define CTOR_LIST_END /* empty */
#undef DTOR_LIST_BEGIN
#undef DTOR_LIST_END
#define DTOR_LIST_BEGIN asm(ARM_EABI_DTORS_SECTION_OP)
#define DTOR_LIST_END /* empty */
#else /* !defined (__ARM_EABI__) */
#define CTORS_SECTION_ASM_OP ARM_CTORS_SECTION_OP
#define DTORS_SECTION_ASM_OP ARM_DTORS_SECTION_OP
#endif /* !defined (__ARM_EABI__) */
#endif /* !defined (IN_LIBCC2) */

#ifndef TARGET_FINAL_INCLUDES
struct cpp_dir;
extern void pic32c_final_include_paths (struct cpp_dir *, struct cpp_dir *);
#define TARGET_FINAL_INCLUDES pic32c_final_include_paths
#endif

#undef TARGET_ASM_SELECT_SECTION
#define TARGET_ASM_SELECT_SECTION mchp_select_section

#undef TARGET_ASM_NAMED_SECTION
#define TARGET_ASM_NAMED_SECTION mchp_asm_named_section

#undef TARGET_SECTION_TYPE_FLAGS
#define TARGET_SECTION_TYPE_FLAGS mchp_section_type_flags

#undef PIC32C_SUBTARGET_ENCODE_SECTION_INFO
#define PIC32C_SUBTARGET_ENCODE_SECTION_INFO(decl, rtl, first)                 \
  pic32c_subtarget_encode_section_info (decl, rtl, first)

/* PIC32C predefined macros */
/* For the LANGUAGE macros, it is worth noting that the condition to
   check for assembler makes use of a global defined in
   c-family/c-pragma.h. The expansion of this occurs in
   config/arm/arm-c.c and rather than change that file, the code is
   added here. */
#undef SUBTARGET_CPU_CPP_BUILTINS
#define SUBTARGET_CPU_CPP_BUILTINS()                                           \
  do                                                                           \
    {                                                                          \
      builtin_define_std ("PIC32");                                            \
      builtin_define_std ("PIC32C");                                           \
      builtin_define ("__C32__");                                              \
      builtin_define ("__XC32");                                               \
      builtin_define ("__XC32__");                                             \
      builtin_define ("__XC");                                                 \
      builtin_define ("__XC__");                                               \
      if (cpp_get_options (parse_in)->lang == CLK_ASM)                         \
        {                                                                      \
          builtin_define_std ("LANGUAGE_ASSEMBLY");                            \
          builtin_define ("_LANGUAGE_ASSEMBLY");                               \
        }                                                                      \
      else if (c_dialect_cxx ())                                               \
        {                                                                      \
          builtin_define ("_LANGUAGE_C_PLUS_PLUS");                            \
          builtin_define ("__LANGUAGE_C_PLUS_PLUS");                           \
          builtin_define ("__LANGUAGE_C_PLUS_PLUS__");                         \
        }                                                                      \
      else                                                                     \
        {                                                                      \
          builtin_define_std ("LANGUAGE_C");                                   \
          builtin_define ("_LANGUAGE_C");                                      \
        }                                                                      \
      if (mchp_stack_in_tcm)                                                   \
        {                                                                      \
          builtin_define ("__XC32_STACK_IN_TCM__");                            \
          builtin_define ("__XC32_STACK_IN_TCM");                              \
        }                                                                      \
      if ((mchp_processor_string != NULL) && *mchp_processor_string)           \
        {                                                                      \
          char *proc, *p;                                                      \
          gcc_assert (strlen (mchp_processor_string) <= 32);                   \
          for (p = (char *) mchp_processor_string; *p; p++)                    \
            {                                                                  \
              if (*p == '-')                                                   \
                *p = '_';                                                      \
              *p = TOUPPER (*p);                                               \
            }                                                                  \
          proc = (char *) alloca (strlen (mchp_processor_string) + 6);         \
          gcc_assert (proc != NULL);                                           \
          sprintf (proc, "__%s", mchp_processor_string);                       \
          gcc_assert (strlen (proc) > 0);                                      \
          builtin_define (proc);                                               \
          sprintf (proc, "__%s__", mchp_processor_string);                     \
          gcc_assert (strlen (proc) > 0);                                      \
          builtin_define (proc);                                               \
          sprintf (proc, "PIC%s", mchp_processor_string);                      \
          gcc_assert (strlen (proc) > 0);                                      \
          builtin_define_std (proc);                                           \
          if (strncmp (mchp_processor_string, "32CZ", 4) == 0)                 \
            {                                                                  \
              builtin_define_std ("PIC32CZ");                                  \
            }                                                                  \
        }                                                                      \
      else                                                                     \
        {                                                                      \
          builtin_define ("__32CGENERIC__");                                   \
          builtin_define ("__32CGENERIC");                                     \
        }                                                                      \
                                                                               \
      builtin_define_with_int_value ("__C32_VERSION__", _XC32_VERSION_);     \
      builtin_define_with_int_value ("__XC32_VERSION__",_XC32_VERSION_);     \
      builtin_define_with_int_value ("__XC32_VERSION",_XC32_VERSION_);       \
      builtin_define_with_int_value ("__XC_VERSION__",_XC32_VERSION_);       \
      builtin_define_with_int_value ("__XC_VERSION",_XC32_VERSION_);         \
      mchp_init_cci (pfile);                                                   \
    }                                                                          \
  while (0)

/*
 *  Builtin functions descriptions
 */

enum pic32c_builtins
{
  PIC32C_BUILTIN_NOP = 1,
  PIC32C_BUILTIN_SOFTWARE_BREAKPOINT,

  /* smart-io builtins - must be contiguous. */
  PIC32C_BUILTIN_FPRINTF_S,
  PIC32C_BUILTIN_SMARTIO_FIRST = PIC32C_BUILTIN_FPRINTF_S,
  PIC32C_BUILTIN_SPRINTF_S,
  PIC32C_BUILTIN_SNPRINTF_S,
  PIC32C_BUILTIN_VFPRINTF_S,
  PIC32C_BUILTIN_VSPRINTF_S,
  PIC32C_BUILTIN_VSNPRINTF_S,
  PIC32C_BUILTIN_FSCANF_S,
  PIC32C_BUILTIN_SSCANF_S,
  PIC32C_BUILTIN_VFSCANF_S,
  PIC32C_BUILTIN_VSSCANF_S,
  PIC32C_BUILTIN_PRINTF_S,
  PIC32C_BUILTIN_VPRINTF_S,
  PIC32C_BUILTIN_SCANF_S,
  PIC32C_BUILTIN_VSCANF_S,
  PIC32C_BUILTIN_SMARTIO_LAST = PIC32C_BUILTIN_VSCANF_S,
  PIC32C_BUILTIN_MAX
};

#define PIC32C_BUILTIN_SMARTIO_N                                               \
  ((PIC32C_BUILTIN_SMARTIO_LAST - PIC32C_BUILTIN_SMARTIO_FIRST) + 1)
#define PIC32C_SMARTIO_INDEX(fcode) ((fcode) -PIC32C_BUILTIN_SMARTIO_FIRST)

/* ARM_BUILTIN_MAX value from enum arm_builtins */
extern unsigned int g_ARM_BUILTIN_MAX;

/* PIC32C target specific builtins have following fn codes:
 pic32c_fn_code = ARM_BUILTIN_MAX + <value from enum pic32c_builtins>;
 following two helper macros help with this transform */
#define BUILTIN_CODE_PIC32C_TO_ARM(code) (code) + (g_ARM_BUILTIN_MAX)
#define BUILTIN_CODE_ARM_TO_PIC32C(code) (code) - (g_ARM_BUILTIN_MAX)

/* Macros called from ARM equivalent functions to register
 PIC32C target specific builtin functions */
#undef PIC32C_SUBTARGET_INIT_BUILTINS
#define PIC32C_SUBTARGET_INIT_BUILTINS pic32c_subtarget_init_builtins

#undef PIC32C_SUBTARGET_EXPAND_BUILTIN
#define PIC32C_SUBTARGET_EXPAND_BUILTIN(code, exp, target)                     \
  pic32c_subtarget_expand_builtin (code, exp, target)

#undef PIC32C_SUBTARGET_BUILTIN_DECL
#define PIC32C_SUBTARGET_BUILTIN_DECL(code) pic32c_subtarget_builtin_decl (code)

#undef SUBTARGET_ASM_FILE_END
#define SUBTARGET_ASM_FILE_END() pic32c_file_end ()

#undef PIC32C_SUBTARGET_GIMPLE_FOLD_BUILTIN
#define PIC32C_SUBTARGET_GIMPLE_FOLD_BUILTIN(gsi)                              \
  pic32c_subtarget_gimple_fold_builtin (gsi)

/* PIC32C target specific option optimizations table 
   Fields are:
   { enum opt_levels , opt_index, arg, value}
   The option index and argument or enabled/disabled sense of the
   option, as passed to handle_generated_option.  If ARG is NULL and
   the option allows a negative form, the option is considered to be
   passed in negative form when the optimization level is not one of
   those in LEVELS (in order to handle changes to the optimization
   level with the "optimize" attribute).
*/
#undef PIC32C_SUBTARGET_OPTION_OPTIMIZATION_TABLE
#define PIC32C_SUBTARGET_OPTION_OPTIMIZATION_TABLE \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fpartial_inlining, NULL, 1 },\
    /*disable at Os*/ \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fcode_hoisting, NULL, 1 }, \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fipa_cp, NULL, 1 }, \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fipa_sra, NULL, 1 }, \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fipa_icf, NULL, 1 }, \
    { OPT_LEVELS_2_PLUS_SPEED_ONLY, OPT_fipa_bit_cp, NULL, 1 },


/* PIC32C target specific attributes table.
   Fields are:
   { name, min_len, max_len, decl_req, type_req, fn_type_req,
     affects_type_identity, handler, om_diagnostics }

   MERGE-TODO: affects_type_identity is new as of GCC8, and has initially
   been populated with 'false'. fix this as needed.
 */
#undef PIC32C_SUBTARGET_ATTRIBUTE_TABLE
#define PIC32C_SUBTARGET_ATTRIBUTE_TABLE                                       \
  /* { name, min_len, max_len, decl_req, type_req, fn_type_req,                \
   * handler,om_diagnostics } */                                               \
    {"address", 1, 1, false, false, false, false, pic32c_address_attribute, NULL},   \
    {"keep", 0, 0, false, false, false, false, pic32c_keep_attribute, NULL},         \
    {"space", 1, 1, false, false, false, false, pic32c_space_attribute, NULL},       \
    {"persistent", 0, 0, false, false, false, false, pic32c_persistent_attribute, NULL}, \
    {"tcm", 0, 0, false, false, false, false, pic32c_tcm_attribute, NULL},           \
    {"unique_section", 0, 0, true, false, false, false, pic32c_unique_section_attribute, NULL}, \
    {"noload", 0, 0, false, false, false, false, pic32c_noload_attribute, NULL},     \
    {"nocodecov", 0, 0, true, false, false, false, pic32c_nocodecov_attribute, NULL}, \
    {"unsupported", 0, 1, false, false, false, false, pic32c_unsupported_attribute, NULL}, \
    {"target_error", 1, 1, false, false, false, false, pic32c_target_error_attribute, NULL}, \
    {"nopa", 0, 0, true, false, false, false, pic32c_nopa_attribute, NULL}, \
    {"ramfunc", 0, 0,  false, true,  true,  pic32c_ramfunc_attribute, NULL},

/* The Microchip port has a few pragmas to define as well */
#undef REGISTER_SUBTARGET_PRAGMAS
#define REGISTER_SUBTARGET_PRAGMAS()                                           \
  {                                                                            \
    c_register_pragma (0, "config", mchp_handle_config_pragma);                \
    c_register_pragma (0, "nocodecov", mchp_handle_nocodecov_pragma);          \
    c_register_pragma (0, "nopa", mchp_handle_nopa_pragma);                    \
    c_register_pragma (0, "default_variable_attributes",     \
        mchp_handle_default_variable_attributes_pragma);     \
    c_register_pragma (0, "default_function_attributes",     \
        mchp_handle_default_function_attributes_pragma);     \
  }

/* set path to linker for collect2 wrapper */
#undef COLLECT2_RELATIVE_LD_FILE_NAME
#define COLLECT2_RELATIVE_LD_FILE_NAME "../../../../bin/xc32-ld"

#undef COLLECT2_RELATIVE_PA_FILE_NAME
#define COLLECT2_RELATIVE_PA_FILE_NAME "../../../../bin/bin/pic32c-pa"

#undef TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P
#define TARGET_ATTRIBUTE_TAKES_IDENTIFIER_P pic32c_attribute_takes_identifier_p

#define XCLM_FULL_CHECKOUT 1

/* Default spec definitions */

/* Base options for arch/fpu - should correspond to SUBTARGET_CPU_DEFAULT. */
#define PIC32C_BASE_ARCH "march=armv6s-m"
#define PIC32C_BASE_FLOAT_ABI "mfloat-abi=soft"

/* Override default arch rather than provide explicit march default -
   avoiding conflicts with mcpu given in spec files.
   This option (from config/arm/arm-arches.def) must agree with
   PIC32C_BASE_ARCH. */
#undef SUBTARGET_CPU_DEFAULT
#define SUBTARGET_CPU_DEFAULT TARGET_CPU_cortexm0plus

/* MERGE-NOTES: we used to set SUBTARGET_CPU_DEFAULT and check that
   in the ARM backend. the logic to set the defaults has changed; for
   now we'll just override TARGET_CPU_DEFAULT to what we want. */
#undef TARGET_CPU_DEFAULT
#define TARGET_CPU_DEFAULT SUBTARGET_CPU_DEFAULT

#undef TARGET_DEFAULT_FLOAT_ABI
#define TARGET_DEFAULT_FLOAT_ABI ARM_FLOAT_ABI_SOFT

/* OPTION_DEFAULT_SPECS is now there to allow explicit defaults added
   as part of the self_spec. this breaks our spec files for devices
   which defer to an existing -mcpu option, if present.
   So, we just blow it all away. */
#undef OPTION_DEFAULT_SPECS

/* Common spec snippets for default arch, fpu and abi settings.
   As these snippets are also used for the assembler, we must ensure that
   any arch/cpu/fpu/abi settings are explicitly provided, hence idioms like
   %{mcpu=*: -mcpu=%*}, since the collect options will be used to match,
   but are not by default also passed to the assembler. */
#define PIC32C_INST_SET_SPEC                                                   \
  "%{mcpu=*: -mcpu=%*; : %{march=*: -march=%*; : -" PIC32C_BASE_ARCH "}}"      \
  "%{!marm: -mthumb}"

/* Default FPU specs.
   float-abi defaults to soft, corresponding to MULTILIB_DEFAULTS. */
#define PIC32C_FLOAT_SPEC                                                      \
  "%{mfloat-abi=*: -mfloat-abi=%*; : -" PIC32C_BASE_FLOAT_ABI "} "             \
  "%{mfpu=*: -mfpu=%*} "

/* Indicate default (i.e. common) options for multilib. */
#undef MULTILIB_DEFAULTS
/*
#define MULTILIB_DEFAULTS                                                      \
  {                                                                            \
    PIC32C_BASE_ARCH, "mthumb", "mlittle-endian", PIC32C_BASE_FLOAT_ABI        \
  }
*/

#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC                                                     \
  "%{mfloat-abi=soft:%{mfloat-abi=hard: %e-mfloat-abi=soft and "               \
  "-mfloat-abi=hard may not be used together}}"

#undef SUBTARGET_CC1_INST_SET_SPEC
#define SUBTARGET_CC1_INST_SET_SPEC PIC32C_INST_SET_SPEC

#undef SUBTARGET_CC1_DEVICE_SPEC
#define SUBTARGET_CC1_DEVICE_SPEC ""

#undef SUBTARGET_CC1_FPU_DEVICE_SPEC
#define SUBTARGET_CC1_FPU_DEVICE_SPEC PIC32C_FLOAT_SPEC

#undef SUBTARGET_CC1_DEBUG_SPEC
#define SUBTARGET_CC1_DEBUG_SPEC "%{D__DEBUG : -mdebugger}"

#undef SUBTARGET_CC1_SAVE_TEMPS_SPEC
#define SUBTARGET_CC1_SAVE_TEMPS_SPEC "%{save-temps: -fverbose-asm}"

/* This used to handle the distinct msmart-io=level/m[no]-smart-io options.
   The two forms are now aliased, but this is kept for compatibility with
   existing device spec files which may define this spec. */
#undef SUBTARGET_CC1_SMARTIO_SPEC
#define SUBTARGET_CC1_SMARTIO_SPEC ""

#undef SUBTARGET_CC1_CONFIG_DATA_SPEC
#define SUBTARGET_CC1_CONFIG_DATA_SPEC ""

#undef SUBTARGET_CC1_XCLM_SPEC
#define SUBTARGET_CC1_XCLM_SPEC                                                \
  "%{fnofallback : -mno-fallback }"                                            \
  "%{-nofallback : -mno-fallback }"

#undef SUBTARGET_ASM_ARCH_SPEC
#define SUBTARGET_ASM_ARCH_SPEC PIC32C_INST_SET_SPEC

/* We require -mfpu=fpa as a default here to ensure that as does not
   default to VFP format for arch=armv6s-m. */
#undef ASM_FLOAT_SPEC
#define ASM_FLOAT_SPEC                                                         \
  "%{mapcs-float: -mfloat}"                                                    \
  "%{!mfpu=*: -mfpu=fpa}"

/* Under -msemihost we link in the rdimon library (from newlib) before
   libpic32c as this overrides stubs in the latter. */
#undef SUBTARGET_PIC32C_LIB_SPEC
#define SUBTARGET_PIC32C_LIB_SPEC                                              \
  " --start-group %{msemihost: %G -lrdimon} -lpic32c %G %L --end-group "

/* FIXME: heap_size is a workaround for linker requiring a heap but
   not providing a default.
   */
#undef SUBTARGET_EXTRA_LINK_SPEC
#define SUBTARGET_EXTRA_LINK_SPEC                                              \
  " --defsym=_min_heap_size=0x2000"

#undef SUBTARGET_ENDIANNESS_SPEC
#define SUBTARGET_ENDIANNESS_SPEC                                              \
  "%{!mlittle-endian | !mbig-endian: -EL}"                                     \
  "%{mlittle-endian: -EL} %{mbig-endian: -EB}"

#undef SUBTARGET_LINKER_SMARTIO_SPEC
#define SUBTARGET_LINKER_SMARTIO_SPEC                                          \
  "%{mno-smart-io: --no-smart-io} %{msmart-io=0: --no-smart-io}"

#undef SUBTARGET_LINKER_SCRIPT_SPEC
#define SUBTARGET_LINKER_SCRIPT_SPEC ""

/* We redefine these to keep crtbegin/crti but not crt0, which
   is replaced by device-specific startup. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC                                                         \
  " crti%O%s crtbegin%O%s "                                                    \
  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s} "

#undef ENDFILE_SPEC
#define ENDFILE_SPEC " crtend%O%s crtn%O%s"

/* Explicit defaults for arch/fpu/abi. */
#define ARCH_DEFAULT_SPEC                                                      \
  "%{!march=*:%{!mcpu=*: -march=armv6s-m}} "                                   \
  "%{!mfpu=*:%{!mfloat-abi=*: -mfloat-abi=soft};: %{!mfloat-abi=*: -mfloat-abi=hard}} "

/* Common spec functions */
extern const char *mchp_last_of (int, const char **);

/* Tell the ARM target about our spec processing functions. */
#undef SUBTARGET_EXTRA_SPEC_FUNCTIONS
#define SUBTARGET_EXTRA_SPEC_FUNCTIONS { "last_of", mchp_last_of },

/* Use DRIVER_SELF_SPECS to do any massaging of input options before
   they may be processed by device specs. FINAL_SELF_SPECS is
   used to provide defaults after they may include device spec additions. */
#undef DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS                                                      \
 Os_NO_MPA

/* We also add FINAL_SELF_SPECS to be processed by the driver after any
   user (i.e. device-specific) self_specs are run, before multilib selection.
   DRIVER_SELF_SPECS follows the option defaults and CL but not
   device spec file self_specs.

   Here, we add defaults if user specs did not supply them, and then
   call the usual machinery to handle 'canonical' arches for arm.
*/
#define FINAL_SELF_SPECS                                                       \
  ARCH_DEFAULT_SPEC, ARCH_CANONICAL_SPECS, TARGET_MODE_SPECS

/* The Code Coverage target hooks -----> */
#define TARGET_XCCOV_LIBEXEC_PATH pic32c_libexec_path
#define TARGET_XCCOV_ADJ_INS_POS  pic32c_adjust_insert_pos
#define TARGET_XCCOV_LD_CC_BITS   pic32c_ld_cc_bits
#define TARGET_XCCOV_CC_BITS_OFS  1
#define TARGET_XCCOV_SET_CC_BIT   pic32c_set_cc_bit
#define TARGET_XCCOV_BEGIN_INSTMT pic32c_begin_cc_instrument
#define TARGET_XCCOV_END_INSTMT   pic32c_end_cc_instrument
#define TARGET_XCCOV_LICENSED     pic32c_licensed_xccov_p
#define TARGET_XCCOV_EMIT_SECTION pic32c_emit_cc_section

#undef SUBTARGET_OVERRIDE_INTERNAL_OPTIONS
#define SUBTARGET_OVERRIDE_INTERNAL_OPTIONS                                    \
  do {                                                                         \
    /* Disable shrink-wrap if the RTL CC is used */                            \
    if (opts->x_mchp_codecov)                                                  \
      opts->x_flag_shrink_wrap = false;                                        \
  } while (0)

#undef SUBTARGET_CONDITIONAL_REGISTER_USAGE
#define SUBTARGET_CONDITIONAL_REGISTER_USAGE pic32c_cond_reg_usage ();

#undef TARGET_ASM_CODE_END
#define TARGET_ASM_CODE_END pic32c_asm_code_end
/* <----- End of Code Coverage defines */

/* MCHP stack-usage */
#define TARGET_STACK_USAGE_SECTION pic32c_emit_su_section

#undef SUBTARGET_INSERT_ATTRIBUTES
#define SUBTARGET_INSERT_ATTRIBUTES pic32c_insert_attributes

/* By default, the C_INCLUDE_PATH_ENV is "C_INCLUDE_PATH", however
   in a cross compiler, another environment variable might want to be used
   to avoid conflicts with the host any host C_INCLUDE_PATH */
#ifndef C_INCLUDE_PATH_ENV
#define C_INCLUDE_PATH_ENV "XC32_C_INCLUDE_PATH"
#endif

/* By default, the COMPILER_PATH_ENV is "COMPILER_PATH", however
   in a cross compiler, another environment variable might want to be used
   to avoid conflicts with the host any host COMPILER_PATH */
#ifndef COMPILER_PATH_ENV
#define COMPILER_PATH_ENV "XC32_COMPILER_PATH"
#endif

/* By default, the LIBRARY_PATH_ENV is "LIBRARY_PATH", however
   in a cross compiler, another environment variable might want to be used
   to avoid conflicts with the host any host LIBRARY_PATH */
#ifndef LIBRARY_PATH_ENV
#define LIBRARY_PATH_ENV "XC32_LIBRARY_PATH"
#endif

/* By default, the GCC_EXEC_PREFIX_ENV prefix is "GCC_EXEC_PREFIX", however
   in a cross compiler, another environment variable might want to be used
   to avoid conflicts with the host any host GCC_EXEC_PREFIX */
#ifndef GCC_EXEC_PREFIX_ENV
#define GCC_EXEC_PREFIX_ENV "XC32_EXEC_PREFIX"
#endif

#endif /* __PIC32C_H */
