/* Best-fit allocator (BFA) for pic32c.

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

/*****************************************************************************
**
** Improved Memory Allocation Routines
**
** These functions implement the improved
** memory allocator .
**
*/

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"

#include "elf-bfd.h"
#include "ld.h"
#include "ldexp.h"
#include "ldlang.h"
#include "ldmain.h"
#include "ldmisc.h"

#include "libiberty.h"

#include "elf/pic32.h"
#include "pic32-vecset.h"
#include "pic32c-utils.h"

#include "pic32c-options.h"
#include "pic32c-emul.h"
#include "pic32c-allocate.h"
#include "pic32-debug.h"
#include "pic32-common-emul.h"
/*
 * debug scope
 */
#define DEBUG_SCOPE "bfa"

/* useful constants and macros */
#define NEAR_BOUNDARY   0xa0010000

#define VALID_NEAR(addr, len) ((bfd_vma)(addr)+(len) <= NEAR_BOUNDARY)

#define VALID_LOW_ADDR(addr, len)  ((bfd_vma)(addr)+(len) <= exclude_addr)
#define VALID_HIGH_ADDR(addr, len)  ((bfd_vma)(addr) >= exclude_addr)

/* Create an id for each section attribute */
#define ATTR(a,b,c)  _##a,
 enum {
#include "pic32c-attributes.h"
 } ;

/* Create a bit mask for each section attribute */
#undef ATTR
#define ATTR(a,b,c)  a = (1<<_##a),
 enum {
#include "pic32c-attributes.h"
 } ;

/* TODO: this is used as the relocated vector address, so the name should probably
   not mention itcm? */
extern bfd_vma pic32c_itcm_vectors_address;
extern bfd_boolean pic32c_relocate_vectors;
extern asection* init_template;
extern unsigned char* init_data;
extern bfd* init_bfd;
extern int dinit_size;

static void create_remainder_blocks (struct pic32_memory *,
				     struct pic32_memory *, unsigned int);

static int allocate_tcm_memory (void);
static int allocate_data_memory (void);
static int allocate_program_memory (void);
static void build_alloc_section_list(unsigned int,
				     struct pic32_section ** const);
static int locate_sections(unsigned int, unsigned int,
			   struct pic32_region *, struct pic32_section** const);
static void align_free_blocks(struct pic32_memory *, unsigned int);
static struct pic32_memory *select_free_block(struct pic32_region *,
					      struct pic32_section *,
					      unsigned int);

static void build_free_block_list(struct pic32_region *,
				  unsigned int ATTRIBUTE_UNUSED);
static void remove_free_block (struct pic32_memory *, struct pic32_memory *);

static void dinit_check_stubs(void);

/* this usage is intended for checking if a region_info member is present and valid,
   i.e. an additional NULL check for the pic32_region pointer. */
int
pic32_valid_region(struct pic32_region *regn) {
    return (regn && valid_region(regn->region));
}

/* a hard coded magic number   the cache line size for jubilee is 16 bytes */
/* for now Jubilee is the only family with combines TCM, so I only need one of these.*/

/* ensure that the region has all of the needed_flags and none of the
   invalid_flags. basically, this copes with flags and not_flags. */
static int 
check_region_flags(const lang_memory_region_type *region, 
                   unsigned needed_flags, 
                   unsigned invalid_flags) {
    return ((region->flags & needed_flags) == needed_flags &&
            (region->not_flags & needed_flags) == 0 &&
            (invalid_flags == 0 ||
              ((region->flags & invalid_flags) == 0) ||
              ((region->not_flags & invalid_flags) != 0)));
}

/* not static, because it's needed in pic32c-emul.c */
struct region_info region_info;

/* a hard coded magic number   the cache line size for jubilee is 16 bytes */
/* for now Jubilee is the only family with combined TCM, so I only need one of these.*/

#define JUBILEE_CACHE_LINE_ALIGNMENT_POWER 4

/* MERGE_NOTES: renamed params to avoid warnings for shadowing code/data globals */
enum tcm_style 
determine_tcm_style (lang_memory_region_type **itcm_region, lang_memory_region_type **dtcm_region) {

/*   the tcm style of the machine is determined by which memory regions are defined
 *   so this really comes from the linker script
 *
 *    if there is a memory region called "tcm" then we have TCM_COMBINED
 *    if either of dtcm or itcm exists we have TCM_SEPERATE
 *    if one of these co-exists with tcm we are in an error situation (not checked here)
 *    if none of these exist we have TCM_NONE    
 *
 *    input tcm sections will have the attribute itcm or dtcm depending if they are
 *    itcm_region or dtcm_region resp.   Plain "tcm" is not a valid attribute.
*/
    
    bfd_boolean found_itcm_or_dtcm = FALSE;
    *itcm_region = *dtcm_region = NULL;
    
    lang_memory_region_type *region = region_lookup("tcm");

    if (valid_region(region)) {
	*itcm_region = region;
	*dtcm_region = region;
	return TCM_COMBINED;
    }
    region = region_lookup("itcm");
    if (valid_region(region)) {
	*itcm_region = region;
	found_itcm_or_dtcm = TRUE;
    }
    else { // if there is no tcm region don't try to put the vectors there ... xc32-1937
	 pic32c_vectors_in_tcm = FALSE;
    }

    region = region_lookup("dtcm");
    if (valid_region(region)) {
	*dtcm_region = region;
	found_itcm_or_dtcm = TRUE;
    }

    if (found_itcm_or_dtcm) return TCM_SEPARATE;
    return TCM_NONE;
}

/* debug helper to display regions as classified */
static void 
dump_single_region_info (const struct pic32_region *region, const char *name) {
    const lang_memory_region_type *regn = region->region;
    fprintf(stderr, "%12s %12s %12x %12x    ", name, regn->name_list.name, regn->origin, regn->length);
    fprintf(stderr, "%c", (region->flags.init_needed ? 'I' : '.'));
    fprintf(stderr, "%c", (region->flags.is_cleared ? 'Z' : '.'));
    fprintf(stderr, "%c", (region->flags.is_exec ? 'X' : '.'));
    fprintf(stderr, "%c", (region->flags.is_tcm ? 'T' : '.'));
    fprintf(stderr, "\n");
}

static void 
dump_region_info (const struct region_info *rinfo) {
    if(!pic32_debug) return;
    fprintf(stderr, "%12s %12s %12s %12s %8s\n", "region", "name", "origin", "length", "flags");

    if (pic32_valid_region(rinfo->code))
        dump_single_region_info(rinfo->code, "code");
    if (pic32_valid_region(rinfo->data)) 
        dump_single_region_info(rinfo->data, "data");
    if (pic32_valid_region(rinfo->code_tcm)) 
        dump_single_region_info(rinfo->code_tcm, "itcm");
    if (pic32_valid_region(rinfo->data_tcm)) 
        dump_single_region_info(rinfo->data_tcm, "dtcm");
    if (pic32_valid_region(rinfo->vectors))
      dump_single_region_info(rinfo->vectors, "vectors");
}

/* helper to output a region description to a memory info file. TCM reporting
   is disabled unless show_tcm is set, as apparently this can affect/break
   the IDE memory display? */
static void
report_single_region_info(FILE *fp, struct pic32_region *regn, const char *name) {
  unsigned long total_size = 0;
  unsigned long used_size = 0;
  struct pic32_section *s;

  if (!pic32_valid_region(regn) || !regn->region->length) 
      return;

  total_size = regn->region->length;

  for (s = pic32_section_list; s != NULL; s = s->next)
      if (s->sec)
          used_size += bfd_pic32_collect_section_size (s, regn->region);

  fprintf (fp, "    <memory name=\"%s\">\n"
               "      <units>bytes</units>\n"
               "      <length>%lu</length>\n"
               "      <used>%lu</used>\n"
               "      <free>%lu</free>\n"
               "    </memory>\n",
           name, total_size, used_size, total_size - used_size);
}

void
pic32_report_region_info (FILE *f, int show_tcm) {

    /* report code as 'rom' if not shared with data (or if readonly?) */
    /* XC32-1658: changed 'rom' to 'program' (the shell and MPLAB X look for this name) */
    if (pic32_valid_region(region_info.code) && 
        region_info.code != region_info.data) {
        report_single_region_info(f, region_info.code, "program");
    }
    /* XC32-1658: similarly, use 'data' instead of 'ram' */
    if (pic32_valid_region(region_info.data)) {
        report_single_region_info(f, region_info.data, "data");
    }

    if (show_tcm) {
        /* report tcm as 'tcm' when combined, else itcm/dtcm */
        if (pic32_valid_region(region_info.code_tcm) &&
            region_info.code_tcm == region_info.data_tcm) {
            report_single_region_info(f, region_info.code_tcm, "tcm");
        } 
        else {
            if (pic32_valid_region(region_info.code_tcm)) {
                report_single_region_info(f, region_info.code_tcm, "itcm");
            }
            if (pic32_valid_region(region_info.data_tcm)) {
                report_single_region_info(f, region_info.data_tcm, "dtcm");
            }
        }
    }
}


/* allocate and initialize a pic32_region for the underlying BFD region. */
static struct pic32_region *
pic32_new_region(struct memory_region_struct *region) {
    struct pic32_region *p = xmalloc(sizeof(struct pic32_region));
    memset(p, 0, sizeof(struct pic32_region));
    p->region = region;
    return p;
}


