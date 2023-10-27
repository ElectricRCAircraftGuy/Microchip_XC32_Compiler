/* Microchip CCI Backend
   Copyright (C) 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,
   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009,
   2010
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* MERGE-TODO: again the cci differences .. */

#ifndef TARGET_MCHP_PIC32MX

#include <stdio.h>
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "cpplib.h"
#include "target.h"

#define CCI_H "config/mchp-cci/cci.h"
#include CCI_H

#define CCI__(x) CCI_##x
#define CCI_(x) CCI__(x)

#define CCI(kind,ccikey,tgtkey,n) \
  { CCI_(kind),ccikey,(intptr_t)tgtkey,n },

static const struct CCIext {
  CCI_KIND   kind;
  const char *ccikey;
  intptr_t   tgtkey;
  int        n;
} CCIext[] = {
#include CCI_H
};

static void
cci_define(struct cpp_reader *pfile, const char *keyword, const char *target)
{
  gcc_assert (keyword);

  const size_t key_len = strlen (keyword);
  const size_t tgt_len = target ? strlen (target) : 0;

  /* xmalloc either succeedes or doesn't return so no need to check for success */
  char *buffer = (char *)xmalloc (key_len + tgt_len + 2);

  /* set buffer to a "keyword=target" string (target may be empty/missing) */
  memcpy (buffer, keyword, key_len);
  buffer[key_len] = '=';
  if (tgt_len)
    memcpy (buffer + key_len + 1, target, tgt_len);
  buffer[key_len + tgt_len + 1] = '\0';

  cpp_define (pfile, buffer);
  free (buffer);
}

static void
cci_attribute(struct cpp_reader *pfile, const char *keyword, const char *target,
              int varargs, int n)
{
  int params_specified = 0;
  char *buffer=NULL,*c=NULL,*tmp=NULL;
  int size;
  int i;

  gcc_assert (keyword && target);

  // check for a couple of special cases
  if (!strcmp (target, TGT_UNSUPPORTED)) {
#define TGT_MSG "unsupported(\"%s is unsupported on this platform\")"
    tmp = (char *)xcalloc (sizeof(TGT_MSG)+strlen(keyword), sizeof(char));
    sprintf (tmp, TGT_MSG, keyword);
#undef TGT_MSG
    target = tmp;
  }
  else if(!strcmp (target, TGT_ERROR)) {
#define TGT_MSG "target_error(\"%s is unsupported on this platform\")"
    tmp = (char *)xcalloc (sizeof(TGT_MSG)+strlen(keyword), sizeof(char));
    sprintf (tmp, TGT_MSG, keyword);
#undef TGT_MSG
    target = tmp;
  }
  if (n) {
    for (const char *c = target; *c; c++) {
      if ((*c == 'P') && (c[1] >= '0') && (c[1] <= '9')) {
        params_specified=1;
        break;
      }
    }
  }
  size = strlen(keyword)+1+sizeof("=__attribute__(())")+strlen(target)+1;
  if (n) {
    if (params_specified == 0) {
      size += 8 * n;  /* up to 99 params: Pnn, */
    } else {
      size += strlen(target) + strlen("()\n");
    }
  }
  if (varargs) size += strlen("=()(),...__VA_ARGS__")+1;
  buffer = (char *)xcalloc(size,sizeof(char));
  c = buffer;
  c += sprintf(c,"%s",keyword);
  if (n || varargs) {
    *c++ = '(';
    for (i = 1; i <= n; i++) {
      c += sprintf(c, "P%d", i);
      if (i < n) *c += ',';
    }
    if (varargs) {
      if (n) *c++=',';
      c += sprintf(c, "...");
    }
    *c++ = ')';
  }
  c += sprintf(c, "=__attribute__((%s", target);
  if ((n || varargs) && !params_specified) {
    *c++ = '(';
    for (i = 1; i <= n; i++) {
      c += sprintf(c, "P%d", i);
      if (i < n) *c += ',';
    }
    if (varargs) {
      if (n) *c++=',';
      c += sprintf(c, "__VA_ARGS__");
    }
    *c++ = ')';
  }
  *c++ = ')';
  *c++ = ')';
  *c++ = 0;

  if (buffer) {
    cpp_define(pfile, buffer);
    free(buffer);
  }
  free(tmp);
}

/*
 * called from SUBTARGET_CPU_CPP_BUILTINS
 */
