/* Code common to pic32m and pic32c for the stack usage feature.

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
#include "demangle.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "bfdlink.h"
#include "ld.h"
#include "ldexp.h"
#include "ldmain.h"
#include "ldlang.h"

#include <stdint.h>
#include <limits.h>

#include "pic32-vecset.h"
#if defined(TARGET_IS_PIC32C)
#include "elf/pic32.h"
#include "pic32c-emul.h"
#endif
#if defined(TARGET_IS_PIC32MX)
#include "pic32m-emul.h"
#endif
#include "pic32-stack-usage.h"
#include "mchp/pic32-su-common.h"

extern bfd_boolean pic32_debug;
extern bfd_boolean pic32_smart_io;

su_callstack *crt_callstack;    /* current call stack */

static const char *su_get_smartio_replacement (const char *);
/* TODO: This comes from pic32-stack-usage.c which is in the BFD code
   and doesn't have a header. */
void pic32_su_add_to_call_graph (bfd *, const char *, bfd_vma,
				 bfd *, const char *, bfd_vma);

/*
* Stack Usage Estimation
* 	check if r_type corresponds to a call semantic
*/
bfd_boolean is_call_reloc (unsigned int r_type);

/*
* Stack Usage Estimation
* 	find the application starting point
* 	in the stack usage list
*/
static struct su_section *
pic32_su_get_entry_point (void)
{
  struct bfd_link_hash_entry *h = NULL;

  ///\ get entry point -> Root function in call graph
 #ifdef TARGET_IS_PIC32C
  if (params.thumb_entry_symbol)
  {
    h = bfd_link_hash_lookup (link_info.hash, params.thumb_entry_symbol,
                              FALSE, FALSE, TRUE);
  }
  else
#endif
  if (entry_symbol.name != NULL)
    h = bfd_link_hash_lookup (link_info.hash, entry_symbol.name, FALSE, FALSE, TRUE);

  if (h == NULL)
    return NULL;

  return get_function_by_name_bfd (h->root.string, h->u.def.section->owner);
}

static bfd_boolean
pic32_is_PAed_function (struct su_section *node)
{
  static const char pa_fn_prefix[] = "__pa_fn_";
  return pic32_pa_enabled ()
           && !strncmp (node->fname, pa_fn_prefix, sizeof (pa_fn_prefix) - 1);
}

/*
* Stack Usage Estimation
* 	compute maximum stack usage starting from root node
*   return the max stack on the subgraph root
*   set the max_stack field for all visited nodes
*/
static uint32_t
pic32_su_max_stack (struct su_section *root)
{
  struct su_section *node;
  uint32_t index;
  uint32_t node_max = 0, tmp;
  bfd_boolean has_PAed_callees = FALSE;

  PIC32_DBG_PRINT ("pic32_su_max_stack(%s), used_stack: %u", root->fname,
                   root->used_stack);
  PIC32_DBG_PRINT (", callees: { ");
  for (index = 0; index < root->nb_callees; index++)
    PIC32_DBG_PRINT ("%s ", root->callees[index]->fname);
  PIC32_DBG_PRINT ("}\n");

  /* is it leaf function */
  if (root->callees == NULL)
    {
      return root->max_stack = root->used_stack;
    }

  /* check recursivity */
  if (root->flags & SU_PROCESSED_NODE)
    {
      /* mark recursive functions */
      mark_as_recursive (crt_callstack, root);

      /* recursivity detected */
      PIC32_DBG_PRINT ("Recursivity! Starting function: %s\n", root->fname);

      /* temporarily return the stack usage of the root function */
      return root->used_stack;
    }

  /* if the max stack usage was computed for this subgraph */
  if (root->max_stack != UINT_MAX)
    {
      return root->max_stack;
    }

  /* set SU_PROCESSED_NODE flag - processing */
  root->flags |= SU_PROCESSED_NODE;
  /* add current node in the crt callstack */
  su_cstack_push (crt_callstack, root);

  /* DFS, keeping the stack of current path */
  for (index = 0; index < root->nb_callees; index++)
    {
      node = root->callees[index];
      tmp = pic32_su_max_stack (node);
      if (tmp > node_max)
        node_max = tmp;

      /* make a note if we find any PAed callees */
      if (pic32_is_PAed_function (node))
        has_PAed_callees = TRUE;
    }

  /* the node processing finished, reset the flag */
  root->flags &= ~SU_PROCESSED_NODE;
  su_cstack_pop (crt_callstack);

  /* XC32-1683: as the PA tool is not producing any SU info at the moment,
   * conservatively assume that a call to a PAed callee uses 8 bytes of stack
   * memory (for pushing a register and keeping SP aligned to 8-bytes) */
  if (has_PAed_callees && node_max < 8)
    node_max = 8;

  root->max_stack = node_max + root->used_stack;

  return root->max_stack;
}

