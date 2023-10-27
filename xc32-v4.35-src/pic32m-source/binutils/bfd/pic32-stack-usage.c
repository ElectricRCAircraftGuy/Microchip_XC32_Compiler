/* pic32-stack-usage.c - Contributed by Microchip Corporation.
 * Written by Alexandru Panek, Lavinia Ghica and Cosmin-Gabriel Samoila.
 */

#include "libiberty.h"
#include <limits.h>
#include <string.h>

#include "pic32-stack-usage.h"
#include "pic32-vecset.h"

bfd_boolean pic32_stack_usage = 0;

extern struct su_section *su_sections;
extern struct su_section **su_sections_arr;
extern unsigned int max_name_length;
extern unsigned int num_functions;

#define BUFFER_LEN 1024

/* we will build a string of filenames where we don't find stack
 * usage information and print it as a warning at the end
 * if stack usage is enabled
 */
static vec_type *missing_su_info_files;
static vec_type *missing_su_hdr_files;
static vec_type *files_with_wrong_version;

const char *const SU_FLAGS_REPR[SU_NUM_FLAGS] = {
  "INDIRECT_CALLS",
  "INLINE_ASM",
  "MISSING_INFO",
  "INACCURATE",
  "INTERRUPT",
  "DISJOINT_FUNC",
  "UNINTERRUPTIBLE",
  "RECURSIVE",
  "ENTRY_FUNC",
};

const char *const SU_MEMTYPE_REPR[] = {
  "STATIC",
  "DYNAMIC",
  "DYNAMIC BOUNDED"
};

uint32_t value32_to_host (const bfd * abfd, const uint32_t v)
{
  if ((__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
       && abfd->xvec->byteorder == BFD_ENDIAN_BIG)
      || (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
          && abfd->xvec->byteorder == BFD_ENDIAN_LITTLE))
    return v;

  /* do the byteswap if machine endianness is different
   * from input bfd endianness.
   */
  return __builtin_bswap32 (v);
}


/* PA is enabled if '-mpa' is present in the COLLECT_GCC_OPTIONS env var */
bfd_boolean
pic32_pa_enabled (void)
{
  static int pa_enabled_value = -1;
  if (pa_enabled_value < 0)
    {
      const char *p = getenv ("COLLECT_GCC_OPTIONS");
      pa_enabled_value = p && strstr (p, "-mpa");
    }
  return pa_enabled_value;
}

extern struct su_section *
add_su_section_node (bfd * abfd,
                     const char *name,
                     uint32_t faddr, uint32_t size, uint8_t kind, uint32_t flags)
{
  struct su_section *node = su_sections, *prev;

  if (!su_sections)
    {
      su_sections = (struct su_section *) xcalloc (1, sizeof (struct su_section));
      node = su_sections;
    }
  else
    {
      while (node)
        {
          prev = node;
          node = node->next;
        }
      node = (struct su_section *) xcalloc (1, sizeof (struct su_section));
      prev->next = node;
    }

  node->fname = xstrdup (name);
  node->aliases = VEC_NEW (char *, 0, 0);
  node->the_bfd = abfd;
  node->callees = NULL;
  node->nb_callees = 0;
  node->max_callees = 0;
  node->next = NULL;

  /* Initialize this struct members only if the section is
   * not incomplete (i.e. the function has stack usage information)
   * If we don't have stack usage info for the function we should call
   * this with SU_MISSING_INFO flag set.
   */
  if (!(flags & SU_MISSING_INFO))
    {
      node->faddr = faddr;
      node->used_stack = size;
      node->used_mem_type = kind;
      node->flags = flags;
    }
  else
    node->used_stack = 0;

  /* reset SU_PROCESSED_NODE */
  node->flags &= ~SU_PROCESSED_NODE;
  /* set SU_DISJOINT_FUNC flag, unless already SU_INTERRUPT */
  if (!(node->flags & SU_INTERRUPT))
    node->flags |= SU_DISJOINT_FUNC;
  node->max_stack = UINT_MAX;

  return node;
}

