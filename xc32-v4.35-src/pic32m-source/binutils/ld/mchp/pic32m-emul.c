/* Linker emulation code for pic32m.

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

#ifndef TARGET_IS_PIC32
#define TARGET_IS_PIC32
#endif

#ifndef PIC32
#define PIC32
#endif

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

#include "elf/mips.h"
#include "elfxx-mips.h"
#include "elf/pic32.h"
#include "ctype.h"
#include "pic32m-utils.h"
#include <stdint.h>
#include <limits.h>

#include "pic32-stack-usage.h"
#include "pic32-vecset.h"
#include "pic32m-options.h"
#include "pic32m-allocate.h"
#include "pic32-su-callstack.h"
#include "pic32-su-common.h"

#include "pic32m-emul.h"
#include "pic32m-emultempl.h"
#include "smartio.h"
#include "mchp/pic32-common-emul.h"
#include "pic32-debug.h"

#define DEBUG_SCOPE "bfa"

/* Defined elsewhere without a header. */
extern int pic32_is_fltpt_machine (const bfd_arch_info_type *);
extern struct pic32_memory *program_memory_free_blocks;

/* defined in bfd/pic32-attributes.c */
char *pic32_section_size_string (asection *);
char *pic32_section_attr_string (asection *);
unsigned int pic32_attribute_map (asection *);
unsigned int pic32_extended_attribute_map (asection *);
void pic32_set_attributes (asection *, unsigned int, unsigned char);
void pic32_set_extended_attributes (asection *, unsigned int, unsigned char);

#define is_mips_elf(bfd)				\
  (bfd_get_flavour (bfd) == bfd_target_elf_flavour	\
   && elf_tdata (bfd) != NULL				\
   && elf_object_id (bfd) == MIPS_ELF_DATA)

/* Fake input file for stubs.  */
static lang_input_statement_type *stub_file;
static bfd *stub_bfd;

bfd_boolean insn32;
int eh_reloc_type = R_MIPS_EH;

struct traverse_hash_info
{
  bfd *abfd;
  asection *sec;
};

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

static void bfd_pic32_report_memory_sections
  (const char *, asection *, FILE *);

extern void bfd_pic32_report_memory_usage_by_module
   (FILE *);

void bfd_pic32_report_memory_usage
  (FILE *);

static void report_percent_used
  (bfd_vma, bfd_vma, FILE *);

void pic32_build_section_list
  (bfd *, asection *, PTR);

void pic32_build_section_list_vma
  (bfd *, asection *, PTR);

bfd_boolean pic32_is_empty_list(struct pic32_section* const lst);


/*static*/ void pic32_init_section_list
  (struct pic32_section **);

static bfd_boolean pic32_name_in_section_list
  (struct pic32_section *, const char *);

static void bfd_pic32_finish
  (void);

void pic32_find_data_code_sections(void);

void pic32_create_data_init_template(void);

void pic32_create_data_init_section_lists(void);

void pic32_create_data_init_template (void);

void pic32_create_specific_fill_sections(void);

bfd * bfd_pic32_create_data_init_bfd
  (bfd *);

static void bfd_pic32_add_bfd_to_link
  (bfd *, const char *);

static void bfd_pic32_scan_data_section
  (asection *, PTR);

static void bfd_pic32_scan_code_section
  (asection *, PTR);

static void bfd_pic32_skip_data_section
  (asection *, PTR);

static void pic32_strip_sections
 (bfd *);
 
asection * bfd_pic32_create_section
  (bfd *, const char *, int, int);

/*static lghica - co-resident*/ void pic32m_append_section_to_list
  (struct pic32_section *, lang_input_statement_type *, asection *);

/*static*/ void pic32_free_section_list
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

struct pic32_memory* pic32_add_to_memory_list
  (struct pic32_memory *, bfd_vma, bfd_vma);

struct pic32_memory* pic32_add_shared_to_memory_list
  (struct pic32_memory *, bfd_vma, bfd_vma, asection* const);

void pic32_remove_from_memory_list
  (struct pic32_memory *, struct pic32_memory *);

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

static bfd_size_type bfd_pic32_collect_section_size
  (struct pic32_section *, const lang_memory_region_type *);

struct bfd_link_hash_entry *bfd_mchp_is_defined_global_symbol
  (const char *const);

static bfd_boolean bfd_pic32_undefine_one_symbol_bfd
  (struct bfd_link_hash_entry *, PTR);

static void bfd_pic32_undefine_symbols_bfd
  (bfd *);

static void bfd_mchp_remove_archive_module
  (const char *const);

static const char * bfd_pic32_lookup_magic_section_description
  (const char *, struct magic_sections_tag *, const char **);

struct bfd_link_hash_entry *bfd_pic32_is_defined_global_symbol
  (const char *const);

// coherent section processing functions

int coherent_section_count = 0;

void pic32_remove_coherent_group_from_section_list
  (struct pic32_section *, unsigned int);

#ifdef TARGET_IS_PIC32MX
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

#define PIC32_CORESIDENT (BSF_WEAK)

extern void bfd_pic32_clean_section_names
    (bfd *, asection *, PTR);


static void bfd_pic32_create_symbol
    (bfd *, char *, asection *, int, int);

static bfd * bfd_pic32_create_rom_usage_bfd
    (bfd *);

static bfd * bfd_pic32_create_ram_usage_bfd
    (bfd *);

static void bfd_pic32_pad_flash
    (void);

void pic32_create_shared_data_init_template(void);
void pic32_create_rom_usage_template(void);
void pic32_create_ram_usage_template(void);

int fill_section_count = 0;
int dinit_size = 0;

/* lghica - co-resident */
int pad_section_count = 0;

#endif

struct pic32_section *memory_region_list;
struct pic32_section *unassigned_sections;
struct pic32_section *alloc_section_list;
struct pic32_section *pic32_section_list;
extern void * bfd_alloc (bfd *, bfd_size_type);

/* defined in ldlang.c */
extern lang_statement_list_type statement_list;

/* defined in bfd/cpu-pic32m.c */
extern int pic32_is_serialmem_machine (const bfd_arch_info_type *);
extern int pic32_is_l1cache_machine (const bfd_arch_info_type *);

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

/* lghica co-resident */
extern struct pic32_section     *shared_data_sections;
extern struct pic32_section     *shared_dinit_sections;
extern bfd_vma                  inherited_shared_dinit_address;


/* lghica co-resident */
extern bfd              *init_shared_bfd;
extern unsigned char    *init_shared_data;
extern asection         *init_shared_template;

extern bfd              *rom_usage_bfd;
extern unsigned char    *rom_usage_data;
extern asection         *rom_usage_template;

extern bfd              *ram_usage_bfd;
extern unsigned char    *ram_usage_data;
extern asection         *ram_usage_template;


/* Symbol Tables */
static asymbol **symtab;
static int symptr;

/* lghica co-resident */
struct pic32_memory *shared_data_memory_blocks;

struct pic32_memory *free_blocks, *data_memory_free_blocks;

static bfd_boolean elf_link_check_archive_element
  (char *, bfd *, struct bfd_link_info *);

/* Declare functions used by various EXTRA_EM_FILEs.  */

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
static bfd_size_type external_memory_used = 0;
static bfd_size_type actual_serial_memory_used = 0;
static bfd_size_type region_serial_memory_used  = 0;
static bfd_size_type total_serial_memory = 0;


/* User-defined memory regions */
bfd_boolean has_user_defined_memory = FALSE;
const char *memory_region_prefix = "__memory_";
struct pic32_section *memory_region_list;
struct pic32_section *user_memory_sections;

/* Section Lists */
struct pic32_section *pic32_section_list;
struct pic32_section *unassigned_sections;

