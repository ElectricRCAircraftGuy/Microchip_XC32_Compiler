/* Subroutines used for Microchip PIC32M code generation.
   Copyright (C) 1989, 1990, 1991, 1993, 1994, 1995, 1996, 1997, 1998,
   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2019
   Free Software Foundation, Inc.
   Contributed by Rathish C, rathish.chamukuttan@microchip.com

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "diagnostic-core.h"
#include "opts.h"
#include "version.h"

#include "mchp-protos.h"
#include "mchp.h"

#if !defined(SKIP_LICENSE_MANAGER)

#include "config/mchp-cci/xclm_public.h"
#include "config/mchp-cci/mchp_sha.h"

#else

#define MCHP_XCLM_FREE_LICENSE           0x0
#define MCHP_XCLM_VALID_STANDARD_LICENSE 0x1
#define MCHP_XCLM_VALID_PRO_LICENSE      0x2
#define MCHP_XCLM_VALID_FS_LICENSE       0x7
#define MCHP_XCLM_NO_CCOV_LICENSE        0x8
#define MCHP_XCLM_VALID_CCOV_LICENSE     0x9
/* New option used for named license */
#define MCHP_XCLM_VALID_NAMED_LICENSE    0xA

/* New option used for analysis tool-suite license */
#define MCHP_XCLM_NO_ANATS_LICENSE         0x0
#define MCHP_XCLM_VALID_ANATS_LICENSE      0xB

#endif  /* SKIP_LICENSE_MANAGER */

/* Note: this doesn't look like it's defined anymore in xclm_public.h,
 * so just define it - but maybe it should be removed?! */
#define MCHP_XCLM_EXPIRED_DEMO           0x10


/* Static Variables to modify the optimization option levels */

static int nullify_Os = 0;
static int nullify_O3 = 0;
static int nullify_mips16 = 0;
static int nullify_lto = 0;

static const char *disabled_option_message = NULL;
static int message_displayed = 0;
static int message_purchase_display = 0;
static const char *invalid_license = "due to an invalid XC32 license";

#define NULLIFY(X,S) \
    if (X) { \
      if ((S != NULL) && (disabled_option_message == NULL)) { \
          disabled_option_message = S; \
          message_displayed++;         \
        } \
    } \
    X

#define str(s) _str(s)
#define _str(s) #s

/* Some standard definitions. */
#define XCLM_XC32_PRODUCT_NAME "swxc32"
#define XCLM_XCCOV_PRODUCT_NAME "swxc-cov"
#define XCLM_XCCOV_COMMAND_OPTION "-fcfc"

/*
 * When building for a functional safety (FUSA) license check, the
 * option passed to xclm for the license check is different, but not
 * for code coverage.  The default license value when skipping the
 * license manager is also different.  More importantly, once we get
 * the license, some checks must be run to ensure that only the FS
 * license is allowed.  The macros below define these values and
 * actions.
 */
#ifndef _BUILD_MCHP_FUSA_
static bool
allow_options_p (HOST_WIDE_INT license_value)
{
  return ((license_value == MCHP_XCLM_VALID_PRO_LICENSE)
	  || (license_value == MCHP_XCLM_VALID_STANDARD_LICENSE));
}

#define XCLM_XC32_COMMAND_OPTION "-fcfc"
#define LM_INITIAL_LICENSE_VALUE MCHP_XCLM_VALID_PRO_LICENSE
#define LM_AFTER_GET_LICENSE do { (void) 0; } while (0)

#else  /* _BUILD_MCHP_FUSA_ */

static bool
allow_options_p (HOST_WIDE_INT license_value)
{
  return (license_value == MCHP_XCLM_VALID_FS_LICENSE);
}

#define XCLM_XC32_COMMAND_OPTION "-fcfs"
#define LM_INITIAL_LICENSE_VALUE MCHP_XCLM_VALID_FS_LICENSE
#define LM_AFTER_GET_LICENSE                                            \
  if (mchp_pic32_license_valid != MCHP_XCLM_VALID_FS_LICENSE)           \
    {                                                                   \
      error("This compiler needs a valid MPLAB XC compiler "            \
            "Functional Safety license.  Aborting compilation.");       \
      inform(input_location, "Visit "					\
             "https://www.microchip.com/mplab/compilers for more information."); \
      return;								\
    }
