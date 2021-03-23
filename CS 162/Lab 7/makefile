all: main.o Menu.o Queue.o
	g++ -std=c++11 main.o Menu.o Queue.o -o lab7

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

Queue.o: Queue.hpp QueueNode.hpp Queue.cpp
	g++ -std=c++11 -c Queue.cpp

clean:
	rm *.o lab7
