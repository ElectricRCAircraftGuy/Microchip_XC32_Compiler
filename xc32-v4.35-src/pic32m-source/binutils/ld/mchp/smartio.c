/* The smartio implementation for the linker.

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

#include "ld.h"
#include "ldmain.h"
#include "ldmisc.h"

#include "ldexp.h"
#include "ldlang.h"

#include "elf-bfd.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "smartio_suffix.h"
#include "smartio.h"

#ifdef NO_SMARTIO_DUMP
#define DEBUG_SMARTIO(...)
#else
#define DEBUG_SMARTIO(...)                                                    \
  do                                                                          \
    {                                                                         \
      if (pic32_debug_smartio)                                                \
        fprintf (stderr, __VA_ARGS__);                                        \
    }                                                                         \
  while (0)
#endif

extern bfd_boolean pic32_debug_smartio;
extern void su_note_smartio_replacement (const char *from, const char *to);

/*
 * The enum smartio_func_index identifies stdio functions with smart-io
 * variations present in the library. This is used to identify smart-io
 * candidates.
 * smart-io calls from the compiler will be prcededed by double-underscores
 * and contain a suffix string indicating the required conversion spec support.
 */
typedef enum
{
  SIO_none = 0,
  SIO_printf,
  SIO_fprintf,
  SIO_sprintf,
  SIO_vprintf,
  SIO_vfprintf,
  SIO_vsprintf,
  SIO_snprintf,
  SIO_vsnprintf,
  SIO_asprintf,
  SIO_vasprintf,
  SIO_scanf,
  SIO_fscanf,
  SIO_vscanf,
  SIO_sscanf,
  SIO_vsscanf,
  SIO_vfscanf,
  SIO_NUM_FUNCS
} smartio_func_index;

typedef enum
{
  SIO_kind_print,
  SIO_kind_scan,
  SIO_NUM_KINDS
} smartio_func_kind;

typedef struct
{
  const char *name;
  smartio_func_kind kind;
} smartio_func_info;

/* smart-io function info by index. */
/* Must match order of smartio_func_index */
static const smartio_func_info smartio_funcs[SIO_NUM_FUNCS]
    = { { "NONE", SIO_kind_print },      { "printf", SIO_kind_print },
        { "fprintf", SIO_kind_print },   { "sprintf", SIO_kind_print },
        { "vprintf", SIO_kind_print },   { "vfprintf", SIO_kind_print },
        { "vsprintf", SIO_kind_print },  { "snprintf", SIO_kind_print },
        { "vsnprintf", SIO_kind_print }, { "asprintf", SIO_kind_print },
        { "vasprintf", SIO_kind_print }, { "scanf", SIO_kind_scan },
        { "fscanf", SIO_kind_scan },     { "vscanf", SIO_kind_scan },
        { "sscanf", SIO_kind_scan },     { "vsscanf", SIO_kind_scan },
        { "vfscanf", SIO_kind_scan } };

/*
 * Trie structure for matching stdio functions in the smart-io set.
 * 'str' is non-null for special nodes which use represent a common
 * suffix (i.e. 'printf'). By convention c is '\0' if str is non-null.
 * If nsucc is 0 then index contains the identified function index.
 */
typedef struct smartio_trie_node_
{
  char c;
  const char *str;
  smartio_func_index index;
  int nsucc;
  int succ[5];
} smartio_trie_node;

