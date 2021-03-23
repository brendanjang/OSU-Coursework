/***************************************************************************** 
** Program Name:	Final Project - SpaceKitchen.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Kitchen class.
*****************************************************************************/

#include "SpaceKitchen.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

SpaceKitchen::SpaceKitchen() {
    name = "kitchen";
    task = "Give the bread to Mom.";
}

SpaceKitchen::~SpaceKitchen() {
}

/**
 * action
 * @param player
 */
void SpaceKitchen::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // give Mom the bread
        if (player->hasItem(Game::bread) == true) {
            string message [] = {
                "Do you want to give the bread to Mom?",
                "1, Yes",
                "2. No"
            };
            int selection = menu.getValue(message, 3, 1, 2);
            if (selection == 1) {
                player->drop(Game::bread);
                this->addItem(Game::bread);
                this->finished = true;
                cout << "Good, You have finished the errand.\n";
            } else {
                cout << "Nothing happens.\n";
            }
        } else {
            cout << "You don't have the "
                    << Game::bread->getDescription() << " in your hand.\n";
        }
    }
}