/******************************************************************************
** Program Name:	Project 4 - BlueMen.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for BlueMen class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "BlueMen.hpp"

/**
 * constructor
 */
BlueMen::BlueMen() {
    armor = 3;
    strength = 12;
    fixed_strength = strength;
}

/**
 * copy constructor 
 * @param o a blue men
 */
BlueMen::BlueMen(const BlueMen& o) : Character(o) {
}

/**
 * destructor
 */
BlueMen::~BlueMen() {
}

/**
 * attacking
 * @return attacked damage
 */
int BlueMen::attack() {
    // roll 2 dice
    int damage_attacked = (rand() % 10) + (rand() % 10) + 2;
    return damage_attacked;
}

/**
 * defending
 * @param damage_attacked attacked damage
 * @return inflicted damage
 */
int BlueMen::defense(int damage_attacked) {
    // get real damage due to mob
    
    int damage_defensed = (rand() % 6) + (rand() % 6) + (rand() % 6) + 3;
    int real_damage_attacked = damage_attacked - damage_defensed * 4;
    
    int damage_inflicted = 0;
    if (real_damage_attacked > 0) {
        damage_inflicted = real_damage_attacked - armor;
    }

    // final damage is 0 when the attack has no effect   
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}