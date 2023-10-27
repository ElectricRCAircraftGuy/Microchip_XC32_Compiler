/* Test tcm attribute. */
/* { dg-do link } */
/* { dg-options "-mitcm=0x8000 -mdtcm=0x8000" } */
/* { dg-additional-options "-T ${srcdir}/gcc.target/pic32c/link-attr-tcm-1.ld " } */

int __attribute__((tcm)) weakfun1()
{
    return 0;
}

int __attribute__((tcm)) weakfun2()
{
    return 0;
}

volatile int __attribute__((tcm)) g_tcm_res = 0x200;

int main ()
{
  weakfun1();
  g_tcm_res = weakfun2();
 
  return 0;
}