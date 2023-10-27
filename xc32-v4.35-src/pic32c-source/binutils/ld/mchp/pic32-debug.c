/* Implementation of the debug scope for the DEBUG_IN_SCOPE macro.

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

#include "config.h"
#include "bfd.h"		/* Needed for bfd_boolean. */
#include "pic32-debug.h"

#include <stddef.h>
#include <string.h>

#define MAX_SCOPES 10
static const char *scopes[MAX_SCOPES + 1];
static const char *SCOPE_ALL = "all";
static const char *SCOPE_EMPTY = "";

static size_t
pic32_debug_member_scopes (const char *name)
{
  size_t i;
  for (i = 1; (i <= MAX_SCOPES) && (scopes[i] != NULL); ++i) {
    if (strcmp (scopes[i], name) == 0)
      return i;
  }

  return 0; 
}

int
pic32_debug_scope_enabled_p (const char *name)
{
  if (scopes[0] != NULL)
    return 1;

  return pic32_debug_member_scopes (name);
}

void
pic32_debug_enable_scope (const char *name)
{
  if (scopes[0] != NULL)
    return;

  if ((name == NULL) || (strcmp (name, SCOPE_ALL) == 0)) {
    scopes[0] = SCOPE_ALL;
    return;
  }

  if (strcmp (name, SCOPE_EMPTY) == 0)
    return;

  size_t i;
  for (i = 1; i <= MAX_SCOPES; ++i) {
    /* Found the end of the set. */
    if (scopes[i] == NULL)
      break;

    /* Scope is already enabled. */
    if (strcmp (scopes[i], name) == 0)
      return;

    /* Found an empty slot in the set. */
    if (strcmp (scopes[i], SCOPE_EMPTY) == 0)
      break;
  }

  if (i > MAX_SCOPES)
    return;

  scopes[i] = name;
}

void
pic32_debug_disable_scope (const char *name)
{
  if (scopes[0] != NULL)
    return;

  if ((name == NULL) || (strcmp (name, SCOPE_EMPTY) == 0)
      || (strcmp (name, SCOPE_ALL) == 0))
    return;

  size_t i = pic32_debug_member_scopes (name);
  if (i != 0)
    scopes[i] = SCOPE_EMPTY;
}
