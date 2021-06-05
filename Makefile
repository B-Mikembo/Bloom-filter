<<<<<<< HEAD
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
=======
CC=gcc
CFLAGS=-Wall -ansi -g
LDFLAGS=-lm
DEPS=bitarray.h filter.h avl.h visualtree.h
OBJ=bitarray.o filter.o main.o avl.o visualtree.o

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
>>>>>>> 0b8d74ca08fd3851d39e67a95ee9861030d00b2e
	rm -f $(OBJ) test test.o main main.o