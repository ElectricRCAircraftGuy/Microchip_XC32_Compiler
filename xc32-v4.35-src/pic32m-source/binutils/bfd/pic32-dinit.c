#ifndef __PIC32_DINIT__
#define __PIC32_DINIT__

#ifndef PIC32
#define PIC32
#endif

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "libiberty.h"
#include "elf-bfd.h"
#include "limits.h"

#if defined(TARGET_IS_PIC32C)
#include "pic32c-utils.h"
#include "elf/arm.h"
#include "../ld/ldexp.h"
#include "../ld/ldlang.h"
#include "../ld/mchp/pic32c-emultempl.h"
#elif defined(TARGET_IS_PIC32M)
#include "pic32m-utils.h"
#endif

extern bfd_boolean  pic32_data_init;
extern bfd_boolean  pic32_has_data_init_option;
extern bfd_boolean  pic32_has_fill_option;
extern bfd_boolean  pic32_has_stack_option;
extern bfd_boolean  pic32_has_processor_option;
extern bfd_boolean  pic32_has_hardfloat_option;
extern bfd_boolean  pic32_has_softfloat_option;
extern bfd_boolean  pic32_code_in_dinit;
extern bfd_boolean  pic32_has_code_in_dinit_option;
extern bfd_boolean  pic32_dinit_in_serial_mem;
extern bfd_boolean  pic32_has_dinit_in_serial_mem_option;
extern bfd_boolean  pic32_dinit_has_absolute_address;
extern bfd_vma      dinit_address;
extern bfd_boolean  pic32_debug;

/*
* dinit_compress_level  = 0 -> legacy
*                       = 1 -> merge sections
*                       = 2 -> merge sections & repeated values 
*                       = 3 -> merge sections & repeated values & compression
*/
/* Set maximum as default */
unsigned int dinit_compress_level = 3;

/* Disable self check by default */
bfd_boolean dinit_self_check = FALSE;
/* Set to largest possible value to break tests in case real value isn't set
 * in fill_dinit_section
 */
int min_gain_repeated_2b = INT_MAX;
int min_gain_repeated_4b = INT_MAX;
int min_gain_compression = INT_MAX;

/* What startup routines to link */
unsigned int dinit_link_mask = 0;

/* Data Structures for the Data Init Template */
bfd             *init_bfd;
unsigned char   *init_data = NULL;
asection        *init_template = 0;
uint32_t        init_data_padding = 0;
static uint32_t saved_dinit = 0;


/* Data Structures for Input Data Sections */
extern struct pic32_section *data_sections;

/* Data Structures for Input Data Sections */
extern struct pic32_section *code_sections;

static void pic32_add_section_to_list
  (struct pic32_section *lst, asection *sec);

static void dinit_gen_repeated_value(PTR* fp, bfd_vma runtime_addr,
                                     bfd_vma runtime_size, uint32_t value,
                                     dinit_type data_type);
static void bfd_pic32_process_data_section
  (asection * const sec, PTR fp);
static void bfd_pic32_process_code_section
  (struct pic32_section * const s, PTR fp, bfd_boolean update_flags);
static void bfd_pic32_write_data_header
  (unsigned char **,  bfd_vma,  bfd_vma, uint16_t);
static unsigned int dinit_compress
  (unsigned char * const buf, unsigned int entry_len, PTR fp);
bfd_boolean is_compressable
  (PTR fp, unsigned int length);
static unsigned char *dinit_get_section_contents
  (asection*, bfd_boolean);
static uint32_t bfd_pic32_repeated_data_sections
  (struct pic32_section* sect, unsigned char** fp, bfd_boolean do_set);

/* Gets content from asection's input or output section depending on do_set */
static unsigned char *
dinit_get_section_contents(asection *sect, bfd_boolean do_set)
{
  unsigned char * buf;

  /*
  ** Note: We are extracting input section data
  ** from an output section.
  */

  if (do_set)
    buf = (unsigned char *)malloc(sect->output_section->size);
  else
    buf = (unsigned char *)malloc(sect->size);

  if (!buf)
  {
    fprintf(stderr, "Link Error: not enough memory for section contents\n");
    abort();
  }

  /* Reset the bfd file pointer, because
        there seems to be a bug with fseek()
        in Winblows that makes seeking to
        a position earlier in the file unreliable. */

  bfd_boolean got_contents = FALSE;

  if (do_set)
  {
    /* TODO: This hack turns off the SEC_IN_MEMORY flag for any output
       section that has it just so the contents can be retrieved.  It
       really should be temporary. */
    bfd_boolean hackflag = FALSE;
    if (sect->output_section->flags & SEC_IN_MEMORY)
    {
      sect->output_section->flags &= ~SEC_IN_MEMORY;
      hackflag = TRUE;
    }

    bfd_seek(sect->output_section->owner, 0, SEEK_SET);
    got_contents = !bfd_get_section_contents(sect->output_section->owner,
                                             sect->output_section, buf,
                                             sect->output_offset, sect->size);
    if (hackflag)
      sect->output_section->flags |= SEC_IN_MEMORY;
  }
  else
  {
    bfd_seek(sect->owner, 0, SEEK_SET);
    got_contents = !bfd_get_section_contents(sect->owner, sect, buf, 0,
                                             sect->size);
  }

  if (got_contents)
  {
    fprintf(stderr, "Link Error: can't load section %s contents\n", sect->name);
    abort();
  }

  return buf;
}

static void
pic32_add_section_to_list (struct pic32_section * lst,
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
  new->children = NULL;
  new->attributes = 0 /*pic32_attribute_map(sec) */;
  new->file = NULL; /* not set at this point */
  new->dinit_type = -1;

  /* find the tail */
  for (s = lst; s != NULL; s = s->next)
    tail = s;

  tail->next = new;  /* add it */
}


/*
 * ** Write a data record header
 * */
static void
bfd_pic32_write_data_header(d, addr, len, format)
     unsigned char **d;
     bfd_vma addr;
     bfd_vma len;
     uint16_t format;
{
  addr &= 0xFFFFFFFF;

  /* write destination address */
  *(*d)++ = (unsigned char) (addr & 0xFF);
  *(*d)++ = (unsigned char) ((addr >> 8) & 0xFF);
  *(*d)++ = (unsigned char) ((addr >> 16) & 0xFF);
  *(*d)++ = (unsigned char) ((addr >> 24) & 0xFF);

  /* write destination length */
  *(*d)++ = (unsigned char) (len & 0xFF);
  *(*d)++ = (unsigned char) ((len >> 8) & 0xFF);
  *(*d)++ = (unsigned char) ((len >> 16) & 0xFF);
  *(*d)++ = (unsigned char) ((len >> 24) & 0xFF);

  /* write format code */
  *(*d)++ = (unsigned char) (format & 0xFF);
  *(*d)++ = (unsigned char) ((format >> 8) & 0xFF);
  *(*d)++ = 0;
  *(*d)++ = 0;
}

static bfd_boolean dinit_is_relocatable(asection * const sec)
{
  if (sec->reloc_count || sec->was_reloc || sec->flags & SEC_RELOC)
    return TRUE;
  return FALSE;
}

static bfd_boolean dinit_is_bss_section(asection * const sec)
{
  if ((PIC32_IS_BSS_ATTR(sec) || PIC32_IS_BSS_ATTR_WITH_MEMORY_ATTR(sec))
      && (sec->size > 0))
    return TRUE;
  return FALSE;
}

static bfd_boolean dinit_is_data_section (asection * const sec)
{
  if ((PIC32_IS_DATA_ATTR(sec) ||
        PIC32_IS_DATA_ATTR_WITH_MEMORY_ATTR(sec) ||
        PIC32_IS_RAMFUNC_ATTR(sec)) &&
        (sec->size > 0))
    return TRUE;
  return FALSE;
}

