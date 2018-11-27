prog: Program.o print.o
	gcc -o prog -Wall Program.o print.o

Program.o: Program.c structure.h
	gcc -c Program.c

print.o: print.c structure.h
	gcc -c print.c

readin.o: readin.c structure.h
	gcc -c readin.c
