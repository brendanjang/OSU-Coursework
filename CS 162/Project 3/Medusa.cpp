/******************************************************************************
** Program Name:	Project 3 - Medusa.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Medusa class.
******************************************************************************/

#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Medusa.hpp"

/*
* Constructor 
*/
Medusa::Medusa() {
    armor = 3;
    strength = 8;
}

/*
* Copy constructor 
* @param orig a medusa
*/
Medusa::Medusa(const Medusa& o) : Character(o) {
}

/*
* Destructor 
*/
Medusa::~Medusa() {
}

/*
* Attacking
* @return attacked damage
*/
int Medusa::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    
    /// glare
    if (damage_attacked == 12) {
        damage_attacked = INT_MAX;
        cout << "Medusa uses Glare\n";
    }
    cout << "The attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/*
* Defending
* @param damage_attacked attacked damage
* @return inflicted damage
*/
int Medusa::defense(int damage_attacked) {
    int damage_defensed = (rand() % 6) + 1;
    cout << "The defender's defend dice roll: " << damage_defensed << "\n";
    
    int damage_inflicted = damage_attacked - armor - damage_defensed;
    
    // Final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
