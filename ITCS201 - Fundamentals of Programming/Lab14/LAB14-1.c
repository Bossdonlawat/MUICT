#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   struct {
     int studentid;
     char studentname[80];
     struct {
       int studentday;
       int studentmonth;
       int studentyear;
     } birthdate;
  } student;
  FILE *inFile;
  FILE *outFile;
  inFile = fopen("student.txt", "r");
  if (inFile == NULL) {
    printf("Failed to open the file.\n");
    exit(1);
  }
  while (fscanf(inFile, "%d %s %d %d %d", &student.studentid, student.studentname, &student.birthdate.studentday, &student.birthdate.studentmonth, &student.birthdate.studentyear) != EOF)
  {
    printf("Read %d %s %d %d %d\n", student.studentid, student.studentname, student.birthdate.studentday, student.birthdate.studentmonth, student.birthdate.studentyear);
  }
  fclose(inFile);
  outFile = fopen("student_age.txt", "a");
  fprintf(outFile, "Student ID: %d\nName: %s\nBirthdate: %d/%d/%d\nAge: %d\n", student.studentid, student.studentname, student.birthdate.studentday, student.birthdate.studentmonth, student.birthdate.studentyear);
  printf("Saved to: student_age.txt");
  fclose(outFile);
  return 0;
}
