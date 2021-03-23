/******************************************************************************
** Program Name:	Project 3 - BlueMen.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Blue Men class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "BlueMen.hpp"

/*
* Constructor
*/
BlueMen::BlueMen() {
    armor = 3;
    strength = 12;
}

/*
* Copy constructor 
* @param o a blue men
*/
BlueMen::BlueMen(const BlueMen& o) : Character(o) {
}

/*
* Destructor
*/
BlueMen::~BlueMen() {
}

/*
* Attacking
* @return attacked damage
*/
int BlueMen::attack() {
    // Roll 2 dice
    int damage_attacked = (rand() % 10) + (rand() % 10) + 2;
    cout << "The attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/*
* Defending
* @param damage_attacked attacked damage
* @return inflicted damage
*/
int BlueMen::defense(int damage_attacked) {
    // Get real damage due to mob
    cout << "BlueMen uses Mob\n";
    int real_damage_attacked = damage_attacked / 4;

    int damage_defensed = (rand() % 6) + (rand() % 6) + (rand() % 6) + 3;
    cout << "The defender's defend dice roll: " << damage_defensed << "\n";

    int damage_inflicted = real_damage_attacked - armor - damage_defensed;

    // Final damage is 0 when the attack has no effect   
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
