#include <stdio.h>

int main(int argc, char const *argv[])
{
  for (float i = 0 ; i <= 4 ; i += 0.5)
    printf ("Distance for %.1f hours is %.2f\n", i, i * 60);
  return 0;
}
