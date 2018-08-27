#include <stdio.h>

int main(int argc, char const *argv[])
{
  float me = 59.5;
  float you = 55.6;
  float avg = (me + you) /2;
  printf("My weight is %.2f\nYou weight are %.2f\n\tWe are around %.2f", me, you, avg);
  return 0;
}
