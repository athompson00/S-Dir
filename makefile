
all: main.o
	gcc -o assignment main.c

main.o: main.c
	gcc -c main.c

run:
	./assignment

clean:
	rm *.o

debug: main.c
	gcc -g main.c

gdb: a.out
	gdb a.out
