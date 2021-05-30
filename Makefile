CC=gcc
CFLAGS=-Wall -ansi -g
LDFLAGS=-lm
DEPS=bitarray.h filter.h
OBJ=bitarray.o filter.o
EXEC=test

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: test.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean

valgrind: 
	make
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

clean:
	rm -f $(OBJ) test test.o