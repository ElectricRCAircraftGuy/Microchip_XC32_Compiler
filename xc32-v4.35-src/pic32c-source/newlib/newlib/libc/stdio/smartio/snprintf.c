#include <stdio.h>
#include <stdarg.h>
#include "prefix.h"

#ifdef NDEBUG
#undef assert
#define assert(ignore) ((void)0)
#endif

#include <stdarg.h>
#include <stdio.h>

extern int FUNC(vsnprintf) (char *s, size_t size, const char *format, va_list arg);

#if defined(__C30_0__) || defined(__C32_0__)
int __attribute__((alias(STRINGIZE(FUNC(snprintf)))))
    FUNC0(snprintf)(char *s, size_t size, const char *, ...);
#endif

int FUNC(snprintf) (char *s, size_t size, const char *format, ...)
{
    va_list arg;
    int n;

    va_start (arg, format);
    n = FUNC(vsnprintf) (s, size, format, arg);
    va_end (arg);
    return n;
}
