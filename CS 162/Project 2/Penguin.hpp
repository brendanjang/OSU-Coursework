/**************************************************************************
**	Program Name:	Project 2 - Penguin.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Penguin class. Inherits from animal 
					class.
**************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal {
public:
    // Constructor
    Penguin(double base_food_cost, int age = 0);
    // Copy constructor 
    Penguin(const Penguin& orig);
    // Destructor
    virtual ~Penguin();
private:

};

#endif /* PENGUIN_HPP */
