/* Test the unique_section attribute. */
/* { dg-do compile } */

/* { dg-final { scan-assembler "\.section\t\.bss\.i,bss" } } */
__attribute__((unique_section)) int i;

/* { dg-final { scan-assembler "\.section\t\.data\.j,data" } } */
__attribute__((unique_section)) int j = 42;

/* { dg-final { scan-assembler "\.section\t\.text\.f,code" } } */
__attribute__((unique_section)) void f(void){}

/* { dg-final { scan-assembler "\.section\t\.bss\.k\.\[0-9\]+,bss" } } */
void g(void) { static int k __attribute__((unique_section)); }
