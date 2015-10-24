//by 13cjcc submitted for CISC 220F assignment 4
#include <stdio.h>
#include "readMarks.h"
#include "statistics.h"
#include "histogram.h"
#define MAXGRADES 20
#define LETTERS 6 //has an extra 0 value at end to help with printHistogram
int main()
{
  int i; //for-loop helper

  //start with readMarks.c
  unsigned int grades[MAXGRADES]; //positive values only
  int numGrades = readMarks(grades);
  if(numGrades < 2)
    return 1; //error, terminate program

  //some debug stuff I don't really understand
  #ifdef DEBUG
  printf("DEBUG: grades = {");
  for(i = 0; i < numGrades - 1; i++)
    printf("%d, ", grades[i]);
  printf("%d}\n", grades[MAXGRADES - 1]);
  #endif
  
  //pass the ball to statistics.c
  double average; double stdDeviation; int min; int max;
  getStats(grades, numGrades, &average, &stdDeviation, &min, &max);
  printf("number of marks: %d\naverage: %.2f\nstandard deviation: %.2f\nminimum: %d\nmaximum: %d\n", numGrades, average, stdDeviation, min, max);
  
  //now on to histogram.c
  int letterGrades[LETTERS] = {0}; //{A's, B's, C's, D's, F's, 0}
  for(i = 0; i < numGrades; i++)
  {
    if (grades[i] >= 80)
      letterGrades[0]++;
    else if (grades[i] >= 70 && grades[i] <= 79)
      letterGrades[1]++;
    else if (grades[i] >= 60 && grades[i] <= 69)
      letterGrades[2]++;
    else if (grades[i] >= 50 && grades[i] <= 59)
      letterGrades[3]++;
    else if (grades[i] <= 49)
      letterGrades[4]++;
  }

  //additional debug
  #ifdef DEBUG
  printf("DEBUG: letterGrades = {");
  for (i = 0; i < LETTERS - 1; i++)
    printf("%d, ", letterGrades[i]);
  printf("%d}\n", letterGrades[LETTERS - 1]);
  #endif

  printHistogram(letterGrades);
  return 0;
}
