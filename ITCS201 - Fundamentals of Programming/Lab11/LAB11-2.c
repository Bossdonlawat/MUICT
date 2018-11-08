#include <stdio.h>
int DATA[8] = {1, 0, 2, 6, 7, 5, 4, 3};
int found_idx = -1;
int i = 0;

// The program has 2 spot problem
// 1. search_for() function that being called by main() do nothing: fix by commenting old one out and mve search_for() from below to above main()
// 2. search_for() function has decleared found_idx which overide variable inside funtion itslef fix by commeting out

// void search_for(int target);
void search_for(int target)
{
  // int found_idx = -1;
  for (int i = 0; i < 8; i++)
  {
    if (DATA[i] == target)
    {
      found_idx = i;
      break;
    }
  }
}
int main()
{
  int target = 6;
  i = 7;
  search_for(target);
  if (found_idx != -1)
  {
    printf("Found the value %d at the index: %d\n", target, found_idx);
  }
  else
  {
    printf("Cannot find the value %d in the data\n", target);
  }
  return 0;
}