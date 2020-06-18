CFLAGS = -Werror -Wextra -Wall -Wpedantic
CC = clang

.phony: clean dval

dither: dither.o
	$(CC) dither.o -o dither

dither.o: dither.c
	$(CC) $(CFLAGS) -c dither.c

clean: 
	rm dither.o dither

dval:
	make clean
	make dither
	valgrind --leak-check=full --show-leak-kinds=all ./dither
