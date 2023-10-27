/*
 * pic32.h -- ELF format helper for the MIPS-based PIC32 architecture.
 * Copyright (C) 2000 Free Software Foundation, Inc.
 * Contributed by Microchip Corporation.
 * Written by Jason Kajita.
 *
 * This file is part of BFD, the Binary File Descriptor library.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef _ELF_PIC32_H
#define _ELF_PIC32_H

#include <stdint.h>
#include <limits.h>

/* type associating a memory region with flags describing special 
   semantics which may not be representable in the language.
   these flags are to be set by pic32_init_region_info, hopefully
   being explicit about why it does what it does. */

struct pic32_memory;
struct memory_region_struct;


struct pic32_region {
  /* the region proper */
  struct memory_region_struct *region;

  /* free block list, potentially shared (i.e. combined code/data) */
  struct pic32_memory *free_blocks;

  struct region_bits {
      /* true if intialized/bss data allocated to this region must
         be initialized at runtime, i.e. .dinit required. */
      unsigned int init_needed : 1;

      /* true if this region is zeroed on load */
      unsigned int is_cleared : 1;

      /* true if this region can contain executable code */
      unsigned int is_exec : 1;

      /* true if this region is tightly coupled (thus not cacheable) */
      unsigned int is_tcm : 1;
  } flags;
};


/* Section Lists */
struct pic32_section
{
  struct pic32_section *next;
  unsigned int attributes;
  PTR *file;
  asection *sec;
  signed char dinit_type;
    // associated sections to be lnked right after this one - probably a stub added by hook_in_stub
    // the pic32_sections form a tree
  struct pic32_section  *children;
    // size represents the size of the section plus the children.  Used for reallocation ...
  bfd_size_type pic32_size;
  struct pic32_region *region;
  struct {
    unsigned int use_vma : 1; /* choose lma/vma when computing section bounds */
  };
};


/* Section types for code coverage */
#define SHT_XC_CODECOV_INFO     (SHT_LOUSER + 0xCC0)
#define SHT_XC_CODECOV_INFO_HDR (SHT_LOUSER + 0xCC1)

/* Section names for code coverage (taken from gcc/gcc/xc-coverage.h) */
#define CODECOV_SECTION        ".codecov"
#define CODECOV_INFO           ".codecov_info"
#define CODECOV_INFO_HDR       ".codecov_info.hdr"

#if defined(TARGET_IS_PIC32C)
extern void pic32c_fake_sections (bfd *, Elf_Internal_Shdr *, asection *);
#elif defined(TARGET_IS_PIC32MX)
struct elf_internal_shdr;
extern void pic32_fake_sections (bfd *, struct elf_internal_shdr *, asection *);
#endif
extern void pic32_free_section_list (struct pic32_section **);
extern void pic32_init_section_list (struct pic32_section **);
extern void pic32_append_section_to_list (struct pic32_section *, asection *);
/************************************************************************/
/*   pic32-specific section flags                                       */
/************************************************************************/
#define SHF_MEMORY   (1 << 19)  /* User-defined memory */
/* OS and processor-specific flags start at postion 20 */
#define SHF_DMA      (1 << 20)  /* DMA memory */
#define SHF_NOLOAD   (1 << 21)  /* Do not allocate or load */
#define SHF_NEAR     (1 << 22)  /* Near memory */
#define SHF_PERSIST  (1 << 23)  /* Persistent */
#define SHF_ABSOLUTE (1 << 24)  /* Absolute address */
#define SHF_REVERSE  (1 << 25)  /* Reverse aligned */
#define SHF_RAMFUNC  (1 << 26)  /* RAMFUNC */
#define SHF_COHERENT (1 << 27)  /* COHERENT */
#define SHF_KEEP     (1 << 28)  /* KEEP */
#define SHF_SHARED   (1 << 29)  /* SHARED lghica - co-resident*/
/************************************************************************/

#if defined(TARGET_IS_PIC32C)
/************************************************************************/
/*   PIC32C-specific "extended" section flags                            */
/*                                                                      */
/*  To work around space limitations in the section flags field,        */
/*  these values are encoded in a symbol named __ext__attr_secname      */
/************************************************************************/

#define STYP_PERSIST        (1 << 0)    /* Persistent */
#define STYP_MEMORY         (1 << 1)    /* User-defined memory */
#define STYP_ABSOLUTE       (1 << 2)    /* Absolute address */
#define STYP_NEAR           (1 << 3)    /* Near memory */
#define STYP_REVERSE        (1 << 4)    /* Reverse aligned */
#define STYP_ALIGNED        (1 << 5)    /* Aligned */
#define STYP_NOLOAD         (1 << 7)    /* Do not allocate or load */
#define STYP_MERGE          (1 << 8)    /* Merged */
#define STYP_INFO           (1 << 9)    /* Info */
#define STYP_DMA            (1 << 10)   /* DMA memory */
#define STYP_HEAP           (1 << 11)   /* Heap memory */
#define STYP_STACK          (1 << 12)   /* Stack memory */
#define STYP_RAMFUNC        (1 << 13)   /* RAMFUNC */
#define STYP_KEEP           (1 << 14)   /* KEEP */
#define STYP_COHERENT       (1 << 15)   /* COHERENT */
#define STYP_SERIAL_MEM     (1 << 16)   /* Serial Memory */
#define STYP_SHARED         (1 << 17)   /* shared section among co-resident apps*/
#define STYP_ITCM           (1 << 18)   /* ITCM section */
#define STYP_DTCM           (1 << 19)   /* DTCM section */
#define STYP_NOPA           (1 << 20)   /* NOPA */
/************************************************************************/



