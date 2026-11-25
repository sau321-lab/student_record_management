#include<stdio.h>
struct Student
{
 int rollNo;
 char name[50];
 float marks;
};
int main()
{
 FILE *fp;
 struct Student s;
 int choice;
 do
 {
  printf("\n--- STUDENT DATABASE ---\n");
  printf("1. Add Student\n");

  printf("2. Display Students\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
  if (scanf("%d", &choice) != 1)
  {
   choice = -1;
  }
  while (getchar() != '\n')
  {
  }
  switch (choice)
  {
   case 1:
   fp = fopen("students.txt", "a");
   if (fp == NULL)
   {
    printf("Unable to open file.\n");
    break;
   }
   printf("Enter Roll Number: ");
   if (scanf("%d", &s.rollNo) != 1)
   {
    printf("Invalid roll number.\n");
    while (getchar() != '\n')
    {
    }
    fclose(fp);
    break;
   }
   while (getchar() != '\n')
   {
   }
   printf("Enter Name: ");
   scanf("%49[^\n]", s.name);
   while (getchar() != '\n')
   {
   }
   printf("Enter Marks: ");
   if (scanf("%f", &s.marks) != 1)
   {
    printf("Invalid marks.\n");
    while (getchar() != '\n')
    {
    }
    fclose(fp);
    break;
   }
   while (getchar() != '\n')
   {
   }
   fprintf(fp, "%d|%s|%.2f\n", s.rollNo, s.name, s.marks);
   fclose(fp);
   printf("Record saved successfully.\n");
   break;

   case 2:
   fp = fopen("students.txt", "r");
   if (fp == NULL)
   {
    printf("No records found.\n");
    break;
   }
   char line[160];
   printf("\n--- STUDENT RECORDS ---\n");
   while (fgets(line, sizeof line, fp) != NULL)
   {
    if (sscanf(line, "%d|%49[^|]|%f", &s.rollNo, s.name, &s.marks) == 3)
    {
     printf("\nRoll No : %d", s.rollNo);
     printf("\nName : %s", s.name);
     printf("\nMarks : %.2f\n", s.marks);
    }
   }
   fclose(fp);
   break;

   case 3:
   printf("Program terminated.\n");
   break;

   default:
   printf("Invalid choice.\n");
   break;
  }
 } while (choice != 3);
 return 0;
}