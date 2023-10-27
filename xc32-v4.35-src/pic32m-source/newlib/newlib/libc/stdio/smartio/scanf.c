/*
 *	Stdio scanf
 */

#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(scanf))))) 
    FUNC0(scanf)(const char *, ...);
#endif

int
FUNC(scanf)(const  char * fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  return(FUNC(vfscanf)(stdin, fmt, ap));
}
