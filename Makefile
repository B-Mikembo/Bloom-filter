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

valgrind: 
	make main
	valgrind --leak-check=full --show-leak-kinds=all ./main 16 3 100words.txt

clean:
	rm -f $(OBJ) test test.o main main.o current-tree.* massif.out*