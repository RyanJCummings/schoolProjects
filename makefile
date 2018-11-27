prog: Program.o print.o readin.o
	gcc -o prog Program.o print.o readin.o

Program.o: Program.c structure.h
	gcc -c Program.c -Wall

print.o: print.c structure.h
	gcc -c print.c -Wall

readin.o: readin.c structure.h
	gcc -c readin.c -Wall
