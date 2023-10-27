/* bin2hex - convert an executable object file to HEX format using the
             BFD library. */

#include "sysdep.h"
#include "bfd.h"
#include "bfdver.h"
#include "getopt.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bucomm.h"
#include "libiberty.h"

struct section_list
{
  struct section_list *next;
  PTR *file;
  asection *sec;
};

/* prototypes */
int main (int argc, char **argv);
static void write_extended_address_record (file_ptr base_address, PTR fp);
static void write_start_linear_address_record (bfd_vma address, PTR fp);
static void write_section (bfd *abfd, asection *sect, PTR fp);
static int write_hex_file (char *name, bfd *abfd);
static void usage (FILE *stream, int status);
static void nonfatal (const char *msg);
static void hexify_file (char *filename, char *target);

/* needed for sorting */
static void init_section_list (struct section_list **);
static void build_section_list (bfd *, asection *, PTR);
static void write_section_list (bfd *, PTR, struct section_list *);
static void free_section_list (struct section_list **);

static int exit_status = 0;
/* The BFD object file format.  */
static char *default_target = NULL;
static bfd_size_type actual_prog_used;
static int verbose = 0;
#if defined(TARGET_MCHP_PIC32MX)
static int sort_by_address = 0;
#else
static int sort_by_address = 1;
#endif
static struct section_list *outputs;
#if defined(TARGET_MCHP_PIC32MX)
static int physical_addresses = 1;
#else
static int physical_addresses = 0;
#endif
static int a0_address_mapping = 0;
static int show_usage = 0;
static int write_sla = 0;
static long long int pfm_offset_address_by = 0;
static long long int bfm_offset_address_by = 0;

static inline bfd_vma
bfd_vma_low_32b (const bfd_vma addr)
{
  return (addr & 0x00000000FFFFFFFF);
}

static inline int
IS_PFM_ADDR (const bfd_vma addr)
{
  bfd_vma x = bfd_vma_low_32b (addr);

  return ((((x) >= (0x1D000000)) && ((x) <= (0x1D1FFFFF))));
}

static inline int
IS_BFM_ADDR (const bfd_vma addr)
{
  bfd_vma x = bfd_vma_low_32b (addr);

  return ((((x) >= (0x1FC00000)) && ((x) <= (0x1FC73FFF))));
}
static int write_generated_files (bfd *abfd);
static int generating_subordinate_files (char *target);
static char *subordinate_image_file = NULL;
char *subordinate_image = NULL;
static char *subordinate_c_file = NULL;
static char *subordinate_h_file = NULL;
static char *subordinate_image_offset = 0;
enum file_generation_mode
{
  AUTO,
  MANUAL
};
enum file_generation_mode file_mode = AUTO;
unsigned long long int hex_as_int = 0;

static struct option long_options[]
    = { { "sort", no_argument, NULL,
          'a' }, /* Kept for backwards compatibility. */
        { "write-sla", no_argument, NULL, 'w' },
        { "virtual", no_argument, NULL, 'i' },
        { "physical", no_argument, NULL, 'p' },
        { "a0-mapping", no_argument, NULL, '0' },
        { "std-mapping", no_argument, NULL, 's' },
        { "verbose", no_argument, NULL, 'v' },
        { "target", required_argument, NULL, 'b' },
        { "help", no_argument, NULL, '?' },
        { "pfm-offset", required_argument, NULL, 'P' },
        { "bfm-offset", required_argument, NULL, 'B' },
#ifdef TARGET_MCHP_PIC32C
        { "image", required_argument, NULL, 'I' },
        { "image-offset", required_argument, NULL, 'A' },
        { "image-generated-c", required_argument, NULL, 'C' },
        { "image-generated-h", required_argument, NULL, 'H' },
        { "image-copy-mode", required_argument, NULL, 'M' },
#endif
        { 0, no_argument, 0, 0 } };

