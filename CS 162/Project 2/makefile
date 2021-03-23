all: Animal.o main.o Penguin.o Turtle.o Camel.o Menu.o Tiger.o Zoo.o
	g++ -std=c++11 -g Animal.o main.o Penguin.o Turtle.o Camel.o Menu.o Tiger.o Zoo.o -o p2

main.o: main.cpp 
	g++ -std=c++11 -g -c main.cpp

Animal.o: Animal.hpp Animal.cpp
	g++ -std=c++11 -g -c Animal.cpp

Penguin.o: Penguin.hpp Penguin.cpp
	g++ -std=c++11 -g -c Penguin.cpp

Turtle.o: Turtle.hpp Turtle.cpp
	g++ -std=c++11 -g -c Turtle.cpp

Camel.o: Camel.hpp Camel.cpp
	g++ -std=c++11 -g -c Camel.cpp

Menu.o:	Menu.hpp Menu.cpp
	g++ -std=c++11 -g -c Menu.cpp

Tiger.o: Tiger.hpp Tiger.cpp
	g++ -std=c++11 -g -c Tiger.cpp

Zoo.o: Zoo.hpp Zoo.cpp
	g++ -std=c++11 -g -c Zoo.cpp

clean:
	rm *.o p2
