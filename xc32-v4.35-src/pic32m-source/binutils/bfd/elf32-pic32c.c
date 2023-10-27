/* Microchip PIC32-specific support for 32-bit ELF
   Copyright 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
   2008, 2009, 2010  Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

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
   MA 02110-1301, USA.  */

#include "bfd.h"
#include "sysdep.h"
#include "elf-bfd.h"
#include "pic32c-utils.h"
#include "elf/pic32.h"

#define DEFAULT_STACK_SIZE  0x100


/* Variables set by pic32 linker options */
bfd_boolean pic32_debug = FALSE;
bfd_boolean pic32_memory_summary= FALSE;
bfd_boolean pic32_report_mem = FALSE;
bfd_boolean pic32_mafrlcsj = FALSE;
bfd_boolean pic32_mafrlcsj2 = FALSE;
bfd_boolean pic32_smart_io = TRUE; 
bfd_boolean pic32_has_smart_io_option = FALSE;
bfd_boolean pic32_debug_smartio = FALSE;
bfd *mchp_output_bfd;
bfd_boolean pic32_allocate = TRUE; /* Enable BFA by default */
unsigned int pic32c_heap_size = 16;
unsigned int pic32c_stack_size = DEFAULT_STACK_SIZE;
unsigned int pic32c_stackguard_size = 16;

bfd_vma     dinit_address = 0;
bfd_boolean pic32_has_data_init_option = FALSE;
bfd_boolean pic32_has_code_in_dinit_option = FALSE;
bfd_boolean pic32_data_init = TRUE;
bfd_boolean pic32_code_in_dinit = FALSE;
bfd_boolean pic32_dinit_has_absolute_address = FALSE;
bfd_boolean pic32_has_crypto_option = FALSE;
bfd_boolean pic32_has_fill_option = FALSE;
bfd_boolean pic32_has_hardfloat_option = FALSE;
bfd_boolean pic32_has_heap_option = FALSE;
bfd_boolean pic32_has_processor_option = FALSE;
bfd_boolean pic32_has_softfloat_option = FALSE;
bfd_boolean pic32_has_stack_option = FALSE;
bfd_boolean pic32_heap_required = FALSE;
bfd_vma     pic32c_itcm_vectors_address = 0x0;
bfd_boolean pic32c_relocate_vectors = FALSE;


/* Data structures for fill option */
struct pic32_fill_option *pic32_fill_option_list;

bfd_boolean          pic32c_tcm_enabled = FALSE;
unsigned int         pic32c_tcm_size = 0;
unsigned int         pic32c_itcm_size = 0;
unsigned int         pic32c_dtcm_size = 0;
bfd_boolean          pic32c_stack_in_tcm = FALSE;
bfd_boolean          pic32c_vectors_in_tcm = TRUE;

/* lghica co-resident*/
//bfd_boolean         pic32_memory_usage;
//bfd_boolean         pic32_reserve_const;
unsigned long       reserve_const_arg;
//bfd_boolean         pic32_pad_flash_option;
//bfd_vma             pad_flash_arg;
bfd_boolean         pic32_application_id;


char * memory_summary_arg;

/* Data Structures for Input Data Sections */
struct pic32_section *data_sections;

/* Data Structures for Input Code Sections */
struct pic32_section *code_sections;

struct pic32_memory *program_memory_free_blocks;

//static void bfd_pic32_process_data_section(struct pic32_section *sect, PTR fp);
//static void bfd_pic32_process_code_section(struct pic32_section *sect, PTR fp, bfd_boolean update_flags);

/* MERGE-TODO: added decl to avoid complaints. is this static? */
bfd_boolean pic32c_elf_final_link(bfd *abfd, struct bfd_link_info *info);

