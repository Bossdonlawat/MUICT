#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  scanf("%d", &a);
  if (a > 0 && a <= 4) {
    printf("You have ordered: ");
    switch (a) {
      case 1:
        printf("Coke");
        break;
      case 2:
        printf("Est Cola");
        break;
      case 3:
        printf("Oishi green tea");
        break;
      case 4:
        printf("Sprite");
        break;
    }
  }
  else {
    printf("Invalid drink number!");
  }
  return 0;
}
