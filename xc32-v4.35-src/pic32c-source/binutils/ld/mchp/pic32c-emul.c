/* Linker emulation code for pic32c.

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

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "getopt.h"
#include "genlink.h"
#include "ld.h"
#include "ldmain.h"
#include "ldmisc.h"
#include "ldexp.h"
#include "ldlang.h"
#include "ldfile.h"
#include "ldctor.h"

#include "ldemul.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/arm.h"
#include "elf/pic32.h"
#include "ctype.h"

#include <stdint.h>

#include "pic32c-utils.h"
#include "pic32-vecset.h"
#include "pic32-stack-usage.h"

#include "pic32c-options.h"
#include "pic32c-allocate.h"
#include "pic32-su-common.h"
#include "pic32-su-callstack.h"
#include "pic32c-emul.h"
#include "pic32c-emultempl.h"
#include "smartio.h"
#include "mchp/pic32-common-emul.h"
#include "pic32-debug.h"

#define DEBUG_SCOPE "bfa"

/* These functions are defined in other emulation files and are
   repeated here for simplicity. */

extern void pic32_print_su_report (FILE *);

/* controls code for supporting user memory region declarations by pragma.
   turning this on will require refactoring of the code to use the region_info
   structure. it's unclear if this feature will ever get ported. */
//#define ENABLE_USER_MEMORY 1
#undef ENABLE_USER_MEMORY

#undef DATA_RECORD_HEADER_SIZE
#define DATA_RECORD_HEADER_SIZE 12

/* FIXME: fix_cortex_a8 is disabled explicitly here. this may create a stub
   after allocation leading to a possible section overlap, and the stub creation
   is triggered by branches spanning a 4k page which is unpredictable.
   Turning it off now is okay because we do not support the cortex-a8 yet, even 
   though the fix will be applied for any armv7-a arch.
   If we do have to turn this on, it will require some care to ensure that 
   the BFA plays well with the code to add __stub sections for that fix. */
struct elf32_arm_params params =
{
  NULL,                         /* thumb_entry_symbol */
  0,                            /* byteswap_code */
  0,                            /* target1_is_rel (initialized by pic32c_before_parse) */ 
  NULL,                         /* target2_type (initialized by pic32c_before_parse)  */
  0,                            /* fix_v4bx */
  0,                            /* use_blx */
  BFD_ARM_VFP11_FIX_DEFAULT,    /* vfp11_denorm_fix */
  BFD_ARM_STM32L4XX_FIX_NONE,   /* stm32l4xx_fix */
  0,                            /* no_enum_size_warning */
  0,                            /* no_wchar_size_warning */
  0,                            /* pic_veneer */
  0,                            /* fix_cortex_a8 */
  1,                            /* fix_arm1176 */
  -1,                           /* merge_exidx_entries */
  0,                            /* cmse_implib */
  NULL                          /* in_implib_bfd */
};

char *in_implib_filename = NULL;
bfd_boolean detailed_mem_usage_to_map = FALSE;

lang_statement_union_type *pic32_last_os;




/* strings to save symbol names to be assigned to _stack and _splim respectively */
/* see ldexp.c                                                                   */
char *altNameforStack = NULL;
char *altNameforSplim = NULL;
/* and we need another set in case stack is in tcm ...                           */
char *altNamefor_dtcm_Stack = NULL;
char *altNamefor_dtcm_Splim = NULL;

/* helper(s) to deal with missing regions that pass region_lookup.
   these get a length of -1. the default region is expected to 
   have this length, so we handle it by name. */
int
valid_region (const lang_memory_region_type *region)
{
  return (
    region && (region->length > 0)
    && ((region->length != ~(bfd_size_type) 0)
	|| (strcmp (region->name_list.name, DEFAULT_MEMORY_REGION) == 0)));
}

static void
remove_section_from_bfd(bfd *abfd, asection *sec)
{
    asection *s, *prev;
    
    s = abfd->sections;
    if ((s == NULL) || (s->next == NULL)) return;
    
    /* as a sanity check, search for the section in the bfd */
    /* this can be removed or made optional if speed is an issue */
#if 1
    /* lookup 'sec' starting with 2nd bfd section (never remove the 1st one) */
    s = s->next;
    while (s != sec && s != NULL)
        s = s->next;
    /* didn't find it */
    if (s == NULL)
#else
    /* simple test for not removing the 1st section */
        if (sec->prev == NULL)
#endif
            return;
    
    prev = sec->prev;
    prev->next = sec->next;
    
    if (sec->next)
        sec->next->prev = prev;
    else
        abfd->section_last = prev; /*update the bfd->section_last field
                                    if the removed section is the
                                    last section.*/
    abfd->section_count -= 1;
    PIC32_DEBUG("    removing section %s", s->name);
    return;
} /* static void remove_section_from_bfd (...)*/




void
pic32c_before_parse (void)
{
  /* These params values were originally written directly into the
     structure definition but because they used shell expansion in the
     emulation file they need to be set here instead. */
  params.target1_is_rel = EMULTEMPL.target1_is_rel;
  params.target2_type = EMULTEMPL.target2_type;
#ifndef TARGET_                 /* I.e., if not generic.  */
  ldfile_set_output_arch (EMULTEMPL.arch, bfd_arch_unknown);
#endif /* not TARGET_ */
  input_flags.dynamic = EMULTEMPL.dynamic;
  config.has_shared = EMULTEMPL.has_shared;
  config.separate_code = EMULTEMPL.separate_code;
  link_info.relro = DEFAULT_LD_Z_RELRO;
}

void
pic32c_set_symbols (void)
{
  /* PR 19106: The section resizing code in gldarmelf_after_allocation
     is effectively the same as relaxation, so prevent early memory
     region checks which produce bogus error messages.
     Note - this test has nothing to do with symbols.  It is just here
     because this is the first emulation routine that is called after
     the command line has been parsed.  */
  if (!bfd_link_relocatable (&link_info))
    TARGET_ENABLE_RELAXATION;
}

void
arm_elf_before_allocation (void)
{

  bfd_elf32_arm_set_byteswap_code (&link_info, params.byteswap_code);

  /* Choose type of VFP11 erratum fix, or warn if specified fix is unnecessary
     due to architecture version.  */
  bfd_elf32_arm_set_vfp11_fix (link_info.output_bfd, &link_info);

  /* Choose type of STM32L4XX erratum fix, or warn if specified fix is
     unnecessary due to architecture version.  */
  bfd_elf32_arm_set_stm32l4xx_fix (link_info.output_bfd, &link_info);

  /* Auto-select Cortex-A8 erratum fix if it wasn't explicitly specified.  */
  /* FIXME: see comment the params structure. */
#if 0
  bfd_elf32_arm_set_cortex_a8_fix (link_info.output_bfd, &link_info);
#endif

  /* Ensure the output sections of veneers needing a dedicated one is not
     removed.  */
  bfd_elf32_arm_keep_private_stub_output_sections (&link_info);

  /* We should be able to set the size of the interworking stub section.  We
     can't do it until later if we have dynamic sections, though.  */
  if (elf_hash_table (&link_info)->dynobj == NULL)
    {
      /* Here we rummage through the found bfds to collect glue information.  */
      LANG_FOR_EACH_INPUT_STATEMENT (is)
	{
          /* Initialise mapping tables for code/data.  */
          bfd_elf32_arm_init_maps (is->the_bfd);

	  if (!bfd_elf32_arm_process_before_allocation (is->the_bfd,
							&link_info)
	      || !bfd_elf32_arm_vfp11_erratum_scan (is->the_bfd, &link_info)
	      || !bfd_elf32_arm_stm32l4xx_erratum_scan (is->the_bfd,
							&link_info))
	    /* xgettext:c-format */
	    einfo (_("Errors encountered processing file %s"), is->filename);
	}

      /* We have seen it all.  Allocate it, and carry on.  */
      bfd_elf32_arm_allocate_interworking_sections (& link_info);
    }

  /* Call the standard elf routine.  */
  emultempl_before_allocation ();
}

/* Fake input file for stubs.  */
static lang_input_statement_type *stub_file;

/* stuff inserted for pic32c JLM */

/* Memory Reporting Info */
struct magic_section_description_tag {
 char *name;
 char *description;
};

struct magic_sections_tag
{
  const struct magic_section_description_tag *sections;
  unsigned int count;
  unsigned int index;
  unsigned int start;
};

bfd_boolean need_layout;

#ifdef ENABLE_USER_MEMORY
static void bfd_pic32_report_memory_sections
   (const char *, asection *, FILE *);
#endif

void bfd_pic32_report_memory_usage
   (FILE *);

extern void bfd_pic32_report_memory_usage_by_module
   (FILE *);

static void report_percent_used
   (bfd_vma, bfd_vma, FILE *);

void pic32_build_section_list
   (bfd *, asection *, PTR);

void pic32_build_section_list_vma
   (bfd *, asection *, PTR);


static struct pic32_section *  find_pic32_sec_from_bfd_section(struct pic32_section *, asection *);



bfd_boolean pic32_is_empty_list
   (struct pic32_section* const lst);
#if 0
static void pic32_init_section_list
   (struct pic32_section **);
#endif

#ifdef ENABLE_USER_MEMORY
static bfd_boolean pic32_name_in_section_list
   (struct pic32_section *, const char *);
#endif

static void bfd_pic32_finish
   (void);

void pic32_create_data_init_section_lists(void);

void pic32_find_data_code_sections(void);

void pic32_create_specific_fill_sections(void);

static void bfd_pic32_add_bfd_to_link
   (bfd *, const char *);

static void bfd_pic32_scan_data_section
(struct pic32_section*, PTR);

static void bfd_pic32_scan_code_section
   (struct pic32_section*, PTR);

static void pic32_strip_sections
  (bfd *);

static void pic32_merge_sections(void);
 
void pic32_append_section_to_list
   (struct pic32_section *, asection *);

static struct pic32_section *
pic32_copy_list (struct pic32_section *);

struct pic32_section *
pic32_copy_section (struct pic32_section *);

void pic32_free_section_list
   (struct pic32_section **);


int pic32_section_list_length
   (struct pic32_section *);

void pic32_print_section_list
   (struct pic32_section *, const char *);

void pic32_remove_from_section_list
   (struct pic32_section *, struct pic32_section *);

void pic32_remove_group_from_section_list
   (struct pic32_section *);

struct pic32_memory * pic32_static_assign_memory
   (struct pic32_memory *, bfd_vma, bfd_vma);

void pic32_add_to_memory_list
   (struct pic32_memory *, bfd_vma, bfd_vma);

void pic32_remove_from_memory_list
   (struct pic32_memory *, struct pic32_memory *);

int pic32_init_region_info
   (struct region_info *);

void pic32_free_region_info
   (struct region_info *);

#ifdef ENABLE_SERIAL_MEM
static int allocate_serial_memory
   (void);
#endif

#ifdef ENABLE_USER_MEMORY
static int allocate_user_memory
   (void);
#endif

void pic32_free_memory_list
   (struct pic32_memory **);

void pic32_init_memory_list
   (struct pic32_memory **);

bfd_boolean pic32_unique_section
   (const char *s);

static bfd_boolean bfd_pic32_process_bfd_after_open
   (bfd *, struct bfd_link_info *);

lang_memory_region_type *region_lookup
   (char *);

static bfd_size_type bfd_pic32_report_sections
   (struct pic32_section *, const lang_memory_region_type *,
           struct magic_sections_tag *, FILE *);

bfd_size_type bfd_pic32_collect_section_size
   (struct pic32_section *, const lang_memory_region_type *);

static const char * bfd_pic32_lookup_magic_section_description
   (const char *, struct magic_sections_tag *, const char **);

// coherent section processing functions

#ifdef ENABLE_COHERENT
static int locate_coherent_sections
   (unsigned int, struct memory_region_struct *);

static int coherent_section_count = 0;

static void pic32_remove_coherent_group_from_section_list
   (struct pic32_section *, unsigned int);
#endif

#ifdef TARGET_IS_PIC32C
  /* fill option definitions */
static bfd * bfd_pic32_create_fill_bfd
   (bfd *);

void pic32_create_fill_templates
   (void);

static void pic32_create_unused_program_sections
   (struct pic32_fill_option *);

void pic32_report_crypto_sections
  (void);

void bfd_pic32_memory_summary
  (char *);



/* lghica co-resident - to be reviewed*/
// keep it so stufff can compile ...

#define PIC32_CORESIDENT (BSF_WEAK)


int fill_section_count = 0;
int dinit_size = 0;
#endif

struct pic32_section *memory_region_list;
struct pic32_section *unassigned_sections;
struct pic32_section *unassigned_sections_master_copy;
struct pic32_section *alloc_section_list;
struct pic32_section *alloc_bss_section_list;
struct pic32_section *pic32_section_list;
extern unsigned int pic32_attribute_map
     (asection *);
extern void pic32_set_extended_attributes(asection *,
                                          unsigned int, unsigned char );
extern void * bfd_alloc (bfd *, bfd_size_type);

/* defined in ldlang.c */
extern lang_statement_list_type statement_list;

/* defined in elf32-pic32c.c */
extern bfd_boolean pic32c_relocate_vectors;

/* Dynamic Memory Info */
unsigned int stack_base, stack_limit;
unsigned int heap_base, heap_limit;
static bfd_boolean user_defined_stack = FALSE;
static bfd_boolean heap_section_defined = FALSE;
static ATTRIBUTE_UNUSED bfd_boolean stack_section_defined = FALSE;
static bfd *heap_bfd, *stack_bfd ATTRIBUTE_UNUSED;

extern bfd *init_bfd;
static bfd *stack_bfd;
extern unsigned char *init_data;
extern asection *init_template;
extern uint32_t init_data_padding;
extern struct pic32_section *data_sections;
extern struct pic32_section *code_sections;

/* Symbol Tables */
static asymbol **symtab;
static int symptr;

/* symbols for stack in DTCM*/
bfd_vma dtcm_stack_limit = 0;
bfd_vma dtcm_stack_base = 0;

static bfd_boolean is_cmse_implib (void);

/* Declare functions used by various EXTRA_EM_FILEs.  */

void pic32c_after_open  (void);

/* Memory Reporting Info */
static const struct magic_section_description_tag magic_pmdescriptions[] =
   {{"", ""},
   {".text", "App's exec code"},
   {".rodata", "Read-only const"},
   {".sdata2", "Small initialized, constant global and static data template"},
   {".sbss2", "Small uninitialized, constant global and static data"},
   {".eh_frame_hdr", "Stack unwind header"},
   {".eh_frame", "Stack unwind info"},
   {".data", "Data-init template"},
   {".got", "Global offset table"},
   {".sdata", "Small data-init template"},
   {".lit8", "8-byte constants"},
   {".lit4", "4-byte constants"},
   {".ramfunc", "RAM-funct template"},
   {".startup", "C startup code"},
   {".app_excpt", "General-Exception"},
   {".reset", "Reset handler"},
   {".bev_excpt", "BEV-Exception"},
   {".vector_0", "Interrupt Vector 0"},
   {".vector_1", "Interrupt Vector 1"},
   {".vector_2", "Interrupt Vector 2"},
   {".vector_3", "Interrupt Vector 3"},
   {".vector_4", "Interrupt Vector 4"},
   {".vector_5", "Interrupt Vector 5"},
   {".vector_6", "Interrupt Vector 6"},
   {".vector_7", "Interrupt Vector 7"},
   {".vector_8", "Interrupt Vector 8"},
   {".vector_9", "Interrupt Vector 9"},
   {".vector_10", "Interrupt Vector 10"},
   {".vector_11", "Interrupt Vector 11"},
   {".vector_12", "Interrupt Vector 12"},
   {".vector_13", "Interrupt Vector 13"},
   {".vector_14", "Interrupt Vector 14"},
   {".vector_15", "Interrupt Vector 15"},
   {".vector_16", "Interrupt Vector 16"},
   {".vector_17", "Interrupt Vector 17"},
   {".vector_18", "Interrupt Vector 18"},
   {".vector_19", "Interrupt Vector 19"},
   {".vector_20", "Interrupt Vector 20"},
   {".vector_21", "Interrupt Vector 21"},
   {".vector_22", "Interrupt Vector 22"},
   {".vector_23", "Interrupt Vector 23"},
   {".vector_24", "Interrupt Vector 24"},
   {".vector_25", "Interrupt Vector 25"},
   {".vector_26", "Interrupt Vector 26"},
   {".vector_27", "Interrupt Vector 27"},
   {".vector_28", "Interrupt Vector 28"},
   {".vector_29", "Interrupt Vector 29"},
   {".vector_30", "Interrupt Vector 30"},
   {".vector_31", "Interrupt Vector 31"},
   {".vector_32", "Interrupt Vector 32"},
   {".vector_33", "Interrupt Vector 33"},
   {".vector_34", "Interrupt Vector 34"},
   {".vector_35", "Interrupt Vector 35"},
   {".vector_36", "Interrupt Vector 36"},
   {".vector_37", "Interrupt Vector 37"},
   {".vector_38", "Interrupt Vector 38"},
   {".vector_39", "Interrupt Vector 39"},
   {".vector_40", "Interrupt Vector 40"},
   {".vector_41", "Interrupt Vector 41"},
   {".vector_42", "Interrupt Vector 42"},
   {".vector_43", "Interrupt Vector 43"},
   {".vector_44", "Interrupt Vector 44"},
   {".vector_45", "Interrupt Vector 45"},
   {".vector_46", "Interrupt Vector 46"},
   {".vector_47", "Interrupt Vector 47"},
   {".vector_48", "Interrupt Vector 48"},
   {".vector_49", "Interrupt Vector 49"},
   {".vector_50", "Interrupt Vector 50"},
   {".vector_51", "Interrupt Vector 51"},
   {".vector_52", "Interrupt Vector 52"},
   {".vector_53", "Interrupt Vector 53"},
   {".vector_54", "Interrupt Vector 54"},
   {".vector_55", "Interrupt Vector 55"},
   {".vector_56", "Interrupt Vector 56"},
   {".vector_57", "Interrupt Vector 57"},
   {".vector_58", "Interrupt Vector 58"},
   {".vector_59", "Interrupt Vector 59"},
   {".vector_60", "Interrupt Vector 60"},
   {".vector_61", "Interrupt Vector 61"},
   {".vector_62", "Interrupt Vector 62"},
   {".vector_63", "Interrupt Vector 63"}
   };

static const struct magic_section_description_tag magic_dmdescriptions[] =
   {{"", ""},
   {".data", "Initialized data"},
   {".got", "Global offset table"},
   {".sdata", "Small init data"},
   {".lit8", "8-byte constants"},
   {".lit4", "4-byte constants"},
   {".sbss", "Small uninit data"},
   {".bss", "Uninitialized data"},
   {".heap", "Dynamic Memory heap"},
   {".stack", "Min reserved for stack"},
   {".ramfunc", "RAM functions"},
   {".dbg_data", "Memory reserved for debugger exec"}};

