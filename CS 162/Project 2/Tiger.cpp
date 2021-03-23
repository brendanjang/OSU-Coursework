/********************************************************************************
**	Program Name:	Project 2 - Tiger.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Tiger class. Inherits from animal 
					class.
*********************************************************************************/

#include "Tiger.hpp"

/*
* Constructor
* @param base_food_cost base food cost
* @param age age of the animal
*/
Tiger::Tiger(double base_food_cost, int age) : Animal(base_food_cost, age) {
    cost = 10000.0;
    baby_num = TIGER_BABY_NUM;    
    pay_off = 0.2 * cost;
}

/*
* Copy constructor
* @param orig a tiger object
*/
Tiger::Tiger(const Tiger& o) : Animal(o) {
}

/*
* Destructor
*/
Tiger::~Tiger() {
}

/*
* Getter
* @return feeding cost
*/
double Tiger::getFeedingCost() {
    return base_food_cost * 5.0;
}
