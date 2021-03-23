/********************************************************************************
**	Program Name:	Project 2 - Zoo.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Zoo class. Zoo class has a dynamnic array for
					each type of animal. Each dynamic array should have a 
					capacity of 10 animals to start with. If more animals are 
					added, resize the dynamic array by doubling the starting 
					capacityto hold more animals.
*********************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Camel.hpp"

#include <string>
using namespace std;

const int INIT_CAPACITY = 10;
const int TIGER = 0;
const int TURTLE = 1;
const int PENGUIN = 2;
const int CAMEL = 3;

const int FEEDING_CHEAP = 1;
const int FEEDING_GENERIC = 2;
const int FEEDING_PREMIUM = 3;

const string message_file = "temp_message.txt";

class Zoo {
public:
    // Constructor
    Zoo(double amount = 100000.0, double base_food_cost = 10.0);
    // Copy constructor
    Zoo(const Zoo& orig);
    // Destructor
    virtual ~Zoo();
    // Method
    void run();

private:
    // Actions of day
    void aDay();  
    // "Nothing happens" task
    void nothingHappen(double bonus);
    // Collect all pay off
    void collectPayoff();
    // Collect payoff from an animal
    double collectPayoff(Animal ** animals, int num);
    
    // "Random event" task
    double randomEvent();
    
    // "Boom" task
    double boom();    
    // Get all adults from input array
    void collectAdultAnimals(Animal ** collection, int & size,
            Animal ** animals, int num);
    
    // Write message to file
    void writeMessage(string message);
    // Read file and show message
    void readFile();

    // "Babies" task
    void babies();
    // "Sickness" task
    void sickness();
    
    // Feeding all animals and get them older 
    void growingAndFeeding();
    // Feeding all animals in a animal and get them older 
    void growingAndFeeding(Animal ** animal, int &size);

    // First task
    void begin();
    // Add new object to a animal's array 
    void addAnimal(int animal_type, int age);
    // Resize array of a animal
    bool resize(int animal_type);

private:
    // Arrays of pointer to animals
    Tiger ** tigers;
    Turtle ** turtles;
    Penguin ** penguins;
    Camel ** camels;
    
    // Number and capacity of each animal
    int tiger_num;
    int tiger_capacity;
    int turtle_num;
    int turtle_capacity;
    int penguin_num;
    int penguin_capacity;
    int camel_num;
    int camel_capacity;

    // Banking amount
    double amount; 
    // Base food cost
    double base_food_cost;
    // Current feeding type
    int feeding_type;
};

#endif /* ZOO_HPP */
