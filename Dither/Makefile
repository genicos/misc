CFLAGS = -Werror -Wextra -Wall -Wpedantic
CC = clang

.phony: clean dval

dither: dither.o lattice.o
	$(CC) dither.o lattice.o -o dither -lm

dither.o: dither.c
	$(CC) $(CFLAGS) -c dither.c

lattice.o: lattice.c lattice.h
	$(CC) $(CFLAGS) -c lattice.c
clean: 
	rm dither.o dither

dval:
	make clean
	make dither
	valgrind --leak-check=full --show-leak-kinds=all ./dither