int
main (int argc, char **argv)
{
  int c;
  char *target = default_target;
  char *unparsed = NULL;
  int arg_index = 0;
  program_name = *argv;
  xmalloc_set_program_name (program_name);
  bfd_init ();
  set_default_bfd_target ();

  while ((c = getopt_long (argc, argv, "awip0svb?P:B:I:A:C:H:M:", long_options,
                           (int *)0))
         != EOF)
    {
      arg_index++;
      switch (c)
        {
        case 'a':
          sort_by_address = 1;
          break;
        case 'w':
          write_sla = 1;
          break;
        case 'v':
          verbose = 1;
          break;
        case 'p':
          physical_addresses = 1;
          break;
        case 'i':
          physical_addresses = 0;
          break;
        case '0':
          a0_address_mapping = 1;
          break;
        case 's':
          a0_address_mapping = 0;
          break;
        case 'b':
          target = optarg;
          break;
        case '?':
          show_usage = 1;
          break;
        case 'P':
          pfm_offset_address_by = strtoll (optarg, 0, 0);
          break;
        case 'B':
          bfm_offset_address_by = strtoll (optarg, 0, 0);
          break;
#ifdef TARGET_MCHP_PIC32C
        case 'I':
          subordinate_image_file = strdup (optarg);
          break;
        case 'A':
          subordinate_image_offset = strdup (optarg);
          hex_as_int = strtoull (optarg, &unparsed, 16);
          if (*unparsed != '\0')
            {
              fprintf (stderr,
                       "*** Error: Image offset '%s'  is an illegal value ",
                       unparsed);
              exit (1);
            }
          break;
        case 'C':
          subordinate_c_file = strdup (optarg);
          break;
        case 'H':
          subordinate_h_file = strdup (optarg);
          break;
        case 'M':
          if (strcmp (optarg, "manual") == 0)
            {
              file_mode = MANUAL;
            }
          else if (strcmp (optarg, "auto") == 0)
            {
              file_mode = AUTO;
            }
          else
            {
              fprintf (stderr,
                       "*** Error: -M or --image-copy-mode value passed is "
                       "not allowed. Pass -? or --help for more info.\n");
              exit (1);
            }
          break;
#endif
        default:
          show_usage = 1;
          break;
        }
    }

  if (show_usage)
    usage (stdout, 0);
#ifdef TARGET_MCHP_PIC32C
  if (generating_subordinate_files (target))
    {
      return exit_status;
    }
#endif
  if (optind == argc)
    {
      char *file = strdup ("a.out");
      hexify_file (file, target);
      free (file);
    }
  else
    for (; optind < argc;)
      hexify_file (argv[optind++], target);
  return exit_status;
}

static int
generating_subordinate_files (char *target)
{
  if (!subordinate_image_file
      && (subordinate_image_offset || subordinate_c_file
          || subordinate_h_file))
    {
      fprintf (stderr, "*** Error: -I or --image arg is required. Pass -? or "
                       "--help for more info.\n");
      exit (1);
    }
  if (subordinate_image_file)
    {
      if (!subordinate_image_offset)
        {
          fprintf (stderr, "*** Error: -A or --image-offset arg is required. "
                           "Pass -? or --help for more info.\n");
          exit (1);
        }
      char *image_file = subordinate_image_file;
      if (get_file_size (image_file) < 1)
        {
          exit_status = 1;
          return 1;
        }
      bfd *abfd;
      abfd = bfd_openr (image_file, target);
      if (!abfd)
        {
          nonfatal (image_file);
          exit_status = 1;
          return 1;
        }
      if (bfd_check_format (abfd, bfd_object))
        {
          exit_status = write_generated_files (abfd);
        }
      bfd_close (abfd);
      return 1;
    }
  return 0;
}

static void
nonfatal (const char *msg)
{
  bfd_nonfatal (msg);
  exit_status = 1;
}

