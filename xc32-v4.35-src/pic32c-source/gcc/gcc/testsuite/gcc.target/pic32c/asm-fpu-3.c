/* Test asm output of fpu type.
   */

/* { dg-do compile } */
/* { dg-require-effective-target arm_vfp3_ok } */
/* { dg-skip-if "" { *-*-* } { "*" } { "-mfpu=vfp*3*" } } */
/* { dg-add-options arm_vfp3 } */

void foo() {}

/* { dg-final { scan-assembler ".fpu vfpv3-d16" } } */