#if 0
static void
bfd_pic32_process_code_section(struct pic32_section *section, PTR fp, bfd_boolean update_flags)
{
    unsigned char *buf,*p;
    unsigned char **d = (unsigned char **) fp;
    asection *sect = section->sec;
    bfd_vma runtime_size = sect->size;
    bfd_vma runtime_addr = sect->output_offset + sect->output_section->vma;
    Elf_Internal_Shdr *this_hdr;
    
    enum {CLEAR, COPY}; /* note matching definition in crt0.c */

    ///\ set runtime address for .vectors
    ///\ itcm origin
    if(!update_flags)
    {
        runtime_addr = pic32c_itcm_vectors_address;
    }
              
    if (PIC32_IS_CODE_ATTR(sect) && (sect->size > 0) && sect->init)
    {
        if (pic32_debug)
            fprintf(stderr,"  %s (data), size = %x bytes, template addr = %lx\n",
                   sect->name, (unsigned int) runtime_size,
                   (long unsigned int) *d);
        
        /*
         ** load a copy of the section contents
         **
         ** Note: We are extracting input section data
         ** from an output section.
         */
        buf = (unsigned char *) malloc (sect->size);
        if (!buf)
        {
            fprintf( stderr, "Link Error: not enough memory for section contents\n");
            abort();
        }
        
        /* Reset the bfd file pointer, because
         there seems to be a bug with fseek()
         in Winblows that makes seeking to
         a position earlier in the file unreliable. */
        bfd_seek(sect->output_section->owner, 0, SEEK_SET);
        
        if (!bfd_get_section_contents(sect->output_section->owner,
                                      sect->output_section,
                                      buf, sect->output_offset, sect->size))
            
        {
            fprintf( stderr, "Link Error: can't load section %s contents\n",
                    sect->name);
            abort();
        }
        
        { int count = 0;

            /* write header */
            bfd_pic32_write_data_header(d, runtime_addr, runtime_size, COPY);
            for (p = buf; p < (buf + sect->size); )
            {
                *(*d)++ = *p++;
                count ++;
                if (count == 4)
                    count = 0;
            }
            /* fill template with zeroes */
            if (count) while (count < 4) { *(*d)++ = 0; count++; }
            //if (count == 4) { *(*d)++ = 0; };
        }
        
        free(buf);
        
        if (update_flags)
        {
            /* make section not LOADable */
            sect->output_section->flags &= ~ SEC_LOAD;
            sect->output_section->flags |= SEC_NEVER_LOAD;
        
            sect->flags &= ~ SEC_LOAD;
            sect->flags |= SEC_NEVER_LOAD;
        
            this_hdr = &elf_section_data (sect->output_section)->this_hdr;
            this_hdr->sh_flags |= SHF_NOLOAD;
        }
    }
}

/*
 ** If the section is BSS or DATA, write the appropriate
 ** record into the data init template.
 **
 ** ToDo: If the data section exceeds 64K, break into
 ** multiple records.
 */
static void
bfd_pic32_process_data_section (struct pic32_section *section, PTR fp)
{
  unsigned char *buf, *p;
  unsigned char **d = (unsigned char **) fp;
  asection *sect = section->sec;
  bfd_vma runtime_size = sect->size;
  bfd_vma runtime_addr; /* lghica */
  Elf_Internal_Shdr *this_hdr;

  enum
  {
    CLEAR,
    COPY
  }; /* note matching definition in crt0.c */

  if (sect->output_section == NULL)
    return;

  if (!sect->init)
    {
      if (pic32_debug)
	fprintf (stderr, "data_section %s (skipped, !init)\n", sect->name);
      return;
    }

  /* skip persistent or noload data sections */
  if (PIC32_IS_PERSIST_ATTR (sect) || PIC32_IS_NOLOAD_ATTR (sect))
    {
      if (pic32_debug)
	fprintf (stderr, "data_section %s (skipped), size = %x\n", sect->name,
		 (unsigned int) runtime_size);
      return;
    }

  /* MERGE_NOTES: restructured the conditions to ensure runtime_addr is known to
     be initialized (i.e. if sect->size > 0) */
  if (sect->size > 0)
    {
      runtime_addr
	= sect->output_offset + sect->output_section->vma; /* lghica */

      /* process BSS-type sections */
      if ((PIC32_IS_BSS_ATTR (sect)
	   || PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR (sect)))
	{
	  if (pic32_debug)
	    fprintf (
	      stderr,
	      "data_Section %s (bss), size = %x bytes, template addr = %lx\n",
	      sect->name, (unsigned int) runtime_size, (long unsigned int) *d);

	  /* write header only */

	  bfd_pic32_write_data_header (d, runtime_addr, runtime_size, CLEAR);
	}

      /* process DATA-type sections */
      if ((PIC32_IS_DATA_ATTR (sect)
	   || PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR (sect)
	   || PIC32_IS_RAMFUNC_ATTR (sect)))
	{
	  if (pic32_debug)
	    fprintf (
	      stderr,
	      "data_section %s (data), size = %x bytes, template addr = %lx\n",
	      sect->name, (unsigned int) runtime_size, (long unsigned int) *d);

	  /*
	   ** load a copy of the section contents
	   **
	   ** Note: We are extracting input section data
	   ** from an output section.
	   */
	  buf = (unsigned char *) malloc (sect->size);
	  if (!buf)
	    {
	      fprintf (stderr,
		       "Link Error: not enough memory for section contents\n");
	      abort ();
	    }

	  /* Reset the bfd file pointer, because
	   there seems to be a bug with fseek()
	   in Winblows that makes seeking to
	   a position earlier in the file unreliable. */
	  bfd_seek (sect->output_section->owner, 0, SEEK_SET);

	  if (!bfd_get_section_contents (sect->output_section->owner,
					 sect->output_section, buf,
					 sect->output_offset, sect->size))

	    {
	      fprintf (stderr, "Link Error: can't load section %s contents\n",
		       sect->name);
	      abort ();
	    }

	  {
	    int count = 0;
	    /* write header */
	    bfd_pic32_write_data_header (d, runtime_addr, runtime_size, COPY);
	    for (p = buf; p < (buf + sect->size);)
	      {
		*(*d)++ = *p++;
		count++;
		if (count == 4)
		  count = 0;
	      }
	    /* fill template with zeroes */
	    if (count)
	      while (count < 4)
		{
		  *(*d)++ = 0;
		  count++;
		}
	    // if (count == 4) { *(*d)++ = 0; };
	  }

	  free (buf);

	  /* make section not LOADable */
	  sect->output_section->flags &= ~SEC_LOAD;
	  sect->output_section->flags |= SEC_NEVER_LOAD;

	  sect->flags &= ~SEC_LOAD;
	  sect->flags |= SEC_NEVER_LOAD;

	  this_hdr = &elf_section_data (sect->output_section)->this_hdr;
	  this_hdr->sh_flags |= SHF_NOLOAD;

	} /* process DATA-type sections */
    }

  return;
} /* static void bfd_pic32_process_data_section (...)*/
#endif

