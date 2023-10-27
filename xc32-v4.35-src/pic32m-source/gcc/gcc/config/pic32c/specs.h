/* Definitions of target machine for GNU compiler.
   For ARM with ELF obj format.
   Copyright (C) 2017, 2018 Free Software Foundation, Inc.
   Contributed by L Ghica <lavinia.ghica@microchip.com>

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include "config/mchp-cci/cci-backend.h"

#ifndef MCHP_CCI_CC1_SPEC
#error MCHP_CCI_CC1_SPEC not defined
#endif

#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC  \
    "%(cpp)"

#undef CC1_SPEC
#define CC1_SPEC             \
    "%(cc1_inst_set)"        \
    "%(cc1_device)"          \
    "%(cc1_fpu_device)"      \
    "%(cc1_debug)"           \
    "%(cc1_save_temps)"      \
    "%(cc1_smartio)"         \
    "%(cc1_config_data)"     \
    "%(cc1_xclm_spec)"       \
    "%(pic32_cmsis_include)" \
    "%(mcc_include)"         \
    "%(mchp_cci_cc1_spec)"

#undef CC1PLUS_SPEC
#define CC1PLUS_SPEC         \
    "%(pic32_cmsis_include)" \
    "%(mcc_include)"


#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS                                                  \
  { "cc1_inst_set", SUBTARGET_CC1_INST_SET_SPEC },                             \
  { "cc1_device", SUBTARGET_CC1_DEVICE_SPEC },                                 \
  { "cc1_fpu_device", SUBTARGET_CC1_FPU_DEVICE_SPEC },                         \
  { "cc1_debug", SUBTARGET_CC1_DEBUG_SPEC },                                   \
  { "cc1_save_temps", SUBTARGET_CC1_SAVE_TEMPS_SPEC },                         \
  { "cc1_smartio", SUBTARGET_CC1_SMARTIO_SPEC },                               \
  { "cc1_config_data", SUBTARGET_CC1_CONFIG_DATA_SPEC },                       \
  { "cc1_xclm_spec", SUBTARGET_CC1_XCLM_SPEC },                                \
  { "pic32c_lib", SUBTARGET_PIC32C_LIB_SPEC },                                 \
  { "endianness", SUBTARGET_ENDIANNESS_SPEC },                                 \
  { "asm_arch", SUBTARGET_ASM_ARCH_SPEC },                                     \
  { "asm_float", ASM_FLOAT_SPEC },                                             \
  { "linker_script", SUBTARGET_LINKER_SCRIPT_SPEC },                           \
  { "linker_smartio", SUBTARGET_LINKER_SMARTIO_SPEC },                         \
  { "subtarget_extra_asm_spec", SUBTARGET_EXTRA_ASM_SPEC },                    \
  { "subtarget_asm_float_spec", SUBTARGET_ASM_FLOAT_SPEC },                    \
  { "subtarget_extra_link_spec", SUBTARGET_EXTRA_LINK_SPEC },                  \
  { "pic32_cmsis_include",      PIC32_CMSIS_INCLUDE_SPEC},                     \
  { "pic32_cmsis_include_m",    PIC32_CMSIS_INCLUDE_M_SPEC},                   \
  { "pic32_cmsis_include_a",    PIC32_CMSIS_INCLUDE_A_SPEC},                   \
  { "mcc_include",      MCC_INCLUDE_SPEC},                                     \
  { "mchp_cci_cc1_spec", MCHP_CCI_CC1_SPEC },                                  \
  SUBSUBTARGET_EXTRA_SPECS

#undef SUBTARGET_EXTRA_ASM_SPEC
#define SUBTARGET_EXTRA_ASM_SPEC \
    "%{mabi=apcs-gnu|mabi=atpcs: -meabi=gnu;: -meabi=5}"

#undef SUBTARGET_ASM_FLOAT_SPEC
#define SUBTARGET_ASM_FLOAT_SPEC \
    "%(asm_float)"

/* MERGE-NOTES: our asm specs don't play well with the arch extensions.
   these may pass arch extensions like armv7e-m+fp to the assembler, which
   isn't expected to handle them. */
#if 0
#undef ASM_SPEC
#define ASM_SPEC        \
    "%(endianness)"     \
    "%(asm_arch)"       \
    "%(cc1_fpu_device)" \
    "%(subtarget_asm_float_spec)" \
    "%(subtarget_extra_asm_spec) "
#endif

#undef LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC \
    "%(pic32c_lib)"

#undef LINK_SPEC
#define LINK_SPEC                                                              \
  "%(endianness)"                                                              \
  "%(linker_smartio)"                                                          

/* Originally from gcc.c, but with added %(linker_script) */
/* -u* was put back because both BSD and SysV seem to support it.  */
/* %{static:} simply prevents an error message if the target machine
   doesn't handle -static.  */
/* We want %{T*} after %{L*} and %D so that it can be used to specify linker
   scripts which exist in user specified directories, or in standard
   directories.  */
/* We pass any -flto flags on to the linker, which is expected
   to understand them.  In practice, this means it had better be collect2.  */
