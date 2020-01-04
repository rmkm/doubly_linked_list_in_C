a.out: main.o list.o
	gcc -Wall -O2 -o a.out main.o list.o

main.o: main.c
	gcc -c main.c

list.o: list.c
	gcc -c list.c

clean:
	rm -f a.out main.o list.o
