all:
	g++ SRC/main.cpp -o game.out -pthread -lncurses -g
	./game.out
