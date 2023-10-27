#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

extern int FUNC(__vasprintf) (char **str, const char *format, va_list arg);

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(asprintf)))))
    FUNC0(asprintf)(const char **, const char *, ...);
#endif

int
FUNC(asprintf)(char **str, const char * f, ...)
{
  int n;
  va_list arg;

  va_start (arg, f);

  n = FUNC(__vasprintf) (str, f, arg);
  va_end (arg);
  return n;
}

