/***************************************************************************** 
** Program Name:	Final Project - SpaceBedroom.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Bedroom class.
*****************************************************************************/

#include "SpaceBedroom.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

SpaceBedroom::SpaceBedroom() {
    name = "bedroom";
    task = "Bring the book to the bedroom and put it on the shelf.";
}

SpaceBedroom::~SpaceBedroom() {
}

/**
 * action
 * @param player
 */
void SpaceBedroom::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // put book on shelf
        if (player->hasItem(Game::howToBook) == true) {
            string message [] = {
                "Do you want to drop the book?",
                "1, Yes",
                "2. No"
            };
            int selection = menu.getValue(message, 3, 1, 2);
            if (selection == 1) {
                player->drop(Game::howToBook);
                this->addItem(Game::howToBook);
                this->finished = true;
                cout << "Good, The book has been on the shelf.\n";
            } else {
                cout << "Nothing happens.\n";
            }
        } else {
            cout << "You don't have the "
                    << Game::howToBook->getDescription() << " in your hand.\n";
        }
    }
}