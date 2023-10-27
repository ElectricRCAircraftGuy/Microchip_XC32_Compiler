#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(vprintf))))) 
    FUNC0(vprintf)(const char *fp,va_list ap);
#endif

int FUNC(vprintf)(const char *f, va_list ap)
{
	return(FUNC(vfprintf)(stdout, f, ap));
}

