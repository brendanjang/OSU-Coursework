all: Game.o main.o Player.o Space.o SpaceKitchen.o Item.o Menu.o SpaceBasement.o SpaceGarden.o SpaceStreet.o List.o Node.o SpaceBedroom.o SpaceHall.o
	g++ -std=c++11 Game.o main.o Player.o Space.o SpaceKitchen.o Item.o Menu.o SpaceBasement.o SpaceGarden.o SpaceStreet.o List.o Node.o SpaceBedroom.o SpaceHall.o -o final

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

main.o:
	g++ -std=c++11 -c main.cpp

Player.o: Player.hpp Player.cpp
	g++ -std=c++11 -c Player.cpp

Space.o: Space.hpp Space.cpp
	g++ -std=c++11 -c Space.cpp

SpaceKitchen.o: SpaceKitchen.hpp SpaceKitchen.cpp
	g++ -std=c++11 -c SpaceKitchen.cpp

Item.o: Item.hpp Item.cpp
	g++ -std=c++11 -c Item.cpp

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

SpaceBasement.o: SpaceBasement.hpp SpaceBasement.cpp
	g++ -std=c++11 -c SpaceBasement.cpp

SpaceGarden.o: SpaceGarden.hpp SpaceGarden.cpp
	g++ -std=c++11 -c SpaceGarden.cpp

SpaceStreet.o: SpaceStreet.hpp SpaceStreet.cpp
	g++ -std=c++11 -c SpaceStreet.cpp

List.o: List.hpp List.cpp
	g++ -std=c++11 -c List.cpp

Node.o: Node.hpp Node.cpp
	g++ -std=c++11 -c Node.cpp

SpaceBedroom.o: SpaceBedroom.hpp SpaceBedroom.cpp
	g++ -std=c++11 -c SpaceBedroom.cpp

SpaceHall.o: SpaceHall.hpp SpaceHall.cpp
	g++ -std=c++11 -c SpaceHall.cpp

clean:
	rm *.o final
