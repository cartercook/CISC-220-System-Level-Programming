//by 13cjcc and 12twgf for CISC 220 assignment 6
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * TODO:make new linkedLists->next = NULL
 * add errno check to openInputFile
 * CLOSE FILES
 */

/* 
 * Parameter: a file name
 * Opens the named file for input and returns a pointer to the file.
 * If the file can't be opened, writes a descriptive error message and exits the
 * program.  So the caller can assume that if this function returns it
 * will be returning a valid file pointer that may be used for reading.
 */
FILE* openInputFile(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("could not open file for reading");
    exit(1);
  }
  return file;
}

/* 
 * Parameter: a file name
 * Opens the named file for output and returns a pointer to the file.
 * If the file can't be opened, writes a descriptive error message and exits the
 * program.  So the caller can assume that if this function returns it
 * will be returning a valid file pointer that may be used for writing.
 */
FILE* openOutputFile(char *filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    perror("could not open file for writing");
    exit(1);
  }
  return file;
}

/*
 * Parameters: a linked list of numbers and a file that should be open for input.
 * Reads an integer from the file (skipping white space first) and adds it to
 * to the start of the linked list, returning a pointer to the modified list.
 */
LinkedList readAndAddToStart(LinkedList list, FILE *inputFile) {
  int numRead;
  if (fscanf(inputFile, "%d", &numRead) != 1) {
    if (feof(inputFile))
      fprintf(stderr, "cannot read past end of file\n");
    else
      fprintf(stderr, "could not read integer from file\n");
    exit(1);
  }
  LinkedList newHead = malloc(sizeof(LinkedList));
  newHead->data = numRead; // (struct *ListNode).data == LinkedList->data
  newHead->next = list;
  return newHead;
}

/*
 * Parameters: a linked list of numbers and a file that should be open for input.
 * Reads an integer from the file (skipping white space first) and adds it to
 * to the end of the linked list, returning a pointer to the modified list.
 */
LinkedList readAndAddToEnd(LinkedList list, FILE *inputFile) {
  if (list == NULL)
    return readAndAddToStart(list, inputFile);
  int numRead;
  if (fscanf(inputFile, "%d", &numRead) != 1) {
    if (feof(inputFile))
      fprintf(stderr, "cannot read past end of file\n");
    else
      fprintf(stderr, "could not read integer from file\n");
    exit(1);
  }
  LinkedList newHead = list;
  while (newHead->next != NULL)
    newHead = newHead->next;
  newHead->next = malloc(sizeof(LinkedList));
  newHead = newHead->next;
  newHead->data = numRead;
  newHead->next = NULL;
  return list;
}

/*
 * Parameters: a linked list of numbers
 * Deletes the first element of the list and returns a pointer to the
 * modified list.  If the list is empty, does not change the list, but
 * returns a pointer to the unmodified list.
 */
LinkedList deleteFirst(LinkedList list) {
  if (list == NULL) {
    fprintf(stderr, "attempt to delete node where none exists\n");
    return NULL;
  }
  LinkedList newHead = list->next;
  free(list);
  list = NULL;
  return newHead;
}

/*
 * Parameters: a linked list of numbers
 * Deletes the last element of the list and returns a pointer to the
 * modified list.  If the list is empty, does not change the list, but
 * returns a pointer to the unmodified list.
 */
LinkedList deleteLast(LinkedList list) {
  if (list == NULL || list->next == NULL)
    return deleteFirst(list);
  LinkedList tail = list;
  while (tail->next->next != NULL)
    tail = tail->next;
  free(tail->next);
  tail->next = NULL;
  return list;
}

/*
 * Parameters: a linked list of numbers and a file that should be open for output.
 * Prints the list to the file in a format like this: [1,2,3,4] --
 * enclosed in square brackets, numbers separated by commas, and no spaces.
 */
void printList(LinkedList list, FILE *outputFile) {
  if (list == NULL) {
    fprintf(outputFile, "[]\n");
    return;
  }
  fprintf(outputFile, "[");
  LinkedList iterator = list;
  while (iterator != NULL) {
    fprintf(outputFile, "%d,", iterator->data);
    iterator = iterator->next;
  }
  fprintf(outputFile, "\b]\n");
}
