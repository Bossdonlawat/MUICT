#include <stdio.h>
#include <math.h>

double euc_dist(double a, double b, double c, double d) {
  return sqrt(((b - a) * (b - a)) + ((d - c) * (d - c)));
}

int main(int argc, char const *argv[])
{
  double x1, x2, y1, y2;
  printf("Please enter a value for x1: ");
  scanf("%lf", &x1);
  printf("Please enter a value for y1: ");
  scanf("%lf", &x2);
  printf("Please enter a value for x2: ");
  scanf("%lf", &y1);
  printf("Please enter a value for y2: ");
  scanf("%lf", &y2);
  printf("The distance between the points is: %lf", euc_dist(x1, x2, y1, y2));
  return 0;
}
