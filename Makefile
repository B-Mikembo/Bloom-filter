CC=gcc
CFLAGS=-Wall -ansi -g
LDFLAGS=-lm
DEPS=bitarray.h filter.h
OBJ=bitarray.o filter.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: test.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean

main: main.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

application-test:
	./test

application:
	./main

valgrind: 
	make
	valgrind --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -f $(OBJ) test test.o main main.o