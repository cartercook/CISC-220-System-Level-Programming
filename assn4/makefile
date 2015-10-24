#by 13cjcc for CISC 220F assignment 4
OBJ=assn4.o readmarks.o statistics.o histogram.o
CC=gcc

assn4: $(OBJ)
	gcc -o assn4 assn4.o readMarks.o statistics.o histogram.o -lm

assn4.o: readMarks.h statistics.h histogram.c

readmarks.o: readMarks.h

statistics.o: statistics.h

histogram.o: histogram.h