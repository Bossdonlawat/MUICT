#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int a[3][4];
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0 ; j < 4 ; j++) {
      a[i][j] = rand() % 10;
    }
  }
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0 ; j < 4 ; j++) {
      printf ("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
