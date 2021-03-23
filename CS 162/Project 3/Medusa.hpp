/******************************************************************************
** Program Name:	Project 3 - Medusa.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Medusa class.
******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
public:
    // Constructor
    Medusa();
    // Copy constructor
    Medusa(const Medusa& orig);
    // Destructor
    virtual ~Medusa();
    // Overriding method
    int attack() override;
    // Overriding method
    int defense(int damage_attacked) override;

private:

};

#endif /* MEDUSA_HPP */