static void
hexify_file (char *filename, char *target)
{
  bfd *abfd;
  char *dot;
  char *hex_file;

  if (get_file_size (filename) < 1)
    {
      exit_status = 1;
      return;
    }

  abfd = bfd_openr (filename, target);
  if (abfd == NULL)
    {
      nonfatal (filename);
      return;
    }

  if (bfd_check_format (abfd, bfd_object))
    {
      if (verbose)
        {
          printf ("\n");
          printf ("Offsetting PFM addresses by 0x%16.16llx and BFM address by "
                  "0x%16.16llx\n",
                  pfm_offset_address_by, bfm_offset_address_by);
        }

      /* strip extension from filename if present */
      dot = strrchr (filename, '.');
      if (dot)
        dot[0] = '\0';

      /* create a new name with .hex extension */
      hex_file = xmalloc (strlen (filename) + strlen (".hex") + 1);
      sprintf (hex_file, "%s%s", filename, ".hex");

      exit_status = write_hex_file (hex_file, abfd);

      if (verbose)
        printf ("\n");

      free (hex_file);
    }

  bfd_close (abfd);
}

static void
usage (FILE *stream, int status)
{
#ifdef TARGET_MCHP_PIC32C
  fprintf (stream,
           "\n\tConverts an ELF file to Intel hex or assembly format\n\n");
#endif
#ifdef TARGET_MCHP_PIC32M
  fprintf (stream, "\n\tConverts an ELF file to Intel hex format\n\n");
#endif
  fprintf (
      stream,
      "USAGE: %s [options] [file]\n"
      "  -a, --sort         sort sections by address (default)\n"
      "  -w, --write-sla    write the entry point into an SLA field (RECTYPE "
      "5)\n"
      "  -i, --virtual      use virtual addresses\n"
      "  -p, --physical     use physical addresses (default)\n"
#ifdef PIC32_SHOW_A0MAPPINGOPTION
      /* After A0, we default to standard address mapping */
      "  -0, --a0-mapping   use A0 address mapping\n"
      "  -s, --std-mapping  use standard address mapping (default)\n"
#endif
#ifdef TARGET_MCHP_PIC32C
      "  -I, --image         specify name of executable to generate .c and .h "
      "files. Generated .c and .h files will be named after executable\n"
      "  -A, --image-offset  set boot memory address offset by specifying a "
      "hexadecimal address\n"
      "  -C, --image-generated-c      specify name or path for generated .c "
      "file instead of using the name of the image executable\n"
      "  -H, --image-generated-h      specify name or path for generated .h "
      "file instead of using the name of the image executable\n"
      "  -M, --image-copy-mode        specify auto or manual in lowercase. "
      "Auto is set by default if this option is not specified and indicates "
      "that the standard data-init mechanism will handle image copying\n"
#endif
      "  -v, --verbose      print verbose messages\n"
      "  -?, --help         print this screen\n",
      program_name);
  exit (status);
}

static int
write_hex_file (char *name, bfd *abfd)
{
  FILE *fp;
  int rc = 0;

  fp = fopen (name, "w");
  if (!fp)
    {
      printf ("Error: could not open file %s for writing!\n", name);
      return 1;
    }

  if (verbose)
    {
      printf ("writing %s\n\n", name);
      printf (
          "section                       byte address     length    (dec)\n");
      printf (
          "--------------------------------------------------------------\n");
    }

  actual_prog_used = 0;

  if (write_sla)
    write_start_linear_address_record (abfd->start_address, fp);

  /* sort, then write each section */
  if (sort_by_address)
    {
      init_section_list (&outputs);
      bfd_map_over_sections (abfd, &build_section_list, outputs);
      write_section_list (abfd, fp, outputs);
      free_section_list (&outputs);
    }
  else
    bfd_map_over_sections (abfd, &write_section, fp);

  /* write the end of file marker */
  fprintf (fp, ":00000001FF\n");
  fclose (fp);

  /* write summary info */
  if (verbose)
    printf ("\nTotal program memory used (bytes): %#18lx    (%ld)\n",
            actual_prog_used, actual_prog_used);

  return rc;
}

