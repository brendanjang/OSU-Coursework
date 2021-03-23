/*********************************************************************************
**	Program Name:	Project 2 - Turtle.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Turtle class. Inherits from animal 
					class.
*********************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle :public Animal {
public:
    // Constructor 
    Turtle(double base_food_cost, int age = 0);
    // Copy constructor
    Turtle(const Turtle& orig);
    // Destructor
    virtual ~Turtle();
    // Getter
    double getFeedingCost();
private:

};

#endif /* TURTLE_HPP */
