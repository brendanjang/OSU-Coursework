/******************************************************************************
** Program Name:	Project 3 - BlueMen.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Blue Men class.
******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"


class BlueMen : public Character {
public:
    // Constructor
    BlueMen();
    // Copy constructor
    BlueMen(const BlueMen& orig);
    // Destructor 
    virtual ~BlueMen();
    // Overriding method
    int attack() override;
    // Overriding method
    int defense(int damage_attacked) override;

private:

};

#endif /* BLUEMEN_HPP */
