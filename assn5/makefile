# Make file for Assignment 5
# Provided for Assignment 5.  We'll talk about how to use this during the "make"
# topic.  Before then, you may use the buildAssn5 instead if you're not comfortable
# with the make tool.
# CISC 220, Fall 2014

assn5: heapReport.o assn5Testing.o assn5Functions.o
	gcc -o assn5 assn5Testing.o heapReport.o assn5Functions.o 
heapReport.o: heapReport.c heapReport.h
assn5Testing.o: assn5Testing.c
assn5Functions.o: assn5Functions.c assn5Functions.h

# cleans up all non-source files 
cleanup:
	rm -f heapReport.o assn5Testing.o assn5Functions.o assn5