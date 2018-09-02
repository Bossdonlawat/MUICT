#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a,b,c;
  int sum = 0; 
  scanf("%d %d %d", &a, &b, &c);
  if (a < 0 || b < 0 || c < 0 || a > 30 || b > 35 || c > 35) {
    printf("The score is invalid.");
  }
  else {
    printf("You have got: ");
    sum = a + b + c;
    if (sum >= 90) {
      printf("A");
    }
    else if (sum < 90 && sum >= 80) {
      printf("B");
    }
    else if (sum < 80 && sum >= 70) {
      printf("C");
    }
    else if (sum < 70 && sum >= 60) {
      printf("D");
    }
    else {
      printf("F");
    }
  }
  return 0;
}
