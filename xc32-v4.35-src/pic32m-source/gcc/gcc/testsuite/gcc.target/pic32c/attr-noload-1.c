/* Test the noload attribute. */
/* { dg-do compile } */

/* { dg-final { scan-assembler "\.section\t\.bss\.i,bss,noload" } } */
__attribute__((noload)) int i;

/* { dg-final { scan-assembler "\.section\t\.data\.j,data,noload" } } */
/* { dg-warning "Noload variable 'j' will not be initialized" "" { target *-*-* } 9 } */
__attribute__((noload)) int j = 42; 

/* { dg-final { scan-assembler "\.section\t\.text\.f,code,noload" } } */
__attribute__((noload)) void f(void){}

/* { dg-final { scan-assembler "\.section\t\.bss\.k\.\[0-9\]+,bss,noload" } } */
void g(void) { static int k __attribute__((noload)); }
