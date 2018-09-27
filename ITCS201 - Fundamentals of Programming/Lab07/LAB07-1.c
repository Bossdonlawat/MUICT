#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[5];
  for (int i = 0 ; i < 5 ; i++)
    scanf ("%d", &a[i]);
  printf ("SUM = %d", a[0] + a[2] + a[4]);
  return 0;
}