#define PIC32_SECTION_IN_DATA_MEMORY(sec) \
  (PIC32_IS_BSS_ATTR(sec) ||              \
   PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR(sec) ||              \
   PIC32_IS_DATA_ATTR(sec) ||             \
   PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR(sec) ||             \
   PIC32_IS_PERSIST_ATTR(sec) ||          \
   PIC32_IS_STACK_ATTR(sec) ||            \
   PIC32_IS_HEAP_ATTR(sec) ||             \
   PIC32_IS_DTCM_ATTR(sec))
#endif
#if defined(TARGET_IS_PIC32MX)

/*
 * pic32-specific "extended" section flags
 *
 * To work around space limitations in the section flags field,
 * these values are encoded in a symbol named __ext__attr_secname
 */

#define STYP_SERIAL_MEM    (0x1)        /* Serial memory */


#define PIC32_SECTION_IN_DATA_MEMORY(sec) \
  (PIC32_IS_BSS_ATTR(sec) ||              \
   PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR(sec) ||              \
   PIC32_IS_DATA_ATTR(sec) ||             \
   PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR(sec) ||             \
   PIC32_IS_PERSIST_ATTR(sec) ||          \
   PIC32_IS_STACK_ATTR(sec) ||            \
   PIC32_IS_HEAP_ATTR(sec))

#endif

#define PIC32_SECTION_IS_BSS_TYPE(sec) \
  (((sec->flags & (SEC_ALLOC | SEC_DATA | SEC_READONLY | SEC_CODE)) \
     == SEC_ALLOC))

struct pic32_memory
{
  struct pic32_memory *next;
  bfd_vma addr;
  bfd_vma size;
  bfd_vma offset;
};

struct expression {
        unsigned char *values_range;
        long long base_value;
        long long addened;};
struct location {
        bfd_boolean unused;
        long long address;
        long long end_address;};
struct pic32_fill_option
{
  struct pic32_fill_option *next;
  struct expression expr;
  struct location loc;
  struct pic32_section *fill_section_list;
  int fill_width;
  int range_size;
};


#if defined(TARGET_IS_PIC32C)
/* an enum to represent the style of TCM that we are linking to */
enum tcm_style
{
    TCM_NONE = 0,    // no tcm:   M0 and M1 cores
    TCM_SEPARATE,    // separate itcm, dtcm spaces:  Canopus, Capella, M7 cores
    TCM_COMBINED     // a single combined tcm for code and data: Jubilee, M4 cores
};

/* determine the TCM style and set code and data to point to the target
   regions for TCM code and TCM data, respectively. */
enum tcm_style determine_tcm_style (struct memory_region_struct **code,
				    struct memory_region_struct **data);

/* struct to record and classify the available memory regions in
   which to allocate. A NULL pointer indicates no such region is available. 

   how this is populated is currently based on names of regions in agreement with
   the linker script definitions. the 'pic32c_init_regions' function should
   be the single point where any special magic happens.

   pic32_section entries allocated within these regions will contain an index
   used to access the pic32_region used.
*/
struct region_info {

  /* Regions for vanilla code and data, but maybe the same. */
  struct pic32_region *code;
  struct pic32_region *data;

  /* TCM regions: separated by code and data, but maybe the same.
     see tcm_style definition. */
  struct pic32_region *code_tcm;
  struct pic32_region *data_tcm;

  /* Pointers to the relocation targets for vectors and stack. NULL
     if no relocation is required. Each of these may alias one of the
     above regions. */
  struct pic32_region *vectors;
  struct pic32_region *stack;
  struct pic32_region *ramfunc;

  /*  The flavour of TCM in use */
  enum tcm_style tcm_style;
};

/* global region_info, living in pic32c-allocate.c */
extern struct region_info region_info;

/* Initialize region_info and other state needed for the allocator. */
extern void pic32_init_alloc (void);

/* the canonical check for a valid memory region. */
/* TODO: all uses of this should be unneccessary once we stop creating
   bogus regions in region_lookup() */
extern int valid_region(const struct memory_region_struct *);

/* write region information to the given file. show_tcm controls whether
   TCM regions are included in the output. */
extern void pic32_report_region_info (FILE *, int show_tcm);

#endif /* TARGET_IS_PIC32C */
#endif /* _ELF_PIC32_H */

