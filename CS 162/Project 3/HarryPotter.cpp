/******************************************************************************
** Program Name:	Project 3 - HarryPotter.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Harry Potter class.
******************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "HarryPotter.hpp"

/*
* Constructor 
*/
HarryPotter::HarryPotter() {
    armor = 0;
    strength = 10;
    live = 1;
}

/*
* Copy constructor 
* @param orig a harry potter 
*/
HarryPotter::HarryPotter(const HarryPotter& orig) : Character(orig) {
    live = orig.live;
}

/*
* Destructor 
*/
HarryPotter::~HarryPotter() {
}

/*
* Attacking
* @return attacked damage
*/
int HarryPotter::attack() {
    int damage_attacked = (rand() % 6) + (rand() % 6) + 2;
    cout << "The attacker's attack dice roll: " << damage_attacked << "\n";
    return damage_attacked;
}

/*
* Defending
* @param damage_attacked attacked damage
* @return inflicted damage
*/
int HarryPotter::defense(int damage_attacked) {
    int damage_defensed = (rand() % 6) + (rand() % 6) + 2;
    cout << "The defender's defend dice roll: " << damage_defensed << "\n";
    int damage_inflicted = damage_attacked - armor - damage_defensed;

    // Garry will die, and he still has a spell to come back to life 
    if (damage_inflicted >= strength
            && live > 0) {
        live = 0;
        strength = 20;
        damage_inflicted = 0;
        cout << "Harry Potter uses Hogwarts\n";
    }

    // Final damage is 0 when the attack has no effect  
    if (damage_inflicted < 0) {
        damage_inflicted = 0;
    }
    return damage_inflicted;
}
