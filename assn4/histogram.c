//by 13cjcc submitted for CISC 220F assignment 4
#include <stdio.h>
#define LETTERS 6 //has an extra 0 value on end to make the printing for-loop simpler

void printHistogram(int letterGrades[LETTERS])
{
  int i;
  int max = 0;
  for(i = 0; i < LETTERS - 1; i++)
    if(letterGrades[i] > max)
      max = letterGrades[i];
  printf("\nGrade distribution:\n");
  char histHelper[LETTERS] = {' ',' ',' ',' ',' ',' '};
  int j; //i represents rows, j columns.
  for(i = max+1; i > 0; i--)
  {
    if(letterGrades[0] == i)
      histHelper[0] = '|'; //for the left side of the first column (A)
    for(j = 0; j < LETTERS; j++)
      if(letterGrades[j] == i || letterGrades[j-1] == i)
	histHelper[j] = '|'; //wall of right or left hand bars (grades B-D)
    if(letterGrades[LETTERS - 2] == i)
      histHelper[LETTERS - 1] = '|'; //right wall of rightmost bar (F)

    if(i == max + 1)
      printf("  "); //leave first line blank
    else
      printf("%d-", i); //y-axis numbering
    for (j = 0; j < LETTERS; j++)
    {
      printf("%c", histHelper[j]); //print lines on sides of bars
      if (letterGrades[j] == i - 1 || i == 1)
        printf("_"); //print bar caps/bottom line
      else
        printf(" "); //print bar's empty middle
    }
    printf("\n");
  }
  printf("   A B C D F\n");
}
