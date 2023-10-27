/* A debug output system inspired by other systems.

  This file is part of the GNU Binutils.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
  MA 02110-1301, USA. */

/* After including this file, define the name of the scope with a
   string.

     #define DEBUG_SCOPE "something"

   Any use of the DEBUG macro after this definition will be
   conditional on the "something" scope being active.

   A scope is activated by calling pic32_debug_enable_scope, or by
   passing an argument to the --debug option.  Use of the --debug
   option is recommended.

   There are three special scopes: "all", "" (the empty string), and
   NULL.  The empty string is always ignored.  "all" and NULL are the
   same: they enable all scopes.  Once all scopes have been enabled,
   they cannot be disabled.

   In practice you will only want to enable scopes via the --debug
   option and avoid manually enabling/disabling scopes.  The ability
   to disable a scope is only provided for development purposes, but
   should not appear in production code.
 */

#ifndef PIC32_DEBUG_H
#define PIC32_DEBUG_H

extern int pic32_debug;	    /* Eventually this should be defined in
			       the pic32-debug.c file. */
extern bfd_boolean verbose;	/* This is the linker --verbose option. */

extern int pic32_debug_scope_enabled_p (const char *);
extern void pic32_debug_enable_scope (const char *);
extern void pic32_debug_disable_scope (const char *);

/* Write a log message unconditionally.  This should only be used
   within a DEBUG macro. */
#define LOG(format, args...)				\
  do { fprintf (stderr, format, ##args); } while (0)

/* Write output when --verbose has been supplied. */
#define DIAG(format, args...)					\
  do {								\
    if (verbose) { fprintf (stderr, format, ##args); }		\
  } while (0)

#define DEBUG_IN_SCOPE(SCOPE, X)				\
  do {								\
    if (pic32_debug && pic32_debug_scope_enabled_p (SCOPE))	\
      {	X; }							\
  } while (0)

#define DEBUG(X) DEBUG_IN_SCOPE(DEBUG_SCOPE, X)

#define PIC32_DEBUG(format, args...) \
  DEBUG_IN_SCOPE(DEBUG_SCOPE, LOG(format "\n", ##args))

#endif /* PIC32_DEBUG_H */
