#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a, b, i, j;
  while (a != b) {
    printf ("Enter the number of rows and columns: ");
    scanf ("%d %d", &a, &b);
    if (a != b) {
      printf ("The matrix must be a square matrix.\n");
    }
  }
  int c[a][b], d[a][b];
  for (i = 0 ; i < a ; i++) {
    for (j = 0 ; j < b ; j++) {
      printf ("Enter element %d,%d: ", i, j);
      scanf ("%d", &c[i][j]);
    }
  }
  for (i = 0 ; i < a ; i++)
    for (j = 0 ; j < b ; j++)
      d[i][j] = c[j][i];
  for (i = 0 ; i < a ; i++) {
    for (j = 0 ; j < b ; j++) {
      if (c[i][j] != d[i][j])
        break;
    }
    if (j != b)
      break;
  }
  if (j == b)
    printf ("The matrix is symmetric.\n");
  else
    printf ("The matrix is not symmetric.\n");
  return 0;
}