struct magic_sections_tag magic_dm =
{
  magic_dmdescriptions,
  0, 0, 0
};
struct magic_sections_tag magic_pm =
{
  magic_pmdescriptions,
  0, 0, 0
};

static bfd_size_type total_prog_memory = 0;
static bfd_size_type total_data_memory = 0;
static bfd_size_type actual_prog_memory_used = 0;
static bfd_size_type data_memory_used = 0;
static bfd_size_type region_data_memory_used = 0;

/* User-defined memory regions */
#ifdef ENABLE_USER_MEMORY
static bfd_size_type external_memory_used = 0;
static bfd_boolean has_user_defined_memory = FALSE;
const char *memory_region_prefix = "__memory_";
static struct pic32_section *memory_region_list;
static struct pic32_section *user_memory_sections;
#endif

/* Section Lists */
struct pic32_section *pic32_section_list;
struct pic32_section *unassigned_sections;

/* Whether we need to call arm_layout_sections_again.  */
static int need_laying_out = 0;

/* Maximum size of a group of input sections that can be handled by
   one stub section.  A value of +/-1 indicates the bfd back-end
   should use a suitable default size.  */
bfd_signed_vma group_size = 1;

struct hook_stub_info
{
  lang_statement_list_type add;
  asection *input_section;
};

/* Traverse the linker tree to find the spot where the stub goes.  */

static bfd_boolean
hook_in_stub (struct hook_stub_info *info, lang_statement_union_type **lp)
{
  lang_statement_union_type *l;
  bfd_boolean ret;
 
 
  for (; (l = *lp) != NULL; lp = &l->header.next)
    {
      switch (l->header.type)
	{
	case lang_constructors_statement_enum:
	  ret = hook_in_stub (info, &constructor_list.head);
	  if (ret)
	    return ret;
	  break;

	case lang_output_section_statement_enum:
	  ret = hook_in_stub (info,
			      &l->output_section_statement.children.head);
	  if (ret)
	    return ret;
	  break;

	case lang_wild_statement_enum:
	  ret = hook_in_stub (info, &l->wild_statement.children.head);
	  if (ret)
	    return ret;
	  break;

	case lang_group_statement_enum:
	  ret = hook_in_stub (info, &l->group_statement.children.head);
	  if (ret)
	    return ret;
	  break;

	case lang_input_section_enum:
	  if (l->input_section.section == info->input_section)
	    {
	      /* We've found our section.  Insert the stub immediately
		 after its associated input section.  */
	      *(info->add.tail) = l->header.next;
	      l->header.next = info->add.head;
	      return TRUE;
	    }
	  break;

	case lang_data_statement_enum:
	case lang_reloc_statement_enum:
	case lang_object_symbols_statement_enum:
	case lang_output_statement_enum:
	case lang_target_statement_enum:
	case lang_input_statement_enum:
	case lang_assignment_statement_enum:
	case lang_padding_statement_enum:
	case lang_address_statement_enum:
	case lang_fill_statement_enum:
	  break;

	default:
	  FAIL ();
	  break;
	}
    }
  return FALSE;
}




/*
** region_lookup()
**
** This provides a wrapper around speculative lookups
** of 'known' regions, i.e. lang_memory_region_lookup(name,FALSE),
** which suppresses the warning when the region is not present.
**
** Note: Ideally, every linker script will include
** these definitions. But we don't want to fail
** if the user is running with a minimal script, or with the
** built-in script.
*/

