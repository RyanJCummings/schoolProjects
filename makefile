<<<<<<< HEAD
prog: Program.o print.o readin.o
	gcc -o Program.o print.o
=======
prog: Program.o print.o
	gcc -o prog -Wall Program.o print.o
>>>>>>> 321058a4cf1b85e2eab9ecb6046cc6623819f395

Program.o: Program.c structure.h
	gcc -c Program.c 
	
print.o: print.c structure.h
	gcc -c print.c

<<<<<<< HEAD
print.o: print.c structure.h
	gcc -c print -Wall print.c

readin.o: readin.c structure.h
	gcc -c readin -Wall readin.c
=======
>>>>>>> 321058a4cf1b85e2eab9ecb6046cc6623819f395
