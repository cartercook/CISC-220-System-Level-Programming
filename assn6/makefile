OBJ = assn6Test.o heapReport.o linkedList.o
CC = gcc

assn6Test: $(OBJ)
	gcc -o assn6Test $(OBJ)

heapReport.o: heapReport.h

linkedList.o: linkedList.h

# "make cleanup" gets rid of all the files produced by the make rules above
cleanup:
	rm -f heapReport.o linkedList.o assn6Test.o assn6Test