#define NAME_IS(s) \
  ((strlen(name) == strlen(#s)) && \
           strcmp(name, (#s)) == 0)

lang_memory_region_type *
region_lookup (char *name)
{
  if (!lang_memory_region_exist (name)) 
    return NULL;
  return lang_memory_region_lookup (name, FALSE);
}

/*
** Utility routine: bfd_pic32_report_sections()
**
** - show memory usage of SEC_ALLOC-flagged sections in memory
*/
static bfd_size_type
bfd_pic32_report_sections (s, region, magic_sections, fp)
     struct pic32_section *s;
     const lang_memory_region_type *region;
     struct magic_sections_tag *magic_sections;
     FILE *fp;
{
  const char *description;
  bfd_size_type region_used = 0;
  unsigned long start = s->sec->vma;
  unsigned long load  = s->sec->lma;
  unsigned long actual = s->sec->size;
  size_t name_len = 0;

  if (PIC32_IS_COHERENT_ATTR(s->sec)) {
    start &= 0xdfffffff;
    load &= 0xdfffffff;
  }

  /* TODO: this is probably indicative of serious issues, if we want
     to report on a fake region. consider an assertion. */
  if (!valid_region (region))
    return 0;
    
  /*
  ** report SEC_ALLOC sections in memory
  */
  if ((s->sec->flags & SEC_ALLOC)
  &&  (s->sec->size > 0))
    {
      char *name, *c;
#define NAME_MAX_LEN 23
#define NAME_FIELD_LEN "24"
      if (strstr(s->sec->name, "fill$")) {
        name = xmalloc(7);
        if (PIC32_IS_ABSOLUTE_ATTR(s->sec))
          strcpy(name, "FILLED");
        else
          strcpy(name, "UNUSED");
      }
      else {
      /* make a local copy of the name */
      name_len = strlen(s->sec->name);
      name = xmalloc(name_len + 1);
      if (NULL == name) {
        fprintf( stderr, "Fatal Error: Could not copy section name\n");
        abort();
      }
      if (name_len > NAME_MAX_LEN)
        name_len = NAME_MAX_LEN;
      strncpy(name, s->sec->name, name_len);
      name[name_len] = '\0';
      }
      /* clean the name of %n */
      c = strchr(name, '%');
      if (c) *c = (char) '\0';

      if ((start >= region->origin) &&
          ((start + actual) <= (region->origin + region->length)))
      {
           bfd_pic32_lookup_magic_section_description (name, magic_sections, &description);
         fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", name,
                 start, actual, actual, description);
         region_used = actual;
      }
      else if ((load >= region->origin) &&
          ((load + actual) <= (region->origin + region->length)) &&
           (s->sec->flags & (SEC_HAS_CONTENTS)))
      {
           bfd_pic32_lookup_magic_section_description (name, magic_sections, &description);
         fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", name,
                  load, actual, actual, description);
         region_used = actual;
      }
      free(name);
#undef NAME_MAX_LEN
#undef NAME_FIELD_LEN
    }
  return region_used;
} /* static bfd_size_type bfd_pic32_report_sections (...) */

static const char empty_string[] = "";
static const char * bfd_pic32_lookup_magic_section_description (name, magic_sections, description)
     const char *name;
     struct magic_sections_tag *magic_sections;
     const char **description;
{
      /* Assume that we don't have a description for the magic section name */
      *description = &empty_string[0];
      do
      {
        if (strcmp(name, magic_sections->sections[magic_sections->index].name))
        {
          /* Keep searching */
          magic_sections->index++;
          if (magic_sections->index == magic_sections->count)
            magic_sections->index = 0;
        }
        else
        {
          *description = magic_sections->sections[magic_sections->index].description;
          break;
        }
      } while(magic_sections->index != magic_sections->start);
      /* Start the next search where this one left off. */
      magic_sections->start = magic_sections->index;

      return *description;
} /* static void char * bfd_pic32_lookup_magic_section_description (...) */

static bfd_boolean 
bfd_pic32_process_bfd_after_open (abfd, info) 
    bfd *abfd;
    struct bfd_link_info *info ATTRIBUTE_UNUSED;
{
  asection *sec;
  asymbol **symbols = 0;
  bfd_boolean has_extended_attributes = FALSE;
  struct pic32_symbol_list *pic32_symbol_list = NULL;

  /*
  ** check the input file name
  */
  if (!strcmp (abfd->filename, "sbrk.o"))
    {
      pic32_heap_required = 1;
    }

  /*
   ** loop through the symbols in this bfd
   */
  {
	pic32_symbol_list = bfd_pic32_fill_symbol_list(abfd);

    /*
     ** loop through the sections in this bfd
     */
    for (sec = abfd->sections; sec != 0; sec = sec->next)
      {
	/* if section has extended attributes, apply them */
	if (pic32_symbol_list)
	  {
	    int c;
	    for (c = 0; c < pic32_symbol_list->pic32_symbol_count; c++)
	      {
		if (strcmp (sec->name, pic32_symbol_list->syms[c].name) == 0)
		  pic32_set_extended_attributes (sec,
						 pic32_symbol_list->syms[c].value, 0);
	      }
	  }

	/* if section has HEAP attribute, record that fact */
	if (PIC32_IS_HEAP_ATTR (sec) && (sec->size > 0))
	  {
	    if (heap_section_defined)
	      einfo (_ ("%P%X: Error: Multiple heap sections defined\n"));
	    else
	      {
		heap_section_defined = TRUE;
		heap_bfd = sec->owner;
		if ((pic32c_heap_size > 0) && (pic32c_heap_size != (sec->size)))
		  einfo (_ ("%P%X: Error: Size of heap requested (%d bytes)"
			    " does not match heap defined in section \'%s\'"
			    "  (%d bytes)\n"),
			 pic32c_heap_size, sec->name, sec->size);
	      }
	  }

	flagword old_flags = sec->flags;

	/* process input section flags here, if necessary */
	if ((sec->flags & (SEC_ALLOC | SEC_LOAD | SEC_DATA))
	    == (SEC_ALLOC | SEC_LOAD | SEC_DATA))
	  sec->flags |= SEC_HAS_CONTENTS; /* elf linker needs this */

	/* report if flags were changed */
	if (sec->flags != old_flags)
	  PIC32_DEBUG("   adjust flags: %s %x --> %x", sec->name,
		      old_flags, sec->flags);
      }

    if (symbols)
      free (symbols);
	if (pic32_symbol_list && has_extended_attributes) {
	  free(pic32_symbol_list->syms);
	  free(pic32_symbol_list);
	}
    return TRUE;
  }
}

void
pic32_find_data_code_sections(void)
{
  /*
   * Loop through all input sections and
   * build a list of DATA or BSS type, and identifying which require
   * initialization.
   */

  asection *sec;
  LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
      for (sec = f->the_bfd->sections; sec != (asection *) NULL;
           sec = sec->next)
        {
          if (((sec->size > 0) && (sec->linked == 0)
               && (PIC32_IS_DATA_ATTR (sec)))
              || (PIC32_IS_BSS_ATTR (sec)) || PIC32_IS_RAMFUNC_ATTR (sec)
              || ((sec->size > 0)
                  && (PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR (sec)))
              || (PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR (sec)))
            pic32_append_section_to_list (data_sections, sec);
          else if ((sec->size > 0) && PIC32_IS_CODE_ATTR (sec))
            pic32_append_section_to_list (code_sections, sec);
        }
    }
}

void
pic32_create_data_init_section_lists(void)
{
  /* init list of input data sections */
  pic32_init_section_list (&data_sections);

  /* init list of input code sections */
  pic32_init_section_list (&code_sections);
}

/* Create the .dinit section describing sections that require
   runtime relocation/initialization, e.g. are located in an output
   region that is not loaded.
*/
void
pic32_create_data_init_template(void)
{
  struct pic32_section *s;
  int total_data = 0;
  asection *sec;

  /*
  ** If data init support is enabled, create a BFD
  ** for section .dinit and add it to the link.
  */
  if (!pic32_data_init)
    {
      init_bfd = NULL;
      init_data = NULL;
    }
  else
    {
      init_bfd = bfd_pic32_create_data_init_bfd (link_info.output_bfd);
      bfd_pic32_add_bfd_to_link (init_bfd, init_bfd->filename);
    }

  /* Compute size of data init template */
  for (s = data_sections; s != NULL; s = s->next)
    if ((s->sec) && ((s->sec->flags & SEC_EXCLUDE) == 0))
      bfd_pic32_scan_data_section (s, &total_data);

  ///\ place in dinit .text sections that should run from itcm
  for (s = code_sections; s != NULL; s = s->next)
    {
      if ((s->sec) && ((s->sec->flags & SEC_EXCLUDE) == 0))
        {
          if ((pic32c_relocate_vectors)
              && (strstr (s->sec->name, ".vectors") != NULL))
            {
              total_data
                += ((s->sec->size % 4) ? (s->sec->size + (4 - s->sec->size % 4))
                    : s->sec->size)
                + DATA_RECORD_HEADER_SIZE;

              /* indicate this will be in template (scan_code_section
                 normally sets this) */
              s->sec->init = 1;
              s->sec->flags &= ~SEC_LOAD;

              PIC32_DEBUG("marking .vectors as requiring initialization");
            }
          else if (s->sec->itcm)
            bfd_pic32_scan_code_section (s, &total_data);
        }
    }

  total_data += 8; /* zero terminated -> 64-bit value*/

  if (total_data % 16)
    init_data_padding += 16 - (total_data % 16);
  total_data += init_data_padding;

  DEBUG({
      pic32_print_section_list (data_sections, "data sections after scan");
      pic32_print_section_list (code_sections, "code sections after scan");
    });
  
  /* bail out having scanned all sections if dinit is disabled. */
  if (!pic32_data_init)
    {
      PIC32_DEBUG("skipping .dinit creation (--no-data-init)");
      return;
    }

  dinit_size = total_data;

  PIC32_DEBUG("optim_dinit dinit_size 0x%x", total_data);

  /* allocate memory for the template */
  init_data = (unsigned char *) bfd_alloc (link_info.output_bfd, total_data);

  if (!init_data)
    {
      fprintf (stderr, "Link Error: not enough memory for data template\n");
      abort ();
    }

  /* fill the template with a default value */
  init_data = memset (init_data, 0x11, total_data);

  /* attach it to the input section */
  sec = bfd_get_section_by_name (init_bfd, ".dinit");

  if (!sec)
    {
      /* FIXME: is an error appropriate here? */
      PIC32_DEBUG("after_open: section .dinit not found");
    }
  else
    {
      sec->size = total_data;
      sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE
                     | SEC_KEEP | SEC_READONLY);
      sec->contents = init_data;
      bfd_set_section_size (init_bfd, sec, total_data);
      init_template = sec; /* save a copy for later */

      if (pic32_dinit_has_absolute_address)
        {
          bfd_set_section_vma (init_bfd, sec, dinit_address);
          PIC32_SET_ABSOLUTE_ATTR (sec);
        }
    }
}

/*
** Create a bfd for the stack
**
** Uses the following global variables:
**   symtab
**   symptr
**   pic32c_stack_size
*/
static bfd *
bfd_pic32_create_stack_bfd (bfd *parent) {
  bfd_size_type size;
  bfd *abfd;
  asection *sec;
  char *oname;
  int flags, align;

  /* create a bare-bones bfd */
  oname = (char *) xmalloc (20);
  sprintf (oname, "stack");
  abfd = bfd_create (oname, parent);
  bfd_find_target (EMULTEMPL.output_format, abfd);
  bfd_make_writable (abfd);

  bfd_set_format (abfd, bfd_object);
  bfd_set_arch_mach (abfd, bfd_arch_arm, 0);

  /* create a symbol table (room for 1 entry) */
  symptr = 0;
  symtab = (asymbol **) xmalloc (2 * sizeof (asymbol *));

  /* create a bare-bones section */
  flags = SEC_LINKER_CREATED | SEC_KEEP;
  align = 1;
  sec = bfd_pic32_create_section (abfd, ".stack", flags, align);
  bfd_set_section_flags (abfd, sec, flags);
  size = 8;
  bfd_set_section_size (abfd, sec, size);

  /* put in the symbol table */
  bfd_set_symtab (abfd, symtab, symptr);

  /* finish it */
  if (!bfd_make_readable (abfd)) {
      fprintf( stderr, "Link Error: can't make stack readable\n");
      abort();
    }
  /* set section flags & attributes again, because the call to
     bfd_make_readable() loses them */
     sec = abfd->sections;
     flags = SEC_LINKER_CREATED | SEC_KEEP;
     bfd_set_section_flags (abfd, sec, flags);
  return abfd;
} /* static bfd * bfd_pic32_create_stack_bfd (...)*/




// add a new stub section to the list of pic32 sections we are keeping
//   after_input_section is the section that caused the stub to be required
static void pic32_add_stub_to_master_copy(asection *after_input_section, asection *new_stub) {


    struct pic32_section *anchor;
    
    if (after_input_section == NULL) {
	/* we should not ever get here ... after_input_section should never be NULL */
	pic32_append_section_to_list(unassigned_sections_master_copy, new_stub);
    }
    // bail if it isn't one of ours
    else if (after_input_section->bfa == FALSE) {
	return;
    }
    else {
        anchor = find_pic32_sec_from_bfd_section(unassigned_sections_master_copy, after_input_section);
	if (anchor == NULL) einfo ("%F Stub %s added after section we can't find: %E\n", new_stub->name);
	
	PIC32_DEBUG("Adding stub %s of size %d alignment %d to section %s",
		    new_stub->name,
		    new_stub->size,
		    new_stub->alignment_power,
		    anchor->sec->name);
	if (NULL == anchor->children) pic32_init_section_list(&anchor->children);
	

	/* if anchor is a ramfunc section then we need to mark the stub the same
	   way and increment the size of dinit        */

	if (anchor->sec && (PIC32_IS_RAMFUNC_ATTR(anchor->sec))) 
	      PIC32_SET_RAMFUNC_ATTR(new_stub);
	if (anchor->sec && (PIC32_IS_ITCM_ATTR(anchor->sec))) 
	      PIC32_SET_ITCM_ATTR(new_stub);
	if (anchor->sec && (PIC32_IS_NOPA_ATTR(anchor->sec))) 
	    PIC32_SET_NOPA_ATTR(new_stub);
	if (anchor->sec->init) new_stub->init =1;
	/* SEC_KEEP causes trouble with pic32c-valid-attributes so if the anchor doesn't have it remove it from the stub */
	/* fixme: this is not a great long-term thing */
	if ((anchor->sec->flags & SEC_KEEP)==0) new_stub->flags = new_stub->flags & ~SEC_KEEP;

	/* for alignment propagate it upwards if needed ... */
	if (new_stub->alignment_power > anchor->sec->alignment_power) anchor->sec->alignment_power = new_stub->alignment_power;

	pic32_append_section_to_list(anchor->children, new_stub);
        /* and add  it to code_sections so that dinit can see it */
	pic32_append_section_to_list(code_sections, new_stub);
	


    }
}




/* Call-back for elf32_arm_size_stubs.  */

/* Create a new stub section, and arrange for it to be linked
   immediately after INPUT_SECTION.  */

static asection *
elf32_arm_add_stub_section (const char * stub_sec_name,
			    asection *   output_section,
			    asection *   after_input_section,
			    unsigned int alignment_power)
{
  asection *stub_sec;
  flagword flags;
  lang_output_section_statement_type *os;
  struct hook_stub_info info;


  flags = (SEC_ALLOC | SEC_LOAD | SEC_READONLY | SEC_CODE
	   | SEC_HAS_CONTENTS | SEC_RELOC | SEC_IN_MEMORY | SEC_KEEP);
  stub_sec = bfd_make_section_anyway_with_flags (stub_file->the_bfd,
						 stub_sec_name, flags);
  if (stub_sec == NULL)
    goto err_ret;

  bfd_set_section_alignment (stub_file->the_bfd, stub_sec, alignment_power);

  os = lang_output_section_get (output_section);

  info.input_section = after_input_section;
  lang_list_init (&info.add);
  lang_add_section (&info.add, stub_sec, NULL, os);

  if (info.add.head == NULL)
    goto err_ret;

  // add this stub to the list of pic32 sections we are keeping 
  pic32_add_stub_to_master_copy(after_input_section, stub_sec);

  
  if (after_input_section == NULL)
    {
      lang_statement_union_type **lp = &os->children.head;
      lang_statement_union_type *l, *lprev = NULL;

      for (; (l = *lp) != NULL; lp = &l->header.next, lprev = l);

      if (lprev)
	lprev->header.next = info.add.head;
      else
	os->children.head = info.add.head;

      return stub_sec;
    }
  else
    {
      if (hook_in_stub (&info, &os->children.head))
	return stub_sec;
    }

 err_ret:
  einfo ("%X%P: can not make stub section: %E\n");
  return NULL;
}

/* Another call-back for elf_arm_size_stubs.  */

static void
arm_layout_sections_again (void)
{
  /* If we have changed sizes of the stub sections, then we need
     to recalculate all the section offsets.  This may mean we need to
     add even more stubs.  */
  emultempl_map_segments (TRUE);
  need_laying_out = -1;
}

static void
build_section_lists (lang_statement_union_type *statement)
{
  if (statement->header.type == lang_input_section_enum)
    {
      asection *i = statement->input_section.section;

      if (i->sec_info_type != SEC_INFO_TYPE_JUST_SYMS
	  && (i->flags & SEC_EXCLUDE) == 0
	  && i->output_section != NULL
	  && i->output_section->owner == link_info.output_bfd)
	elf32_arm_next_input_section (& link_info, i);
    }
}

static int
compare_output_sec_vma (const void *a, const void *b)
{
  asection *asec = *(asection **) a, *bsec = *(asection **) b;
  asection *aout = asec->output_section, *bout = bsec->output_section;
  bfd_vma avma, bvma;

  /* If there's no output section for some reason, compare equal.  */
  if (!aout || !bout)
    return 0;

  avma = aout->vma + asec->output_offset;
  bvma = bout->vma + bsec->output_offset;


  if (avma > bvma)
    return 1;
  else if (avma < bvma)
    return -1;

  return 0;
}


/*
 * This routine is called after allocate_memory when dinit is 
 * disabled, and is responsible for warning if a section 
 * will not be initialized.
 *
 * This effectively means any section placed by the BFA requiring initialization,
 * rather than anything modified by the script. 
 */
static void
pic32_warn_if_dinit_needed (struct pic32_section *section)
{
  if (section->sec && section->sec->bfa && section->sec->init)
    {
      einfo (_ (
	       "%P: warning: automatic data initialization has been turned off,"
	       " section %s will not be initialized using .dinit template.\n"),
	     section->sec->name);
    }
}




/* Stuff for checking for overlap.  This is substantially copied from
   lang_check_section_addresses in ldlang.c 
   We are doing less here - we are only returning a boolean value indicating if 
   any sections overlap.  We are not printing any error message, we will try to
   reallocate.
*/

struct check_sec
{
  asection *sec;
};

static int
sort_sections_by_lma (const void *arg1, const void *arg2)
{
  const asection *sec1 = ((const struct check_sec *) arg1)->sec;
  const asection *sec2 = ((const struct check_sec *) arg2)->sec;

  if (sec1->lma < sec2->lma)
    return -1;
  else if (sec1->lma > sec2->lma)
    return 1;
  else if (sec1->id < sec2->id)
    return -1;
  else if (sec1->id > sec2->id)
    return 1;

  return 0;
}

static int
sort_sections_by_vma (const void *arg1, const void *arg2)
{
  const asection *sec1 = ((const struct check_sec *) arg1)->sec;
  const asection *sec2 = ((const struct check_sec *) arg2)->sec;

  if (sec1->vma < sec2->vma)
    return -1;
  else if (sec1->vma > sec2->vma)
    return 1;
  else if (sec1->id < sec2->id)
    return -1;
  else if (sec1->id > sec2->id)
    return 1;

  return 0;
}

/* debug display stuff JLM */

void display_bfd_section(asection*);
void display_bfd_section(asection *s){
    if (s==NULL) return;
    LOG("os %s lma %X size %d ",s->name,s->lma,s->size);
    if (s->output_section != NULL) LOG( "w/ os %s lma %X size %d ",s->output_section->name,s->output_section->lma,s->output_section->size);
    LOG("\n");
}

void display_output_section_statement(lang_statement_union_type*, int);
void display_output_section_statement(lang_statement_union_type *oss, int indent){
  lang_statement_union_type *l;
  for ( l = oss;l != NULL; l = l->header.next)
    
    switch (l->header.type)
	{
	case lang_output_section_statement_enum:
	  {
	    lang_output_section_statement_type osst = l->output_section_statement;
	    LOG("%d: oss %s has output section   ",indent, osst.name);
	    display_bfd_section(osst.bfd_section);
	    display_output_section_statement(osst.children.head, indent+1);
	    break;
	  }
	case lang_input_section_enum:
	    LOG("%d: input section: ",indent);
	    display_bfd_section(l->input_section.section);
	    break;
	case lang_wild_statement_enum:
	    LOG("%d: found a wild one \n",indent);
	    display_output_section_statement(l->wild_statement.children.head, indent+1);	    
	    break;
	case lang_constructors_statement_enum:
	    LOG("%d: found a ctor one \n",indent);
	    display_output_section_statement(constructor_list.head, indent+1);	    
	    break;
	case lang_group_statement_enum:
	    LOG("%d: found a group one \n",indent);
	    display_output_section_statement(l->group_statement.children.head, indent+1);	    
	    break;
	    
	case lang_input_statement_enum:
	    LOG("%d: found an input statement for %s \n",indent,l->input_statement.filename);
	    break;
	case lang_padding_statement_enum:
	    LOG("%d: found a padding statement %d bytes \n",indent,l->padding_statement.size);
	    break;

	case lang_data_statement_enum:
	case lang_reloc_statement_enum:
	case lang_object_symbols_statement_enum:
	case lang_output_statement_enum:
	case lang_target_statement_enum:
	case lang_assignment_statement_enum:
	case lang_address_statement_enum:
	case lang_fill_statement_enum:
	    LOG("%d: found a weird one %d \n",indent,l->header.type);
	    break;
	default:
	    FAIL ();
	    break;
	}
}
  


void display_output_section_statements(char*);
void display_output_section_statements(char *msg){
    lang_statement_union_type *oss =   lang_output_section_statement.head;
    LOG("Output section statements at %s \n",msg);
    display_output_section_statement(oss,0);
}
/* debug display routimes commented out
void pic32_display_output_bfd(char *);
void pic32_display_output_bfd(char * title){

    asection *s;
    int count = 0;
    LOG("output bfd at %s \n",title);
    for (s = link_info.output_bfd->sections; s != NULL; s = s->next)
	{
	    printf ("%s : %d :: ",s->name,s->size);
	    count++;
	}

    LOG("\n %d sections \n");
}
*/




bfd_boolean pic32_sections_overlap(void);

bfd_boolean pic32_sections_overlap(void){

  asection *s, *p;
  struct check_sec *sections;
  size_t i, count;
  bfd_vma s_start;
  bfd_vma s_end;
  bfd_vma p_start = 0;
  bfd_vma p_end = 0;
  bfd_boolean overlays;
  count = bfd_count_sections (link_info.output_bfd);
  if (count <= 1) return FALSE;
  sections = XNEWVEC (struct check_sec, count);

  /* Scan all sections in the output list.  */
  count = 0;
  for (s = link_info.output_bfd->sections; s != NULL; s = s->next)
    {
      if ((s->flags & SEC_ALLOC) == 0
          || s->size == 0)
        continue;

      sections[count].sec = s;
      count++;
    }

  if (count <= 1)
    {
      free (sections);
      return FALSE;
    }

  qsort (sections, count, sizeof (*sections), sort_sections_by_lma);
  /* First check section LMAs.  There should be no overlap of LMAs on
     loadable sections, even with overlays.  */

  for (p = NULL, i = 0; i < count; i++)
    {
      s = sections[i].sec;
      if ((s->flags & SEC_LOAD) != 0)
        {
          s_start = s->lma;
          s_end = s_start +  (s->size) - 1;

          /* Look for an overlap.  We have sorted sections by lma, so
             we know that s_start >= p_start.  Besides the obvious
             case of overlap when the current section starts before
             the previous one ends, we also must have overlap if the
             previous section wraps around the address space.  */
          if (p != NULL
              && (s_start <= p_end
                  || p_end < p_start))
            {
	      /* overlap has been detected */
	      return TRUE;
            }
          p = s;
          p_start = s_start;
          p_end = s_end;
        }
    }
    /* If any non-zero size allocated section (excluding tbss) starts at
     exactly the same VMA as another such section, then we have
     overlays.  Overlays generated by the OVERLAY keyword will have
     this property.  It is possible to intentionally generate overlays
     that fail this test, but it would be unusual.  */
  qsort (sections, count, sizeof (*sections), sort_sections_by_vma);
  overlays = FALSE;
  p_start = sections[0].sec->vma;
  for (i = 1; i < count; i++)
    {
      s_start = sections[i].sec->vma;
      if (p_start == s_start)
        {
          overlays = TRUE;
          break;
        }
      p_start = s_start;
    }

  /* Now check section VMAs if no overlays were detected.  */
  if (!overlays)
    {
      for (p = NULL, i = 0; i < count; i++)
        {
          s = sections[i].sec;
          s_start = s->vma;
          s_end = s_start + (s->size) - 1;

          if (p != NULL
              && (s_start <= p_end
                  || p_end < p_start))
	      return TRUE;
          p = s;
          p_start = s_start;
          p_end = s_end;
        }
    }

  free (sections);
  return FALSE;

     
}







static void pic32_deallocate_sections(struct pic32_section*);

/* recursively remove the output sections associated with a list of pic32_sections
   (and their children)   */

static void pic32_deallocate_sections(struct pic32_section* lst){
    struct pic32_section  *s;
    
    for (s = lst ; s != NULL ; s = s->next) {
	
	if (NULL != s->sec) {
	    if (s->sec->output_section) {
		/* Unlink the section.  */
		s->sec->output_section = NULL;
		if (!PIC32_IS_ABSOLUTE_ATTR(s->sec)){
		    s->sec->vma = 0;
		    s->sec->lma = 0;
		}
	    }
	    if (NULL != s->children){
		pic32_deallocate_sections(s->children);
	    }
	}
    }
}

static void pic32_discard_previous_bfa_allocation(void);

static void pic32_discard_previous_bfa_allocation(){

    lang_statement_union_type *os, *next;
    PIC32_DEBUG("Discarding the output section statements created by the bfa:");

    /* unlink all the output_section statements that follow pic32_last_os */

    for (os =  pic32_last_os;
         os != (lang_statement_union_type *) NULL;) {
        next = os->header.next;
	/* remove next, and its output bfd_section */
	if (NULL == next) break;
	if (next->header.type == lang_output_section_statement_enum) {
	    PIC32_DEBUG("discarding %s", next->output_section_statement.name);
	    /* unlink the oss pointed to by next */
	    if (!(os->header.next = next->header.next))
		/* update statement_list.tail if we just removed/merged the last stmt */
		stat_ptr->tail = &os->header.next;
	    
	    /* there's another (doubly) linked list containing only the output section */
	    /* statements so also update its links and the tail address when the last */
	    /* output statement is removed / merged */
	    if (!(os->output_section_statement.next = next->output_section_statement.next))
		lang_output_section_statement.tail = (union lang_statement_union **) &os->output_section_statement.next;
	    else
		os->output_section_statement.next->prev = (struct lang_output_section_statement_struct *) os;
	    next = os->header.next;	    
	}
	else {
	    LOG("we found a non-oss \n");
	}

    }
    /* next blow through the output bfd and ditch any sections that were added by the bfa
     * this code assumes that the first output section in the output bfd is not from the bfa
     */
    asection *s,*prev;
    prev = link_info.output_bfd->sections;
    for (s = link_info.output_bfd->sections; s != NULL; s = s->next){
	if(s->bfa) {
	    prev = s->prev;
	    prev->next = s->next;
	    
	    if (s->next)
		s->next->prev = prev;
	    else
		 link_info.output_bfd->section_last = prev; /*update the bfd->section_last field
					     if the removed section is the
					     last section.*/
	    link_info.output_bfd->section_count -= 1;
	    s = prev;
	}
    }


    
    /* then look at the input sections we need to reallocate
     and make then look un-allocated  */
    pic32_deallocate_sections(unassigned_sections);

 
}




void
pic32c_after_allocation (void)
{
  int ret;
  //  int tries_remaining = 0;
  bfd_boolean sections_overlap;

  /* Build a sorted list of input text sections, then use that to process
     the unwind table index.  */
  unsigned int list_size = 10;
  asection **sec_list = (asection **)
    xmalloc (list_size * sizeof (asection *));
  unsigned int sec_count = 0;

  LANG_FOR_EACH_INPUT_STATEMENT (is)
    {
      bfd *abfd = is->the_bfd;
      asection *sec;

      if ((abfd->flags & (EXEC_P | DYNAMIC)) != 0)
	continue;

      for (sec = abfd->sections; sec != NULL; sec = sec->next)
	{
	  asection *out_sec = sec->output_section;

	  if (out_sec
	      && elf_section_data (sec)
	      && elf_section_type (sec) == SHT_PROGBITS
	      && (elf_section_flags (sec) & SHF_EXECINSTR) != 0
	      && (sec->flags & SEC_EXCLUDE) == 0
	      && sec->sec_info_type != SEC_INFO_TYPE_JUST_SYMS
	      && out_sec != bfd_abs_section_ptr)
	    {
	      if (sec_count == list_size)
		{
		  list_size *= 2;
		  sec_list = (asection **)
		    xrealloc (sec_list, list_size * sizeof (asection *));
		}

	      sec_list[sec_count++] = sec;
	    }
	}
    }

  qsort (sec_list, sec_count, sizeof (asection *), &compare_output_sec_vma);

  if (elf32_arm_fix_exidx_coverage (sec_list, sec_count, &link_info,
				    params.merge_exidx_entries))
    need_laying_out = 1;

  free (sec_list);


      
  // stuff added here for best fit allocator

  // make a copy of the unassigned sections list to go back to if we need it 
  unassigned_sections_master_copy = pic32_copy_list(unassigned_sections);
  
  
  sections_overlap = TRUE;
  
  /*
  ** Invoke the best-fit allocator
  */
  
  //display_output_section_statements("before first allocation");
  
  if (pic32_allocate)
    {
      /* save aside the last output section statement
	 after sequential allocation
	 we will need it for merging sections and we may need it for reallocation */      
      pic32_last_os = lang_output_section_statement.head;
      /* pic32_last_os points at the last non-null output sections statement  */
      for(; pic32_last_os->header.next !=NULL;pic32_last_os = pic32_last_os->header.next) {};

      allocate_memory ();
    }
  //display_output_section_statements("after first allocation");
  
  
  /* If dinit is turned off, warn if we placed any sections requiring
   * initialization. */
  if (!pic32_data_init)
      {
	   struct pic32_section *s;
	   
	   for (s = data_sections; s != NULL; s = s->next)
	       pic32_warn_if_dinit_needed (s);
	   
	   for (s = code_sections; s != NULL; s = s->next)
	       pic32_warn_if_dinit_needed (s);
       }
   
   /* bfd_elf32_discard_info just plays with debugging sections,
      ie. doesn't affect any code, so we can delay resizing the
      sections.  It's likely we'll resize everything in the process of
      adding stubs.  */
   ret = bfd_elf_discard_info (link_info.output_bfd, & link_info);
   if (ret < 0)
       {
	   einfo ("%X%P: .eh_frame/.stab edit: %E\n");
	   return;
       }
   else if (ret > 0)
       need_laying_out = 1;


   /* If generating a relocatable output file, then we don't
      have to examine the relocs.  */
   if (stub_file != NULL && !bfd_link_relocatable (&link_info))
       {
	   ret = elf32_arm_setup_section_lists (link_info.output_bfd, &link_info);

	   if (ret != 0)
	       {
		   if (ret < 0)
		       {
			   einfo ("%X%P: could not compute sections lists for stub generation: %E\n");
			   return;
		       }
		   
		   lang_for_each_statement (build_section_lists);

		   
		   /* Call into the BFD backend to do the real work.  */
		   if (! elf32_arm_size_stubs (link_info.output_bfd,
					       stub_file->the_bfd,
					       & link_info,
					       group_size,
					       & elf32_arm_add_stub_section,
					       & arm_layout_sections_again))
		       {
			   einfo ("%X%P: cannot size stub section: %E\n");
			   return;
		       }
	       }
       }



      if (need_laying_out != -1) {
	  // readjust the sections assigned by the vanilla linker ...
	  emultempl_map_segments (TRUE);

      }

      /*  do we need to do it all over again because we added some stubs?  */
      sections_overlap = pic32_sections_overlap();

      if (pic32_allocate && sections_overlap) {

	  // we start by copying the master copy of unassigned sections back over to the working copy so we can start again ...
	  unassigned_sections = pic32_copy_list(unassigned_sections_master_copy);

	  // remove the output sections created by the bfa ...

	  pic32_discard_previous_bfa_allocation();
          //display_output_section_statements("after discard");

	  
	  // resize dinit to account for any ramfunc stubs ...

	  estimate_dinit_optim(&link_info);
	  //fill_dinit_section(&link_info);
	 
 	  
	  // reallocate sections previously allocated by the bfa ..
	  allocate_memory();

	  //display_output_section_statements("after second allocation");
	  
	  	  
      }

      
      sections_overlap = pic32_sections_overlap(); 
      if (sections_overlap)
	  PIC32_DEBUG(" sections still overlap!"); //report link error!
      
      /*
       * try to merge consecutive sections with identical flags
       */
      pic32_merge_sections();
      /*
       * at this point we have a final allocation and we will not try any more reallocation
       */
      lang_reset_memory_regions ();
      lang_size_sections (NULL, ! RELAXATION_ENABLED);

      /*
      ** remove output sections with size = 0
      */
      pic32_strip_sections(link_info.output_bfd);
      
      
      if (pic32_has_fill_option)
	  pic32_create_fill_templates();
}

/*
** Return a pointer to bfd_link_hash_entry
** if a global symbol is defined;
** else return zero.
*/
struct bfd_link_hash_entry *
bfd_pic32_is_defined_global_symbol (name)
     const char *const name;
{
    struct bfd_link_hash_entry *h;
    h = bfd_link_hash_lookup (link_info.hash, name, FALSE, FALSE, TRUE);

    if ((h != (struct bfd_link_hash_entry *) NULL) &&
        (h->type == bfd_link_hash_defined))
      return h;
    else
      return (struct bfd_link_hash_entry *) NULL;
}

static bfd_boolean is_cmse_implib (void)
{
  return (params.cmse_implib == 1);
}


bfd_boolean (*mchp_is_cmse_implib)(void) = is_cmse_implib;

/*
** Create a bfd for the fill templates
**
** Uses the following global variables:
**   symtab
**   symptr
*/
static bfd *
bfd_pic32_create_fill_bfd (bfd *parent ATTRIBUTE_UNUSED)
{
  bfd_size_type size;
  bfd *abfd;
  asection *sec;
  char *oname;
  int flags, sec_align;
  const char *sname;

  /* create a bare-bones bfd */
  oname = (char *) bfd_alloc (link_info.output_bfd, 20);
  sprintf (oname, "fill%d", fill_section_count);
  abfd = bfd_create (oname, parent);
  bfd_find_target (EMULTEMPL.output_format, abfd);
  bfd_make_writable (abfd);

  bfd_set_format (abfd, bfd_object);
  bfd_set_arch_mach (abfd, bfd_arch_arm, 0);

  /* create a symbol table (room for 1 entry) */
  symptr = 0;
  symtab = (asymbol **) bfd_alloc (link_info.output_bfd, 2 * sizeof (asymbol *));

  /*
  ** create a bare-bones section for
  */
  /* get unique section name */
  /* probably not readonly? */
  sname = bfd_get_unique_section_name (abfd, "fill$", &fill_section_count);
  flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP |
          SEC_LINKER_CREATED;
  sec_align = 0; 
  sec = bfd_pic32_create_section (abfd, sname, flags, sec_align);
  size = 0; /* will update later */
  bfd_set_section_size (abfd, sec, size);

  /* put in the symbol table */
  bfd_set_symtab (abfd, symtab, symptr);
  /* finish it */
  if (!bfd_make_readable (abfd))
    {
      fprintf( stderr, "Link Error: can't make fill readable\n");
      abort();
    }
  return abfd;
} /* static bfd * bfd_pic32_create_fill_bfd (...)*/



/*
** Append a section to a list
*/
void
pic32_append_section_to_list (struct pic32_section *lst,
                              asection *sec)
{
  struct pic32_section *s, *tail, *new;

  if (!(lst))
    return;
  /* create a new element */
  new = ((struct pic32_section *)
         xmalloc(sizeof(struct pic32_section)));
  new->next  = 0;
  new->sec  = sec;
  new->pic32_size = sec->size;
  new->attributes = pic32_attribute_map(sec);
  new->file = NULL;
  new->children = NULL;
  new->use_vma = 0;
  new->region = NULL;
  new->dinit_type = -1;

  /* find the tail */
  for (s = lst; s != NULL; s = s->next)
    tail = s;

  tail->next = new;  /* add it */
}

/*
** add up the sizes of a list of pic32_sections
*/
bfd_size_type pic32_add_sizes (struct pic32_section *);


bfd_size_type pic32_add_sizes (struct pic32_section *lst) {

    if (lst == NULL) return 0;
    bfd_size_type total = 0;
    struct pic32_section *s;
    for (s = lst; s != NULL; s = s->next) total+= s->pic32_size;
    return total;
}

/*
** make a copy of a single pic32_section
** the pic32_sections are recreated but we do not copy the bfd sections ...
*/

struct pic32_section * pic32_copy_section (struct pic32_section *src){
    struct pic32_section *new = ((struct pic32_section *)
				 xmalloc(sizeof(struct pic32_section)));
    if (NULL == new) {
	fprintf( stderr, "Fatal Error: Could not build section list\n");
	abort();
    }
    new->sec  = src->sec;
    new->attributes = src->attributes;
    new->file = src->file;
    new->use_vma = src->use_vma;
    new->region = src->region;
    new->pic32_size = src->pic32_size;
    new->children = NULL;
    new->next = NULL;
    if (src->children == NULL)
	return new;
    struct pic32_section *prev = NULL;
    for (struct pic32_section *curr = src->children;
	 curr != NULL;
	 curr = curr->next)
	{
	    struct pic32_section *newchild = pic32_copy_section (curr);
	    if (new->children == NULL)
		new->children = newchild;
	    else
		prev->next = newchild;
	    prev = newchild;
	}
    return new;
}

/*
struct pic32_section * pic32_copy_section (struct pic32_section *src){

    struct pic32_section *new = ((struct pic32_section *)
				 xmalloc(sizeof(struct pic32_section)));
    
    if (NULL == new) {
	fprintf( stderr, "Fatal Error: Could not build section list\n");
	abort();
    }
    new->sec  = src->sec;
    new->attributes = src->attributes;
    new->file = src->file;
    new->use_vma = src->use_vma;
    new->region = src->region;
    new->pic32_size = src->pic32_size;
    if (NULL != src->children)
	new->children = pic32_copy_section(src->children);
    else
	new->children = NULL;
    return new;

}
*/


/*
** make a copy of a list
** the pic32_sections are recreated but we do not copy the bfd sections ...
*/
static struct pic32_section *
pic32_copy_list (struct pic32_section *src_lst)

{
    struct pic32_section *tail, *s, *dest_lst;
    if (NULL ==src_lst)
	return NULL;
    pic32_init_section_list(&dest_lst);
    tail = dest_lst;
    for (s = src_lst; s != NULL; s = s->next){	    
	/* add s to dest_lst*/
	if (NULL != s->sec) {
	    pic32_append_section_to_list(dest_lst, s->sec);
	    /* advance the tail */
            tail = tail->next;	    
	    tail->attributes = s->attributes;
	    tail->file = s->file;
	    tail->use_vma = s->use_vma;
	    tail->region = s->region;	
	    if (s->children != NULL)
		tail->children = pic32_copy_list (s->children);
	    else  tail->children = NULL;
	    // doing this after the recursive call ensures that the children sizes are computed first.
	    
	    tail->pic32_size = (s->sec->rawsize? s->sec->rawsize : s->sec->size)
		+ pic32_add_sizes(s->children);
	}
    }
    return dest_lst;
}




/*
 * See if a section name matches
 * the unique section list. Truncate
 * section names at the % char, which
 * is used to differentiate orphan sections
 * with the same names.
 */ 
bfd_boolean
pic32_unique_section(const char *s)
{
  struct unique_sections *unam;
  const char *us;

  for (unam = unique_section_list; unam; unam = unam->next) {
    us = unam->name;
    while (*us) {
      if (*us++ != *s++) continue;
      if ((*s == '%') || (*s == '0'))  return TRUE;
    }
  }
  return FALSE;
}

/*
** Length of a section list
*/
int
pic32_section_list_length (lst)
     struct pic32_section *lst;
{
  struct pic32_section *s;
  int count = -1; /* first element is null */

  for (s = lst; s != NULL; s = s->next)
      count++;

  return count;

} /* pic32_section_list_length (..) */

/*
** Print a section list
*/
void
pic32_print_section_list_helper (struct pic32_section *, int);

void
pic32_print_section_list_helper (struct pic32_section *lst, int indent) {
  struct pic32_section *s, *prev, *next;
  prev = lst;
  int j;
  for (s = prev; s != NULL; s = next)
    {
      next = s->next;
      for(j=0;j<indent;j++) LOG(" ");
      if (NULL != s->sec) {
	LOG("  name = %s, addr = %x, len = %d, ",s->sec->name,s->sec->lma,s->pic32_size);
	  //	  if (0 == strcmp(s->sec->name,".text_itcm")) {jimmy debug
	  //    if(s->sec->itcm) printf(" bfd_section has itcm ");  
	  
	  if (NULL != s->sec->output_section) {
	    LOG("oss = %d, ossrs = %d, ",s->sec->output_section->size, s->sec->output_section->rawsize);
	  }
	  LOG(" attr = %x vma = %d init = %d ptr = %lx\n", s->attributes, s->use_vma, s->sec->init, (unsigned long) s->sec);
      }
      else 
	LOG("  N/A \n");
      prev = s;
      if (NULL != s->children) pic32_print_section_list_helper(s->children, indent+4);
    }
}


void
pic32_print_section_list (lst, name)
     struct pic32_section *lst;
      const char *name;
{
  LOG("Contents of %s section list at %p:\n", name, lst);
  pic32_print_section_list_helper(lst,0);

  LOG("\n");

} /* pic32_print_section_list (..) */





/*
** Add a node to a memory list
**  in order of increasing size
*/
void
pic32_add_to_memory_list (lst, addr, size)
     struct pic32_memory *lst;
     bfd_vma addr, size;
{
  struct pic32_memory *new, *b, *prev;
  int done = 0;

  /* create a new element */
  new = ((struct pic32_memory *)
         xmalloc(sizeof(struct pic32_memory)));
  new->addr  = addr;
  new->size  = size;
  new->offset = 0;

  /* insert it at the right spot */
  prev = lst;
  for (b = prev; b != NULL; b = b->next)
    {
      if (new->size < b->size)
        {
          prev->next = new;
          new->next = b;
          done++;
          break;
        }
      prev = b;
    }

  if (!done)
    {
      prev->next = new;
      new->next = NULL;
    }
} /* static void pic32_add_to_memory_list (..) */

/*
** Remove an element from a section list
*/
void
pic32_remove_from_section_list (lst, sec)
     struct pic32_section *lst;
     struct pic32_section *sec;
{
  struct pic32_section *s, *prev, *next;
  int done = 0;

  prev = lst;
  for (s = prev; s != NULL; s = next)
    {
      next = s->next;
      if (s == sec)
        {
          prev->next = next;
          free(s);
          done = 1;
          break;
        }
      prev = s;
    }

  /*
   * If we didn't find it, search for element->section.
   * This enables us to remove an element that was
   * identified from another list.
   *
   * Example: Remove a member of "unassigned sections"
   * that was identified from an allocation list.
   */
  if (!done)
    {
      prev = lst;
      for (s = prev; s != NULL; s = next)
        {
          next = s->next;
          if (s->sec == sec->sec)
            {
              prev->next = next;
              free(s);
              done = 1;
              break;
            }
          prev = s;
        }
    }

  if (done == 0)
    PIC32_DEBUG("    !Could not remove section \"%s\" from list at %lx",
		sec->sec->name, (long unsigned int) &lst);

} /* pic32_remove_from_section_list (..) */


/*
** Remove a group from a section list
**
** Sections in a group are related by name.
** We can't delete them, so we clear the
** attributes field so they won't match
** any more allocation stages.
*/
void
pic32_remove_group_from_section_list (lst)
     struct pic32_section *lst;
{
  struct pic32_section *s, *prev, *next;

  prev = lst;
  for (s = prev; s != NULL; s = next)
    {
      next = s->next;
      if (s->sec && (PIC32_IS_RAMFUNC_ATTR(s->sec))) {
          s->attributes = 0;
        }
      prev = s;
    }
} /* pic32_remove_group_from_section_list() */


/*
** Remove a group from a section list
**
** Sections in a group are related by name.
** We can't delete them, so we clear the
** attributes field so they won't match
** any more allocation stages.
*/
#ifdef ENABLE_COHERENT
static void
pic32_remove_coherent_group_from_section_list (lst, mask)
    struct pic32_section *lst;
    unsigned int mask;
{
    struct pic32_section *s, *prev, *next;

    prev = lst;

    for (s = prev; s != NULL; s = next)
    {
        next = s->next;

        if ( s->sec &&
            (PIC32_IS_COHERENT_ATTR(s->sec)) &&
            ((s->attributes & mask) == mask)
        )
        {
            s->attributes = 0;
        }
        prev = s;
    }
} /* pic32_remove_coherent_group_from_section_list() */
#endif

/*
** Find a suitable free block - static
**
** This function scans the free memory list
** looking for a buffer that will accomodate
** a static section (fixed address).
**
** If a suitable block is found, fill in the
** offset field to reflect the section starting
** address and return the block.
**
** If a suitable block can not be found, return NULL.
*/
struct pic32_memory *
pic32_static_assign_memory (lst, size, sec_address)
     struct pic32_memory *lst;
     bfd_vma size, sec_address;
{
  struct pic32_memory *b, *prev;
  bfd_vma offset;

  prev = lst;
  for (b = prev; b != NULL; b = b->next)
    {
      if ((b->size < size) || (b->addr > sec_address))
        continue;

      offset = sec_address - b->addr;
      if (b->size >= (offset + size))
        {
          b->offset = offset;
          return b;
        }
    }

  /*
  ** if we get here, a suitable block could not be found
  */
  return (struct pic32_memory *) NULL;
} /* static struct pic32_memory * pic32_static_assign_memory (...) */

/*
** Remove a block from a memory list
*/
void
pic32_remove_from_memory_list (lst, block)
     struct pic32_memory *lst;
     struct pic32_memory *block;
{
  struct pic32_memory *b, *prev, *next;

  prev = lst;
  for (b = prev; b != NULL; b = next)
    {
      next = b->next;
      if (b == block)
        {
          prev->next = next;
          free(b);
          break;
        }
      prev = b;
    }

} /* static void pic32_remove_from_memory_list(..) */

/*
** Free a memory list
*/
void
pic32_free_memory_list(lst)
     struct pic32_memory **lst;
{
  struct pic32_memory *s, *next;

  if (lst == NULL) return;
  if (*lst == NULL)return;

  for (s = *lst; s != NULL; s = next)
    {
      next = s->next;
      free(s);
    }

  *lst = NULL;
} /* static void pic32_free_memory_list (...) */

/*
** Create a list of free memory blocks
**
** - first item is null
*/
void
pic32_init_memory_list(lst)
     struct pic32_memory **lst;
{
  *lst = ((struct pic32_memory *)
         xmalloc(sizeof(struct pic32_memory)));
  (*lst)->next = 0;
  (*lst)->addr = 0;
  (*lst)->size = 0;
  (*lst)->offset = 0;
}

/*
** Add a new bfd to the link
*/
static void
bfd_pic32_add_bfd_to_link (abfd, name)
     bfd *abfd;
     const char *name;
{
  lang_input_statement_type *fake_file;
  fake_file = lang_add_input_file (name,
                                   lang_input_file_is_fake_enum,
                                   NULL);
  fake_file->the_bfd = abfd;
  ldlang_add_file (fake_file);
  if (! bfd_link_add_symbols (abfd, &link_info))
    einfo (_("%F%B: could not add symbols: %E\n"), abfd);

  return;
} /* static void bfd_pic32_add_bfd_to_link (...)*/

/*
** Create a new section
*/
asection *
bfd_pic32_create_section (abfd, name, flags, align)
     bfd *abfd;
     const char *name;
     int flags;
     int align;
{
  asection *sec;
  asymbol *sym;

  PIC32_DEBUG("Creating input section \"%s\"", name);

  /* do NOT call bfd_make_section_old_way(), its buggy! */
  sec = bfd_make_section_anyway (abfd, name);
  bfd_set_section_flags (abfd, sec, flags | SEC_ALLOC | SEC_KEEP | SEC_LINKER_CREATED);
  bfd_set_section_alignment (abfd, sec, align);
  /* Set the gc mark to prevent the section from being removed by garbage
     collection, despite the fact that no relocs refer to this section.  */
  sec->gc_mark = 1;
  sec->output_section = sec;

  /* add a symbol for the section name */
  sym = bfd_make_empty_symbol (abfd);
  symtab[symptr++] = sym;
  sym->name = sec->name;
  sym->section = sec;
  sym->flags = BSF_LOCAL;
  sym->value = 0;

  return sec;
} /* static asection * bfd_pic32_create_section (...)*/

/*
** Strip zero-length sections
*/
static void
pic32_strip_sections (abfd)
     bfd *abfd;
{
  asection *sec, *prev;

  PIC32_DEBUG("Looking for zero-length sections:");

  sec = abfd->sections;
  if ((sec == NULL) || (sec->next == NULL))
    return;

  sec = sec->next; /* never strip the first section */
  /* loop through the sections in this bfd */
  for (; sec != NULL; sec = sec->next)
    {
    if (sec->flags & (SEC_KEEP | SEC_LINKER_CREATED))
        continue;
    /* remove sections with size = 0 */
      if (sec->size == 0)
      {
        prev = sec->prev;
        prev->next = sec->next;
        if (sec->next)
          sec->next->prev = prev; 
        else
          abfd->section_last = prev; /*update the bfd->section_last field
                                       if the removed section is the 
                                       last section.*/
        abfd->section_count -= 1;
        PIC32_DEBUG("  Stripping section %s", sec->name);
      }
    }
  return;
} /* static void pic32_strip_sections (...)*/


void pic32_merge_sections() {

}


/* anything here may depend on stuff in pic32c-allocate.c. that's just how it is.
   TODO: Maybe not any more.
 */

/* pic32_init_alloc()
 * perform initialization steps for the allocator. this should be called 
 * in ldlang before any BFA-related work is done to identify the 
 * memory configuration. */
void
pic32_init_alloc(void) {

    
  pic32_allocate = pic32_allocate && pic32_init_region_info(&region_info);

  /* XC32E-661: bypass anything dinit-related when called with "-r".
     The lto-wrapper will call us with "-r" to extract some debug info only. */
  if (bfd_link_relocatable (&link_info))
    pic32_data_init = FALSE;
}

void
bfd_pic32_finish (void)
{
  struct bfd_link_hash_entry *h;
  asection *stack_sec = NULL;
  lang_output_section_statement_type *os;

  /* if we've encountered a fatal error, stop here */
  if (config.make_executable == FALSE)
    einfo ("%P%F: Link terminated due to previous error(s).\n");

  /* check for _min_stack_size symbol -- this is an old way to specify
     a stack, and is really not preferred */
  if ((h = bfd_pic32_is_defined_global_symbol ("_min_stack_size")))
    {
      if (pic32_has_stack_option && (h->u.def.value != pic32c_stack_size))
	fprintf (stderr,
		 "Warning: --stack option overrides _min_stack_size symbol\n");
      else
	pic32c_stack_size = h->u.def.value;
    }

  /* if heap is required, make sure one is specified */
  if (pic32_heap_required && !heap_section_defined && !pic32_has_heap_option
      && !bfd_pic32_is_defined_global_symbol ("_min_heap_size"))
    einfo ("%P%X Error: A heap is required, but has not been specified\n");

  /* check for _min_stack_size symbol -- this is an old way to specify
     a stack, and is really not preferred */
  if ((h = bfd_pic32_is_defined_global_symbol ("_min_heap_size")))
    {
      if (pic32_has_heap_option && (h->u.def.value != pic32c_heap_size))
	fprintf (stderr,
		 "Warning: --heap option overrides _min_heap_size symbol\n");
      else
	pic32c_heap_size = h->u.def.value;
    }

  /*
  ** Check for user-defined stack
  **
  ** note: symbol (_stack) must be defined
  */
  if ((h = bfd_pic32_is_defined_global_symbol ("_stack")))
    {
      user_defined_stack = TRUE;
      stack_base = h->u.def.value;
      /* if defined value is relative, add in the section base address */
      if (h->u.def.section && (h->u.def.section != bfd_abs_section_ptr))
	stack_base += h->u.def.section->vma;
    }
  else
    user_defined_stack = FALSE;

  /* If a stack was not defined as a section, or by symbols,
     allocate one from remaining memory */
  if (!user_defined_stack && pic32_allocate)
    {
      allocate_default_stack (region_info.data);

      /*
      ** Set stack symbols for the runtime library
      */
      PIC32_DEBUG("Creating _heap = %x", heap_base);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_heap", BSF_GLOBAL,
					bfd_abs_section_ptr, heap_base, "_heap",
					1, 0, 0);
      PIC32_DEBUG("Creating _eheap = %x", heap_limit);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_eheap", BSF_GLOBAL,
					bfd_abs_section_ptr, heap_limit,
					"_eheap", 1, 0, 0);

      PIC32_DEBUG("Creating _splim = %x", stack_base);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_splim", BSF_GLOBAL,
					bfd_abs_section_ptr, stack_base,
					"_splim", 1, 0, 0);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_SPLIM", BSF_GLOBAL,
					bfd_abs_section_ptr, stack_base,
					"_SPLIM", 1, 0, 0);

      stack_sec = bfd_get_section_by_name (stack_bfd, ".stack");
      if (stack_sec)
	{
	  etree_type *addr_tree;
	  os = lang_output_section_statement_lookup (".stack", 0, TRUE);
	  stack_sec->size = pic32c_stack_size;
	  if (os->bfd_section != NULL)
	    {
	      bfd_set_section_size (stack_bfd, stack_sec, pic32c_stack_size);
	      bfd_set_section_vma (stack_bfd, stack_sec, stack_base);
	      os->bfd_section->vma = stack_sec->vma;
	      os->bfd_section->lma = stack_sec->lma;
	      os->bfd_section->size = stack_sec->size;
	      stack_sec->flags |= SEC_LINKER_CREATED;
	      os->bfd_section->flags = stack_sec->flags;
	      addr_tree = xmalloc (sizeof (etree_type));
	      addr_tree->value.type.node_class = etree_value;
	      addr_tree->value.value = stack_sec->vma;
	      os->addr_tree = addr_tree;
	      PIC32_DEBUG("Creating _stack = %x", stack_limit);
	      _bfd_generic_link_add_one_symbol (&link_info, stack_sec->owner,
						"_stack", BSF_GLOBAL,
						bfd_abs_section_ptr,
						stack_limit, "_stack", 1, 0, 0);
	    }
	  else
	    fprintf (stderr, "Link Error: Unable to allocate stack\n");
	}
    }

  /* was there a PROVIDE in the linker script to give an alternate name for
   * _stack and _splim? */
  /* see ldexp.c for details */
  if (altNameforStack != NULL)
    {
      PIC32_DEBUG("Creating symbol %s equivalent to _stack",
		  altNameforStack);

      /* MERGE_NOTES: possibly uninitialized stack_sec here. */
      BFD_ASSERT (stack_sec);
      _bfd_generic_link_add_one_symbol (&link_info, stack_sec->owner,
					altNameforStack, BSF_GLOBAL,
					bfd_abs_section_ptr, stack_limit,
					altNameforStack, 1, 0, 0);
      free (altNameforStack);
    }
  if (altNameforSplim != NULL)
    {

      PIC32_DEBUG("Creating symbol %s equivalent to _splim",
		  altNameforSplim);

      /* MERGE_NOTES: possibly uninitialized stack_sec here. */
      BFD_ASSERT (stack_sec);
      _bfd_generic_link_add_one_symbol (&link_info, stack_sec->owner,
					altNameforSplim, BSF_GLOBAL,
					bfd_abs_section_ptr, stack_base,
					altNameforSplim, 1, 0, 0);
      free (altNameforSplim);
    }

  /* if we don't understand the stack, we shouldn't check it. */
  if (stack_limit && stack_base)
    {

      /* Range check the stack, no matter how it was created */
      if ((unsigned int) (stack_limit - stack_base)
	  < (unsigned int) pic32c_stack_size)
	{
	  einfo ("%P%X Error: Not enough memory for stack"
		 " (%u bytes needed, %u bytes available)\n",
		 (unsigned int) (pic32c_stack_size + pic32c_stackguard_size),
		 (unsigned int) ((stack_limit - stack_base)
				 + pic32c_stackguard_size));
	}

      PIC32_DEBUG("Creating __MIN_STACK_SIZE = %x", pic32c_stack_size);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"__MIN_STACK_SIZE", BSF_GLOBAL,
					bfd_abs_section_ptr, pic32c_stack_size,
					"__MIN_STACK_SIZE", 1, 0, 0);
      PIC32_DEBUG("Creating _min_stack_size = %x", pic32c_stack_size);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_min_stack_size", BSF_GLOBAL,
					bfd_abs_section_ptr, pic32c_stack_size,
					"_min_stack_size", 1, 0, 0);

      PIC32_DEBUG("Creating __MIN_HEAP_SIZE = %x", pic32c_heap_size);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"__MIN_HEAP_SIZE", BSF_GLOBAL,
					bfd_abs_section_ptr, pic32c_heap_size,
					"__MIN_HEAP_SIZE", 1, 0, 0);
      PIC32_DEBUG("Creating _min_heap_size = %x", pic32c_heap_size);
      _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					"_min_heap_size", BSF_GLOBAL,
					bfd_abs_section_ptr, pic32c_heap_size,
					"_min_heap_size", 1, 0, 0);
    }

  /*
   * check if stack should be moved in tcm, if yes, generate the tcm stack
   * symbol
   */
  if (pic32c_stack_in_tcm)
    {
      PIC32_DEBUG("Creating _sdtcm_stack");

      if (pic32_valid_region (region_info.data_tcm))
	{
	  ///\ generate _sdtcm_stack
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_sdtcm_stack", BSF_GLOBAL,
					    bfd_abs_section_ptr,
					    dtcm_stack_limit, "_sdtcm_stack", 1,
					    0, 0);
	  // generate _sdtcm_splim
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_sdtcm_splim", BSF_GLOBAL,
					    bfd_abs_section_ptr,
					    dtcm_stack_base, "_sdtcm_splim", 1,
					    0, 0);
	}
      ///\ emit symbols with abs address 0
      else
	{
	  // DZ - is this guaranteed to work if there is no DTCM region? or
	  // should it be an error?
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_sdtcm_stack", BSF_GLOBAL,
					    bfd_abs_section_ptr, 0x0,
					    "_sdtcm_stack", 1, 0, 0);
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_sdtcm_splim", BSF_GLOBAL,
					    bfd_abs_section_ptr, 0x0,
					    "_sdtcm_splim", 1, 0, 0);
	}

      /* was there a PROVIDE in the linker script to give an alternate name for
       * _sdtcm_stack and _sdtcm_splim? */
      /* see ldexp.c for details (and just above ...) */
      if (altNamefor_dtcm_Stack != NULL)
	{

	  PIC32_DEBUG("Creating symbol %s equivalent to _sdtcm_stack",
		      altNamefor_dtcm_Stack);
	  _bfd_generic_link_add_one_symbol (&link_info, stack_sec->owner,
					    altNamefor_dtcm_Stack, BSF_GLOBAL,
					    bfd_abs_section_ptr,
					    dtcm_stack_limit,
					    altNamefor_dtcm_Stack, 1, 0, 0);
	  free (altNamefor_dtcm_Stack);
	}
      if (altNamefor_dtcm_Splim != NULL)
	{

	  PIC32_DEBUG("Creating symbol %s equivalent to _sdtcm_splim",
		      altNamefor_dtcm_Splim);
	  _bfd_generic_link_add_one_symbol (&link_info, stack_sec->owner,
					    altNamefor_dtcm_Splim, BSF_GLOBAL,
					    bfd_abs_section_ptr,
					    dtcm_stack_base,
					    altNamefor_dtcm_Splim, 1, 0, 0);
	  free (altNamefor_dtcm_Splim);
	}
    }

  /*
  ** Set _dinit_addr symbol for data init template
  **   so the C startup module can find it.
  */

  if (pic32_data_init)
    {
      asection *sec;
      sec = init_template->output_section; /* find the template's output sec */

      if (sec)
	{
	  bfd_vma dinit_addr = sec->lma + init_template->output_offset;
	  unsigned int dinit_addr_masked = dinit_addr & 0xFFFFFFFFul;

	  PIC32_DEBUG("Creating _dinit_addr= %x", dinit_addr_masked);
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_dinit_addr", BSF_GLOBAL,
					    bfd_abs_section_ptr,
					    dinit_addr_masked, "_dinit_addr", 1,
					    0, 0);
	  PIC32_DEBUG("Creating _dinit_size= %x", dinit_size);
	  _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
					    "_dinit_size", BSF_GLOBAL,
					    bfd_abs_section_ptr, dinit_size,
					    "_dinit_size", 1, 0, 0);
	}
    }
}

