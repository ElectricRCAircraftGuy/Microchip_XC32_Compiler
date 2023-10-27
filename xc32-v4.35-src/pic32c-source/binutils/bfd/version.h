/* The date below is automatically updated every day by a bot.  During
   development, we include the date in the tools' version strings
   (visible in 'ld -v' etc.) because people build binutils from a
   variety of sources - git, tarballs, distro sources - and we want
   something that can easily identify the source they used when they
   report bugs.  The bfd version plus date is usually good enough for
   that purpose.

   During development, this date ends up in libbfd and libopcodes
   sonames because people naturally expect shared libraries with the
   same soname to have compatible ABIs.  We could bump the bfd version
   on every ABI change, but that's just another thing contributors and
   maintainers would need to remember.  Instead, it's much easier for
   all if the soname contains the date.  This is not perfect but is
   good enough.

   In releases, the date is not included in either version strings or
   sonames.  */
/* PIC32: We don't have such a bot. We instead use the date to force in
   our own version string. */
/* MERGE-TODO: our practice of putting a long XC32 string as BFD_VERSION_DATE
   breaks the makefile commands to create bfdver.h from this file. Find another
   way - if this is even necessary. why not set via configure? */
#define BFD_VERSION_DATE 20190703
#define BFD_VERSION @bfd_version@
#define BFD_VERSION_STRING @bfd_version_package@ @bfd_version_string@
#define REPORT_BUGS_TO @report_bugs_to@
