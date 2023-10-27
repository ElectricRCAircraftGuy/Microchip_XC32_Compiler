/*
 *	Stdio sscanf
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdarg.h>
#include	"prefix.h"
#include        "local.h" 

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(sscanf)))))
    FUNC0(sscanf)(const char *, const char *, ...);
#endif

int 
FUNC(sscanf)(const char * str, const char * fmt, ...)
{
  int ret;
  va_list ap;
  FILE f;

  f._flags = __SRD | __SSTR;
  f._bf._base = f._p = (unsigned char *) str;
  f._bf._size = f._r = strlen (str);
  f._read = __seofread; /* from local.h */
  f._ub._base = NULL;
  f._lb._base = NULL;
  f._file = -1;  /* No file. */
  va_start (ap, fmt);
  ret = FUNC(vfscanf)(&f, fmt, ap);
  return ret;
}
