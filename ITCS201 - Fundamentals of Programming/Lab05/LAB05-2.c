#include <stdio.h>

int main(int argc, char const *argv[])
{
  int i = 125;
  while (i >= 5) {
    if (i % 25 != 0) {
      printf ("%d ", i);
    }
    i -= 10;
  }
  return 0;
}
