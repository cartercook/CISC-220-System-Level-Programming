//by 13cjcc submitted for CISC 220F assignment 4
#include <stdio.h>
#include <math.h>
#define MAXGRADES 20

//the last 4 params passed in are empty vars used to return values
void getStats(int grades[MAXGRADES], int numGrades, double *average, double *stdDeviation, int *min, int *max)
{
  *average = 0;
  int i;
  for(i = 0; i < numGrades; i++)
    *average += grades[i];
  *average = *average / numGrades;
  *stdDeviation = 0;
  *min = 100;
  *max = 0;
  for(i = 0; i < numGrades; i++)
  {
    *stdDeviation += (grades[i] - *average) * (grades[i] - *average); //there's no ^2 function :(
    if (grades[i] < *min)
      *min = grades[i];
    if (grades[i] > *max)
      *max = grades[i];
  }
  *stdDeviation = sqrt(*stdDeviation / (numGrades - 1));
}
