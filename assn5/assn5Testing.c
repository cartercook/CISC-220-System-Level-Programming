/*
 * This module is for testing your solutions to Assignment 5.
 * Please don't waste server space by handing it in.  We will 
 * use a slightly different testing module, to make sure your
 * funtions aren't specifically tailored to these test cases.
 * Feel free to try additional testing of your own.
 * 
 * CISC 220, Fall 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// heapReport.h contains a header for a heapReport function which 
// tells you how much heap space your program is currently using
#include "heapReport.h"
// assn5.h contains headers for the functions to be written by
// students for Assigment 5
#include "assn5Functions.h"


/*
 * Displays an array of words as returned by splitString
 */
void displayWords(char *wordArray[], int numWords) {
  // The enclosing if statement is here so that when the program is
  // run with the stub version of splitString this function will
  // do nothing instead of crashing with a null pointer.
  // Student don't need to change this function.
  if (wordArray != NULL) {
    int i;
    for (i = 0; i < numWords; i++)
      printf("%i. %s\n", i, wordArray[i]);
  } // end for
} // end displayWords


int main() {
  printf("TESTING countSpaces:--------------\n");
  printf("should be 3: %d\n", countSpaces("one two three four")); 
  printf("should be 11: %d\n", countSpaces("  a     b   c ")); // should print 11
  printf("should be 0: %d\n", countSpaces("singleword")); // should print 0
  printf("----------------------------------\n");

  printf("Before any calls to malloc: ");  heapReport();

  #define NUM_SENTENCES 5  
  char *hamlet[] = {"Give every man thy ear, but few thy voice",
		    "Neither a borrower nor a lender be",
		    "For loan oft loses both itself and friend",
		    "And borrowing dulls the edge of husbandry",
		    "This above all: to thine own self be true"};
  int i;
  for (i = 0; i < NUM_SENTENCES; i++) {
    int size;
    char **words = splitString(hamlet[i], &size);
    displayWords(words, size);
    printf("before cleaning up space for this sentence: "); heapReport();
    cleanup(words, size);
    printf("after cleaning up space: "); heapReport();
    printf("\n");
  }

  printf("end of program: "); heapReport();

  return 0;
} // end main