/* Populate region_info with information about regions that the BFA
   can allocate to. Returns true iff the BFA has any hope of working,
   i.e. there are regions for everything that could be allocated.
*/
int
pic32_init_region_info(struct region_info *rinfo) {


    lang_memory_region_type *code_region, *data_region;

    // if dinit is explicitly provided then do it even on loadable data sections and all tcm
    // note: not done for the default code region
    bfd_boolean init_always = pic32_data_init &&  pic32_has_data_init_option;

    /* wipe out whatever was there. */
    memset(rinfo, 0, sizeof *rinfo);

    /* first: check for 'ram'/'rom', the usual case. these
       are the expected regions, along with maybe TCM, for 
       cortex-M devices so far.
       the convention here is that if 'ram' exists, we expect
       a 'rom' as well. */
    data_region = region_lookup ("ram");
    code_region = region_lookup ("rom");

    if (valid_region(data_region)) {
        /* FIXME: our scripts use the 'r' flag for just about every section
           which seems to mean readonly, not readable (everything is readable).
           so we can't check that flag for data. */
        if (check_region_flags(data_region, (SEC_DATA), 0)) {
	    PIC32_DEBUG( "classify: data -> 'ram'");
            rinfo->data = pic32_new_region(data_region);
            rinfo->data->flags.is_exec = check_region_flags(data_region, (SEC_CODE), 0);
            rinfo->data->flags.init_needed = check_region_flags(data_region, 0, (SEC_LOAD)) || init_always;
        }
    }
    else {
      /* try sram if ram isn't anywhere to be found. */
      data_region = region_lookup ("sram");
      if (valid_region(data_region)
          && check_region_flags(data_region, (SEC_DATA), 0)) {
          PIC32_DEBUG( "classify: data -> 'sram'");
	  rinfo->data = pic32_new_region(data_region);
	  rinfo->data->flags.is_exec = check_region_flags(data_region, (SEC_CODE), 0);
	  rinfo->data->flags.init_needed = check_region_flags(data_region, 0, (SEC_LOAD)) || init_always;
      }
    }

    if (valid_region(code_region)) {

	if (check_region_flags(code_region, (SEC_CODE), 0)) {
	    PIC32_DEBUG( "classify: code -> 'rom'");
            rinfo->code = pic32_new_region(code_region);
            rinfo->code->flags.is_exec = 1;
            rinfo->code->flags.init_needed = check_region_flags(code_region, 0, (SEC_LOAD));
        }
    }

    /* check for TCM regions and kind of TCM to handle. */
    
    rinfo->tcm_style = determine_tcm_style(&code_region, &data_region);

    
    if (rinfo->tcm_style != TCM_NONE) {

        /* currently determine_tcm_style guarantees the regions are real, but 
           we'll also check flags */
        /* see above TODO for a note about SEC_READONLY .. */
        if (valid_region(data_region) &&
            check_region_flags(data_region, (SEC_DATA), 0)) {
            rinfo->data_tcm = pic32_new_region(data_region);
            rinfo->data_tcm->flags.is_exec = check_region_flags(data_region, (SEC_CODE), 0);
            rinfo->data_tcm->flags.init_needed = check_region_flags(data_region, 0, (SEC_LOAD)) || init_always;
        }

        if (rinfo->tcm_style == TCM_COMBINED) {
            rinfo->code_tcm = rinfo->data_tcm;
        }
        else if (valid_region(code_region) && 
            check_region_flags(code_region, (SEC_CODE), 0)) {
            rinfo->code_tcm = pic32_new_region(code_region);
            rinfo->code_tcm->flags.is_exec = 1;
            rinfo->code_tcm->flags.init_needed = check_region_flags(code_region, 0, (SEC_LOAD)) || init_always;
        }
    }

    if (rinfo->code == NULL && rinfo->data != NULL) {
        /* if is_exec isn't set, we are out of luck. */
        if (!rinfo->data->flags.is_exec) {
	    PIC32_DEBUG( "no rom region available, but ram is not executable");
            return 0;
        }
        rinfo->code = rinfo->data;

        /* in this case there is no rom and we must assume that the section is loaded
           we default to not doing data init on such sections because we assume it is handled
           by the loader, but in some cases a user will want data-init to happen on a soft reset
           so we allow them to specify that by explicitly providing the -qdata-init flag

        */

	rinfo->code->flags.init_needed = init_always;
	rinfo->data->flags.init_needed = init_always;


	PIC32_DEBUG( "classify: code and data will be in same region");
    }

    /* Now, we determine how to handle tcm-like relocations, i.e. moving .vectors
       around at runtime to something that isn't the code region. 
       If there's tcm regions, we trust the tcm-related options. 
       Otherwise, we check for 'sram', magically indicating SAMA5/MPU.
       TODO: set stack region as needed for stack-in-dtcm?
       */ 
    if (rinfo->tcm_style == TCM_NONE) {
        code_region = region_lookup("sram");

        /* we only want to relocate the vectors if we are not locating
           code in sram already. */
        if (valid_region(code_region) &&
            (rinfo->code != NULL && rinfo->code->region != code_region)) {
            if (check_region_flags(code_region, (SEC_CODE), 0)) {
                PIC32_DEBUG( "classify: vectors -> 'sram'");
                rinfo->vectors = pic32_new_region(code_region);
                rinfo->vectors->flags.is_exec = 1;
                rinfo->vectors->flags.init_needed = check_region_flags(code_region, 0, (SEC_LOAD));
                pic32c_relocate_vectors = TRUE;
                pic32c_vectors_in_tcm = FALSE;
            }
        }
    }
    else if (pic32c_vectors_in_tcm) {
        rinfo->vectors = rinfo->code_tcm;
        pic32c_relocate_vectors = TRUE;
    }

    /* that's it for magic names, now just check if we can proceed at all. */
    if (!pic32_valid_region(rinfo->code) || !pic32_valid_region(rinfo->data)) {
	PIC32_DEBUG( "unable to determine code/data targets for allocation.");
	PIC32_DEBUG( "check memory region names/flags.");
	dump_region_info (rinfo);
	
        return 0;
    }

    
    PIC32_DEBUG ("after classify:");
    dump_region_info (rinfo);
    return 1;
}

/* create the free_block list for each known region as needed. this is moved out of
   the allocate_XXX_memory function in order to deal with code/data sharing. 
   we'll still keep the order itcm->dtcm->code->data. 
   this also initializes the vector/stack target region lists for relocation
   if they are in different region(s) than code/data/tcm. */
static void
pic32_build_free_blocks(struct region_info *rinfo) {

    /* build itcm/tcm free blocks */
    if (pic32_valid_region(rinfo->code_tcm))
        build_free_block_list(rinfo->code_tcm, 0);

    /* build dtcm free blocks if not shared with itcm/tcm */
    if (pic32_valid_region(rinfo->data_tcm)) {
        if (rinfo->data_tcm != rinfo->code_tcm)
            build_free_block_list(rinfo->data_tcm, 0);
    }

    /* do the same for code/data. */
    if (pic32_valid_region(rinfo->code))
        build_free_block_list(rinfo->code, 0);

    if (rinfo->data == rinfo->code) {
        // TODO: have to suspect the same cache line issue may affect shared code/data
        // for SAMA5/MPUs
        //align_free_blocks(rinfo->data->free_blocks, 5);
    }
    else {
        if (pic32_valid_region(rinfo->data))
            build_free_block_list(rinfo->data, 0);
    }

    /* if the vector/stack targets are not any of the above, build them now.
     */
    if (rinfo->vectors != NULL && rinfo->vectors->free_blocks == NULL) 
        build_free_block_list(rinfo->vectors, 0);
    if (rinfo->stack != NULL && rinfo->stack->free_blocks == NULL) 
        build_free_block_list(rinfo->stack, 0);
}

/* Free any allocated memory used by region_info. In particular,
   free all the free block lists. This is to be called from 
   bfd_pic32_finish, or at least at the end of the region_info's usefulness. */
void 
pic32_free_region_info(struct region_info *rinfo) {
    if (!rinfo) return;

    /* here we deal with sharing of free block lists - code/data may be shared
       between tcm and not-tcm flavours */
    if (pic32_valid_region(rinfo->code) && rinfo->code->free_blocks) {
        pic32_free_memory_list(&rinfo->code->free_blocks);
    }

    if (pic32_valid_region(rinfo->data) && rinfo->data->free_blocks) {
        pic32_free_memory_list(&rinfo->data->free_blocks);
    }

    if (pic32_valid_region(rinfo->code_tcm) && rinfo->code_tcm->free_blocks) {
        pic32_free_memory_list(&rinfo->code_tcm->free_blocks);
    }

    if (pic32_valid_region(rinfo->data_tcm) && rinfo->data_tcm->free_blocks) {
        pic32_free_memory_list(&rinfo->data_tcm->free_blocks);
    }

    /* and then do the same excercise for the regions themselves. */
    if (rinfo->code) {
        free (rinfo->code);
        if (rinfo->data == rinfo->code)
            rinfo->data = NULL;
        rinfo->code = NULL;
    }
    if (rinfo->data) {
        free (rinfo->data);
        rinfo->data = NULL;
    }
    if (rinfo->code_tcm) {
        free (rinfo->code_tcm);
        if (rinfo->data_tcm == rinfo->code_tcm)
            rinfo->data_tcm = NULL;
        rinfo->code_tcm = NULL;
    }
    if (rinfo->data_tcm) {
        free (rinfo->data_tcm);
        rinfo->data_tcm = NULL;
    }

    memset(rinfo, 0, sizeof *rinfo);
}

/* Create a bit mask to match any attribute */
#define all_attr 0xFFFFFFFF


/* Memory allocator options  */
enum {
  NO_LOCATE_OPTION,
  FAVOR_LOW_ADDR,     /* scan free blocks from low addr only  */
  FAVOR_HIGH_ADDR,    /* scan free blocks from high addr only */
  EXCLUDE_LOW_ADDR,   /* avoid memory below LIMIT             */
  EXCLUDE_HIGH_ADDR,  /* avoid memory above LIMIT - 1         */
  LOCATE_HIGHEST,
};

/* Data structure for free program memory blocks */
extern struct pic32_memory *program_memory_free_blocks;

static void allocate_stack_in_dtcm (void);

static void
finish_section_info(struct pic32_section *s, lang_output_section_statement_type *os);

static int locate_options = 0;
static bfd_vma exclude_addr = 0;

static void
reset_locate_options(void) {
  locate_options = NO_LOCATE_OPTION;
  exclude_addr = 0;
}

#define IS_LOCATE_OPTION(a)  ((locate_options & (a)) == (a))

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




/*
 * reserve_space_for_vectors()
 *
 * This function reserve space at the beginning the given region for a copy of
 * .vectors section
 *
 * Called by: allocate_program_memory()
 *
 * Calls:     region_lookup()
 *            bfd_get_section_by_name()
 *            pic32_static_assign_memory()
 *
 */
