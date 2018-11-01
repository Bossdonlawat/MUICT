#include <stdio.h>

int find_abs(int a) {
  if (a < 0)
    return a * -1;
  else
    return a;
}

int main(int argc, char const *argv[])
{
  int x;
  printf("Enter a number: ");
  scanf("%d", &x);
  printf("The absolute value of %d is %d", x, find_abs(x));
  return 0;
}
