all: Menu.o main.o
	g++ -std=c++11 Menu.o main.o -o lab5

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

main.o: main.cpp Menu.hpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o lab5