void mchp_init_cci (struct cpp_reader *pfile) {
  if (!CCI_MCHP)
    return;

  for (unsigned i = 0; i != sizeof(CCIext)/sizeof(*CCIext); ++i) {
    const struct CCIext &ext = CCIext[i];
    switch (ext.kind) {
    case CCI_define:
      cci_define (pfile, ext.ccikey, (const char *)ext.tgtkey);
      break;
    case CCI_attribute:
    case CCI_attribute_n:
      cci_attribute (pfile, ext.ccikey, (const char *)ext.tgtkey, 0,
                     (ext.kind == CCI_attribute ? 0 : ext.n));
      break;
    case CCI_attribute_v:
    case CCI_attribute_nv:
      cci_attribute (pfile, ext.ccikey, (const char *)ext.tgtkey, 1,
                     (ext.kind == CCI_attribute_v ? 0 : ext.n));
      break;
    default:
      gcc_unreachable ();
    }
  }
}

#else /* TARGET_IS_PIC32MX */

/*
 *  Common CCI Backend definitions for Microchip Compilers
 */

#include <stdio.h>
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "basic-block.h"
#include "stringpool.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "insn-config.h"
#include "conditions.h"
#include "output.h"
#include "insn-attr.h"
#include "flags.h"
#include "function.h"
#include "profile-count.h"
#include "expr.h"
#include "memmodel.h"
#include "optabs.h"
#include "libfuncs.h"
#include "recog.h"
#include "diagnostic-core.h"
#include "toplev.h"
#include "reload.h"
#include "bitmap.h"
#include "df.h"
#include "ggc.h"
#include "tm_p.h"
#include "debug.h"
#include "target.h"
#include "target-def.h"
#include "langhooks.h"
#include "opts.h"
#include "cgraph.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "cpplib.h"
#include "langhooks.h"
#include "tree.h"

#define CCI_BACKEND_H "config/mchp-cci/cci-backend.h"
#include CCI_BACKEND_H

#ifdef _BUILD_C30_
#define TARGET_C30 1
#else
#define TARGET_C30 0
#endif
#ifdef _BUILD_C32_
#define TARGET_C32 1
#else
#define TARGET_C32 0
#endif
#define TARGET_MCHP 1

void mchp_print_builtin_function (const_tree t)
{
  if (t && DECL_P(t))
    puts (IDENTIFIER_POINTER(DECL_NAME(t)));
}

#ifdef _BUILD_C32_
#include "target.h"
#include "config/pic32m/mchp-protos.h"
#define CCI_H "config/mchp-cci/cci.h"
#include CCI_H

#ifdef _BUILD_C30_
#define TARGET_C30 1
#else
#define TARGET_C30 0
#endif
#ifdef _BUILD_C32_
#define TARGET_C32 1
#else
#define TARGET_C32 0
#endif
#define TARGET_MCHP 1

static void cci_define(void *pfile_v, const char *keyword, const char *target) {
  struct cpp_reader *pfile = (struct cpp_reader *)pfile_v;
  char *buffer = NULL;

  if (target)
    {
      buffer = (char *)xmalloc(strlen(keyword) + strlen(target) + 7);
      sprintf(buffer,"%s=%s", keyword, target);
    }
  else
    {
      buffer = (char *)xmalloc(strlen(keyword) + strlen("=") + 7);
      sprintf(buffer,"%s=", keyword);
    }
  if (buffer) {
    cpp_define(pfile, buffer);
    free(buffer);
  }
  return;
}

