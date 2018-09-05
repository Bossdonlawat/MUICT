#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a, b = 0, c = 0, d = 0;
  scanf("%d", &a);
  if (a % 100 != 0) {
    printf("Sorry.. the amounts you insert are not possible to withdrawn");
  }
  else {
    b = a / 1000;
    c = (a - (b * 1000)) / 500;
    d = (a - (b * 1000) - (c * 500)) / 100;
    printf("Summary of banknotes:\n%d notes of 1000 bath\n%d notes of 500 bath\n%d notes of 100 bath", b, c, d);
  }
  return 0;
}