static void
init_section_list (struct section_list **lst)
{
  *lst = ((struct section_list *)xmalloc (sizeof (struct section_list)));
  (*lst)->next = 0;
  (*lst)->sec = 0;
  (*lst)->file = 0;
}

/*
** Build a list of output sections sorted by address.
**
** - called via bfd_map_over_sections ()
*/
void
build_section_list (bfd *abfd ATTRIBUTE_UNUSED, asection *sect, PTR p)
{
  struct section_list *new, *s, *prev;
  int done = 0;

  /* create a new element */
  new = ((struct section_list *)xmalloc (sizeof (struct section_list)));
  new->sec = sect;

  prev = (struct section_list *)p;
  for (s = prev; s != NULL; s = s->next)
    {
      /* insert it at the correct spot */
      if (s->sec && (new->sec->lma < s->sec->lma))
        {
          prev->next = new;
          new->next = s;
          done++;
          break;
        }
      prev = s;
    }

  /* if still not placed, add it to the end */
  if (!done)
    {
      prev->next = new;
      new->next = NULL;
    }
}

static void
write_section_list (bfd *abfd, PTR fp, struct section_list *p)
{
  struct section_list *s;

  for (s = p; s != NULL; s = s->next)
    {
      if (s->sec)
        write_section (abfd, s->sec, fp);
    }
}

static void
free_section_list (struct section_list **lst)
{
  struct section_list *s, *next;

  if (!(*lst))
    return;

  for (s = *lst; s != NULL; s = next)
    {
      next = s->next;
      free (s);
    }
  *lst = NULL;
}

/*
  https://training.mips.com/basic_mips/PDF/Memory_Map.pdf
  Memory map with fixed MMU MIPS32
 */
static file_ptr
decode_address (file_ptr addr)
{
  /* A0 Silicon has a bug whereby the address mapping is incorrect */
  if (a0_address_mapping)
    addr &= 0x1FFFFFFF;
  else if (addr & 0x80000000)
    {
      if (addr & 0x40000000)
        /* KSEG2/KSEG3 address - to decode do nothing */
        addr = addr;
      else
        /* KSEG0/KSEG1 address - to decode strip upper 3 bits */
        addr &= 0x1FFFFFFF;
    }
  else
    /* USEG/KUSEG address - to decode add 0x40000000 to the address */
    addr += 0x40000000;

  return addr;
}

