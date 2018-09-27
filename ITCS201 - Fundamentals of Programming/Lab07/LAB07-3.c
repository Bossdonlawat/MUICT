#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[5];
  for (int i = 0 ; i < 5 ; i++)
    scanf ("%d", &a[i]);
  printf ("%d %d %d %d %d", a[4], a[2], a[1], a[3], a[0]);
  return 0;
}
