/******************************************************************************
** Program Name:	Project 3 - HarryPotter.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Harry Potter class.
******************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
public:
    // Constructor
    HarryPotter();
    // Copy constructor
    HarryPotter(const HarryPotter& orig);
    // Destructor
    virtual ~HarryPotter();
    // Overriding method
    int attack() override;
    // Overriding method
    int defense(int damage_attacked) override;

private:
    int live; // Number of lives
};

#endif /* HARRYPOTTER_HPP */
