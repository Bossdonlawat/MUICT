#include <stdio.h>

int main(int argc, char const *argv[])
{
  int b, d = 0;
  float e = 0, f = 0;
  char a[1000], c[1000];
  printf("Input Customer ID:");
  scanf("%s", &a);
  printf("Input the name of the customer:");
  scanf("%s", &c);
  printf("Input the unit(mins) consumed by the customer:");
  scanf("%d", &b);
  
  // while (b != d) {
  //   if (d < 100) {
  //     e += 1;
  //   }
  //   else if (d >= 100 && d < 300) {
  //     e += 0.75;
  //   }
  //   else if (d >= 300 && d < 600) {
  //     e += 0.50;
  //   }
  //   else {
  //     e += 0.25;
  //   }
  //   d++;
  // }

  if (b >= 600) {
    e = 400 + ((600 - b) * 0.25);
  }
  else if (b >= 300 && b < 600) {
    e = 250 + ((b - 300) * 0.5);
  }
  else if (b >= 100 && b < 300) {
    e = 100 + ((b - 100) * 0.75);
  }
  else {
    e = b;
  }

  if (e > 300)
    f = e * 0.15;

  printf("\nTelephone Bill\n");
  printf("Customer ID NO\t\t\t:%s\n", a);
  printf("Customer Name\t\t\t:%s\n", c);
  printf("Unit Consumed (Mins)\t\t:%d\n", b);
  if (f == 0)
    printf("Surcharge Amount (15)\t\t:0.00\n");
  else
    printf("Surcharge Amount\t\t:%.2f\n", f);
  printf("Net Amount Paid\t\t\t:%.2f", e + f);
  return 0;
}
