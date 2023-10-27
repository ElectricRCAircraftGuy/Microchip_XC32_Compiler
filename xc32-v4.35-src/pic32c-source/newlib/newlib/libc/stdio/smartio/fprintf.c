#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(fprintf))))) 
    FUNC0(fprintf)(FILE *fp, register const char *, ...);
#endif

int
FUNC(fprintf)(FILE * file, const char * f, ...)
{
	va_list	ap;

	va_start(ap, f);
	return(FUNC(vfprintf)(file, f, ap));
}
