/* check for expected multilib path */
/* { dg-do compile } */
/* { dg-require-effective-target xc32_device_fpu_ok } */
/* { dg-skip-if "" { *-*-* } { "-mfloat-abi=*" } { "" } } */
/* { dg-additional-options "-mfloat-abi=softfp --print-multi-directory" } */
/* { dg-message ".*softfp.*" "" { target pic32c-*-* } {0} } */
/* { dg-bogus ".*softfp.*" "" { target pic32c-*-* } {0} } */
