//by 13cjcc submitted for CISC 220F assignment 4
#include <stdio.h>
#define MAXGRADES 20

int readMarks(unsigned int grades[MAXGRADES])
{
  //scan in a list of ints from input and deposit them into grades array
  int numGrades = 0;
  int result;
  while((result = scanf("%u", &grades[numGrades])) == 1 && numGrades < MAXGRADES)
    numGrades++;
  if(result != 1 && result != EOF)
    return -1; //error
  else
    return numGrades;
}
