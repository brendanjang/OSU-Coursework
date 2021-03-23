
all: Ant.o  main.o  Menu.o
	g++ Ant.o  main.o  Menu.o -o p1
Ant.o: Ant.hpp
	g++ -c Ant.cpp
main.o: Menu.hpp Ant.hpp
	g++ -c main.cpp
Menu.o: Menu.hpp
	g++ -c Menu.cpp

clean:
	rm *.o p1		
