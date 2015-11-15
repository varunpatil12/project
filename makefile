project: code.o code2.o code3.o print.o
	gcc code.o code2.o code3.o print.o -o project
code.o: code.c 111.h
	gcc code.c -c
code2.o: code2.c 11.h
	gcc code2.c -c
code3.o: code3.c 111.h
	gcc code3.c -c
print.o: print.c 111.h 
	gcc print.c -c 
