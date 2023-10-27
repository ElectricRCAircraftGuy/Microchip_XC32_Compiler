/* Common hooks for XC32 compilers.
   Copyright (C) 2020
   Microchip Technology, Inc.

This file is part of Microchip XC compiler tool-chain.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* Called from DRIVER_SELF_SPEC for XC32 targets to cope with multiple 
   instances of an option.

   This is meant to deal with options that are used in device specs using the
   substitution syntax %{mopt=*: %*}, where multiple occurrences of mopt will lead
   to multiple substitutions.

   Use this in specs as ${mopt=*: -mopt=%:mchp_last_of(-mopt %* %<mopt=*0)}. The
   argument spec will be processed, removing all instances of mopt, and then
   the last of the -mopt arguments in the expansion of %* will be supplied as the
   unique instance of that option.

   Any usage must ensure that the flag name is the first argument, and that
   at least one flag is specified. 
*/

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "memmodel.h"
#include "tm_p.h"
#include "common/common-target.h"
#include "common/common-target-def.h"
#include "opts.h"
#include "flags.h"
#include "diagnostic.h"

/* Given an option name and list of at least one value for that option,
   return the last and warn about any mismatching options that will be 
   ignored. */
const char *
mchp_last_of(int argc, const char **argv)
{
  int i;
  gcc_assert (argc >= 2);

  for (i = 1; i < argc - 1; ++i) 
    {
      if (strcmp(argv[i], argv[argc-1]) != 0)
        {
           warning (0, "option %s=%s differs from last instance (%s=%s) and will be ignored",
                    argv[0], argv[i], argv[0], argv[argc-1]);
        }
    }
  return argv[argc-1];
}

