#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int check(int a, int b) {
  if (a == b)
    return 0;
  else if (a > b)
    return 1; //TOO LOW
  else
    return -1; //TOO HIGH
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int x;
  int r = 1 + rand() % 100;
  for (int i = 6 ; i >= 0 ; i--) {
    printf("Enter your guess: ");
    scanf("%d", &x);
    if (check(r, x) == 0) {
      printf("Hooray, you have won!");
      break;
    }
    else if(check(r, x) == 1) {
      printf("Wrong number :( Your guess was too low.\nYou have %d guesses left. Try again.\n", i);
    }
    else {
      printf("Wrong number :( Your guess was too high.\nYou have %d guesses left. Try again.\n", i);
    }
  }
  return 0;
}
