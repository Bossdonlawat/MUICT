#include <stdio.h>
#include <limits.h>

int maxthis(int a, int b) {
  switch ((a > b) - (a < b)) {
    case -1:
      return b;
    case 1:
      return a;
    default:
      return a;
  }
}

int main(int argc, char const *argv[])
{
  int a, b, c;
  int max = INT_MIN;
  scanf("%d %d %d",&a, &b, &c);
  max = maxthis(a , maxthis(b ,c));
  printf("Max number is %d", max);
  return 0;
}
