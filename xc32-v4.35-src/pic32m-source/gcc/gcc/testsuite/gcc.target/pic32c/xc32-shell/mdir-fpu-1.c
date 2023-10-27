/* check for expected multilib path */
/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-mfpu=*" "-mfloat-abi=soft" } { "" } } */
/* { dg-require-effective-target xc32_device_fpu_dp_ok } */
/* { dg-additional-options "--print-multi-directory" } */
/* { dg-message ".*fpv5.*" "" { target pic32c-*-* } {0} } */
/* { dg-bogus ".*fpv5.*" "" { target pic32c-*-* } {0} } */
