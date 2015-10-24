//written by 13cjcc and 12twgf for CISC 220 assignment 5
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int countSpaces(char theString[])
{
  int spaces = 0;
  int i;
  for(i=0; theString[i] != '\0'; i++)
    if(theString[i] == ' ')
      spaces++;
  return spaces;
}

char** splitString(char theString[], int *arraySize)
{
  /*
   * an array of pointers that each point an array of char. we use sizeof(char) because
   * we know that each pointer points to index [0] of its respective array.
   */
  char **words = malloc(sizeof(char *) * (countSpaces(theString) + 1));
  
  int wordLen = 0; //length of current word, use strIndex - wordLen to get first char in the word
  int strIndex = -1; //basically i iterating through length of theString[]
  int wordIndex = 0; //the current word, stating from zero and ending at countSpaces + 1
  
  do
  {
    strIndex++;
    if (theString[strIndex] == ' ' || theString[strIndex] == '\0')
    {
      words[wordIndex] = malloc(sizeof(char) * (wordLen + 1)); //grab the required space for the word
      strncpy(words[wordIndex], &theString[strIndex - wordLen], wordLen); //theString[strIndex-wordLen] is the first char of the word, converted to a pointer by &
      words[wordIndex][wordLen] = '\0'; //add the escape character
      printf("wordLen: %d, strIndex: %d, wordIndex: %d, word: %s\n", wordLen, strIndex, wordIndex, words[wordIndex]);
      wordIndex++; //move on to the next pointer in words array
      wordLen = 0; //ready for a new word
    }
    else
      wordLen++;
  } while (theString[strIndex] != '\0');
  
  *arraySize = wordIndex;
  return words;
}

void cleanup(char *words[], int numWords)
{
  int i;
  for (i=0; i < numWords; i++)
    free(words[i]);
  free(words);
}