#endif /* _BUILD_MCHP_FUSA_ */

#ifdef MCHP_USE_LICENSE_CONF
#define MCHP_LICENSE_CONF_FILENAME "license.conf"
#define MCHP_LICENSEPATH_MARKER "license_dir"
#endif /* MCHP_USE_LICENSE_CONF */


/* Set the License manager */

#ifdef __MINGW32__
#define MCHP_MAX_LICENSEPATH_LINE_LENGTH 1024
#define MCHP_XCLM_FILENAME "xclm.exe"
#else
#define MCHP_XCLM_FILENAME "xclm"
#endif /* __MINGW32__*/

/* this value indicates that the license status isn't resolved yet */
#define MCHP_LICENSE_TBD -1

#ifdef SKIP_LICENSE_MANAGER
static HOST_WIDE_INT mchp_pic32_license_valid = LM_INITIAL_LICENSE_VALUE;
static HOST_WIDE_INT mchp_xccov_license_valid = MCHP_XCLM_VALID_CCOV_LICENSE;
#else
static HOST_WIDE_INT mchp_pic32_license_valid = MCHP_LICENSE_TBD;
static HOST_WIDE_INT mchp_xccov_license_valid = MCHP_LICENSE_TBD;
#endif /* SKIP_LICENSE_MANAGER*/

#ifdef MCHP_USE_LICENSE_CONF
/* get a line, and remove any line-ending \n or \r\n */
static char *
get_line (char *buf, size_t n, FILE *fptr)
{
  if (fgets (buf, n, fptr) == NULL)
    return NULL;
  while (buf [strlen (buf) - 1] == '\n'
         || buf [strlen (buf) - 1] == '\r')
    buf [strlen (buf) - 1] = '\0';
  return buf;
}
#endif


#ifndef SKIP_LICENSE_MANAGER

