/******************************************************************************
** Program Name:	Project 3 - Barbarian.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Barbarian class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Barbarian.hpp"

/*
* Constructor
*/
Barbarian::Barbarian() {
    armor = 0;
    strength = 12;
}

/*
* Copy constructor
* @param o a barbarian
*/
Barbarian::Barbarian(const Barbarian& o) : Character(o) {
}

/*
* Destructor
*/
Barbarian::~Barbarian() {
}

/*
* Attacking
* @return attacked damage
*/
int Barbarian::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    cout << "The attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/*
* Defending
* @param damage_attacked attacked damage
* @return inflicted damage
*/
int Barbarian::defense(int damage_attacked) {
    
    // Roll 2 dice
    int damage_defensed = (rand() % 6) + (rand() % 6) + 2;
    
    cout << "The defender's defend dice roll: " << damage_defensed << "\n";
    
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    // Final damage is 0 when the attack has no effect   
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return  damage_inflicted;
}
