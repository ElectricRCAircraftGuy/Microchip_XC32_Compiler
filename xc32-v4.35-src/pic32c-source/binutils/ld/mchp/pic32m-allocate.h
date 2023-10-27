/* Interface for the best-fit allocator.

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

#ifndef PIC32M_ALLOCATE_H
#define PIC32M_ALLOCATE_H

void allocate_memory(void);
int allocate_data_memory (void);
int allocate_serial_memory (void);
int allocate_program_memory (void);
int allocate_user_memory (void);
void allocate_default_stack(void);
void update_section_info(bfd_vma, struct pic32_section *,
			 struct memory_region_struct *);
void create_remainder_blocks(struct pic32_memory *,
			     struct pic32_memory *, unsigned int);

#endif
