/* Stack protector support.
   Copyright (C) 2005-2018 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */


#include "config.h"
#ifdef HAVE_ALLOCA_H
# include <alloca.h>
#endif
#ifdef HAVE_MALLOC_H
# include <malloc.h>
#endif
#ifdef HAVE_STRING_H
# include <string.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#endif
#ifdef HAVE_PATHS_H
# include <paths.h>
#endif
#ifndef _PATH_TTY
/* Native win32 apps don't know about /dev/tty but can print directly
   to the console using  "CONOUT$"   */
#if defined (_WIN32) && !defined (__CYGWIN__)
#include <windows.h>
#include <wincrypt.h>
# define _PATH_TTY "CONOUT$"
#else
# define _PATH_TTY "/dev/tty"
#endif
#endif
#ifdef HAVE_SYSLOG_H
# include <syslog.h>
#endif

void *__stack_chk_guard = 0;

static void __attribute__ ((constructor))
__guard_setup (void)
{
  unsigned char *p;

  if (__stack_chk_guard != 0)
    return;

#if defined (_WIN32) && !defined (__CYGWIN__)
  HCRYPTPROV hprovider = 0;
  if (CryptAcquireContext(&hprovider, NULL, NULL, PROV_RSA_FULL,
                          CRYPT_VERIFYCONTEXT | CRYPT_SILENT))
    {
      if (CryptGenRandom(hprovider, sizeof (__stack_chk_guard),
          (BYTE *)&__stack_chk_guard) &&  __stack_chk_guard != 0)
        {
           CryptReleaseContext(hprovider, 0);
           return;
        }
      CryptReleaseContext(hprovider, 0);
    }
#else
  int fd = open ("/dev/urandom", O_RDONLY);
  if (fd != -1)
    {
      ssize_t size = read (fd, &__stack_chk_guard,
                           sizeof (__stack_chk_guard));
      close (fd);
      if (size == sizeof(__stack_chk_guard) && __stack_chk_guard != 0)
        return;
    }

#endif
  /* If a random generator can't be used, the protector switches the guard
     to the "terminator canary".  */
  p = (unsigned char *) &__stack_chk_guard;
  p[sizeof(__stack_chk_guard)-1] = 255;
  p[sizeof(__stack_chk_guard)-2] = '\n';
  p[0] = 0;
}



#ifndef __DISABLE_WARNINGS__
char __attribute__((section(".gnu.warning.__stack_chk_fail")))
__warning__stack_chk_fail[] = "Linking stub __stack_chk_fail(). Hint: It is better to provide an app-specific implementation of void __stack_chk_fail (void)";
#endif

void
__attribute__((weak,noreturn)) __stack_chk_fail (void)
{
    //\ XC32 implementation
    while(1)
    {
        __builtin_software_breakpoint();
    }
}

#ifndef __DISABLE_WARNINGS__
char __attribute__((section(".gnu.warning.__chk_fail")))
__warning__chk_fail[] = "Linking stub __chk_fail(). Hint: It is better to provide an app-specific implementation of void __chk_fail (void)";
#endif

void
__attribute__((weak,noreturn)) __chk_fail (void)
{
    //\ XC32 implementation
    while(1)
    {
        __builtin_software_breakpoint();
    }
}

#ifdef HAVE_HIDDEN_VISIBILITY
void
__attribute__((visibility ("hidden")))
__stack_chk_fail_local (void)
{
  __stack_chk_fail ();
}
#endif
