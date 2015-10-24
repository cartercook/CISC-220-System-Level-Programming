/*
 * Headers for functions to be written by students for Assignment 5.
 * CISC 220, Fall 2014
 */

// Returns the number of space characters (' ') in its parameter
int countSpaces(char theString[]);

/*
 * Splits a string into individual words.  
 * First parameter: a string.  Assumes that the words in the string are separated by
 *   single spaces, with no spaces before the first word or after the second word.  So
 *   the number of words is equal to the number of spaces plus 1.
 * Second parameter: the address of an integer in which the function will store the
 *   number of words in the string.
 * Return value: pointer to the beginning of an array of strings containing the individual
 * words from the sentence.  These will be separate strings, not pointers into the sentence.
 * The words and the array of words are all allocated on the heap.
 */
char** splitString(char theString[], int *arraySize);

/* Cleans up the space used by an array of words.  
 * Parameters: array of words and its length
 * Assumes that the array of words and each individual word are
 * stored on the heap.
 */
void cleanup(char *words[], int numWords);
