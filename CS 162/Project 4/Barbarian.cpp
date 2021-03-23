/******************************************************************************
** Program Name:	Project 4 - Barbarian.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Barbarian class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Barbarian.hpp"

/**
 * constructor
 */
Barbarian::Barbarian() {
    armor = 0;
    strength = 12;
    fixed_strength = strength;
}

/**
 * copy constructor
 * @param o a barbarian
 */
Barbarian::Barbarian(const Barbarian& o) : Character(o) {
}

/**
 * destructor
 */
Barbarian::~Barbarian() {
}

/**
 * attacking
 * @return attacked damage
 */
int Barbarian::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    //cout << "\tThe attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/**
 * defending
 * @param damage_attacked attacked damage
 * @return inflicted damage
 */
int Barbarian::defense(int damage_attacked) {
    
    // roll 2 dice
    int damage_defensed = (rand() % 6) + (rand() % 6) + 2;
        
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    // final damage is 0 when the attack has no effect   
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return  damage_inflicted;
}


