#include <stdio.h>

int main(int argc, char const *argv[])
{
  printf("%-10s %10s\n", "Part No.", "Price");
  printf("%-10s %10s\n", "T1267", "$6.34");
  printf("%-10s %10s\n", "T1300", "$8.92");
  printf("%-10s %10s\n", "T2401", "$65.40");
  printf("%-10s %10s", "T4482", "$36.99");
  return 0;
}
