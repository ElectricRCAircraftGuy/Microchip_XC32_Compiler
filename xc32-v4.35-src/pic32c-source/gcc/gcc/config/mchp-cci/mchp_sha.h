/* Subroutines used for Microchip PIC32 MCU support
   Copyright (C) 2014
   Microchip Technology, Inc.
   Contributed by S. Bekal, swaroopkumar.bekal@microchip.com

This file is part of Microchip XC compiler tool-chain.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
alng with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef MCHP_SHA_H
#define MCHP_SHA_H

/* SHA-256 digest of xclm executables for Win, Linux and OS X */
#if !defined(MCHP_XCLM_SHA256_DIGEST)
# if defined(__MINGW32__)
#  define MCHP_XCLM_SHA256_DIGEST   c95c0bf9e3e346b79b5f14c261c2deb9640591523fba5d1f0a6e6202e0f79b22
# elif defined(__linux__)
#  define MCHP_XCLM_SHA256_DIGEST   25c59700405f1de167e24681e90af0f4c354fac1e111b55b9bc3ba8f3e562c82
# elif defined(__MACH__)
#  define MCHP_XCLM_SHA256_DIGEST   2d97361e93c150bbcdd9726923eae00e1ce1a2a5f00a550f9b1f34774ad69baa
# else
#  error "Unknown host"
# endif
#endif

/* Function to calculate the SHA256 digest of given file
 * Parameters :
 *     - Absolute path to file
 *     - Buffer to hold SHA256 digest
 * Return value :
 *     - 0 on success, non-zero on any error
*/
int mchp_sha256( const char *path, unsigned char output[32] );

/* Function to validate if the SHA256 digest of given file
 * mathces the suppiled value
 * Parameters :
 *     - Absolute path to file
 *     - Pre-calculated SHA256 digest of the file (null terminated)
 * Return value :
 *     - 0 on match, non-zero on mis-match
*/
int mchp_sha256_validate( const char *path, unsigned const char *sha2);

#endif
