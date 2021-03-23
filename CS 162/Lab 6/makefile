all: DoublyLinkedList.o main.o Menu.o Node.o
	g++ -std=c++11 DoublyLinkedList.o main.o Menu.o Node.o -o lab6

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.hpp
	g++ -std=c++11 -c DoublyLinkedList.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

Node.o: Node.cpp Node.hpp
	g++ -std=c++11 -c Node.cpp

clean:
	rm *.o lab6