static bfd_boolean dinit_is_valid_section (asection * const sec)
{
  /* skip persistent or noload data sections*/
  if (PIC32_IS_PERSIST_ATTR(sec) || PIC32_IS_NOLOAD_ATTR(sec) || (sec->size == 0))
    {
      if (pic32_debug)
        fprintf(stderr, "  optim_dinit %s (skipped), size = 0x%x\n",
               sec->name, (unsigned int) sec->size);
      return FALSE;
    }
  return TRUE;
}

static void dinit_reset_section_flags(asection * const sect, bfd_boolean do_set)
{
  if (do_set)
  {
    Elf_Internal_Shdr *this_hdr;

    /* make section not LOADable */
    sect->output_section->flags &= ~SEC_LOAD;
    sect->output_section->flags |= SEC_NEVER_LOAD;

    sect->flags &= ~SEC_LOAD;
    sect->flags |= SEC_NEVER_LOAD;

    this_hdr = &elf_section_data(sect->output_section)->this_hdr;
    this_hdr->sh_flags |= SHF_NOLOAD;
  }
}

/*
** If the section is BSS or DATA, write the appropriate
** record into the data init template.
**
** ToDo: If the data section exceeds 64K, break into
** multiple records.
*/
static void bfd_pic32_process_data_section(asection * const sect, PTR fp)
{
  unsigned char *buf,*p;
  unsigned char **d = (unsigned char **) fp;
  bfd_vma runtime_size = sect->size;
  bfd_vma runtime_addr;

    if (sect == NULL)
        return;

    if (sect->output_section == NULL)
        return;

#ifdef TARGET_IS_PIC32C
    if (!sect->init)
    {
      if (pic32_debug)
	    fprintf (stderr, "  optim_dinit data_section %s (skipped, !init)\n", sect->name);
      return;
    }
#endif

    if (sect->size > 0)
      runtime_addr = sect->output_offset + sect->output_section->vma;
    else
      return;

  /* skip persistent or noload data sections */
  if (!dinit_is_valid_section(sect))
    return;

  /* process BSS-type sections */
  if (dinit_is_bss_section(sect))
    {
      if (pic32_debug)
        fprintf(stderr,
                "  optim_dinit %s (bss), size = 0x%x bytes, template addr = %lx\n",
                sect->name, (unsigned int) runtime_size,
                (long unsigned int) *d);

      /* write header only */
      bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_CLEAR);
    }

   /* process DATA-type sections */
  if (dinit_is_data_section(sect))
    {
      if (pic32_debug)
        fprintf(stderr,
                "  optim_dinit %s (data), size = 0x%x bytes, template addr = %lx\n",
                sect->name, (unsigned int) runtime_size,
                (long unsigned int) *d);

      buf = dinit_get_section_contents(sect, TRUE);

      int count = 0;
      /* write header */
      bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_COPY);

      for (p = buf; p < (buf + sect->size); )
      {
        *(*d)++ = *p++;
      }
      /* fill template with zeroes
        * padding for word alignment
        */
      count = sect->size % 4;
      if (count) while (count < 4) { *(*d)++ = 0; count++; }

      free(buf);

      /* make section not LOADable */
      dinit_reset_section_flags(sect, TRUE);
    } /* process DATA-type sections */

  return;
} /* static void bfd_pic32_process_data_section (...)*/


static void bfd_pic32_process_code_section(struct pic32_section * const s, PTR fp, bfd_boolean update_flags)
{
  unsigned char *buf,*p;
  unsigned char **d = (unsigned char **) fp;
  asection* sect = s->sec;

  bfd_vma runtime_size = sect->size;
  bfd_vma runtime_addr = sect->output_offset + sect->output_section->vma;

#ifdef TARGET_IS_PIC32C
    ///\ set runtime address for .vectors
    ///\ itcm origin
    if(!update_flags)
        runtime_addr = pic32c_itcm_vectors_address;
#endif

  if (PIC32_IS_CODE_ATTR(sect) && (sect->size > 0)
#ifdef TARGET_IS_PIC32C
        && sect->init
#endif
  )
    {
      if (pic32_debug)
        fprintf(stderr, "  optim_dinit %s (code), size = 0x%x bytes, template addr = %lx\n",
                sect->name, (unsigned int)runtime_size, (long unsigned int)*d);

      buf = dinit_get_section_contents(sect, TRUE);

      { int count = 0;
          /* write header */
          bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_COPY);
          for (p = buf; p < (buf + sect->size); )
            {
              *(*d)++ = *p++;
              count ++;
              if (count == 4)
                count = 0;
            }
          /* fill template with zeroes */
          if (count) while (count < 4) { *(*d)++ = 0; count++; }

        free(buf);
#ifdef TARGET_IS_PIC32C
        if (update_flags)
#endif
          /* make section not LOADable */
          dinit_reset_section_flags(sect, TRUE);
    }
  }
}

/* check if 2 sections are compatible to be merged at dinit level */
static bfd_boolean are_dinit_compatible(asection * const s1, asection * const s2)
{
  /* Make sure we have output sections, this occurs when dinit is run before
	 allocation */
  if (!s1->output_section || !s2->output_section)
	return FALSE;

  bfd_vma s1_addr = s1->output_offset + s1->output_section->vma;
  bfd_vma s2_addr = s2->output_offset + s2->output_section->vma;


  if (s1 && s2
      /* same type */
      && ( (dinit_is_bss_section(s1) && dinit_is_bss_section(s2))
          || (dinit_is_data_section(s1) && dinit_is_data_section(s2)))
      /* continuous addresses */
      && ((s1_addr + s1->size) == s2_addr)
      )
      return TRUE;
  return FALSE;
}

static void
dinit_gen_repeated_value(PTR* fp, bfd_vma runtime_addr, bfd_vma runtime_size,
                         uint32_t value, dinit_type data_type)
{
    unsigned char **d = (unsigned char**)fp;
    
    bfd_pic32_write_data_header(d, runtime_addr, runtime_size,
                                        data_type);

    switch (data_type)
    {
      case DINIT_COPY_VAL_EMB:
            *d -= 2; /* Utilize zeros placed by write_data_header */
            *(*d)++ = (unsigned char)(value & 0xFF);
            *(*d)++ = (unsigned char)((value >> 8) & 0xFF);
          break;

      case DINIT_COPY_VAL_DATA:
            *(*d)++ = (unsigned char)(value & 0xFF);
            *(*d)++ = (unsigned char)((value >> 8) & 0xFF);
            *(*d)++ = (unsigned char)((value >> 16) & 0xFF);
            *(*d)++ = (unsigned char)((value >> 24) & 0xFF);
          break;

      default:
        break;
    }
}


