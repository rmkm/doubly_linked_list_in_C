a.out: main.o dll.o
	gcc -Wall -O2 -o a.out main.o dll.o

main.o: main.c
	gcc -c main.c

dll.o: dll.c
	gcc -c dll.c

clean:
	rm -f a.out main.o dll.o
