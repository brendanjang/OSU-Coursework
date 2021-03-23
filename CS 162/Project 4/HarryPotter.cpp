/******************************************************************************
** Program Name:	Project 4 - HarryPotter.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for HarryPotter class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "HarryPotter.hpp"

/**
 * constructor 
 */
HarryPotter::HarryPotter() {
    armor = 0;
    strength = 10;
    live = 1;
    fixed_strength = strength;
}

/**
 * copy constructor 
 * @param orig a harry potter 
 */
HarryPotter::HarryPotter(const HarryPotter& orig) : Character(orig) {
    live = orig.live;
}

/**
 * destructor 
 */
HarryPotter::~HarryPotter() {
}

/**
 * attacking
 * @return attacked damage
 */
int HarryPotter::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    return damage_attacked;
}

/**
 * defending
 * @param damage_attacked attacked damage
 * @return inflicted damage
 */
int HarryPotter::defense(int damage_attacked) {
    int damage_defensed = (rand() % 6) + (rand() % 6) + 2;
    int damage_inflicted = damage_attacked - armor - damage_defensed;

    // harry will die, and he still have a spell to come back to life 
    if (damage_inflicted >= strength
            && live > 0) {
        live = 0;
        strength = 20;
        damage_inflicted = 0;
    }

    // final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