void
mips_after_parse (void)
{
  /* .gnu.hash and the MIPS ABI require .dynsym to be sorted in different
     ways.  .gnu.hash needs symbols to be grouped by hash code whereas the
     MIPS ABI requires a mapping between the GOT and the symbol table.  */
  if (link_info.emit_gnu_hash)
    {
      einfo ("%X%P: .gnu.hash is incompatible with the MIPS ABI\n");
      link_info.emit_hash = TRUE;
      link_info.emit_gnu_hash = FALSE;
    }
  if (pic32_coresident_app)
    link_info.allow_multiple_definition = TRUE;

  /* MERGE-NOTES: call default after_parse as expected when renaming
     the LDEMUL_AFTER_PARSE hook. */
  emultempl_after_parse ();
}

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
	  if (info->input_section == NULL
	      || l->input_section.section == info->input_section)
	    {
	      /* We've found our section.  Insert the stub immediately
		 before its associated input section.  */
	      *lp = info->add.head;
	      *(info->add.tail) = l;
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

/* Create a new stub section called STUB_SEC_NAME and arrange for it to
   be linked in OUTPUT_SECTION.  The section should go at the beginning of
   OUTPUT_SECTION if INPUT_SECTION is null, otherwise it must go immediately
   before INPUT_SECTION.  */

static asection *
mips_add_stub_section (const char *stub_sec_name, asection *input_section,
		       asection *output_section)
{
  asection *stub_sec;
  flagword flags;
  const char *secname;
  lang_output_section_statement_type *os;
  struct hook_stub_info info;

  /* PR 12845: If the input section has been garbage collected it will
     not have its output section set to *ABS*.  */
  if (bfd_is_abs_section (output_section))
    return NULL;

  /* Create the stub file, if we haven't already.  */
  if (stub_file == NULL)
    {
      stub_file = lang_add_input_file ("linker stubs",
				       lang_input_file_is_fake_enum,
				       NULL);
      stub_bfd = bfd_create ("linker stubs", link_info.output_bfd);
      if (stub_bfd == NULL
	  || !bfd_set_arch_mach (stub_bfd,
				 bfd_get_arch (link_info.output_bfd),
				 bfd_get_mach (link_info.output_bfd)))
	{
	  einfo ("%F%P: can not create BFD %E\n");
	  return NULL;
	}
      stub_bfd->flags |= BFD_LINKER_CREATED;
      stub_file->the_bfd = stub_bfd;
      ldlang_add_file (stub_file);
    }

  /* Create the section.  */
  stub_sec = bfd_make_section_anyway (stub_bfd, stub_sec_name);
  if (stub_sec == NULL)
    goto err_ret;

  /* Set the flags.  */
  flags = (SEC_ALLOC | SEC_LOAD | SEC_READONLY | SEC_CODE
	   | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP);
  if (!bfd_set_section_flags (stub_bfd, stub_sec, flags))
    goto err_ret;

  /* Create an output section statement.  */
  secname = bfd_get_section_name (output_section->owner, output_section);
  os = lang_output_section_find (secname);

  /* Initialize a statement list that contains only the new statement.  */
  lang_list_init (&info.add);
  lang_add_section (&info.add, stub_sec, NULL, os);
  if (info.add.head == NULL)
    goto err_ret;

  /* Insert the new statement in the appropriate place.  */
  info.input_section = input_section;
  if (hook_in_stub (&info, &os->children.head))
    return stub_sec;

 err_ret:
  einfo ("%X%P: can not make stub section: %E\n");
  return NULL;
}

/* This is called before the input files are opened.  */

void
mips_create_output_section_statements (void)
{
  struct elf_link_hash_table *htab;

  htab = elf_hash_table (&link_info);
  if (is_elf_hash_table (htab) && is_mips_elf (link_info.output_bfd))
  /*MERGE-NOTES: to be double-checked that we can use TRUE as last arg*/
    _bfd_mips_elf_linker_flags (&link_info, insn32, eh_reloc_type, TRUE);

  if (is_mips_elf (link_info.output_bfd))
    _bfd_mips_elf_init_stubs (&link_info, mips_add_stub_section);
}

/* This is called after we have merged the private data of the input bfds.  */

void
mips_before_allocation (void)
{
  flagword flags;

  flags = elf_elfheader (link_info.output_bfd)->e_flags;
  if (!link_info.shared
      && !link_info.nocopyreloc
      && (flags & (EF_MIPS_PIC | EF_MIPS_CPIC)) == EF_MIPS_CPIC)
    _bfd_mips_elf_use_plts_and_copy_relocs (&link_info);

  emultempl_before_allocation ();
}

/* Avoid processing the fake stub_file in vercheck, stat_needed and
   check_needed routines.  */

static void (*real_func) (lang_input_statement_type *);

static void mips_for_each_input_file_wrapper (lang_input_statement_type *l)
{
  if (l != stub_file)
    (*real_func) (l);
}

void
mips_lang_for_each_input_file (void (*func) (lang_input_statement_type *))
{
  real_func = func;
  lang_for_each_input_file (&mips_for_each_input_file_wrapper);
}

#define lang_for_each_input_file mips_lang_for_each_input_file

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
    {{"kseg0_program_mem",
      "kseg0 Program-Memory Usage",
      "      Total kseg0_program_mem used"},
     {"kseg0_boot_mem",
      "kseg0 Boot-Memory Usage",
      "         Total kseg0_boot_mem used"},
     {"exception_mem",
      "Exception-Memory Usage ",
      "          Total exception_mem used"},
     {"kseg1_boot_mem",
      "kseg1 Boot-Memory Usage",
      "         Total kseg1_boot_mem used"}};

  struct region_report_tag dmregions_to_report[] =
    {{"kseg0_data_mem",
      "Data-Memory Usage",
      "         Total kseg0/kseg1 data_mem used"},
      {"kseg1_data_mem",
      "Data-Memory Usage",
      "         Total kseg0/kseg1 data_mem used"}
    };

  /* clear the counters */
  actual_prog_memory_used = 0;
  data_memory_used = 0;
  region_prog_memory_used = 0;
  region_data_memory_used = 0;
  total_data_memory = total_prog_memory = 0;
  actual_serial_memory_used = 0;
  region_serial_memory_used  = 0;
  total_serial_memory = 0;
  
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
     region = region_lookup(pmregions_to_report[region_index].name);

     /* print code header */
     fprintf( fp, "\n\n%s\n", pmregions_to_report[region_index].title);
     fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
     fprintf( fp, "-------                 ----------  -------------------------  -----------\n");
     /* report code sections */
     for (s = pic32_section_list; s != NULL; s = s->next)
       if (s->sec && !strstr(s->sec->name, "fill$"))
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

  /* SERIAL MEMORY */
  if (lang_memory_region_exist("serial_mem") &&
      pic32_is_serialmem_machine(global_PROCESSOR)) {

    region = region_lookup("serial_mem");

    /* print serial header */
    fprintf( fp, "\n\nSerial Memory Usage\n");
    fprintf( fp, "section                    address  length [bytes]      (dec)  Description\n");
    fprintf( fp, "-------                 ----------  -------------------------  -----------\n");
    /* report serial-mem sections */
    for (s = pic32_section_list; s != NULL; s = s->next)
      if (s->sec)
      {
        region_serial_memory_used += bfd_pic32_report_sections (s, region, &magic_pm,fp);
      }
  fprintf (fp, "\n        --------------------------------------------------------------------------\n");
    fprintf( fp, "         Total Serial Memory Used  :  %#10lx  %10ld  ",
            (unsigned long)region_serial_memory_used, (unsigned long)region_serial_memory_used);
    report_percent_used(region_serial_memory_used,region->length, fp);
  fprintf (fp, "\n        --------------------------------------------------------------------------\n");
  }

  /* DATA MEMORY */

  region_count = sizeof(dmregions_to_report)/sizeof(dmregions_to_report[0]);
  magic_dm.count = sizeof(magic_dmdescriptions)/sizeof(magic_dmdescriptions[0]);
  magic_dm.start = magic_dm.index = 0;
  for (region_index = 0; region_index < region_count; region_index++)
  {
     if (!lang_memory_region_exist(dmregions_to_report[region_index].name))
       continue;
         
     region = region_lookup(dmregions_to_report[region_index].name);
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
  fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", "stack",
             (unsigned long)stack_base, (unsigned long)(stack_limit-stack_base),
             (unsigned long)(stack_limit-stack_base), "Reserved for stack");
  fprintf( fp, "\n        --------------------------------------------------------------------------\n");
  

  /* 
     Report user-defined memory sections...
     They require some extra effort to organize by
     external memory region 
   */
   
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

  fflush (fp);
#undef NAME_MAX_LEN
#undef NAME_FIELD_LEN
} /* static void bfd_pic32_report_memory_usage (...)*/


void pic32_report_crypto_sections()
{
   FILE *crypto;
   struct pic32_section *s;
   char *c;
   crypto = fopen(crypto_file, "w");
   if (!crypto){
     fprintf(stderr,"Error: crypto output file cannot be opened.\n");
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
}

void bfd_pic32_memory_summary(char *arg) 
{
  FILE *memory_summary_file;
  
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
    {{"kseg0_program_mem",
      "kseg0 Program-Memory Usage",
      "      Total kseg0_program_mem used"},
     {"kseg0_boot_mem",
      "kseg0 Boot-Memory Usage",
      "         Total kseg0_boot_mem used"},
     {"exception_mem",
      "Exception-Memory Usage ",
      "          Total exception_mem used"},
     {"kseg1_boot_mem",
      "kseg1 Boot-Memory Usage",
      "         Total kseg1_boot_mem used"}};

  struct region_report_tag dmregions_to_report[] =
    {{"kseg0_data_mem",
      "kseg0 Data-Memory Usage",
      "         Total kseg0_data_mem used"},
      {"kseg1_data_mem",
      "kseg1 Data-Memory Usage",
      "         Total kseg1_data_mem used"}
    };


  memory_summary_file = fopen (arg, "w");
   
  if (memory_summary_file == NULL){
     fprintf(stderr,"Warning: Could not open %s.\n", arg );
     return;
   }
  else {
     /*Calculate and output memory summary file*/

     /* clear the counters */
     actual_prog_memory_used = 0;
     data_memory_used = 0;
     region_prog_memory_used = 0;
     region_data_memory_used = 0;
     total_data_memory = total_prog_memory = 0;
  
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

        region = region_lookup(pmregions_to_report[region_index].name);

        /* collect code sections */
        for (s = pic32_section_list; s != NULL; s = s->next)
          if (s->sec && !strstr(s->sec->name, "fill$"))
          {
            region_prog_memory_used += bfd_pic32_report_sections(s, region, NULL, NULL);
          }
 
        total_prog_memory += region->length;
        actual_prog_memory_used += region_prog_memory_used;
        region_prog_memory_used = 0;
     }
 
 
     /* DATA MEMORY */
 
     region_count = sizeof(dmregions_to_report)/sizeof(dmregions_to_report[0]);
     magic_dm.count = sizeof(magic_dmdescriptions)/sizeof(magic_dmdescriptions[0]);
     magic_dm.start = magic_dm.index = 0;
     for (region_index = 0; region_index < region_count; region_index++)
     {
        if (!lang_memory_region_exist(dmregions_to_report[region_index].name))
          continue;
          
        region = region_lookup(dmregions_to_report[region_index].name);
 
        /* collect data sections */
        for (s = pic32_section_list; s != NULL; s = s->next)
          if (s->sec)
          {
            region_data_memory_used += bfd_pic32_report_sections (s, region, NULL, NULL);
          }
 
        total_data_memory += region->length;
        data_memory_used += region_data_memory_used;
        region_data_memory_used = 0;
     }

     /*Do not change the output xml format as it might throw the IDE off*/

     fprintf( memory_summary_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?> \n");
     fprintf( memory_summary_file, "<project>                                  \n");
     fprintf( memory_summary_file, "  <executable name=\"%s\">                 \n",
                                                          output_filename ); 
     fprintf( memory_summary_file, "    <memory name=\"program\">                 \n");
     fprintf( memory_summary_file, "      <units>bytes</units>                 \n");
     fprintf( memory_summary_file, "      <length>%ld</length>                 \n",
                                          (unsigned long)total_prog_memory);
     fprintf( memory_summary_file, "      <used>%ld</used>                     \n",
                                    (unsigned long)actual_prog_memory_used);
     fprintf( memory_summary_file, "      <free>%ld</free>                     \n",
              (unsigned long)(total_prog_memory - actual_prog_memory_used));
     fprintf( memory_summary_file, "    </memory>                              \n");
     fprintf( memory_summary_file, "    <memory name=\"data\">              \n");
     fprintf( memory_summary_file, "      <units>bytes</units>                 \n");
     fprintf( memory_summary_file, "      <length>%ld</length>                 \n",
                                          (unsigned long)total_data_memory);
     fprintf( memory_summary_file, "      <used>%ld</used>                     \n",
                                          (unsigned long)data_memory_used );
     fprintf( memory_summary_file, "      <free>%ld</free>                     \n",
                     (unsigned long)(total_data_memory - data_memory_used));
     fprintf( memory_summary_file, "    </memory>                              \n");
     fprintf( memory_summary_file, "  </executable>                            \n");
     fprintf( memory_summary_file, "</project>                                 \n");
  
     fclose(memory_summary_file);
  }
}

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

      n = c2 ? (unsigned int) (c2 - c1) : strlen(c1);
      if (strncmp(c1, sect->name, n) == 0) {
        char *c, *name = xmalloc(strlen(sect->name) + 1);
        strcpy(name, sect->name);  /* make a local copy of the name */
        c = strchr(name, '%');
        if (c) *c = '\0';   /* remove the %n terminator */
        
        fprintf( fp, "%-24s%#10lx     %#10lx  %10ld \n", name, start, total, total);
 
        external_memory_used += total;
        free(name);
        break;
      }
    }
  }
  return;
} /* static void bfd_pic32_report_memory_sections (...)*/

/*
** Utility routine: bfd_pic32_collect_section_size()
**
** - calculate memory usage of SEC_ALLOC-flagged sections in memory
*/
static bfd_size_type
bfd_pic32_collect_section_size (s, region )
     struct pic32_section *s;
     const lang_memory_region_type *region;
{
  bfd_size_type region_used = 0;
  unsigned long start = s->sec->vma;
  unsigned long load  = s->sec->lma;
  unsigned long actual = s->sec->size;

  if (PIC32_IS_COHERENT_ATTR(s->sec)) {
    start &= 0xbfffffff;
    load &= 0xbfffffff;
  }
    
  /*
  ** report SEC_ALLOC sections in memory
  */
  if ((s->sec->flags & SEC_ALLOC)
  &&  (s->sec->size > 0))
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
       fprintf( fp, "%.1f%% of %#lx", percent, max);
     else
       fprintf( fp, "<1%% of %#lx", max);
   }
}

/*
** Return a pointer to bfd_link_hash_entry
** if a global symbol is defined;
** else return zero.
*/
struct bfd_link_hash_entry *
bfd_mchp_is_defined_global_symbol (name)
     const char *const name;
{
    struct bfd_link_hash_entry *h;
    h = bfd_link_hash_lookup (link_info.hash, name, FALSE, FALSE, TRUE);
    if ((h != (struct bfd_link_hash_entry *) NULL) &&
        (h->type == bfd_link_hash_defined)) {
      return h;
    }
    else
      return (struct bfd_link_hash_entry *) NULL;
}


