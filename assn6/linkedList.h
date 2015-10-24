/*
 * Linked list type definitions to be used with Assignment 6.
 * Your program *must* work with this header file.
 * Don't waste server space by submitting a copy, since
 * the TAs will have the file already.
 *
 * CISC 220, Fall 2014
 * M. Lamb
 */

#include <stdio.h>

// A single node in a linked list
struct ListNode {
  int data; // the data in this node
  struct ListNode *next; // point to next node, NULL for last node in the list
};

// Refer to a linked list with a pointer to the first node
typedef struct ListNode *LinkedList;

/* 
 * Parameter: a file name
 * Opens the named file for input and returns a pointer to the file.
 * If the file can't be opened, writes a descriptive error message and exits the
 * program.  So the caller can assume that if this function returns it
 * will be returning a valid file pointer that may be used for reading.
 */
FILE *openInputFile(char *filename);

/* 
 * Parameter: a file name
 * Opens the named file for output and returns a pointer to the file.
 * If the file can't be opened, writes a descriptive error message and exits the
 * program.  So the caller can assume that if this function returns it
 * will be returning a valid file pointer that may be used for writing.
 */
FILE *openOutputFile(char *filename);

/*
 * Parameters: a linked list of numbers and a file that should be open for input.
 * Reads an integer from the file (skipping white space first) and adds it to
 * to the start of the linked list, returning a pointer to the modified list.
 */
LinkedList readAndAddToStart(LinkedList list, FILE *inputFile);


/*
 * Parameters: a linked list of numbers and a file that should be open for input.
 * Reads an integer from the file (skipping white space first) and adds it to
 * to the end of the linked list, returning a pointer to the modified list.
 */
LinkedList readAndAddToEnd(LinkedList list, FILE *inputFile);

/*
 * Parameters: a linked list of numbers
 * Deletes the first element of the list and returns a pointer to the
 * modified list.  If the list is empty, does not change the list, but
 * returns a pointer to the unmodified list.
 */
LinkedList deleteFirst(LinkedList list);

/*
 * Parameters: a linked list of numbers
 * Deletes the last element of the list and returns a pointer to the
 * modified list.  If the list is empty, does not change the list, but
 * returns a pointer to the unmodified list.
 */
LinkedList deleteLast(LinkedList list);

/*
 * Parameters: a linked list of numbers and a file that should be open for output.
 * Prints the list to the file in a format like this: [1,2,3,4] --
 * enclosed in square brackets, numbers separated by commas, and no spaces.
 */
void printList(LinkedList list, FILE *outputFile);
