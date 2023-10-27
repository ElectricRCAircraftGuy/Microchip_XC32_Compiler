/* mchp-pragmas.c */
/* Subroutines used for MCHP PIC32 pragma handling.
   Copyright (C) 2017
   Free Software Foundation, Inc.

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

#ifndef MCHP_PRAGMAS_H
#define MCHP_PRAGMAS_H

/*
 * #pragma config support
 */
extern void mchp_handle_config_pragma(struct cpp_reader *pfile);
extern void mchp_handle_section_pragma (struct cpp_reader *pfile);
extern void mchp_handle_printf_args_pragma (struct cpp_reader *pfile);
extern void mchp_handle_scanf_args_pragma (struct cpp_reader *pfile);
extern void mchp_handle_keep_pragma (struct cpp_reader *pfile);
extern void mchp_handle_optimize_pragma (struct cpp_reader *pfile);
extern void mchp_handle_align_pragma (struct cpp_reader *pfile);
extern void mchp_handle_nocodecov_pragma (struct cpp_reader *pfile);
extern int mchp_pragma_nocodecov;
extern void mchp_handle_nopa_pragma (struct cpp_reader *pfile);
extern int mchp_pragma_nopa;
extern void mchp_handle_default_variable_attributes_pragma (struct cpp_reader *pfile);
extern void mchp_handle_default_function_attributes_pragma (struct cpp_reader *pfile);
extern char* mchp_pragma_default_variable_section;
extern char* mchp_pragma_default_function_section;
#include "mchp_pragma_config.h"


#endif