/*
** Undefine one symbol by BFD
**
** This routine is called by bfd_link_hash_traverse()
*/
static bfd_boolean
bfd_pic32_undefine_one_symbol_bfd (h, p)
     struct bfd_link_hash_entry *h;
     PTR p;
{
  struct bfd_link_hash_entry *H = (struct bfd_link_hash_entry *) h;
  struct traverse_hash_info *info = ( struct traverse_hash_info *) p;

  /* if this symbol is defined, and owned by the BFD in question */
  if ((( H->type == bfd_link_hash_defined) ||
       ( H->type == bfd_link_hash_defweak)) &&
      ( H->u.def.section->owner == info->abfd))

    /* mark it undefined */
    H->type = bfd_link_hash_undefined;

  /* traverse the entire hash table */
  return TRUE;
} /* static bfd_boolean bfd_pic32_undefine_one_symbol_bfd (...)*/


/*
** Undefine all symbols owned by a bfd
*/
static void
bfd_pic32_undefine_symbols_bfd (target)
     bfd *target;
{
    struct traverse_hash_info info;
    info.abfd = target;

    /* traverse the global linker hash table */
    bfd_link_hash_traverse (link_info.hash,
       bfd_pic32_undefine_one_symbol_bfd, &info);

} /* static void bfd_pic32_undefine_symbols_bfd (...) */

/*
** Remove an archive module
*/
static void
bfd_mchp_remove_archive_module (name)
     const char *const name;
{
  LANG_FOR_EACH_INPUT_STATEMENT (is)
  {
      if (strcmp (is->the_bfd->filename, name) == 0)
      {
	DEBUG({
	    LOG("\nRemoving %s\n", name);
	    LOG("  %s had %d symbols\n", name , is->the_bfd->symcount);
          });

          /*
          ** remove the symbols
          */
          bfd_pic32_undefine_symbols_bfd (is->the_bfd);
          is->the_bfd->symcount = 0;

          /*
          ** remove the sections in this bfd
          */
          bfd_section_list_clear(is->the_bfd);
          break;
      }
  }
} /* static void bfd_mchp_remove_archive_module */


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
    if (lst == NULL)
        return TRUE;

    if (lst->next == NULL)
        return TRUE;

    return FALSE;
}

#if 0
/*
** Create a new list
**
** - first item is null
*/
/*static*/ void
pic32_init_section_list(lst)
     struct pic32_section **lst;
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

#endif

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
		      new->sec->name, (unsigned int)new->sec->lma,
		      (unsigned int)new->sec->vma);
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
} /* static void pic32_build_section_list_vma (...) */