/*
** This routine is called by before_allocation().
**
** Scan a DATA or BSS section and accumulate
** the data template size.
**
** This function must be consistent with bfd_pic32_process_data_section
** in bfd/elf32-pic32c.c, or the size of the dinit template will
** be incorrect.
*/
static void
bfd_pic32_scan_data_section (section, p)
     struct pic32_section *section;
     PTR p;
{
  int *data_size = (int *) p;
  asection *sect = section->sec;

  if (p == (int *) NULL)
    return;

  /* this is only called for sections to be placed in ram/dtcm. we judiciously
     check the data/data_tcm region as appropriate to determine if initialization
     is needed.
     Now this check is done before region info is availible, which involves
     checking section flags.
  */
  if (sect->dtcm)
    {
      BFD_ASSERT(region_info.data_tcm);
      if (!region_info.data_tcm->flags.init_needed)
        {
	  PIC32_DEBUG("  %s (skipped, init_needed = 0), size = %x bytes",
		      sect->name, (unsigned int)sect->size);
          return;
        }
    }
  else
    {
      if (pic32_valid_region(region_info.data) &&
          !region_info.data->flags.init_needed)
        {
	  PIC32_DEBUG("  %s (skipped, init_needed = 0), size = %x bytes",
		      sect->name, (unsigned int)sect->size);
          return;
        }
  }

  /*
  ** skip persistent or noload data sections
  */
  if (PIC32_IS_PERSIST_ATTR(sect) || PIC32_IS_NOLOAD_ATTR(sect))
  {
      /*
      ** issue a warning if DATA values are present
      */
      if ((sect->flags & SEC_DATA) && (sect->size > 0))
        einfo(_("%P: Warning: initial values were specified for a non-loadable"
                " data section (%s). These values will be ignored.\n"),
              sect->name);

      PIC32_DEBUG("scan_data_section %s (skipped, persist/noload), size = %x bytes",
		  sect->name, (unsigned int) sect->size);
      return;
  }

  /*
  ** process BSS-type sections
  */
  if ((PIC32_SECTION_IS_BSS_TYPE(sect) || PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR(sect)) &&
      (sect->size > 0))
  {
        *data_size += DATA_RECORD_HEADER_SIZE;
        sect->init = 1;
        PIC32_DEBUG("scan_data_section %s (bss), size = %x bytes, template += %x bytes",
		    sect->name, (unsigned int) sect->size,
		    DATA_RECORD_HEADER_SIZE);
  }

  /*
  ** process DATA-type sections
  */
  if ((PIC32_IS_DATA_ATTR (sect) || PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR (sect)
       || PIC32_IS_RAMFUNC_ATTR (sect))
      && (sect->size > 0))
    {
      /* account for 0-padding so that new dinit records always start at a
      ** new memory location
      */
      int count
	= (sect->size % 4) ? (sect->size + (4 - sect->size % 4)) : sect->size;
      int delta = DATA_RECORD_HEADER_SIZE + count;
      *data_size += delta;

      /*
      ** make section not LOADable
      */
      sect->flags &= ~SEC_LOAD;
      sect->init = 1;

      PIC32_DEBUG("scan_data_section %s (data), size = 0x%x bytes, template += 0x%x "
		  "bytes\n",
		  sect->name, (unsigned int) sect->size, delta);
    }

} /*static void bfd_pic32_scan_data_section (...)*/

