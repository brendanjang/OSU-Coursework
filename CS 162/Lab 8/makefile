all: main.o Menu.o
	g++ -std=c++11 main.o Menu.o -o lab8

main.o: main.cpp Menu.hpp
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

clean:
	rm *.o lab8
