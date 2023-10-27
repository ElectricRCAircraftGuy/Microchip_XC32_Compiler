/* Declarations for pic32c options for the linker.

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

#ifndef _PIC32C_OPTIONS_H
#define _PIC32C_OPTIONS_H

#define DEFAULT_TCM_SIZE           0x20000
#define MAX_DINIT_OPTIMIZATION_LVL 3
#define DEFAULT_DINIT_LEVEL        3
#define STR(s)                     #s
#define F_STR(s)                   STR(s)

/*
** Externals declared in bfd *.c
*/

extern bfd_boolean pic32_report_mem;
extern bfd_boolean pic32_mafrlcsj;
extern bfd_boolean pic32_mafrlcsj2;
extern bfd_boolean pic32_memory_summary;
extern char *memory_summary_arg;
extern bfd_boolean pic32_debug;
extern bfd_boolean pic32_debug_smartio;
extern bfd_boolean pic32_smart_io;
extern bfd_boolean pic32_has_smart_io_option;
extern bfd_boolean pic32_allocate;
extern bfd_boolean pic32_data_init;
extern bfd_boolean pic32_has_data_init_option;
extern bfd_boolean pic32_has_fill_option;
extern struct pic32_fill_option *pic32_fill_option_list;
extern bfd_boolean pic32_has_stack_option;
extern unsigned int pic32c_stack_size;
extern bfd_boolean pic33_has_stackguard_option;
extern unsigned int pic32c_stackguard_size;
extern bfd_boolean pic32_has_heap_option;
extern bfd_boolean pic32_heap_required;
extern unsigned int pic32c_heap_size;
extern bfd_boolean pic32_has_crypto_option;
//extern char * crypto_file;
extern bfd_boolean pic32_has_processor_option;
extern bfd_boolean pic32_has_hardfloat_option;
extern bfd_boolean pic32_has_softfloat_option;
extern bfd_boolean pic32_code_in_dinit;
extern bfd_boolean pic32_has_code_in_dinit_option;
//extern bfd_boolean pic32_has_dinit_in_serial_mem_option;
//extern bfd_boolean pic32_dinit_in_serial_mem;
extern bfd_boolean pic32_dinit_has_absolute_address;
extern bfd_vma dinit_address;

extern bfd_boolean          pic32c_tcm_enabled;
extern unsigned int         pic32c_tcm_size;
extern unsigned int         pic32c_itcm_size;
extern unsigned int         pic32c_dtcm_size;
extern bfd_boolean          pic32c_stack_in_tcm;
extern bfd_boolean          pic32c_vectors_in_tcm;

/* lghica - co-resident */
//extern bfd_boolean      pic32_memory_usage;
//extern bfd_boolean      pic32_reserve_const;
extern unsigned long    reserve_const_arg;
//extern bfd_boolean      pic32_pad_flash_option;
//extern bfd_vma          pad_flash_arg;
extern bfd_boolean      pic32_application_id;
//extern char             *application_id;
//extern bfd_boolean      pic32_coresident_app;
//extern bfd_boolean      pic32_inherit_application_info;
//extern char             *inherited_application;
extern unsigned int     dinit_compress_level;
extern bfd_boolean      dinit_self_check;
extern unsigned int     dinit_link_mask;

extern bfd_boolean      pic32_stack_usage;

void pic32c_list_options (FILE *);
int pic32c_parse_args (int, char**);

/* Codes used for the long options with no short synonyms.  1000 isn't
   special; it's just an arbitrary non-ASCII char value that is
   different from the range used in lexsup.c  */
enum elfpic32c_options {
  REPORT_MEM_OPTION = 1000,
  PIC32C_DEBUG_OPTION,
  PIC32C_DEBUG_SMARTIO_OPTION,
  REPORT_MAFRLCSJ_OPTION,
  REPORT_MAFRLCSJ2_OPTION,
  SMART_IO_OPTION,
  NO_SMART_IO_OPTION,
  DATA_INIT_OPTION,
  NO_DATA_INIT_OPTION,
  FILL_OPTION,
  CRYPTO_OPTION,
  MEMRESERVE_OPTION,
  HARDFLOAT_OPTION,
  MEMORY_SUMMARY,
  SOFTFLOAT_OPTION,
  CODE_IN_DINIT_OPTION,
  NO_CODE_IN_DINIT_OPTION,
#if 0 ///\ tmp removed
  DINIT_IN_SERIAL_MEM_OPTION,
  NO_DINIT_IN_SERIAL_MEM_OPTION,
#endif
  DINIT_ADDRESS_OPTION,
  TCM_OPTION,
  ITCM_OPTION,
  DTCM_OPTION,
  STACK_IN_TCM_OPTION,
  VECTORS_IN_TCM_OPTION,
  NO_VECTORS_IN_TCM_OPTION,

  /* lghica co-resident */
    MEMORY_USAGE,
    RESERVE_CONST,
    PAD_FLASH,
    APPLICATION_ID,
    CORESIDENT,
    INHERIT_APPLICATION_INFO,
  MCHP_STACK_USAGE,
  MCHP_DINIT_COMPRESS,
  MCHP_DINIT_SELF_CHECK
};

#endif
