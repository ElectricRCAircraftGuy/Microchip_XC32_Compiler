/*
 *	Stdio scanf
 */

#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(vscanf))))) 
    FUNC0(vscanf)(const char *fmt, va_list ap);
#endif

int
FUNC(vscanf)(const char * fmt, va_list ap)
{
  return(FUNC(vfscanf)(stdout, fmt, ap));
}
