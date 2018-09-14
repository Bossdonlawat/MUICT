#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a = 0;
  while (scanf ("%d", &a) != EOF) {
    printf ("%-3d |", a);
    for (int i = 0 ; i < a ; i++)
      printf ("*");
    printf ("\n");
  }
  return 0;
}