static char*
get_license_manager_path (void)
{
  extern struct cl_decoded_option *save_decoded_options;
  char *xclmpath = NULL;
  char* bindir = NULL;
  struct stat filestat;
  int xclmpath_length;

#ifdef MCHP_USE_LICENSE_CONF
  char *conf_dir, *conf_fname;
  FILE *fptr = NULL;
  char line [MCHP_MAX_LICENSEPATH_LINE_LENGTH] = {0};

  /* MCHP_LICENSE_CONF_FILENAME must reside in the same directory as pic32-gcc */
  conf_dir = make_relative_prefix(save_decoded_options[0].arg,
                                  "/pic32mx/bin/gcc/pic32mx/"
                                  str(BUILDING_GCC_MAJOR) "."
                                  str(BUILDING_GCC_MINOR) "."
                                  str(BUILDING_GCC_PATCHLEVEL),
                                  "/bin");

  /* alloc space for the filename: directory + '/' + MCHP_LICENSE_CONF_FILENAME
   */
  conf_fname = (char*)alloca (strlen (conf_dir) + 1 +
                              strlen (MCHP_LICENSE_CONF_FILENAME) + 1);
  strcpy (conf_fname, conf_dir);
  if (conf_fname [strlen (conf_fname) - 1] != '/'
      && conf_fname [strlen (conf_fname) - 1] != '\\')
    strcat (conf_fname, "/");
  strcat (conf_fname, MCHP_LICENSE_CONF_FILENAME);

  if ((fptr = fopen (conf_fname, "rb")) != NULL)
    {
      while (get_line (line, sizeof (line), fptr) != NULL)
        {
          char *pch0, *pch1;
          /* Find the line with the license directory */
          if (strstr (line, MCHP_LICENSEPATH_MARKER))
            {
              /* Find the quoted string on that line */
              pch0 = strchr (line,'"') +1;
              pch1 = strrchr (line,'"');
              if ((pch1-pch0) > 2)
                strncpy (xclmpath, pch0, pch1-pch0);
              break;
            }
        }
      /* Append the xclm executable name to the directory. */
      if (xclmpath [strlen (xclmpath) - 1] != '/'
          && xclmpath [strlen (xclmpath) - 1] != '\\')
        strcat (xclmpath, "/");
      strcat (xclmpath, MCHP_XCLM_FILENAME);

    }

  if (fptr != NULL)
    {
      fclose (fptr);
      fptr = NULL;
    }
#endif /* MCHP_USE_LICENSE_CONF */

#ifdef MCHP_USE_LICENSE_CONF
  if (-1 == stat (xclmpath, &filestat))
#endif /* MCHP_USE_LICENSE_CONF */
    {
      /*  Try the compiler bin directory.
       *
       */
      bindir = make_relative_prefix(save_decoded_options[0].arg,
                                          "/pic32mx/bin/gcc/pic32mx/"
                                          str(BUILDING_GCC_MAJOR) "."
                                          str(BUILDING_GCC_MINOR) "."
                                          str(BUILDING_GCC_PATCHLEVEL),
                                          "/bin");
#if defined(MCHP_DEBUG)
      fprintf(stderr, "bindir = %s\n", bindir);
#endif

      xclmpath_length = strlen(bindir) + 1 + strlen(MCHP_XCLM_FILENAME) + 1;
      xclmpath = (char*)xcalloc(xclmpath_length+1,sizeof(char));
      strncpy (xclmpath, bindir, xclmpath_length);
      /* Append the xclm executable name to the directory. */
      if (xclmpath [strlen (xclmpath) - 1] != '/'
          && xclmpath [strlen (xclmpath) - 1] != '\\')
        strcat (xclmpath, "/");
      strcat (xclmpath, MCHP_XCLM_FILENAME);

      if (-1 == stat (xclmpath, &filestat))
        {
          free (xclmpath);
          /*  Try the old common directory
           */
          xclmpath_length = strlen("/opt/Microchip/xclm/bin/") + strlen(MCHP_XCLM_FILENAME) + 1;
          xclmpath = (char*)xcalloc(xclmpath_length+1,sizeof(char));
          strncpy (xclmpath, "/opt/Microchip/xclm/bin/", xclmpath_length);
          /* Append the xclm executable name to the directory. */
          strcat (xclmpath, MCHP_XCLM_FILENAME);
        }
      if (-1 == stat (xclmpath, &filestat))
        {
          /*  Try the build directory
           */
          strncpy (xclmpath, "/build/xc32/xclm/bin/", xclmpath_length);
          /* Append the xclm executable name to the directory. */
          strcat (xclmpath, MCHP_XCLM_FILENAME);
        }
    }

#if defined(__MINGW32__)
  {
    char *convert;
    convert = xclmpath;
    while (*convert != '\0')
      {
        if (*convert == '\\')
          *convert = '/';
        convert++;
      }
  }
#endif /* __MINGW32__ */

  if (-1 == stat (xclmpath, &filestat))
    return NULL;

#if defined(MCHP_DEBUG)
  fprintf (stderr, "%d Final xclmpath: %s\n", __LINE__, xclmpath);
#endif /* MCHP_DEBUG */
  return xclmpath;
}
#ifdef MCHP_USE_LICENSE_CONF
#undef MCHP_MAX_LICENSEPATH_LINE_LENGTH
#undef MCHP_LICENSE_CONF_FILENAME
#undef MCHP_LICENSEPATH_MARKER
#endif /* MCHP_USE_LICENSE_CONF */

#undef MCHP_XCLM_FILENAME

#endif /* SKIP_LICENSE_MANAGER */

/* Retrieves the XC32 or the XCCOV license from XCLM.  Calls XCLM
   using xclm_option and product_name, and returns the license type
   indicated by XCLM's return code.  If there are any errors, return
   default_license.  If the mafrlcsj option was provided, return
   valid_license. */