/* a section and its function symbols */
typedef struct {
  asection *section;
  vec_type *func_syms;
} sec_funcs;

/* adds the function symbol into the 'func_syms' vector while keeping it
 * ordered by the function addresses; multiple functions at the same address
 * are allowed (any such entries are stored in the order of appearance);
 * XC32-1631: keep a single entry in case of exact overlaps & rely on aliasing info */
void
pic32_su_add_func (vec_type         *func_syms,
                   Elf_Internal_Sym *isym)
{
  int idx = 0;
  while (idx != (int) VEC_SIZE (func_syms)
         && ST_VALUE2 (VEC (Elf_Internal_Sym*, func_syms, idx)) <= ST_VALUE2 (isym))
    ++idx;

  /* XC32-1631: add the new symbol only if a different address and/or size */
  if (!idx
      || ST_VALUE2 (VEC (Elf_Internal_Sym*, func_syms, idx - 1)) != ST_VALUE2 (isym)
      || (VEC (Elf_Internal_Sym*, func_syms, idx - 1))->st_size  != isym->st_size)
    VEC_INSERT (Elf_Internal_Sym *, func_syms, idx, isym);
}

/* returns the index of the first function (symbol) containing the specified
 * address (*MATCH is set to 1 in this case) or the index of the next func symbol /
 * the end of the function collection (*MATCH is set to 0 in this case) */
int
pic32_su_lookup_func (vec_type *func_syms,
                      int      from_idx,
                      bfd_vma  vma,
                      int      *match /*out*/)
{
  int idx = from_idx;
  while (idx != (int) VEC_SIZE (func_syms))
    {
      Elf_Internal_Sym *isym = VEC (Elf_Internal_Sym*, func_syms, idx);
      if (vma < ST_VALUE2 (isym) + isym->st_size)
        break;
      ++idx;
    }
  *match =
    idx != (int) VEC_SIZE (func_syms)
      && vma >= ST_VALUE2 (VEC (Elf_Internal_Sym *, func_syms, idx));
  return idx;
}

/* returns the functions (ordered by start addr) for the specified section */
static vec_type *
pic32_su_lookup_func_syms (vec_type *bfd_funcs,
                           asection *section)
{
  int i;
  for (i = 0; i != (int) VEC_SIZE (bfd_funcs); ++i)
    {
      sec_funcs *sf = &VEC (sec_funcs, bfd_funcs, i);
      if (sf->section == section)
        return sf->func_syms;
    }
  return NULL;
}

/*
 * returns a vector of sec_funcs structures i.e. all the function symbols
 * from the input bfd grouped per section
 */