static void 
reserve_space_for_vectors(struct pic32_region *regn)
{


    ///\ get .vectors
    asection                        *vectors_section =
    bfd_get_section_by_name(link_info.output_bfd, ".vectors");
    struct pic32_memory             *vectors_block = NULL;

    // ensure target region exists and is valid
    if (!pic32_valid_region(regn))
        return;

    PIC32_DEBUG( "allocating space for .vectors in %s", regn->region->name_list.name);


    if (vectors_section == NULL)
        return;

    ///\ keep the itcm->origin for .dinit dump
    pic32c_itcm_vectors_address = regn->region->origin;

    ///\ allocate .vectors as an absolute section
    vectors_block = pic32_static_assign_memory(regn->free_blocks,
                                               vectors_section->size,
                                               pic32c_itcm_vectors_address);
    if (vectors_block == NULL)
        einfo("%X Could not allocate .vectors at the beginning of itcm\n");
    
    create_remainder_blocks(regn->free_blocks,vectors_block, vectors_section->size);
}


static void generate_flash_vectors_symbol(char * const name)
{
    // add a symbol for .vectors if it was in the ld script
    asection   *vectors_section =
                bfd_get_section_by_name(link_info.output_bfd, ".vectors");
    if (vectors_section != NULL) {
	_bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, name,
					  BSF_GLOBAL, bfd_abs_section_ptr,
					  vectors_section->lma,
					  name, 1, 0, 0);
    }
}

static void generate_vectors_symbols (void)
{

    generate_flash_vectors_symbol("__svectors_nvm");
    
    ///\ generate itcm .vectors symbol
    _bfd_generic_link_add_one_symbol (&link_info, link_info.output_bfd, "__svectors",
                                BSF_GLOBAL, bfd_abs_section_ptr,
                                pic32c_itcm_vectors_address,
                                "__svectors", 1, 0, 0);
    
}


static void check_absolute_section(struct pic32_section *s)
{
    lang_memory_region_type *m;
//    bfd_boolean found = FALSE;
    if (s->sec == NULL) return;
    
    /* cannot do this - need to reach into ldlang to get a list of regions
     this check is a work in progress ... see XC32E-406
    for (m = lang_memory_region_list; m != NULL; m = m->next)
    {
	if ((s->sec->lma >= m->origin) && (s->sec->lma < (m->origin + m->length))) {
	    found = TRUE;
	    break;
	}
	
    }
    
    if (pic32c_debug) {
	if (found) PIC32_DEBUG("found absolute section %s in region %s ",s->sec->name, m->name_list.name);
	else PIC32_DEBUG("Error: invalid address for absolute section %s ",s->sec->name);
    }
    */

    if ((region_info.tcm_style == TCM_COMBINED) && pic32_valid_region(region_info.code_tcm)) {
	m = region_info.code_tcm->region;
	if ((s->sec->lma >= m->origin) && (s->sec->lma < (m->origin + m->length)))
	    einfo("Absolute section %s is in tcm memory.  Not permitted on this device. ",s->sec->name);
    }
}






static void
report_allocation_error(struct pic32_section *s) {
#define PREFIX "/tmp"
    char *colon = "";
    char *filename = "";
    char *secname = "*";
    char *s1 = pic32_section_size_string(s->sec);
    char *s2 = pic32_section_attr_string(s->sec);

    /* report the file name, unless its a temp file */
    if (strncmp(s->sec->owner->filename, PREFIX, strlen(PREFIX)) != 0) {
      colon = ":";
      filename = (char *) s->sec->owner->filename;
    }

    /* report the section name, unless its based on a temp file */
    if (strncmp(s->sec->name, PREFIX, strlen(PREFIX)) != 0)
      secname = (char *) s->sec->name;

    einfo(_("%X%s%s Link Error: Could not allocate section %s, %s, %s\n"),
          filename, colon, secname, s1 ? s1 : "", s2 ? s2 : "");
 
    if (s1) free(s1);  /* free the malloc'ed strings */
    if (s2) free(s2);

    PIC32_DEBUG("    Error: Could not allocate section %s", s->sec->name);
}



/*
 * This is really a helper for reset_pic32_section_sizes
 *
 * the space needed by a pic32_section and its children depends on the various alignments
 * of the section and its children.  To know for sure that a pic32-section will fit into
 * this size it is necessary that a child never have stricter alignment than the parent
 */

static bfd_size_type size_pic32_section_children(struct pic32_section*, uint32_t);

static bfd_size_type size_pic32_section_children(struct pic32_section* lst, uint32_t alignment){

     struct pic32_section  *s;
     bfd_size_type sum = 0;
     bfd_size_type children_size = 0;
     for (s = lst ; s != NULL ; s = s->next) {
	
	if (NULL != s->sec) {
            s->pic32_size = s->sec->size;
	    if (s->sec->alignment_power > alignment) alignment = s->sec->alignment_power;
	    // align sum to that needed by s ...
	    sum = (sum + (1 << s->sec->alignment_power) -1 ) & ~(uint32_t)((1 << s->sec->alignment_power) -1);

	    if(NULL != s->children){
		children_size = size_pic32_section_children(s->children, alignment);
		// round the size up to the next <alignment> boundary
		BFD_ASSERT (alignment <= s->sec->alignment_power);
		if (alignment > 0) s->pic32_size = ((s->pic32_size + (1 << alignment) -1)) & ~(uint32_t)((1 << alignment) -1);
		s->pic32_size += children_size;		
	    }
	    sum += s->pic32_size;
	}
     }
     return sum;
}


/*
 * We re-calculate the pic32_size field for a list of pic32 sections.
 * this is necessary for the unassigned section list after stubs have been added
 */

static void  size_pic32_sections(struct pic32_section*);

static void  size_pic32_sections(struct pic32_section* lst){


    struct pic32_section  *s;
    bfd_size_type children_size = 0;
    uint32_t alignment;
        
    for (s = lst ; s != NULL ; s = s->next) {
	
	if (NULL != s->sec) {
            s->pic32_size = s->sec->size;
	    
	    if(NULL != s->children){
		alignment = 0;
		children_size = size_pic32_section_children(s->children, alignment);
		// round the size up to the next <alignment> boundary
		BFD_ASSERT (alignment <= s->sec->alignment_power);
		if (alignment > 0) s->pic32_size = (s->pic32_size + (1 << alignment) -1) & ~(uint32_t)((1 << alignment) -1);
		s->pic32_size += children_size;
	    }
   	}
    }
    return;
}



/*
 * allocate_memory()
 *
 * This function attempts to locate sections using
 * a best-fit algorithm. The term "best-fit" implies
 * that the smallest suitable free block will be used
 * for each section. This approach makes efficient use
 * of the free block list and reduces fragmentation.
 *
 * Called by: ldemul_after_allocation()
 *
 * Calls:     allocate_program_memory()
 *            allocate_data_memory()
 *            bfd_map_over_sections()
 *
 * If any of the sub-processes fail, report it
 * and continue. This helps to suppress misleading
 * messages, and follows the general philosophy
 * of doing as much work as we can, despite the
 * occurrence of fatal errors.
 *
 * update 2022:  we now allow re-allocation which means
 * there could be more than one call to allocate_memory
 * we count the visits because some actions are only taken
 * the first time

 */

static int calls_to_allocate = 0;


void
allocate_memory (void)
{
  int result;
  char str[50];
  calls_to_allocate++;
  
#define ERR_STR " Link Error: Could not allocate "



  /*  this should not be necessary on the first allocation but shouldn't hurt
   *  after that it is necessary to account for stub sizes
   */
  size_pic32_sections(unassigned_sections);

  DEBUG({
      sprintf(str, "unassigned_sections at allocation no. %d",calls_to_allocate);
      pic32_print_section_list (unassigned_sections, str);
    });
  
  if ((calls_to_allocate == 1) && region_info.tcm_style == TCM_COMBINED) {  
    /*
     * with combined TCM we need to enforce a rule that programmers cannot mark any item as both
     * tcm and absolute.   If this is allowed it becomes very complicated to make sure that data
     * and code do not co-exist on the same cache line
     */
    struct pic32_section *s, *prev, *next;

    // check all the absolute sections to see that they make sense
    prev = unassigned_sections;
    for (s = prev; s != NULL; s = next) {
      if ((s->sec != NULL) && PIC32_IS_ABSOLUTE_ATTR(s->sec)) {
          check_absolute_section(s);
      }
      next = s->next;
    }
  }


  
  DEBUG({
      pic32_print_section_list(unassigned_sections, "unassigned");
      pic32_print_section_list(memory_region_list, "memory region");
    });

  /*
   * Build an ordered list of output sections
   * that were placed by sequential allocator.
   * It will help identify any gaps between
   * output sections that are available.
   */
  pic32_init_section_list (&pic32_section_list);

  bfd_map_over_sections (link_info.output_bfd, &pic32_build_section_list, NULL);
  bfd_map_over_sections (link_info.output_bfd, &pic32_build_section_list_vma, NULL);
    
  DEBUG({
      pic32_print_section_list(unassigned_sections, "unassigned");
      pic32_print_section_list(memory_region_list, "memory region");
    });
    
    /* build the free blocks list for all known regions. */
    pic32_build_free_blocks(&region_info);

    result = allocate_tcm_memory();
    if (result != 0)
        einfo(_("%F%stcm memory\n"), ERR_STR );

    result = allocate_data_memory();
    if (result != 0)
        einfo(_("%F%sdata memory\n"), ERR_STR );

    /* We can now estimate dinit merging as all sections belonging in .dinit
     * are allocated.
     * tcm is handled by allocate_tcm_memory
     * data/bss/ramfunc are handled by allocate_data_memory
     * the .dinit section is handled by allocate_program_memory
     */
    dinit_check_stubs();
    /* dinit analysis finished, size of dinit section may have changed */
    size_pic32_sections(unassigned_sections);


    result = allocate_program_memory();
    if (result != 0)
        einfo(_("%F%sprogram memory\n"), ERR_STR );

#ifdef ENABLE_USER_MEMORY
    if (has_user_defined_memory) {
        result = allocate_user_memory();
        if (result != 0)
            einfo(_("%F%suser-defined memory region\n"), ERR_STR );
    }
#endif

    // if vectors are not to be relocated, generate the symbols in the
    // default code region
    if (!pic32c_relocate_vectors) {
        generate_flash_vectors_symbol("__svectors_nvm");
        generate_flash_vectors_symbol("__svectors");
    }
  
    /* allocate the heap, if required */

  /* allocate the stack, unless the user has defined one */

  /* free the output section list */
  pic32_free_section_list(&pic32_section_list);

} /* allocate_memory() */




