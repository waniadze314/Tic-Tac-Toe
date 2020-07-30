CC = g++
CFLAGS = -std=c++17 -Wall -pedantic

tictactoe: main.o board.o minmax_algorithm.o
	$(CC) -o tictactoe main.o board.o minmax_algorithm.o

main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(CFLAGS)

board.o: board.cpp
	$(CC) -c -o board.o board.cpp $(CFLAGS)

minmax_algorithm.o: minmax_algorithm.cpp board.cpp
	$(CC) -c -o minmax_algorithm.o minmax_algorithm.cpp $(CFLAGS)

clean: 
	rm *.o