static vec_type *
pic32_su_get_bfd_funcs (bfd              *input_bfd,
                        Elf_Internal_Sym *isymbuf)
{
  Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (input_bfd);
  size_t symcount = symtab_hdr->sh_size / sizeof (Elf32_External_Sym);
  vec_type *bfd_funcs = VEC_NEW (sec_funcs, 0, 0);
  Elf_Internal_Sym *isym, *isymend;

  for (isym = isymbuf + 1, isymend = isymbuf + symcount; isym < isymend; ++isym)
    {
      if (ELF_ST_TYPE (isym->st_info) == STT_FUNC)
        {
          if (pic32_debug)
            {
              const char *func_name = bfd_elf_sym_name (input_bfd, symtab_hdr,
                                                        isym, NULL);
              PIC32_DBG_PRINT ("\tfunction: %s [size: 0x%0" BFD_VMA_FMT "X]%s\n",
			       func_name, isym->st_size,
			       (!isym->st_size ? "\t***** WARNING *****" : ""));
            }
          if (isym->st_size != 0)
            {
              asection *section = bfd_section_from_elf_index (input_bfd, isym->st_shndx);
              vec_type *func_syms = pic32_su_lookup_func_syms (bfd_funcs, section);
              if (!func_syms)
                {
                  sec_funcs tmp = { section, VEC_NEW (Elf_Internal_Sym *, 0, 0) };
                  VEC_PUSHBACK (sec_funcs, bfd_funcs, tmp);
                  func_syms = tmp.func_syms;
                }
              pic32_su_add_func (func_syms, isym);
            }
        }
    }

  return bfd_funcs;
}

/* free the memory used by the 'bfd_funcs' vector */
static void
pic32_su_free_bfd_funcs (vec_type *bfd_funcs)
{
  int i;
  for (i = 0; i != (int) VEC_SIZE (bfd_funcs); ++i)
    VEC_DELETE (VEC (sec_funcs, bfd_funcs, i).func_syms);
  VEC_DELETE (bfd_funcs);
}

struct su_name_addr {
  const char *name;
  bfd_vma    addr;

  /* these are used for caching purposes & should be inited to NULL */
  /* (the BFD is assumed to be the same) */
  asection    *section;
  bfd_vma     section_ofs;
  vec_type    *func_syms;
  int         func_idx;
  bfd_boolean first;
};

/*
 * returns TRUE (and fills 'name_addr') if it finds a function in
 * 'input_bfd' and 'section' that contains the 'section_ofs' location;
 * 'first' == TRUE means getting the first function spanning the location,
 * 'first' == FALSE, the subsequent ones, if available
 * returns FALSE if no (more) match(es) is/are found
 *
 */
static int
pic32_su_get_func_name_addr (struct su_name_addr *name_addr,
                             bfd                 *input_bfd,
                             vec_type            *bfd_funcs,
                             asection            *section,
                             bfd_vma             section_ofs,
                             bfd_boolean         first)
{
  vec_type *func_syms = FALSE;
  int func_idx = 0, found = FALSE;

  /* looking for the first symbol matching (section, section_ofs) */
  if (first)
    {
      /* if the previous search was identical, we already have the name/addr */
      if (name_addr->first
          && section == name_addr->section
          && section_ofs == name_addr->section_ofs)
        return TRUE;

      /* ok, need to search; */
      /* the first step is to find the func_syms for this section */
      func_syms = (section == name_addr->section)
                     ? name_addr->func_syms
                     : pic32_su_lookup_func_syms (bfd_funcs, section);
      if (func_syms)
        func_idx = pic32_su_lookup_func (func_syms, 0, section_ofs, &found);
    }
  else
    {
      /* looking for the next symbols matching the same (section, section_ofs) */
      /* so assert there was a previous match */
      BFD_ASSERT (section == name_addr->section
                  && section_ofs == name_addr->section_ofs
                  && name_addr->func_syms);

      func_syms = name_addr->func_syms;
      func_idx = pic32_su_lookup_func (func_syms,
                                       name_addr->func_idx + 1,
                                       section_ofs, &found);
    }

  if (found)
    {
      Elf_Internal_Sym *isym = VEC (Elf_Internal_Sym *, func_syms, func_idx);
      name_addr->name = bfd_elf_sym_name (input_bfd, &elf_symtab_hdr (input_bfd),
                                          isym, NULL);
      name_addr->addr = section->output_section->vma
                          + section->output_offset + ST_VALUE2 (isym);
      if (first)
        {
          name_addr->section = section;
          name_addr->section_ofs = section_ofs;
          name_addr->func_syms = func_syms;
        }
      name_addr->func_idx = func_idx;
      name_addr->first = first;
      return TRUE;
    }

  return FALSE;
}

