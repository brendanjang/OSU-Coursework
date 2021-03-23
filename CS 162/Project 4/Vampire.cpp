/******************************************************************************
** Program Name:	Project 4 - Vampire.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Vampire class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Vampire.hpp"

/**
 * constructor 
 */
Vampire::Vampire() {
    armor = 1;
    strength = 18;
    fixed_strength = strength;
}

/**
 * copy constructor 
 * @param orig a medusa
 */
Vampire::Vampire(const Vampire& o) : Character(o) {
}

/**
 * destructor 
 */
Vampire::~Vampire() {
}

/**
 * attacking
 * @return attacked damage
 */
int Vampire::attack() {
    int damage_attacked = (rand() % 12) + 1;
    return damage_attacked;
}

/**
 * defending
 * @param damage_attacked attacked damage
 * @return inflicted damage
 */
int Vampire::defense(int damage_attacked) {
    
    // special skill
    if (rand() % 2 == 0) {
       // cout << "\tVampire uses Charm\n";
        return 0;
    }
    int damage_defensed = (rand() % 6) + 1;
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    
    // final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