/* Checks if the object has a .xc_stack_usage.hdr section
 * and the version matches with current Stack Usage version.
 *
 * A warning is thrown if the section is missing or has a different
 * version but the linking continues. This will most likely lead to
 * inaccurate stack usage computation.
 */
static void
check_su_meta_section (bfd * abfd, struct bfd_section *s)
{
  uint8_t *sec_content;
  uint32_t version;
  uint8_t size;

  if (!s)
    {
      if (!missing_su_hdr_files)
        missing_su_hdr_files = VEC_NEW (const char *, 0, 0);
      VEC_PUSHBACK (const char *, missing_su_hdr_files, xstrdup (abfd->filename));
      return;
    }

  sec_content = (uint8_t *) xmalloc (s->size);

  bfd_get_section_contents (abfd, s, sec_content, 0, s->size);

  size = sec_content[0];
  version = value32_to_host (abfd, *(uint32_t *) (sec_content + 1));

  if (version != SU_VERSION)
    {
      if (!files_with_wrong_version)
        files_with_wrong_version = VEC_NEW (const char *, 0, 0);
      VEC_PUSHBACK (const char *, files_with_wrong_version,
                    xstrdup (abfd->filename));
    }
}

/* Returns first node with this function name or NULL.
 * Obs: There might be multiple nodes with the same function
 *      names that can come from different objects;
 *      abfd == NULL will return the first node with a matching name,
 *      abfd != NULL will match on both name and bfd
 */
extern struct su_section *
get_function_by_name_bfd (const char *fname, bfd * abfd)
{
  struct su_section *node = su_sections;
  int i;

  while (node)
    {
      if (!abfd || (abfd == node->the_bfd))
        {
          if (!strcmp (node->fname, fname))
            return node;

          /* also check the aliases / alternate names */
          for (i = 0; i != VEC_SIZE (node->aliases); ++i)
            if (!strcmp (fname, VEC (char *, node->aliases, i)))
              return node;
        }
      node = node->next;
    }

  return NULL;
}

/* Generic iterator over the sections; calls 'func' for each su_section,
 * passing it the su_section address and 'param'.
 * If the callback returns a non-zero value, the iteration stops and
 * 'map_over_su_sections' returns with that value,
 * otherwise it returns zero (i.e. all sections were processed ok). */
extern intptr_t
map_over_su_sections (intptr_t (*func) (struct su_section *, void *), void *param)
{
  intptr_t rc = 0;
  if (func)
    {
      struct su_section *node = su_sections;

      while (node && (rc = func (node, param)) == 0)
        node = node->next;
    }
  return rc;
}

#define FST_NB_CALLEES	2
#ifndef NEXTPOW2
#define NEXTPOW2(X) ({ \
  uint32_t x = (X); x ? 1U << (32 - __builtin_clz (x)) : 1U; })
#endif


void
add_func_callee (struct su_section *const node, struct su_section *const callee_node)
{
  /* first callee added */
  if (node->callees == NULL)
    {
      node->callees = (struct su_section **) xcalloc (FST_NB_CALLEES,
                                                      sizeof (struct su_section *));
      node->max_callees = FST_NB_CALLEES;
      node->nb_callees = 1;
      node->callees[0] = callee_node;
    }
  else
    {
      /* avoid adding a callee multiple times */
      uint32_t i;
      for (i = 0; i != node->nb_callees; ++i)
        if (callee_node == node->callees[i])
          return;

      if (node->nb_callees == node->max_callees)
        {
          node->max_callees = NEXTPOW2 (node->max_callees);
          node->callees = xrealloc (node->callees,
                                    node->max_callees *
                                    sizeof (struct su_section *));
        }
      node->callees[node->nb_callees++] = callee_node;
    }

  /* callee is no longer a disjoint function */
  callee_node->flags &= ~SU_DISJOINT_FUNC;
}


