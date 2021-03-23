/***************************************************************************** 
** Program Name:	Final Project - SpaceHall.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Hall class.
*****************************************************************************/

#include "SpaceHall.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

SpaceHall::SpaceHall() {
    name = "hall";
    task = "Sweep the hall.";
}

SpaceHall::~SpaceHall() {
}

/**
 * action
 * @param player
 */
void SpaceHall::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // sweep the hall
        if (player->hasItem(Game::broom) == true) {
            this->finished = true;
            cout << "Good, The hall has been swept.\n";
        } else {
            cout << "You don't have the "
                        << Game::broom->getDescription() << " in your hand.\n";
        }
    }
}