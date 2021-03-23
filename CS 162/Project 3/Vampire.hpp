/******************************************************************************
** Program Name:	Project 3 - Vampire.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Vampire class.
******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
public:
    // Constructor
    Vampire();
    // Copy constructor
    Vampire(const Vampire& orig);
    // Destructor
    virtual ~Vampire();
    // Overriding method
    int attack() override;
    // Overriding method
    int defense(int damage_attacked) override;

private:
    
};

#endif /* VAMPIRE_HPP */