/*
 * allocate_tcm_memory()
 *
 * This function attempts to allocate all itcm and dtcm input memory sections.
 *
 * Called by: allocate_memory()
 *
 * Calls:     build_alloc_section_list()
 *            build_free_block_list()
 *            locate_sections()
 *            pic32_section_list_length()
 *
 * Returns:   status code
 *            (0 = success)
 */
static int
allocate_tcm_memory() {

  unsigned int mask = itcm|dtcm ;
  int result = 0;
  
  PIC32_DEBUG("Building allocation list for regions \"itcm\", \"dtcm\" and \"tcm\"\n"
	      "  attribute mask = %x", mask);

  build_alloc_section_list(mask, &alloc_section_list);
  // if (pic32_section_list_length(alloc_section_list) == 0)
  //   return result;


  DEBUG(pic32_print_section_list(alloc_section_list, "tcm input"));

// first we allocate itcm sections to itcm_region
// then we allocate dtcm input sections to dtcm_region
// these two might be the same ... in that case we will need to check that no free block in free_blocks has any partial cache line.
// for now the cache line size is hard coded - there is only one such family (Jubilee) and the line size is 16 bytes
// in the more common case that itcm and dtcm are separate memory regions we will need to build a new free block list


  if (!pic32_valid_region(region_info.code_tcm)) {
      // do not even try if itcm_region is not defined ...
      PIC32_DEBUG("no output region for itcm input sections  : not proceeding with BF allocation ");
  }
  else {
      if (pic32c_vectors_in_tcm && pic32_valid_region(region_info.vectors))  {
	      reserve_space_for_vectors(region_info.vectors);
	      generate_vectors_symbols();
      } 

      reset_locate_options();
      
      result |= locate_sections(address, dtcm, region_info.code_tcm, &alloc_section_list);   /* most restrictive  */
      result |= locate_sections(all_attr, dtcm, region_info.code_tcm, &alloc_section_list);  /* less restrictive */
  }
  
  if (!pic32_valid_region(region_info.data_tcm)) {
      // do not even try if dtcm_region is not defined ...
      PIC32_DEBUG("no output region for dtcm input sections  : not proceeding with BF allocation ");
  }
  else {
      // 
      // make sure that the free blocks list does not contain any partial cache lines
      // TODO: make cache line size configurable
      if (region_info.tcm_style == TCM_COMBINED)
	  align_free_blocks(region_info.data_tcm->free_blocks, JUBILEE_CACHE_LINE_ALIGNMENT_POWER);
      
      
      reset_locate_options();
      
      result |= locate_sections(address, 0, region_info.data_tcm, &alloc_section_list);   /* most restrictive  */
      result |= locate_sections(all_attr, 0, region_info.data_tcm, &alloc_section_list);  /* least restrictive */
  }

  if (pic32c_stack_in_tcm)
      allocate_stack_in_dtcm();

  
  return result;
} /* allocate_tcm_memory() */



/*
 * allocate_program_memory()
 *
 * This function attempts to allocate program memory sections.
 *
 * Called by: allocate_memory()
 *
 * Calls:     build_alloc_section_list()
 *            build_free_block_list()
 *            locate_sections()
 *            pic32_section_list_length()
 *
 * Returns:   status code
 *            (0 = success)
 */
static int
allocate_program_memory() {
  unsigned int mask = code ;
  int result = 0;

  PIC32_DEBUG("Building allocation list for region \"program\" \n"
           "  attribute mask = %x", mask);

  build_alloc_section_list(mask, &alloc_section_list);
  if (pic32_section_list_length(alloc_section_list) == 0)
    return result;

  DEBUG(pic32_print_section_list(alloc_section_list, "allocate_code"));

    
// now we  allocate the list of input sections we just built to ROM

  if (!pic32_valid_region(region_info.code)) {
      // do not bother going further if rom was not defined in the linker script ...
      PIC32_DEBUG( "no section named rom : not proceeding with BF allocation");

      return 0;
  }

  reset_locate_options();

  result |= locate_sections(address, itcm, region_info.code, &alloc_section_list);   /* most restrictive  */
  result |= locate_sections(all_attr, itcm, region_info.code, &alloc_section_list);  /* less restrictive */
  
  return result;
} /* allocate_program_memory() */



/*
 * allocate_data_memory()
 *
 * This function attempts to allocate data memory sections.
 *
 * Called by: allocate_memory()
 *
 * Calls:     build_section_list()
 *            build_free_block_list()
 *            locate_sections()
 *
 * Returns:   status code
 *            (0 = success)
 *
 * Notes: List "data_memory_free_blocks" is needed by
 *        bfd_pic32_finish() to allocate the stack
 *        and heap, so don't exit this function early.
 *        DZ: data_memory_free_blocks is now region_info.data->free_blocks, 
 *        but the same caveat about freeing the list applies.
 *
 *        EDS allocation is tricky. Although these sections
 *        can be allocated anywhere, we need to preserve
 *        low memory for the stack. In the first pass,
 *        we exclude memory below the stack limit altogether.
 *        In the second pass, we scan free blocks in reverse
 *        only, which helps when a block crosses the
 *        stack limit boundary. Eventually we'll take
 *        whatever memory we need to, and leave the rest
 *        for the stack and heap.
 *
 *        We also support allocation of stack and heap
 *        that are defined with section attributes.
 *
 *        See comments below for additional info
 *        about stack allocation.
 */
static int
allocate_data_memory() {
    struct pic32_section *s;
    unsigned int mask = data|persist|stack|heap|ramfunc;
    int result = 0;

    PIC32_DEBUG("Building allocation list for region \"data\"\n"
		"  attribute mask = %x", mask);

    // build a list of data sections to be allocated -should not contain any tcm
    // build a distinct list for bss to have bss sections one after the other
    build_alloc_section_list(mask, &alloc_section_list);
    build_alloc_section_list(bss, &alloc_bss_section_list);

    DEBUG({
        pic32_print_section_list(alloc_section_list, "allocate_data");
        pic32_print_section_list(alloc_bss_section_list, "allocate_bss");
      });

    if (!pic32_valid_region(region_info.data)) {
        // do not bother going further if  ram was not defined in the linker script ...
        PIC32_DEBUG("no section named ram : not proceeding with BF allocation");
        return 0; 
    }

    /* TODO: try to move the reserving of space for vectors outside of specific
       allocate functions. for now we do it here assuming allocate_tcm didn't, 
       based on the presence of the code_tcm region. */
    if (pic32c_relocate_vectors && !pic32c_vectors_in_tcm) {
      reserve_space_for_vectors(region_info.vectors);
      generate_vectors_symbols();
    }

    // now we allocate the sections on the list to ram
    // 
    reset_locate_options();
    result |= locate_sections(address, dtcm, region_info.data, &alloc_bss_section_list);
    result |= locate_sections(address, dtcm, region_info.data, &alloc_section_list);
    result |= locate_sections(all_attr, stack|heap|dtcm, region_info.data, &alloc_bss_section_list);
    result |= locate_sections(all_attr, stack|heap|dtcm, region_info.data, &alloc_section_list);


  /* Don't support user-defined stack sections yet */
  for (s = alloc_section_list; s != NULL; s = s->next) {
      /* lghica co-resident */
      if(s && (s->sec != NULL) && (s->sec->linked))
          continue;
      if (s->sec && (PIC32_IS_STACK_ATTR(s->sec) || PIC32_IS_HEAP_ATTR(s->sec))) {
	  lang_output_section_statement_type *os;
	  s->sec->lma = 0;
	  s->sec->vma = 0;
	  os = lang_output_section_statement_lookup (".stack", 0, TRUE);
	  /* lang_add_section() will call init_os() if needed */
	  lang_add_section (&os->children, s->sec, NULL, os);
	  finish_section_info(s, os);
	  pic32_remove_from_section_list(alloc_section_list,s);
	  os->bfd_section->flags = s->sec->flags;
      }
  }
  

  /* if any sections are left in the allocation list, report an error */
  for (s = alloc_section_list; s != NULL; s = s->next) {
  if ((s->attributes != 0) && (s->sec->linked == 0) /* lghica co-resident*/)
  {
    report_allocation_error(s);
    result = 1;
    break;
  }
  }

  /* if any sections are left in the allocation list, report an error */
  for (s = alloc_bss_section_list; s != NULL; s = s->next) {
  if ((s->attributes != 0) && (s->sec->linked == 0) /* lghica co-resident*/)
  {
    report_allocation_error(s);
    result = 1;
    break;
  }
  }

  return result;
} /* allocate_data_memory() */


#define OUTSIDE_REGION(addr, len, region)          \
  (((addr + len) <= region->origin)                \
   || (addr >= (region->origin + region->length)))

#define ACROSS_REGION(addr, len, region)                            \
  (((addr < region->origin) && ((addr + len) > region->origin)) ||  \
   ((addr < (region->origin + region->length)) &&                   \
    ((addr + len) > (region->origin + region->length))))




/*
 * locate_single_section()
 *
 * Helper function to locate a single section
 * using the free_blocks list.
 *
 * Called by: locate_sections()
 *
 * Returns:   status code
 *            (0 = success)
 */

static int
locate_single_section(struct pic32_section *s,
                      struct pic32_region *regn,
                      struct pic32_section **const ptr_alloc_list) {

  struct pic32_memory *b;
  bfd_vma len = s->pic32_size;
  bfd_vma addr = s->sec->lma;
  bfd_vma last_addr;
  
  int result = 0;

  s->region = NULL; /* initially unassigned */
  
  /* look for tricky user error */
  if (PIC32_IS_ABSOLUTE_ATTR(s->sec) && ACROSS_REGION(addr, len, regn->region))
        einfo(_(" Link Warning: absolute section \'%s\' crosses"
                " the boundary of region %s.\n"),
              s->sec->name, regn->region->name_list.name);
  
  if (len == 0)
    update_section_info(0,s,regn);       /* trivial case */
  else if (PIC32_IS_ABSOLUTE_ATTR(s->sec) &&
           OUTSIDE_REGION(addr, len, regn->region)) {
    update_section_info(addr, s, regn);  /* falls outside region */
  }
  else {                          /* locate using free_blocks list */
    b = select_free_block(regn, s, len);
    if (b) {
      addr = b->addr + b->offset;
      /*  we cannot just use 'len' when managing the free block list
       *  because alignment issues may have caused more than len bytes to be used.
       *  update_section_info will tell us how much space it needed
       */
      last_addr = update_section_info(addr,s,regn);
      len = last_addr - addr;
      create_remainder_blocks(regn->free_blocks,b,len);

      remove_free_block(regn->free_blocks,b);
    } else {
      if (locate_options != NO_LOCATE_OPTION) {
        PIC32_DEBUG("    \"%s\" location declined", s->sec->name);
        return 0;
      }
      result |= 1;
    }
  }


  PIC32_DEBUG("    removing %s from allocation list", s->sec->name);

  pic32_remove_from_section_list(*ptr_alloc_list,s);

  return result;
} /* locate_single_section() */


