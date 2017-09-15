output: main.o stack.o
	gcc main.o stack.o -o output

main.o: main.c
	gcc -c main.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *.o output