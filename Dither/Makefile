CFLAGS = -Werror -Wextra -Wall -Wpedantic
CC = clang

.phony: clean dval

main: main.o lattice.o
	$(CC) main.o lattice.o -o main -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lattice.o: lattice.c lattice.h
	$(CC) $(CFLAGS) -c lattice.c
clean: 
	rm main.o lattice.o main

dval:
	make clean
	make main
	valgrind --leak-check=full --show-leak-kinds=all ./main