/*
** This routine is called by bfd_pic32_create_data_init_template().
**
** Scan a CODE  sections and accumulate
** the data template size, setting the init flag for things that will
** require initialization.
*/
static void
bfd_pic32_scan_code_section (section, p)
     struct pic32_section *section;
     PTR p;
{
  int *data_size = (int *) p;
  asection *sect = section->sec;

  if (p == (int *) NULL)
    return;

  /* this is only called for TCM code sections assuming they require
     initialization in itcm.. */
  BFD_ASSERT (sect->itcm);
  BFD_ASSERT (region_info.code_tcm);

  if (!region_info.code_tcm->flags.init_needed)
    {
      PIC32_DEBUG("  %s (skipped, init_needed = 0), size = %x bytes",
		  sect->name, (unsigned int) sect->size);
      return;
    }
    
  /*
  ** process CODE-type sections
  */
  if (PIC32_IS_CODE_ATTR(sect) && (sect->size > 0))
  { 
    /* Analyze initialization data now and find out what the after compression
       size of the data initialization template */
    /* account for 0-padding so that new dinit records always start at a
    ** new memory location
    */
    int count = (sect->size % 4) ? (sect->size + (4 - sect->size % 4)) \
                                 : sect->size;
    int delta = DATA_RECORD_HEADER_SIZE + count;
    *data_size += delta;

    /*
    ** make section not LOADable
    */
    sect->flags &= ~SEC_LOAD;

    /* mark for dinit template addition */
    sect->init = 1;

    PIC32_DEBUG("  %s (data), size = %x bytes, template += %x bytes",
		sect->name, (unsigned int) sect->size, delta);
  }
} /*static void bfd_pic32_scan_code_section (...)*/


/*
** Create a bfd for the data init template
**
** Uses the following global variables:
**   symtab
**   symptr
*/
bfd *
bfd_pic32_create_data_init_bfd (parent)
     bfd *parent;
{
  bfd_size_type size;
  bfd *abfd;
  asection *sec;
  char *oname;
  int flags, alignment;

  /* create a bare-bones bfd */
  oname = (char *) bfd_alloc (link_info.output_bfd, 20);
  snprintf (oname, 20, "data_init");
  abfd = bfd_create (oname, parent);
  bfd_find_target (EMULTEMPL.output_format, abfd);
  bfd_make_writable (abfd);

  bfd_set_format (abfd, bfd_object);
  bfd_set_arch_mach (abfd, bfd_arch_arm, 0);
  elf_elfheader(abfd)->e_flags |= EF_ARM_EABI_VER5; /* TODO: Find a better way */

  /* create a symbol table (room for 1 entry) */
  symptr = 0;
  symtab = (asymbol **) bfd_alloc (link_info.output_bfd, 2 * sizeof (asymbol *));

  /*
  ** create a bare-bones section for .dinit
  */
  flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP |
          SEC_LINKER_CREATED | SEC_ALLOC | SEC_READONLY;
  alignment = 2; /* 2^2 */
  sec = bfd_pic32_create_section (abfd, ".dinit", flags, alignment);
  size = 0; /* will update later */
  bfd_set_section_size (abfd, sec, size);

  /* put in the symbol table */
  bfd_set_symtab (abfd, symtab, symptr);

  /* will add section contents later */

  /* finish it */
  if (!bfd_make_readable (abfd))
    {
      fprintf( stderr, "Link Error: can't make data init readable\n");
      abort();
    }

  return abfd;
} /* static bfd * bfd_pic32_create_data_init_bfd (...)*/


void pic32_create_fill_templates(void)
{
  struct pic32_fill_option *o;
  if (region_info.code->free_blocks)
    {
      if (pic32_fill_option_list)
        {
         for (o = pic32_fill_option_list; o != NULL; o = o->next)
            {
              if (o == pic32_fill_option_list)
                continue;

              if (o->loc.unused)
                pic32_create_unused_program_sections(o);
            }

        }
     }
   else
     einfo(_("%P: Warning: There is not any free program memory to fill.\n"));
}

static void pic32_create_unused_program_sections
                      (struct pic32_fill_option *opt)
{
  asection * sec;
  struct pic32_memory *b, *next;
  bfd *fill_bfd;
  unsigned char *fill_data;
  struct pic32_section *s;
  bfd_vma size = 0;
  bfd_vma addr = 0;
  int sec_align = 2;

  for (b = region_info.code->free_blocks; b != NULL; b = next)
    {
     next = b->next;
     if ((b->addr == 0) && (b->size == 0))
      continue;
     fill_bfd = bfd_pic32_create_fill_bfd(link_info.output_bfd);
     bfd_pic32_add_bfd_to_link (fill_bfd, fill_bfd->filename);
     
     addr = align_power(b->addr, sec_align); /*align to an instruction word*/
     size = b->size - (addr - b->addr);
    

     fill_bfd->sections->vma = fill_bfd->sections->lma = addr;
     fill_bfd->sections->rawsize = size;
     fill_bfd->sections->size = size;

       /* create a pic32_section */
     pic32_init_section_list(&s);
     s->sec = fill_bfd->sections;
     LANG_FOR_EACH_INPUT_STATEMENT (file)
      {
       if (strcmp(file->filename, fill_bfd->filename) == 0)
        s->file = (PTR) file;
      }
       /* allocate memory for the template */
     fill_data = (unsigned char *) bfd_alloc (link_info.output_bfd, size);
     if (!fill_data)
      {
       fprintf( stderr, "Link Error: not enough memory for fill template\n");
       abort();
      }

       /* fill the template with a default value */
     fill_data = memset(fill_data, 0x11, size);

       /* attach it to the input section */
     sec = bfd_get_section_by_name(fill_bfd, fill_bfd->sections->name);
     if (sec)
      {
       sec->rawsize = size;
       sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE);
       sec->contents = fill_data;
       bfd_set_section_alignment(fill_bfd, sec, sec_align); /*align to an insn word*/
       bfd_set_section_size (fill_bfd, sec, size);
       fill_bfd->sections = sec;  /* save a copy for later */
      }
     else {
       PIC32_DEBUG("after_open: section %s not found", sec->name);
     }

     ///\ LG to change looking for execute flag!!!
     // DZ - use identified code region instead
     update_section_info(addr, s, region_info.code);

     pic32_append_section_to_list(opt->fill_section_list, sec);
     pic32_remove_from_memory_list(region_info.code->free_blocks, b);
   }
}