/* Returns first node that is not processed
 * (i.e. SU_PROCESSED_NODE flag unset)
 */
extern struct su_section *
get_first_unprocessed_su_section ()
{
  struct su_section *node = su_sections;

  while (node)
    {
      node = node->next;
      if (!(node->flags & SU_PROCESSED_NODE))
        return node;
    }

  return NULL;
}


/* Returns the ELF symbol for a su_section (corresponding to its 'fname') */
static Elf_Internal_Sym *
get_node_sym (struct su_section   *node,
              Elf_Internal_Sym    *isymbuf)
{
  Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (node->the_bfd);
  size_t symcount = symtab_hdr->sh_size / sizeof (Elf32_External_Sym);
  Elf_Internal_Sym *isym, *isymend;

  for (isym = isymbuf + 1, isymend = isymbuf + symcount; isym < isymend; ++isym)
    if ((ELF_ST_TYPE (isym->st_info) == STT_FUNC
          || ELF_ST_TYPE (isym->st_info) == STT_OBJECT) /* XC32-1689: STT_OBJECTs also */
        && !strcmp (node->fname, bfd_elf_sym_name (node->the_bfd, symtab_hdr,
                                                   isym, NULL)))
      return isym;

  return NULL;
}


/* a su_section and the corresponsing ELF symbol */
typedef struct su_section_sym {
  struct su_section *node;
  Elf_Internal_Sym  *isym;
} su_section_sym;


/* fills in the aliases information for all the su_sections in the specified bfd */
static void
fill_aliases_info (bfd              *abfd,
                   Elf_Internal_Sym *isymbuf,
                   vec_type         *su_syms)
{
  Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (abfd);
  size_t symcount = symtab_hdr->sh_size / sizeof (Elf32_External_Sym);
  Elf_Internal_Sym *isym, *isymend, *isym2;
  int i;

  /* for each function symbol */
  for (isym = isymbuf + 1, isymend = isymbuf + symcount; isym < isymend; ++isym)
    if (ELF_ST_TYPE (isym->st_info) == STT_FUNC)
      {
        /* see if it's an alias to an existing su_section */
        for (i = 0; i != VEC_SIZE (su_syms); ++i)
          {
            su_section_sym *su_sym = &VEC (su_section_sym, su_syms, i);
            isym2 = su_sym->isym;

            /* i.e. a different function symbol but with the same address */
            if (isym2 != isym
                && isym2->st_shndx == isym->st_shndx
                && isym2->st_value == isym->st_value)
              {
                const char *name = bfd_elf_sym_name (abfd, symtab_hdr, isym, NULL);
                /* ok, add it to the list of aliases for this su_section */
                VEC_PUSHBACK (char *, su_sym->node->aliases, xstrdup (name));
              }
          }
      }
}

static bfd_boolean
pic32_is_PAed_object (bfd *abfd)
{
  static const char pa_obj_prefix[] = "__pa_outline_";
  return pic32_pa_enabled ()
           && !strncmp (basename (abfd->filename),
                        pa_obj_prefix, sizeof (pa_obj_prefix) - 1);
}

/* This function is called for each object to parse the
 * concatenated .xc_stack_usage* sections.
 *
 * A warning is thrown if any of the stack usage sections are missing
 * or if object has a different stack usage version. The linking continues
 * but this will most likely lead to inaccurate stack usage computation.
 */
