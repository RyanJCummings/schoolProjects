prog: main.o structure.o print.o
	gcc -o prog main.o structure.o print.o

main.o: main.c
	gcc -c main.c

structure.o: structure.c
	gcc -c structure.c
	
print.o: print.c
	gcc -c print.c
