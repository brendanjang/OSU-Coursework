/***************************************************************************** 
** Program Name:	Final Project - SpaceStreet.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Street class.
*****************************************************************************/

#include <iostream>

#include "Menu.hpp"
#include "SpaceStreet.hpp"
#include "Game.hpp"

SpaceStreet::SpaceStreet() {
    name = "street";
    task = "Pick up the key from the hole which is hidden under the red brick.";
}

SpaceStreet::~SpaceStreet() {
}

/**
 * action
 * @param player
 */
void SpaceStreet::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // take the key
        if (player->hasItem(Game::gateKey) == true) {
            cout << "You have taken the key already.\n";
        } else if (this->hasItem(Game::gateKey) == false) {
            cout << "There isn't a '"
                    << Game::gateKey->getDescription()
                    << "' in the " << name << ".\n";
        } else {
            string message [] = {
                "Do you want to take the '"
                + Game::gateKey->getDescription() + "'? ",
                "1, Yes",
                "2. No"
            };
            int selection = menu.getValue(message, 3, 1, 2);
            if (selection == 1) {
                if (player->take(Game::gateKey) == true) {
                    for (int i = 0; i < items.size(); i++) {
                        if (items[i] == Game::gateKey) {
                            items.erase(items.begin() + i);
                            break;
                        }
                    }
                    this->finished = true;
                    cout << "Good, You have taken the key\n";
                } else {
                    cout << "Your bag is full., "
                            "You should drop some items first.\n";
                }                
            } else {
                cout << "Nothing happens.\n";
            }
        }
    }
}