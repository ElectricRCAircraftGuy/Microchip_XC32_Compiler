/* Test asm output of fpu type.
   */

/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "*" } { "-mfpu=fpv5-d16" } } */
/* { dg-require-effective-target arm_fpv5_ok } */
/* { dg-add-options arm_fpv5 } */

void foo() {}

/* { dg-final { scan-assembler ".fpu fpv5-d16" } } */
