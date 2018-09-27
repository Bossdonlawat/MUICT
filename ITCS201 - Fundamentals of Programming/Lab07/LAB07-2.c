#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a[10], c;
  float b = 0;
  for (int i = 0 ; i < 10 ; i++) {
    scanf ("%d", &a[i]);
    if (a[i] < 0) {
      c = i;
      break;
    }
  }
  for (int i = 0 ; i < c ; i++)
      b += a[i];
  printf ("AVG = (");
  for (int i = 0 ; i < c ; i++) {
    printf ("%d", a[i]);
    if (i != c - 1)
      printf ("+");
  }
  printf (")/%d = %.1f", c, b / c);
  return 0;
}
