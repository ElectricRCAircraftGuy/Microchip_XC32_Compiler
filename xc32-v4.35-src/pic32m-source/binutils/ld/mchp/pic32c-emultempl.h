/* Interface for the linker emulation code to call and use the pic32c
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

#ifndef PIC32C_EMULTEMPL_H
#define PIC32C_EMULTEMPL_H
/* Holds the build parameter values that are substituted as shell
   code.  The names should match the name of the variable used or
   where it is supposed to be used. */
struct pic32c_build_emulation_parameters {
  char *emulation_name;
  int target1_is_rel;
  char *target2_type;
  char *arch;
  int dynamic;
  bfd_boolean has_shared;
  bfd_boolean separate_code;
  char *output_format;
};

/* This is defined in elf32pic32c.em and contains the values that come
   from shell substitution. */
extern struct pic32c_build_emulation_parameters EMULTEMPL;


/* These are objects from our code used in fragments in the emulation
   file. */
extern struct elf32_arm_params params;
extern bfd_signed_vma group_size;
extern char *in_implib_filename;
extern bfd_boolean detailed_mem_usage_to_map;

/* These functions are used as entry points by the emulation layer.
   Note that the "after_open" one calls the emulation one, so it is
   what is known as an "around" method. */
void pic32c_after_open  (void);
void arm_elf_before_allocation (void);
void arm_extra_map_file_text (bfd *, struct bfd_link_info *, FILE *);
void arm_elf_create_output_section_statements (void);
lang_output_section_statement_type *arm_elf_place_orphan (asection *,
							  const char *, int);

/* These are functions that are called by emulation functions in
   elf32pic32c.em to call into our code. */
void pic32c_before_parse (void);
void pic32c_after_allocation (void);
void pic32c_list_options (FILE *);
int pic32c_parse_args (int, char **);
void pic32c_set_symbols (void);
void pic32c_finish (void);

/* These are emulation functions that we need to call from
   elf32pic32c.em, defined as extern'ed wrappers so we don't have to
   change declarations from static to extern in other emulation
   files. */

/* Found in ../emultempl/elf32.em */
void emultempl_before_allocation (void);
void emultempl_after_open (void);
lang_output_section_statement_type *emultempl_place_orphan (asection *,
							    const char *, int);
/* Found in ../emultempl/elf-generic.em */
void emultempl_map_segments (bfd_boolean);

#endif
