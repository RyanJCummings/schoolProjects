prog: Program.o print.o
	gcc -o Program.o print.o

Program.o: Program.c structure.h
	gcc -c main.c 

structure.o: structure.c structure.h
	gcc -c structure.c
	
print.o: print.c structure.h
	gcc -c print.c

Program.o: Program.c structure.h
	gcc -c Program -Wall Program.c

print.o: print.c
	gcc -c print -Wall print.c

