#include <stdio.h>

int main(int argc, char const *argv[])
{
  double number;
  goto input;

  input:
    printf("Enter a number:");
    scanf("%lf",&number);
    goto check;
  check:
    if(number < 0.0) {
      printf("number is negative");
      goto input;
    }
    else {
      printf("number is positive");
    }
  return 0;
}

// goto can jump from staements to another statemens.
// for example, in label `check` if number is negative. normally code will work from up to bottom (except any code with async) but `goto input` will turn code statement back to line 8 again