/* check for expected multilib path */
/* { dg-do compile } */
/* { dg-require-effective-target xc32_device_fpu_ok } */
/* { dg-skip-if "" { *-*-* } { "-mfloat-abi=*" } { "" } } */
/* { dg-additional-options "-mfloat-abi=soft --print-multi-directory" } */
/* { dg-bogus ".*(hard|softfp).*" "" { target pic32c-*-* } {0} } */
/* { dg-excess-errors "" } */
