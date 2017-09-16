output: main.o list.o
	gcc main.o list.o -o output

main.o: main.c
	gcc -c main.c

stack.o: list.c list.h
	gcc -c list.c

clean:
	rm *.o output