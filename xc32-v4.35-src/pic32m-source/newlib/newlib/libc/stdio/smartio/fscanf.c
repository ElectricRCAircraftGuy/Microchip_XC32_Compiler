/*
 *	HI-TECH C stdio fscanf
 */

#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(fscanf))))) 
    FUNC0(fscanf)(FILE *fp, register const char *, ...);
#endif

int FUNC(fscanf)(FILE * file, const char * fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  return FUNC(vfscanf)(file, fmt, ap);
}