static smartio_trie_node smartio_trie[] = {
  /* root node */
  /* 0 */ { 0, NULL, SIO_none, 5, { 1, 2, 3, 4, 5 } },
  /* 1 */ { 0, "asprintf", SIO_asprintf, 0, { 0, 0, 0, 0, 0 } },/* prefix ''*/
  /* 2 */ { 'f', NULL, SIO_none, 2, { 6, 7, 0, 0, 0 } },
  /* 3 */ { 0, "printf", SIO_printf, 0, { 0, 0, 0, 0, 0 } },
  /* 4 */ { 's', NULL, SIO_none, 4, { 8, 9, 10, 18, 0 } },
  /* 5 */ { 'v', NULL, SIO_none, 5, { 11, 12, 13, 19, 20 } },
  /* 6 */ { 0, "printf", SIO_fprintf, 0, { 0, 0, 0, 0, 0 } },   /* prefix 'f'*/
  /* 7 */ { 0, "scanf", SIO_fscanf, 0, { 0, 0, 0, 0, 0 } },
  /* 8 */ { 0, "canf", SIO_scanf, 0, { 0, 0, 0, 0, 0 } },       /* prefix 's'*/
  /* 9 */ { 0, "printf", SIO_sprintf, 0, { 0, 0, 0, 0, 0 } },
  /* 10*/ { 0, "scanf", SIO_sscanf, 0, { 0, 0, 0, 0, 0 } },
  /* 11*/ { 0, "printf", SIO_vprintf, 0, { 0, 0, 0, 0, 0 } },   /* prefix 'v'*/
  /* 12*/ { 's', NULL, SIO_none, 4, { 14, 15, 16, 17, 0 } },
  /* 13*/ { 0, "asprintf", SIO_vasprintf, 0, { 0, 0, 0, 0, 0 } },
  /* 14*/ { 0, "printf", SIO_vsprintf, 0, { 0, 0, 0, 0, 0 } },  /* prefix 'vs'*/
  /* 15*/ { 0, "nprintf", SIO_vsnprintf, 0, { 0, 0, 0, 0, 0 } },
  /* 16*/ { 0, "canf", SIO_vscanf, 0, { 0, 0, 0, 0, 0 } },
  /* 17*/ { 0, "scanf", SIO_vsscanf, 0, { 0, 0, 0, 0, 0 } },
  /* 18*/ { 0, "nprintf", SIO_snprintf, 0, { 0, 0, 0, 0, 0 } }, /* prefix 's'*/
  /* 19*/ { 0, "fprintf", SIO_vfprintf, 0, { 0, 0, 0, 0, 0 } }, /* prefix'vf'*/
  /* 20*/ { 0, "fscanf", SIO_vfscanf, 0, { 0, 0, 0, 0, 0 } }
};

struct traverse_hash_info
{
  bfd *abfd;
  asection *sec;
};

/*
 * Use smartio_trie to attempt to match the given symbol name
 * to a smart-io function. Leading underscores will be ignored.
 * SIO_none is returned if no match is found.
 */
static smartio_func_index
smartio_match_sym (const char *str)
{
  long ndx = 0;      /* root of trie */
  long len = 0;      /* length of string ignoring underscores */
  long us_count = 0; /* number of leading underscores */

  while (*str == '_')
    {
      ++str;
      ++us_count;
    }

  len = strlen (str); /* length of remainder */

  /* hack check for _r suffix - leave these alone */
  if (len > 1 && str[len - 2] == '_')
    {
      char c = sio_map_char (str[len - 1]);
      if (!(valid_suffixes & sio_suffix_bit (c)))
        return SIO_none;
    }

  while (len)
    {
      const smartio_trie_node *n = &(smartio_trie[ndx]);
      long j, m;

      if (n->nsucc == 0)
        return n->index;

      for (j = 0, m = n->nsucc; j < m; ++j)
        {
          long succ_index = n->succ[j];
          if (smartio_trie[succ_index].c)
            {
              if (smartio_trie[succ_index].c == *str)
                break;
            }
          else
            {
              long slen = strlen (smartio_trie[succ_index].str);
              if (slen <= len
                  && strncmp (str, smartio_trie[succ_index].str, slen) == 0)
                break;
            }
        }

      /* Bail out if we reached the end without a match. */
      if (j == m)
        return SIO_none;

      ndx = n->succ[j];
      ++str;
      --len;
    }
  return SIO_none;
}

/*
 * Structure to associate a spec_mask representing all conversion specifiers
 * seen for a smart-io/stdio function, as well as the associated bfd hash
 * entry. A NULL entry for hlist.h indicates the function was not found.
 */
// TODO: to be refactored to use a std::vector
typedef struct bfd_entry_list_
{
  struct bfd_link_hash_entry *h;
  struct bfd_entry_list_ *next;
  smartio_func_index index;
} bfd_entry_list;

typedef struct smartio_spec_info_
{
  bfd_entry_list hlist;
  spec_mask mask;
} smartio_spec_info;

/*
 * Contains all information on smart-io/stdio functions seen.
 * Initialized by smartio_add_symbols, then used by smartio_merge_symbols
 * after all files loaded to do merging.
 */
static smartio_spec_info spec_info[SIO_NUM_KINDS];

/*
 * Initialize a spec_info entry.
 */
#define SPEC_INFO_INIT(si)                                                    \
  do                                                                          \
    {                                                                         \
      (si).hlist.h = NULL;                                                    \
      (si).hlist.next = NULL;                                                 \
      (si).mask = 0;                                                          \
    }                                                                         \
  while (0)

/*
 * Free a bfd_entry_list.
 */
static void
entry_list_free (smartio_spec_info *info)
{
  bfd_entry_list *p, *next;
  for (p = info->hlist.next; p; p = next)
    {
      next = p->next;
      free (p);
    }
  info->hlist.next = NULL;
  info->hlist.h = NULL;
}

