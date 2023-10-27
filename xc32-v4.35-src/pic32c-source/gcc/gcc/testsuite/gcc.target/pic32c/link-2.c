/* { dg-do link } */
/* { dg-additional-options "-T ${srcdir}/gcc.target/pic32c/link-2.ld " } */

#include <inttypes.h>

extern uint32_t __stack_start__;
extern uint32_t __exidx_start;

volatile unsigned long Testresult = 4242;


void  foo()
{
        Testresult = 4242;
        Testresult = 4242;

        return;
}

void  bar( int i)
{
        Testresult = 0;
        Testresult = 0;
        if(__stack_start__)  Testresult = 4;
        if(__exidx_start)  Testresult = 5;
}



int main() { foo();bar(6);return 0; }