void
pic32_build_section_list (abfd, sect, fp)
     bfd *abfd ATTRIBUTE_UNUSED ;
     asection *sect;
     PTR fp ATTRIBUTE_UNUSED ;
{
  struct pic32_section *new, *s, *prev;
  int done = 0;

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
	  PIC32_DEBUG("pic32_build_section_list: Adding %s LMA:%x VMA:%x",
		      new->sec->name, (unsigned int)new->sec->lma,
		      (unsigned int)new->sec->vma);
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
** Search a section list by name
*/
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


/*
** region_lookup()
**
** Call this instead of lang_memory_region_lookup()
** if you want reasonable defaults set for the
** following regions:
**
** data
** program
**
** Note: Ideally, every linker script will include
** these definitions. But we don't want to fail
** if the user is running with a minimal script.
*/
#define NAME_IS(s) \
  ((strlen(name) == strlen(#s)) && \
           strcmp(name, (#s)) == 0)

lang_memory_region_type *
region_lookup( name )
     char * name;
{
  lang_memory_region_type *region;
  bfd_vma upper_limit = 0;
  int use_default = 0;

  region = lang_memory_region_lookup (name, FALSE);
  if (region->length == ~(bfd_size_type) 0) {
    if (NAME_IS(kseg0_program_mem)) {
      use_default = 1;
      region->origin = 0x9D000000;     /* works with 32MX320F512L */
      region->length = 0x80000;
      upper_limit    = (region->origin + region->length)-1;
    }
    else if (NAME_IS(kseg0_boot_mem)) {
      use_default = 1;
      region->origin = 0x9FC00490;     /* works with 32MX320F512L */
      region->length = 0x970;
      upper_limit    = (region->origin + region->length)-1;
    }
    else if (NAME_IS(exception_mem)) {
      use_default = 1;
      region->origin = 0x9FC01000;     /* works with 32MX320F512L */
      region->length = 0x1000;
      upper_limit    = (region->origin + region->length)-1;
    }
    else if (NAME_IS(kseg1_boot_mem)) {
      use_default = 1;
      region->origin = 0x9FC01000;     /* works with 32MX320F512L */
      region->length = 0x490;
      upper_limit    = (region->origin + region->length)-1;
    }
    else if (NAME_IS(kseg1_data_mem)) {
      use_default = 1;
      region->origin = 0xA0000000;     /* works with 32MX320F512L */
      region->length = 0x8000;
      upper_limit    = (region->origin + region->length)-1;
    }
    else if (NAME_IS(kseg0_data_mem)) {
      use_default = 1;
      region->origin = 0x80000000;     /* works with 32MX320F512L */
      region->length = 0x8000;
      upper_limit    = (region->origin + region->length)-1;
    }
    else
      einfo("Memory region %s does not exist\n", name);

    if (use_default) {
      einfo(_("%P: Warning: %s memory region not defined,"
              " using default range: 0x%v .. 0x%v\n"),
            name, region->origin, upper_limit);
      region->current = region->origin;
    }
  }

  return region;
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
  unsigned long actual = s->sec->output_section->size;
  size_t name_len = 0;

  if (PIC32_IS_COHERENT_ATTR(s->sec)) {
    start &= 0xbfffffff;
    load &= 0xbfffffff;
  }
    
  /*
  ** report SEC_ALLOC sections in memory
  */
  if ((s->sec->flags & SEC_ALLOC)
  &&  (s->sec->size > 0))
    {
      char *name, *c;
#define NAME_MAX_LEN 23
#define NAME_FIELD_LEN "24"
#define COH_ADDR    0x20000000
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

      if (((start|COH_ADDR) >= (region->origin|COH_ADDR)) &&
          (((start + actual)|COH_ADDR) <= ((region->origin + region->length)|COH_ADDR)))
      {
        if (fp != NULL)
        {
          bfd_pic32_lookup_magic_section_description (name, magic_sections, &description);
          fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", name,
                 start, actual, actual, description);
        }
        region_used = actual;
      }
      else if ((load >= region->origin) &&
          ((load + actual) <= (region->origin + region->length)) &&
           (s->sec->flags & (SEC_HAS_CONTENTS)))
      {
        if (fp != NULL)
        {
          bfd_pic32_lookup_magic_section_description (name, magic_sections, &description);
          fprintf( fp, "%-" NAME_FIELD_LEN "s%#10lx     %#10lx  %10ld  %s \n", name,
                  load, actual, actual, description);
        }
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
  struct pic32_symbol_list *pic32_symbol_list = NULL;

  /*
  ** check the input file name
  */
  if (!strcmp(abfd->filename, "sbrk.o"))
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
    if (pic32_symbol_list) {
      int c;
      for (c=0; c < pic32_symbol_list->pic32_symbol_count; c++) {
        if (strcmp(sec->name, pic32_symbol_list->syms[c].name) == 0)
          pic32_set_extended_attributes(sec, pic32_symbol_list->syms[c].value, 0);
      }
    }

    /* if section has HEAP attribute, record that fact */
    if (PIC32_IS_HEAP_ATTR(sec) && (sec->size > 0)) {
      if (heap_section_defined)
        einfo(_("%P%X: Error: Multiple heap sections defined\n"));
      else {
        heap_section_defined = TRUE;
        heap_bfd = sec->owner;
        if ((pic32_heap_size > 0) &&
            (pic32_heap_size != (sec->size)))
          einfo(_("%P%X: Error: Size of heap requested (%d bytes)"
                  " does not match heap defined in section \'%s\'"
                  "  (%d bytes)\n"), pic32_heap_size, sec->name,
                   sec->size );
      }
    }

    struct bfd_link_hash_entry *h;
    flagword old_flags = sec->flags;
    static unsigned int region_index = 0;
    const char *region_name = 0;

    /* If section represents a memory region, record it */

    if (PIC32_IS_INFO_ATTR(sec) &&
        strncmp(sec->name, memory_region_prefix, 
                strlen(memory_region_prefix)) == 0 &&
	strchr(sec->name, '@') == NULL) 
  {
      region_name = sec->name + strlen(memory_region_prefix);

      region_index++;
      h = bfd_pic32_is_defined_global_symbol(region_name);
      if (h == NULL) 
      {
	PIC32_DEBUG("  ..creating global symbol for user-defined memory %s",
		    region_name);

        _bfd_generic_link_add_one_symbol (info, abfd,
                                          region_name, BSF_GLOBAL,
                                          bfd_abs_section_ptr, region_index,
                                          region_name, 1, 0, 0);
      }
    }
    
    /* process input section flags here, if necessary */
    if ((sec->flags & (SEC_ALLOC | SEC_LOAD | SEC_DATA)) ==
         (SEC_ALLOC | SEC_LOAD | SEC_DATA))
      sec->flags |= SEC_HAS_CONTENTS;  /* elf linker needs this */

    /* report if flags were changed */
    if (sec->flags != old_flags)
      PIC32_DEBUG("   adjust flags: %s %x --> %x", sec->name, old_flags, sec->flags);

    if (PIC32_IS_INFO_ATTR(sec) &&
        strncmp(sec->name, memory_region_prefix, 
                strlen(memory_region_prefix)) == 0 &&
	strchr(sec->name, '@') != NULL) 
    {
 	char *ext_mem_sec_region_name = xstrdup(sec->name);
 	size_t ext_mem_sec_region_len = strlen(ext_mem_sec_region_name);
 	
	const char *atdelim = strchr(ext_mem_sec_region_name,'@');
	
	int atdelim_index  = 0;
 	int mem_prefix_len = 0;
 	
	atdelim_index  = (int) (atdelim - ext_mem_sec_region_name) ;
	mem_prefix_len = strlen(memory_region_prefix);
	
	int ext_sec_name_len = 0 ;
	int ext_reg_name_len = 0 ;

	ext_reg_name_len = atdelim_index - mem_prefix_len;
	ext_sec_name_len = ext_mem_sec_region_len - atdelim_index - 1 ;

	char *region_name_tmp = xmalloc(ext_reg_name_len+1);
	strncpy(region_name_tmp, ext_mem_sec_region_name+mem_prefix_len, ext_reg_name_len);
	region_name_tmp[ext_reg_name_len] = '\0';
	
	char *sec_name    = xmalloc(ext_sec_name_len+1);
	strncpy(sec_name, ext_mem_sec_region_name+atdelim_index+1, ext_sec_name_len);
	sec_name[ext_sec_name_len] = '\0';

        pic32m_append_section_to_list (user_memory_sections,
                                       (lang_input_statement_type *) region_name_tmp,
                                       (asection *) sec_name);

	free(ext_mem_sec_region_name); 
    }
  }
  if (symbols)
	free(symbols);
  if (pic32_symbol_list) {
	free(pic32_symbol_list->syms);
	free(pic32_symbol_list);
  }
  return(TRUE);
 }
}

/*
** Create a bfd for the data init template
**
** Uses the following global variables:
**   symtab
**   symptr
*/
bfd *
bfd_pic32_create_data_init_bfd (parent)
     bfd *parent ATTRIBUTE_UNUSED;
{
  bfd_size_type size;
  bfd *abfd;
  asection *sec;
  char *oname;
  int flags, align;

  /* create a bare-bones bfd */
  oname = (char *) bfd_alloc (link_info.output_bfd, 20);
  snprintf (oname, 20, "data_init");
  abfd = bfd_create (oname, parent);
  bfd_find_target (EMULTEMPL.output_format, abfd);
  bfd_make_writable (abfd);

  bfd_set_format (abfd, bfd_object);
  bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

  /* create a symbol table (room for 1 entry) */
  symptr = 0;
  symtab = (asymbol **) bfd_alloc (link_info.output_bfd, 2 * sizeof (asymbol *));

  /*
  ** create a bare-bones section for .dinit
  */
  flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP |
          SEC_LINKER_CREATED | SEC_ALLOC | SEC_READONLY;
  align = 2; /* 2^2 */
  sec = bfd_pic32_create_section (abfd, ".dinit", flags, align);
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

/* lghica - co-resident */

static bfd *
bfd_pic32_create_shared_data_init_bfd (bfd *parent ATTRIBUTE_UNUSED)
{
    bfd_size_type       size;
    bfd                 *abfd;
    asection            *sec;
    struct pic32_section *s;
    char                *oname;
    int                 flags, align;

    /* create a bare-bones bfd */
    oname = (char *) bfd_alloc (link_info.output_bfd, 20);
    sprintf (oname, "shared_data_init");
    abfd = bfd_create (oname, parent);
    bfd_find_target (EMULTEMPL.output_format, abfd);
    bfd_make_writable (abfd);

    bfd_set_format (abfd, bfd_object);
    bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

    /* create a symbol table (room for 1 entry) */
    symptr = 0;
#if 0
    if (pic32_inherit_application_info)
        symtab = (asymbol **) bfd_alloc (link_info.output_bfd, 2*sizeof (asymbol *));
    else
#endif
    symtab = (asymbol **) bfd_alloc (link_info.output_bfd, sizeof (asymbol *));

    /*
    ** create a bare-bones section for .shared.dinit
    */
    flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP | SEC_READONLY;
    align = 1; /* 2^1 */
    sec = bfd_pic32_create_section (abfd, ".shared.dinit", flags, align);
    size = 0; /* will update later */
    bfd_set_section_size (abfd, sec, size);

    /* allocate .shared.dinit at the same address where previous .shared.dinit
    was allocated */
    if (pic32_inherit_application_info)
    {
        for (s = inherited_sections; s!= NULL; s = s->next)
        {
            if (s->sec && strcmp(s->sec->name, ".shared.dinit") == 0)
            {
                PIC32_SET_ABSOLUTE_ATTR(sec);
                bfd_set_section_vma(abfd, sec, s->sec->vma);
            }
        }
    }

#if 0 /* Keeping this in case it is needed */
    if (pic32_exclude_application) {
        flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP | SEC_READONLY;
        align = 1; /* 2^1 */
        sec = bfd_pic32_create_section (abfd, ".shared.dinit$", flags, align);
        size = 4;
        bfd_set_section_size (abfd, sec, size);
        for (s = inherited_sections; s!= NULL; s = s->next)
        {
            if (s->sec && strcmp(s->sec->name, ".shared.dinit") == 0)
                inherited_shared_dinit_address = sec->vma = sec->lma = s->sec->vma;
        }
        PIC32_SET_ABSOLUTE_ATTR(sec);
    }
#endif

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
}



static bfd *
bfd_pic32_create_rom_usage_bfd (parent)
    bfd *parent ATTRIBUTE_UNUSED;
{
    bfd_size_type   size;
    bfd             *abfd;
    asection        *sec;
    char            *oname;
    int             flags, align;

    LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
        for (sec = f->the_bfd->sections;
                sec != (asection *) NULL;
                sec = sec->next)
            if (strcmp(sec->name,".rom_usage") == 0)
                sec->flags |= SEC_EXCLUDE;
    }

    /* create a bare-bones bfd */
    oname = (char *) bfd_alloc (link_info.output_bfd, 20);
    sprintf (oname, "rom_usage_bfd");
    abfd = bfd_create (oname, parent);
    bfd_find_target (EMULTEMPL.output_format, abfd);
    bfd_make_writable (abfd);

    bfd_set_format (abfd, bfd_object);
    bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

    /* create a symbol table (room for 1 entry) */
    symptr = 0;
    symtab = (asymbol **) bfd_alloc (link_info.output_bfd, sizeof (asymbol *));

    /*
    ** create a bare-bones section for .rom_usage
    */
    flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP;
    align = 1; /* 2^1 */
    sec = bfd_pic32_create_section (abfd, ".rom_usage", flags, align);
    size = 0; /* will update later */
    bfd_set_section_size (abfd, sec, size);

    /* create global label at offset zero */
    bfd_pic32_create_symbol (abfd, "__ROM_USAGE", sec,
                        BSF_GLOBAL | BSF_WEAK, 0);

    /* put in the symbol table */
    bfd_set_symtab (abfd, symtab, symptr);

    /* will add section contents later */

    /* finish it */
    if (!bfd_make_readable (abfd))
    {
        fprintf( stderr, "Link Error: can't make rom usage readable\n");
        abort();
    }

    return abfd;
}   /* end of bfd_pic32_create_rom_usage_bfd */

static bfd *
bfd_pic32_create_ram_usage_bfd (parent)
    bfd *parent ATTRIBUTE_UNUSED;
{
    bfd_size_type   size;
    bfd             *abfd;
    asection        *sec;
    char            *oname;
    int             flags, align;

    LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
        for (sec = f->the_bfd->sections;
                    sec != (asection *) NULL;
                    sec = sec->next)
            if (strcmp(sec->name,".ram_usage") == 0)
                sec->flags |= SEC_EXCLUDE;
    }

    /* create a bare-bones bfd */
    oname = (char *) bfd_alloc (link_info.output_bfd, 20);
    sprintf (oname, "ram_usage_bfd");
    abfd = bfd_create (oname, parent);
    bfd_find_target (EMULTEMPL.output_format, abfd);
    bfd_make_writable (abfd);

    bfd_set_format (abfd, bfd_object);
    bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

    /* create a symbol table (room for 1 entry) */
    symptr = 0;
    symtab = (asymbol **) bfd_alloc (link_info.output_bfd, sizeof (asymbol *));

    /*
    ** create a bare-bones section for .ram_usage
    */
    flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP;
    align = 1; /* 2^1 */
    sec = bfd_pic32_create_section (abfd, ".ram_usage", flags, align);
    size = 0; /* will update later */
    bfd_set_section_size (abfd, sec, size);

    /* create global label at offset zero */
    bfd_pic32_create_symbol (abfd, "__RAM_USAGE", sec,
    BSF_GLOBAL | BSF_WEAK, 0);

    /* put in the symbol table */
    bfd_set_symtab (abfd, symtab, symptr);

    /* will add section contents later */

    /* finish it */
    if (!bfd_make_readable (abfd))
    {
        fprintf( stderr, "Link Error: can't make ram usage readable\n");
        abort();
    }

    return abfd;
}   /* end of bfd_pic32_create_ram_usage_bfd */

void
pic32_find_data_code_sections(void)
{
  /*
   * Loop through all input sections and
   * build a list of DATA or BSS type.
   */
  asection * sec;
  LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
      for (sec = f->the_bfd->sections;
           sec != (asection *) NULL;
           sec = sec->next)
        if (((sec->size > 0) && (sec->linked == 0) && (PIC32_IS_DATA_ATTR(sec)))
            || (PIC32_IS_BSS_ATTR(sec)) || PIC32_IS_RAMFUNC_ATTR(sec)
            || ((sec->size > 0) && (PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR(sec)))
            || (PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR(sec)))
          {
          /* fix for xc32-146 */
          if (PIC32_IS_DATA_ATTR(sec) &&
              (strcmp(sec->name, ".rodata") == 0)) {
            sec->flags &= ~SEC_DATA;
            PIC32_SET_CODE_ATTR(sec);
            if (sec->owner->my_archive) {
              einfo(_("%P: Warning: %s of %s needs to be compiled"
                      " with MPLAB XC32.\n"),
                      sec->owner->filename, sec->owner->my_archive->filename);
            }
            else {
              einfo(_("%P: Warning: %s needs to be compiled"
                      " with MPLAB XC32.\n"), sec->owner->filename);
            }
          }
          else
          {
            if ((sec->shared == 1) && (sec->linked == 0))
              pic32m_append_section_to_list(shared_data_sections, f, sec);
            else
              pic32m_append_section_to_list(data_sections, f, sec);
          }
        }
       else if ((sec->size > 0) && PIC32_IS_CODE_ATTR(sec))
         pic32m_append_section_to_list(code_sections, f, sec);
    }
}

void
pic32_create_data_init_section_lists(void)
{
  /* init list of input data sections */
  pic32_init_section_list(&data_sections);

  /* lghica co-resident */
  pic32_init_section_list(&shared_data_sections);
  pic32_init_section_list(&shared_dinit_sections);

  /* init list of input code sections */
  pic32_init_section_list(&code_sections);
}

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

  if (pic32_data_init)
    {
      init_bfd = bfd_pic32_create_data_init_bfd (link_info.output_bfd);
      bfd_pic32_add_bfd_to_link (init_bfd, init_bfd->filename);

      /* Compute size of data init template */
      for (s = data_sections; s != NULL; s = s->next)
        if ((s->sec) && ((s->sec->flags & SEC_EXCLUDE) == 0))
          bfd_pic32_scan_data_section(s->sec, &total_data);

      if (pic32_code_in_dinit) {
        for (s = code_sections; s != NULL; s = s->next) {
          if ((s->sec) && ((s->sec->flags & SEC_EXCLUDE) == 0))
            bfd_pic32_scan_code_section(s->sec, &total_data);
        }
      }

      total_data += 4; /* zero terminated */

      ///\ reserve space for entry_address
      if (pic32_code_in_dinit)
        total_data += 4;

      ///\ reserve space for pointer to shared.dinit
      if ((shared_data_sections != NULL) && (shared_data_sections->sec != NULL))
        total_data +=8;

      if (total_data % 16)
        init_data_padding += 16 - (total_data % 16);
      total_data += init_data_padding;

      dinit_size = total_data;

      PIC32_DEBUG("optim_dinit dinit_size %d", total_data);

      /* allocate memory for the template */
      init_data = (unsigned char *) bfd_alloc (link_info.output_bfd,
                                               total_data);
      if (!init_data)
        {
          fprintf( stderr, "Link Error: not enough memory for data template\n");
          abort();
        }

      /* fill the template with a default value */
      init_data = memset( init_data, 0x11, total_data);

      /* attach it to the input section */
      sec = bfd_get_section_by_name(init_bfd, ".dinit");
      if (sec)
        {
          sec->size = total_data;
          sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD |
                         SEC_CODE | SEC_KEEP | SEC_READONLY);
          sec->contents = init_data;
          bfd_set_section_size (init_bfd, sec, total_data);
          init_template = sec;  /* save a copy for later */

          if (pic32_dinit_has_absolute_address)
            {
              bfd_set_section_vma(init_bfd, sec, dinit_address);
              PIC32_SET_ABSOLUTE_ATTR(sec);
            }
          if (pic32_dinit_in_serial_mem)
            {
              PIC32_SET_SERIAL_MEM_ATTR(sec);
              sec->flags &= ~(SEC_CODE | SEC_READONLY);

              char *name;
              char *ext_attr_prefix = "__ext_attr_";

              name = xmalloc (strlen(sec->name) + strlen(ext_attr_prefix) + 1);
              (void) sprintf(name, "%s%s", ext_attr_prefix, sec->name);
              _bfd_generic_link_add_one_symbol (&link_info,
                                                link_info.output_bfd, name,
                                                PIC32_CORESIDENT /*BSF_GLOBAL*/,
                                                bfd_abs_section_ptr,
                                                pic32_extended_attribute_map(sec),
                                                name, 1, 0, 0);
            }
        }
      else
	PIC32_DEBUG("after_open: section .dinit not found");
    }
  else /* if (pic32_data_init) */
    {
      /* warn if initial data values will be ignored */
      for (s = data_sections; s != NULL; s = s->next)
        if (s->sec)
          bfd_pic32_skip_data_section(s->sec, &total_data);
    }
}

/*
** Create a bfd for the stack
**
** Uses the following global variables:
**   symtab
**   symptr
**   pic32_stack_size
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
  bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

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

/* This is called after all the input files have been opened.  */
void
pic32_after_open(void)
{
  lang_output_section_statement_type* os;

  os = lang_output_section_statement_lookup (".bev_excpt", 0, FALSE);

  if (pic32_coresident_app != 0)
    {
      ///\ remove section
      if (os!= NULL)
        {
	  if (os->bfd_section == NULL)
            {
	      os->bfd_section = bfd_make_section_anyway_with_flags(link_info.output_bfd, ".bev_excpt", SEC_EXCLUDE);
	      ///\ reset region
	      os->region = NULL;
            }
	  else
	    os->bfd_section->flags |= SEC_EXCLUDE;
        }
    }


  /*
  ** Merge full- and reduced-set I/O functions
  */
  if (pic32_smart_io)
    {
      PIC32_DEBUG("\nMerging smart-io functions:");

      smartio_merge_symbols ();

    } /* pic32_smart_io */

  /*
  ** For PIC, don't invoke the best-fit allocator.
  */
  if (link_info.shared || link_info.pie)
    pic32_allocate = FALSE;

  emultempl_after_open();

  /* Prepare a list for sections in user-defined regions */
  if (user_memory_sections)
    pic32_free_section_list(&user_memory_sections);
  pic32_init_section_list(&user_memory_sections);

  {
    /* loop through all of the input bfds */
    LANG_FOR_EACH_INPUT_STATEMENT (is)
      {
        if (!bfd_pic32_process_bfd_after_open(is->the_bfd, &link_info))
          {
            einfo("Errors encountered processing file %s\n", is->filename);
          }
      }
  }

  /*
  ** If a heap is required, but not provided
  ** as an input section, create one.
  **
  ** FIXME: may want to test pic32_stack_required
  ** and create a default size stack
  */
  if (!((link_info.shared || link_info.pie)) && 
      !stack_section_defined && (pic32_stack_size > 0)) {
    PIC32_DEBUG("\nCreating stack of size %x", pic32_stack_size);
    stack_bfd = bfd_pic32_create_stack_bfd (link_info.output_bfd);
    bfd_pic32_add_bfd_to_link (stack_bfd, stack_bfd->filename);
    stack_section_defined = TRUE;
  }
}


/******************************************
* STACK USAGE ESTIMATION                  *
*******************************************/

/*
* Stack Usage Estimation
*   check if r_type corresponds to a call semantic
*/
bfd_boolean is_call_reloc(unsigned int r_type)
{
    if (   (r_type == (unsigned int) R_MIPS_LO16)
        || (r_type == (unsigned int) R_MIPS_HI16)
        || (r_type == (unsigned int) R_MIPS_CALL16)
        || (r_type == (unsigned int) R_MIPS_CALL_HI16)
        || (r_type == (unsigned int) R_MIPS_CALL_LO16)
        || (r_type == (unsigned int) R_MIPS16_CALL16)
        || (r_type == (unsigned int) R_MICROMIPS_CALL16)
        || (r_type == (unsigned int) R_MICROMIPS_CALL_HI16)
        || (r_type == (unsigned int) R_MICROMIPS_CALL_LO16)
        || (r_type == (unsigned int) R_MICROMIPS_HI16)
        || (r_type == (unsigned int) R_MICROMIPS_LO16)
        || (r_type == (unsigned int) R_MIPS_26)
        || (r_type == (unsigned int) R_MIPS_PC16)
        || (r_type == (unsigned int) R_MIPS_PC21_S2)
        || (r_type == (unsigned int) R_MIPS_PC26_S2)
        || (r_type == (unsigned int) R_MIPS16_26)
        || (r_type == (unsigned int) R_MIPS16_PC16_S1)
        || (r_type == (unsigned int) R_MICROMIPS_26_S1)
        || (r_type == (unsigned int) R_MICROMIPS_PC7_S1)
        || (r_type == (unsigned int) R_MICROMIPS_PC10_S1)
        || (r_type == (unsigned int) R_MICROMIPS_PC16_S1)
        || (r_type == (unsigned int) R_MICROMIPS_PC23_S2)
        || (r_type == (unsigned int) R_MIPS_GOT16)
/* to check */
        || (r_type == (unsigned int) R_MIPS_32)
        || (r_type == (unsigned int) R_MIPS_TLS_DTPMOD32)
        || (r_type == (unsigned int) R_MIPS_TLS_GD)
        || (r_type == (unsigned int) R_MIPS_TLS_LDM)
        || (r_type == (unsigned int) R_MIPS_TLS_TPREL_HI16)
        || (r_type == (unsigned int) R_MIPS_TLS_TPREL_LO16)
    )
        return TRUE;
    return FALSE;
}

int32_t
pic32_su_rel_addend (bfd               *abfd,
                     asection          *section,
                     Elf_Internal_Rela *irela,
                     Elf_Internal_Sym  *isym)
{
  int32_t word;
  bfd_boolean rc;

  switch (ELF32_R_TYPE (irela->r_info)) {
  case R_MIPS_26:
    /*
       local:    ( ( (A << 2) | (P & 0xf0000000) ) + S ) >> 2
       external: ( sign_extend (A << 2) + S ) >> 2
    */
    rc = bfd_get_section_contents (abfd, section, &word, irela->r_offset, 4);
    BFD_ASSERT (rc);

    word = (word << 2) & 0x0FFFFFFFF;

    /* sign-extend if not local */
    if (ELF32_ST_BIND (isym->st_info) != STB_LOCAL
        || ELF32_ST_TYPE (isym->st_info) == STT_SECTION)
      {
        word = word << 4 >> 4;
      }

    return word;

  case R_MIPS_32:
    rc = bfd_get_section_contents (abfd, section, &word, irela->r_offset, 4);
    BFD_ASSERT (rc);
    return word;

  default:
    return 0;
  }
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

/*
** finish()
**
** This function is called after symbol assignments
** are completed, but before relocations are resolved.
*/
void
pic32_finish(void)
{
  /* MERGE-NOTES: hopefully the final resting place for strip_sections.
     after lang_size_sections and allocation, before map_segments. */
  pic32_strip_sections (link_info.output_bfd);

  need_layout = bfd_elf_discard_info (link_info.output_bfd,
  				      &link_info);

  /* We need to map segments here so that we determine file positions for 
     sections added by best-fit-allocator */
  emultempl_map_segments (need_layout);

  if (!bfd_link_relocatable (&link_info))
    {
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

  finish_default();
} /* static void pic32_finish ()*/

/* Place an orphan section.  We use this to put random SHF_ALLOC
   sections in the right segment.  */

/* NB: the return type is only used here as NULL for failure,
   or non-NULL for success. The returned pointer is not usable otherwise. */
lang_output_section_statement_type *
pic32m_place_orphan (lang_input_statement_type *file,
		     asection *sec,
		     const char *secname ATTRIBUTE_UNUSED,
		     int constraint ATTRIBUTE_UNUSED)
{
    /* lghica co-resident */
    struct pic32_section *s;
    unsigned long was_placed = 0;

  if (pic32_allocate) {  /* if best-fit allocator enabled */

    /* if this section represents a memory region,
       we don't want it allocated or its relocations
       processed. */
    if ( PIC32_IS_INFO_ATTR(sec) &&
         strncmp(sec->name, memory_region_prefix, strlen(memory_region_prefix)) == 0 &&
         strchr(sec->name, '@') == NULL) {

      PIC32_DEBUG("LG - memory region - %s", sec->name);


      if (!memory_region_list)
        pic32_init_section_list(&memory_region_list);

      if (!pic32_name_in_section_list(memory_region_list, sec->name))
        pic32m_append_section_to_list(memory_region_list, file, sec);
      has_user_defined_memory = TRUE;
      return (lang_output_section_statement_type *) 1ul;
    }

   if (((sec->flags & SEC_DEBUGGING) == SEC_DEBUGGING)
        || ((sec->flags & SEC_ALLOC) == 0))
      return NULL; /* let the base code handle non-alloc sections */

    if (PIC32_IS_PRESERVED_ATTR(sec))
    {
        for (s = inherited_sections; s != NULL; s= s->next)
        {
            if (s->sec && (strcmp(sec->name, s->sec->name) == 0)
                    && (sec->rawsize == s->sec->rawsize))
            {
                PIC32_SET_ABSOLUTE_ATTR(sec);
                bfd_set_section_vma(sec->owner, sec, s->sec->vma);
            }
        }
    }


    if (!unassigned_sections)
      pic32_init_section_list(&unassigned_sections);

    pic32m_append_section_to_list(unassigned_sections, file, sec);

    return (lang_output_section_statement_type *) 1ul;  /* and exit */
  }

   return (lang_output_section_statement_type *) was_placed;
} /*static int gldelf32pic32mx_place_orphan () */

/*
** Append a section to a list
*/
/*static*/ void
pic32m_append_section_to_list (struct pic32_section *lst,
                              lang_input_statement_type *file,
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
  new->file = (PTR) file;
  new->dinit_type = -1;
  new->children = NULL;
  new->use_vma = 0;
  new->region = NULL;

  /* find the tail */
  for (s = lst; s != NULL; s = s->next)
    tail = s;

  tail->next = new;  /* add it */
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
pic32_print_section_list (lst, name)
     struct pic32_section *lst;
      const char *name;
{
  unsigned int opb = bfd_octets_per_byte (link_info.output_bfd);
  struct pic32_section *s, *prev, *next;

  LOG("\nContents of %s section list at %lx:\n", name, (bfd_vma) lst);
  prev = lst;
  for (s = prev; s != NULL; s = next)
    {
      next = s->next;
      LOG("  name = %s, addr = %lx, len = %lx, attr = %x\n",
             s->sec ? s->sec->name : "(none)",
             s->sec ? s->sec->lma : 0,
             s->sec ? s->sec->rawsize / opb : 0,
             s->attributes);
      prev = s;
    }
  LOG("\n");

} /* pic32_print_section_list (..) */

/*
** Add a node to a memory list
**  in order of increasing size
*/
struct pic32_memory*
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
    //new->section = NULL;

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
    return new;
} /* static struct pic32_memory* pic32_add_to_memory_list (..) */


/*
* add a memory region for shared sections to the list
*/
struct pic32_memory* pic32_add_shared_to_memory_list(
            struct pic32_memory *lst,
            bfd_vma addr, bfd_vma size,
            asection* const sec)
{
    struct pic32_memory *new, *b, *prev;
    int done = 0;

    /* create a new element */
    new = ((struct pic32_memory *) xmalloc(sizeof(struct pic32_memory)));
    new->addr  = addr;
    new->size  = size;
    new->offset = 0;
    //new->section = sec;

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
    return new;
}


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
void
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
    if (sec_address == 0)
        sec_address = b->addr;

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

  if (!(*lst))
    return;

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
** This routine is called by bfd_pic32_create_data_init_template().
**
** Scan a DATA or BSS section and accumulate
** the data template size.
*/
static void
bfd_pic32_scan_data_section (sect, p)
     asection *sect;
     PTR p;
{
#define DATA_RECORD_HEADER_SIZE 12

   int *data_size = (int *) p;

  if (p == (int *) NULL)
    return;

  /*
  ** skip persistent or noload data sections
  */
  if (PIC32_IS_PERSIST_ATTR(sect) || PIC32_IS_NOLOAD_ATTR(sect))
  {
      /*
      ** issue a warning if DATA values are present
      */
      if ((sect->flags & SEC_DATA) && (sect->size > 0) && (sect->linked == 1))
        einfo(_("%P: Warning: initial values were specified for a non-loadable"
                " data section (%s). These values will be ignored.\n"),
              sect->name);

      PIC32_DEBUG("  %s (skipped), size = %x bytes",
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
      PIC32_DEBUG("  %s (bss), size = %x bytes, template += %x bytes",
		  sect->name, (unsigned int) sect->size,
		  DATA_RECORD_HEADER_SIZE);
  }

  /*
  ** process DATA-type sections
  */
  if ((PIC32_IS_DATA_ATTR(sect) || PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR(sect) || PIC32_IS_RAMFUNC_ATTR(sect)) && (sect->size > 0))
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
      sect->flags &= ~ SEC_LOAD;

      PIC32_DEBUG("  %s (data), size = %x bytes, template += %x bytes",
		  sect->name, (unsigned int) sect->size, delta);
  }
} /*static void bfd_pic32_scan_data_section (...)*/

/*
** This routine is called by bfd_pic32_create_data_init_template().
**
** Scan a CODE  sections and accumulate
** the data template size.
*/
static void
bfd_pic32_scan_code_section (sect, p)
     asection *sect;
     PTR p;
{
#define DATA_RECORD_HEADER_SIZE 12

   int *data_size = (int *) p;

  if (p == (int *) NULL)
    return;

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
      sect->flags &= ~ SEC_LOAD;

      PIC32_DEBUG("  %s (data), size = %x bytes, template += %x bytes",
		  sect->name, (unsigned int) sect->size, delta);
  }
} /*static void bfd_pic32_scan_code_section (...)*/



/*
** This routine is called by before_allocation()
** when the --no-data-init option is specified.
**
** Scan for loadable DATA sections...if found,
** mark them NEVER_LOAD and issue a warning.
*/
static void
bfd_pic32_skip_data_section (sect, p)
     asection *sect;
     PTR p ATTRIBUTE_UNUSED ;
{
  /*
  ** process DATA-type sections
  */
  if (((sect->flags & SEC_DATA) == SEC_DATA) && (sect->size > 0))
  {
      /*
      ** make section not LOADable
      */
      sect->flags &= ~ SEC_LOAD;
      sect->flags |= SEC_NEVER_LOAD;

      /*
      ** issue a warning (unless the linker is called with "-r" to link together 
      ** the debug-info objects)
      */
      if (! bfd_link_relocatable (&link_info))
        einfo(_("%P: Warning: data initialization has been turned off,"
                " therefore section %s will not be initialized using .dinit template.\n"), sect->name);

      PIC32_DEBUG("  %s (skipped), size = %x",
		  sect->name, (unsigned int) sect->size);
  }
}

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

  PIC32_DEBUG("\nCreating input section \"%s\"", name);

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

static bfd_boolean is_debug_section(asection* const sec)
{
    if ((strstr(sec->name, "debug") != 0) &&
        ((sec->flags & SEC_LOAD) ==0))
        return TRUE;

return FALSE;
}

/*
*  mark sections as absolute and linked
*/
static void pic32_mark_linked_sections(bfd* abfd)
{
    asection *sec;

    for (sec = abfd->sections; sec != NULL; sec = sec->next)
    {
        if (((sec->size != 0) || (sec->rawsize != 0))
            && ((sec->flags & SEC_EXCLUDE) == 0)
            && ((sec->flags & SEC_LOAD) != 0))
        {
            PIC32_SET_ABSOLUTE_ATTR(sec);
            sec->linked = 1;
        }
        ///\ looking for non-loadable debug sections & mark them as linked
        ///\ for co-resident
        if (is_debug_section(sec))
        {
            sec->linked = 1;
        }
    }
}

/*
** Strip zero-length sections
*/
static void
pic32_strip_sections (abfd)
     bfd *abfd;
{
  asection *sec, *prev;

  PIC32_DEBUG("\nLooking for zero-length sections:");

  sec = abfd->sections;
  if ((sec == NULL) || (sec->next == NULL))
    return;

  sec = sec->next; /* never strip the first section */
  /* loop through the sections in this bfd */
  for (; sec != NULL; sec = sec->next)
    {
      /* don't touch the keep/linker created sections */
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


void
bfd_pic32_finish(void)
{
  struct bfd_link_hash_entry *h;
  asection *stack_sec;
  lang_output_section_statement_type *os;
  lang_memory_region_type *region;
  bfd_vma end_data_mem;

    /* lghica co-resident */
    char* alias_name = 0;

 /*
  ** remove output sections with size = 0
  */
/* MERGE-NOTES: it seems that this is too late; map_segments will die
  if we feed it zero-length sections, which have garbage flags. */
/*
  pic32_strip_sections(link_info.output_bfd);
*/

    /* lghica co-resident */
    if (pic32_application_id)
    {
        alias_name = xmalloc(1+ strlen(application_id) + 80);/* TODO check 80 */
    }

    ///\ lghica - coresident
    pic32_mark_linked_sections(link_info.output_bfd);

  /* if we've encountered a fatal error, stop here */
  if (config.make_executable == FALSE)
    einfo("%P%F: Link terminated due to previous error(s).\n");

// PIE SUPPORT

if (!(link_info.shared || link_info.pie)) 
{
  /* check for _min_stack_size symbol -- this is an old way to specify
     a stack, and is really not preferred */
  if ((h = bfd_pic32_is_defined_global_symbol("_min_stack_size"))) {
    if (pic32_has_stack_option && (h->u.def.value != pic32_stack_size))
      fprintf (stderr, "Warning: --stack option overrides _min_stack_size symbol\n");
    else
      pic32_stack_size = h->u.def.value;
  }

   /* if heap is required, make sure one is specified */
  if (pic32_heap_required && !heap_section_defined && !pic32_has_heap_option &&
      !bfd_pic32_is_defined_global_symbol("_min_heap_size"))
      einfo("%P%X Error: A heap is required, but has not been specified\n");

  /* check for _min_stack_size symbol -- this is an old way to specify
     a stack, and is really not preferred */
  if ((h = bfd_pic32_is_defined_global_symbol("_min_heap_size"))) {
    if (pic32_has_heap_option && (h->u.def.value != pic32_heap_size))
      fprintf (stderr, "Warning: --heap option overrides _min_heap_size symbol\n");
    else
      pic32_heap_size = h->u.def.value;
  }

  /*
  ** Check for user-defined stack
  **
  ** note: symbol (_stack) must be defined
  */
  if ((h = bfd_pic32_is_defined_global_symbol("_stack"))) {
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
  if (!user_defined_stack) {
    allocate_default_stack();

    /* lghica co-resident */
#define link_add_one_symbol(link_info, output_bfd, name, \
                            type, section, heap_base, name2, a,b,c) \
    _bfd_generic_link_add_one_symbol(link_info, output_bfd, name, \
                            type, section, heap_base, name2, a,b,c); \
    if (pic32_application_id) { \
        (void)sprintf(alias_name, "_%s%s", application_id, name); \
        _bfd_generic_link_add_one_symbol(link_info, output_bfd, alias_name, \
                            type, section, heap_base, alias_name, a,b,c); \
    }


  /*
  ** Set stack symbols for the runtime library
  */
      PIC32_DEBUG("Creating _heap = %x", heap_base);
      /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_heap",
                                        PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                        heap_base, "_heap", 1, 0, 0);
      PIC32_DEBUG("Creating _eheap = %x", heap_limit);
      /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_eheap",
                                        PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                        heap_limit, "_eheap", 1, 0, 0);

      PIC32_DEBUG("Creating _splim = %x", stack_base);
      /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_splim",
                                        PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                        stack_base, "_splim", 1, 0, 0);
      /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_SPLIM",
                                        PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                        stack_base, "_SPLIM", 1, 0, 0);

      stack_sec = bfd_get_section_by_name(stack_bfd, ".stack");
      if (stack_sec)
        {
          etree_type *addr_tree;
          os = lang_output_section_statement_lookup (".stack", 0, TRUE);
          stack_sec->size = pic32_stack_size;
          if (os->bfd_section != NULL)
          {
            bfd_set_section_size (stack_bfd, stack_sec, pic32_stack_size);
            bfd_set_section_vma (stack_bfd, stack_sec, stack_base);
            os->bfd_section->vma = stack_sec->vma;
            os->bfd_section->lma = stack_sec->lma;
            os->bfd_section->size = stack_sec->size;
            stack_sec->flags |= SEC_LINKER_CREATED;
            os->bfd_section->flags = stack_sec->flags;
            addr_tree = xmalloc(sizeof(etree_type));
            addr_tree->value.type.node_class = etree_value;
            addr_tree->value.value = stack_sec->vma;
            os->addr_tree = addr_tree;
	    PIC32_DEBUG("Creating _stack = %x", stack_limit);
            /*_bfd_generic_*/link_add_one_symbol (&link_info, stack_sec->owner, "_stack",
                                              PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                              stack_limit, "_stack", 1, 0, 0);
                                              
          }
          else
            fprintf( stderr, "Link Error: Unable to allocate stack\n");
        }

  }

  /* Range check the stack, no matter how it was created */
  if ( (int) (stack_limit - stack_base) < (int) pic32_stack_size)
    {
      einfo("%P%X Error: Not enough memory for stack"
            " (%d bytes needed, %d bytes available)\n",
            pic32_stack_size + pic32_stackguard_size,
            (int) (stack_limit - stack_base) + pic32_stackguard_size);
    }

  PIC32_DEBUG("Creating __MIN_STACK_SIZE = %x", pic32_stack_size);
  /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "__MIN_STACK_SIZE",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    pic32_stack_size, "__MIN_STACK_SIZE", 1, 0, 0);
  PIC32_DEBUG("Creating _min_stack_size = %x", pic32_stack_size);
  /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_min_stack_size",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    pic32_stack_size, "_min_stack_size", 1, 0, 0);

  PIC32_DEBUG("Creating __MIN_HEAP_SIZE = %x", pic32_heap_size);
  /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "__MIN_HEAP_SIZE",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    pic32_heap_size, "__MIN_HEAP_SIZE", 1, 0, 0);
  PIC32_DEBUG("Creating _min_heap_size = %x", pic32_heap_size);
  /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_min_heap_size",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    pic32_heap_size, "_min_heap_size", 1, 0, 0);

  end_data_mem = stack_limit;

  if (pic32_is_l1cache_machine(global_PROCESSOR))
  {
    /* Try to use kseg0_data_mem, but fall back to kseg1_data_mem. */
    if (lang_memory_region_exist("kseg0_data_mem"))
      region = region_lookup ("kseg0_data_mem");
    else if (lang_memory_region_exist("kseg1_data_mem"))
      region = region_lookup ("kseg1_data_mem");
    else
      region = region_lookup ("kseg0_data_mem");
  }
  else
  {
    /* Try to use kseg1_data_mem, but fall back to kseg0_data_mem. */
    if (lang_memory_region_exist("kseg1_data_mem"))
      region = region_lookup ("kseg1_data_mem");
    else if (lang_memory_region_exist("kseg0_data_mem"))
      region = region_lookup ("kseg0_data_mem");
    else
      region = region_lookup ("kseg1_data_mem");
  }

  if (region) {
    end_data_mem = region->origin + region->length;
  }

  if (!bfd_pic32_is_defined_global_symbol("_ramfunc_begin"))
  {
    /* If there are no ram fumctions, add the _ramfunc_begin symbol with value 0 */
    /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_ramfunc_begin",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    0, "_ramfunc_begin", 1, 0, 0);
  }
  if (!bfd_pic32_is_defined_global_symbol("_bmxdkpba_address"))
  {
    /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_bmxdkpba_address",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    end_data_mem - region->origin, "_bmxdkpba_address", 1, 0, 0);
  }
  if (!bfd_pic32_is_defined_global_symbol("_bmxdudba_address"))
  {
    /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_bmxdudba_address",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    region->length, "_bmxdudba_address", 1, 0, 0);

    /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_bmxdupba_address",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    region->length, "_bmxdupba_address", 1, 0, 0);
  }
  if (!bfd_pic32_is_defined_global_symbol("_bmxdupba_address"))
  {
    /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd, "_bmxdupba_address",
                                    PIC32_CORESIDENT/*BSF_GLOBAL*/, bfd_abs_section_ptr,
                                    region->length, "_bmxdupba_address", 1, 0, 0);
  }

  /*
  ** Set _dinit_addr symbol for data init template
  **   so the C startup module can find it.
  */

  if (pic32_data_init)
    {
      asection *sec;
      sec = init_template->output_section;  /* find the template's output sec */

      if (sec)
        {
          bfd_vma dinit_addr = sec->lma + init_template->output_offset;
          unsigned int dinit_addr_32 = dinit_addr & 0xFFFFFFFFul;

	  PIC32_DEBUG("Creating _dinit_addr= %x", dinit_addr_32);
          /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd,
                                            "_dinit_addr", PIC32_CORESIDENT /* BSF_GLOBAL */,
                                            bfd_abs_section_ptr, dinit_addr_32,
                                            "_dinit_addr", 1, 0, 0);
	  PIC32_DEBUG("Creating _dinit_size= %x", dinit_size);
          /*_bfd_generic_*/link_add_one_symbol (&link_info, link_info.output_bfd,
                                            "_dinit_size", PIC32_CORESIDENT /* BSF_GLOBAL */,
                                            bfd_abs_section_ptr, dinit_size,
                                            "_dinit_size", 1, 0, 0);
        }

        if (init_shared_template != NULL)
        {
            ///\ coresident - if shared data ...
            sec = init_shared_template->output_section;  /* find the shared */
                                                     /* template's output sec */
            if (sec)
            {
                bfd_vma shared_dinit_addr = sec->lma + init_shared_template->output_offset;
		PIC32_DEBUG("Creating __shared_dinit_addr = %lx", shared_dinit_addr);
                link_add_one_symbol (&link_info, link_info.output_bfd,
                                    "__shared_dinit_addr",
                                    BSF_GLOBAL | BSF_WEAK,
                                    bfd_abs_section_ptr,
                                    shared_dinit_addr,
                                    "__shared_dinit_addr", 1, 0, 0);
            }
        }
    }
 } // PIE SUPPORT

