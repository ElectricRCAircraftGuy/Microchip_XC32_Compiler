/* Test asm output of fpu type.
   */
/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-mfpu=*" "-mfloat-abi=soft" } { "" } } */
/* { dg-require-effective-target xc32_device_fpu_dp_ok } */

void foo() {}

/* { dg-final { scan-assembler ".fpu fpv5-d16" } } */
