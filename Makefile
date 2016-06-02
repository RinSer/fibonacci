# Compiler
CC = gcc
# Flags
FLAGS = -g -std=c99 -Wall -o fibonacci

fibonacci: fibonacci.c Makefile
	$(CC) $(FLAGS) fibonacci.c -lm

clean:
	rm -f *.0 fibonacci
