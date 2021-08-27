all:
	g++ -c SCR/main.cpp
	g++ main.o -o game.out -lsfml-graphics -lsfml-window -lsfml-system
	./game.out
