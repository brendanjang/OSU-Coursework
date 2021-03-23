/******************************************************************************
** Program Name:	Project 4 - Medusa.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Medusa class.
******************************************************************************/

#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Medusa.hpp"

/**
 * constructor 
 */
Medusa::Medusa() {
    armor = 3;
    strength = 8;
    fixed_strength = strength;
}

/**
 * copy constructor 
 * @param orig a medusa
 */
Medusa::Medusa(const Medusa& o) : Character(o) {
}

/**
 * destructor 
 */
Medusa::~Medusa() {
}

/**
 * attacking
 * @return attacked damage
 */
int Medusa::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    
    // glare
    if (damage_attacked == 12) {
        damage_attacked = INT_MAX;
    }
    return damage_attacked;
}

/**
 * defending
 * @param damage_attacked attacked damage
 * @return inflicted damage
 */
int Medusa::defense(int damage_attacked) {
    int damage_defensed = (rand() % 6) + 1;
    
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    
    // final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
