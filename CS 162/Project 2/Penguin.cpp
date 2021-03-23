/**************************************************************************
**	Program Name:	Project 2 - Penguin.cpp
**	Author:			Brendan Jang
** 	Date:			2/2/2019
**	Description:	Implementation file for Penguin class. Inherits from 
					animal class.
***************************************************************************/

#include "Penguin.hpp"
#include "Animal.hpp"

/*
* Constructor
* @param base_food_cost base food cost
* @param age age of the animal
*/
Penguin::Penguin(double base_food_cost, int age) : Animal(base_food_cost, age) {
    cost = 1000.0;
    baby_num = PENGUIN_BABY_NUM;
    pay_off = 0.1 * cost;
}

/*
* Copy constructor
* @param orig a penguin object
*/
Penguin::Penguin(const Penguin& orig) : Animal(orig) {
}

/*
* Destructor
*/
Penguin::~Penguin() {
}
