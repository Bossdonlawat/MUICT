#include <stdio.h>

int check(int a, float b, double c) {
  printf("The integer is %d\nThe floating point number is %f\nThe double precision number is %lf", a, b, c);
  return 0;
}

int main(int argc, char const *argv[])
{
  int x;
  float y;
  double z;
  printf("Enter an integer: ");
  scanf("%d", &x);
  printf("Enter a floating point number: ");
  scanf("%f", &y);
  printf("Enter a double precision number: ");
  scanf("%lf", &z);
  check(x, y, z);
  return 0;
}
