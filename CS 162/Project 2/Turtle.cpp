/*********************************************************************************
**	Program Name:	Project 2 - Turtle.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Turtle class. Inherits from animal 
					class.
*********************************************************************************/

#include "Turtle.hpp"

/*
* Constructor
* @param base_food_cost base food cost
* @param age age of the animal
*/
Turtle::Turtle(double base_food_cost, int age) : Animal(base_food_cost, age) {
    cost = 100.0;
    baby_num = TURTLE_BABY_NUM;
    pay_off = 0.05 * cost;
}

/*
* Copy constructor
* @param orig a turtle object
*/
Turtle::Turtle(const Turtle& orig) : Animal(orig) {
}

/*
* Destructor
*/
Turtle::~Turtle() {
}

/*
* Getter
* @return feeding cost
*/
double Turtle::getFeedingCost() {
	return base_food_cost * 0.5;
}
