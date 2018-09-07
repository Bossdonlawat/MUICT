#include <stdio.h>

int main(int argc, char const *argv[])
{
  printf("Part No.\t Price\n");
  printf("T1267\t\t $%.2f\n", 6.34);
  printf("T1300\t\t $%.2f\n", 8.92);
  printf("T2401\t\t$%.2f\n", 65.40);
  printf("T4482\t\t$%.2f", 36.99);

  // This code is also works but without $
  // printf("%-10s %10s\n", "Part No.", "Price");
  // printf("%-10s %10.2f\n", "T1267", 6.34);
  // printf("%-10s %10.2f\n", "T1300", 8.92);
  // printf("%-10s %10.2f\n", "T2401", 65.40);
  // printf("%-10s %10.2f", "T4482", 36.99);

  // Original one that using string
  // printf("%-10s %10s\n", "Part No.", "Price");
  // printf("%-10s %10s\n", "T1267", "$6.34");
  // printf("%-10s %10s\n", "T1300", "$8.92");
  // printf("%-10s %10s\n", "T2401", "$65.40");
  // printf("%-10s %10s", "T4482", "$36.99");
  return 0;
}
