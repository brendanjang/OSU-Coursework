/***************************************************************************** 
** Program Name:	Final Project - SpaceBasement.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Basement class.
*****************************************************************************/

#include "SpaceBasement.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

SpaceBasement::SpaceBasement() {
    name = "basement";
    task = "Take the toolbox to the basement to fix the washing machine.";
}

SpaceBasement::~SpaceBasement() {
}

/**
 * fix the machine
 * @return 
 */
bool SpaceBasement::fixing() {
    
    string message = "The machine has some problems with its resistor.\n"
            "Let's do a physics calculation.\n"
            "A resistor has a voltage across it of 120 volts and\n"
            "a current through it of 2.5 amperes.\n"
            "Calculate the resistance of the resistor.\n";
    
    // expected result
    const double result = 48.0;
    
    // show message to screen
    double answer = menu.getValue(&message, 1, 0, 20000);
    
    // compare result
    if (result == answer) {
        cout << "Good! We have to increase the "
                "resistance of the resistor this time.\n";
        cout << "The washing machine has been fixed.\n";
        return true;
    }      
    cout << "The machine crashes again, we calculated incorrectly.\n";
    return false;
}

/**
 * action
 * @param player
 */
void SpaceBasement::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // fix machine
        if (player->hasItem(Game::toolBox) == true) {
            string message [] = {
                "Are you ready to fix the washing machine?",
                "1, Yes",
                "2. No"
            };
            int selection = menu.getValue(message, 3, 1, 2);
            if (selection == 1) {
                this->finished = fixing();                
            } else {
                cout << "Nothing happens.\n";
            }
        } else {
            cout << "You don't have the "
                    << Game::toolBox->getDescription() << " in your hand.\n";
        }
    }
}