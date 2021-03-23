/********************************************************************************
**	Program Name:	Project 2 - Tiger.hpp
**	Author:			Brendan Jang
** 	Date:			2/2/2019
**	Description:	Header  file for Tiger class. Inherits from animal 
					class.
*********************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal {
public:
    // Constructor
    Tiger(double base_food_cost, int age = 0);
    // Copy constructor
    Tiger(const Tiger& orig);
    // Destructor 
    virtual ~Tiger();   
    // Getter
    double getFeedingCost();
private:    
};

#endif /* TIGER_HPP */