/*
* select a repeated value type if possible, otherwise return copy 
*/
static dinit_type dinit_get_entry_type(struct pic32_section* sect, unsigned char** fp, bfd_boolean do_set)
{
  unsigned char*  buf = NULL;
  uint32_t        repeated_int;
  uint16_t        repeated_short;
  bfd_size_type   use_copy_val_int = 0;
  bfd_size_type   use_copy_val_short = 0;
  bfd_vma         runtime_addr = 0;
  unsigned char** d = (unsigned char**)fp;
	unsigned char*  p;

  if (do_set)
    runtime_addr = sect->sec->output_offset + sect->sec->output_section->vma;

  /* reloc sect->sections are always DINIT_COPY */
  if (dinit_is_relocatable(sect->sec))
    return DINIT_COPY;

  if (dinit_is_bss_section(sect->sec))
    return DINIT_CLEAR;

  buf = dinit_get_section_contents(sect->sec, do_set);

	repeated_int = *(uint32_t*)buf;
	repeated_short = *(uint16_t*)buf;
	bfd_boolean check_int = !(sect->sec->size % 4) && sect->sec->size > 4;
	bfd_boolean check_short = !(sect->sec->size % 2)  && sect->sec->size > 2;

	/* Check for repeated values */
	for (p = buf; p < (buf + sect->sec->size); p += 2)
	  {
		if (check_int && (uintptr_t) p % 4 == 0)
		  if (repeated_int == *(uint32_t *)p)
			use_copy_val_int++;

		if (check_short && repeated_short == *(uint16_t*)p)
		  use_copy_val_short++;
	  }

    free(buf);

	/* Ensure we only create a COPY_VAL_DATA/EMB type when the entire
        sect->section is the same repeated value */
    if ((!do_set && use_copy_val_short && (use_copy_val_short == sect->sec->size/2))
        || (do_set && (dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_EMB)) && (sect->dinit_type == DINIT_COPY_VAL_EMB)))
    {
      if(do_set)
        dinit_gen_repeated_value((void **) d, runtime_addr, sect->sec->size,
                               (uint32_t)repeated_short, DINIT_COPY_VAL_EMB);
      return DINIT_COPY_VAL_EMB;
    }

    if ((!do_set && use_copy_val_int && (use_copy_val_int == sect->sec->size/4))
        || (do_set && (dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_DATA))))
    {
      if (do_set)
        dinit_gen_repeated_value((void **) d, runtime_addr, sect->sec->size,
                               repeated_int, DINIT_COPY_VAL_DATA);
      return DINIT_COPY_VAL_DATA;
    }
    /* dinit is checked just for data, it can't be DINIT_CLEAR */
    return DINIT_COPY;
}

struct pic32_section*
bfd_pic32_process_merged_sections(struct pic32_section * const p32_start_sec, PTR fp, bfd_boolean do_set);
struct pic32_section*
bfd_pic32_process_merged_sections(struct pic32_section * const p32_start_sec, PTR fp, bfd_boolean do_set)
{
  asection *sect = p32_start_sec->sec;
  struct pic32_section *crt_sec;
  unsigned char *buf,*p;
  unsigned char **d = (unsigned char **) fp;
  bfd_vma runtime_size = sect->size;
  bfd_vma runtime_addr;
  unsigned char sec_type = 0; /* =1 ->bss, =2 ->data */
  /* keep a local list with the sections that can be merged in dinit */
  struct pic32_section *merged_sec = NULL, *tmp;
  uint32_t report_amount = 0;

  if (sect == NULL || (do_set && sect->output_section == NULL))
    return p32_start_sec->next;

  /* skip persistent or noload data sections - shouldn't happen!!!
   replace with assert */
  if (PIC32_IS_PERSIST_ATTR(sect) || PIC32_IS_NOLOAD_ATTR(sect))
    {
      if (pic32_debug)
        fprintf(stderr, "  optim_dinit %s (skipped), size = 0x%x\n",
               sect->name, (unsigned int) runtime_size);
      return p32_start_sec->next;
    }

  /* We can only merge if both sections are not optimized, this checks the
   * initial section.
   */
  if ((p32_start_sec && (p32_start_sec->dinit_type > DINIT_COPY) &&
          (dinit_link_mask & GEN_DINIT_MASK(p32_start_sec->dinit_type))))
    return p32_start_sec->next;

#ifdef TARGET_IS_PIC32C
  if (!sect->init)
    {
      if (pic32_debug)
        fprintf (stderr, "  optim_dinit data_section %s (skipped, !init)\n", sect->name);
      return p32_start_sec->next;
    }

#endif

  if (do_set && sect->size > 0)
      runtime_addr = sect->output_offset + sect->output_section->vma;
  else
      runtime_addr = 0;

  /* check if it is bss or data section*/
  dinit_is_bss_section(sect)? (sec_type = 1) : (sec_type = 2);

  /* build the list of consecutive sections that can be merged in dinit */
  /* using a stack address - not a good practice!!!*/
  pic32_init_section_list(&merged_sec);
  pic32_add_section_to_list(merged_sec, sect);

  /* check next section */
  crt_sec = p32_start_sec->next;

  while(crt_sec!= NULL)
  {
    while(crt_sec && !(dinit_is_valid_section (crt_sec->sec)))
    {
      crt_sec = crt_sec->next;
    }

    /* check if the section was already optimized
     * repeated values or compression -> it is not merged
     * this checks the current section.
     */
    if (crt_sec && (crt_sec->dinit_type > DINIT_COPY)
        && (dinit_link_mask & GEN_DINIT_MASK(crt_sec->dinit_type)))
      break;

    /* check if the sections can be merged */
    if (crt_sec && are_dinit_compatible(sect, crt_sec->sec))
    {

      runtime_size += crt_sec->sec->size;
      /* add the new section in the list */
      if (pic32_debug)
        fprintf(stderr,
                "  optim_dinit %s , addr: 0x%lx, size = 0x%x bytes & %s, addr: 0x%lx, size 0x%x",
                sect->name, runtime_addr, (unsigned int) sect->size,
                crt_sec->sec->name,
                crt_sec->sec->output_offset + crt_sec->sec->output_section->vma,
                (unsigned int) crt_sec->sec->size);
      pic32_add_section_to_list(merged_sec, crt_sec->sec);

      report_amount = saved_dinit;

      /* If section to be merged can fit inside of the zero padding of the
       * current section. This causes us to save another word. This only
       * applies to DINIT_COPY sections.
       */
      if ((((4 - ((runtime_size - crt_sec->sec->size) % 4)) + sect->size) <= 4)
          && crt_sec->dinit_type == DINIT_COPY
          && !do_set)
        saved_dinit += 4;

      if (!do_set) {
        saved_dinit += 12; /* HEADER size*/
        report_amount = saved_dinit - report_amount;
        if (pic32_debug)
          fprintf(stderr, ", saved 0x%x\n", report_amount);
      } else
        if (pic32_debug)
          fprintf(stderr, "\n");

      report_amount = 0;
      sect = crt_sec->sec;
      crt_sec = crt_sec->next;
    }
    else
      break;
  }
 if (!do_set)
 {
   pic32_free_section_list(&merged_sec);
   return crt_sec;
 }

 /*the list is complete - start filling .dinit */
  /* process BSS-type sections */
  if (sec_type == 1)
    {
      /* write header only */
      bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_CLEAR);
    }
   /* process DATA-type sections */
  else
    {
      int count = 0;
      /* write header */
      bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_COPY);

      for (tmp = merged_sec; tmp != NULL; tmp = tmp->next)
      {
          if (tmp->sec == NULL)
            continue;

        sect = tmp->sec;
        buf = dinit_get_section_contents(sect, do_set);

        if (do_set)
          for (p = buf; p < (buf + sect->size); )
            *(*d)++ = *p++;

      free(buf);
    }
    count = (4 - runtime_size%4)%4;

    /* padding with 0*/
    while (count != 0)
    {
      if (do_set)
        *(*d)++ = 0;

	  count--;
    }

    /* reset sections LOAD flags */
    for (tmp = merged_sec; tmp!= NULL; tmp = tmp->next)
        if (tmp->sec != NULL)
          dinit_reset_section_flags(tmp->sec, do_set);

    } /* process DATA-type sections */

  pic32_free_section_list(&merged_sec);
  return crt_sec;
} /* static struct pic32_section* bfd_pic32_process_merged_sections (...)*/