static int
pic32_get_license (int current_license, int default_license, int valid_license,
                   const char *xclm_option, const char *product_name,
                   bool construct_version)
{
  /* if license type already determined for the corresponding product, just return it */
  if (current_license != MCHP_LICENSE_TBD)
    {
      return current_license;
    }

  int license_type = default_license;

  /*
   *  On systems where we have a licence manager, call it
   */
#ifndef SKIP_LICENSE_MANAGER
  {
    char *exec;
#if XCLM_FULL_CHECKOUT
    char *kopt = const_cast<char *>(xclm_option);
#else
    char kopt[] = "-checkout";
#endif /* XCLM_FULL_CHECKOUT */
    char *product = const_cast<char *>(product_name);
    char version[16] = "1.0"; /* 1.0 works for xccov; for xc32, the version is determined below */
    char date[] = MCHP_BUILD_DATE;

#if XCLM_FULL_CHECKOUT
    char *args[] = { NULL, NULL, NULL, NULL, NULL, NULL};
#else
    char *args[] = { NULL, NULL, NULL, NULL, NULL};
#endif /* XCLM_FULL_CHECKOUT */

    const char *failure = NULL;
    int status = 0;
    int err = 0;
    struct stat filestat;
    int found_xclm = 0, xclm_tampered = 1;

    /* Get the version number string from the entire version string */
    if (construct_version)
      {
        snprintf (version, sizeof(version), "%d", _XC32_VERSION_);
      }

    /* Arguments to pass to xclm */
    args[1] = kopt;
    args[2] = product;
    args[3] = version;

#if XCLM_FULL_CHECKOUT
    args[4] = date;
#endif /* XCLM_FULL_CHECKOUT */

    /* Get a path to the license manager to try */
    exec = get_license_manager_path();

#if defined(MCHP_DEBUG)
    fprintf (stderr, "exec is %s\n", exec);
#endif

    if (exec == NULL)
      {
         /*The free edition is used if the license manager isn't available.*/
        warning (0, "Could not retrieve compiler license");
        inform (input_location, "Please reinstall the compiler");
      }
    else if (-1 == stat (exec, &filestat))
      {
         /*The free edition is used if the license manager execution fails. */
        warning (0, "Could not retrieve compiler license");
        inform (input_location, "Please reinstall the compiler");
      }
    else
      {
        /* Found xclm */
          found_xclm = 1;
      }

    /* Verify SHA sum and call xclm to determine the license */
    if (found_xclm && !TARGET_SKIP_LICENSE_CHECK)
      {
        /* Verify that xclm executable is untampered */
        xclm_tampered = mchp_sha256_validate(exec, (const unsigned char*)str(MCHP_XCLM_SHA256_DIGEST));
#ifdef __linux__
        /*On linux, try to validate against 64-bit and fake xclm SHA if 32-bit xclm SHA does not match*/
        if (xclm_tampered != 0)
          {
            xclm_tampered = mchp_sha256_validate(exec, (const unsigned char*)str(MCHP_XCLM64_SHA256_DIGEST));
          }
        if (xclm_tampered != 0)
          {
            xclm_tampered = mchp_sha256_validate(exec, (const unsigned char*)str(MCHP_FXCLM_SHA256_DIGEST));
          }
#endif
        if (xclm_tampered != 0)
          {
            /* The free edition is used if the license manager SHA digest does not
               match. The free edition disables optimization options without an
               eval period. */
            warning (0, "Detected corrupt executable file");
            inform (input_location, "Please reinstall the compiler");
          }
        else
          {
            args[0] = exec;
            failure = pex_one(0, exec, args, "MPLAB XC32 Compiler", 0, 0, &status, &err);

            if (failure != NULL)
              {
                /* The free edition is used if the license manager isn't available.
                   The free edition disables optimization options without an
                   eval period. */
                warning (0, "Could not retrieve compiler license (%s)", failure);
                inform (input_location, "Please reinstall the compiler");
              }
            else if (WIFEXITED(status))
              {
                /* Use the license type reported by XCLM */
                license_type = WEXITSTATUS(status);
              }
          }
      }
  }
#endif /* SKIP_LICENSE_MANAGER */

  if (mchp_mafrlcsj) {
    license_type = valid_license;
  }

  return license_type;
}

/* xc-coverage.c uses this to check for a valid codecov license */
int
pic32_licensed_xccov_p ()
{
  return (mchp_xccov_license_valid == MCHP_XCLM_VALID_CCOV_LICENSE ||
	  mchp_xccov_license_valid == MCHP_XCLM_VALID_ANATS_LICENSE);
}

