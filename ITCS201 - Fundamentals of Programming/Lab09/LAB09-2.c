#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int a[3][4], b = 0;
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0 ; j < 4 ; j++) {
      a[i][j] = rand() % 10;
    }
  }
  // for (int i = 0 ; i < 3 ; i++) {
  //   for (int j = 0 ; j < 4 ; j++) {
  //     printf ("%d ", a[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("Sum of rows: ");
  for (int i = 0 ; i < 3 ; i++) {
    for (int j = 0 ; j < 4 ; j++) {
      b += a[i][j];
    }
    printf("%d ", b);
    b = 0;
  }
  printf("\nSum of columns: ");
  for (int i = 0 ; i < 4 ; i++) {
    for (int j = 0 ; j < 3 ; j++) {
      b += a[j][i];
    }
    printf("%d ", b);
    b = 0;
  }
  return 0;
}
