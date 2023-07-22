CC = g++
CFLAGS = -std=c++17 -Wall -Wextra

all: libsearchlib.a main

libsearchlib.a: search_lib.o
	ar rcs libsearchlib.a search_lib.o

search_lib.o: search_lib.cpp search_lib.h
	$(CC) $(CFLAGS) -c search_lib.cpp

main: main.cpp libsearchlib.a
	$(CC) $(CFLAGS) -o main main.cpp -L. -lsearchlib

clean:
	rm -f *.o *.a main
