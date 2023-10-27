/* ldver.h -- Header file for ldver.c.
   Copyright (C) 1991-2019 Free Software Foundation, Inc.

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
   MA 02110-1301, USA.  */

void ldversion (int);

#if defined(TARGET_IS_PIC32C) || defined(TARGET_IS_PIC32MX)
/* MERGE-TODO: uses of this seem to guard with 0, this one with TARGET_IS_PIC32C,
   which may effectively be 0 due to config issues. MIPS only stuff. */
extern char *pic32_resource_version;
extern bfd_boolean pic32_has_processor_option;
#endif
