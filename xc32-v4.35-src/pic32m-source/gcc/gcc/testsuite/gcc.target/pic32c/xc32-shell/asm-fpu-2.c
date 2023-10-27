/* Test asm output of fpu type.
   */
/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-mfpu=*" "-mfloat-abi=soft" } { "" } } */
/* { dg-require-effective-target xc32_device_fpu_sp_ok } */

void foo() {}

/* { dg-final { scan-assembler ".fpu fpv4-sp-16" } } */
