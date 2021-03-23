/***************************************************************************** 
** Program Name:	Final Project - Game.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Game class.
*****************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <ctime>
using namespace std;

/**
 * constructor
 * @param runtime
 */
Game::Game(int runtime) {
    this->runtime = runtime;
}

/**
 * destructor
 */
Game::~Game() {
    // clean all spaces
    for (Space * elem : universe) {
        if (elem != 0) {
            delete elem;
        }
        elem = 0;
    }
    // clean player
    delete player;

    // clean all items
    for (Item * elem : items) {
        if (elem != 0) {
            delete elem;
        }
        elem = 0;
    }
}

/**
 * set up the game
 */
void Game::setup() {
    // push spaces to the game map
    universe.push_back(basement);
    universe.push_back(bedroom);
    universe.push_back(gardern);
    universe.push_back(hall);
    universe.push_back(kitchen);
    universe.push_back(street);

    // set up connection
    basement->setNeighbor(Space::SPACE_TOP, hall);

    hall->setNeighbor(Space::SPACE_BOTTOM, basement);
    hall->setNeighbor(Space::SPACE_RIGHT, kitchen);
    hall->setNeighbor(Space::SPACE_TOP, bedroom);
    hall->setNeighbor(Space::SPACE_LEFT, street);

    kitchen->setNeighbor(Space::SPACE_LEFT, hall);
    kitchen->setNeighbor(Space::SPACE_RIGHT, gardern);

    bedroom->setNeighbor(Space::SPACE_BOTTOM, hall);
    gardern->setNeighbor(Space::SPACE_LEFT, kitchen);

    street->setNeighbor(Space::SPACE_RIGHT, hall);

    // player starts from street and has bread
    player = new Player(street);
    player->take(bread);

    // gate key is under a brick near the gate
    street->addItem(gateKey);

    hall->addItem(broom);
    hall->addItem(toolBox);
    hall->addItem(howToBook);

	items.push_back(howToBook);
    items.push_back(toolBox);
	items.push_back(gateKey);
	items.push_back(bread);
	items.push_back(broom);

}

/**
 * check game status 
 * @return true if game is over
 */
bool Game::gameover() {
    // the player has to end up in the street
    if (player->getSpace() == street) {
        // all tasks must be fulfilled
        for (Space * elem : universe) {
            if (elem->isFinished() == false) {
                return false;
            }
        }
        return true;
    }
    return false;
}

/**
 * show welcome message
 */
void Game::welcomeMessage() {
    cout << "Welcome to The Errand Game\n";
    cout << "You are DJ, a random boy who is running errands.\n"
            << "You are coming home from the bakery.\n"
            << "You need to deliver bread "
            "to your mom who is in the kitchen.\n"
            << "Next, you will need to clean the hall with your "
			"grandpa's broom,\n"
            << "bring the toolbox to the basement to fix the washing machine,\n"
            << "water plants in the garden,\n"
            << "and finally bring the textbook to the bedroom.\n"
            << "You will need to go back "
			"out to the street when you finish the game.\n\n";
}

/**
 * show checklist
 */
void Game::showChecklist() {
    cout << "Checklist\n";
    for (Space * elem : universe) {
        cout << "\t" << elem->getTask() << ": ";
        if (elem->isFinished()) {
            cout << "CHECKED\n";
        } else {
            cout << "UNCHECKED\n";
        }
    }
}

/**
 * show the map
 */
void Game::showMap() {
    cout << "Map\n";
    cout << "\t        |bedroom |\n";
    cout << "\t street | hall   | kitchen | garden\n";
    cout << "\t        |basement|\n";
    cout << "You are at " << player->getSpace()->getName() << ".\n";
}

/**
 * run the game
 */
void Game::launch() {

    setup();
    welcomeMessage();

    Space * current;
    string message [] = {
        "What do you want to do?",
        "1. Look around.",
        "2. Show the map.",
        "3. Look at the checklist."
    };
    Menu menu;
    int selection;

   
    while (runtime > 0
            && gameover() == false) {
        cout << "You have " << runtime  << " steps left!\n";

        // get selection
        selection = menu.getValue(message, 4, 1, 3);
        switch (selection) {
            case 1:
                // action
                current = player->getSpace();
                current->show();
                current->action(player);
                break;
            case 2:
                // helper functions
                showMap();
                break;
            case 3:
                // helper functions
                showChecklist();
                break;

        }

        cout << "\n";
        runtime--;
    }

    // conclusion
    if (gameover() == false) {
        cout << "You lose!\n";
    } else {
        cout << "You win!\n";
    }

}