/*
* find the potential compression gain
*   on the char array
*/
int32_t dinit_get_compression_gain(asection *);
int32_t dinit_get_compression_gain(asection *sect)
{
  unsigned char *p;
  unsigned char *data = NULL;
  uint32_t length = sect->size;
  int32_t gain_bytes = 0; /* this one can be negative if there are just few 0's, not compensating the compression overhead */
  uint32_t nb_zero = 0;

  data = dinit_get_section_contents(sect, FALSE);

  for (p = data; p < (data + length); p++)
  {
    if (*p == 0) {
      if (nb_zero == 0xFF) {
        gain_bytes += nb_zero - 2;
        nb_zero = 1;
      }
      else
        nb_zero++;
    }
    else
    {
      if(nb_zero != 0)
      {
        gain_bytes += nb_zero - 2;
        nb_zero = 0;
      }
    }
  }
  if(nb_zero != 0)
    gain_bytes += nb_zero - 2;

  return (gain_bytes & 0xFFFFFFFC);
}

/**
 * Compress the buffer content
 * buf - holds the data to be compressed
 * entry_len - the length of the buffer
 * fp - where the compressed data is stored
 * returns the length of the compressed data
*/
static unsigned int dinit_compress (unsigned char * const buf,
                                    unsigned int entry_len, PTR fp)
{
  int length = 0, nb_zero=0, saved = 0;
  unsigned char **d = fp;
  unsigned char *p;

  BFD_ASSERT(buf != NULL);

  for (p = buf; p < (buf + entry_len); p++)
  {
    if(*p == 0)
    {
      if (nb_zero == 0xFF)
      {
        *(*d)++ = 0;
        *(*d)++ = 0xFF;
        saved += (nb_zero - 1);
        nb_zero = 1;
        length +=2; /* written bytes: < 0 | 0xFF > */
      }
      else
        nb_zero++;
    }
    else
    {
      if(nb_zero != 0)
      {
        *(*d)++ = 0;
        *(*d)++ = nb_zero;
        *(*d)++ = *p;
        nb_zero = 0;
        length += 3; /* written bytes: < 0 | nb_zero | *p > */
      }
      else
      {
        *(*d)++ = *p;
        length++;
      }
    }
  }

  if (nb_zero != 0)
  {
    *(*d)++ = 0;
    *(*d)++ = nb_zero;
    length += 2; /* written bytes: < 0 | nb_zero > */
  }

  int i = (4 - length%4)%4;

  /* padding with 0*/
  while (i != 0)
  {
    *(*d)++ = 0;
    i--;
  }
  return length;
}


static uint32_t
bfd_pic32_compress_data_section(struct pic32_section * const p32_start_sec, PTR fp)
{
  asection* sect = p32_start_sec->sec;
  unsigned char *buf = NULL,*p;
  unsigned char **d = (unsigned char **) fp;
  bfd_vma runtime_size = sect->size;
  bfd_vma runtime_addr;
  unsigned int count, saved = 0;

  if (sect == NULL)
      return 0;

  if (sect->output_section == NULL)
      return 0;

  /* skip persistent or noload data sections - shouldn't happen!!!
   replace with assert */
  if (PIC32_IS_PERSIST_ATTR(sect) || PIC32_IS_NOLOAD_ATTR(sect))
    {
      if (pic32_debug)
        fprintf(stderr, "  optim_dinit %s (skipped), size = 0x%x\n",
               sect->name, (unsigned int) runtime_size);
      return 0;
    }
#ifdef TARGET_IS_PIC32C
  if (!sect->init)
    {
      if (pic32_debug)
        fprintf (stderr, "  optim_dinit data_section %s (skipped, !init)\n", sect->name);
      return 0;
    }
#endif

  if (sect->size > 0)
    runtime_addr = sect->output_offset + sect->output_section->vma;
  else
    return 0;

  if (dinit_is_bss_section(sect))
  {
    /* write header */
    bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_CLEAR);
    return 0;
  }

  buf = dinit_get_section_contents(sect, TRUE);
 
  if ((p32_start_sec->dinit_type == DINIT_COMPRESSED) 
      && (dinit_link_mask & (GEN_DINIT_MASK(DINIT_COMPRESSED)))
      && !dinit_is_relocatable(sect))
  {
    bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_COMPRESSED);

    /*compress buffer*/
    count = 0; /* padded inside compression */
    saved = (sect->size - dinit_compress (buf,  sect->size, d)) & 0xFFFFFFFC; /* ensure 4-byte alignment*/
  }
  else
  {
    bfd_pic32_write_data_header(d, runtime_addr, runtime_size, DINIT_COPY);
    for (p = buf; p < (buf + sect->size); )
        *(*d)++ = *p++;

    count = (4 - runtime_size%4)%4;
  }

  /* padding with 0*/
  while (count != 0)
  {
    *(*d)++ = 0;
    count--;
  }

  free(buf);

  /* reset flags - make section not LOADable */
  dinit_reset_section_flags(sect, TRUE);
  return saved;
}

/*
* return the gain of repeated values
*/
static uint32_t
bfd_pic32_repeated_data_sections(struct pic32_section* sect, unsigned char** fp, bfd_boolean do_set)
{
  unsigned char **d = (unsigned char **) fp;
  dinit_type data_type = dinit_get_entry_type(sect, d, do_set);

  if (data_type == DINIT_COPY_VAL_DATA)
      return sect->sec->size - 4;
  else if (data_type == DINIT_COPY_VAL_EMB)
    return sect->sec->size;

  return 0;
}

static void
set_optimization_gain_min(bfd* ibfds)
{
  bfd* abfd;
#ifdef TARGET_IS_PIC32C
  uint32_t i;
  long symsize;
  asymbol **symbol_table;
  long number_of_symbols;
#endif

#ifdef TARGET_IS_PIC32MX
  #define DATA_INIT_OBJ "pic32_data_init_core.o"
#endif
#ifdef TARGET_IS_PIC32C
  #define DATA_INIT_OBJ "data_init.o"
#endif

    /* Size of _dinit_decompress and code to select branch */
    for (abfd = ibfds; abfd != (bfd *)NULL; abfd = abfd->link.next) {
      /*
       * Maybe we can get the archive and find the symbol's size somehow?
       * would be better than magic numbers. These numbers were obtained
       * by manually checking the size with dissasembly of the library files.
       */
      if (!strcmp(basename(abfd->filename), DATA_INIT_OBJ)) {
#ifdef TARGET_IS_PIC32MX
        if (_bfd_mips_is_micromips(abfd)) {
          min_gain_compression = 0x3e; /* bytes */
          min_gain_repeated_2b = 0x1e;
          min_gain_repeated_4b = 0x1a;
        }
        else
        {
          min_gain_compression = 0x68; /* bytes */
          min_gain_repeated_2b = 0x1c;
          min_gain_repeated_4b = 0x20;
        }
#endif
#ifdef TARGET_IS_PIC32C
        /* The approach we used on MIPS does not work for arm due to how
         * architecture information is set in the BFD.
         */
        symsize = bfd_get_symtab_upper_bound(abfd);

        if (symsize <= 0)
          break;

        symbol_table = (asymbol **)xmalloc(symsize);
        number_of_symbols = bfd_canonicalize_symtab(abfd, symbol_table);

        for (i = 0; i < number_of_symbols; i++)
          // Look for the Thumb/arm mode special symbols
          if (!strcmp(bfd_asymbol_name(symbol_table[i]), "$t")) {
            min_gain_compression = 0x46; /* bytes */
            min_gain_repeated_2b = 0x1e;
            min_gain_repeated_4b = 0x26;
            break;
          } else if (!strcmp(bfd_asymbol_name(symbol_table[i]), "$a")) {
            min_gain_compression = 0x70; /* bytes */
            min_gain_repeated_2b = 0x38;
            min_gain_repeated_4b = 0x44;
            break;
          }
        free(symbol_table);
#endif
        break;
        }
    }
    if (min_gain_compression == INT_MAX || min_gain_repeated_2b == INT_MAX
        || min_gain_repeated_4b == INT_MAX)
    {
      fprintf (stderr,
               "Warning: dinit optimization threshholds not set; dinit "
               "may not function\n");
    }
}