extern void
add_su_sections_from_bfd (bfd * abfd)
{
  Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (abfd);
  Elf_Internal_Sym *isymbuf = NULL;
  struct bfd_section *bfd_sec = abfd->sections;
  struct bfd_section *sec = NULL, *meta_sec = NULL;
  uint8_t *sec_content;
  bfd_size_type sec_size;
  int offset = 0;
  int i = 0;
  int fname_sz;
  vec_type *su_syms = NULL;

  /* XC32-1683: ignore the objects created by the PA tool as we know those
   * are not containing any SU info at the moment and we compensate for that
   * by detecting the PAed callees in pic32_su_max_stack () */
  if (pic32_is_PAed_object (abfd))
    return;

  for (; bfd_sec; bfd_sec = bfd_sec->next)
    {
      if (CONST_STRNEQ (bfd_sec->name, SU_SECTION_HDR))
        {
          meta_sec = bfd_sec;
        }
      else if (CONST_STRNEQ (bfd_sec->name, SU_SECTION))
        {
          sec = bfd_sec;
        }
    }

  /* first check the header and extract version */
  check_su_meta_section (abfd, meta_sec);

  /* we will only be adding the .xc_stack_usage sections */
  if (!sec)
    {
      if (!missing_su_info_files)
        missing_su_info_files = VEC_NEW (const char *, 0, 0);
      VEC_PUSHBACK (const char *, missing_su_info_files, xstrdup (abfd->filename));
      return;
    }

  sec_size = sec->size;

  sec_content = (uint8_t *) xmalloc (sec_size);

  /* get the section contents for parsing */
  bfd_get_section_contents (abfd, sec, sec_content, 0, sec_size);

  /* also get the bfd symbols for filling out the alias info */
  isymbuf =
    bfd_elf_get_elf_syms (abfd, symtab_hdr,
                          symtab_hdr->sh_size / sizeof (Elf32_External_Sym),
                          0, NULL, NULL, NULL);

  su_syms = VEC_NEW (su_section_sym, 0, 0);
  while (offset < sec_size)
    {
      su_section_sym su_sym;
      uint32_t faddr = value32_to_host (abfd, *(uint32_t *) (sec_content + offset));
      offset += 4;
      char *fname = (char *) (sec_content + offset);
      fname_sz = strlen (fname);
      offset += (fname_sz + 1);
      uint32_t size = value32_to_host (abfd, *(uint32_t *) (sec_content + offset));
      offset += 4;
      uint32_t flags = value32_to_host (abfd, *(uint32_t *) (sec_content + offset));
      offset += 4;
      uint8_t kind = sec_content[offset];
      offset++;

      /* add a su_section node in the linked list */
      su_sym.node = add_su_section_node (abfd, fname, faddr, size, kind, flags);

      /* (temporarily) collect the SU infos from this bfd + the assoc. syms */
      su_sym.isym = get_node_sym (su_sym.node, isymbuf);
      if (su_sym.isym)
        VEC_PUSHBACK (su_section_sym, su_syms, su_sym);
      else
        fprintf (stderr, "warning: symbol for '%s' su_section not found (%s)\n",
                 fname, abfd->filename); /* XC32-1689: warn about missing symbols */
    }

  if (offset != sec_size)
    {
      fprintf (stderr,
               "error: something went wrong when parsing stack usage sections: parsed_bytes != sec_size\n");
      abort ();
    }

  fill_aliases_info (abfd, isymbuf, su_syms);
  VEC_DELETE (su_syms);

  free (sec_content);
  free (isymbuf);
}

/* This counts the number of su_section nodes and stores all the pointers
 * in an array. It assumes that linked list will remain unchanged after
 * this function was called and we will use the index in the array as an
 * unique ID for a section. This ID will be used in the algoritm for
 * computing maximum used stack.
 *
 * While itterating through list, we will also gather the maximum
 * function name length for pretty printing.
 */
extern void
su_allocate_array ()
{
  struct su_section *node = su_sections;
  unsigned int nlen, i = 0;
  num_functions = 0;
  max_name_length = 0;

  while (node)
    {
      num_functions++;
      nlen = strlen (node->fname);
      if (nlen > max_name_length)
        max_name_length = nlen;
      node = node->next;
    }

  /* put a max length for formating to 20 characters */
  if (max_name_length > 20)
    max_name_length = 20;

  su_sections_arr =
    (struct su_section **) xmalloc (num_functions * sizeof (struct su_section *));

  node = su_sections;
  while (node)
    {
      su_sections_arr[i] = node;
      node = node->next;
      i++;
    }
}

