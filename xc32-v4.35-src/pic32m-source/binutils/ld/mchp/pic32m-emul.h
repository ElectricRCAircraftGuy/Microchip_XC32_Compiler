/* Interface for the pic32m emulation code.

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

#ifndef PIC32M_EMUL_H
#define PIC32M_EMUL_H

extern struct pic32_section *pic32_section_list;
extern struct pic32_section *unassigned_sections;
extern struct pic32_section *memory_region_list;
extern struct pic32_section *alloc_section_list;
extern struct pic32_memory *free_blocks;
extern struct pic32_memory *data_memory_free_blocks;
extern struct pic32_memory *shared_data_memory_blocks;
extern bfd_boolean has_user_defined_memory;
extern int coherent_section_count;
extern unsigned int stack_base;
extern unsigned int stack_limit;
extern unsigned int heap_base;
extern unsigned int heap_limit;
extern const char *memory_region_prefix;
extern struct pic32_section *user_memory_sections;

void pic32_build_section_list (bfd *, asection *, PTR);
void pic32_build_section_list_vma (bfd *, asection *, PTR);
void pic32_print_section_list (struct pic32_section *, const char *);
bfd_boolean pic32_unique_section (const char *s);
int pic32_section_list_length (struct pic32_section *);
lang_memory_region_type *region_lookup (char *);
void pic32_init_memory_list (struct pic32_memory **);
void pic32_remove_group_from_section_list (struct pic32_section *);

struct bfd_link_hash_entry *
bfd_pic32_is_defined_global_symbol (const char *const);

void pic32_remove_from_section_list (struct pic32_section *,
				     struct pic32_section *);
struct pic32_memory* pic32_add_shared_to_memory_list (struct pic32_memory *,
						      bfd_vma, bfd_vma,
						      asection* const);
struct pic32_memory * pic32_static_assign_memory (struct pic32_memory *,
						  bfd_vma, bfd_vma);
struct pic32_memory * pic32_assign_shared_memory (struct pic32_memory *,
						  bfd_vma,
						  struct pic32_section *);
struct pic32_memory* pic32_add_to_memory_list (struct pic32_memory *,
					       bfd_vma, bfd_vma);
void pic32_free_memory_list (struct pic32_memory **);
void pic32_remove_from_memory_list (struct pic32_memory *,
				    struct pic32_memory *);
void pic32_remove_coherent_group_from_section_list (struct pic32_section *,
						    unsigned int);
int32_t pic32_su_rel_addend (bfd *, asection *, Elf_Internal_Rela *,
			     Elf_Internal_Sym  *);
bfd_boolean is_call_reloc(unsigned int);
void pic32_create_data_init_template(void);
void pic32_create_data_init_section_lists(void);
void pic32_find_data_code_sections(void);

#endif
