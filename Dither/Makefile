CFLAGS = -Werror -Wextra -Wall -Wpedantic
CC = clang

.phony: clean

dither: dither.o
	$(CC) dither.o -o dither

dither.o: dither.c
	$(CC) $(CFLAGS) -c dither.c

clean: 
	rm dither.o dither

