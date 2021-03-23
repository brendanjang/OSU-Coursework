/******************************************************************************
** Program Name:	Project 3 - Vampire.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Vampire class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Vampire.hpp"

/*
* Constructor 
*/
Vampire::Vampire() {
    armor = 1;
    strength = 18;
}

/*
* Copy constructor 
* @param orig a medusa
*/
Vampire::Vampire(const Vampire& o) : Character(o) {
}

/*
* Destructor 
*/
Vampire::~Vampire() {
}

/*
* Attacking
* @return attacked damage
*/
int Vampire::attack() {
    int damage_attacked = (rand() % 12) + 1;
    cout << "The attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/*
* Defending
* @param damage_attacked attacked damage
* @return inflicted damage
*/
int Vampire::defense(int damage_attacked) {
    
    // Special skill
    if (rand() % 2 == 0) {
        cout << "Vampire uses Charm\n";
        return 0;
    }
    int damage_defensed = (rand() % 6) + 1;
    cout << "The defender's defend dice roll: " << damage_defensed << "\n";
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    
    // Final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
