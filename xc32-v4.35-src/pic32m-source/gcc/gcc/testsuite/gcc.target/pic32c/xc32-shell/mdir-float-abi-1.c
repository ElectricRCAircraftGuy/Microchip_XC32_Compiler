/* check for expected multilib path */
/* { dg-do compile } */
/* { dg-require-effective-target xc32_device_fpu_ok } */
/* { dg-skip-if "" { *-*-* } { "-mfloat-abi=*" } { "" } } */
/* { dg-additional-options "--print-multi-directory" } */
/* { dg-message ".*hard.*" "" { target pic32c-*-* } {0} } */
/* { dg-bogus ".*hard.*" "" { target pic32c-*-* } {0} } */
