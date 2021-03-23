/******************************************************************************
** Program Name:	Project 3 - Barbarian.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Barbarian class.
******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
public:
    // Constructor 
    Barbarian();
    // Copy constructor
    Barbarian(const Barbarian& orig);
    // Destructor 
    virtual ~Barbarian();
    // Overriding method
    int attack() override;
    // Overriding method
    int defense(int damage_attacked) override;

private:

};

#endif /* BARBARIAN_HPP */