/* %{e*} includes -export-dynamic; see comment in common.opt.  */
#ifndef LINK_COMMAND_SPEC
#define LINK_COMMAND_SPEC "\
%{!fsyntax-only:%{!c:%{!M:%{!MM:%{!E:%{!S:\
    %(linker) " \
    LINK_PLUGIN_SPEC \
   "%{flto|flto=*:%<fcompare-debug*} \
    %{flto} %{fno-lto} %{flto=*} %l " LINK_PIE_SPEC \
   "%{fuse-ld=*:-fuse-ld=%*} " LINK_COMPRESS_DEBUG_SPEC \
   "%X %{o*} %{e*} %{N} %{n} %{r}\
    %{s} %{t} %{u*} %{z} %{Z} %{!nostdlib:%{!nostartfiles:%S}} \
    %{static:} %{L*} %(mfwrap) %(link_libgcc) " \
    VTABLE_VERIFICATION_SPEC " " SANITIZER_EARLY_SPEC " %o " CHKP_SPEC " \
    %{fopenacc|fopenmp|%:gt(%{ftree-parallelize-loops=*:%*} 1):\
	%:include(libgomp.spec)%(link_gomp)}\
    %{fcilkplus:%:include(libcilkrts.spec)%(link_cilkrts)}\
    %{fgnu-tm:%:include(libitm.spec)%(link_itm)}\
    %(mflib) " STACK_SPLIT_SPEC "\
    %{fprofile-arcs|fprofile-generate*|coverage:-lgcov} " SANITIZER_SPEC " \
    %{!nostdlib:%{!nodefaultlibs:%(link_ssp) %(link_gcc_c_sequence)}}\
    %{!nostdlib:%{!nostartfiles:%E}} %{T*} %(linker_script) \n%(post_link) }}}}}}"
#endif
#ifndef LINK_COMMAND_SPEC_SUPPRESS_DEFAULT_SCRIPT
#define LINK_COMMAND_SPEC_SUPPRESS_DEFAULT_SCRIPT "\
%{!fsyntax-only:%{!c:%{!M:%{!MM:%{!E:%{!S:\
    %(linker) " \
    LINK_PLUGIN_SPEC \
   "%{flto|flto=*:%<fcompare-debug*} \
    %{flto} %{fno-lto} %{flto=*} %l " LINK_PIE_SPEC \
   "%{fuse-ld=*:-fuse-ld=%*} " LINK_COMPRESS_DEBUG_SPEC \
   "%X %{o*} %{e*} %{N} %{n} %{r}\
    %{s} %{t} %{u*} %{z} %{Z} %{!nostdlib:%{!nostartfiles:%S}} \
    %{static:} %{L*} %(mfwrap) %(link_libgcc) " \
    VTABLE_VERIFICATION_SPEC " " SANITIZER_EARLY_SPEC " %o " CHKP_SPEC " \
    %{fopenacc|fopenmp|%:gt(%{ftree-parallelize-loops=*:%*} 1):\
	%:include(libgomp.spec)%(link_gomp)}\
    %{fcilkplus:%:include(libcilkrts.spec)%(link_cilkrts)}\
    %{fgnu-tm:%:include(libitm.spec)%(link_itm)}\
    %(mflib) " STACK_SPLIT_SPEC "\
    %{fprofile-arcs|fprofile-generate*|coverage:-lgcov} " SANITIZER_SPEC " \
    %{!nostdlib:%{!nodefaultlibs:%(link_ssp) %(link_gcc_c_sequence)}}\
    %{!nostdlib:%{!nostartfiles:%E}} %{T*} \n%(post_link) }}}}}}"
#endif

/* FIXME: this should be moved to device spec files rather than matching
   options. */
#define PIC32_CMSIS_INCLUDE_M_SPEC " -isystem %R/include/CMSIS/Core/Include "
#define PIC32_CMSIS_INCLUDE_A_SPEC " -isystem %R/include/CMSIS/Core_A/Include "
#define PIC32_CMSIS_INCLUDE_SPEC                                               \
  " %{mprocessor=SAMA5*|mcpu=cortex-a*|march=armv7-a*: "                       \
  "%(pic32_cmsis_include_a); :%(pic32_cmsis_include_m)}"                       

#define MCC_INCLUDE_SPEC \
  " %{!minclude-legacy-headers: -D__XC32_INCLUDE_MCC  -isystem %R/include_mcc \
      ;: -D__XC32_INCLUDE_LEGACY } "

#undef SUBTARGET_CPP_SPEC
#define SUBTARGET_CPP_SPEC                                                     \
  "%(pic32_cmsis_include)"                                                     \
  "%(mcc_include)"                                                             \
  " -D__USES_INITFINI__"

#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC                                                     \
  "%(cpp)"                                                                     \
  "%(pic32_cmsis_include)"                                                     \
  "%(mcc_include)"

/* Output an element in the static constructor array.  */
#undef TARGET_ASM_CONSTRUCTOR
#define TARGET_ASM_CONSTRUCTOR arm_elf_asm_constructor

#undef TARGET_ASM_DESTRUCTOR
#define TARGET_ASM_DESTRUCTOR arm_elf_asm_destructor

