/* Interface for other utilities in the pic32 linker code.

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

#ifdef TARGET_IS_PIC32C
#include "pic32c-utils.h"
#elif defined(TARGET_IS_PIC32MX)
#include "pic32m-utils.h"
#else
#error "Undefined target for including pic32-utils.h"
#endif

void bfd_pic32_report_memory_usage_by_module(FILE *);
