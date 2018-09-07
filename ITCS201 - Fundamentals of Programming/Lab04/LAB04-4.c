#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  scanf("%d", &a);
  if (a > 0 && a <= 4)
    printf("You have ordered: %s", (a == 1) ? "Coke" : ((a == 2) ? "Est Cola" : ((a == 3) ? "Oishi green tea" : "Sprite")));
  else
    printf("Invalid drink number!");
  return 0;
}
