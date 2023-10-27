/* PIC32C: moved from nano-vfscanf.c, and renamed to avoid conflicts with
   non-nano form. */

#include <newlib.h>

#define _NO_POS_ARGS
#ifdef _WANT_IO_POS_ARGS
# undef _NO_POS_ARGS
#endif

#include <_ansi.h>
#include <reent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <wchar.h>
#include <sys/lock.h>
#include <stdarg.h>
#include "local.h"
#include "../stdlib/local.h"

_NOINLINE_STATIC int
__sfputc_r (struct _reent *ptr, int c, FILE *fp)
{
  if (--fp->_w >= 0 || (fp->_w >= fp->_lbfsize && (char)c != '\n'))
    return (*fp->_p++ = c);
  else
    return (__swbuf_r(ptr, c, fp));
}

/* this used to be __sfputs_r in nano-vfscanf.c. it differs from the usual
   __sfputs_r because it calls the static __sfputc_r to bypass the heavyweight
   __fputc_r. so I've added an extra s to distinguish them. */
int
__ssfputs_r (struct _reent *ptr, FILE *fp, const char *buf, size_t len)
{
  register int i;

#ifdef _WIDE_ORIENT
  if (fp->_flags2 & __SWID)
    {
      wchar_t *p;

      p = (wchar_t *) buf;
      for (i = 0; i < (len / sizeof (wchar_t)); i++)
	{
	  if (_fputwc_r (ptr, p[i], fp) == WEOF)
	    return -1;
	}
    }
  else
#endif
    {
      for (i = 0; i < len; i++)
	{
	  /* Call __sfputc_r to skip _fputc_r.  */
	  if (__sfputc_r (ptr, (int)buf[i], fp) == EOF)
	    return -1;
	}
    }
  return (0);
}

