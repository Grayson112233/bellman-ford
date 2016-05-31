main: main.o
	gcc -Wall -o main main.o

main.o: main.c
	gcc -Wall -std=c99 -c main.c
