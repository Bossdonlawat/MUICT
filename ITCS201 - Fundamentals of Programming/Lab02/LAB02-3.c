#include <stdio.h>

int main(int argc, char const *argv[])
{
  int num1 = 5;
  int num2 = 8;
  float sum = num1 + num2;
  float avg = sum / 2;
  printf("num1=%d, num2=%d\nAVG=%.4f\nSUM=%.4f", num1, num2, avg, sum);
  return 0;
}
