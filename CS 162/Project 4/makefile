all: Barbarian.o Character.o main.o Menu.o BlueMen.o HarryPotter.o Medusa.o Vampire.o LinkedList.o Stack.o Queue.o Team.o
	g++ -std=c++11 Barbarian.o Character.o main.o Menu.o BlueMen.o HarryPotter.o Medusa.o Vampire.o LinkedList.o Stack.o Queue.o Team.o -o game

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

main.o: 
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

LinkedList.o:
	g++ -std=c++11 -c LinkedList.cpp

Stack.o:
	g++ -std=c++11 -c Stack.cpp

Queue.o:
	g++ -std=c++11 -c Queue.cpp

Team.o:
	g++ -std=c++11 -c Team.cpp

clean:
	rm *.o game
