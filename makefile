prog: Program.o print.o readin.o
	gcc -o Program.o print.o

Program.o: Program.c structure.h
	gcc -c Program -Wall Program.c

print.o: print.c structure.h
	gcc -c print -Wall print.c

readin.o: readin.c structure.h
	gcc -c readin -Wall readin.c
