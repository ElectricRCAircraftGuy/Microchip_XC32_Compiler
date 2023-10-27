#include	<stdio.h>
#include	<stdarg.h>
#include	"prefix.h"

extern int FUNC(__vasprintf) (char **str, const char *format, va_list arg);

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(vasprintf)))))
    FUNC0(vasprintf)(const char **, const char *, va_list arg);
#endif

int
FUNC(vasprintf)(char **str, const char * f, va_list arg)
{
        return FUNC(__vasprintf) (str, f, arg);
}