/* helper to get the su_section for a certain function;
 * if a real su_section isn't found for the function, a dummy one is created  */
struct su_section *
pic32_su_call_graph_get_create (bfd * abfd, const char *fname, bfd_vma faddr)
{
  struct su_section *node = get_function_by_name_bfd (fname, abfd);

  if (node == NULL)
    {
      /* add new node in su_sections */
      node = add_su_section_node (abfd, fname, faddr , 0, 0,
                                  SU_MISSING_INFO);
    }
  else if (node->faddr == 0)
    node->faddr = faddr;

  return node;
}

/* helper to add an arc in the call graph given the two functions/nodes */
void
pic32_su_add_to_call_graph (bfd * caller_bfd, const char *caller_name, bfd_vma caller_addr,
                            bfd * callee_bfd, const char *callee_name, bfd_vma callee_addr)
{
  struct su_section *caller_node =
    pic32_su_call_graph_get_create (caller_bfd, caller_name, caller_addr);

  struct su_section *callee_node =
    pic32_su_call_graph_get_create (callee_bfd, callee_name, callee_addr);

  add_func_callee (caller_node, callee_node);
}


extern void
free_su_sections ()
{
  struct su_section *next, *node = su_sections;
  int i;

  while (node)
    {
      next = node->next;
      free (node->fname);

      for (i = 0; i != VEC_SIZE (node->aliases); ++i)
        free (VEC (char *, node->aliases, i));
      VEC_DELETE (node->aliases);

      if (node->callees != NULL)
        free (node->callees);

      free (node);
      node = next;
    }
  su_sections = NULL;

  free (su_sections_arr);
  su_sections_arr = NULL;
}

extern void
print_su_sections ()
{
  struct su_section *node = su_sections;
  int i;

  while (node)
    {
      printf ("Stack Usage: function %s @%X used stack 0x%x, type: %s",
              node->fname, node->faddr, node->used_stack,
              SU_MEMTYPE_REPR[node->used_mem_type]);
      if (node->the_bfd)
        printf (", filename: %s, flags: {", node->the_bfd->filename);
      else
        printf (", (nil), flags {");
      for (i = 0; i < SU_NUM_FLAGS; i++)
        {
          if (node->flags & (1 << i))
            {
              printf ("%s,", SU_FLAGS_REPR[i]);
            }
        }
      if (node->flags & SU_INTERRUPT)
        printf ("}, IPL: %u;\n", SU_GET_IPL (node->flags));
      else
        printf ("};\n");
      if (VEC_SIZE (node->aliases))
        {
          printf ("\taliases:");
          for (i = 0; i != VEC_SIZE (node->aliases); ++i)
            printf (" %s", VEC (char *, node->aliases, i));
          printf ("\n");
        }
      node = node->next;
    }
}

static inline void
su_print_report_lines (FILE * fp, uint32_t flag)
{
  char line_buffer[BUFFER_LEN];
  int offset = 0;
  struct su_section *node;

  for (node = su_sections; node != NULL; node = node->next)
    {
      uint32_t flags = node->flags;
      if (flags & SU_DISCARDED_NODE) /* ignore discarded functions */
        continue;
      if (flags & flag)
        {
          offset = snprintf (line_buffer, BUFFER_LEN - 1, "\n\t%s", node->fname);

          /* we don't give an estimate for recursive functions */
          if (flag != SU_RECURSIVE)
            offset +=
              snprintf (line_buffer + offset, BUFFER_LEN - 1 - offset,
                        " uses %d bytes", node->max_stack);

          /* if we are printing in file, also print address */
          if (fp != stdout)
            offset +=
              snprintf (line_buffer + offset, BUFFER_LEN - 1 - offset,
                        " (address 0x%X)", node->faddr);

          fprintf (fp, "%s", line_buffer);
        }
    }
}


