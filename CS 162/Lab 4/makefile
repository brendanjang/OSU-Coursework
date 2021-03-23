all: Building.o main.o Person.o University.o Instructor.o Menu.o Student.o
	g++ -std=c++11 Building.o main.o Person.o University.o Instructor.o Menu.o Student.o -o lab4

Building.o: Building.cpp Building.hpp
	g++ -std=c++11 -c Building.cpp

main.o:	Building.hpp Person.hpp University.hpp Instructor.hpp Menu.hpp Student.hpp main.cpp
	g++ -std=c++11 -c main.cpp

Person.o: Person.hpp Person.cpp
	g++ -std=c++11 -c Person.cpp

University.o: University.hpp University.cpp
	g++ -std=c++11 -c University.cpp

Instructor.o: Instructor.hpp Instructor.cpp
	g++ -std=c++11 -c Instructor.cpp

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++11 -c Menu.cpp

Student.o: Student.hpp Student.cpp
	g++ -std=c++11 -c Student.cpp

clean:
	rm *.o lab4
