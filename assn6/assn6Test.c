/* 
 * Sample testing program for Assignment 6.  Your linkedList.c file will
 * be tested with different code.
 * CISC 220, Fall 2014
 * M. Lamb
 */

#include "heapReport.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("start of program: "); heapReport();
  
  FILE *inputFile = openInputFile("input.txt");
  FILE *outputFile = openOutputFile("output.txt");

  LinkedList list;

  // Read 10 integers from the input file, adding them
  // alternately to the beginning and end of the list.
  // After each change to the list, write the contents of the
  // list to the output file.

  fprintf(outputFile, "CREATING LIST:\n");
  int count;
  for (count = 1; count <= 5; count++) {
    list = readAndAddToStart(list, inputFile);
    printList(list, outputFile);
    list = readAndAddToEnd(list, inputFile);
    printList(list, outputFile);
  } // end for

  // Show heap space used on standard input
  printf("after creating list: "); heapReport();

  fprintf(outputFile, "\nWHILE DELETING FROM LIST:\n");
  int start = 1; // 1 (true) means addint to start
  while (list != NULL) {
    if (start) 
      list = deleteFirst(list);
    else
      list = deleteLast(list);
    start = !start;
    printList(list, outputFile);
  } // end for

  // Show heap space again; if delete functions have freed space
  // it should be zero.
  printf("after emptying list: "); heapReport();

  fclose(inputFile);
  fclose(outputFile);
  printf("after closing files: "); heapReport();


  return 0;
} // end main