void
pic32_create_specific_fill_sections (void)
{
  asection *sec;
  bfd *fill_bfd;
  unsigned char *fill_data;
  bfd_vma size;
  struct pic32_fill_option *o;

  for (o = pic32_fill_option_list->next; o != NULL; o = o->next)
    {
      if (o->loc.unused)
	continue;

      if (o->loc.end_address)
	size = (o->loc.end_address - o->loc.address) + 1;
      else if (o->fill_width == 1)
	size = 1;
      else if (o->fill_width == 2)
	size = 2;
      else if (o->fill_width == 8)
	size = 8;
      else
	size = 4;

      fill_bfd = bfd_pic32_create_fill_bfd (link_info.output_bfd);
      bfd_pic32_add_bfd_to_link (fill_bfd, fill_bfd->filename);

      fill_bfd->sections->vma = fill_bfd->sections->lma = o->loc.address;
      fill_bfd->sections->rawsize = size;
      fill_bfd->sections->size = size;

      /* allocate memory for the template */
      fill_data = (unsigned char *) bfd_alloc (link_info.output_bfd, size);
      if (!fill_data)
	{
	  fprintf (stderr, "Link Error: not enough memory for fill template\n");
	  abort ();
	}

      /* fill the template with a default value */
      fill_data = memset (fill_data, 0x11, size);

      /* attach it to the input section */
      sec = bfd_get_section_by_name (fill_bfd, fill_bfd->sections->name);
      if (sec)
	{
	  sec->rawsize = size;
	  sec->flags
	    |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE);
	  PIC32_SET_ABSOLUTE_ATTR (sec);
	  sec->contents = fill_data;
	  bfd_set_section_size (fill_bfd, sec, size);
	  fill_bfd->sections = sec; /* save a copy for later */
	}
      else
	{
	  PIC32_DEBUG("after_open: section %s not found", sec->name);
	}

      pic32_append_section_to_list (o->fill_section_list, sec);
    }
}

/******************************************
* STACK USAGE ESTIMATION                  *
*******************************************/


/*
* Stack Usage Estimation
* 	check if r_type corresponds to a call semantic
*/
bfd_boolean is_call_reloc(unsigned int r_type)
{
  switch (r_type)
    {
      case R_ARM_CALL:
      case R_ARM_THM_CALL:
      case R_ARM_JUMP24:
      case R_ARM_THM_JUMP19:
      case R_ARM_THM_XPC22:
      case R_ARM_THM_JUMP24:
      case R_ARM_PLT32:
      case R_ARM_TLS_CALL:
      case R_ARM_THM_TLS_CALL:
      /* -mlong-calls and -fpic relocations */
      case R_ARM_ABS32:
      case R_ARM_MOVT_ABS:
      case R_ARM_THM_MOVT_ABS:
      case R_ARM_REL32:
      case R_ARM_MOVT_PREL:
      case R_ARM_THM_MOVT_PREL:
        return TRUE;

      default:
        return FALSE;
    }
}

int32_t
pic32_su_rel_addend (bfd               *abfd,
                     asection          *section,
                     Elf_Internal_Rela *irela,
                     Elf_Internal_Sym  *isym __attribute__((unused)))
{
  int32_t word;
  bfd_boolean rc;

  switch (ELF32_R_TYPE (irela->r_info)) {
    case R_ARM_ABS32:
    case R_ARM_REL32:
      rc = bfd_get_section_contents (abfd, section, &word, irela->r_offset, 4);
      BFD_ASSERT (rc);
      return word;

    default:
      return 0;
  }
}

struct su_section* pic32_su_call_graph_get_create (bfd *abfd, const char *fname);

void pic32_su_add_to_call_graph (bfd *caller_bfd, const char *caller_name, bfd_vma caller_addr,
                            bfd *callee_bfd, const char *callee_name, bfd_vma callee_addr);

static Elf_Internal_Sym *
pic32_su_lookup_callee (vec_type *func_syms,
                        bfd_vma  target_vma)
{
  int in_callee = FALSE;
  int callee_idx = pic32_su_lookup_func (func_syms, 0, target_vma, &in_callee);
  bfd_vma min_d_vma;

  /* if none of the function symbols contains the address, bail out */
  if (!in_callee)
    return NULL;

  /* otherwise, try to see if we can have a better match (from the callee
   * determining perspective) than the first symbol;
   * more precisely, see if one the following symbols starts closer to
   * (ideally exactly at) 'target_vma';
   * NOTE: this is a heuristic added to cater for situations like the
   * following (not normally produced by the compiler but that can appear
   * in hand-written assembly):

    00000000 <__gedf2>:
      0:	f04f 3cff 	mov.w	ip, #4294967295	; 0xffffffff
      4:	e006      	b.n	14 <__cmpdf2+0x4>
      6:	bf00      	nop

    00000008 <__ledf2>:
      8:	f04f 0c01 	mov.w	ip, #1
      c:	e002      	b.n	14 <__cmpdf2+0x4>
      e:	bf00      	nop

    00000010 <__cmpdf2>:
      10:	f04f 0c01 	mov.w	ip, #1
      14:	f84d cd04 	str.w	ip, [sp, #-4]!
      18:	ea4f 0c41 	mov.w	ip, r1, lsl #1
      ...
  */
  min_d_vma = target_vma
                - ST_VALUE2 (VEC (Elf_Internal_Sym *, func_syms, callee_idx));
  if (min_d_vma)
    {
      int idx;
      for (idx = callee_idx + 1; idx != (int) VEC_SIZE (func_syms); ++idx)
        {
          Elf_Internal_Sym *isym = VEC (Elf_Internal_Sym*, func_syms, idx);
          bfd_vma d_vma = target_vma - ST_VALUE2 (isym);

          /* have we exceed the range of possible matches? */
          if ((bfd_signed_vma) d_vma < 0)
            break;

          /* a better match? */
          if (d_vma <= isym->st_size && d_vma < min_d_vma)
            {
              callee_idx = idx;
              min_d_vma = d_vma;

              /* exact even? then stop */
              if (!min_d_vma)
                break;
            }
        }
    }

  return VEC (Elf_Internal_Sym *, func_syms, callee_idx);
}

/* extracts N bits from the 32-bit X value at the S bit position */
static inline uint32_t
ext_bits_32 (uint32_t x, uint8_t s, uint8_t n)
{
  const uint32_t mask = (1U << n) - 1;
  return (x >> s) & mask;
}

/* inserts N BITS into the 32-bit X value at the S bit position */
static inline uint32_t
ins_bits_32 (uint32_t x, uint8_t s, uint8_t n, uint32_t bits)
{
  const uint32_t mask = ((1U << n) - 1) << s;
  return (x & ~mask) | ((bits << s) & mask);
}

/* returns the 32-bit immediate value encoded in the Thumb B.N (uncond) insn */
static int32_t
thumb_branch_imm32 (uint32_t bits)
{
  const uint32_t imm11 = ext_bits_32 (bits, 0, 11);

  /* sign-extend the lower 11 bits and multiply by 2 */
  return (int32_t) imm11 << 21 >> 20;
}

/* returns the 32-bit immediate value encoded in the Thumb BL/B.W (uncond) insns */
static int32_t
thumb2_branch_imm32 (uint32_t bits)
{
  const uint32_t imm11 = ext_bits_32 (bits, 0, 11);
  const uint32_t imm10 = ext_bits_32 (bits, 16, 10);
  const uint32_t J1    = ext_bits_32 (bits, 13, 1);
  const uint32_t J2    = ext_bits_32 (bits, 11, 1);
  const uint32_t S     = ext_bits_32 (bits, 26, 1);
  const uint32_t I1    = J1 ^ S ^ 1;
  const uint32_t I2    = J2 ^ S ^ 1;
  const uint32_t tmp   = imm11 | (imm10 << 11) | (I2 << 21) | (I1 << 22)
                           | (S << 23);

  /* sign-extend the 24 bits and multiply by 2 */
  return (int32_t) tmp << 8 >> 7;
}

/* returns the 32-bit immediate value encoded in the ARM B/BL insns */
static int32_t
arm_branch_imm32 (uint32_t bits)
{
  const uint32_t imm24 = ext_bits_32 (bits, 0, 24);

  /* sign-extend the lower 24 bits and multiply by 4 */
  return (int32_t) imm24 << 8 >> 6;
}

/* returns the 32-bit immediate value encoded in the ARM BLX(immediate) insn */
static int32_t
arm_branchx_imm32 (uint32_t bits)
{
  const uint32_t imm24 = ext_bits_32 (bits, 0, 24);
  const uint32_t H     = ext_bits_32 (bits, 24, 1);
  const uint32_t tmp   = H | (imm24 << 1);

  /* sign-extend the 25 bits and multiply by 2 */
  return (int32_t) tmp << 7 >> 6;
}

/*
 * Looks for call/jump instructions without relocations in the specified
 * code range (ARM or Thumb) and updates the call graph accordingly.
 */
static void
pic32c_su_calls_wo_relocs_in_range (bfd               *abfd,
                                    Elf_Internal_Shdr *symtab_hdr,
                                    asection          *section,
                                    vec_type          *func_syms,
                                    set_type          *call_relocs_offsets,
                                    const bfd_vma     start_ofs,
                                    const bfd_vma     end_ofs,
                                    int               arm_range)
{
  PIC32_DBG_PRINT ("\t\tprocessing %s range [0x%0X-0x%0X)\n",
                   (arm_range ? "ARM" : "Thumb"), start_ofs, end_ofs);

  int in_fn = FALSE; /* TRUE if inside function FN_IDX */
  int fn_idx = pic32_su_lookup_func (func_syms, 0, start_ofs, &in_fn);
  Elf_Internal_Sym *fn_sym = (fn_idx != (int) VEC_SIZE (func_syms)) ?
    VEC (Elf_Internal_Sym *, func_syms, fn_idx) : NULL;

  /* past the funcs we know from the sym table or in a big
   * (hypothetical, I'm not sure if it's possible) gap? bail out...
   * TODO: set a global "inaccurate" flag? */
  if (!fn_sym || end_ofs <= ST_VALUE2 (fn_sym))
    {
      PIC32_DBG_PRINT ("\t\tno point in scanning the insns ");
      if (fn_sym)
        PIC32_DBG_PRINT ("(next function %s starts at 0x%0X "
                         "and this range ends at 0x%0X)\n",
                         bfd_elf_sym_name (abfd, symtab_hdr, fn_sym, NULL),
                         ST_VALUE2 (fn_sym), end_ofs);
      else
        PIC32_DBG_PRINT ("(no function containing or coming after "
                         "0x%0X found)\n", start_ofs);
      return;
    }

  const char *fn_name = bfd_elf_sym_name (abfd, symtab_hdr, fn_sym, NULL);
  PIC32_DBG_PRINT ("\t\t%s function %s\n\t\t\tinsns:",
                   (in_fn ? "in" : "before"), fn_name);

  /* the next function change will happen at this offset (at the end of the
   * current function or at the beginning of the next one, depending whether
   * we start inside a function or not) */
  bfd_vma next_ofs = in_fn ? ST_VALUE2 (fn_sym) + fn_sym->st_size
                           : ST_VALUE2 (fn_sym);

  const uint8_t *const sec_data = (uint8_t *) section->contents;
  bfd_vma crt_ofs = start_ofs;

  while (crt_ofs < end_ofs)
    {
      /* time to change the function? */
      if (crt_ofs >= next_ofs)
        {
          PIC32_DBG_PRINT ("\n");
          if (in_fn)
            {
next_fn:
              /* we were inside a function until now; advance to next func */
              fn_sym = (++fn_idx != (int) VEC_SIZE (func_syms)) ?
                  VEC(Elf_Internal_Sym *, func_syms, fn_idx) : NULL;

              /* TODO: set a global "inaccurate" flag? */
              if (!fn_sym || end_ofs <= ST_VALUE2 (fn_sym))
                {
                  PIC32_DBG_PRINT ("\t\tno point in scanning more insns ");
                  if (fn_sym)
                    PIC32_DBG_PRINT ("(next function %s starts at 0x%0X "
                                     "and this range ends at 0x%0X)\n",
                                     bfd_elf_sym_name (abfd, symtab_hdr, fn_sym, NULL),
                                     ST_VALUE2 (fn_sym), end_ofs);
                  else
                    PIC32_DBG_PRINT ("(no function containing or coming after "
                                     "0x%0X found)\n", crt_ofs);
                  return;
                }

              /* but check if indeed inside it or in a "gap" */
              if (crt_ofs < ST_VALUE2 (fn_sym))
                {
                  in_fn = FALSE;
                  next_ofs = ST_VALUE2 (fn_sym);
                }
              else
                {
                  /* continue with the next function (there's a small change
                   * that it partially or totally overlaps the crt one) */
                  crt_ofs = ST_VALUE2 (fn_sym);
                  next_ofs = crt_ofs + fn_sym->st_size;

                  /* adjust the new crt ofs if 'start_ofs' is somewhere in the
                   * middle of crt/next function address range (we just want to
                   * scan the insns in the [start_ofs, end_end) range) */
                  if (start_ofs > crt_ofs)
                    crt_ofs = start_ofs;
                }

              fn_name = bfd_elf_sym_name (abfd, symtab_hdr, fn_sym, NULL);
            }
          else
            {
              /* we were before the function until now;
               * remain on the same func but set 'in_fn' to TRUE */
              BFD_ASSERT (crt_ofs == next_ofs);
              in_fn = TRUE;
              next_ofs += fn_sym->st_size;
            }

          PIC32_DBG_PRINT ("\t\t%s function %s\n\t\t\tinsns:",
                           (in_fn ? "in" : "before"), fn_name);
        }

      uint32_t bits;
      int is_32b;

      if (!arm_range)
        {
          /* for Thumb we need to read the first 16 bits so that we know
          * the size of the insn / how much to advance (even if we just skip it) */
          bits = *(uint16_t *)(sec_data + crt_ofs);

          /* 16- or 32-bit insn? */
          is_32b = ((bits & 0xe000) == 0xe000) && ((bits & 0x1800) != 0);
        }
      else
        {
          /* ARM insns are always 32-bit */
          is_32b = TRUE;
        }


      /* if not in a function, don't process the insn, just dump its size
       * and advance the crt position */
      if (!in_fn)
        {
          PIC32_DBG_PRINT (" %d", 2 << is_32b);
          crt_ofs += 2 << is_32b;
          continue;
        }

      /* process the instruction i.e. try to see if a call/jump to a function */
      int check_target_vma = FALSE;
      bfd_vma target_vma;

      if (arm_range)
        {
          /* ARM32 insn */
          PIC32_DBG_PRINT (" 4");

          bits = *(uint32_t *)(sec_data + crt_ofs);
          crt_ofs += 4;

          const char *opcode = NULL;
          bfd_signed_vma rel_ofs;

          switch (bits & 0xfe000000)
            {
              case 0xea000000: /* B */
              case 0xeb000000: /* BL */
                opcode = (bits & 0x01000000) ? "BL" : "B";
                rel_ofs = arm_branch_imm32 (bits);
                break;
              case 0xfa000000: /* BLX */
              case 0xfb000000:
                opcode = "BLX";
                rel_ofs = arm_branchx_imm32 (bits);
                break;
            }

          if (opcode)
            {
              const bfd_vma insn_vma = crt_ofs - 4;
              target_vma = (insn_vma + 8)/* ARM PC value */ + rel_ofs;

              PIC32_DBG_PRINT ("(%s%+d)", opcode, rel_ofs);

              /* only check the target for branches without relocs
               * (also ignore self-referencing branches / empty loops) */
              check_target_vma = (target_vma != insn_vma)
                && !(call_relocs_offsets
                      && SET_CONTAINS (bfd_vma, call_relocs_offsets, insn_vma));
            }
        }
      else if (!is_32b)
        {
          /* 16-bit Thumb insn */
          PIC32_DBG_PRINT (" 2");

          crt_ofs += 2;

          if ((bits & 0xf800) == 0xe000)              /* B.N */
            {
              const bfd_vma insn_vma = crt_ofs - 2;
              const bfd_signed_vma rel_ofs = thumb_branch_imm32 (bits);

              target_vma = (insn_vma + 4)/* Thumb PC value */ + rel_ofs;

              PIC32_DBG_PRINT ("(B%+d)", rel_ofs);

              /* no relocs for these, so always check the target
               * (that is, unless it's a jump to itself / empty loop
               * as in the dummy handlers) */
              check_target_vma = target_vma != insn_vma;
            }
        }
      else
        {
          /* 32-bit Thumb insn */
          PIC32_DBG_PRINT (" 4");

          bits <<= 16;
          bits |= *(uint16_t *)(sec_data + crt_ofs + 2);
          crt_ofs += 4;

          switch (bits & 0xf800d000)
            {
              case 0xf0009000: /* B.W */
              case 0xf000d000: /* BL */
                {
                  const int is_BL = (bits & 0x4000);
                  const bfd_vma insn_vma = crt_ofs - 4;
                  const bfd_signed_vma rel_ofs = thumb2_branch_imm32 (bits);

                  target_vma = crt_ofs /*PC value=insn_vma + 4*/ + rel_ofs;

                  PIC32_DBG_PRINT ("(%s%+d)", (is_BL ? "BL" : "B"), rel_ofs);

                  /* only check the target for BL/B.W without relocs
                   * (also ignore a possible self-referencing branch /
                   * empty loop, although these usually use B.N) */
                  check_target_vma = (target_vma != insn_vma)
                    && !(call_relocs_offsets
                         && SET_CONTAINS (bfd_vma, call_relocs_offsets, insn_vma));
                }
                break;
            }
        }

      /* check to see if 'target_vma' is the addr of another func
       * from this section */
      if (check_target_vma)
        {
          Elf_Internal_Sym *callee_sym =
            pic32_su_lookup_callee (func_syms, target_vma);

          /* if another function, consider it a callee even if the jump
             is not at its beginning; otherwise, only if the jump is at the
             beginning (for allowing recursive calls but discarding loops) */
          if (callee_sym
              && (callee_sym != fn_sym || target_vma == ST_VALUE2 (callee_sym)))
            {
              const char *callee_name =
                bfd_elf_sym_name (abfd, symtab_hdr, callee_sym, NULL);
              bfd_vma callee_addr = ST_VALUE2 (callee_sym) + section->output_offset +
                                    section->output_section->vma;
              bfd_vma caller_addr = ST_VALUE2 (fn_sym) + section->output_offset +
                                    section->output_section->vma;

              PIC32_DBG_PRINT ("\n\t\t[scanins-based] %s calls %s\n"
                                "\t\t\tinsns:", fn_name, callee_name);

              pic32_su_add_to_call_graph (abfd, fn_name, caller_addr,
                                          abfd, callee_name, callee_addr);
            }
        }
    }
  PIC32_DBG_PRINT ("\n");

  BFD_ASSERT (crt_ofs == end_ofs);

  /* A pretty particular case would be to have two or more overlapping functions
   * with the same end address / equal to the end address of the range - I think
   * using a goto is preferable to totally mess up the above while condition */
  if (in_fn && (fn_idx + 1) < (int) VEC_SIZE (func_syms))
    {
      /* if the next function is also before 'end_ofs', process it as well */
      Elf_Internal_Sym *next_fn = VEC(Elf_Internal_Sym *, func_syms, (fn_idx + 1));
      if (ST_VALUE2 (next_fn) < end_ofs)
        goto next_fn;
    }
}

