/********************************************************************************
**	Program Name:	Project 2 - Camel.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Camel class. Inherits from animal class. Allow
					user to dynamically create a new animal during runtime,
					reprompting them for each trait. Extra credit class.
*********************************************************************************/

#ifndef CAMEL_HPP
#define CAMEL_HPP

#include "Animal.hpp"

// Extra credit class 
class Camel : public Animal {
public:
    // Constructor
    Camel(double base_food_cost, int age = 0);
    // Copy constructor
    Camel(const Camel& orig);
    // Destructor
    virtual ~Camel();
    // Getter
    double getFeedingCost();
private:

};

#endif /* CAMEL_HPP */