/*
 * ensures that no su_sections from 'input_bfd' remain without addresses
 * (for the case when we'll need to dump the func addresses to the map file)
 */
static void
pic32_fill_su_section_addrs (bfd              *input_bfd,
                             Elf_Internal_Sym *isymbuf)
{
  Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (input_bfd);
  size_t symcount = symtab_hdr->sh_size / sizeof (Elf32_External_Sym);
  Elf_Internal_Sym *isym, *isymend;

  for (isym = isymbuf + 1, isymend = isymbuf + symcount; isym < isymend; ++isym)
    {
      if (ELF_ST_TYPE (isym->st_info) == STT_FUNC)
        {
          asection *section = bfd_section_from_elf_index (input_bfd, isym->st_shndx);
          if (section->output_section)
            {
              const char *fname = bfd_elf_sym_name (input_bfd, symtab_hdr, isym, NULL);
              struct su_section *node = get_function_by_name_bfd (fname, input_bfd);
              if (node && !node->faddr)
                {
                  node->faddr = section->output_section->vma
                                  + section->output_offset + ST_VALUE2 (isym);
                }
            }
        }
    }
}

/*
* Stack Usage Estimation
* 	build the pseudo call-graph based on the relocation tables
*
* (Note: return value is meaningless, but because the
* RELOC_FOR_GLOBAL_SYMBOL macro can return FALSE, it returns a value.)
*/
static int
pic32_su_call_tree (void)
{
  bfd *input_bfd;

  /* XC32-1656: keep this handy so that when encountering an .init_array /
   *            .preinit_array section we can automatically add the
   *            functions referenced there as its callees */
  struct su_section *ctors_caller =
#ifdef TARGET_IS_PIC32C
    get_function_by_name_bfd ("__libc_init_array", NULL);
#else
    get_function_by_name_bfd ("__do_global_ctors_aux", NULL);
#endif

  for (input_bfd = link_info.input_bfds; input_bfd != NULL;
       input_bfd = input_bfd->link.next)
    {
      Elf_Internal_Shdr *symtab_hdr = &elf_symtab_hdr (input_bfd);
      struct elf_link_hash_entry **sym_hashes = elf_sym_hashes (input_bfd);
      Elf_Internal_Sym *isymbuf = NULL;
      vec_type *bfd_funcs = NULL;
      asection *section;

      PIC32_DBG_PRINT ("\ninput_bfd: %s\n", input_bfd->filename);

      /* read all symbols (local + global) for the current bfd */
      isymbuf =
        bfd_elf_get_elf_syms (input_bfd, symtab_hdr,
                              symtab_hdr->sh_size / sizeof (Elf32_External_Sym),
                              0, NULL, NULL, NULL);
      /* no symbols => no callers => don't bother */
      if (!isymbuf)
        continue;

      /* cache the function symbols for (all the sections of) this bfd */
      bfd_funcs = pic32_su_get_bfd_funcs (input_bfd, isymbuf);

      /* check all sections */
      for (section = input_bfd->sections; section != NULL; section = section->next)
        {
          const bfd_boolean ctors_section = ctors_caller && !(
#ifdef TARGET_IS_PIC32C
            strcmp (section->name, ".init_array")
              && strcmp (section->name, ".preinit_array")
#else
            strcmp (section->name, ".ctors")
#endif
          );
          struct su_name_addr caller = { NULL }, callee = { NULL };
          Elf_Internal_Rela *internal_relocs, *irelaend, *irela;
          vec_type *func_syms;

          PIC32_DBG_PRINT ("\tsection: %s [size: 0x%0" BFD_VMA_FMT "X]\n",
			   section->name, section->size);

          /* regular code sections (i.e. not arrays of pointers to functions) */
          if (!ctors_section)
            {
              /* check only code sections */
              if (!(section->flags & SEC_CODE))
                continue;

              /* we should also have some function symbols for this section */
              func_syms = pic32_su_lookup_func_syms (bfd_funcs, section);
              if (!func_syms)
                continue;
            }

          /* this discarded section test is taken from lang_map () in ldlang.c */
          if ((section->output_section == NULL
                || section->output_section->owner != link_info.output_bfd)
                && (section->flags & (SEC_LINKER_CREATED | SEC_KEEP)) == 0)
            {
              int idx;

              /* mark all the su_sections from this section as discarded */
              PIC32_DBG_PRINT ("\t  discarded section; unused function(s):");
              for (idx = 0; idx != (int) VEC_SIZE (func_syms); ++idx)
                {
                  Elf_Internal_Sym *isym = VEC (Elf_Internal_Sym*, func_syms, idx);
                  const char *func_name =
                    bfd_elf_sym_name (input_bfd, symtab_hdr, isym, NULL);
                  struct su_section *su_info =
                    get_function_by_name_bfd (func_name, input_bfd);

                  if (su_info)
                    su_info->flags |= SU_DISCARDED_NODE;

                  PIC32_DBG_PRINT (" %s\n", func_name);
                }
              PIC32_DBG_PRINT ("\n");

              /* ...and that's all the processing for these sections */
              continue;
            }

          /* NOTE: always pass 'keep_memory' as TRUE because otherwise we
           *       may need to check and free() the returned buffer */
          internal_relocs =
            _bfd_elf_link_read_relocs (input_bfd, section, NULL, NULL,
                                       TRUE /*link_info.keep_memory*/);
#ifdef TARGET_IS_PIC32C
          /* no point in looking for calls in an .init_array section */
          if (!ctors_section)
            pic32c_su_calls_wo_relocs_in_section (input_bfd, symtab_hdr, section,
                                                  internal_relocs, isymbuf, func_syms);
#endif
          if (internal_relocs == NULL)
            continue;

          /* Now examine each relocation.  */
          irela = internal_relocs;
          irelaend = irela + section->reloc_count;
          for (; irela < irelaend; irela++)
            {
              asection *callee_sec;
              unsigned int r_type, r_indx;

              r_type = ELF32_R_TYPE (irela->r_info);
              r_indx = ELF32_R_SYM (irela->r_info);

              if (!(is_call_reloc (r_type) || ctors_section))
                continue;

              /* relocation against a global symbol? */
              if (r_indx >= symtab_hdr->sh_info)
                {
                  struct elf_link_hash_entry *hash_entry = NULL;
                  bfd_boolean unresolved_reloc = FALSE;
                  __attribute__((unused)) bfd_vma relocation;
                  __attribute__((unused)) bfd_boolean warned, ignored;

                  RELOC_FOR_GLOBAL_SYMBOL ((&link_info), input_bfd, section, irela,
                                           r_indx, symtab_hdr, sym_hashes,
                                           hash_entry, callee_sec, relocation,
                                           unresolved_reloc, warned, ignored);

                  /* basically ignore the non-function symbols (although there
                   * are some functions symbols in the math library (libm)
                   * marked as STT_OBJECT, so allow that type as well) */
                  if (unresolved_reloc
                      || !(callee_sec->flags & SEC_CODE)
                      || (hash_entry->type != STT_FUNC
                          && hash_entry->type != STT_OBJECT))
                    continue;

                  if ((hash_entry->root.type != bfd_link_hash_defined) &&
                      (hash_entry->root.type != bfd_link_hash_defweak))
                    continue;

                  BFD_ASSERT (callee_sec);

                  callee.name = hash_entry->root.root.string;
                  if (pic32_smart_io)
                    callee.name = su_get_smartio_replacement (callee.name);
                  callee.addr = hash_entry->root.u.def.section->vma
                                  + hash_entry->root.u.def.value;
                }
              else
                {
                  /* relocation against a local symbol */
                  Elf_Internal_Sym *isym = isymbuf + r_indx;
                  bfd_vma sec_ofs = ST_VALUE2 (isym)
                                      + pic32_su_rel_addend (input_bfd, section,
                                                             irela, isym);
                  callee_sec = bfd_section_from_elf_index (input_bfd, isym->st_shndx);

                  BFD_ASSERT (callee_sec);

                  if (!(callee_sec->flags & SEC_CODE))
                    continue;

                  if (!pic32_su_get_func_name_addr (&callee, input_bfd, bfd_funcs,
                                                    callee_sec, sec_ofs, TRUE))
                    {
                      PIC32_DBG_PRINT ("No function found in section %s @ ofs %"
				       BFD_VMA_FMT "u\n", callee_sec->name, sec_ofs);
                      continue;
                    }

                  /* ignore the "calls" that don't correspond precisely to the
                   * beginning of a function; most likely these are just jumps
                   * (esp. on MIPS) but (without this check) they're seen as
                   * recursive calls! */
                  if (ST_VALUE2 (VEC (Elf_Internal_Sym *,
                      callee.func_syms, callee.func_idx)) != sec_ofs)
                    continue;
                }

              /* XC32-1656: the caller of the functions from .init_array
               *            is assumed to be the __libc_init_array function */
              if (ctors_section)
                {
                  pic32_su_add_to_call_graph (ctors_caller->the_bfd,
                                              ctors_caller->fname,
                                              ctors_caller->faddr,
                                              callee_sec->owner, callee.name,
                                              callee.addr);
                  continue;
                }

              /* XC32-1638: calling pic32_su_get_func_name_addr () in a loop
               *            will iterate any overlapped callers */
              if (pic32_su_get_func_name_addr (&caller, input_bfd,
                                               bfd_funcs, section,
                                               irela->r_offset, TRUE))
                {
                  do
                    {
                      PIC32_DBG_PRINT ("\t\t[reloc-based] %s calls %s\n",
                                      caller.name, callee.name);

                      pic32_su_add_to_call_graph (input_bfd, caller.name,
                                                  caller.addr, callee_sec->owner,
                                                  callee.name, callee.addr);
                    }
                  while (pic32_su_get_func_name_addr (&caller, input_bfd,
                                                      bfd_funcs, section,
                                                      irela->r_offset, FALSE));
                }
              else
                {
                  PIC32_DBG_PRINT ("No function found in section %s @ ofs %"
				   BFD_VMA_FMT "u\n", section->name, irela->r_offset);
                }
            }
        }

      /* complete the function addresses left unset
       * by the pic32_su_add_to_call_graph () calls */
      pic32_fill_su_section_addrs (input_bfd, isymbuf);

      pic32_su_free_bfd_funcs (bfd_funcs);
      free (isymbuf);
    }

#ifdef TARGET_IS_PIC32MX
  /* for PIC32M, __do_global_ctors_aux () is called from _init () but...
   * we don't see that call here b/c the '_init' symbol has a size of 0 and
   * there's no way we can set it a proper size during the XC32 build as that
   * size is the result of concatenating the .init sections contents from
   * crti.o, an arbitrary number of user objs and crtn.o
   * so maybe we could look at the size of the .init output section?
   * anyway, an easier hack would be to just add __do_global_ctors_aux()
   * as a callee of _init () - which we do below... */
  if (ctors_caller)
    {
      struct su_section *_init = get_function_by_name_bfd ("_init", NULL);
      if (_init)
        pic32_su_add_to_call_graph (_init->the_bfd, _init->fname, _init->faddr,
                                    ctors_caller->the_bfd, ctors_caller->fname,
                                    ctors_caller->faddr);
    }
#endif
  return 1;
}

