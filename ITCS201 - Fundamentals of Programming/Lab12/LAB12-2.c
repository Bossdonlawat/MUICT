#include <stdio.h>

void swap(int *a, int *b);

void sort_nums(int *a, int *b, int *c);

int main(int argc, char const *argv[])
{
  int a, b, c;
  printf("Enter 3 integers: ");
  scanf("%d %d %d", &a, &b, &c);
  sort_nums(&a, &b, &c);
  printf("Sorted integers: %d %d %d", a, b, c);
  return 0;
}

void sort_nums(int *a, int *b, int *c) {
  if (*a < *c)
    swap(a, c);
  if (*a < *b)
    swap(a, b);
  if (*b < *c)
    swap(b, c);
}

void swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}