static void
write_section (bfd *abfd, asection *sect, PTR fp)
{
#define ROW_SIZE ((bfd_size_type)0x10)
  FILE *hexfile;
  unsigned char dat[ROW_SIZE];
  unsigned char *p;
  file_ptr start, offset;
  file_ptr upper_addr, base_addr; /* for Extended Linear Address Records */
  bfd_size_type total;
  unsigned int num_rows, last_row, i, j, sum;
  unsigned short low_addr;

  base_addr = 0;
  hexfile = fp;
  p = &dat[0];
  offset = 0;
  total = (unsigned long)bfd_section_size (abfd, sect)
          / bfd_octets_per_byte (abfd);

  /* if section is load-able and has contents */
  if ((sect->flags & SEC_LOAD) && (sect->flags & SEC_HAS_CONTENTS)
      && ((sect->flags & SEC_NEVER_LOAD) == 0) && (total > 0))
    {
      start = sect->lma;
      /* To convert to a physical address, the top 3 bits are masked off */
      if (physical_addresses)
        {
          start = decode_address (start);

          if (IS_PFM_ADDR (start))
            {
              start += pfm_offset_address_by;
            }
          else if (IS_BFM_ADDR (start))
            {
              start += bfm_offset_address_by;
            }
        }

      /* print section header */
      if (verbose)
        printf ("%-25s     %#12lx     %#6lx    (%ld)\n", sect->name,
                (unsigned long)start, total, total);

      actual_prog_used += total; /* actual program memory used */
      num_rows = total / ROW_SIZE;
      last_row = total % ROW_SIZE;

      /* start with extended address = 0 */
      write_extended_address_record (0, fp);

      /* write the full records */
      for (i = 0; i < num_rows; i++)
        {
          sum = 0;
          low_addr = (unsigned short)(start + offset);
          upper_addr = (start + offset) - low_addr;
          /* if address overflows */
          if (upper_addr > base_addr)
            {
              base_addr = upper_addr;
              write_extended_address_record (base_addr, fp);
            }

          bfd_get_section_contents (abfd, sect, p, offset, ROW_SIZE);
          fprintf (hexfile, ":10%4.4x00", low_addr); /* begin record */
          sum -= (0x10 + (low_addr >> 8) + (low_addr & 0xFF));
          offset += ROW_SIZE;
          /* fill in data */
          for (j = 0; j < ROW_SIZE; j++)
            {
              fprintf (hexfile, "%2.2x", dat[j]);
              sum -= dat[j];
            }
          fprintf (hexfile, "%2.2x\n", (unsigned char)sum); /* add checksum */
        }

      /* write the last record */
      if (last_row)
        {
          sum = 0;
          low_addr = (unsigned short)(start + offset);
          upper_addr = (start + offset) - low_addr;
          /* if address overflows */
          if (upper_addr > base_addr)
            {
              base_addr = upper_addr;
              write_extended_address_record (base_addr, fp);
            }
          /* begin record */
          fprintf (hexfile, ":%2.2x%4.4x00", last_row, low_addr);
          sum -= (last_row + (low_addr >> 8) + (low_addr & 0xFF));
          bfd_get_section_contents (abfd, sect, p, offset, last_row);
          /* fill in data */
          for (j = 0; j < last_row; j++)
            {
              fprintf (hexfile, "%2.2x", dat[j]);
              sum -= dat[j];
            }
          /* add checksum */
          fprintf (hexfile, "%2.2x\n", (unsigned char)sum);
        }
    }
#undef ROW_SIZE
}

static void
write_extended_address_record (file_ptr base_address, PTR fp)
{
  FILE *hexfile;
  unsigned int sum;
  unsigned int upper_addr;

  sum = 0;
  hexfile = fp;
  upper_addr = (unsigned long)base_address >> 16;
  sum -= (2 + 0 + 4 + (upper_addr >> 8) + (upper_addr & 0xFF));
  fprintf (hexfile, ":02000004%4.4x%2.2x\n", upper_addr, (unsigned char)sum);
}

static void
write_start_linear_address_record (bfd_vma address, PTR fp)
{
  FILE *hexfile = (FILE *)fp;
  unsigned int sum = 0;
  unsigned int addr = (unsigned int)address;
  int i;

  sum -= (4 + 5);
  for (i = 0; i < 4; ++i)
    {
      sum -= (unsigned char)((addr >> (i * 8)) & 0xFF);
    }

  fprintf (hexfile, ":04000005%8.8x%2.2x\n", addr, (unsigned char)sum);
}

static void
convert_to_function_name (char *filename)
{
  char *current_char;
  for (current_char = filename; *current_char; current_char++)
    {
      if (isalnum (*current_char) == 0)
        *current_char = '_';
    }
}

#define PIC32_IS_LOADABLE(sec)                                                \
  ((sec->flags & SEC_LOAD) && (sec->flags & SEC_HAS_CONTENTS)                 \
   && ((sec->flags & SEC_NEVER_LOAD) == 0))

static int
is_manual_mode (void)
{
  return (file_mode == MANUAL);
}