/*
 * locate_sections()
 *
 * This function attempts to locate all sections
 * in the section list that match a specified
 * attribute mask. The block argument specifies
 * attributes that disqualify a section.
 *
 * Called by: allocate_program_memory()
 *            allocate_data_memory()
 *            allocate_eedata_memory()
 *            allocate_auxflash_memory()
 *
 * Calls:     select_free_block()
 *            update_section_info()
 *            create_remainder_blocks()
 *            remove_free_block()
 *            remove_alloc_section()
 *
 * Returns:   status code
 *            (0 = success)
 */
static int
locate_sections(unsigned int mask, unsigned int block,
                struct pic32_region *regn, struct pic32_section** const ptr_alloc_list)
{
    struct pic32_section *s,*next;
    int result = 0;
    
    PIC32_DEBUG("Locating sections with mask %x, but not %x", mask, block);
    PIC32_DEBUG("  locate_options = %x, exclude_addr = %x",
		locate_options, exclude_addr);
    
    for (s = *ptr_alloc_list; s != NULL; s = next) {
	
	next = s->next;

       {
	    if (s->sec && (s->attributes & mask) &&
		((s->attributes & block) == 0)) {
		bfd_vma len = s->sec->rawsize? s->sec->rawsize: s->sec->size;

		DEBUG({
		    char *attr = pic32_section_attr_string(s->sec);
		    
		    LOG("  b \"%s\", len = %lx, %s",
			   s->sec->name, (unsigned long)len, attr ? attr : "");
		    if (attr) free(attr);
		  });
		
		result |= locate_single_section(s, regn, ptr_alloc_list);

	    }
	}
    }
    return result;
} /* locate_sections() */


/*
 * next_aligned_address()
 */
static bfd_vma
next_aligned_address( bfd_vma start, unsigned int align_power) {

  bfd_vma mask = ~((~0U) << align_power);
  return (bfd_vma) ((start + 1 + mask) & (~mask));
}


/*
 * prev_aligned_address()
 */
static bfd_vma
prev_aligned_address( bfd_vma start, unsigned int align_power) {

  bfd_vma mask = ~((~0U) << align_power);
  if (start < mask)
    return (bfd_vma) 0;
  else
    return (bfd_vma) ((start - 1 - mask) & (~mask));
}


/*
 * select_free_block()
 *
 * This function attempts to select a suitable
 * free block for a specified section. For each
 * free block, the section is positioned two ways:
 *  (1) as close to the starting address as possible,
 *  (2) as close to the ending address as possible.
 *
 * The position that leaves the largest unused
 * remainder space is selected. If a suitable free
 * block is found, the block offset is written into
 * the free block structure and the structure is returned.
 *
 * The selection algorithm can be fine-tuned by previous
 * calls to set_locate_options().
 *
 * Called by: locate_sections()
 *
 * Calls:     pic32_static_assign_memory()
 *            next_aligned_address()
 *            prev_aligned_address()
 *
 * Returns:   suitable free block, or 0
 */

#if 0
static void
confirm_dma_range_defined() {
  struct bfd_link_hash_entry *h;
  static bfd_boolean base_err_reported = FALSE;
  static bfd_boolean end_err_reported = FALSE;

  if ((!dma_base_defined) || (!dma_end_defined)) {

    h = bfd_pic32_is_defined_global_symbol(str3);
    if (h) {
      dma_base = h->u.def.value;
      dma_base_defined = TRUE;
    }
    else {
      if (!base_err_reported) {
        einfo(_(str1), str3);
        base_err_reported = TRUE;
      }
    }

    h = bfd_pic32_is_defined_global_symbol(str4);
    if (h) {
      dma_end = h->u.def.value;
      dma_end_defined = TRUE;
    }
    else {
      if (!end_err_reported) {
        einfo(_(str1), str4);
        end_err_reported = TRUE;
      }
    }
  }
}
#endif


static struct pic32_memory *
select_free_block(struct pic32_region *regn, struct pic32_section *s, unsigned int len) {

  unsigned int align_power = s->sec->alignment_power;

  const char *err_str1 = "Link Error: Could not allocate section";

  struct pic32_memory *b = 0;
  bfd_vma option1, limit1;
  bfd_vma option2, limit2;
  bfd_boolean option1_valid, option2_valid;
/* lghica co-resident */
    unsigned int    opb = bfd_octets_per_byte (link_info.output_bfd);
    bfd_vma         old_option1, new_option1;
    bfd_vma         old_option2, new_option2;
    
    
  /*
   * If the section is absolute, call the static function
   */
  if (PIC32_IS_ABSOLUTE_ATTR(s->sec))
  {
      b = pic32_static_assign_memory(regn->free_blocks, len, s->sec->lma);
      if (!b) {
	  if ((s->sec->flags & SEC_NEVER_LOAD) ||
	      (command_line.check_section_addresses == FALSE))
	      /* OK, don't report as error */;
	  else
	      einfo(_("%X %s \'%s\' at 0x%v\n"),
		    err_str1, s->sec->name, s->sec->lma);
	  return (struct pic32_memory *) NULL;
      } else
	  return b;
  }


  /*
   * Loop through the free blocks list
   */
  for (b = regn->free_blocks; b != NULL; b = b->next) {

    if ((b->addr == 0) && (b->size == 0))
      continue;

    PIC32_DEBUG("    consider block at %x, len = %x", b->addr, b->size);

    /*
     * Qualify the block first, so we don't waste
     *  time scanning for alignment.
     */
    if (b->size < len)
      continue;


    /* qualify NEAR with leftmost position in free block */
    if (PIC32_IS_NEAR_ATTR(s->sec) && !VALID_NEAR(b->addr, len))
      continue;

    /* qualify LOW_ADDR with leftmost position in free block */
    if (IS_LOCATE_OPTION(EXCLUDE_HIGH_ADDR) &&
        !VALID_LOW_ADDR(b->addr, len))
      continue;

    /* qualify HIGH_ADDR with rightmost position in free block */
    if (IS_LOCATE_OPTION(EXCLUDE_LOW_ADDR) &&
        !VALID_HIGH_ADDR((b->addr + b->size - len), len))
      continue;

    /* fall through if block passes pre-qual tests */

    /* Compute option1: scan from the start of the block */
    option1 = b->addr - 1 ;
    limit1  = b->addr + (b->size - len);
    option1_valid = TRUE; /* set default */
    PIC32_DEBUG("    option1 [advancing from %x]", option1 + 2);
    while (1) {

      if (IS_LOCATE_OPTION(FAVOR_HIGH_ADDR)) {
        option1_valid = FALSE;
        break;
      }

      /* find the next aligned address */
      if (PIC32_IS_REVERSE_ATTR(s->sec)) {
        option1 = next_aligned_address(option1 + len, align_power);
        option1 -= len;
      }
      else
        option1 = next_aligned_address(option1, align_power);

      if (option1 > limit1) {
        option1_valid = FALSE;
        break;
      }


      PIC32_DEBUG("    option1 aligned at %x", option1);

      /* aligned address is valid, check other attributes */


        if (PIC32_IS_NEAR_ATTR(s->sec)  && !VALID_NEAR(option1, len)) {
        option1_valid = FALSE;  /* scanning forward won't help */
        break;
      }
        
      /* lghica co-resident */
#if 1
        /* this check is necessary for Co-resident applications */
        /* to make sure persistent data is not over written at any time */
        
        if (PIC32_IS_PERSIST_ATTR(s->sec) || PIC32_IS_SHARED_ATTR(s->sec))
        {
            old_option1 = option1;
            new_option1 = option1;
            struct pic32_section *ls;
            for (ls = alloc_section_list; ls != NULL; ls = ls->next)
            {
                if (ls->sec && (ls->sec->linked == 1))
                {
                    if (((ls->sec->lma <= old_option1)
                         && (old_option1 < (ls->sec->lma + (ls->sec->rawsize / opb)))))
                    {
                        new_option1 = ls->sec->lma + (ls->sec->rawsize / opb);
                        break;
                    }
                }
            }
            if (new_option1 != old_option1)
                continue;
            else
                option1= new_option1;
        }
#endif
        
      if (IS_LOCATE_OPTION(EXCLUDE_LOW_ADDR) &&
          !VALID_HIGH_ADDR(option1, len)) {
        option1 = exclude_addr - 1;  /* skip ahead */
	PIC32_DEBUG("    approaching EXCLUDE boundary from %x", option1);
        continue;
      }

      /* if we get here, the option is valid */
      break;
    } /* while (!done) */

    /* Compute option2: scan from the end of the block       */
    /*                  unless the section is BOOT or SECURE */
    option2 = limit1 + 1;
    limit2  = b->addr;
      option2_valid = TRUE; /* set default */
      PIC32_DEBUG("    option2 [descending from %x]", option2 - 2);
      while (1) {

        if (IS_LOCATE_OPTION(FAVOR_LOW_ADDR)) {
          option2_valid = FALSE;
          break;
        }

        /* find the next aligned address */
        if (PIC32_IS_REVERSE_ATTR(s->sec)) {
          option2 = prev_aligned_address(option2 + len, align_power);
          option2 -= len;
        }
        else
          option2 = prev_aligned_address(option2, align_power);

        if (option2 < limit2) {
          option2_valid = FALSE;
          break;
        }

	PIC32_DEBUG("    option2 aligned at %x", option2);

          /* lghica co-resident */
#if 1
          /* this check is necessary for Co-resident applications */
          /* to make sure persistent data is not over written at any time */
          if (PIC32_IS_PERSIST_ATTR(s->sec) || PIC32_IS_SHARED_ATTR(s->sec)) {
              old_option2 = option2;
              new_option2 = option2;
              struct pic32_section *ls;
              for (ls = alloc_section_list; ls != NULL; ls = ls->next)
              {
                  if (ls->sec && (ls->sec->linked == 1))
                  {
                      if (((ls->sec->lma <= old_option2)
                           && (old_option2 < (ls->sec->lma + (ls->sec->rawsize / opb)))))
                      {
                          new_option2 = ls->sec->lma - len;
                          break;
                      }
                  }
              }
              if (new_option2 != old_option2) 
                  continue;
              else
                  option2= new_option2;
          }
#endif
        if  (PIC32_IS_NEAR_ATTR(s->sec)    && !VALID_NEAR(option2, len)) {
          option2 = NEAR_BOUNDARY - len + 1;  /* skip back */
	  PIC32_DEBUG("    approaching Near boundary from %x", option2);
          continue;
        }


        if (IS_LOCATE_OPTION(EXCLUDE_HIGH_ADDR) &&
            !VALID_LOW_ADDR(option2, len)) {
          option2 = exclude_addr - len + 1;  /* skip back */
	  PIC32_DEBUG("    approaching EXCLUDE boundary from %x", option2);
          continue;
        }

        /* if we get here, the option is valid */
        break;
      } /* while (!done) */

    if ((option1_valid == FALSE) && (option2_valid == FALSE))
      continue;  /* try the next free block */

    DEBUG(LOG("    "));
    if (option1_valid)
      DEBUG(LOG("option1 = %x, ", option1));
    if (option2_valid)
      DEBUG(LOG("option2 = %x", option2));
    DEBUG(LOG("\n"));


    /* we have 1 or 2 valid options */
    if (option1_valid == FALSE)
      b->offset = option2 - b->addr;
    else if (option2_valid == FALSE)
      b->offset = option1 - b->addr;
    else {
      /* compare the two "outer" remainders */
      bfd_vma rem1 = option1 - b->addr;
      bfd_vma rem2 = (b->addr + b->size) - option2 - len;

      b->offset = (rem1 > rem2) ?
                  (option2 - b->addr) : (option1 - b->addr);
    }

    return b;
  } 

  /* If we get here, a suitable block could not be found */
  if (locate_options != NO_LOCATE_OPTION)
    return (struct pic32_memory *) NULL; /* exit quietly */
  else
    report_allocation_error(s);

#if 0
  {
#define PREFIX "/tmp"
    char *colon = "";
    char *filename = "";
    char *secname = "*";
    char *s1 = pic32_section_size_string(s->sec);
    char *s2 = pic32_section_attr_string(s->sec);

    /* report the file name, unless its a temp file */
    if (strncmp(s->sec->owner->filename, PREFIX, strlen(PREFIX)) != 0) {
      colon = ":";
      filename = (char *) s->sec->owner->filename;
    }

    /* report the section name, unless its based on a temp file */
    if (strncmp(s->sec->name, PREFIX, strlen(PREFIX)) != 0)
      secname = (char *) s->sec->name;

    einfo(_("%X%s%s Link Error: Could not allocate section %s, %s, %s\n"),
          filename, colon, secname, s1 ? s1 : "", s2 ? s2 : "");

    if (s1) free(s1);  /* free the malloc'ed strings */
    if (s2) free(s2);

    PIC32_DEBUG("    Error: Could not allocate section %s", s->sec->name);
  }
#endif

  return (struct pic32_memory *) NULL;
} /* select_free_block() */

