#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  struct monster
  {
    char name[80];
    int attack;
    int hp;
  };
  struct monster monsters[3] = {
    { "bone", 20, 50 },
    { "snot", 30, 100 },
    { "plague", 50, 70 }
  };
  char a[10];
  int p, h = 100;
  while(monsters[0].hp != 0 || monsters[1].hp != 0 || monsters[2].hp != 0) {
    printf("Enter the monster's name: ");
    scanf("%s", a);
    printf("Enter attack power from 1 to 100: ");
    scanf("%d", &p);
    if(strcmp("bone", a) == 0) {
      if(monsters[0].hp - p <= 0)
        monsters[0].hp = 0;
      else {
        monsters[0].hp -= p;
        h -= monsters[0].attack;
      }
      printf("Monster: %s\nHP: %d\n", monsters[0].name, monsters[0].hp);
    }
    else if(strcmp("snot", a) == 0) {
      if(monsters[1].hp - p <= 0)
        monsters[1].hp = 0;
      else {
        monsters[1].hp -= p;
        h -= monsters[1].attack;
      }
      printf("Monster: %s\nHP: %d\n", monsters[1].name, monsters[1].hp);
    }
    else if(strcmp("plague", a) == 0) {
      if(monsters[2].hp - p <= 0)
        monsters[2].hp = 0;
      else {
        monsters[2].hp -= p;
        h -= monsters[2].attack;
      }
      printf("Monster: %s\nHP: %d\n", monsters[2].name, monsters[2].hp);
    }

    printf("Your HP: %d\n", h);

    if(h <= 0)
      break;
    else if(monsters[0].hp == 0 && monsters[1].hp == 0 && monsters[2].hp == 0) {
      printf("You won");
      break;
    }
  }
  return 0;
}