void estimate_dinit_optim(struct bfd_link_info *info)
{
  bfd_size_type         dinit_size;
  unsigned char         *dat;
  struct pic32_section  *s_sec;
  uint32_t              i;
  unsigned char         sec_type = 0;
  int32_t               saved_dinit_repeated_2b = 0, saved_dinit_repeated_4b = 0, saved_compression = 0;
  uint32_t              nb_repeated_2b = 0; /* number of sections optimized as repeated embedded values */

  if (!pic32_data_init)
    return;

  BFD_ASSERT (init_template != NULL);

  set_optimization_gain_min(info->input_bfds);
  
  if (pic32_debug)
    fprintf (stderr, "optim_dinit ... estimation DINIT pass\n");

  dinit_size = init_template->size;

  if (init_data == NULL)
    {
      init_data = (unsigned char *)malloc (dinit_size * sizeof (unsigned char));
      if (init_data == NULL)
      {
        fprintf (stderr, "Link Error: can't allocate dinit buffer\n");
        abort ();
      }
      memset (init_data, 0x11, dinit_size);
    }

  /* update the default fill value */
  dat = init_data;
  for (i=0; i < dinit_size; i++)
    *dat++ *= 2;

  /* scan sections and write data records */
  if (pic32_debug)
    fprintf(stderr, "\noptim_dinit estimating data sections:\n");
  dat = init_data;

  for (s_sec = data_sections; s_sec != NULL; )
  {
    if ((s_sec)
        && (s_sec->sec)
        && ((s_sec->sec->flags & SEC_EXCLUDE) == 0)
        && (s_sec->sec->output_section != bfd_abs_section_ptr)
        && (s_sec->sec->size > 0)
#ifdef TARGET_IS_PIC32C
        && (s_sec->sec->init != 0)
#endif
        )
    {
      /*
        * Set was_reloc before anything else, this attribute persists
        * across both passes ensuring we do not optimize relocatable
        * sections.
        */
      if (dinit_is_relocatable(s_sec->sec))
      {
        if (pic32_debug)
          fprintf(stderr,"  optim_dinit section %s COPY_RELOC, size = 0x%lx bytes\n",
                  s_sec->sec->name, s_sec->sec->size);
        s_sec->sec->was_reloc = TRUE;
        if (s_sec->sec->output_section)
            s_sec->sec->output_section->was_reloc = TRUE;
        dinit_link_mask |=  GEN_DINIT_MASK(DINIT_COPY);
        s_sec->dinit_type = DINIT_COPY;
        s_sec = s_sec->next;
        continue; /* no more analysis is needed, this one is just copied*/
      }

      dinit_is_bss_section(s_sec->sec)? (sec_type = 1) : (sec_type = 2);

      /* bss section cannot be optimized at this point */
      if (sec_type == 1)
      {
        /* set clear flag */
        if (pic32_debug)
          fprintf(stderr,"  optim_dinit section %s CLEAR, size = 0x%lx bytes\n",
                  s_sec->sec->name, s_sec->sec->size);
        dinit_link_mask |=  GEN_DINIT_MASK(DINIT_CLEAR);
        s_sec->dinit_type = DINIT_CLEAR;
        s_sec = s_sec->next;
        continue;
      }

      switch (dinit_compress_level)
      {
      case 0:
      case 1: /* merging cannot be done in this phase */
        dinit_link_mask |=  GEN_DINIT_MASK(DINIT_COPY);
        s_sec->dinit_type = DINIT_COPY;
        break;

      case 2:
      case 3:
      {
          int32_t tmp = 0;            
          tmp = bfd_pic32_repeated_data_sections(s_sec, &dat, FALSE);
          
          if (tmp != 0)
          {
            /* 1) set mask 
               2) set saved value
               3) add in map - section & optim type
            */
            if (dinit_get_entry_type(s_sec, &dat, FALSE) ==  DINIT_COPY_VAL_EMB)
            {
              dinit_link_mask |=  GEN_DINIT_MASK(DINIT_COPY_VAL_EMB);
              s_sec->dinit_type = DINIT_COPY_VAL_EMB;
              nb_repeated_2b += 1;
              saved_dinit_repeated_2b += tmp;
              if (pic32_debug)
                fprintf(stderr,"  optim_dinit section %s COPY_EMB, size = 0x%lx bytes, saved 0x%x\n",
                        s_sec->sec->name, s_sec->sec->size, tmp);
            }
            else 
            {
              dinit_link_mask |= GEN_DINIT_MASK(DINIT_COPY_VAL_DATA);
              s_sec->dinit_type = DINIT_COPY_VAL_DATA;
              saved_dinit_repeated_4b += tmp;
              if (pic32_debug)
                fprintf(stderr,"  optim_dinit section %s COPY_DATA, size = 0x%lx bytes, saved 0x%x\n",
                        s_sec->sec->name, s_sec->sec->size, tmp);
            }
          }
          else if ((tmp == 0) && (dinit_compress_level == 3))
          {
            /* get section content and analyze it*/
            tmp = dinit_get_compression_gain(s_sec->sec);
            if (tmp != 0)
            {
              dinit_link_mask |=  GEN_DINIT_MASK(DINIT_COMPRESSED);
              s_sec->dinit_type = DINIT_COMPRESSED;
              if (pic32_debug)
                fprintf(stderr,"  optim_dinit section %s COMPRESSED, size = 0x%lx bytes, saved 0x%x\n",
                        s_sec->sec->name, s_sec->sec->size, tmp);
              saved_compression += tmp;
            }
            else
            {
              if (pic32_debug)
                fprintf(stderr,"  optim_dinit section %s COPY, size = 0x%lx bytes, saved 0x%x\n",
                        s_sec->sec->name, s_sec->sec->size, tmp);
              dinit_link_mask |= GEN_DINIT_MASK(DINIT_COPY);
              s_sec->dinit_type = DINIT_COPY;
            }
          } 
          else
          {
            if (pic32_debug)
              fprintf(stderr,"  optim_dinit section %s COPY, size = 0x%lx bytes, saved 0x%x\n",
                      s_sec->sec->name, s_sec->sec->size, tmp);
            dinit_link_mask |=  GEN_DINIT_MASK(DINIT_COPY);
            s_sec->dinit_type = DINIT_COPY;
          }
          break;
        }

        default:
          BFD_ASSERT(0); // report error -> unknown compression level 
          break;
        }
      }
      s_sec = s_sec->next;
    }
  
  /* check the improvement */
  if (dinit_link_mask &  GEN_DINIT_MASK(DINIT_COPY_VAL_EMB))
  {
    if (saved_dinit_repeated_2b < min_gain_repeated_2b)
    {
      /* transform it into 4b */
      /* 4 - repeated 4b is 4 bytes larger than repeated 2b */
      saved_dinit_repeated_4b += (saved_dinit_repeated_2b - 4*nb_repeated_2b);
      /* reset flag */
      dinit_link_mask &= ~GEN_DINIT_MASK(DINIT_COPY_VAL_EMB);
      dinit_link_mask |= GEN_DINIT_MASK(DINIT_COPY_VAL_DATA);
      if (pic32_debug)
        fprintf(stderr,"  optim_dinit COPY_VAL_EMB => COPY_VAL_DATA, saved: 0x%x, thresh: 0x%x\n",
                saved_dinit_repeated_2b, min_gain_repeated_2b);
      saved_dinit_repeated_2b = 0;
    }
  }
  if (dinit_link_mask &  GEN_DINIT_MASK(DINIT_COPY_VAL_DATA))
  {
    if (saved_dinit_repeated_4b < min_gain_repeated_4b)
    {
      dinit_link_mask &= ~GEN_DINIT_MASK(DINIT_COPY_VAL_DATA);
      if (pic32_debug)
        fprintf(stderr,"  optim_dinit COPY_VAL_DATA => COPY, saved: 0x%x, thresh: 0x%x\n",
                saved_dinit_repeated_4b, min_gain_repeated_4b);
      saved_dinit_repeated_4b = 0;
      dinit_link_mask |= GEN_DINIT_MASK(DINIT_COPY);
    }
  }
  if (dinit_link_mask &  GEN_DINIT_MASK(DINIT_COMPRESSED))
  {
    if (saved_compression < min_gain_compression)
    {
      dinit_link_mask &= ~GEN_DINIT_MASK(DINIT_COMPRESSED);
      if (pic32_debug)
        fprintf(stderr,"  optim_dinit COMPRESSED => COPY, saved: 0x%x, thresh: 0x%x\n",
                saved_compression, min_gain_compression);
      saved_compression = 0;
      dinit_link_mask |= GEN_DINIT_MASK(DINIT_COPY);
    }
  }

  /* Now that we have finished downgrading sections we fix up ->dinit_type for
   * each one. This will simplify checking when outputting.
   */

  for (s_sec = data_sections; s_sec != NULL; s_sec = s_sec->next)
  {
    if ((s_sec) && (s_sec->sec) && (s_sec->dinit_type > 1))
    {
      if (!(dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_EMB))
            && s_sec->dinit_type == DINIT_COPY_VAL_EMB)
          s_sec->dinit_type = DINIT_COPY_VAL_DATA;

      if (!(dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_DATA))
            && s_sec->dinit_type == DINIT_COPY_VAL_DATA)
          s_sec->dinit_type = DINIT_COPY;

      if (!(dinit_link_mask & GEN_DINIT_MASK(DINIT_COMPRESSED))
           && s_sec->dinit_type == DINIT_COMPRESSED)
          s_sec->dinit_type = DINIT_COPY;
    }
  }

  if (pic32_debug) {
    fprintf(stderr,"  optim_dinit saved_dinit (no merge) COPY_EMB: 0x%x, COPY_VAL_DATA: 0x%x, COMPRESSION: 0x%x\n",
            saved_dinit_repeated_2b, saved_dinit_repeated_4b, saved_compression);
    fprintf(stderr, "optim_dinit estimating data sections done\n");
  }
  saved_dinit = saved_dinit_repeated_2b + saved_dinit_repeated_4b
                + saved_compression;

  /* no estimation needed on code, as code is just copied
   * check existence to enable COPY flag if we only have code.
   */
