/* Interface for the linker emulation code to call and use the pic32m
   emulation code.

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

#ifndef PIC32M_EMULTEMPL_H
#define PIC32M_EMULTEMPL_H

/* Needed for R_MIPS_PC32 in one of the fragments. */
#include "elf/mips.h"

/* Holds the build parameter values that are substituted as shell
   code.  The names should match the name of the variable used or
   where it is supposed to be used. */
struct pic32m_build_emulation_parameters {
  char *emulation_name;
  char *output_format;
};

/* This is defined in elf32pic32mx.em and contains the values that come
   from shell substitution. */
extern struct pic32m_build_emulation_parameters EMULTEMPL;

/* These are objects from our code used in fragments in the emulation
   file. */
extern bfd_boolean insn32;
extern int eh_reloc_type;

/* These functions are used as entry points by the emulation layer. */
void pic32_finish (void);
void pic32_after_open (void);
void mips_lang_for_each_input_file (void (*func) (lang_input_statement_type *));
void mips_create_output_section_statements (void);
void mips_after_parse (void);
void mips_before_allocation (void);

/* These are functions that are called by emulation functions in
   elf32pic32mx.em to call into our code. */
void pic32m_list_options (FILE *);
int pic32m_parse_args (int, char**);
void pic32m_after_allocation (void);
lang_output_section_statement_type *
pic32m_place_orphan (lang_input_statement_type *, asection *,
		     const char *, int);

/* These are emulation functions that we need to call from
   elf32pic32mx.em, defined as extern'ed wrappers so we don't have to
   change declarations from static to extern in other emulation
   files. */

/* Found in ../emultempl/elf32.em */
void emultempl_after_parse (void);
void emultempl_before_allocation (void);
void emultempl_after_open (void);

/* Found in ../emultempl/elf-generic.em */
void emultempl_map_segments (bfd_boolean);

#endif