#if 1
if (link_info.shared || link_info.pie)
 {
   /* if heap is required, make sure one is specified */

   if (pic32_heap_required && !heap_section_defined && !pic32_has_heap_option &&
	  !bfd_pic32_is_defined_global_symbol("_min_heap_size"))
	  einfo("%P%X Error: A heap is required, but has not been specified\n");

   /* check for _min_stack_size symbol -- this is an old way to specify
	 a stack, and is really not preferred */
   if ((h = bfd_pic32_is_defined_global_symbol("_min_heap_size"))) {
	if (pic32_has_heap_option && (h->u.def.value != pic32_heap_size))
	  fprintf (stderr, "Warning: --heap option overrides _min_heap_size symbol\n");
	else
	  pic32_heap_size = h->u.def.value;
   }
  
   PIC32_DEBUG("Creating __MIN_HEAP_SIZE = %x", pic32_heap_size);
  
  if (!bfd_pic32_is_defined_global_symbol("__MIN_HEAP_SIZE"))
   _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, "__MIN_HEAP_SIZE",
									BSF_GLOBAL, bfd_abs_section_ptr,
									pic32_heap_size, "__MIN_HEAP_SIZE", 1, 0, 0);
//  PIC32_DEBUG("Creating _min_heap_size = %x", pic32_heap_size);
//  
//  if (!bfd_pic32_is_defined_global_symbol("_min_heap_size"))
//   _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, "_min_heap_size",
//									BSF_GLOBAL, bfd_abs_section_ptr,
//									pic32_heap_size, "_min_heap_size", 1, 0, 0);  
 PIC32_DEBUG("Creating _heap = %x", heap_base);
     
   if (!bfd_pic32_is_defined_global_symbol("_heap"))
     _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, "_heap",
                                        BSF_GLOBAL, bfd_abs_section_ptr,
                                        heap_base, "_heap", 1, 0, 0);
	
   PIC32_DEBUG("Creating _eheap = %x", heap_limit);

   if (!bfd_pic32_is_defined_global_symbol("_eheap"))
     _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, "_eheap",
                                        BSF_GLOBAL, bfd_und_section_ptr,
                                        heap_limit, "_eheap", 1, 0, 0);


  /*
  ** Set _dinit_addr symbol for data init template
  **   so the C startup module can find it.
  */
  if (pic32_data_init)
    {
      asection *sec;
      sec = init_template->output_section;  /* find the template's output sec */

      if (sec)
        {
          bfd_vma dinit_addr = sec->lma + init_template->output_offset;
          unsigned int dinit_addr_32 = dinit_addr & 0xFFFFFFFFul;

	  PIC32_DEBUG("Creating _dinit_addr= %x", dinit_addr_32);
          _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
                                            "_dinit_addr", PIC32_CORESIDENT /* BSF_GLOBAL */,
                                            bfd_abs_section_ptr, dinit_addr_32,
                                            "_dinit_addr", 1, 0, 0);
	  PIC32_DEBUG("Creating _dinit_size= %x", dinit_size);
          _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
                                            "_dinit_size", PIC32_CORESIDENT /* BSF_GLOBAL */,
                                            bfd_abs_section_ptr, dinit_size,
                                            "_dinit_size", 1, 0, 0);
        }
    }
									
  } // PIE SUPPORT
