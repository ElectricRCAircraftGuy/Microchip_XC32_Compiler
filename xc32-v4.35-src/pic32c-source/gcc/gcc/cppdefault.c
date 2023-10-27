/* CPP Library.
   Copyright (C) 1986-2018 Free Software Foundation, Inc.
   Contributed by Per Bothner, 1994-95.
   Based on CCCP program by Paul Rubin, June 1986
   Adapted to ANSI C, Richard Stallman, Jan 1987

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "cppdefault.h"

#ifndef NATIVE_SYSTEM_HEADER_COMPONENT
#define NATIVE_SYSTEM_HEADER_COMPONENT 0
#endif

#if defined (CROSS_DIRECTORY_STRUCTURE) && !defined (TARGET_SYSTEM_ROOT)
# undef LOCAL_INCLUDE_DIR
# undef NATIVE_SYSTEM_HEADER_DIR
#else
# undef CROSS_INCLUDE_DIR
#endif

/*
  similar with gcc/config/linux.h

  musl avoids problematic includes by rearranging the include directories.

  Even with this rearranging - to be able to search first into the
  pic32c/include/musl - we have to define the NATIVE_SYSTEM_HEADER_DIR relative
  to the GCC_INCLUDE_DIR. This because of how the add_standard_paths is
  implemented:

  if (sysroot && p->add_sysroot)
    continue;
  if (!filename_ncmp (p->fname, cpp_GCC_INCLUDE_DIR, len))

  add_standard_paths first installs (searches for headers) the
  non-sysroot-paths that start with cpp_GCC_INCLUDE_DIRi.
 */
#ifdef _BUILD_MCHP_

#ifndef GCC_INCLUDE_DIR
#error GCC_INCLUDE_DIR not defined
#endif

#ifndef NATIVE_SYSTEM_HEADER_DIR
#error NATIVE_SYSTEM_HEADER_DIR not defined
#endif

#ifdef TARGET_IS_PIC32C
#define MCHP_NATIVE_SYSTEM_HEADER_DIR                                         \
  GCC_INCLUDE_DIR "/../../../../../pic32c/" NATIVE_SYSTEM_HEADER_DIR
#define INCLUDE_PIC32M_LIBS
#else
#define MCHP_NATIVE_SYSTEM_HEADER_DIR                                         \
  GCC_INCLUDE_DIR "/../../../../../pic32mx/" NATIVE_SYSTEM_HEADER_DIR
#define INCLUDE_PIC32M_LIBS { "/include/pic32m-libs", 0, 0, 0, 1, 0 },
#endif

#define INCLUDE_DEFAULTS_MUSL_GPP                                             \
  {                                                                           \
    GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1, GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0  \
  },                                                                          \
      { GPLUSPLUS_TOOL_INCLUDE_DIR,        "G++", 1, 1,                       \
        GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 1 },                               \
      { GPLUSPLUS_BACKWARD_INCLUDE_DIR,    "G++", 1, 1,                       \
        GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0 },

