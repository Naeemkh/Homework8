# -------- makefile --------------

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: prime

prime: main.cpp
	$(CC) $(CFLAGS) io_print_handler.cpp  earthquake.cpp station.cpp  main.cpp -o main 

clean:
	rm -rf main

