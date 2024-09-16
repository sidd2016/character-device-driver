#! /bin/bash
  

main: main.o init.o exitApplication.o mainMenu.o openDev.o releaseDev.o writeDev.o readDev.o
	gcc -o main main.o init.o exitApplication.o mainMenu.o openDev.o releaseDev.o writeDev.o readDev.o
  
readDev.o: readDev.c headers.h declarations.h
	gcc -c readDev.c
 
writeDev.o: writeDev.c headers.h declarations.h
	gcc -c writeDev.c

releaseDev.o: releaseDev.c headers.h declarations.h
	gcc -c releaseDev.c
 
openDev.o: openDev.c headers.h declarations.h
	gcc -c openDev.c

mainMenu.o: mainMenu.c headers.h declarations.h
	gcc -c mainMenu.c
 
exitApplication.o: exitApplication.c headers.h declarations.h
	gcc -c exitApplication.c
init.o: init.c headers.h declarations.h
	gcc -c init.c
main.o: main.c headers.h declarations.h
	gcc -c main.c

clean:
	-rm *.o

