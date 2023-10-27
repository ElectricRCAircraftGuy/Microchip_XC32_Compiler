/* Implementation of the license manager.

  This file is part of the GNU Binutils.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
  MA 02110-1301, USA. */

#include "sysdep.h"
#include "bfd.h"
#include "ld.h"                 /* For the _() macro */
#include "ldmisc.h"
#include "ldmain.h"		/* For program_name */

#include "pic32-license-manager.h"

#ifndef MCHP_BUILD_DATE
#define MCHP_BUILD_DATE __DATE__
#endif

#if !defined(SKIP_LICENSE_MANAGER)

#include <sys/stat.h>
#include <sys/types.h>

#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif
#ifndef WIFEXITED
#define WIFEXITED(S) (((S) & 0xff) == 0)
#endif
#ifndef WEXITSTATUS
#define WEXITSTATUS(S) (((S) & 0xff00) >> 8)
#endif

#include "bfdver.h"
#include "libiberty.h"

/* ugly, but we really don't need yet another xclm_public.h ... */
#include "../../gcc/gcc/config/mchp-cci/xclm_public.h"

#ifdef MCHP_XCLM_SHA256_DIGEST

/* TODO: Move this code into libmchp. */
#include "../../gcc/gcc/config/mchp-cci/sha256.c"
#include "../../gcc/gcc/config/mchp-cci/mchp_sha.c"

#ifndef xstr
#define mkstr(s) #s
#define xstr(s) mkstr(s)
#endif

#endif /* MCHP_XCLM_SHA256_DIGEST */

#ifdef __MINGW32__
#define MCHP_XCLM_FILENAME "xclm.exe"
#else
#define MCHP_XCLM_FILENAME "xclm"
#endif /* __MINGW32__*/

#ifdef _BUILD_MCHP_FUSA_
static const int max_license_type = MCHP_XCLM_VALID_FS_LICENSE;
static const char *xclm_arg1 = "-fcfs";
#else
static const int max_license_type = MCHP_XCLM_VALID_PRO_LICENSE;
static const char *xclm_arg1 = "-fcfc";
#endif


/* generic function to retrieve a license from XCLM */
/* currently declared as static as we don't use for anything else */
/* other than checking if we should do the stack usage estimation */
static int
getLicenseFromXCLM (const char *xclmExecutable,
                    const char *productName,
                    const char *productVersion)
{
  int license_type = MCHP_XCLM_FREE_LICENSE;
  int output_warning = TRUE;

  struct stat info;
  /* check the existence of the XCLM executable */
  if (!xclmExecutable || stat (xclmExecutable, &info) == -1)
    ;
  /* if MCHP_XCLM_SHA256_DIGEST is defined, use it to validate the XCLM executable */
#ifdef MCHP_XCLM_SHA256_DIGEST
  else if (0 != mchp_sha256_validate (xclmExecutable,
                   (const unsigned char *) xstr (MCHP_XCLM_SHA256_DIGEST)))
    {
      einfo (_("%Q: warning: Detected corrupt executable file.\n"));
      einfo (_("%Q: note: Please reinstall the compiler.\n"));
      output_warning = FALSE;
    }
#endif
  /* XCLM executable is ok, use it to retrieve the XC32 license */
  else
    {
      const char *args[] = { xclmExecutable, xclm_arg1, productName,
                             productVersion, MCHP_BUILD_DATE, NULL };
      int status, err;
      const char *failure = pex_one (0, xclmExecutable, (char * const *)args,
                                     "MPLAB XC32 Compiler",
                                     0, 0, &status, &err);
      if (!failure && WIFEXITED (status))
        {
          const int reported_license_type = WEXITSTATUS (status);
          if (reported_license_type >= MCHP_XCLM_FREE_LICENSE
              && reported_license_type <= max_license_type)
            {
              license_type = reported_license_type;
              output_warning = FALSE;
            }
        }
    }

  if (output_warning)
    {
      einfo (_("%Q: warning: Could not retrieve compiler license.\n"));
      einfo (_("%Q: note: Please reinstall the compiler.\n"));
    }

  return license_type;
}

typedef struct { int major, minor; } xc32_version;

static const xc32_version def_ver = { 3, 0 };

/* retrieve the XC32 version from the BFD_VERSION_STRING */
static xc32_version
getXC32Version (void)
{
  char *s = strchr (BFD_VERSION_STRING, 'v'), *end_s;
  if (s)
    {
      int major = (int) strtol (s + 1, &end_s, 10), minor;
      if (*end_s == '.'
          && major >= def_ver.major
          && major < 100)
        {
          minor = (int) strtol (end_s + 1, &end_s, 10);
          if (minor >= (major > def_ver.major ? 0 : def_ver.minor)
              && minor < 100)
            {
              return (xc32_version) { major, minor };
            }
        }
    }

  einfo (_("%Q: warning: Invalid package version (defaulting to v%d.%d)\n"),
         def_ver.major, def_ver.minor);
  return def_ver;
}

int
mchpStackUsageValidLicense (void)
{
  static int suLicenseValid = -1; /* license status not determined yet */

  if (suLicenseValid < 0)
    {
      char *xclmPath = make_relative_prefix (program_name, "./bin/bin", "./bin/");
      if (xclmPath)
        {
          const size_t xclm_path_len = strlen (xclmPath);
          const size_t xclm_name_len = strlen (MCHP_XCLM_FILENAME);
#ifdef __MINGW32__
          size_t i;
          /* xclmPath: replace backslashes with slashes on Windows */
          for (i = 0; i != xclm_path_len; ++i)
            if (xclmPath[i] == '\\')
              xclmPath[i] = '/';
#endif
          /* realloc the buffer returned by make_relative_prefix ()
           * so that we can append "xclm[.exe]" */
          char *tmpPath = (char *) realloc (xclmPath,
                                            xclm_path_len + xclm_name_len + 1);
          char XC32_VERSION[8];
          if (tmpPath)
          {
            xclmPath = tmpPath;
            memcpy (xclmPath + xclm_path_len, MCHP_XCLM_FILENAME,
                    xclm_name_len + 1);

            xc32_version version = getXC32Version ();
            snprintf (XC32_VERSION, sizeof(XC32_VERSION), "%d.%d",
                      version.major, version.minor);

            const int license_type = getLicenseFromXCLM (xclmPath, "swxc32",
                                                         XC32_VERSION);

            /* max license (PRO/FS) enables stack usage estimation */
            suLicenseValid = license_type == max_license_type;
          }
          free (xclmPath);
        }
    }

  return suLicenseValid;
}

#endif /* !defined(SKIP_LICENSE_MANAGER) */
