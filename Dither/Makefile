CFLAGS = -Werror -Wextra -Wall -Wpedantic
CC = clang

.phony: clean dval

main: main.o lattice.o dither.o
	$(CC) main.o lattice.o dither.o -o main -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lattice.o: lattice.c lattice.h
	$(CC) $(CFLAGS) -c lattice.c

dither.o: dither.c dither.h
	$(CC) $(CFLAGS) -c dither.c
clean: 
	rm main.o lattice.o dither.o main

dval:
	make clean
	make main
	valgrind --leak-check=full --show-leak-kinds=all ./main
