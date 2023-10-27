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

/*
 * Flush out all the vectors defined by the given uio,
 * then reset it so that it can be reused.
 */
int
__sprint_r (struct _reent *ptr,
       FILE *fp,
       register struct __suio *uio)
{
	register int err = 0;

	if (uio->uio_resid == 0) {
		uio->uio_iovcnt = 0;
		return (0);
	}
#ifdef _WIDE_ORIENT
	if (fp->_flags2 & __SWID) {
		struct __siov *iov;
		wchar_t *p;
		int i, len;

		iov = uio->uio_iov;
		for (; uio->uio_resid != 0;
		     uio->uio_resid -= len * sizeof (wchar_t), iov++) {
			p = (wchar_t *) iov->iov_base;
			len = iov->iov_len / sizeof (wchar_t);
			for (i = 0; i < len; i++) {
				if (_fputwc_r (ptr, p[i], fp) == WEOF) {
					err = -1;
					goto out;
				}
			}
		}
	} else
#endif
		err = __sfvwrite_r(ptr, fp, uio);
out:
	uio->uio_resid = 0;
	uio->uio_iovcnt = 0;
	return (err);
}
