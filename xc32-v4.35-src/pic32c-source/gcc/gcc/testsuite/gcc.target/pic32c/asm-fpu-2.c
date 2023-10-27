/* Test asm output of fpu type.
   */

/* { dg-do compile } */
/* { dg-require-effective-target arm_fpv4_sp_ok } */
/* { dg-skip-if "" { *-*-* } { "*" } { "-mfpu=fpv4-sp-d16" } } */
/* { dg-add-options arm_fpv4_sp } */

void foo() {}

/* { dg-final { scan-assembler ".fpu fpv4-sp-d16" } } */
