#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  printf ("Enter a number of row: ");
  scanf ("%d", &a);
  for (int i = a ; i > 0 ; i--) {
    for (int j = i ; j > 0 ; j--) {
      printf ("%d", j);
    }
    printf ("\n");
  }
  return 0;
}
