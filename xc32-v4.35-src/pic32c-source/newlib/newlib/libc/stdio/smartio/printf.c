#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(printf))))) 
    FUNC0(printf)(FILE *fp, ...);
#endif

int FUNC(printf)(const char * f, ...)
{
	va_list	ap;

	va_start(ap, f);
	return(FUNC(vfprintf)(stdout, f, ap));
}