#ifdef TARGET_IS_PIC32MX
  if (pic32_code_in_dinit)
  {
#endif
    for (s_sec = code_sections; s_sec != NULL; s_sec = s_sec->next)
      if ((s_sec->sec) &&
          (s_sec->sec->size > 0) &&
          ((s_sec->sec->flags & SEC_EXCLUDE) == 0) &&
          (s_sec->sec->output_section != bfd_abs_section_ptr))
      {
#if TARGET_IS_PIC32C
          if (s_sec->sec->itcm)
#endif
          {
            if (pic32_debug)
              fprintf (stderr,
                       "  optim_dinit (code) section: %s size: 0x%x link "
                       "DINIT_COPY startup\n",
                       s_sec->sec->name, s_sec->sec->size);
            dinit_link_mask |= GEN_DINIT_MASK (DINIT_COPY);
          }
#ifdef TARGET_IS_PIC32C
          else if ((pic32c_relocate_vectors)
                   && s_sec->sec
                   && (strstr (s_sec->sec->name, ".vectors")
                       != NULL))
          {
            if (pic32_debug)
              fprintf (stderr,
                       "  optim_dinit (code) section: %s size: 0x%x link "
                       "DINIT_COPY startup\n",
                       s_sec->sec->name, s_sec->sec->size);
            dinit_link_mask |= GEN_DINIT_MASK (DINIT_COPY);
          }
#endif
      }
#ifdef TARGET_IS_PIC32MX
  }
#endif
}

/* We are really re-implementing most of create_data_init_template here,
 * not ideal
 *
 * This function returns a new .dinit section size if it grew, or 0 called by
 * the BFA.
 */

bfd_size_type check_dinit_growth(struct bfd_link_info *link_info) {
  bfd_size_type dinit_size = 0;
  uint32_t new_init_data_padding = 0;
  struct pic32_section* s_sec;

  if (!pic32_data_init)
    return 0;

  for (s_sec = code_sections; s_sec != NULL; s_sec = s_sec->next)
    if ((s_sec->sec) && (((s_sec->sec->flags & SEC_EXCLUDE) == 0) &&
                         (s_sec->sec->output_section != bfd_abs_section_ptr)))
#ifdef TARGET_IS_PIC32C
      if (s_sec->sec->itcm)
        dinit_size += ((s_sec->sec->size % 4)
                           ? (s_sec->sec->size + (4 - s_sec->sec->size % 4))
                           : s_sec->sec->size) + 12;

      else if (pic32c_vectors_in_tcm && s_sec->sec &&
               (strstr(s_sec->sec->name, ".vectors") != NULL))
        dinit_size += ((s_sec->sec->size % 4)
                           ? (s_sec->sec->size + (4 - s_sec->sec->size % 4))
                           : s_sec->sec->size) + 12;
#endif

  for (s_sec = data_sections; s_sec != NULL; s_sec = s_sec->next)
    if ((s_sec) && (s_sec->sec) && ((s_sec->sec->flags & SEC_EXCLUDE) == 0) &&
        (s_sec->sec->output_section != bfd_abs_section_ptr) &&
        (s_sec->sec->size > 0))
    {
#ifdef TARGET_IS_PIC32C
      if (!s_sec->sec->init)
        continue; 
#endif
      if (dinit_is_bss_section(s_sec->sec))
        dinit_size += 12;
      else
        dinit_size += ((s_sec->sec->size % 4)
                           ? (s_sec->sec->size + (4 - s_sec->sec->size % 4))
                           : s_sec->sec->size)
                          + 12;
    }

  if (pic32_debug)
    printf("  optim_dinit pre padding old_size 0x%x new_size 0x%x\n",
           init_template->size, dinit_size);

  /* 0's for end of section */
#if defined(TARGET_IS_PIC32C)
  dinit_size += 8;
#elif defined(TARGET_IS_PIC32MX) /* Not used on mips but do this anyway */
  dinit_size += 4;
#endif

  /* Cache align - this needs to be done since we are comparing against the
   * untouched init_template which is cache aligned already
   */
  if (dinit_size % 16)
    {
      new_init_data_padding = 16 - (dinit_size % 16);
      dinit_size += new_init_data_padding;
    }

  if (pic32_debug)
    printf("  optim_dinit check_dinit_growth old_size 0x%x new_size 0x%x\n",
           init_template->size, dinit_size);

  if (dinit_size > init_template->size)
    {
      /* We are discarding/re-sizing dinit and will have a new value for
       * 'original' padding before exclusions and merging in
       * estimate_dinit_merging. */
      init_data_padding = new_init_data_padding;
      return dinit_size;
    }
  else
    return 0;
}

