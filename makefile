prog: Program.o structure.o print.o
	gcc -o prog Program.o structure.o print.o

main.o: main.c # class.h
	gcc -c main.c 

structure.o: structure.c # class.h
	gcc -c structure.c
	
print.o: print.c # class.h
	gcc -c print.c