struct su_caller_list {
  struct su_section     *node;
  struct su_caller_list *prev, *next;
};

static void
pic32_dump_call_subgraph_1 (struct su_caller_list *caller_list)
{
  static const int SU_INFO_COL = 120;  /* dump SU info @ the same column, if possible */
  static const char *PREFIXES[][2] = {
#ifndef __MINGW32__
    { "│  ", "   " }, { "├──", "└──" } /* similar to `tree`'s output (UTF-8 encoding) */
#else
    { "|  ", "   " }, { "|--", "\\--" }/* but of course it doesn't work on Windows */
#endif                                 /* so use alternate ASCII chars */
  };

  struct su_section *node = caller_list->node;
  struct su_caller_list *root = caller_list;
  int len = 0, to_align, idx;
  char *demangled_name = NULL;

  /* 'caller_list' has at least a caller-callee pair */
  if (root->prev)
    {
      /* 'unwind' the caller list to process it from the root node/topmost caller */
      do
        root = root->prev;
      while (root->prev);

      /* for each caller-callee pair */
      /* (the last 'caller' in the list has no callees) */
      while (root->next)
        {
          struct su_section *caller = root->node, *callee = root->next->node;

          const int last_caller_callee = callee == caller->callees[caller->nb_callees - 1];
          const int last_callee_in_list = root->next->next == NULL;

          const char *prefix = PREFIXES[last_callee_in_list][last_caller_callee];

          PIC32_DBG_PRINT ("%s ", prefix);
          len += 4; /* hardcoded b/c the UTF-8 chars are seen as multiple chars */
          root = root->next;
        }
    }

  demangled_name = bfd_demangle (link_info.output_bfd, node->fname,
                                 DMGL_ANSI | DMGL_PARAMS);

  /* if available, use the demangled name, but not if it is very long */
  len += PIC32_DBG_PRINT ("%s", (demangled_name
                                   && len + (int) strlen (demangled_name) <= SU_INFO_COL)
                                 ? demangled_name : node->fname);
  free (demangled_name);

  to_align = SU_INFO_COL - len;
  if (to_align > 0)
    PIC32_DBG_PRINT ("%*s", to_align, "");

  /* print the stack usages and a '(r)' mark for the recursive calls */
  PIC32_DBG_PRINT ("%4u %4u%s\n", node->used_stack, node->max_stack,
                   ((node->flags & SU_RECURSIVE) ? " (r)" : ""));

  /* don't expand the callees more than once */
  if (node->flags & SU_EXPANDED_NODE)
    return;

  node->flags |= (SU_PROCESSED_NODE | SU_EXPANDED_NODE);

  if (node->nb_callees)
    {
      struct su_caller_list new_caller_list = { .prev = caller_list,
                                                .next = NULL };
      caller_list->next = &new_caller_list;
      for (idx = 0; idx != (int) node->nb_callees; ++idx)
        {
          new_caller_list.node = node->callees[idx];
          pic32_dump_call_subgraph_1 (&new_caller_list);
        }
      caller_list->next = NULL;
    }

  node->flags &= ~SU_PROCESSED_NODE;
}

