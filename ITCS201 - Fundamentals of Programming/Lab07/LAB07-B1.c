#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[5] = {5, 4, 3, 2, 1}, b[5];
  for (int i = 0 ; i < 5 ; i++)
    a[i] = i + 1;
  for (int i = 0 ; i < 5 ; i++)
    a[i] = b[i];
  for (int i = 5 ; i >= 0 ; i--)
    printf ("%d ", b[i]);
  return 0;
}
