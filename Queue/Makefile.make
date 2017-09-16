output: main.o queue.o
	gcc main.o queue.o -o output

main.o: main.c
	gcc -c main.c

stack.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm *.o output