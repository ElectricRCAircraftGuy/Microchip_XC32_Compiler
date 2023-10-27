/* MIPS SCB Lite MEL GNU/Linux Configuration.
   Copyright (C) 2012 Free Software Foundation, Inc.

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

/* Override linux64.h to default to O32.  */
#undef DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS \
  BASE_DRIVER_SELF_SPECS, \
  LINUX_DRIVER_SELF_SPECS \
  " %{!EB:%{!EL:%(endian_spec)}}" \
  "%{!mabi=*: -mabi=32}"

/* We do not need to provide an explicit big-endian multilib.  */
#undef MULTILIB_DEFAULTS
#define MULTILIB_DEFAULTS { "EB", "mabi=32" }

/* The various C libraries each have their own subdirectory.  */
#undef SYSROOT_SUFFIX_SPEC
#define SYSROOT_SUFFIX_SPEC "%{march=xlp:/xlp}%{mel|EL:/el}"

#undef STARTFILE_PREFIX_SPEC
#define STARTFILE_PREFIX_SPEC                          \
  "%{mabi=32: /usr/local/lib/ /lib/ /usr/lib/}                 \
   %{mabi=64: /usr/local/lib64/ /lib64/ /usr/lib64/}"
