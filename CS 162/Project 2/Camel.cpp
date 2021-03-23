/*********************************************************************************
**	Program Name:	Project 2 - Camel.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Camel class. Inherits from animal
					class. Allow user to dynamically create a new animal during
					runtime, reprompting them for each trait.
*********************************************************************************/

#include "Camel.hpp"

/*
* Constructor
* @param base_food_cost base food cost
* @param age age of the animal
*/
Camel::Camel(double base_food_cost, int age) : Animal(base_food_cost, age) {
    cost = 5000.0;
    baby_num = CAMEL_BABY_NUM;    
    pay_off = 0.15 * cost;
}

/*
* Copy constructor
* @param orig a camel object
*/
Camel::Camel(const Camel& orig) : Animal(orig) {
}

/*
* Destructor
*/
Camel::~Camel() {
}

/*
* Getter
* @return feeding cost
*/
double Camel::getFeedingCost() {
    return base_food_cost * 2.0;
}