void  set_dinit_content(bfd* abfd, struct bfd_link_info* info);

void check_dinit_content(struct bfd_link_info* info);

bfd_boolean
pic32c_elf_final_link (bfd *abfd, struct bfd_link_info *info)
{
  set_dinit_content(abfd, info);

  /* check dinit structure */
  check_dinit_content(info);

  return TRUE;
}


void pic32c_fake_sections (bfd *abfd, Elf_Internal_Shdr *hdr, asection *sec)
{
  const char * name;

  name = bfd_get_section_name (abfd, sec);

  if (CONST_STRNEQ (name, CODECOV_INFO_HDR))
    {
      hdr->sh_type = SHT_XC_CODECOV_INFO_HDR;
    }
  else if (CONST_STRNEQ (name, CODECOV_INFO))
    {
      hdr->sh_type = SHT_XC_CODECOV_INFO;
    }
}

/*
** Create a new list
**
** - first item is null
*/
void pic32_init_section_list(struct pic32_section **lst)
{
  *lst = ((struct pic32_section *)
         xmalloc(sizeof(struct pic32_section)));
  if (NULL == lst) {
    fprintf( stderr, "Fatal Error: Not enough memory to initialize section list\n");
    abort();
  }
  (*lst)->next = 0;
  (*lst)->sec = 0;
  (*lst)->attributes = 0;
  (*lst)->file = 0;
  (*lst)->pic32_size = 0;
  (*lst)->children = NULL;
}

/*
** Free a section list
*/
void pic32_free_section_list(struct pic32_section **lst)
{
  struct pic32_section *s, *next;

  if (!(*lst))
    return;

  for (s = *lst; s != NULL; s = next)
    {
      next = s->next;
      if (NULL != s->children) pic32_free_section_list(&(s->children));
      free(s);
    }

  *lst = NULL;
} /* void pic32_free_section_list (...) */


#include "pic32-stack-usage.c"
#include "pic32-dinit.c"

#if 0
/* TODO not added yet */
/* Data Structures for the Undefined Symbol Table */
struct mchp_undefsym_table *undefsyms;

/**********************************************************************
**
** Undefined Symbol Hash Table Routines
**
** We use a hash table to keep track of undefined
** symbols and their object signatures.
**
** Derived from the basic table provided in /bfd/hash.c
*/

/* Create a new hash table entry */
struct bfd_hash_entry *
mchp_undefsym_newfunc (entry, table, string)
     struct bfd_hash_entry *entry;
     struct bfd_hash_table *table;
     const char *string;
{
  struct mchp_undefsym_entry *ret = (struct mchp_undefsym_entry *) entry;

  /* Allocate the structure if it has not already been allocated by a
     subclass.  */
  if (ret == (struct mchp_undefsym_entry *) NULL)
    ret = ((struct mchp_undefsym_entry *)
	   bfd_hash_allocate (table, sizeof (struct mchp_undefsym_entry)));
  if (ret == (struct mchp_undefsym_entry *) NULL)
    return NULL;

  /* Call the allocation method of the superclass.  */
  ret = ((struct mchp_undefsym_entry *)
	 bfd_hash_newfunc ((struct bfd_hash_entry *) ret, table, string));

  if (ret) {     /* Initialize the local fields. */
    ret->most_recent_reference = 0;
    ret->external_options_mask = 0;
    ret->options_set = 0;
    }

  return (struct bfd_hash_entry *) ret;
}
/* Create a new hash table */
struct mchp_undefsym_table *
mchp_undefsym_init (struct bfd_link_info *info)
{
  struct mchp_undefsym_table *table;

  table = ((struct mchp_undefsym_table *)
	   bfd_alloc (info->output_bfd, sizeof (struct mchp_undefsym_table)));
  if (table == NULL)
    return NULL;

  if (! bfd_hash_table_init_n (&table->table, mchp_undefsym_newfunc,
                               sizeof(struct mchp_undefsym_entry),
                               MCHP_UNDEFSYM_INIT)) {
      free (table);
      return NULL;
    }

  table->num = 0;
  return table;
}
#endif
