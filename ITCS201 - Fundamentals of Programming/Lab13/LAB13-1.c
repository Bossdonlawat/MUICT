#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  struct {
    char n[80];
    char p[10];
  } a[2];

  char o[10];
  
  printf("Enter name#1: ");
  scanf("%s", a[0].n);
  printf("Enter phone#1: ");
  scanf("%s", a[0].p);

  printf("Enter name#2: ");
  scanf("%s", a[1].n);
  printf("Enter phone#2: ");
  scanf("%s", a[1].p);

  printf("Sort by: ");
  scanf("%s", o);

  if(strcmp("phone", o) == 0) {
    if(strcmp(a[0].p, a[1].p) < 0)
      printf("%s %s\n%s %s", a[0].n, a[0].p, a[1].n, a[1].p);
    else
      printf("%s %s\n%s %s", a[1].n, a[1].p, a[0].n, a[0].p);
  }
  else {
    if(strcmp(a[0].n, a[1].n) < 0)
      printf("%s %s\n%s %s", a[0].n, a[0].p, a[1].n, a[1].p);
    else
      printf("%s %s\n%s %s", a[1].n, a[1].p, a[0].n, a[0].p);
  }

  return 0;
}