/*
 * Looks for call/jump instructions without relocations in the given section
 * and updates the call graph accordingly.
 */
void
pic32c_su_calls_wo_relocs_in_section (bfd               *abfd,
                                      Elf_Internal_Shdr *symtab_hdr,
                                      asection          *section,
                                      Elf_Internal_Rela *relocs,
                                      Elf_Internal_Sym  *isymbuf,
                                      vec_type          *func_syms)
{
  size_t locsymcount;
  Elf_Internal_Sym *isymend, *isym;
  Elf_Internal_Rela *relocsend, *irela;
  int free_contents = FALSE, rc;

  /* process only code sections with contents and not linker created */
  const flagword flags =
    SEC_ALLOC | SEC_LOAD | SEC_READONLY | SEC_CODE | SEC_HAS_CONTENTS;
  if (((section->flags & flags) != flags)
      || (section->flags & SEC_LINKER_CREATED))
    return;

  /* the ARM mapping symbols are local symbols so we need to look
     at the local symbols at the beginning of the sym table */
  locsymcount = symtab_hdr->sh_info;
  if (!locsymcount)
    return;

  /* cache the locations of the call relocs in a set for faster access */
  set_type *call_relocs_offsets = NULL;
  if (relocs && section->reloc_count)
    {
      for (irela = relocs, relocsend = relocs + section->reloc_count;
          irela != relocsend; ++irela)
        {
          if (is_call_reloc (ELF32_R_TYPE (irela->r_info)))
            {
              /* lazy allocation */
              if (!call_relocs_offsets)
                call_relocs_offsets = SET_NEW (bfd_vma);

              PIC32_DBG_PRINT ("\t\tcall reloc at 0x%0X\n", irela->r_offset);
              SET_INSERT (bfd_vma, call_relocs_offsets, irela->r_offset);
            }
        }
    }

  /* we need the section contents loaded into memory */
  if (section->contents == NULL)
    {
      bfd_byte *sec_contents = (bfd_byte *) xmalloc (section->size);
      rc = bfd_get_section_contents (abfd, section, sec_contents,
                                     0, section->size);
      BFD_ASSERT (rc);
      section->contents = sec_contents;

      /* TODO: would it be bad to not free the contents when exiting
       *       this function and set the SEC_IN_MEMORY flag instead? */
      free_contents = TRUE;
    }

  typedef enum {
    SEGT_NONE = 0, SEGT_THUMB = 't', SEGT_DATA = 'd', SEGT_ARM = 'a'
  } seg_t;

  typedef struct segments {
    bfd_vma start_off;
    seg_t type;
  } segments_t;

  int segments_compare(const void *p, const void *q)
  {
    bfd_vma l = ((segments_t *)p)->start_off;
    bfd_vma r = ((segments_t *)q)->start_off;

    return (l - r);
  }

  /* Worst case scenario is to have all the local syms
   * with st_shndx = current_section_index. We will allocate
   * a buffer of segments_t with that size instead of reallocating
   * It is a tradeoff memory vs speed.
   */
  segments_t *section_segments = xmalloc(locsymcount * sizeof(section_segments[0]));
  int i, local_syms_for_section = 0;

  /* get the mapping symbols for this section; first sym is bogus/NULL;
   * go one extra iteration to synthesize an "end section symbol" */
  for (isym = isymbuf + 1, isymend = isymbuf + locsymcount;
       isym <= isymend; ++isym)
    {
      if (isym != isymend)
        {
          if (ELF_ST_TYPE (isym->st_info) != STT_NOTYPE
              || isym->st_size != 0
              || bfd_section_from_elf_index (abfd, isym->st_shndx) != section)
            continue;

          const char *sym_name =
            bfd_elf_sym_name (abfd, symtab_hdr, isym, NULL);

          /* mapping symbol names: $t (Thumb), $d (Data), $a (ARM) */
          if (!sym_name || sym_name[0] != '$' || sym_name[2] != '\0'
              || strchr ("tda", sym_name[1]) == NULL)
            continue;

          section_segments[local_syms_for_section].type = sym_name[1];
          section_segments[local_syms_for_section].start_off = ST_VALUE2 (isym);
          local_syms_for_section++;
        }
      else
        {
          section_segments[local_syms_for_section].type = SEGT_NONE;
          section_segments[local_syms_for_section].start_off = section->size;
          local_syms_for_section++;
        }
    }

    /* sort the section_segments by start_offset so we can build our
     * code intervals where we can search for relocs: [t|a, d|none]
     */
    qsort(section_segments, local_syms_for_section,
          sizeof(section_segments[0]), segments_compare);

    /* Last segment will always be SEGT_NONE with value = section->size */
    for (i = 0; i < local_syms_for_section - 1; i++)
    {
      /* skip the data segments */
      if (section_segments[i].type == SEGT_DATA)
        continue;

      bfd_vma start_offset = section_segments[i].start_off;
      bfd_vma end_offset = section_segments[i + 1].start_off;
      seg_t current_type = section_segments[i].type;
      seg_t next_type = section_segments[i + 1].type;

      /* make sure the current segment ends either when a data
       * segment starts or with end of section (encoded by SEGT_NONE)
       */
      BFD_ASSERT (next_type == SEGT_DATA || next_type == SEGT_NONE);

      pic32c_su_calls_wo_relocs_in_range (abfd, symtab_hdr, section,
                                          func_syms, call_relocs_offsets,
                                          start_offset, end_offset,
                                          current_type == SEGT_ARM);
    }

  free(section_segments);
  section_segments = NULL;

  if (free_contents)
    {
      free (section->contents);
      section->contents = NULL;
    }

  SET_DELETE (call_relocs_offsets);
}

/* Print the memory reports iff a valid license is found
 * and report-mem option was used.
 * Dump the report in map file if a map was specified or at
 * stdout otherwise.
 */
static void print_memory_reports(void)
{
  /* XC32-2375: always put the reports in map file
   * if -Map was provided
   */
  if (config.map_file != NULL)
    {
      bfd_pic32_report_memory_usage (config.map_file);
      bfd_pic32_report_memory_usage_by_module (config.map_file);
    }

  /* No memory report if mafrlcsj was provided */
  if (pic32_mafrlcsj || pic32_mafrlcsj2)
    return;


  /* XC32-2375: dump the memory reports to stdout only
   * if --report-mem is enabled
   */
  if (!pic32_report_mem)
    return;

  bfd_pic32_report_memory_usage (stdout);
  bfd_pic32_report_memory_usage_by_module (stdout);
}

void
pic32c_finish (void)
{
  struct bfd_link_hash_entry * h;

  {
    LANG_FOR_EACH_INPUT_STATEMENT (is)
      {
        /* Figure out where VFP11 erratum veneers (and the labels returning
           from same) have been placed.  */
        bfd_elf32_arm_vfp11_fix_veneer_locations (is->the_bfd, &link_info);

	/* Figure out where STM32L4XX erratum veneers (and the labels returning
	   from them) have been placed.  */
	bfd_elf32_arm_stm32l4xx_fix_veneer_locations (is->the_bfd, &link_info);
      }
  }

  if (!bfd_link_relocatable (&link_info))
    {
      /* Now build the linker stubs.  */
      if (stub_file->the_bfd->sections != NULL)
	{
	  if (! elf32_arm_build_stubs (& link_info))
	    einfo ("%X%P: can not build stubs: %E\n");
	}
    }

  /*  stuff added here from the mips version if pic32_finish */

  need_layout = bfd_elf_discard_info (link_info.output_bfd,
                                      &link_info);
  /* We need to map segments here so that we determine file positions for
     sections added by best-fit-allocator */
  emultempl_map_segments (need_layout);

  /* XC32E-661: account for being called with -r by the lto-wrapper.
     This is done to extract debug info, essentially, but will pull in
     global symbols (like _stack, _dinit_addr, etc.) that confuse the
     hell out of us when actually linking later on. */
  if (!bfd_link_relocatable (&link_info)) {
    bfd_pic32_finish();

    if (pic32_stack_usage) {
      pic32_stack_estimation_run ();
    }
  }

  print_memory_reports();

  if (pic32_has_crypto_option)
    pic32_report_crypto_sections();

  /* Output memory descriptor file for IDE */
  if (pic32_memory_summary)
    bfd_pic32_memory_summary(memory_summary_arg);

  /* XC32-1658: moved this from (the end of) bfd_pic32_finish () here as it
     needs to be called after the memory summary is produced */
  pic32_free_region_info (&region_info);

  /* end of stuff from pic32_finish */

  finish_default ();

  if (params.thumb_entry_symbol)
    {
      h = bfd_link_hash_lookup (link_info.hash, params.thumb_entry_symbol,
				FALSE, FALSE, TRUE);
    }
  else
    {
      struct elf_link_hash_entry * eh;

      if (!entry_symbol.name)
	return;

      h = bfd_link_hash_lookup (link_info.hash, entry_symbol.name,
				FALSE, FALSE, TRUE);
      eh = (struct elf_link_hash_entry *)h;
      if (!h || ARM_GET_SYM_BRANCH_TYPE (eh->target_internal)
	  != ST_BRANCH_TO_THUMB)
	return;
    }


  if (h != (struct bfd_link_hash_entry *) NULL
      && (h->type == bfd_link_hash_defined
	  || h->type == bfd_link_hash_defweak)
      && h->u.def.section->output_section != NULL)
    {
      static char buffer[32];
      bfd_vma val;

      /* Special procesing is required for a Thumb entry symbol.  The
	 bottom bit of its address must be set.  */
      val = (h->u.def.value
	     + bfd_get_section_vma (link_info.output_bfd,
				    h->u.def.section->output_section)
	     + h->u.def.section->output_offset);

      val |= 1;

      /* Now convert this value into a string and store it in entry_symbol
	 where the lang_finish() function will pick it up.  */
      buffer[0] = '0';
      buffer[1] = 'x';

      sprintf_vma (buffer + 2, val);

      if (params.thumb_entry_symbol != NULL && entry_symbol.name != NULL
	  && entry_from_cmdline)
	einfo (_("%P: warning: '--thumb-entry %s' is overriding '-e %s'\n"),
	       params.thumb_entry_symbol, entry_symbol.name);
      entry_symbol.name = buffer;
    }
  else
    einfo (_("%P: warning: cannot find thumb start symbol %s\n"),
	   params.thumb_entry_symbol);
}

/* This is a convenient point to tell BFD about target specific flags.
   After the output has been created, but before inputs are read.  */
void
arm_elf_create_output_section_statements (void)
{

  if (strstr (bfd_get_target (link_info.output_bfd), "arm") == NULL)
    {
      /* The arm backend needs special fields in the output hash structure.
	 These will only be created if the output format is an arm format,
	 hence we do not support linking and changing output formats at the
	 same time.  Use a link followed by objcopy to change output formats.  */
      einfo ("%F%X%P: error: Cannot change output format whilst linking ARM binaries.\n");
      return;
    }

  if (in_implib_filename)
    {
      params.in_implib_bfd = bfd_openr (in_implib_filename,
				 bfd_get_target (link_info.output_bfd));

      if (params.in_implib_bfd == NULL)
	einfo ("%F%s: Can't open: %E\n", in_implib_filename);

      if (!bfd_check_format (params.in_implib_bfd, bfd_object))
	einfo ("%F%s: Not a relocatable file: %E\n", in_implib_filename);
    }

  bfd_elf32_arm_set_target_params (link_info.output_bfd, &link_info, &params);

  stub_file = lang_add_input_file ("linker stubs",
 				   lang_input_file_is_fake_enum,
 				   NULL);
  stub_file->the_bfd = bfd_create ("linker stubs", link_info.output_bfd);
  if (stub_file->the_bfd == NULL
      || ! bfd_set_arch_mach (stub_file->the_bfd,
 			      bfd_get_arch (link_info.output_bfd),
 			      bfd_get_mach (link_info.output_bfd)))
    {
      einfo ("%X%P: can not create BFD %E\n");
      return;
    }

  stub_file->the_bfd->flags |= BFD_LINKER_CREATED;
  ldlang_add_file (stub_file);

  /* Also use the stub file for stubs placed in a single output section.  */
  bfd_elf32_arm_add_glue_sections_to_bfd (stub_file->the_bfd, &link_info);
  bfd_elf32_arm_get_bfd_for_interworking (stub_file->the_bfd, &link_info);
}

/* Avoid processing the fake stub_file in vercheck, stat_needed and
   check_needed routines.  */

#if 0    /* Ignored Arm stuff */
/* TODO: This collection of definitions is not used but comes from the
   Arm emulation file.  In the event we need to use it, we can avoid
   rewriting it. Whether we really need to keep it is up for
   discussion. */
static void (*real_func) (lang_input_statement_type *);

static void arm_for_each_input_file_wrapper (lang_input_statement_type *l)
{
  if (l != stub_file)
    (*real_func) (l);
}

static void
arm_lang_for_each_input_file (void (*func) (lang_input_statement_type *))
{
  real_func = func;
  lang_for_each_input_file (&arm_for_each_input_file_wrapper);
}

#define lang_for_each_input_file arm_lang_for_each_input_file
#endif	/* Ignored Arm stuff */

/*
** Utility routine: bfd_pic32_report_memory_usage
**
** - print a section chart to file *fp
**/
void
bfd_pic32_report_memory_usage (fp)
     FILE *fp;
{
  bfd_size_type region_prog_memory_used;
  lang_memory_region_type *region;
  unsigned int region_index, region_count;
  struct pic32_section *s;
  struct region_report_tag {
    char *name;
    char *title;
    char *total;
  };
  struct region_report_tag pmregions_to_report[] =
    {{"rom",
      "ROM Program-Memory Usage",
      "      Total ROM used"}
     };

  struct region_report_tag dmregions_to_report[] =
    {{"ram",
        "RAM Data-Memory Usage",
        "         Total RAM used"}
    };

  /* clear the counters */
  actual_prog_memory_used = 0;
  data_memory_used = 0;
  region_prog_memory_used = 0;
  region_data_memory_used = 0;
  total_data_memory = total_prog_memory = 0;

  fflush (fp);

  fprintf (fp, "\nMicrochip PIC32 Memory-Usage Report");

  /* build an ordered list of output sections */
  pic32_init_section_list(&pic32_section_list);
  bfd_map_over_sections(link_info.output_bfd, &pic32_build_section_list, NULL);

  region_count = sizeof(pmregions_to_report)/sizeof(pmregions_to_report[0]);
  magic_pm.count = sizeof(magic_pmdescriptions)/sizeof(magic_pmdescriptions[0]);
  magic_pm.start = magic_pm.index = 0;
  for (region_index = 0; region_index < region_count; region_index++)
  {
     if (!lang_memory_region_exist(pmregions_to_report[region_index].name))
       continue;
     region = lang_memory_region_lookup(pmregions_to_report[region_index].name, FALSE);

     /* could have a bogus region due to region_lookup's strangeness. */
     if (!valid_region(region)) 
       continue;

     /* print code header */
     fprintf( fp, "\n\n%s\n", pmregions_to_report[region_index].title);
     fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
     fprintf( fp, "-------                 ----------  -------------------------  -----------\n");
     /* report code sections */
     for (s = pic32_section_list; s != NULL; s = s->next)
       if (s->sec)
       {
         region_prog_memory_used += bfd_pic32_report_sections (s, region, &magic_pm,fp);
       }
     fprintf( fp, "%s  :  %#10lx  %10ld  ",
            pmregions_to_report[region_index].total,
            (unsigned long)region_prog_memory_used, (unsigned long)region_prog_memory_used);
     report_percent_used(region_prog_memory_used,region->length, fp);
     total_prog_memory += region->length;
     actual_prog_memory_used += region_prog_memory_used;
     region_prog_memory_used = 0;
   }

  /* -------------------- */
  /*  print code summary  */
  /* -------------------- */

  fprintf (fp, "\n        --------------------------------------------------------------------------\n");
  fprintf (fp,     "         Total Program Memory used  :  %#10lx  %10ld  ",
         (unsigned long)actual_prog_memory_used, (unsigned long)actual_prog_memory_used);
  report_percent_used (actual_prog_memory_used, total_prog_memory, fp);
  fprintf (fp, "\n        --------------------------------------------------------------------------\n");

  /* DATA MEMORY */

  region_count = sizeof(dmregions_to_report)/sizeof(dmregions_to_report[0]);
  magic_dm.count = sizeof(magic_dmdescriptions)/sizeof(magic_dmdescriptions[0]);
  magic_dm.start = magic_dm.index = 0;
  for (region_index = 0; region_index < region_count; region_index++)
  {
     if (!lang_memory_region_exist(dmregions_to_report[region_index].name))
       continue;

     region = lang_memory_region_lookup(dmregions_to_report[region_index].name, FALSE);

     /* could have a bogus region due to region_lookup's strangeness. */
     if (!valid_region(region))
       continue;

     /* print data header */
     fprintf( fp, "\n\n%s\n", dmregions_to_report[region_index].title);
     fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
     fprintf( fp, "-------                 ----------  -------------------------  -----------\n");
     /* report data sections */
     for (s = pic32_section_list; s != NULL; s = s->next)
       if (s->sec)
       {
         region_data_memory_used += bfd_pic32_report_sections (s, region, &magic_dm, fp);
       }

     fprintf( fp, "%s  :  %#10lx  %10ld  ",
            dmregions_to_report[region_index].total,
            (unsigned long)region_data_memory_used, (unsigned long)region_data_memory_used);
     report_percent_used(region_data_memory_used,region->length, fp);
     total_data_memory += region->length;
     data_memory_used += region_data_memory_used;
     region_data_memory_used = 0;
   }

  /* -------------------- */
  /*  print data summary  */
  /* -------------------- */

  fprintf( fp, "\n        --------------------------------------------------------------------------\n");
  fprintf( fp,     "            Total Data Memory used  :  %#10lx  %10ld  ",
         (unsigned long)data_memory_used, (unsigned long)data_memory_used);
  report_percent_used (data_memory_used, total_data_memory, fp);
  fprintf( fp, "\n        --------------------------------------------------------------------------\n");


  /* Dynamic Data Memory */
#define NAME_MAX_LEN 23
#define NAME_FIELD_LEN "24"
  fprintf( fp, "\n\n%s\n", "Dynamic Data-Memory Reservation");
  fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
  fprintf( fp, "-------                 ----------  -------------------------  -----------\n");
  fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", "heap",
             (unsigned long)heap_base, (unsigned long)(heap_limit-heap_base),
             (unsigned long)(heap_limit-heap_base), "Reserved for heap");

    if (pic32c_stack_in_tcm && (dtcm_stack_limit != 0))
    {
        fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", "stack",
            (unsigned long) dtcm_stack_limit, (unsigned long)(dtcm_stack_limit-dtcm_stack_base),
            (unsigned long)(dtcm_stack_limit-dtcm_stack_base), "Reserved for stack");
    }
    else
    {
        fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", "stack",
            (unsigned long)stack_base, (unsigned long)(stack_limit-stack_base),
            (unsigned long)(stack_limit-stack_base), "Reserved for stack");
    }

  fprintf( fp, "\n        --------------------------------------------------------------------------\n");


  /* 
     Report user-defined memory sections...
     They require some extra effort to organize by
     external memory region 
   */
