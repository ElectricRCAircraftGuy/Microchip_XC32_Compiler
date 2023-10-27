int _result = 4242;

#define abort(n)                                                               \
  do                                                                           \
    {                                                                          \
      _result = 4242;                                                          \
      _abort ();                                                               \
    }                                                                          \
  while (0)

void _abort()
{
    _result = 4242;
    while(1);
}

#define exit(n)                                                                \
  do                                                                           \
    {                                                                          \
      _result = n;                                                             \
      _exit (n);                                                               \
    }                                                                          \
  while (0)

void _exit(int i)
{
    while(1);
}