/*
 * Add a hash link entry to the end of the given entry list.
 */
static void
entry_list_add (struct bfd_link_hash_entry *h, smartio_func_index n,
                smartio_spec_info *info)
{
  bfd_entry_list *p = NULL;

  if (info->hlist.h == NULL)
    {
      info->hlist.h = h;
      info->hlist.index = n;
      info->hlist.next = NULL;
      return;
    }

  /* Insert at start */
  p = xmalloc (sizeof (bfd_entry_list));
  p->h = info->hlist.h;
  p->next = info->hlist.next;
  p->index = info->hlist.index;
  info->hlist.h = h;
  info->hlist.index = n;
  info->hlist.next = p;
}

static unsigned
force_keep_symbol (char *symbol, char *module_name ATTRIBUTE_UNUSED)
{
  smartio_func_index index = smartio_match_sym (symbol);

  bfd_entry_list *p = &spec_info[smartio_funcs[index].kind].hlist;
  while (p != NULL)
    {
      if (p->index == index && p->h != NULL)
        return 1;
      p = p->next;
    }
  return 0;
}

/*
** Undefine one symbol by BFD
**
** This routine is called by bfd_link_hash_traverse()
*/
static bfd_boolean
bfd_pic32_undefine_one_symbol_bfd (struct bfd_link_hash_entry *h, PTR p)
{
  struct bfd_link_hash_entry *H = (struct bfd_link_hash_entry *)h;
  struct traverse_hash_info *hinfo = (struct traverse_hash_info *)p;

  /* if this symbol is defined, and owned by the BFD in question */
  if (((H->type == bfd_link_hash_defined)
       || (H->type == bfd_link_hash_defweak))
      && (H->u.def.section->owner == hinfo->abfd))

    /* mark it undefined */
    H->type = bfd_link_hash_undefined;

  /* traverse the entire hash table */
  return TRUE;
}

/*
** Undefine all symbols owned by a bfd
*/
static void
bfd_pic32_undefine_symbols_bfd (bfd *target)
{
  struct traverse_hash_info hinfo;
  hinfo.abfd = target;

  /* traverse the global linker hash table */
  bfd_link_hash_traverse (link_info.hash, bfd_pic32_undefine_one_symbol_bfd,
                          &hinfo);
}

/*
** Remove an archive module
*/
static void
bfd_mchp_remove_archive_module (const char *const name)
{
  LANG_FOR_EACH_INPUT_STATEMENT (is)
  {
    if (strcmp (is->the_bfd->filename, name) == 0)
      {
        /*
        ** remove the symbols
        */
        bfd_pic32_undefine_symbols_bfd (is->the_bfd);
        is->the_bfd->symcount = 0;

        /*
        ** remove the sections in this bfd
        */
        bfd_section_list_clear (is->the_bfd);
        break;
      }
  }
}

/*
 * Attempt to match the given symbol to a smart-io/stdio function.
 * info is assumed to be an array of smartio_spec_info indexed by
 * smartio_func_index values.
 */
static bfd_boolean
smartio_match (struct bfd_link_hash_entry *h, void *info)
{
  smartio_spec_info *sinfo = (smartio_spec_info *)info;
  const char *name = h->root.string;

  smartio_func_index index = smartio_match_sym (name);

  if (index != SIO_none)
    {
      /* have a match, check for suffix information  */
      long len = strlen (name);
      spec_mask mask = 0;
      smartio_func_kind kind = smartio_funcs[index].kind;

      DEBUG_SMARTIO ("[SIO] match %s -- got index %d\n", name, index);

      if (len >= 1 && name[0] == '_')
        {
          /* search back from end until '_' starting the suffix */
          const char *p = name + len - 1;

          while (*p != '_')
            {
              char c = *p;

              /* hack: some chars need remapping as they
                 don't appear in smartio suffices but are included by gcc. */
              if (c == 'i')
                c = 'd';

              c = sio_map_char (c);

              /* check for an invalid suffix - bail out if so. this handily
                 excludes _r forms posing as smart-io functions. */
              if (!(valid_suffixes & sio_suffix_bit (c)))
                return TRUE;

              mask |= sio_suffix_bit (c);
              --p;
            }
/*
  XC32-2366
    Make sure that we do not break the backward compatibility for MIPS arch
    (where - prior to v4.30 release - smartIO symbols with a single underscore
    prefix were generated by the mips compiler)
*/
#if defined(TARGET_IS_PIC32C)
          /* Only match suffix forms with double underscore prefix. */
          if (len >= 2 && name[1] != '_')
            return TRUE;
#endif
        }
      else
        mask = -1;

      entry_list_add (h, index, &(sinfo[kind]));
      sinfo[kind].mask |= mask;

      DEBUG_SMARTIO ("[SIO] mask %08x cumulative %08x\n", mask,
                     sinfo[kind].mask);
    }

  return TRUE; /* continue traversal of hash */
}