static intptr_t
pic32_reset_processed_expanded_flags (struct su_section *node,
                                      void *param __attribute__((unused)))
{
  BFD_ASSERT (node);
  node->flags &= ~(SU_PROCESSED_NODE | SU_EXPANDED_NODE);
  return 0;
}

static void
pic32_dump_call_subgraph (struct su_section *root)
{
  struct su_caller_list caller_list = { root, NULL, NULL };
  pic32_dump_call_subgraph_1 (&caller_list);
}

/* smart-io replaces some function symbols */
typedef struct {
  char *from;
  char *to;
} su_sio_replace;

static vec_type *su_sio_replaces = NULL;

/* returns the smart-io replacement, if one exists;
 * otherwise, returns the original function name */
static const char *
su_get_smartio_replacement (const char *from)
{
  int i;

  if (!su_sio_replaces)
    su_sio_replaces = VEC_NEW (su_sio_replace, 0, 0);

  for (i = 0; i != (int) VEC_SIZE (su_sio_replaces); ++i)
    {
      const su_sio_replace *rep = &VEC (su_sio_replace, su_sio_replaces, i);
      if (!strcmp (rep->from, from))
        return rep->to;
    }

  return from;
}

void
su_note_smartio_replacement (const char *from, const char *to)
{
  su_sio_replace tmp;

  /* if not already added */
  if (su_get_smartio_replacement (from) == from)
    {
      PIC32_DBG_PRINT ("smart-io replacement: %s -> %s\n", from, to);

      tmp.from = xstrdup (from);
      tmp.to   = xstrdup (to);

      VEC_PUSHBACK (su_sio_replace, su_sio_replaces, tmp);
    }
}