static void cci_attribute(void *pfile_v,const char *keyword, const char *target,
                   int varargs, int n) {
  struct cpp_reader *pfile = (struct cpp_reader *)pfile_v;
  int params_specified = 0;
  char *buffer=NULL,*c=NULL;
  int size;
  int i;

  if (n) {
    const char *c = NULL;
    for (c = target; *c; c++) {
      if ((*c == 'P') && (c[1] >= '0') && (c[1] <= '9')) {
        params_specified=1;
        break;
      }
    }
  }
  size = strlen(keyword)+1+sizeof("=__attribute__(())")+strlen(target)+1;
  if (n) {
    if (params_specified == 0) {
      size += 8 * n;  /* up to 99 params: Pnn, */
    } else {
      size += strlen(target) + strlen("()\n");
    }
  }
  if (varargs) size += strlen("=()(),...__VA_ARGS__")+1;
  buffer = (char *)xcalloc(size,sizeof(char));
  c = buffer;
  c += sprintf(c,"%s",keyword);
  if (n || varargs) {
    *c++ = '(';
    for (i = 1; i <= n; i++) {
      c += sprintf(c, "P%d", i);
      if (i < n) *c += ',';
    }
    if (varargs) {
      if (n) *c++=',';
      c += sprintf(c, "...");
    }
    *c++ = ')';
  }
  c += sprintf(c, "=__attribute__((%s", target);
  if ((n || varargs) && !params_specified) {
    *c++ = '(';
    for (i = 1; i <= n; i++) {
      c += sprintf(c, "P%d", i);
      if (i < n) *c += ',';
    }
    if (varargs) {
      if (n) *c++=',';
      c += sprintf(c, "__VA_ARGS__");
    }
    *c++ = ')';
  }
  *c++ = ')';
  *c++ = ')';
  *c++ = 0;

  if (buffer) {
    cpp_define(pfile, buffer);
    free(buffer);
  }
}

ATTRIBUTE_UNUSED static void set_value(unsigned int *loc, unsigned int value) {
 *loc = value;
}

/*
 * call from TARGET_CPU_CPP_BUILTINS
 */

void mchp_init_cci(void *pfile_v) {

#define CCI
#define CCI_DEFINE(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    cci_define(pfile_v, CCI_KEYWORD, (const char *)TGT_KEYWORD);
#include CCI_H

#define CCI
#define CCI_ATTRIBUTE(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    cci_attribute(pfile_v, CCI_KEYWORD, (const char *)TGT_KEYWORD, 0, 0);
#include CCI_H

#define CCI
#define CCI_ATTRIBUTE_N(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    cci_attribute(pfile_v, CCI_KEYWORD, (const char *)TGT_KEYWORD, 0, N);
#include CCI_H

#define CCI
#define CCI_ATTRIBUTE_V(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    cci_attribute(pfile_v, CCI_KEYWORD, (const char *)TGT_KEYWORD, 1, 0);
#include CCI_H

#define CCI
#define CCI_ATTRIBUTE_NV(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    cci_attribute(pfile_v, CCI_KEYWORD, (const char *)TGT_KEYWORD, 1, N);
#include CCI_H

#define CCI
#define CCI_SET_VALUE(TARGET, CCI_KEYWORD, TGT_KEYWORD, N) \
  if (TARGET) \
    set_value((unsigned int*)TGT_KEYWORD,N);
#include CCI_H

}

void mchp_init_cci_builtins(void) {

#ifndef _BUILD_C32_
#define CCI
#define CCI_PRAGMA(TARGET, CCI_KEYWORD, TGT_FN, N) \
  if (TARGET) \
    c_register_pragma(0, CCI_KEYWORD, TGT_FN);
#include CCI_H
#endif
/*
 * Special case mapping
 *
 */
 if (IMPORT_MCHP("iar")) {
   // define builtins for the functions that we don't define
   //   and mark them as unsupported

   tree attrib, args;
   tree fn_type;

#  define MESSAGE "Intrinsic function is unsupported for this target"
   args = build_tree_list(NULL_TREE, build_string(strlen(MESSAGE), MESSAGE));
   attrib = build_tree_list(get_identifier("target_error"), args);
#  undef MESSAGE

   fn_type = build_function_type_list(void_type_node, void_type_node,NULL_TREE);
   add_builtin_function("__disable_fiq", fn_type, 0, BUILT_IN_MD, NULL, attrib);
   /*                                             ^ this should be okay
    *  because we are going to generate an error for it...
    */

   add_builtin_function("__disable_irq", fn_type, 0, BUILT_IN_MD, NULL, attrib);
   /*                                             ^ this should be okay
    *  because we are going to generate an error for it...
    */

   add_builtin_function("__enable_fiq", fn_type, 0, BUILT_IN_MD, NULL, attrib);
   /*                                            ^ this should be okay
    *  because we are going to generate an error for it...
    */

   add_builtin_function("__enable_irq", fn_type, 0, BUILT_IN_MD, NULL, attrib);
   /*                                            ^ this should be okay
    *  because we are going to generate an error for it...
    */
 }
}
#endif

#endif /* TARGET_IS_PIC32MX */