void estimate_dinit_merging()
{
  struct pic32_section  *s_sec;
  bfd_size_type         dinit_size, saved_dinit_pre = 0;

  if (!pic32_data_init)
    return;

  BFD_ASSERT (init_template != NULL);

  /* Work around sections added to data_section that got garbage collected
   * this is not necessary once we move dinit to inside the bfa. */
  for (s_sec = data_sections; s_sec; s_sec = s_sec->next)
    if (s_sec && s_sec->sec && (s_sec->sec->size > 0)
        && (s_sec->dinit_type >= DINIT_CLEAR)
        && (s_sec->sec->flags & SEC_EXCLUDE)
#ifdef TARGET_IS_PIC32C
        && (s_sec->sec->init != 0)
#endif
        ) {
      if (pic32_debug)
        printf("  optim_dinit exclude section %s size 0x%x type: %d\n",
               s_sec->sec->name, s_sec->sec->size, s_sec->dinit_type);
      if (s_sec->dinit_type == DINIT_CLEAR)
        saved_dinit += 12;
      else if (s_sec->dinit_type == DINIT_COPY)
        saved_dinit += ((s_sec->sec->size % 4)
                        ? (s_sec->sec->size + (4 - s_sec->sec->size % 4))
                        : s_sec->sec->size) + 12;
      else if (s_sec->dinit_type == DINIT_COPY_VAL_EMB)
        saved_dinit += 12; /* 'save' just the header for the section */
      else if (s_sec->dinit_type == DINIT_COPY_VAL_DATA)
        saved_dinit += 16; /* 'save' the header plus the 1 word entry */
      else if (s_sec->dinit_type == DINIT_COMPRESSED)
        /* 'save' the difference between what is already saved and the header
         * dinit_get_compression_gain will deal with alignment */
        saved_dinit +=
            (s_sec->sec->size - dinit_get_compression_gain(s_sec->sec)) + 12;
    }

  saved_dinit_pre = saved_dinit;

  if (dinit_compress_level > 0)
    {
      if (pic32_debug)
        fprintf (stderr, "\noptim_dinit estimate merging\n");

      /* scan sections and write data records */
          for (s_sec = data_sections; s_sec != NULL; )
          {
            if ((s_sec)
                && (s_sec->sec)
                && ((s_sec->sec->flags & SEC_EXCLUDE) == 0)
                && (s_sec->sec->output_section != bfd_abs_section_ptr)
                && (s_sec->sec->size > 0))
            {
              s_sec = bfd_pic32_process_merged_sections(s_sec, NULL, FALSE);
            }
            else if (!s_sec)
              break;
            else
              s_sec = s_sec->next;
          }
  }

  /* Align to cache line, this was done before v4.10 - keep it that way
   * We need to remove the original padding as it was calculated on the
   * original size of .dinit. We also cannot remove that original padding
   * in case we are unable to optimize any sections as init_template is
   * already allocated */
  dinit_size = init_template->size - saved_dinit - init_data_padding;

  if (dinit_size % 16)
  {
    init_data_padding = 16 - (dinit_size % 16);
    dinit_size += init_data_padding;
  }


  if (pic32_debug)
    {
      fprintf (stderr,
               "  optim_dinit saved_dinit (merge) MERGE: 0x%lx, TOTAL: 0x%x, "
               "SIZE: 0x%x\n",
               saved_dinit - saved_dinit_pre, saved_dinit, dinit_size);
      if (dinit_compress_level > 0)
        fprintf (stderr, "optim_dinit estimate merging done\n");
    }

  /* We didn't allocate enough memory for the init template or optimized the
   * entire section away (underflow). It may be possible to recover from this
   * but this indicates something has gone wrong with optimization or section
   * selection. */
  BFD_ASSERT (dinit_size <= init_template->size);

  if(!bfd_set_section_size(init_bfd, init_template, dinit_size)) {
    fprintf(stderr, "Link Error: could not resize init_data section, try lower --dinit-compress level.\n");
    abort();
  }
  return;
}

/* root .dinit function */
void
fill_dinit_section(struct bfd_link_info *info)
{
  asection              *dinit_sec;
  bfd_size_type         dinit_size;
  unsigned char         *dat;
  struct pic32_section  *s_sec;
  uint32_t              i;
  Elf_Internal_Shdr     *hdr;

  if (!pic32_data_init)
    return;

    BFD_ASSERT (init_template != NULL);

    if (pic32_debug)
      fprintf (stderr, "\noptim_dinit ... filling DINIT last pass\n");

    dinit_sec = init_template->output_section;
    dinit_size = init_template->size;

    if (!dinit_sec)
      {
        fprintf( stderr, "Link Error: could not access data template\n");
        abort();
      }

    /* clear SEC_IN_MEMORY flag if inaccurate */
    if ((dinit_sec->contents == 0) &&
        ((dinit_sec->flags & SEC_IN_MEMORY) != 0))
      dinit_sec->flags &= ~ SEC_IN_MEMORY;

    if(init_data == NULL)
      {
        init_data = (unsigned char*) malloc(dinit_size * sizeof(unsigned char));
        if (init_data == NULL)
          {
            fprintf (stderr, "Link Error: can't allocate dinit buffer\n");
            abort ();
          }
        memset (init_data, 0x11, dinit_size);
      }

    /* update the default fill value */
    dat = init_data;
    for (i=0; i < dinit_size; i++)
      *dat++ *= 3;

  /* scan sections and write data records */
      if (pic32_debug)
        fprintf(stderr, "\noptim_dinit Filling data sections:\n");

      dat = init_data;
      for (s_sec = data_sections; s_sec != NULL; )
      {
        if ((s_sec)
            && (s_sec->sec)
            && ((s_sec->sec->flags & SEC_EXCLUDE) == 0)
            && (s_sec->sec->output_section != bfd_abs_section_ptr)
            && (s_sec->sec->size > 0))
        {          
          if (pic32_debug)
            fprintf(stderr,
                    "  optim_dinit section %s, type: %d size = 0x%lx bytes\n",
                    s_sec->sec->name, s_sec->dinit_type, s_sec->sec->size);
          switch (dinit_compress_level)
          {
          case 0:
            bfd_pic32_process_data_section(s_sec->sec, &dat);
            s_sec = s_sec->next;
            break;
           
          case 1:
            s_sec =  bfd_pic32_process_merged_sections(s_sec, &dat, TRUE);
            break;

          case 2:
          case 3:
          {
            /* is candidate for repeated values */
            if (((dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_EMB)) && (s_sec->dinit_type == DINIT_COPY_VAL_EMB))
                || ((dinit_link_mask & GEN_DINIT_MASK(DINIT_COPY_VAL_DATA)) && ((s_sec->dinit_type == DINIT_COPY_VAL_EMB) || (s_sec->dinit_type == DINIT_COPY_VAL_DATA))))
            {
              dinit_get_entry_type (s_sec, &dat, TRUE);
              s_sec = s_sec->next;
            }
            else if ((dinit_compress_level == 3) 
                    && (dinit_link_mask & GEN_DINIT_MASK(DINIT_COMPRESSED))
                    && (s_sec->dinit_type == DINIT_COMPRESSED)
                    )
            {
              bfd_pic32_compress_data_section(s_sec, &dat); 
              s_sec = s_sec->next;             
            }
            else
              s_sec =  bfd_pic32_process_merged_sections(s_sec, &dat, TRUE);
            break;
          }

          default:
            break;
          }
        }
        else
        {
          if (s_sec == NULL)
            break;
          else
            s_sec = s_sec->next;
        }
      }

      if (pic32_debug)
        fprintf(stderr, "optim_dinit Filling data sections done\n");