static inline int
su_file_reached (vec_type * v, unsigned int idx)
{
  const char *v_val = VEC (const char *, v, idx);
  struct su_section *node;

  for (node = su_sections; node != NULL; node = node->next)
    if (node->the_bfd && strcmp (node->the_bfd->filename, v_val) == 0)
      return 1;
  return 0;
}


/* When we print the report for stack usage we might issue
 * error/warning messages when we don't find SU info in .o files:
 * warning: .xc_stack_usage section is missing from files:
 *    linker stubs
 *    /opt/microchip/xc32/v3.00/bin/bin/../../lib/gcc/pic32c/8.3.1/thumb/v7e-m+fp/hard/crti.o
 *    /opt/microchip/xc32/v3.00/bin/bin/../../lib/gcc/pic32c/8.3.1/thumb/v7e-m+fp/hard/crtbegin.o
 *    data_init.o
 *    lib_a-init.o
 *    /opt/microchip/xc32/v3.00/bin/bin/../../lib/gcc/pic32c/8.3.1/thumb/v7e-m+fp/hard/crtend.o
 *    /opt/microchip/xc32/v3.00/bin/bin/../../lib/gcc/pic32c/8.3.1/thumb/v7e-m+fp/hard/crtn.o
 *
 * One of the problems is that those .o might not have any function inside
 * or will not be reached. In this function, we will eliminate all the .o
 * files reported here but not reached when building the call graph.
 */
static void
su_eliminate_unreached_files ()
{
  struct su_section *node;
  unsigned int i;

  if (missing_su_info_files)
    {
      for (i = 0; i != VEC_SIZE (missing_su_info_files); i++)
        {
          if (!su_file_reached (missing_su_info_files, i))
            {
              char *str = VEC (char *, missing_su_info_files, i);
              free (str);
              VEC_ERASE (char *, missing_su_info_files, i);
              i--;
            }
        }
    }

  if (missing_su_hdr_files)
    {
      for (i = 0; i != VEC_SIZE (missing_su_hdr_files); i++)
        {
          if (!su_file_reached (missing_su_hdr_files, i))
            {
              char *str = VEC (char *, missing_su_hdr_files, i);
              free (str);
              VEC_ERASE (char *, missing_su_hdr_files, i);
              i--;
            }
        }
    }

  if (files_with_wrong_version)
    {
      for (i = 0; i != VEC_SIZE (files_with_wrong_version); i++)
        {
          if (!su_file_reached (files_with_wrong_version, i))
            {
              char *str = VEC (char *, files_with_wrong_version, i);
              free (str);
              VEC_ERASE (char *, files_with_wrong_version, i);
              i--;
            }
        }
    }
}

/*
 * Stack Usage Estimation
 * function that prints the stack usage report
 */
