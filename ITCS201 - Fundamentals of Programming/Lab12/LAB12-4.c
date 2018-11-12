#include <stdio.h>

float findMean(int *a) {
  return (*a + *(a + 1) + *(a + 2) + *(a + 3) + *(a + 4)) / 5.0;
}

int findMin(int *a) {
  int min = 999999999;
  for(int i = 0 ; i < 5 ; i++) {
    if(min > *(a + i))
      min = *(a + i);
  }
  return min;
}

int findMax(int *a) {
  int max = -999999999;
  for(int i = 0 ; i < 5 ; i++) {
    if(max < *(a + i))
      max = *(a + i);
  }
  return max;
}

int main(int argc, char const *argv[])
{
  int num[5];
  printf("Enter 5 integers: ");
  for(int i = 0 ; i < 5 ; i++)
    scanf("%d", &num[i]);
  printf("Mean: %.3f\nMin: %d\nMax: %d\nRange: %d", findMean(num), findMin(num), findMax(num), findMax(num) - findMin(num));
  return 0;
}