static void
su_free_smartio_replacements (void)
{
  if (su_sio_replaces)
    {
      int i;
      for (i = 0; i != (int) VEC_SIZE (su_sio_replaces); ++i)
        {
          su_sio_replace *rep = &VEC (su_sio_replace, su_sio_replaces, i);
          free (rep->from);
          free (rep->to);
        }
      VEC_DELETE (su_sio_replaces);
      su_sio_replaces = NULL;
    }
}

/*
* Stack Usage Estimation
* 	main function for stack usage estimation
* 		- stack usage estimation per function should
*		already be gathered
* 		- build the pseudo call-graph by adding link 
*		between caller-callee
*		- find the entry point of the application and 
*		compute the maximum stack usage from that point
*/
void
pic32_stack_estimation_run (void)
{
  struct su_section *root, *node;

  /* build call tree based on relocations */
  pic32_su_call_tree ();

  /* get application entry-point */
  root = pic32_su_get_entry_point ();

  /* prepare callstack */
  crt_callstack = su_cstack_new ();

  /* make sure we start with cleared SU_PROCESSED_NODE/SU_EXPANDED_NODE flags
   * for all the functions;
   *
   * SU_PROCESSED_NODE is set temporarily (reset on return) during each
   *                   pic32_su_max_stack() and pic32_dump_call_subgraph() call
   *
   * SU_EXPANDED_NODE is only set (never reset) by the
   *                  pic32_dump_call_subgraph () calls
   */
  map_over_su_sections (pic32_reset_processed_expanded_flags, NULL);

  if (root != NULL)
    {
      /* set the entry point flag so we can identify it later */
      root->flags |= SU_ENTRY_FUNC;
      root->flags &= ~SU_DISJOINT_FUNC;

      /* compute max stack usage starting from entry-point */
      pic32_su_max_stack (root);

      if (pic32_debug)
        {
          PIC32_DBG_PRINT ("==========================================\n");
          PIC32_DBG_PRINT ("App max stack usage %d\n", root->max_stack);
          PIC32_DBG_PRINT ("==========================================\n");
          pic32_dump_call_subgraph (root);
          PIC32_DBG_PRINT ("\n");
        }
    }

  /* check that callstack is in good shape (empty) */
  if (!su_cstack_is_empty (crt_callstack))
    PIC32_DBG_PRINT ("Error: Callstack not empty!\n");

  /* compute max stack usage for the rest of root functions */
  for (node = su_sections; node != NULL; node = node->next)
    {
      if (node == root || (node->flags & SU_DISCARDED_NODE))
        continue;

      if (node->flags & (SU_INTERRUPT | SU_DISJOINT_FUNC))
        {
          pic32_su_max_stack (node);

          if (pic32_debug)
            {
              PIC32_DBG_PRINT ("==========================================\n");
              PIC32_DBG_PRINT ("Interrupt/disjoint fn <%s> stack usage %d\n",
                               node->fname, node->max_stack);
              PIC32_DBG_PRINT ("==========================================\n");
              pic32_dump_call_subgraph (node);
              PIC32_DBG_PRINT ("\n");
            }
        }
    }

  /* print the stack usage report */
  pic32_print_su_report (stdout);

  /* if we have the map file, also dump the report there */
  if (config.map_file)
    pic32_print_su_report (config.map_file);

  /* work done for stack usage 
   * time to clean up
   */
  su_cstack_free (crt_callstack);
  free_su_sections ();
  su_free_smartio_replacements ();
}