static void
write_generated_h_file (void)
{
  char *subordinate_file;
  if (subordinate_h_file)
    {
      subordinate_file = subordinate_h_file;
      char *dot = strrchr (subordinate_file, '.');
      if (dot)
        {
          dot[0] = '\0';
        }
    }
  else if (subordinate_c_file)
    {
      subordinate_file = subordinate_c_file;
    }
  else
    {
      subordinate_file = subordinate_image_file;
    }
  char *header_name = subordinate_file;
  int name_len = strlen (header_name) + strlen (".h") + 1;
  char *header_file = xmalloc (name_len);
  strncpy (header_file, subordinate_file, name_len);
  strcat (header_file, ".h");
  if (!header_file)
    {
      fprintf (stderr, "Error: could not create header file '%s\n'",
               header_file);
      exit (1);
    }
  FILE *header_fp = fopen (header_file, "w+");
  if (!header_fp)
    {
      fprintf (stderr, "Error: could not open header file '%s' for writing!\n",
               header_name);
      exit (1);
    }
  fprintf (header_fp, "#ifndef __BIN2HEX_XC32_SECONDARY_RECORD_H\n"
                      "#define __BIN2HEX_XC32_SECONDARY_RECORD_H\n");
  if (is_manual_mode ())
    {
      fprintf (header_fp,
               "typedef struct __xc32_section_record {\n"
               "    void *sectionDestinationAddress;\n"
               "    const unsigned char *sectionData;\n"
               "} __xc32_section_record;\n"
               "\n"
               "extern const __xc32_section_record "
               "__attribute__((space(prog))) __secondary_image_sections[];\n"
               "extern const void "
               "__xc32_LoadSecondarySection(__xc32_section_record "
               "*section_to_load);\n"
               "extern const void __xc32_LoadAllSecondarySections();\n");
    }
  fprintf (header_fp, "\n#endif //__BIN2HEX_XC32_SECONDARY_RECORD_H");
  free (header_file);
}