#endif

    /* lghica co-resident */

    /* clean the section names */
    PIC32_DEBUG("\nCleaning section names:");
    bfd_map_over_sections(link_info.output_bfd, &bfd_pic32_clean_section_names, 0);

    asection *s;
    for (s = link_info.output_bfd->sections; s != NULL; s= s->next)
    {
        if (s->name && (strcmp(s->name, ".shared.dinit") == 0) &&
                ((s->flags & SEC_EXCLUDE) == 0))
            pic32m_append_section_to_list(shared_dinit_sections, 0, s);
    }

    for (s = link_info.output_bfd->sections; s != NULL; s= s->next)
    {
        ///\ mark as linked all debug sections
        if ((!PIC32_IS_INFO_ATTR(s)) || (strstr(s->name, "debug") != NULL) )
        {
            ///\ fix to prevent absolute .comment sections
            if (strcmp(s->name, ".comment") == 0)
                continue;
            if (s->linked == 1)
            {
                char *name;
                char *linked_prefix = "__linked_";

                name = xmalloc (strlen(s->name) + strlen(linked_prefix) + 1);
                (void) sprintf(name, "%s%s", linked_prefix, s->name);

                _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd,
                            name, BSF_GLOBAL,
                            bfd_abs_section_ptr, 1,
                            name, 1, 0, 0);

                if ((PIC32_IS_DATA_ATTR(s) || PIC32_IS_BSS_ATTR(s))
                        && !PIC32_IS_SHARED_ATTR(s))
                    continue;
                else if (strcmp(s->name, ".reset") == 0)
                    PIC32_SET_ABSOLUTE_ATTR(s);
            }
        }
    }
}

