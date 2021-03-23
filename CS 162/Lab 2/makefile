all: main.o countLetters.o outputLetters.o
	g++ main.o countLetters.o outputLetters.o -o lab2

main.o: main.cpp countLetters.hpp outputLetters.hpp
	g++ -c main.cpp

countLetters.o: countLetters.cpp countLetters.hpp outputLetters.hpp
	g++ -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	g++ -c outputLetters.cpp

clean:
	rm *.o lab2
