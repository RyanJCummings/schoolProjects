prog: Program.o print.o readin.o
	gcc -o prog Program.o print.o readin.o

Program.o: Program.c structure.h
	gcc -c -Wall Program.c

print.o: print.c structure.h
	gcc -c -Wall print.c

readin.o: readin.c structure.h
	gcc -c -Wall readin.c
