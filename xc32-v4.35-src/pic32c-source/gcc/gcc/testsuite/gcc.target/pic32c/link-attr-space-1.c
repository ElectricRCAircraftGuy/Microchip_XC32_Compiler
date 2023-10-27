/* Test space attribute (RAMFUNC). */
/* { dg-do link } */

/* FIXME: remove long_call once it is added by default with space(data) */
int __attribute__((space(data),long_call)) fn_in_ram()
{
    return 0;
}

int main()
{
  volatile int x = fn_in_ram();
  return 0;
}