void mchp_override_options_after_change(void) {
    if (nullify_Os)
      {
        /* Disable -Os optimization(s) */
        /* flag_web and flag_inline_functions already disabled */
        if (optimize_size)
          {
            optimize = 2;
          }
        NULLIFY(optimize_size, "Optimize for size") = 0;
      }

    if (nullify_O3)
      {
        if (optimize >= 3)
          {
            NULLIFY(optimize, "Optimization level > 2") = 2;
          }
        /* Disable -O3 optimizations */
        NULLIFY(flag_tree_loop_distribute_patterns, "tree loop distribute patterns") = 0;
        NULLIFY(flag_predictive_commoning, "predictive commoning") = 0;
        NULLIFY(flag_split_paths, "split paths") = 0;
        NULLIFY(flag_inline_functions, "inline functions") = 0;
        NULLIFY(flag_split_loops, "split loops") = 0;
        NULLIFY(flag_unswitch_loops, "unswitch loops") = 0;
        NULLIFY(flag_unroll_jam, "unroll and jam") = 0;
        NULLIFY(flag_gcse_after_reload, "gcse after reload") = 0;
        NULLIFY(flag_tree_loop_vectorize, "tree loop vectorize") = 0;
        NULLIFY(flag_tree_slp_vectorize, "tree slp vectorize") = 0;
        NULLIFY(flag_ipa_cp_clone, "ipa cp clone") = 0;
        NULLIFY(flag_tree_partial_pre, "tree partial pre") = 0;
        NULLIFY(flag_peel_loops, "peel loops") = 0;
        flag_ipa_cp = 0;
       }
    if (nullify_mips16)
      {
        /* Disable -mips16 and -mips16e */
        if ((mips_base_compression_flags & (MASK_MIPS16)) != 0)
          {
            /* Disable -mips16 and -mips16e */
            NULLIFY(mips_base_compression_flags, "mips16 mode") = 0;
          }
        if ((mips_base_compression_flags & (MASK_MICROMIPS)) != 0 &&
            mchp_subtarget_mips32_enabled())
          {
            /* Disable -mmicromips */
            NULLIFY(mips_base_compression_flags, "micromips mode") = 0;
          }
      }
    if (nullify_lto)
      {
        NULLIFY(flag_lto, "Link-time optimization") = 0;
        NULLIFY(flag_whole_program, "Whole-program optimizations") = 0;
        NULLIFY(flag_generate_lto, "Link-time optimization") = 0;
      }
}

static void mchp_print_license_warning (void)
{
    switch (mchp_pic32_license_valid)
      {
      case MCHP_XCLM_EXPIRED_DEMO:
        invalid_license = "because the XC32 evaluation period has expired";
        break;
      case MCHP_XCLM_FREE_LICENSE:
        invalid_license = "because this feature requires the MPLAB XC32 PRO compiler";
        break;
      default:
        invalid_license = "due to an invalid XC32 license";
        break;
      }

    if (message_displayed && TARGET_LICENSE_WARNING)
      {
        /* Display a warning for the Standard option first */
        if (disabled_option_message != NULL)
          warning (0,"Compiler option (%s) ignored %s",
                   disabled_option_message, invalid_license);
        disabled_option_message = NULL;
        message_purchase_display++;
      }
}

