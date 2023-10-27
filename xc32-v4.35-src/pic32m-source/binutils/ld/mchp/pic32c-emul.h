/* Interface for the pic32c emulation code.

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

#ifndef PIC32C_EMUL_H
#define PIC32C_EMUL_H

/* Data objects and functions from the emulation code used in other
   files. */
extern struct elf32_arm_params params;
extern struct pic32_section *pic32_section_list;
extern struct pic32_section *alloc_section_list;
extern struct pic32_section *unassigned_sections;
extern struct pic32_section *unassigned_sections_master_copy;
extern struct pic32_section *memory_region_list;
extern bfd_vma dtcm_stack_limit;
extern bfd_vma dtcm_stack_base;
extern unsigned int stack_base, stack_limit;
extern unsigned int heap_base, heap_limit;
extern struct pic32_section *alloc_bss_section_list;


lang_memory_region_type *region_lookup (char *);
bfd_size_type bfd_pic32_collect_section_size (struct pic32_section *,
					      const lang_memory_region_type *);

void pic32_free_region_info (struct region_info *);
void pic32_free_memory_list (struct pic32_memory **);
struct pic32_memory *pic32_static_assign_memory (struct pic32_memory *,
						 bfd_vma, bfd_vma);
void pic32_print_section_list (struct pic32_section *, const char *);
void pic32_build_section_list (bfd *, asection *, PTR);
void pic32_build_section_list_vma (bfd *, asection *, PTR);
bfd_boolean pic32_unique_section (const char *s);
int pic32_section_list_length (struct pic32_section *);
void pic32_remove_from_section_list (struct pic32_section *,
				     struct pic32_section *);
void pic32_remove_group_from_section_list (struct pic32_section *);
void pic32_add_to_memory_list (struct pic32_memory *, bfd_vma, bfd_vma);
void pic32_init_memory_list (struct pic32_memory **);
void pic32_remove_from_memory_list (struct pic32_memory *,
				    struct pic32_memory *);
void pic32c_su_calls_wo_relocs_in_section (bfd *, Elf_Internal_Shdr *,
					   asection *, Elf_Internal_Rela *,
					   Elf_Internal_Sym *, vec_type *);
int32_t pic32_su_rel_addend (bfd *, asection *, Elf_Internal_Rela *,
			     Elf_Internal_Sym  *);
void pic32_stack_estimation_run(void);
bfd_boolean is_call_reloc(unsigned int);
struct bfd_link_hash_entry *bfd_pic32_is_defined_global_symbol
   (const char *const);

void pic32_create_data_init_template(void);
void pic32_create_data_init_section_lists(void);
void pic32_find_data_code_sections(void);
struct bfd_link_hash_entry *bfd_pic32_is_defined_global_symbol
  (const char *const);
struct pic32_section * pic32_copy_section (struct pic32_section *);

#endif