/*
 * Given a symbol to resolve all smart-io variants of a stdio function to,
 * release all variants which differ from the symbol, as these were
 * preemptively kept due to force_keep_symbol.
 */
static void
mchp_release_kept_symbols (char *symbol, const smartio_spec_info *info)
{
  /* Traverse the variant list getting module info from the bfd link entry. */
  const bfd_entry_list *p;
  long len = strlen (symbol);

  DEBUG_SMARTIO ("[SIO] release_kept_symbols(%s)\n", symbol);

  for (p = &(info->hlist); p; p = p->next)
    {
      if (strncmp (p->h->root.string, symbol, len) != 0)
        {
          if (p->h->type == bfd_link_hash_defined)
            {
              const char *module = p->h->u.undef.abfd->filename;

              /* SIO_TODO: is it really safe to assume the whole module can be
                 punted? */
              DEBUG_SMARTIO ("[SIO] found %s (undef) in module %s\n",
                             p->h->root.string, module);
              bfd_mchp_remove_archive_module (module);
            }
        }
    }
}

/*
 * Identify smart-io/stdio symbols and add to undefined list.
 * Initializes/uses spec_info.
 */
static void
smartio_add_symbols (struct bfd_link_info *sec_info)
{
  struct bfd_link_hash_entry *undefs = NULL;
  long i;
  const smartio_suffix *suffix_info = get_suffix_info ();

  /* Initialize the info table. */
  for (i = 0; i != SIO_NUM_KINDS; ++i)
    SPEC_INFO_INIT (spec_info[i]);

  ASSERT (sec_info);
  undefs = sec_info->hash->undefs;

  DEBUG_SMARTIO ("[SIO] smartio_add_symbols\n");

  /* Traverse the undefined list collecting info. */
  struct bfd_link_hash_entry *u;
  for (u = undefs; u; u = u->u.undef.next)
    smartio_match (u, spec_info);

  /* For each function kind, find the covering suffix and add to undefined list
     so the usual mechanism can pull them in. */
  for (i = 0; i < SIO_NUM_KINDS; ++i)
    {
      bfd_entry_list *hlist = &spec_info[i].hlist;
      long index = -1; /* smartio suffix index, -ve value indicates none. */
      long use_smartio = 0;
      char buf[64] = "";

      if (!spec_info[i].hlist.h)
        continue;

      DEBUG_SMARTIO ("[SIO] process func %ld (%s) mask=%08x\n", i,
                     spec_info[i].hlist.h->root.string, spec_info[i].mask);

      if (spec_info[i].mask != (spec_mask)-1)
        {
          /* We have one or more smart-io candidates */
          long j;
          for (j = num_suffixes - 1; j >= 0; --j)
            {
              if ((spec_info[i].mask & ~(suffix_info[j].mask)) == 0)
                {
                  index = j;
                  break;
                }
            }
        }

      if (spec_info[i].mask == (spec_mask)-1 || index < 0)
        {
          /* We have an instance of the 'complete' stdio function, or
             no smart-io function to handle all candidates. */
          DEBUG_SMARTIO ("[SIO] no cover, using vanilla function\n");
        }
      else
        {
          /* We have a suitable smartio function to cover all smartio calls. */
          use_smartio = 1;
          DEBUG_SMARTIO ("[SIO] found cover with mask %08x (%s)\n",
                         suffix_info[index].mask, buf);
        }

      while (hlist != NULL)
        {
          /* xc32-981 - we must also do a lookup for user-defined equivalents
             and faithfully use them. */
          long user_defined = 0;
          struct bfd_link_hash_entry *hf = bfd_link_hash_lookup (
              sec_info->hash, smartio_funcs[hlist->index].name, 0, 0, 0);

          if (hf && (hf->type == bfd_link_hash_defined))
            {
              user_defined = 1;
              DEBUG_SMARTIO ("[SIO] using user-defined %s for %s\n",
                             smartio_funcs[hlist->index].name,
                             hlist->h->root.string);
            }

          if (use_smartio && !user_defined)
            sprintf (buf, "_%s_%s", smartio_funcs[hlist->index].name,
                     suffix_info[index].suffix);
          else
            sprintf (buf, "%s", smartio_funcs[hlist->index].name);

          DEBUG_SMARTIO ("[SIO] adding cover function %s for %s\n", buf,
                         hlist->h->root.string);

          struct bfd_link_hash_entry *h
              = bfd_link_hash_lookup (sec_info->hash, buf, 0, 0, 0);

          if (!h)
            {
              struct bfd_link_hash_entry *new;

              DEBUG_SMARTIO ("[SIO] adding undefined symbol %s\n", buf);

              new = bfd_link_hash_lookup (sec_info->hash, buf, 1, 1, 1);
              new->type = bfd_link_hash_undefined;
              bfd_link_add_undef (sec_info->hash, new);
              entry_list_add (new, hlist->index, &(spec_info[i]));
            }

          hlist = hlist->next;
        }
    }
}

