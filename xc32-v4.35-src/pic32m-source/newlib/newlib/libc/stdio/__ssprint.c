/* PIC32C: moved from vfprintf.c. */
#include <newlib.h>

#define _NO_POS_ARGS
#ifdef _WANT_IO_POS_ARGS
# undef _NO_POS_ARGS
#endif

#include <_ansi.h>
#include <reent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <wchar.h>
#include <sys/lock.h>
#include <stdarg.h>
#include "local.h"
#include "../stdlib/local.h"
#include "fvwrite.h"
#include "vfieeefp.h"

int
__ssprint_r (struct _reent *ptr,
       FILE *fp,
       register struct __suio *uio)
{
	register size_t len;
	register int w;
	register struct __siov *iov;
	register const char *p = NULL;

	iov = uio->uio_iov;
	len = 0;

	if (uio->uio_resid == 0) {
		uio->uio_iovcnt = 0;
		return (0);
	}

        do {
		while (len == 0) {
			p = iov->iov_base;
			len = iov->iov_len;
			iov++;
		}
		w = fp->_w;
		if (len >= w && fp->_flags & (__SMBF | __SOPT)) {
			/* must be asprintf family */
			unsigned char *str;
			int curpos = (fp->_p - fp->_bf._base);
			/* Choose a geometric growth factor to avoid
		 	 * quadratic realloc behavior, but use a rate less
			 * than (1+sqrt(5))/2 to accomodate malloc
		 	 * overhead. asprintf EXPECTS us to overallocate, so
		 	 * that it can add a trailing \0 without
		 	 * reallocating.  The new allocation should thus be
		 	 * max(prev_size*1.5, curpos+len+1). */
			int newsize = fp->_bf._size * 3 / 2;
			if (newsize < curpos + len + 1)
				newsize = curpos + len + 1;
			if (fp->_flags & __SOPT)
			{
				/* asnprintf leaves original buffer alone.  */
				str = (unsigned char *)_malloc_r (ptr, newsize);
				if (!str)
				{
					ptr->_errno = ENOMEM;
					goto err;
				}
				memcpy (str, fp->_bf._base, curpos);
				fp->_flags = (fp->_flags & ~__SOPT) | __SMBF;
			}
			else
			{
				str = (unsigned char *)_realloc_r (ptr, fp->_bf._base,
						newsize);
				if (!str) {
					/* Free unneeded buffer.  */
					_free_r (ptr, fp->_bf._base);
					/* Ensure correct errno, even if free
					 * changed it.  */
					ptr->_errno = ENOMEM;
					goto err;
				}
			}
			fp->_bf._base = str;
			fp->_p = str + curpos;
			fp->_bf._size = newsize;
			w = len;
			fp->_w = newsize - curpos;
		}
		if (len < w)
			w = len;
		(void)memmove ((void *) fp->_p, (void *) p, (size_t) (w));
		fp->_w -= w;
		fp->_p += w;
		w = len;          /* pretend we copied all */
		p += w;
		len -= w;
        } while ((uio->uio_resid -= w) != 0);

	uio->uio_resid = 0;
	uio->uio_iovcnt = 0;
	return 0;

err:
  fp->_flags |= __SERR;
  uio->uio_resid = 0;
  uio->uio_iovcnt = 0;
  return EOF;
}