#ifdef LOCAL_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_LOCAL                                           \
  { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 2 }, { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_LOCAL
#endif

#ifdef PREFIX_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_PREFIX { PREFIX_INCLUDE_DIR, 0, 0, 1, 0, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_PREFIX
#endif

#ifdef CROSS_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_CROSS { CROSS_INCLUDE_DIR, "GCC", 0, 0, 0, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_CROSS
#endif

#ifdef TOOL_INCLUDE_DIR
#define INCLUDE_DEFAULTS_MUSL_TOOL                                            \
  { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1, 0, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_TOOL
#endif

#ifdef NATIVE_SYSTEM_HEADER_DIR
#define INCLUDE_DEFAULTS_MUSL_NATIVE                                          \
  { MCHP_NATIVE_SYSTEM_HEADER_DIR, 0, 0, 0, 0, 2 },                           \
      { MCHP_NATIVE_SYSTEM_HEADER_DIR, 0, 0, 0, 0, 0 },
#else
#define INCLUDE_DEFAULTS_MUSL_NATIVE
#endif

#if defined(CROSS_DIRECTORY_STRUCTURE) && !defined(TARGET_SYSTEM_ROOT)
#undef INCLUDE_DEFAULTS_MUSL_LOCAL
#define INCLUDE_DEFAULTS_MUSL_LOCAL
#undef INCLUDE_DEFAULTS_MUSL_NATIVE
#define INCLUDE_DEFAULTS_MUSL_NATIVE
#else
#undef INCLUDE_DEFAULTS_MUSL_CROSS
#define INCLUDE_DEFAULTS_MUSL_CROSS
#endif

#undef INCLUDE_DEFAULTS
#define INCLUDE_DEFAULTS                      \
  {                                           \
    INCLUDE_DEFAULTS_MUSL_GPP                 \
    INCLUDE_DEFAULTS_MUSL_LOCAL               \
    INCLUDE_DEFAULTS_MUSL_PREFIX              \
    INCLUDE_DEFAULTS_MUSL_CROSS               \
    INCLUDE_DEFAULTS_MUSL_TOOL                \
    INCLUDE_DEFAULTS_MUSL_NATIVE              \
    INCLUDE_PIC32M_LIBS                       \
    { GCC_INCLUDE_DIR, "GCC", 0, 1, 0, 0 },   \
    { 0, 0, 0, 0, 0, 0 }                      \
  }
#endif

const struct default_include cpp_include_defaults[]
#ifdef INCLUDE_DEFAULTS
= INCLUDE_DEFAULTS;
#else
= {
#ifdef GPLUSPLUS_INCLUDE_DIR
    /* Pick up GNU C++ generic include files.  */
    { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1,
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0 },
#endif
#ifdef GPLUSPLUS_TOOL_INCLUDE_DIR
    /* Pick up GNU C++ target-dependent include files.  */
    { GPLUSPLUS_TOOL_INCLUDE_DIR, "G++", 1, 1,
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 1 },
#endif
#ifdef GPLUSPLUS_BACKWARD_INCLUDE_DIR
    /* Pick up GNU C++ backward and deprecated include files.  */
    { GPLUSPLUS_BACKWARD_INCLUDE_DIR, "G++", 1, 1,
      GPLUSPLUS_INCLUDE_DIR_ADD_SYSROOT, 0 },
#endif
#ifdef GCC_INCLUDE_DIR
    /* This is the dir for gcc's private headers.  */
    { GCC_INCLUDE_DIR, "GCC", 0, 0, 0, 0 },
#endif
#ifdef LOCAL_INCLUDE_DIR
    /* /usr/local/include comes before the fixincluded header files.  */
    { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 2 },
    { LOCAL_INCLUDE_DIR, 0, 0, 1, 1, 0 },
#endif
#ifdef PREFIX_INCLUDE_DIR
    { PREFIX_INCLUDE_DIR, 0, 0, 1, 0, 0 },
#endif
#ifdef FIXED_INCLUDE_DIR
    /* This is the dir for fixincludes.  */
    { FIXED_INCLUDE_DIR, "GCC", 0, 0, 0,
      /* A multilib suffix needs adding if different multilibs use
	 different headers.  */
#ifdef SYSROOT_HEADERS_SUFFIX_SPEC
      1
#else
      0
#endif
    },
#endif
#ifdef CROSS_INCLUDE_DIR
    /* One place the target system's headers might be.  */
    { CROSS_INCLUDE_DIR, "GCC", 0, 0, 0, 0 },
#endif
#ifdef TOOL_INCLUDE_DIR
    /* Another place the target system's headers might be.  */
    { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1, 0, 0 },
#endif
#ifdef NATIVE_SYSTEM_HEADER_DIR
    /* /usr/include comes dead last.  */
    { NATIVE_SYSTEM_HEADER_DIR, NATIVE_SYSTEM_HEADER_COMPONENT, 0, 0, 1, 2 },
    { NATIVE_SYSTEM_HEADER_DIR, NATIVE_SYSTEM_HEADER_COMPONENT, 0, 0, 1, 0 },
#endif
#ifdef TARGET_MCHP_PIC32MX
    { "/include/pic32m-libs", 0, 0, 0, 1, 0 },
#endif    
    { 0, 0, 0, 0, 0, 0 }
  };
#endif /* no INCLUDE_DEFAULTS */

#ifdef GCC_INCLUDE_DIR
const char cpp_GCC_INCLUDE_DIR[] = GCC_INCLUDE_DIR;
const size_t cpp_GCC_INCLUDE_DIR_len = sizeof GCC_INCLUDE_DIR - 8;
#else
const char cpp_GCC_INCLUDE_DIR[] = "";
const size_t cpp_GCC_INCLUDE_DIR_len = 0;
#endif

/* The configured prefix.  */
const char cpp_PREFIX[] = PREFIX;
const size_t cpp_PREFIX_len = sizeof PREFIX - 1;
const char cpp_EXEC_PREFIX[] = STANDARD_EXEC_PREFIX;

/* This value is set by cpp_relocated at runtime */
const char *gcc_exec_prefix;

/* Return true if the toolchain is relocated.  */
bool
cpp_relocated (void)
{
  static int relocated = -1;

  /* A relocated toolchain ignores standard include directories.  */
  if (relocated == -1)
    {
      /* Check if the toolchain was relocated?  */
      gcc_exec_prefix = getenv ("GCC_EXEC_PREFIX");
      if (gcc_exec_prefix)
       relocated = 1;
      else
       relocated = 0;
    }

  return relocated;
}