static struct section_list *
write_section_subordinate (bfd *abfd, struct section_list *first, PTR fp)
{
  struct section_list *s = first;
  bfd_size_type max_section_size = 0;
  size_t longest_section_name = 0;
  for (s = first; s; s = s->next)
    {
      if (PIC32_IS_LOADABLE (s->sec))
        {
          if (strlen (s->sec->name) > longest_section_name)
            longest_section_name = strlen (s->sec->name);
          if (s->sec->size > max_section_size)
            max_section_size = s->sec->size;
        }
    }
  write_generated_h_file ();
  FILE *imagefile = fp;
  fprintf (imagefile,
           "/*\n"
           " *   EDIT AT YOUR OWN RISK\n"
           " *   Generated by xc32-bin2hex %s\n"
           " *\n",
           BFD_VERSION_STRING);
  if (is_manual_mode ())
    {
      fprintf (
          imagefile,
          " *\n"
          " *   Passing \"-C/--image-generated-c <path>\" along with "
          "\"-M/--image-copy-mode manual\" generates a .c file with\n"
          " *   the secondary core contents. A .h file is generated providing "
          "helper functions to copy the secondary core contents.\n"
          " *   Not specifying \"-M/--image-copy-mode\" defaults to using "
          "auto as the mode.\n"
          " *\n");
      fprintf (imagefile,
               " *\n"
               " *   Defining the __XC32_SECTION_MEM_CPY macro can override "
               "the image copying function. Instead of using memcpy,\n"
               " *   an end-user can implement their own copying function but "
               "must ensure the function signature matches the\n"
               " *   data types of arguments passed.\n"
               " * */\n");
      fprintf (imagefile, "#ifndef __XC32_SECTION_MEM_CPY\n"
                          "#define __XC32_SECTION_MEM_CPY memcpy\n"
                          "#endif\n"
                          " \n"
                          "#include <string.h>\n"
                          " \n"
                          "typedef struct __xc32_section_record {\n"
                          "    void *sectionDestinationAddress;\n"
                          "    const unsigned char *sectionData;\n"
                          "    const size_t sectionSizeInBytes;\n"
                          "} __xc32_section_record;\n");
    }
  else
    {
      fprintf (
          imagefile,
          " *\n"
          " *   Passing \"-C/--image-generated-c <path>\" along with "
          "\"-M/--image-copy-mode auto\" generates a .c file with\n"
          " *   the secondary core contents. The dinit mechanism will "
          "automatically copy the secondary contents to relevant memory. \n"
          " *   Not specifying \"-M/--image-copy-mode\" defaults to using "
          "auto as the mode.\n"
          " * */\n");
    }
  unsigned int unique_id = 0;
  unsigned char *buffer = xmalloc (max_section_size);
  char *curr_section_name = xmalloc (longest_section_name + 1);
  int indent_offset = 4;
  for (s = first; s != NULL; s = s->next)
    {
      if (!PIC32_IS_LOADABLE (s->sec))
        continue;
      strcpy (curr_section_name, s->sec->name);
      convert_to_function_name (curr_section_name);
      if (s->sec->vma != s->sec->lma)
        {
          fprintf (stderr,
                   "*** Info: VMA does not match LMA. Defaulting to VMA for "
                   "section %s\n",
                   s->sec->name);
        }
      unsigned char *data = buffer;
      uint32_t sec_size = s->sec->size;
      uint32_t mem_passed = 0x0;
      if (bfd_get_section_contents (abfd, s->sec, data, 0, s->sec->size) == 0)
        {
          fprintf (stderr, "*** Error %d: could not get section contents %s\n",
                   bfd_get_error (), s->sec->name);
        }
      if (is_manual_mode ())
        {
          fprintf (imagefile,
                   "\nconst static unsigned char __attribute__((space(prog))) "
                   "__%s_section_id%d[] = \n"
                   "{\n",
                   curr_section_name, unique_id);
          size_t j;
          fprintf (imagefile, "%*c", indent_offset, ' ');
          for (j = 0; j < sec_size; j++)
            {
              if (j != 0)
                {
                  if ((mem_passed % 16) == 0)
                    {
                      fprintf (imagefile, ",\n");
                      fprintf (imagefile, "%*c", indent_offset, ' ');
                    }
                  else
                    {
                      fprintf (imagefile, ",");
                    }
                }
              fprintf (imagefile, "0x%2.2x", data[0]);
              data += 1;
              mem_passed++;
            }
          fprintf (imagefile, "\n};\n");
          unique_id++;
          continue;
        }
      size_t j;
      // As of at least v4.20, the compiler is making char arrays 4-byte
      // aligned.
      unsigned int vars_to_fill = (4 - ((hex_as_int + s->sec->vma) % 4)) % 4;
      if (vars_to_fill != 0)
        {
          for (j = 0; j < vars_to_fill; j++)
            {
              fprintf (
                  imagefile,
                  "\nunsigned char __attribute__((space(data), "
                  "address(0x%2.2llX), keep, used)) __%s_section_VAR_id%d = ",
                  hex_as_int + s->sec->vma + j, curr_section_name, unique_id);
              fprintf (imagefile, "0x%2.2x;\n", data[0]);
              data += 1;
              mem_passed++;
              unique_id++;
            }
          fprintf (imagefile, "\n");
        }
      if (s->sec->size == vars_to_fill)
        {
          continue;
        }
      fprintf (imagefile,
               "\nunsigned char __attribute__((space(data), "
               "address(0x%2.2llX), keep, used)) __%s_section_id%d[] = \n"
               "{\n",
               hex_as_int + s->sec->vma + vars_to_fill, curr_section_name,
               unique_id);
      fprintf (imagefile, "%*c", indent_offset, ' ');
      for (j = 0; j < sec_size - vars_to_fill; j++)
        {
          if (j != 0)
            {
              if ((mem_passed % 16) == 0)
                {
                  fprintf (imagefile, ",\n");
                  fprintf (imagefile, "%*c", indent_offset, ' ');
                }
              else
                {
                  fprintf (imagefile, ",");
                }
            }
          fprintf (imagefile, "0x%2.2x", data[0]);
          data += 1;
          mem_passed++;
        }
      unique_id++;
      fprintf (imagefile, "\n};\n");
    }
  free (buffer);
  static const char *sections_template
      = "{ (void*) 0x%2.2llX, __%s_section_id%d, sizeof(__%s_section_id%d) }";
  static const char *sections_array_declaration
      = "const __xc32_section_record __attribute__((space(prog))) "
        "__secondary_core_sections[] = ";
  if (is_manual_mode ())
    {
      fprintf (imagefile, "%s", sections_array_declaration);
      fprintf (imagefile, "\n{\n");
      unsigned int unique_id_verify = 0;
      for (s = first; s != NULL; s = s->next)
        {
          if (!PIC32_IS_LOADABLE (s->sec))
            continue;
          strcpy (curr_section_name, s->sec->name);
          convert_to_function_name (curr_section_name);
          fprintf (imagefile, "%*c", indent_offset, ' ');
          fprintf (imagefile, sections_template, hex_as_int + s->sec->vma,
                   curr_section_name, unique_id_verify, curr_section_name,
                   unique_id_verify);
          unique_id_verify++;
          if (unique_id_verify == unique_id)
            continue;
          fprintf (imagefile, ",");
          fprintf (imagefile, "\n");
        }
      if (unique_id_verify != unique_id)
        {
          fprintf (stderr, "*** Error: Section count mismatch when generating "
                           ".c file in Manual mode.");
          exit (1);
        }
      fprintf (imagefile, "\n};");
      fprintf (imagefile, "\nvoid __xc32_LoadAllSecondarySections(void) { \n");
      unsigned int k = 0;
      for (k = 0; k < unique_id; k++)
        {
          fprintf (imagefile,
                   "    "
                   "__XC32_SECTION_MEM_CPY(__secondary_core_sections[%d]."
                   "sectionDestinationAddress, "
                   "__secondary_core_sections[%d].sectionData, "
                   "__secondary_core_sections[%d].sectionSizeInBytes );\n"
                   "",
                   k, k, k);
        }
      fprintf (imagefile, "}\n\n");
      fprintf (imagefile,
               "void __xc32_LoadSecondarySection(__xc32_section_record "
               "*section_to_load) {\n"
               "    "
               "__XC32_SECTION_MEM_CPY(section_to_load->"
               "sectionDestinationAddress, section_to_load->sectionData, "
               "section_to_load->sectionSizeInBytes);\n"
               "}\n\n");
      fprintf (imagefile, "\n");
    }
  free (curr_section_name);
  return s;
}

static void
write_section_list_subordinate (bfd *abfd, PTR fp, struct section_list *p)
{

  struct section_list *s;
  for (s = p; s != NULL; s ? s = s->next : s)
    {
      if (s->sec)
        {
          s = write_section_subordinate (abfd, s, fp);
        }
    }
}

static int
write_generated_files (bfd *abfd)
{
  int rc = 0;
  char *file
      = subordinate_c_file ? subordinate_c_file : subordinate_image_file;
  char *file_tmp = file;
  char *dot;
  dot = strrchr (file_tmp, '.');
  if (dot)
    dot[0] = '\0';
  int name_len = strlen (file) + strlen (".c") + 1;
  char *filename = xmalloc (name_len);
  strncpy (filename, file, name_len);
  strcat (filename, ".c");
  FILE *fp = fopen (filename, "w+");
  if (!fp)
    {
      fprintf (stderr, "Error: could not open file '%s' for writing!\n",
               filename);
      exit (1);
    }
  init_section_list (&outputs);
  bfd_map_over_sections (abfd, &build_section_list, outputs);
  write_section_list_subordinate (abfd, fp, outputs);
  free_section_list (&outputs);
  free (filename);
  return rc;
}