extern void
pic32_print_su_report (FILE * fp)
{
  struct su_section *root = NULL, *node;
  /* if we have to print a line > 512 chars in the report,
   * something is definetly wrong.
   */
  unsigned int recursive_funcs = 0;
  unsigned int inaccurate_funcs = 0;
  unsigned int interrupt_funcs = 0;
  unsigned int disjoint_funcs = 0;
  int index = 1;
  int offset = 0;

  /* it is not necessary to count how many functions we have
   * for each category but since we most likely will anyway
   * iterate through all sections anyway, we could count them
   * and use this information to pretty format if necessary
   */
  for (node = su_sections; node != NULL; node = node->next)
    {
      uint32_t flags = node->flags;
      if (flags & SU_DISCARDED_NODE) /* ignore discarded functions */
        continue;
      if (flags & SU_RECURSIVE)
        recursive_funcs++;
      if (flags & SU_INACCURATE)
        inaccurate_funcs++;
      if (flags & SU_INTERRUPT)
        interrupt_funcs++;
      if (flags & SU_DISJOINT_FUNC)
        disjoint_funcs++;
      if (!root && (flags & SU_ENTRY_FUNC))
        root = node;
    }

  fprintf (fp, "============= STACK USAGE GUIDANCE =============\n");

  /* do this print only when printing the report not when dumping it
   * into the mapfile
   */
  if (fp == stdout)
    {
      unsigned i;

      su_eliminate_unreached_files ();

      if (missing_su_info_files && VEC_SIZE (missing_su_info_files))
        {
          fprintf (stderr,
                   "warning: .xc_stack_usage section is missing from %d files:\n",
                   VEC_SIZE (missing_su_info_files));
          for (i = 0; i != VEC_SIZE (missing_su_info_files); ++i)
            fprintf (stderr, "\t%s\n", VEC (const char *, missing_su_info_files, i));
          fprintf (stderr,
                   "Stack Usage analysis might be inaccurate because of this.\n");
          VEC_DELETE (missing_su_info_files);
        }

      if (missing_su_hdr_files && VEC_SIZE (missing_su_hdr_files))
        {
          fprintf (stderr,
                   "warning: .xc_stack_usage.hdr section is missing from %d files:\n",
                   VEC_SIZE (missing_su_hdr_files));
          for (i = 0; i != VEC_SIZE (missing_su_hdr_files); ++i)
            fprintf (stderr, "\t%s\n", VEC (const char *, missing_su_hdr_files, i));
          fprintf (stderr,
                   "Stack Usage analysis might be inaccurate because of this.\n");
          VEC_DELETE (missing_su_hdr_files);
        }

      if (files_with_wrong_version && VEC_SIZE (files_with_wrong_version))
        {
          fprintf (stderr,
                   "warning: Different stack usage version for %d files:\n",
                   VEC_SIZE (files_with_wrong_version));
          for (i = 0; i != VEC_SIZE (files_with_wrong_version); ++i)
            fprintf (stderr, "\t%s\n",
                     VEC (const char *, files_with_wrong_version, i));
          fprintf (stderr,
                   "Stack Usage analysis might be inaccurate because of this.\n");
          VEC_DELETE (files_with_wrong_version);
        }
    }

  if (root)
    {
      fprintf (fp, "In the call graph beginning at %s", root->fname);
      /* if we are printing in file, also print address */
      if (fp != stdout)
        fprintf (fp, " (address 0x%X)", root->faddr);
      fprintf (fp, ",\n\t%d bytes of stack are required.\n", root->max_stack);
    }
  else
    {
      fprintf (fp, "Couldn't determine the root of the main call graph.\n");
    }

  if (recursive_funcs || inaccurate_funcs || interrupt_funcs || disjoint_funcs)
    fprintf (fp, "\nHowever, the following cautions exists:\n");

  /* print recursive functions */
  if (recursive_funcs)
    {
      fprintf (fp, "\n%d. Recursion has been detected:", index);
      su_print_report_lines (fp, SU_RECURSIVE);
      fprintf (fp, "\nNo stack usage predictions can be made.\n");
      index++;
    }

  /* print inaccurate functions */
  if (inaccurate_funcs)
    {
      fprintf (fp, "\n%d. Indeterminate stack adjustment has been detected:", index);
      su_print_report_lines (fp, SU_INACCURATE);
      fprintf (fp, "\nNo stack usage predictions can be made.\n");
      index++;
    }

  /* print interrupt functions */
  if (interrupt_funcs)
    {
      fprintf (fp, "\n%d. The following functions are interrupt functions:", index);
      su_print_report_lines (fp, SU_INTERRUPT);
      fprintf (fp, "\nYou must add stack allowances for those functions.\n");
      index++;
    }

  /* print disjoint functions */
  if (disjoint_funcs)
    {
      fprintf (fp,
               "\n%d. The following functions cannot be connected to the main call graph.\n",
               index);
      fprintf (fp, "This is usually caused by some indirection:");
      su_print_report_lines (fp, SU_DISJOINT_FUNC);
      fprintf (fp, "\nYou must add stack allowances for those functions.\n");
      index++;
    }

  fprintf (fp, "================================================\n");
}
