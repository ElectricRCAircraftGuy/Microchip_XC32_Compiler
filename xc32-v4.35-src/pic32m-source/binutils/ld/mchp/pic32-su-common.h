/* Interface for the common stack usage code.

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

#ifndef PIC32_SU_COMMON_H
#define PIC32_SU_COMMON_H

void pic32_stack_estimation_run (void);
void pic32_su_add_func (vec_type *, Elf_Internal_Sym *);
int pic32_su_lookup_func (vec_type *, int, bfd_vma, int *);
void su_note_smartio_replacement (const char *, const char *);

#endif