#ifdef TARGET_IS_PIC32MX
     if (pic32_code_in_dinit) {
#endif
      if (pic32_debug)
        fprintf(stderr, "\noptim_dinit Filling code sections:\n");
       for (s_sec = code_sections; s_sec != NULL; s_sec = s_sec->next)
         if ((s_sec->sec) &&
             (((s_sec->sec->flags & SEC_EXCLUDE) == 0) &&
              (s_sec->sec->output_section != bfd_abs_section_ptr)))
           {
#if TARGET_IS_PIC32C
             if (s_sec->sec->itcm)
#endif
               bfd_pic32_process_code_section(s_sec, &dat, TRUE);
#ifdef TARGET_IS_PIC32C
         else if ((pic32c_relocate_vectors)
                  && s_sec->sec
                  && (strstr (s_sec->sec->name, ".vectors")
                      != NULL))
           bfd_pic32_process_code_section (s_sec, &dat, FALSE);

#endif
           }
#ifdef TARGET_IS_PIC32MX
     }
#endif
     /* write zero terminator */
       *dat++ = 0; *dat++ = 0;
       *dat++ = 0; *dat++ = 0;
/* as 0x0 (32b) is a valid address on PIC32C devices, the end of .dinit section is marked with 64b */
#ifdef TARGET_IS_PIC32C
       *dat++ = 0; *dat++ = 0;
       *dat++ = 0; *dat++ = 0;
#endif

#ifdef TARGET_IS_PIC32MX
      if (pic32_code_in_dinit)
      {

        struct bfd_link_hash_entry *h;
        h = bfd_link_hash_lookup (info->hash, entry_symbol_copy.name,
                                  FALSE, FALSE, TRUE);
        if (h != NULL
            && (h->type == bfd_link_hash_defined
                || h->type == bfd_link_hash_defweak)
            && h->u.def.section->output_section != NULL)
        {
        bfd_vma entry_address;

        entry_address = h->u.def.value
                        + bfd_get_section_vma (info->output_bfd,
                                    h->u.def.section->output_section)
                        + h->u.def.section->output_offset;


        *dat++ = entry_address & 0xFF;
        *dat++ = (entry_address >> 8) & 0xFF;
        *dat++ = (entry_address >> 16) & 0xFF;
        *dat++ = (entry_address >> 24) & 0xFF;
        }
      }
#endif

  if (pic32_debug)
    fprintf(stderr, "\noptim_dinit last template addr written = %lx\n",
           (long unsigned int)(dat-1));

  hdr = &elf_section_data (dinit_sec)->this_hdr;
  hdr->sh_size = dinit_sec->size;
  dinit_sec->flags |= SEC_LINKER_CREATED;
  init_template->flags |= SEC_LINKER_CREATED;
}

void
set_dinit_content(bfd *abfd, struct bfd_link_info *info);
void
set_dinit_content(bfd *abfd, struct bfd_link_info *info)
{
  asection              *dinit_sec;
  bfd_size_type         dinit_size;
  file_ptr              dinit_offset;
  fill_dinit_section(info);

  if (!pic32_data_init)
    return;

  dinit_sec = init_template->output_section;
  dinit_size = init_template->size;
  dinit_offset = init_template->output_offset;

  bfd_seek(dinit_sec->owner, 0, SEEK_SET);

  if (!bfd_set_section_contents (abfd, dinit_sec,
                                 init_data, dinit_offset, dinit_size))
  {
      fprintf(stderr, "Link Error: can't write section %s contents\n",
              dinit_sec->name);
      abort();
  }
}

  /*
  * Simulate the consumption of .dinit section
  * emit linker error if the structure is not valid
  * the purpose of this check is to avoid 
  * a runtime fault  
  */
void check_dinit_content(struct bfd_link_info *info);
void check_dinit_content(struct bfd_link_info *info)
{
  asection            *dinit_sec;
  bfd_size_type       dinit_size;
  int32_t             i, j, padding_count;
  uint32_t            *dinit_ptr;
  uint8_t             *dinit_content;

  if (!pic32_data_init)
    return;

  if(!dinit_self_check)
    return;

  BFD_ASSERT (init_template != NULL);

  dinit_sec = init_template->output_section;
  dinit_size = init_template->size;

  dinit_content = (unsigned char *)malloc(dinit_size);

  bfd_seek(dinit_sec->owner, 0, SEEK_SET);

  if( !bfd_get_section_contents(dinit_sec->owner, dinit_sec, dinit_content,
                                  init_template->output_offset, dinit_size))
  {
    fprintf(stderr, "Link Error: can't load section .dinit contents\n");
    abort();
  }

  if (pic32_debug)
    fprintf(stderr, "\noptim_dinit check: dinit size 0x%x\n", dinit_size);

  for (i = 0, dinit_ptr = (uint32_t*)(dinit_content); i < dinit_size/4; )
    {
      uint32_t addr;       ///\ address to write to
      int32_t length;      ///\ number of bytes to write
      uint16_t entry_type; ///\ encoding type
      uint8_t  *dat;
      uint32_t delta;
      /* check and consume termination sequence
       *  pic32m 0x00000000
       *  pic32c 0x00000000 0x00000000
       */
      if (*dinit_ptr == 0x0)
        {
#ifdef TARGET_IS_PIC32C
          if (*(dinit_ptr+1) == 0x0)
            {
              i++;
              dinit_ptr++;
#endif
          i++;
          dinit_ptr++;
          free (dinit_content);
          /* We are at the end of dinit data now, count padding */
          for (padding_count = 0; i < dinit_size/4;
               i++,padding_count++,dinit_ptr++) {}

          if (pic32_debug)
            fprintf (stderr,
                     "\n  optim_dinit check: padding amount: %d bytes\n",
                     padding_count);
          /* At most we need 3 words of padding for 16 byte alignment. We don't
           * need to abort as this won't cause a runtime error, only waste space
           */
          if (padding_count > 3)
            if (pic32_debug)
              fprintf (stderr,
                       "\b optim_dinit: Too much .dinit section padding: %d"
                       " bytes\n",
                       padding_count);
          return;
#ifdef TARGET_IS_PIC32C
            }
#endif
        }

      /* address - 4 bytes */
      addr        = *dinit_ptr; dinit_ptr++;
      length      = *dinit_ptr; dinit_ptr++;
      entry_type  = (uint16_t)*dinit_ptr; dinit_ptr++;
      i += 3;  /* dinit entry header length */

      if (pic32_debug)
        fprintf(stderr,
                "\n  optim_dinit check: entry addr: 0x%lx size: 0x%lx type: "
                "0x%lx\n",
                (long unsigned int)addr, (long unsigned int)length,
                (long unsigned int)entry_type);

      switch (entry_type)
        {
        case DINIT_CLEAR:
        case DINIT_COPY_VAL_EMB:
          break;

        case DINIT_COPY:
          delta = (length/4) + ((length%4 != 0)? 1:0);
          dinit_ptr += delta;
          i += delta;
          break;

        case DINIT_COPY_VAL_DATA:
          dinit_ptr++; i++;
          break;

        case DINIT_COMPRESSED:
          for (j = 0, dat = (uint8_t*)dinit_ptr; j < length; )
            {
              if (*dat != 0)
                {
                  dat++; j++;
                }
              else
                {
                  dat++; j+= *dat++;
                }
            }
          delta = (((uint32_t)dat - (uint32_t)dinit_ptr)/4 +
                   ((((uint32_t)dat % 4) != 0) ? 1 : 0));
          dinit_ptr += delta;
          i += delta;
          break;

        default:
          ///\ link error -> not expected type
          fprintf(stderr, "Link Error: Unexpected .dinit entry type %d\n",
                  (uint32_t)entry_type);
          abort();
          break;
        }
    }

  /*
   * malformed .dinit section
   */
  free (dinit_content);
  fprintf(stderr, "Link Error: Malformed .dinit section\n");
  abort();
}
#endif /* __PIC32_DINIT__ */
