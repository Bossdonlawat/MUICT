#include <stdio.h>

int main(int argc, char const *argv[])
{
  float a;
  char b;
  scanf("%f %c", &a, &b);
  if (b == 99) {
    printf("%.2f cm = %.2f inch", a, a / 2.54);
  }
  else if(b == 105) {
    printf("%.2f inch = %.2f cm", a, a * 2.54);
  }
  return 0;
}