static char *
unique_section_name(const char *s) {
  static int auto_sec_cnt = 0;
  char *name;
  int len;

  len = strlen(s) + 1 + 5;
  name = xmalloc (len + 1);
  snprintf(name, len, "%s%s%d", s, "%", ++auto_sec_cnt);
  return name;
}


static char *
unique_zero_length_section_name(const char *s) {
  static int auto_zero_sec_cnt = 0;
  char *name;
  int len;

  len = strlen(s) + 2 + 5;
  name = xmalloc (len + 1);
  snprintf(name, len, "%s%s%d", s, "%z", ++auto_zero_sec_cnt);
  return name;
}

/*
 * finish_section_info()
 *
 * called by:
 *  update_section_info()
 *
 * Note that we don't copy in the section size,
 * because lang_process() will calculate the
 * output section size after the emulation
 * returns control.
 */
static void
finish_section_info(struct pic32_section *s, lang_output_section_statement_type *os)
{
  etree_type *addr_tree;

  if (os->bfd_section == NULL) /* --gc-sections discarded this, so done */
    return;
  os->bfd_section->vma = s->sec->vma;
  os->bfd_section->lma = s->sec->lma;
  os->bfd_section->bfa = 1;
  addr_tree = xmalloc(sizeof(etree_type));
  addr_tree->value.type.node_class = etree_value;
  addr_tree->value.value = s->sec->vma;
  os->addr_tree = addr_tree;

} /* finish_section_info() */


#define update_section_addr(s,addr)                     \
  {                                                     \
  s->lma = addr;                                        \
  s->vma = addr;                                        \
  }

/*
 * update_children_info()
 *
 * Update section info after allocation for the children of s
 * this is recursive
 */

bfd_vma 
update_children_info(lang_output_section_statement_type*,struct pic32_region *,struct pic32_section *,bfd_vma);

bfd_vma update_children_info(lang_output_section_statement_type *os,
			     struct pic32_region *regn,
			     struct pic32_section *section_list,
			     bfd_vma alloc_addr)  {

    struct pic32_section *s;

    for (s =section_list ; s != NULL; s = s->next) {
	if (s->sec) {
	    /* advance alloc_addr to alignment needed by s->sec */
	    if (s->sec->alignment_power >0) {
                alloc_addr = (alloc_addr + (1 << s->sec->alignment_power) -1 ) & ~(uint32_t)((1 << s->sec->alignment_power) -1);
	    }
	    update_section_addr(s->sec, alloc_addr);
	    alloc_addr += s->sec->size;
	    lang_add_section (&os->children, s->sec, NULL, os);
            s->region=regn;
	    PIC32_DEBUG("    updating info for child %s:"
		       "  vma = %x, lma = %x   ps = %d s = %d", s->sec->name,s->sec->vma, s->sec->lma,s->pic32_size,s->sec->size);
	}
	if (NULL != s->children) alloc_addr = update_children_info(os,regn,s->children,alloc_addr);
    }
    return alloc_addr;
}





/*
 * update_section_info()
 *
 * Update section info after allocation
 *
 * If section was a heap or stack, set some globals.
 *
 */
bfd_vma
update_section_info(bfd_vma alloc_addr,
                    struct pic32_section *s,
                    struct pic32_region *regn) {


  bfd_vma  last_addr = alloc_addr + s->pic32_size ;
  lang_output_section_statement_type *os;
  char *name;

  update_section_addr(s->sec, alloc_addr);

  PIC32_DEBUG("    updating info for section %s:"
	      "  vma = %x, lma = %x   ps = %d s = %d", s->sec->name,s->sec->vma, s->sec->lma,s->pic32_size,s->sec->size);

  /* create a unique name for the output section */
  name = (s->pic32_size > 0) ?
  unique_section_name(s->sec->name) :
  unique_zero_length_section_name(s->sec->name);

  /* create an output section (statement) */
  os = lang_output_section_statement_lookup (name, 0, TRUE);

  PIC32_DEBUG("    creating output section statement \"%s\"", os->name);

  /* lang_add_section() will call init_os() if needed */
  lang_add_section (&os->children, s->sec, NULL, os);

  /* loop recursively through the children of this pic32_section, if any  */
  /* they are allocated sequentially  in the same output section */
  /* they may go further than expected if they need special alignment */
  if (NULL != s->children) {
      last_addr = update_children_info(os,regn,s->children,alloc_addr + s->sec->size);
  }



  
  finish_section_info(s, os);

  /* hook section up to target region */
  s->region = regn;

  return last_addr;
} /* update_section_info() */



/*
 * create_remainder_blocks()
 *
 * Create [0,1,2] remainder blocks based on
 * block->offset and section->size.
 */
static void
create_remainder_blocks(struct pic32_memory *lst,
                        struct pic32_memory *b, unsigned int len) {

  bfd_vma remainder = b->size - (len + b->offset);

  PIC32_DEBUG("    creating remainder blocks: %x, %x",
	      b->offset, remainder);

  if (b->offset > 0)  /* gap at beginning */
    pic32_add_to_memory_list(lst, b->addr, b->offset);

  if (remainder > 0)  /* gap at end */
    pic32_add_to_memory_list(lst,
                             b->addr + b->offset + len, remainder);
} /* create_remainder_blocks() */


/*
 * insert_alloc_section()
 *
 * Insert a pic32_section into the list
 *  in order of decreasing size or alignment power.
 *
 * Note: a new copy of the pic32_section is made
 *
 *
 * Update Nov 2022 . a list of pic32 sections is now a tree since each pic32_section can have children ...
 * we now use the pic32_size field in the pic32_section instead of sec->size.  This number reflects
 * the size of this section plus all of its children
 */

static struct pic32_section *ramfunc_section;

static void
insert_alloc_section (struct pic32_section *lst,
                      struct pic32_section *as)
{
  struct pic32_section *new, *prev, *s;
  int done = 0; 
  
  /* create a new element */
  new = pic32_copy_section(as);

  /* for ramfunc sections we accumulate them as children of the first one we encounter, incrementing the size as we go
   * it will be added to the list at the end when we know the final size
   */
  if (as->sec && (PIC32_IS_RAMFUNC_ATTR(as->sec))) {
      if (NULL == ramfunc_section) ramfunc_section = new;
      else {
	  if (NULL == ramfunc_section->children)  pic32_init_section_list(&ramfunc_section->children);
	  /* insert it at the end of the list of children
	  * first find the end of that list
	  */
	  for(s = ramfunc_section->children;  s->next!=NULL ; s = s->next){};
	  s->next = new;
	  new->next = NULL;
	  ramfunc_section->pic32_size += as->pic32_size;
      }
      return;
  }


