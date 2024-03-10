all: lista.o
	gcc main.c lista.o -o prog
	./prog


lista.o: lista.c
	gcc -c lista.c

clean:

	rm *.o prog