void
pic32m_after_allocation (void)
{
  /* MERGE-NOTES: it seems the order of various things may have changed
     between the initial mips and arm versions. the order of these things
     is different in various ways in pic32c. */
#if 0 /* NO  - this is in pic32_finish now */
   /* If any sections are discarded then relocations of symbols referenced
      in sections like .eh_frame, .stab, .pdr will be removed. Also entries 
      these sections may be removed to eleminate duplication. 
      So the size will change. If we don't map_segments before 
      best-fit-allocation overlapping may occur. */
   need_layout = bfd_elf_discard_info (link_info.output_bfd,
                                                  &link_info);

   emultempl_map_segments (need_layout);
#endif

#ifdef TARGET_IS_PIC32MX
    /* lghica - co-resident */
    if (pic32_pad_flash_option)
        bfd_pic32_pad_flash();
#endif

/*
** Invoke the best-fit allocator
*/
  if (pic32_allocate) {
    allocate_memory();
  }

  /* MERGE-NOTES: let's just try stripping sections here? */
  /* absolutely not - we can only strip afteer lang_size_sections is called,
     since otherwise most sections will be unsized and removed. */
  /*
  pic32_strip_sections (link_info.output_bfd);
  */
  
#ifdef TARGET_IS_PIC32MX
  if (pic32_has_fill_option)
    pic32_create_fill_templates();
#endif
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

/*
** Create a bfd for the fill templates
**
** Uses the following global variables:
**   symtab
**   symptr
*/
static bfd *
bfd_pic32_create_fill_bfd (parent)
     bfd *parent ATTRIBUTE_UNUSED;
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
  bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

  /* create a symbol table (room for 1 entry) */
  symptr = 0;
  symtab = (asymbol **) bfd_alloc (link_info.output_bfd, 2 * sizeof (asymbol *));

  /*
  ** create a bare-bones section for
  */
  /* get unique section name */
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

void pic32_create_fill_templates(void)
{
  struct pic32_fill_option *o;
  if (program_memory_free_blocks)
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
  struct memory_region_struct *region;
  bfd_vma size = 0;
  bfd_vma addr = 0;
  int sec_align = 2;

  for (b = program_memory_free_blocks; b != NULL; b = next)
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
 else
   PIC32_DEBUG("after_open: section %s not found", sec->name);

     region = region_lookup ("kseg0_program_mem");

     update_section_info(addr, s, region);

     pic32m_append_section_to_list(opt->fill_section_list, 
                                  (lang_input_statement_type *)s->file, sec);
     pic32_remove_from_memory_list(program_memory_free_blocks, b);
    }

}

void pic32_create_specific_fill_sections(void)
{
  asection * sec;
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

       fill_bfd = bfd_pic32_create_fill_bfd(link_info.output_bfd);
       bfd_pic32_add_bfd_to_link (fill_bfd, fill_bfd->filename);

       fill_bfd->sections->vma = fill_bfd->sections->lma = o->loc.address;
       fill_bfd->sections->rawsize = size;
       fill_bfd->sections->size = size;

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
       sec = bfd_get_section_by_name(fill_bfd,fill_bfd->sections->name );
       if (sec)
       {
        sec->rawsize = size;
        sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE);
        PIC32_SET_ABSOLUTE_ATTR(sec);
        sec->contents = fill_data;
        bfd_set_section_size (fill_bfd, sec, size);
        fill_bfd->sections = sec;  /* save a copy for later */
       }
      else
	PIC32_DEBUG("after_open: section %s not found", sec->name);

      pic32m_append_section_to_list(o->fill_section_list,
                                 (lang_input_statement_type *)NULL, sec);
   }
}