  /* insert it at the right spot */
  /* alignment power gets propagated from  children to parents
     in elf32_arm_add_stub_section  */
  prev = lst;
  for (s = prev; s != NULL; s = s->next)
    {
      if (s->sec && ((new->pic32_size > s->pic32_size) ||
          ((bfd_vma)(1 << new->sec->alignment_power) > s->pic32_size)) ) {
        prev->next = new;
        new->next = s;
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
} /* insert_alloc_section() */


/*
 * build_alloc_section_list()
 *
 * Build alloc_section_list from the
 * list of unassigned_sections, based on
 * an attribute mask.
 *
 * Sort the list in order of decreasing S,
 * where S is the greater of size and
 * alignment requirement.
 *
 * Note: If a section has length zero,
 * we allocate it anyway, although it
 * is stripped from the output file.
 * The linker needs to have an output
 * section statement created for it.
 *
 * Future enhancement:
 *   If --re-order-sections is set, also
 *   add explicity mapped output sections
 *   unless they have an absolute address.
 */
static void
build_alloc_section_list(unsigned int mask, struct pic32_section ** const ptr_alloc_list) {
  struct pic32_section *s, *prev, *next;

  if (ramfunc_section)
    pic32_free_section_list(&ramfunc_section);
  ramfunc_section = NULL;
  
  if (*ptr_alloc_list)
    pic32_free_section_list(ptr_alloc_list);

  pic32_init_section_list(ptr_alloc_list);


  /* insert the unassigned sections */
  prev = unassigned_sections;
  for (s = prev; s != NULL; s = next) {
    next = s->next;
    /* Don't add gc-sections to the alloc list */
    if ((NULL == s->sec) || (s->sec->flags & SEC_EXCLUDE))
      continue;    

    if (s->attributes & mask) {
        PIC32_DEBUG("  input section \"%s\", len = %x, flags = %x, attr = %x",
		    s->sec->name, s->pic32_size, s->sec->flags, s->attributes);
	
	insert_alloc_section(*ptr_alloc_list, s);
	prev->next = next; /* unlink it from unassigned_sections */        
    } else {
        PIC32_DEBUG("  input section (skipped) \"%s\", len = %x, flags = %x, attr = %x",
		    s->sec->name, s->pic32_size, s->sec->flags, s->attributes);
	prev = s;
    }
  }
  /* now we add the ramfunc sections to the list.  we dont call insert_alloc_section to do this
   * because they have already been copied.  We just add them into the right spot.
   */
  if (NULL != ramfunc_section) {
      
      int done = 0; 
      prev =  *ptr_alloc_list;

      
      
      for (s = *ptr_alloc_list; s != NULL; s = s->next)
	  {
	      if (s->sec && ((ramfunc_section->pic32_size > s->pic32_size) ||
			     ((bfd_vma)(1 << ramfunc_section->sec->alignment_power) > s->pic32_size)))  {
		  prev->next = ramfunc_section;
		  ramfunc_section->next = s;
		  done++;
		  break;
	      }
	      prev = s;
	  }
      
      if (!done)
	  {
	      prev->next = ramfunc_section;
	      ramfunc_section->next = NULL;
	  }
      ramfunc_section = NULL;
  }
} /* build_alloc_section_list() */


/*
 * build_free_block_list()
 *
 * Build a list of free memory blocks
 * in a specified region.
 *
 * Sort the list in order of increasing size.
 *
 * Future enhancement:
 *   If --re-order-sections is set, add free blocks
 *   for explicity mapped output sections unless
 *   they have an absolute address.
 */
static void
build_free_block_list(struct pic32_region *regn,
                      unsigned int mask ATTRIBUTE_UNUSED) {
  int cnt = 0;
  bfd_vma len, dot, limit, ma;
  struct pic32_section *s;
  struct memory_region_struct *region = regn->region;
  struct pic32_memory *b,*next;

  /* if the free blocks are already there then free them - we are realllocating */
  if (NULL != regn->free_blocks) {
      for (b = regn->free_blocks; b != NULL; b = next) {
	  next = b->next;
	  free(b);
      }
  }


  pic32_init_memory_list(&regn->free_blocks);

  PIC32_DEBUG("Building free block list for region \"%s\"\n"
	      "  origin = %x, length = %x, current = %x",
	      region->name_list.name, region->origin, region->length, region->current );
  

  /* find any gaps left by sequential allocator */
  dot = region->origin;
  limit = dot + region->length;
  for (s = pic32_section_list; s != NULL; s = s->next) {

      if (s->sec)
	  PIC32_DEBUG("    Checking (section \"%s\", lma = %x, vma = %x, len = %x, attr = %x)",
		      s->sec->name, s->sec->lma, s->sec->vma,
		      s->sec->rawsize? s->sec->rawsize : s->sec->size,
		      s->attributes);
      
    if (s->sec && (s->use_vma==0) &&
        (s->sec->lma >= region->origin)
        && (s->sec->lma <= (region->origin + region->length))
        && (s->sec->lma!=0)
        )
        ma = s->sec->lma;
    else if (s->sec && (s->use_vma) &&
        (s->sec->vma >= region->origin) &&
           (s->sec->vma <= (region->origin + region->length)))
        ma = s->sec->vma;
    else
        ma = 0;

    if ((s->sec) && ((s->sec->rawsize | s->sec->size) > 0) &&
        (ma || ( (s->sec->lma == 0x0) && (region->origin == 0x0)))
        ) {
        PIC32_DEBUG("    (section \"%s\", addr = %x, len = %x, attr = %x)",
		    s->sec->name, ma,
		    s->sec->rawsize? s->sec->rawsize : s->sec->size,
		    s->attributes);
	if (ma == dot)                   /* no gap, just advance dot */
	    dot += s->sec->rawsize? s->sec->rawsize : s->sec->size;
	else if (ma >= limit)   /* section belongs to another region */
	    continue;
	else if (ma > dot) {               /* a gap preceeds section */
	    len = ma - dot;                          /* compute length */
	    PIC32_DEBUG("  block %d, addr = %x, len = %x",
			++cnt, dot, len);
	    pic32_add_to_memory_list(regn->free_blocks, dot, len);  /* add free block */
	    dot += len + (s->sec->rawsize? s->sec->rawsize : s->sec->size);           /* advance dot    */
	}
    }
  }

  /* add a block for any free space remaining in this region */
  /* .. use dot, because region->current may have been set for CodeGuard */
  len = region->length - (dot - region->origin);
  if (len > 0) {
      PIC32_DEBUG("  block %d, addr = %x, len = %x",
		  ++cnt, dot, len);
      pic32_add_to_memory_list(regn->free_blocks, dot, len);
  }
} /* build_free_block_list() */


/*
 * remove_free_block()
 *
regn-> * Remove an item from the free memory blocks list.
 *
 */
static void
remove_free_block(struct pic32_memory *lst, struct pic32_memory *b) {
  pic32_remove_from_memory_list(lst, b);
}


/*
 * align_free_blocks(unsigned int)
 *
 * go through the free block list and trim away any partial cache lines ...
 * this is necessary on some parts where code and data can both be allocated to the same space but
 * are not permitted to share cache lines.
 *
 * specifically we are doing this for Jubilee tcm allocation
 */
static void
align_free_blocks(struct pic32_memory *lst, unsigned int alignment_power) {

    bfd_vma bump_amount;
    bfd_vma alignment_amount = 1 << alignment_power;
    struct pic32_memory     *block;
    
    for(block = lst; block != NULL ; block = block->next){
	// for each free block in the list trim away partial cache lines at either end.

	bump_amount = block->addr % alignment_amount;
	if (bump_amount > 0) {
	    bump_amount = alignment_amount - bump_amount;
	    block->addr += bump_amount;
	    block->size -= bump_amount;
	}
	bump_amount =  (block->size % alignment_amount);
	if (bump_amount > 0) {
	    block->size -= bump_amount;            
	}	
    }   
}





/*
 * allocate_default_stack()
 *
 * If a stack section was not explicitly defined,
 * and the stack init symbols were not defined,
 * then this function is called to allocate the
 * largest stack possible from the given region.
 *
 * Called by: bfd_pic32_finish()
 *
 * Calls:     pic32_add_to_memory_list()
 *            pic32_remove_from_memory_list()
 *
 * Returns:   sets global vars stack_base, stack_limit
 *
 * Notes: The free blocks list is sorted in order
 *        of increasing size
 *
 *        The calling function will confirm that
 *        the resulting stack satisfies the minimum
 *        size requirements.
 *
 *
 */

void
allocate_default_stack(struct pic32_region *regn) {
  struct pic32_memory *big_block = 0;
  struct pic32_memory *b, *next;
  bfd_vma under,over;
  bfd_vma max_addr;

  if (!pic32_valid_region(regn)) {
      PIC32_DEBUG( "allocate_default_stack failed - invalid pic32 region");
      abort();
  }

  max_addr = regn->region->origin + regn->region->length - 1;

  if (regn->free_blocks == NULL) {
      einfo("%P%F: Error: Unable to allocate stack. No blocks available in %s. \n",
            regn->region->name_list.name);
      return;
  }
    
    
  /* if a free block straddles the upper limit, divide it */
  for (b = regn->free_blocks; b != NULL; b = next) {
    next = b->next;
    if ((b->addr < max_addr) && ((b->addr + b->size) > max_addr)) {

        PIC32_DEBUG("  free block at %x crosses upper stack limit (%x)",
		    b->addr, max_addr);

	under = max_addr - b->addr;
	over  = (b->addr + b->size) - max_addr;
	
	pic32_add_to_memory_list(regn->free_blocks, b->addr, under);
	pic32_add_to_memory_list(regn->free_blocks, max_addr, over);
	pic32_remove_from_memory_list(regn->free_blocks, b);
	break;
    }
  }

  /* find the largest block that qualifies */
  for (b = regn->free_blocks; b != NULL; b = next) {
    if (b->addr < max_addr)
      big_block = b;
    next = b->next;
  }

  if ((unsigned int)(pic32c_heap_size) >
      (unsigned int)big_block->size) {
    heap_base = (big_block->addr + 1);
    heap_limit = (heap_base + (big_block->size) - 0x80u);
    einfo("%P%X Error: Not enough memory for heap"
          " (%u bytes needed, %u bytes available)\n",
            (unsigned int)(pic32c_heap_size),
            (unsigned )(heap_limit - heap_base));
  } else {
    heap_base = (big_block->addr + 1);
    heap_limit = (heap_base + pic32c_heap_size);
  }
  while (heap_base % 8 != 0)
    heap_base++;
  while (heap_limit % 8 != 0)
    heap_limit++;

  stack_base  = (heap_limit + 1 + pic32c_stackguard_size);
  stack_limit = (heap_base + big_block->size
                 - pic32c_stackguard_size + 1);
  /* Stack must be aligned by 8 */
  while (stack_base % 8 != 0)
    stack_base++;
  while (stack_limit % 8 != 0)
    stack_limit--;

  PIC32_DEBUG("  selecting block at %x", big_block->addr);
  PIC32_DEBUG("  heap base = %x, heap limit = %x", heap_base, heap_limit);
  PIC32_DEBUG("  stack base = %x, stack limit = %x", stack_base, stack_limit);


  /* remove the block that we just used */
  pic32_remove_from_memory_list(regn->free_blocks, big_block);
}

static void 
allocate_stack_in_dtcm (void)
{
    struct pic32_memory     *block = NULL;
    struct pic32_memory     *iter;
    unsigned int            max_size = 0;
  
    if (!pic32_valid_region(region_info.data_tcm)) {
        einfo(_("%X Link error: requested stack in dtcm but dtcm region not present\n"));
        return;
    }

    lang_memory_region_type *dtcm_region = region_info.data_tcm->region;
    struct pic32_memory *free_blocks = region_info.data_tcm->free_blocks;

    if (free_blocks == NULL) {
        einfo("%P%F: Error: Unable to allocate stack. No blocks available in %s. \n",
              dtcm_region->name_list.name);
        return;
    }
    
    ///\ stack gets the largest, and preferably the highest address
    ///\ lookup for the free block with this property(ies)
    for (iter = free_blocks; iter != NULL; iter = iter->next) {
	if (iter->size > max_size)
        {
            block = iter;
            max_size = iter->size;
        }
    }
    
    ///\ check that addresses from data_memory_free_blocks belong to dtcm

    if (block == NULL || (block->addr > (unsigned long)(dtcm_region->origin + dtcm_region->length+1))
        || (block->addr < (unsigned long)dtcm_region->origin))
        einfo(_("%X Link Error: Data memory free blocks built for incorrect region\n"));
    
    
    dtcm_stack_limit = block->addr + block->size - 1 ;
    
    while (dtcm_stack_limit % 8 != 0)
        dtcm_stack_limit--;
    
    dtcm_stack_base = (block->addr%8)? (block->addr)
    : (block->addr + (8 - block->addr%8)) ;
    
    pic32_remove_from_memory_list(free_blocks, block);
}

/*
 * dinit_check_stubs()
 *
 * If .dinit has grown in size since initial estimation init_data needs to be
 * reallocated to avoid buffer overflows.
 *
 * If .dinit grew this function will mark the old section to be discarded
 * then create a new section of appropriate size finally it will add it to be
 * allocated.
 *
 * Called by: allocate_memory()
 *
 */

static void dinit_check_stubs() {
  int dinit_resize = check_dinit_growth(&link_info);
  if (dinit_resize) {
    PIC32_DEBUG("\noptim_dinit Resizing dinit section to 0x%x\n",
		dinit_resize);
    dinit_size =
        dinit_resize; // Update for _dinit_size symbol which we don't use?
    init_template->flags = SEC_EXCLUDE; // Discard old .dinit section
    int flags = SEC_CODE | SEC_HAS_CONTENTS | SEC_IN_MEMORY | SEC_KEEP |
                SEC_LINKER_CREATED | SEC_ALLOC | SEC_READONLY;
    init_template = bfd_pic32_create_section(init_bfd, ".dinit", flags, 2);
    /* We need to let **something** create the output section for us or flags
     * will not be right */
    init_template->output_section = NULL;
    bfd_set_section_size(init_bfd, init_template, dinit_resize);
    init_data = (unsigned char *)bfd_alloc(link_info.output_bfd, dinit_resize);
    init_data = memset(init_data, 0x11, dinit_resize);
    init_template->contents = init_data;

    if (pic32_dinit_has_absolute_address) {
      bfd_set_section_vma(init_bfd, init_template, dinit_address);
      PIC32_SET_ABSOLUTE_ATTR(init_template);
    }

    /* Add the new .dinit section to unassigned_sections so the BFA sees it */
    pic32_append_section_to_list(unassigned_sections, init_template);
    pic32_append_section_to_list(unassigned_sections_master_copy,
                                 init_template);
  }
  /* Finalize size with optimizations */
  estimate_dinit_merging();
}

#ifdef ENABLE_USER_MEMORY

static int
compare_memory_region_origin (const void *a, const void *b)
{
  const asection *sec1 = *(const asection **) a;
  const asection *sec2 = *(const asection **) b;

 
  /* If there's no section for some reason, compare equal.  */
  if (!sec1 || !sec2)
    return 0;
  
  if (sec1->vma < sec2->vma)
    return -1;
  else if (sec1->vma > sec2->vma)
    return 1;
  
  return 0;
}

static void
check_overlapping_memory_regions (asection **asec_list, unsigned int asec_count)
{
  unsigned int i ;
  asection* a = NULL ;
  asection* b = NULL ;
  const char *asec_name = NULL ;
  const char *bsec_name = NULL ;
  
  for (i=0; i<(asec_count-1); i++)
  {
    a = asec_list[i];
    b = asec_list[i+1];
    
    if ( (a->vma + a->lma) >= b->vma )
    {
        asec_name = a->name + strlen(memory_region_prefix) + 1;
        bsec_name = b->name + strlen(memory_region_prefix) + 1;

        einfo(_(" Link Error: user defined memory region \'%s\' crosses"
                " the boundary of region '%s'.\n"),
                asec_name, bsec_name);
    }
  }
}


static void
validate_memory_region_list()
{
  /* Build a sorted list of memory regions, then use that to validate */
  struct pic32_section *r, *rnext;
  unsigned int list_size = 10;
  unsigned int sec_count = 0;

  asection **sec_list = (asection **)
    xmalloc (list_size * sizeof (asection *));

  for (r = memory_region_list; r != NULL; r = rnext) 
  {
    rnext = r->next;
    asection *asec = r->sec;
    if (asec) 
    {
      if (sec_count == list_size) 
      {
        list_size *= 2;
        sec_list = (asection **) 
        xrealloc (sec_list, list_size * sizeof (asection *));
      }

      sec_list[sec_count++] = asec;
    }
  }

  qsort (sec_list, sec_count, sizeof (asection *), &compare_memory_region_origin);
  check_overlapping_memory_regions(sec_list, sec_count);
  free (sec_list);

  return ;
}



/*
 * allocate_user_memory()
 *
 * This function attempts to allocate sections
 * in user-defined memory regions.
 *
 * Called by: allocate_memory()
 *
 * Calls:     build_section_list()
 *            build_free_block_list()
 *            locate_sections() 
 *
 * Returns:   status code
 *            (0 = success)
 */
static int
allocate_user_memory() {
  struct memory_region_struct temp_region;
  struct pic32_section *r, *rnext, *s, *snext, *ss, *ssnext, *ssprev;
  const char *region_name;
  int result = 0;

  /* Validate that the memory regions aren't overlapping*/
  validate_memory_region_list();

  /* loop through any user-defined regions */
  for (r = memory_region_list; r != NULL; r = rnext) {
  
    rnext = r->next;
    if (r->sec == 0) continue;
    
    region_name = r->sec->name + strlen(memory_region_prefix);
    PIC32_DEBUG("Building allocation list for user-defined region \"%s\""
		" origin = %lx, length = %lx",
		region_name, r->sec->vma, r->sec->lma);

    /* the assembler will not accept a memory region
       definition with length 0... if we see one here,
       it indicates that a section has referenced a
       region that was never defined */
    if (r->sec->lma == 0)
      einfo(_("%s: Link Error: Memory region \'%s\' has been referenced"
              " but not defined\n"),
              r->sec->owner->filename, region_name);

    /* loop through the list of memory-type sections..
       note that only two fields of this list are
       used (file, sec) and they are both (char *) */
    for (s = user_memory_sections; s != NULL; s = snext) {

      snext = s->next;
      if (!s->file || !s->sec) continue;
      
      if (strcmp((char *)s->file, region_name) == 0) {
        /* if this section has been assigned to the current region,
           add it to the allocation list */
        ssprev = unassigned_sections;
        for (ss = ssprev; ss != NULL; ss = ssnext) {
          ssnext = ss->next;
          if (ss->sec && strcmp((char *) s->sec, ss->sec->name) == 0) {
              PIC32_DEBUG("  input section \"%s\", len = %lx, flags = %x, attr = %x",
			  ss->sec->name, ss->sec->size,
			  ss->sec->flags, ss->attributes);
	      
	      insert_alloc_section(alloc_section_list, ss);
	      ssprev->next = ssnext; /* unlink it from unassigned_sections */
          } else
	      ssprev = ss;
        }
      }
    }
    
    if (pic32_section_list_length(alloc_section_list) == 0) {
        PIC32_DEBUG("  (none)");
	continue;
    }
      
//    temp_region.name = (char *) region_name;
    temp_region.next = &temp_region;
    temp_region.origin = r->sec->vma;
    temp_region.length = r->sec->lma;

    /* don't expect to need these.. */
    temp_region.current = r->sec->vma;
//    temp_region.old_length = 0;
    temp_region.flags = 0;
    temp_region.not_flags = 0;
    temp_region.had_full_message = FALSE;

    if (free_blocks)
      pic32_free_memory_list(&free_blocks);
    pic32_init_memory_list(&free_blocks);
  
    /* start with entire region as a free block */
    pic32_add_to_memory_list(free_blocks, temp_region.origin,
                             temp_region.length);

    DEBUG(pic32_print_section_list(alloc_section_list, "allocation"));
  
    result |= locate_sections(address, 0, &temp_region, &alloc_section_list);   /* most restrictive  */
    result |= locate_sections(all_attr, 0, &temp_region, &alloc_section_list);  /* least restrictive */
  }

  return result;
} /* allocate_user_memory() */
#endif /* ENABLE_USER_MEMORY */
