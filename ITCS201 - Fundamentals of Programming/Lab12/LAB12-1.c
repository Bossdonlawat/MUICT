#include <stdio.h>

int main(int argc, char const *argv[])
{
  int boneHP = 50;
  int snotHP = 100;
  int plagueHP = 70;
  char a;
  int b;
  printf("Enter the 1st character of Monster's name: ");
  scanf("%c", &a);
  printf("Enter the attack power from 1 to 100: ");
  scanf("%d", &b);
  int *current_monsterHP;
  switch(a) {
    case 98:
      current_monsterHP = &boneHP;
    case 115:
      current_monsterHP = &snotHP;
    case 112:
      current_monsterHP = &plagueHP;
  }
  printf("Current HP: %d\n", *current_monsterHP);
  printf("Attack power: %d\n", b);
  if(*current_monsterHP - b < 0)
    *current_monsterHP = 0;
  else
    *current_monsterHP -= b;
  printf("Remaining HP: %d", *current_monsterHP);
  return 0;
}
