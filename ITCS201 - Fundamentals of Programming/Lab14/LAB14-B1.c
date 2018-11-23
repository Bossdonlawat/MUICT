#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   double c[100000];
   int i = 0;
  FILE *inFile;
  FILE *outFile;
  inFile = fopen("f.txt", "r");
  if (inFile == NULL) {
    printf("Failed to open the file.\n");
    exit(1);
  }
  while (fscanf(inFile, "%lf", &c[i]) != EOF)
  {
    c[i] = (c[i] - 32) * 5 / 9;
    i++;
  }
  fclose(inFile);
  printf("Converting from F to C ...\n");
  outFile = fopen("c.txt", "a");
  for(int j = 0 ; j < i ; j++) {
    printf("%.2lf\n", c[j]);
    fprintf(outFile, "%.2lf\n", c[j]);
  }
  fclose(outFile);
  return 0;
}
