#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prefix.h"

#define SN_MIN_BUF	256

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(vsnprintf)))))
    FUNC0(vsnprintf)(char *, size_t, const char *, va_list);
#endif

int
FUNC(vsnprintf)(char *str, size_t size, const char *fmt, va_list ap)
{
  int ret;
  FILE f;

  f._flags = __SWR | __SSTR;
  f._bf._base = f._p = (unsigned char *) str;
  f._bf._size = f._w = (size > 0 ? size - 1 : 0);
  f._file = -1;  /* No file. */
  f._flags2 = 0; /* initialize flags2 as it will be used to check the __SWID flag */
  ret = FUNC(vfprintf)(&f, fmt, ap);
  if (size > 0)
    *f._p = 0;
  return ret;
}
