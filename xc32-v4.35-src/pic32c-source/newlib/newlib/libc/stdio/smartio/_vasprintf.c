#include	<stdio.h>
#include	<stdarg.h>
#include 	<stdlib.h>
#include	<errno.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(__vasprintf)))))
    FUNC0(__vasprintf)(const char **, const char *,  va_list arg);
#endif

int
FUNC(__vasprintf)(char **strp, const char * fmt, va_list ap)
{
  int ret;
  FILE f;
  unsigned char *buf;

  f._flags = __SWR | __SSTR | __SMBF ;
  f._bf._base = f._p = (unsigned char*)malloc (128);
  f._bf._size = f._w = 127;
  f._file = -1;  /* No file. */
  f._flags2 = 0; /* initialize flags2 as it will be used to check the __SWID flag */
  ret = FUNC(vfprintf)(&f, fmt, ap);
  if (ret < 0)
    goto err;
  *f._p = '\0';
  buf = realloc (f._bf._base, ret+1);
  if (buf == NULL)
    goto err;

  *strp = (char *)buf;
  return ret;

err:
  if (f._bf._base)
    free(f._bf._base);
  *strp = NULL;
  errno = ENOMEM;
  return -1;
}

