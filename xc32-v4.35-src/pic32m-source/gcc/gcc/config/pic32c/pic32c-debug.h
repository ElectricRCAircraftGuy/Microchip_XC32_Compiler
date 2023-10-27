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

#ifndef __PIC32C_DEBUG_H
#define __PIC32C_DEBUG_H

/* Define various macros for dumpfile/stderr debugging for development builds.
   All macros should guard code such that debug code can be statically
   eliminated by the compiler when _BUILD_MCHP_DEVEL_ is 0/undefined.

   Note the user is responsible to ensure that the tree-pretty-print/rtl
   headers are included as appropriate.
   */
#if _BUILD_MCHP_DEVEL_

/* Debug macros for development. When _BUILD_MCHP_DEVEL_ is set,
   expand MDBG(str) to look up "str" in the deferred -mdbg option string,
   returning non-zero if the option is present. Otherwise expands to literal 0.
   */
extern int pic32c_get_debug_option(const char *);
#define MDBG(str) pic32c_get_debug_option( #str )

/* Default output file for MDBG_ macros. Redfined to a specific file pointer
   to reroute output. Default is dump_file, or stderr if mdbg=stderr is specified.
   */
#define MDBG_DUMPFILE (MDBG(stderr) ? stderr : dump_file)

/* Standard prefix for MDBG_ macro output. Enabled with -mdbg=pfx. */
#ifndef MDBG_PREFIX
#define MDBG_PREFIX(str) "mdbg:%-8s [%s:%-5d]", #str , __func__, __LINE__
#endif

/* Print the given format string + args to dump if -mdbg=str is
   specified. */
#define MDBG_DUMP(str, ...)                                                    \
  do {                                                                         \
    FILE *dump = MDBG_DUMPFILE;                                                \
    if (MDBG(str) && dump) {                                                   \
      if (MDBG(pfx))                                                           \
        fprintf(dump, MDBG_PREFIX(str));                                       \
      fprintf(dump, "" __VA_ARGS__);                                           \
    }                                                                          \
  } while (0)

/* Print the given gimple expr plus optional format string + args to
   dump if -mdbg=str is specified. */
#define MDBG_EXPR(str, e, ...)                                                 \
  do {                                                                         \
    FILE *dump = MDBG_DUMPFILE;                                                \
    if (MDBG(str) && dump) {                                                   \
      if (MDBG(pfx))                                                           \
        fprintf(dump, MDBG_PREFIX(str));                                       \
      fprintf(dump, "" __VA_ARGS__);                                           \
      print_generic_expr(dump, e, TDF_VERBOSE | TDF_TREE);                     \
      fprintf(dump, "\n");                                                     \
    }                                                                          \
  } while (0)

/* Print the given gimple stmt plus optional format string + args to
   dump if -mdbg=str is specified. */
#define MDBG_STMT(str, e, ...)                                                 \
  do {                                                                         \
    FILE *dump = MDBG_DUMPFILE;                                                \
    if (MDBG(str) && dump) {                                                   \
      if (MDBG(pfx))                                                           \
        fprintf(dump, MDBG_PREFIX(str));                                       \
      fprintf(dump, "" __VA_ARGS__);                                           \
      print_generic_stmt(dump, e, TDF_VERBOSE | TDF_TREE);                     \
      fprintf(dump, "\n");                                                     \
    }                                                                          \
  } while (0)

/* Print the given rtl expression plus optional format string + args to
   dump if -mdbg=str is specified. */
#define MDBG_RTL(str, e, ...)                                                  \
  do {                                                                         \
    FILE *dump = MDBG_DUMPFILE;                                                \
    if (MDBG(str) && dump) {                                                   \
      if (MDBG(pfx))                                                           \
        fprintf(dump, MDBG_PREFIX(str));                                       \
      fprintf(dump, "" __VA_ARGS__);                                           \
      print_rtl_single(dump, e);                                               \
      fprintf(dump, "\n");                                                     \
    }                                                                          \
  } while (0)

#else /* !_BUILD_MCHP_DEVEL_ */

#define MDBG(str) 0
#define MDBG_DUMP(...) 
#define MDBG_EXPR(...)
#define MDBG_STMT(...)
#define MDBG_RTL(...)

#endif /* _BUILD_MCHP_DEVEL_ */

#endif /* __PIC32C_DEBUG_H */


