#include <stdio.h>

int main(int argc, char const *argv[])
{
  float a, b;
  char c;
  printf("Select an operator either (+,-,*,/) ");
  scanf("%c", &c);
  printf("Enter two numbers: ");
  scanf("%f %f", &a, &b);
  switch (c) {
    case 43: //+
      printf("%.1f %c %.1f = %.1f", a, 43, b , a + b);
      break;
    case 45: //-
      printf("%.1f %c %.1f = %.1f", a, 45, b , a - b);
      break;
    case 42: //*
      printf("%.1f %c %.1f = %.1f", a, 42, b , a * b);
      break;
    case 47: ///
      printf("%.1f %c %.1f = %.1f", a, 47, b , a / b);
      break;
    default:
      printf("Invalid operaters");
  }
  return 0;
}
