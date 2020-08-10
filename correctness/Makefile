CC = clang
CFLAGS = -Werror -Wpedantic -Wextra -Wall

.PHONY: clean 

test: test.o stack.o
	$(CC) $(CFLAGS) test.o stack.o -o test

test.o: test.c  
	$(CC) $(CFLAGS) -c test.c

correct: correct.o stack.o
	$(CC) $(CFLAGS) correct.o stack.o -o correct

correct.o: correct.c
	$(CC) $(CFLAGS) -c correct.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm test test.o 
