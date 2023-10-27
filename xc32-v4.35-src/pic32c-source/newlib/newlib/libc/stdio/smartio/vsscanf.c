/*
 *	Stdio vsscanf
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdarg.h>
#include	"prefix.h"
#include        "local.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(vsscanf)))))
    FUNC0(vsscanf)(const char *, const char *, va_list arg);
#endif

int 
FUNC(vsscanf)(const char * str, const char * fmt, va_list arg)
{
  FILE f;

  f._flags = __SRD | __SSTR;
  f._bf._base = f._p = (unsigned char *) str;
  f._bf._size = f._r = strlen (str);
  f._read = __seofread; /* from stdio/local.h */
  f._ub._base = NULL;
  f._lb._base = NULL;
  f._file = -1;  /* No file. */
  return FUNC(vfscanf)(&f, fmt, arg);
}
