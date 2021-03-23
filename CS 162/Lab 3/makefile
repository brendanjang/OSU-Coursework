all: Die.o Game.o LoadedDie.o main.o Menu.o
	g++ Die.o Game.o LoadedDie.o main.o Menu.o -o game

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -c LoadedDie.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c --std=c++11 Menu.cpp

main.o: main.cpp
	g++ -c --std=c++11 -c main.cpp

clean:
	rm *.o game