#ifdef ENABLE_USER_MEMORY
  if (has_user_defined_memory) {
    struct pic32_section *r, *rnext;
    const char *region_name;

    /* Loop through any user-defined regions */
    for (r = memory_region_list; r != NULL; r = rnext) {
        rnext = r->next;

      if (r->sec == 0) continue;

      region_name = r->sec->name + strlen(memory_region_prefix);
      fprintf( fp, "\nExternal Memory %s"
               "  [Origin = 0x%lx, Length = 0x%lx]\n\n",
                region_name, r->sec->vma, r->sec->lma);


      fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
      fprintf( fp, "-------                 ----------  -------------------------  -----------\n");


      external_memory_used = 0;
      for (s = pic32_section_list; s != NULL; s = s->next)
        if (s->sec)
          bfd_pic32_report_memory_sections (region_name, s->sec, fp);


      /* -------------------- */
      /*  print data summary  */
      /* -------------------- */

      fprintf( fp, "\n        --------------------------------------------------------------------------\n");
      fprintf( fp,     "         Total External Memory used :  %#10lx  %10ld  ",
                                   (unsigned long)external_memory_used, (unsigned long)external_memory_used);
      if (external_memory_used > 0)
        report_percent_used (external_memory_used, r->sec->lma, fp);
      fprintf( fp, "\n        --------------------------------------------------------------------------\n");
    }
  }
#endif /* 0 */

  fflush (fp);
#undef NAME_MAX_LEN
#undef NAME_FIELD_LEN
} /* static void bfd_pic32_report_memory_usage (...)*/


void pic32_report_crypto_sections()
{
#if 0 
  FILE *crypto;
   struct pic32_section *s;
   char *c;
   crypto = fopen(crypto_file, "w");
   if (!crypto){
     printf("Error: crypto output file cannot be opened.\n");
     xexit(1);
   }
     for (s = pic32_section_list; s != NULL; s = s->next)
       if (s->sec && (strstr(s->sec->name,"XC32$_crypto") ||
                      (strncmp(s->sec->name, ".dinit%", 7) == 0)))
       {
          c = strchr(s->sec->name, '%');
          if (c) *c = (char) '\0';
	  fprintf( crypto, "%s\t%#x\t%#x\n", s->sec->name,
                 (unsigned int)s->sec->vma, (unsigned int)s->sec->size);
       }
    fclose(crypto);
    free(crypto_file);
#endif
}

#ifdef ENABLE_USER_MEMORY
static void
bfd_pic32_report_memory_regions (FILE *memory_summary_file,
                                 const char memory_name[],
                                 const char *region_names[])
{
  unsigned long total_size = 0;
  unsigned long used_size = 0;

  struct pic32_section *s;
  lang_memory_region_type *region;

  for (; *region_names; ++region_names)
  {
    if (!lang_memory_region_exist (*region_names))
      continue;

    region = lang_memory_region_lookup (*region_names, FALSE);

    if (!valid_region(region))
      continue;

    for (s = pic32_section_list; s != NULL; s = s->next)
      if (s->sec)
      {
        used_size += bfd_pic32_collect_section_size (s, region);
      }

    total_size += region->length;
  }

  // TCM memory is not included if it's not enabled / zero size
  if (strcmp (memory_name, "tcm") || total_size)
  {
    // NB: the free size is redundant (easily derived from the other two)
    fprintf (memory_summary_file, "    <memory name=\"%s\">\n"
                                  "      <units>bytes</units>\n"
                                  "      <length>%lu</length>\n"
                                  "      <used>%lu</used>\n"
                                  "      <free>%lu</free>\n"
                                  "    </memory>\n",
      memory_name, total_size, used_size, total_size - used_size);
  }
}
#endif

void bfd_pic32_memory_summary(char *arg)
{
  FILE *memory_summary_file = fopen (arg, "w");
  if (memory_summary_file == NULL) {
    fprintf (stderr, "Warning: Could not open %s.\n", arg );
    return;
  }

  /* build an ordered list of output sections */
  pic32_init_section_list (&pic32_section_list);
  bfd_map_over_sections (link_info.output_bfd, &pic32_build_section_list, NULL);

  /*Do not change the output xml format as it might throw the IDE off*/
  fprintf (memory_summary_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                                "<project>\n"
                                "  <executable name=\"%s\">\n", output_filename ); 

  /*Calculate and output memory summary file*/
  /*For now, generate the TCM info only when doing the PRO comparison (i.e. not
    for the regular builds because it messes the memory display in the IDE */
  pic32_report_region_info (memory_summary_file, pic32_mafrlcsj || pic32_mafrlcsj2);

  fprintf (memory_summary_file, "  </executable>\n"
                                "</project>\n");
  fclose (memory_summary_file);
}


#ifdef ENABLE_USER_MEMORY
/*
** Utility routine: bfd_pic32_report_memory_sections()
**
** - show memory usage of sections in user-defined regions
*/ 
static void
bfd_pic32_report_memory_sections (region, sect, fp) 
     const char *region;
     asection *sect;
     FILE *fp;
{
  unsigned long start = sect->vma;
  unsigned int opb = bfd_octets_per_byte (link_info.output_bfd);
  bfd_size_type total = sect->rawsize / opb; /* ignore phantom bytes */

  if (PIC32_IS_MEMORY_ATTR(sect)) {
    const char *c1, *c2;
    struct pic32_section *s;
    unsigned int n;

    /* loop through the list of memory-type sections */
    for (s = user_memory_sections; s != NULL; s = s->next) {
      if (!s->file || !s->sec) continue;
      if (strcmp((char *)s->file, region) != 0) continue;
      
      c1 = (const char *) s->sec;  /* name is stored here! */
      c2 = strchr(c1, '%');        /* avoid the %n terminator */
      n = c2 ? c2 - c1 : strlen(c1);
      if (strncmp(c1, sect->name, n) == 0) {
        char *c, *name = xmalloc(strlen(sect->name) + 1);
        strcpy(name, sect->name);  /* make a local copy of the name */
        c = strchr(name, '%');
        if (c) *c = (char) NULL;   /* remove the %n terminator */
        
        fprintf( fp, "%-24s%#10lx     %#10lx  %10ld \n", name, start, total, total);
 
        external_memory_used += total;
        free(name);
        break;
      }
    }
  }
  return;
} /* static void bfd_pic32_report_memory_sections (...)*/
#endif

/*
** Utility routine: bfd_pic32_collect_section_size()
**
** - calculate memory usage of SEC_ALLOC-flagged sections in memory
*/
bfd_size_type
bfd_pic32_collect_section_size (s, region )
     struct pic32_section *s;
     const lang_memory_region_type *region;
{
  bfd_size_type region_used = 0;
  unsigned long start = s->sec->vma;
  unsigned long load  = s->sec->lma;
  unsigned long actual = s->sec->output_section->size;

  if (PIC32_IS_COHERENT_ATTR(s->sec)) {
    start &= 0xdfffffff;
    load &= 0xdfffffff;
  }
   
  /*
  ** report SEC_ALLOC sections in memory
  */
  if (valid_region(region) &&
      ((s->sec->flags & SEC_ALLOC) && (s->sec->size > 0)))
    {
      if ((start >= region->origin) &&
          ((start + actual) <= (region->origin + region->length)))
      {
         region_used = actual;
      }
      else if ((load >= region->origin) &&
          ((load + actual) <= (region->origin + region->length)) &&
           (s->sec->flags & (SEC_HAS_CONTENTS)))
      {
         region_used = actual;
      }
    }
  return region_used;
} /* static bfd_size_type bfd_pic32_collect_section_size (...) */


static void
report_percent_used (used, max, fp)
     bfd_vma used, max;
     FILE *fp;
{
  double percent;

  if (max > 0) {
     percent = 100 * ((float) used/max);

     if (percent)
       fprintf( fp, "%.1f%% of %#x", percent, max);
     else
       fprintf( fp, "<1%% of %#x", max);
   }
}
// end of code for reporting memory usage


static bfd_boolean
is_section_discarded (asection *s)
{
  return ((s->output_section == NULL
              || s->output_section->owner != link_info.output_bfd)
	      && (s->flags & (SEC_LINKER_CREATED | SEC_KEEP)) == 0);
}

typedef struct llist {
  const char *name;
  bfd_size_type len;
  struct llist *next;
} llist_type;

static void
add_to_seclist (asection* input_sec, llist_type** list_head_ptr)
{
  llist_type *lptr = (llist_type*) malloc(sizeof(llist_type));
  lptr->name = input_sec->name;
  lptr->len = input_sec->size;
  lptr->next = NULL;

  if (*list_head_ptr == NULL)
    *list_head_ptr = lptr;
  else {
    llist_type* llast = *list_head_ptr;
    while (llast->next)
      llast = llast->next;
    llast->next = lptr;
  }
}

static void
freeup_list (llist_type* lptr)
{
  if (lptr == NULL)
    return;
  if (lptr->next)
    freeup_list(lptr->next);
  else
    free(lptr);
}

#define SECTION_NAME_MAP_LENGTH (30)
static void
align_next_column (int len)
{
  if (len >= SECTION_NAME_MAP_LENGTH - 1)
    {
      print_nl ();
      len = 0;
    }
  while (len < SECTION_NAME_MAP_LENGTH)
    {
      print_space ();
      ++len;
    }
}

void
arm_extra_map_file_text (bfd *abfd ATTRIBUTE_UNUSED,
			 struct bfd_link_info *hinfo ATTRIBUTE_UNUSED,
			 FILE *mapf)
{
  if (detailed_mem_usage_to_map == FALSE)
    return;

  fprintf (mapf, _ ("\nInput files and contributions to "
		    "output file."));

  LANG_FOR_EACH_INPUT_STATEMENT (f)
  {
    if ((f->the_bfd->flags & (BFD_LINKER_CREATED | DYNAMIC)) != 0
	|| f->flags.just_syms || f->the_bfd->filename == NULL)
      continue;

    bfd_boolean does_bfd_contribute = FALSE;
    lang_output_section_statement_type *os;

    for (os = &lang_output_section_statement.head->output_section_statement;
	 os != NULL; os = os->next)
      {
	llist_type *input_seclist_head = NULL;
	asection *output_section = os->bfd_section;

	/* Skip if null or section contains debug info */
	if ((output_section == NULL)
	    || ((output_section->flags & SEC_ALLOC) == 0))
	  continue;

	asection *i;
	bfd_size_type size_from_this_bfd = 0;

	for (i = f->the_bfd->sections; i != NULL; i = i->next)
	  {
	    if ((is_section_discarded (i))
		|| (i->output_section != output_section) || (i->size == 0))
	      continue;

	    add_to_seclist (i, &input_seclist_head);
	    size_from_this_bfd += i->size;
	  }

	if (size_from_this_bfd > 0)
	  {
	    int len;

	    if (does_bfd_contribute == FALSE)
	      {
		does_bfd_contribute = TRUE;
		fprintf (mapf, "\n\n%s\n", f->the_bfd->filename);
	      }

	    minfo ("\n%s", output_section->name);

	    len = strlen (output_section->name);
	    align_next_column (len);
	    minfo ("%W", size_from_this_bfd);
	    minfo ("\t(%s)", os->region->name_list.name);

	    /* Print input sections and size */
	    llist_type *lptr = input_seclist_head;
	    while (lptr)
	      {
		minfo ("\n  %s", lptr->name);
		len = strlen (lptr->name) + 2;
		align_next_column (len);
		minfo ("%W", lptr->len);
		lptr = lptr->next;
	      }
	    freeup_list (input_seclist_head);
	  }
      }
  }
}

/*****************************************************************************
**
** Section List Routines
**
** Maintain a list of sections in order
** of ascending load address.
**
** Used for creating memory usage reports.
**
*/

/*
** check if a list is empty
*/
bfd_boolean pic32_is_empty_list(struct pic32_section* const lst)
{
    if (lst && (lst->sec == 0))
        return TRUE;

    return FALSE;
}

/*
** Add a section to the list
**
** - in order of increasing load address
** - this function is called via bfd_map_over_sections()
*/
void
pic32_build_section_list_vma (abfd, sect, fp)
     bfd *abfd ATTRIBUTE_UNUSED ;
     asection *sect;
     PTR fp ATTRIBUTE_UNUSED ;
{
  struct pic32_section *new, *s, *prev;
  int done = 0;

  /* Already added due to lma */
  if (sect->lma == sect->vma)
    return;

  /* create a new element */
  new = ((struct pic32_section *)
         xmalloc(sizeof(struct pic32_section)));
  if (NULL == new) {
    fprintf( stderr, "Fatal Error: Could not build section list\n");
    abort();
  }
  new->sec  = sect;
  new->attributes = pic32_attribute_map(sect);
  new->file = 0;
  new->use_vma = 1;
  new->pic32_size = sect->size;
  new->region = NULL;
  new->children = NULL;

  /* insert it at the right spot */
  prev = pic32_section_list;
  for (s = prev; s != NULL; s = s->next)
    {
      if (s->sec && (new->sec->vma < s->sec->lma))
        {
          prev->next = new;
          new->next = s;
          PIC32_DEBUG("pic32_build_section_list_vma: Adding %s LMA:%x VMA:%x",
		      new->sec->name,
		      (unsigned int)new->sec->lma,
		      (unsigned int)new->sec->vma);
          done++;
          break;
        }
      prev = s;
    }

  if (!done)
    {
      if (prev) 
        prev->next = new;
      else {
        PIC32_DEBUG("internal error: build_section_list called on uninitialized list");
      }
      new->next = NULL;
    }

} /* static void pic32_build_section_list_vma (...) */

void
pic32_build_section_list (abfd, sect, fp)
     bfd *abfd ATTRIBUTE_UNUSED ;
     asection *sect;
     PTR fp ATTRIBUTE_UNUSED ;
{
  struct pic32_section *new, *s, *prev;
  int done = 0;

  /* the list is used by BFA, so we are interested only in allocatable sections */
  if (!(sect->flags & (SEC_LOAD | SEC_ALLOC)))
    return;

  /* create a new element */
  new = ((struct pic32_section *)
         xmalloc(sizeof(struct pic32_section)));
  if (NULL == new) {
    fprintf( stderr, "Fatal Error: Could not build section list\n");
    abort();
  }
  new->sec  = sect;
  new->attributes = pic32_attribute_map(sect);
  new->file = 0;
  new->use_vma = 0;
  new->pic32_size = sect->size;
  new->region = NULL;
  new->children = NULL;

  /* insert it at the right spot */
  prev = pic32_section_list;
  for (s = prev; s != NULL; s = s->next)
    {
      if (s->sec && (new->sec->lma < s->sec->lma))
        {
          prev->next = new;
          new->next = s;
	  //PIC32_DEBUG("pic32_build_section_list: Adding %s LMA:%x VMA:%x  bfa? %d\n", new->sec->name, (unsigned int)new->sec->lma, (unsigned int)new->sec->vma, new->sec->bfa);
          done++;
          break;
        }
      prev = s;
    }

  if (!done)
    {
      prev->next = new;
      new->next = NULL;
    }
} /* static void pic32_build_section_list (...) */



/*
** return the pic32_section from the given list corresponding to the given bfd section, or NULL.
*/

static struct pic32_section *  find_pic32_sec_from_bfd_section(struct pic32_section *lst, asection *bfd_sec) {

    struct pic32_section *s,  *c;
    if (NULL == lst || NULL == bfd_sec) return NULL;
    for (s = lst; s != NULL; s = s->next) {
	if (NULL == s->sec) continue;
	// comparison of pointers !
	if (s->sec == bfd_sec) return s;
	if (NULL != s->children) {
	    c = find_pic32_sec_from_bfd_section(s->children, bfd_sec);
	    if (c != NULL) return c;
	}
    }
    return NULL;
}





/*
** Search a section list by name
*/
#ifdef ENABLE_USER_MEMORY
static bfd_boolean
pic32_name_in_section_list (lst, name)
     struct pic32_section *lst;
     const char *name;
{
  struct pic32_section *s, *next;
  for (s = lst; s != NULL; s = next) {
    next = s->next;
    if (s->sec && strcmp(s->sec->name, name) == 0)
      return TRUE;
  }
  return FALSE;
}
#endif




/* This is called after all the input files have been opened. */
void
pic32c_after_open (void)
{
  /*
  ** Merge full- and reduced-set I/O functions
  */
  if (pic32_smart_io)
    {
      PIC32_DEBUG("Merging smart-io functions:");

      smartio_merge_symbols ();
    } /* pic32_smart_io */

  emultempl_after_open ();

#ifdef ENABLE_USER_MEMORY
  /* Prepare a list for sections in user-defined regions */
  if (user_memory_sections)
    pic32_free_section_list (&user_memory_sections);
  pic32_init_section_list (&user_memory_sections);
#endif

  {
    /* loop through all of the input bfds */
    LANG_FOR_EACH_INPUT_STATEMENT (is)
    {
      if (!bfd_pic32_process_bfd_after_open (is->the_bfd, &link_info))
	{
	  einfo ("Errors encountered processing file %s\n", is->filename);
	}
    }
  }

  if (!(bfd_link_pic (&link_info) || bfd_link_relocatable (&link_info))
      && !stack_section_defined && (pic32c_stack_size > 0))
    {
      PIC32_DEBUG("Creating stack of size %x", pic32c_stack_size);

      stack_bfd = bfd_pic32_create_stack_bfd (link_info.output_bfd);
      bfd_pic32_add_bfd_to_link (stack_bfd, stack_bfd->filename);
      stack_section_defined = TRUE;
    }
} /* end of pic32c_after_open */

/* Place an orphan section.  We use this to put random SHF_ALLOC
   sections in the right segment.  */

lang_output_section_statement_type *
arm_elf_place_orphan (asection *sec, const char *secname ATTRIBUTE_UNUSED,
		      int constraint ATTRIBUTE_UNUSED)
{
  if (pic32_allocate) 
    {

      if (((sec->flags & SEC_DEBUGGING) == SEC_DEBUGGING)
	  || ((sec->flags & SEC_ALLOC) == 0))
	return NULL; /* let the base code handle non-alloc sections */

      if (!unassigned_sections)
	pic32_init_section_list (&unassigned_sections);

      pic32_append_section_to_list (unassigned_sections, sec);

      /* mark that the section is being placed by the allocator. */
      sec->bfa = 1;

      /* MERGE_NOTES: maybe theres a more sensible thing to return? but the
         idea here is to just return non-NULL since the output section will be
         determined by the BFA. */
      return (lang_output_section_statement_type *) 1; /* and exit */
    }
  else
    {
      return emultempl_place_orphan (sec, secname, constraint);
    }
}
