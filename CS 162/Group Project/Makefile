all: Ant.o  Cell.o  Critter.o  Doodlebug.o  Grid.o  main.o  Menu.o
	g++ -std=c++11 Ant.o  Cell.o  Critter.o  Doodlebug.o  Grid.o  main.o  Menu.o -o lab
Ant.o: Ant.cpp Ant.hpp Cell.hpp
	g++ -std=c++11 -c Ant.cpp
Cell.o: Cell.cpp Ant.hpp Cell.hpp Doodlebug.hpp
	g++ -std=c++11 -c Cell.cpp
Critter.o: Critter.cpp Critter.hpp Cell.hpp
	g++ -std=c++11 -c Critter.cpp
Doodlebug.o: Doodlebug.cpp Ant.hpp Cell.hpp Doodlebug.hpp
	g++ -std=c++11 -c Doodlebug.cpp
Grid.o: Grid.cpp Grid.hpp Ant.hpp Doodlebug.hpp
	g++ -std=c++11 -c Grid.cpp
main.o: main.cpp Grid.hpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

clean:
	rm *.o lab
