CC=gcc
CFLAGS=-std=c11 -O2 -Wall -Wextra -pedantic -g

all: sum-files sum-files-threaded

sum-files: src/sum-files.c
	$(CC) $(CFLAGS) $< -o sum-files

sum-files-threaded: src/sum-files-threaded.c
	$(CC) $(CFLAGS) $< -o sum-files-threaded -lpthread

clean:
	rm -f sum-files sum-files-threaded *.o