/* lghica co-resident */

/*
** Create a new symbol
**
** Uses the following global variables:
**   symtab
**   symptr
*/
static void
bfd_pic32_create_symbol(bfd *abfd, char *name, asection *sec,
                int flags, int addr)
{
asymbol *sym;

PIC32_DEBUG("  Adding symbol %s", name);

sym = bfd_make_empty_symbol (abfd);
sym->name = name;
sym->section = sec;
sym->flags = flags;
sym->value = addr;
symtab[symptr++] = sym;
} /* static void bfd_pic32_create_symbol (...)*/



static bfd *
bfd_pic32_create_pad_bfd (bfd *parent ATTRIBUTE_UNUSED)
{
    bfd_size_type   size;
    bfd             *abfd;
    asection        *sec;
    char            *oname;
    int             flags, align;
    const char      *sname;

    /* create a bare-bones bfd */
    oname = (char *) bfd_alloc (link_info.output_bfd, 20);
    sprintf (oname, "pad%d", pad_section_count);
    abfd = bfd_create (oname, parent);
    bfd_find_target (EMULTEMPL.output_format, abfd);
    bfd_make_writable (abfd);

    bfd_set_format (abfd, bfd_object);
    bfd_set_arch_mach (abfd, bfd_arch_mips, 0);

    /* create a symbol table (room for 1 entry) */
    symptr = 0;
    symtab = (asymbol **) bfd_alloc (link_info.output_bfd, sizeof (asymbol *));

    /*
    ** create a bare-bones section for
    */

    /* get unique section name */
    sname = bfd_get_unique_section_name (abfd, "pad$", &pad_section_count);
    flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY;
    align = 1; /* 2^1 */
    sec = bfd_pic32_create_section (abfd, sname, flags, align);
    size = 0; /* will update later */
    bfd_set_section_size (abfd, sec, size);

    /* put in the symbol table */
    bfd_set_symtab (abfd, symtab, symptr);
    /* finish it */
    if (!bfd_make_readable (abfd))
    {
        fprintf( stderr, "Link Error: can't make pad readable\n");
        abort();
    }
    return abfd;
}


/* lghica co-resident */

#define PAD_PATTERN     0x11


static void bfd_pic32_pad_flash()
{
    asection                    *sec;
    struct pic32_memory         *b, *next;
    bfd                         *pad_bfd;
    unsigned char               *pad_data;
    struct pic32_section        *s;
    struct memory_region_struct *region;
    bfd_vma                     size = 0;
    bfd_vma                     addr = 0;
    bfd_vma                     len = 0;
    bfd_vma                     pad_to = 0; /* instruction words */

    if (pad_flash_arg)
        pad_to = pad_flash_arg;
    else
    {
        /* einfo(_("%P%F: Warning: Flash padding size not specified.\n" )); */
        return;
    }


    if (program_memory_free_blocks)
    {
        if (lang_memory_region_exist("kseg0_program_mem"))
            region = region_lookup ("kseg0_program_mem");
        else if (lang_memory_region_exist("kseg1_program_mem"))
            region = region_lookup ("kseg1_program_mem");
        else
            ///\ todo - add warning
            return;

        pad_to = pad_to * 2;   /* PC-units */

        for (b = program_memory_free_blocks; b != NULL; b = next)
        {
            next = b->next;
            if ((b->addr == 0) && (b->size == 0))
                continue;
            if (b->addr % pad_to)
            {
                addr = b->addr;
                len = pad_to - (b->addr % pad_to);
            }
            else if (next && (b->size % pad_to))
            {
                len = b->size % pad_to;
                addr = b->addr + b->size - len;
                b->offset = addr - b->addr;
            }
            else
                len = 0;

            if (len)
            {
                size = len * 2;
                pad_bfd = bfd_pic32_create_pad_bfd(link_info.output_bfd);
                bfd_pic32_add_bfd_to_link (pad_bfd, pad_bfd->filename);

                pad_bfd->sections->vma = pad_bfd->sections->lma = addr;
                pad_bfd->sections->rawsize = size;
                pad_bfd->sections->size = size;

                /* create a pic32_section */
                pic32_init_section_list(&s);
                s->sec = pad_bfd->sections;

                LANG_FOR_EACH_INPUT_STATEMENT (file)
                {
                    if (strcmp(file->filename, pad_bfd->filename) == 0)
                        s->file = (PTR) file;
                }

                /* allocate memory for the template */
                pad_data = (unsigned char *) bfd_alloc (link_info.output_bfd, size);

                if (!pad_data)
                {
                    fprintf( stderr, "Link Error: not enough memory for data template\n");
                    abort();
                }

                /* fill the template with a default value */
                pad_data = memset(pad_data, PAD_PATTERN, size);

                /* attach it to the input section */
                sec = bfd_get_section_by_name(pad_bfd, pad_bfd->sections->name);

                if (sec)
                {
                    sec->rawsize = size;
                    sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE);
                    sec->contents = pad_data;
                    bfd_set_section_size (pad_bfd, sec, size);
                    pad_bfd->sections = sec;  /* save a copy for later */
                }
                else
		  PIC32_DEBUG("after_open: section %s not found", sec->name);

                update_section_info(addr, s, region);
                create_remainder_blocks(program_memory_free_blocks, b, len);
                pic32_remove_from_memory_list(program_memory_free_blocks, b);
                next = program_memory_free_blocks->next;
            }
        }
    }
}

/* lghica co-resident */
void pic32_create_shared_data_init_template(void)
{
    struct pic32_section    *s;
    int                     total_data = 0;
    asection                *sec;

    /*
    ** If data init support is enabled, create a BFD
    ** for section .dinit and add it to the link.
    */
    if (pic32_data_init)
    {
        init_shared_bfd = bfd_pic32_create_shared_data_init_bfd (link_info.output_bfd);
        bfd_pic32_add_bfd_to_link (init_shared_bfd, init_shared_bfd->filename);

        /* Compute size of data init template */
        for (s = shared_data_sections; s != NULL; s = s->next)
            if ((s->sec) && ((s->sec->flags & SEC_EXCLUDE) == 0))
                bfd_pic32_scan_data_section(s->sec, &total_data);

        total_data += 8; /* 2*4 bytes- zero terminated */

	DEBUG({
	    LOG("  null terminator, template += 1 pword\n");
            LOG("\n Total initialized data: %x pwords\n", total_data/4);
	  });

        /* allocate memory for the template */
        init_shared_data = (unsigned char *) bfd_alloc (link_info.output_bfd, total_data);
        if (!init_shared_data)
        {
            fprintf( stderr, "Link Error: not enough memory for data template\n");
            abort();
        }

        /* fill the template with a default value */
        init_shared_data = memset( init_shared_data, PAD_PATTERN, total_data);

        /* attach it to the input section */
        sec = bfd_get_section_by_name(init_shared_bfd, ".shared.dinit");
        if (sec)
        {
            sec->rawsize = total_data;
            sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE | SEC_KEEP);
            sec->contents = init_shared_data;
            bfd_set_section_size (init_shared_bfd, sec, total_data);
            init_shared_template = sec;  /* save a copy for later */
        }
        else
	  PIC32_DEBUG("after_open: section .shared.dinit not found");
    } /* if (pic32_data_init) */
    else
    {
        /* warn if initial data values will be ignored */
        for (s = shared_data_sections; s != NULL; s = s->next)
            if (s->sec)
                bfd_pic32_skip_data_section(s->sec, &total_data);
    }
}


/* lghica co-resident */
void pic32_create_rom_usage_template(void)
{
    int                     rom_usage_size= 0;
    asection                *sec;

    rom_usage_bfd = bfd_pic32_create_rom_usage_bfd (link_info.output_bfd);
    bfd_pic32_add_bfd_to_link (rom_usage_bfd, rom_usage_bfd->filename);

    /* Compute size of flash usage template */

    LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
        for (sec = f->the_bfd->sections;
                    sec != (asection *) NULL;
                    sec = sec->next)
            if ((sec->rawsize > 0)
                && ((sec->flags & SEC_EXCLUDE) == 0)
                && PIC32_IS_CODE_ATTR(sec))
            {
                if (strcmp(sec->name, ".dinit") == 0)
                    continue;
                else
                    rom_usage_size += 8;
            }
    }

    rom_usage_size += 8;    /* .text section in linker script */
    rom_usage_size += 16;   /* count for .rom_usage and .ram_usage */
    rom_usage_size += 4;    /* zero terminated */


    /* allocate memory for the template */
    rom_usage_data = (unsigned char *) bfd_alloc (link_info.output_bfd, rom_usage_size);

    if (!rom_usage_data)
    {
        fprintf( stderr, "Link Error: not enough memory for rom usage template\n");
        abort();
    }

    /* fill the template with a default value */
    rom_usage_data = memset( rom_usage_data, PAD_PATTERN, rom_usage_size);
    /* attach it to the input section */
    sec = bfd_get_section_by_name(rom_usage_bfd, ".rom_usage");

    if (sec)
    {
        sec->rawsize = rom_usage_size;
        sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE | SEC_KEEP);
        sec->contents = rom_usage_data;
        bfd_set_section_size (rom_usage_bfd, sec, rom_usage_size);
        rom_usage_template = sec;  /* save a copy for later */
    }
    else
      PIC32_DEBUG("after_open: section .rom_usage not found");

}


/* lghica co-resident */
void pic32_create_ram_usage_template(void)
{
    int                     ram_usage_size= 0;
    asection                *sec;

    ram_usage_bfd = bfd_pic32_create_ram_usage_bfd (link_info.output_bfd);
    bfd_pic32_add_bfd_to_link (ram_usage_bfd, ram_usage_bfd->filename);

    /* Compute size of flash usage template */

    LANG_FOR_EACH_INPUT_STATEMENT (f)
    {
        for (sec = f->the_bfd->sections;
                    sec != (asection *) NULL;
                    sec = sec->next)
            if ((sec->rawsize > 0) && ((sec->flags & SEC_EXCLUDE) == 0)
                    && (PIC32_SECTION_IN_DATA_MEMORY(sec) || PIC32_IS_MEMORY_ATTR(sec)))
                ram_usage_size += 8;
    }

    ram_usage_size += 4; /* zero terminated */


    /* allocate memory for the template */
    ram_usage_data = (unsigned char *) bfd_alloc (link_info.output_bfd, ram_usage_size);

    if (!ram_usage_data)
    {
        fprintf( stderr, "Link Error: not enough memory for ram usage template\n");
        abort();
    }

    /* fill the template with a default value */
    ram_usage_data = memset( ram_usage_data, PAD_PATTERN, ram_usage_size);

    /* attach it to the input section */
    sec = bfd_get_section_by_name(ram_usage_bfd, ".ram_usage");

    if (sec)
    {
        sec->rawsize = ram_usage_size;
        sec->flags |= (SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_LOAD | SEC_CODE | SEC_KEEP);
        sec->contents = ram_usage_data;
        bfd_set_section_size (ram_usage_bfd, sec, ram_usage_size);
        ram_usage_template = sec;  /* save a copy for later */
    }
    else
      PIC32_DEBUG("after_open: section .ram_usage not found");
}