void
mchp_subtarget_override_options_license (void)
{

  if (mchp_it_transport && *mchp_it_transport) {
    if (strcasecmp(mchp_it_transport,"profile") == 0) {
          mchp_profile_option = 1;
    }
  }

  if (mchp_stack_usage)
    flag_stack_usage_info = 1;

#ifndef SKIP_LICENSE_MANAGER
  nullify_O3     = 1;
  nullify_Os     = 1;
  nullify_mips16 = 1;
  nullify_lto    = 1;
#endif /* SKIP_LICENSE_MANAGER */

  if (TARGET_SKIP_LICENSE_CHECK) {
    TARGET_LICENSE_WARNING = 0;
  }

  if (mchp_profile_option) {
    flag_inline_small_functions = 0;
    flag_inline_functions = 0;
    flag_no_inline = 1;
    flag_optimize_sibling_calls = 0;
  }

  if (TARGET_SKIP_LICENSE_CHECK)
  {
    mchp_pic32_license_valid = MCHP_XCLM_FREE_LICENSE;
    mchp_xccov_license_valid = MCHP_XCLM_NO_CCOV_LICENSE;
  }
  else
  {
    mchp_pic32_license_valid = pic32_get_license (mchp_pic32_license_valid,
                                                  MCHP_XCLM_FREE_LICENSE,
                                                  LM_INITIAL_LICENSE_VALUE,
                                                  XCLM_XC32_COMMAND_OPTION,
                                                  XCLM_XC32_PRODUCT_NAME,
                                                  true);
    LM_AFTER_GET_LICENSE;
    if (mchp_codecov !=0) {
      mchp_xccov_license_valid = pic32_get_license (mchp_xccov_license_valid,
                                                  MCHP_XCLM_NO_CCOV_LICENSE,
                                                  MCHP_XCLM_VALID_CCOV_LICENSE,
                                                  XCLM_XCCOV_COMMAND_OPTION,
                                                  XCLM_XCCOV_PRODUCT_NAME,
                                                  false);
    }
    else {
      mchp_xccov_license_valid = MCHP_XCLM_NO_CCOV_LICENSE ;
    }
  }

  if (allow_options_p (mchp_pic32_license_valid))
    {
      nullify_lto = nullify_mips16 = nullify_O3 = nullify_Os = 0;
    }

  /*
   *  On systems where we have a licence manager, call it
   */

  {
    /*
     * Prior to v1.40 (gcc upgrade from 4.5.2 to 4.8.3),
     * mchp_override_options_after_change() was called from optimization_option()
     * through OPTIMIZATION_OPTION target macro which is poisoned in 4.8.3. Hence
     * optimization_option() was removed. Call to  mchp_override_options_after_change()
     * added here to fix XC32-546
     */

    mchp_override_options_after_change();
    if (TARGET_LICENSE_WARNING)
    {
      mchp_print_license_warning();
    }

    if (nullify_lto)
    {
      if (optimize_size)
      {
        optimize = 2;
      }
      if (optimize >= 3)
      {
        NULLIFY(optimize, "Optimization level > 2") = 2;
      }

      NULLIFY(optimize_size, "Optimize for size") = 0;
      NULLIFY(flag_predictive_commoning, "predictive commoning") = 0;
      NULLIFY(flag_inline_functions, "inline functions") = 0;
      NULLIFY(flag_unswitch_loops, "unswitch loops") = 0;
      NULLIFY(flag_gcse_after_reload, "gcse after reload") = 0;
      NULLIFY(flag_tree_loop_vectorize, "tree loop vectorize") = 0;
      NULLIFY(flag_tree_slp_vectorize, "tree slp vectorize") = 0;
      NULLIFY(flag_ipa_cp_clone, "ipa cp clone") = 0;

      flag_ipa_cp = 0;

      NULLIFY(flag_lto, "Link-time optimization") = 0;
      NULLIFY(flag_whole_program, "Whole-program optimizations") = 0;
      NULLIFY(flag_generate_lto, "Link-time optimization") = 0;

      /* Disable -mips16 and -mips16e */
      if ((mips_base_compression_flags & (MASK_MIPS16)) != 0)
      {
        /* Disable -mips16 and -mips16e */
        NULLIFY(mips_base_compression_flags, "mips16 mode") = 0;
       }

      if (((mips_base_compression_flags & (MASK_MICROMIPS)) != 0 && mchp_subtarget_mips32_enabled()) ||
          (target_flags & MASK_MICROMIPS))
      {
        /* If this device also supports mips32, disable -mmicromips */
        NULLIFY(mips_base_compression_flags, "micromips mode") = 0;
      }
    }
	  
    if (message_displayed && TARGET_LICENSE_WARNING)
    {
      /*Now display a warning for the Pro option */
      if (disabled_option_message != NULL)
        warning (0,"Pro Compiler option (%s) ignored %s", disabled_option_message,
                   invalid_license);
      message_purchase_display++;
      message_displayed=0;
    }

    if ((message_purchase_display > 0) && (TARGET_LICENSE_WARNING))
    {
      inform ((location_t) 0, "Disable the option or visit http://www.microchip.com/MPLABXCcompilers "
                "to purchase a new MPLAB XC compiler license.");

      /*If the --nofallback option was specified, abort compilation. */
      if (TARGET_NO_FALLBACKLICENSE)
          error ("Unable to find a valid license, aborting");

      message_purchase_display = 0;
    }

    /*Require a Standard or Pro license */
    if (TARGET_NO_FALLBACKLICENSE &&
        (mchp_pic32_license_valid == MCHP_XCLM_FREE_LICENSE))
      error ("Unable to find a valid license, aborting");
  }
}
