#include	<stdio.h>
#include	<stdarg.h>
#include        <limits.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(sprintf)))))
    FUNC0(sprintf)(const char *, const char *, ...);
#endif

int
FUNC(sprintf)(char * str, const char * fmt, ...)
{
  int ret;
  va_list ap;
  FILE f;

  f._flags = __SWR | __SSTR;
  f._bf._base = f._p = (unsigned char *) str;
  f._bf._size = f._w = INT_MAX;
  f._file = -1;  /* No file. */
  f._flags2 = 0; /* initialize flags2 as it will be used to check the __SWID flag */
  va_start (ap, fmt);
  ret = FUNC(vfprintf)(&f, fmt, ap);
  va_end (ap);
  *f._p = '\0';	/* terminate the string */
  return (ret);
}