/*
 * Perform merging of smart-io/stdio symbols.
 */
void
smartio_merge_symbols (void)
{
  long i;
  const smartio_suffix *suffix_info = get_suffix_info ();

  DEBUG_SMARTIO ("[SIO] smartio_merge_symbols\n");

  for (i = 0; i != SIO_NUM_KINDS; ++i)
    {
      bfd_entry_list *hlist = &spec_info[i].hlist;
      long index = -1; /* smartio suffix index, -ve value indicates none. */
      long use_smartio = 0;
      char buf[256] = "";

      if (!spec_info[i].hlist.h)
        continue;

      DEBUG_SMARTIO ("[SIO] process func %ld (%s) mask=%08x\n", i,
                     spec_info[i].hlist.h->root.string, spec_info[i].mask);

      if (spec_info[i].mask != (spec_mask)-1)
        {
          /* We have one or more smart-io candidates */
          long j;
          for (j = num_suffixes - 1; j >= 0; --j)
            {
              if ((spec_info[i].mask & ~(suffix_info[j].mask)) == 0)
                {
                  index = j;
                  break;
                }
            }
        }

      if (spec_info[i].mask == (spec_mask)-1 || index < 0)
        {
          /* We have an instance of the 'complete' stdio function, or
             no smart-io function to handle all candidates. */
          DEBUG_SMARTIO ("[SIO] no cover, using complete function\n");
        }
      else
        {
          /* We have a suitable smartio function to cover all smartio calls. */
          use_smartio = 1;
          DEBUG_SMARTIO ("[SIO] found cover with mask %08x (%s)\n",
                         suffix_info[index].mask, buf);
        }

      while (hlist)
        {
          if (use_smartio)
            sprintf (buf, "_%s_%s", smartio_funcs[hlist->index].name,
                     suffix_info[index].suffix);
          else
            sprintf (buf, "%s", smartio_funcs[hlist->index].name);

          DEBUG_SMARTIO ("[SIO] merging with function %s\n", buf);

          /* remap all calls to the covering symbol and discard unused syms. */
          struct bfd_link_hash_entry *h
              = bfd_link_hash_lookup (link_info.hash, buf, FALSE, FALSE, TRUE);

          /* XC32-981 - if the covering symbol is not defined, we chose
             not to add it in smartio_add_symbols. so complete the handshake
             and fall back to the plain symbol. */
          if (!h
              || !(h->type == bfd_link_hash_defined
                   || h->type == bfd_link_hash_defweak))
            {
              DEBUG_SMARTIO (
                  "[SIO] covering symbol not found, using vanilla function\n");

              /* XC32-1138 the lookup for the vanilla function now sets the
                 'create' flag so that we can proceed with an undefined
                 reference. */
              h = bfd_link_hash_lookup (link_info.hash,
                                        smartio_funcs[hlist->index].name, TRUE,
                                        FALSE, TRUE);
            }
          /* NB: if the covering symbol was not found, h should point to a
             valid hash entry (possibly undefined) for the vanilla function. */
          ASSERT (h);

          if (hlist->h->type == bfd_link_hash_undefined
              || hlist->h->type == bfd_link_hash_undefweak)
            {
              DEBUG_SMARTIO ("[SIO] merging %s into symbol %s\n",
                             hlist->h->root.string, buf);

              struct elf_link_hash_entry *from
                  = (struct elf_link_hash_entry *)hlist->h;

              from->root.type = bfd_link_hash_indirect;
              from->root.u.i.link = h;
              su_note_smartio_replacement (hlist->h->root.string, buf);
            }

          hlist = hlist->next;
        }

      mchp_release_kept_symbols (buf, &(spec_info[i]));
      entry_list_free (&(spec_info[i]));
    }
  /* SIO_TODO: repair undef list here? */
}

unsigned (*mchp_force_keep_symbol) (char *, char *) = force_keep_symbol;
void (*mchp_smartio_add_symbols) (struct bfd_link_info *)
    = smartio_add_symbols;

