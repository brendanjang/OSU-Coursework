/***************************************************************************** 
** Program Name:	Final Project - Space.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space class.
*****************************************************************************/

#include "Space.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

/**
 * constructor
 */
Space::Space() {

    // set all pointers to 0
    for (int i = 0; i < SPACE_NUM; i++) {
        neighbors[i] = 0;
    }
    index = counter;
    counter++;
    finished = false;
}

/**
 * destructor
 */
Space::~Space() {
}

/**
 * 
 * @param direction
 * @return pointer to a neighbor 
 */
Space* Space::getNeighbor(int direction) {
    if (direction < 0 || direction >= SPACE_NUM) {
        return 0;
    }
    return neighbors[direction];
}

/**
 * set neighbor 
 * @param direction position
 * @param space pointer 
 * @return true if we could set it
 */

bool Space::setNeighbor(int direction, Space* space) {
    if (direction < 0 || direction >= SPACE_NUM) {
        return false;
    }

    neighbors[direction] = space;
    return true;
}

/**
 * add item to space
 * @param item
 */
void Space::addItem(Item* item) {
    items.push_back(item);
}

/**
 * get index of the space
 * @return 
 */
int Space::getIndex() {
    return index;
}

/**
 * get name of space
 * @return name
 */
string Space::getName() {
    return name;
}

/**
 * checker
 * @return true if the task of this space is fulfilled
 */
bool Space::isFinished() {
    return finished;
}

/**
 * show the space
 */
void Space::show() {
    // show the space
    cout << "You are in the " << name << "\n";
    const string directions[] = {
        "top", "left", "bottom", "right"
    };

    // show items
    if (items.size() > 0) {
        cout << "Item in the " << name << ":\n";
        for (Item * elem : items) {
            cout << "\t" << elem->getName()
                    << ": " << elem->getDescription() << "\n";
        }
    }

    // show doors
    cout << "Ways out of the " << name << "\n";
    for (int i = 0; i < SPACE_NUM; i++) {
        Space * elem = neighbors[i];
        if (elem != 0) {
            cout << "\t" << directions[i]
                    << " direction to the " << elem->getName() << "\n";
        }
    }
}

/**
 * generate 1st message of the game
 * @return a string
 */
vector<string> Space::actionMessage() {
    // create vector of string
    vector<string> message;
    message.push_back("What are you going to do?");
    int counter = 1;
    string line;
    const string directions[] = {
        "top", "left", "bottom", "right"
    };
    line = to_string(TAKE_ITEM) + ". Take item";
    message.push_back(line);

    line = to_string(DROP_ITEM) + ". Drop item";
    message.push_back(line);

    line = to_string(SHOW_ITEM) + ". Show items in the bag";
    message.push_back(line);

    line = to_string(MOVE_AWAY) + ". Move away";
    message.push_back(line);

    line = to_string(DO_SOMETHING) + ". " + task;
    message.push_back(line);
    return message;
}

/**
 * 
 * @return description of all items in the space
 */
vector<string> Space::itemMessage() {
    vector<string> message;
    message.push_back("What do you want to take?");
    string line;
    for (int i = 0; i < items.size(); i++) {
        Item * item = items[i];
        line = to_string(i) + ". "
                + item->getName() + ": " + item->getDescription();
        message.push_back(line);
    }
    return message;
}

/**
 * player takes item from the space
 * @param player
 */
void Space::takeItem(Player* player) {
    // bad case 
    if (items.size() == 0) {
        cout << "There isn't a item in the " << name << "\n";
        return;
    }

    // generate information of all items
    vector<string> vt = itemMessage();

    string message[vt.size()];
    std::copy(vt.begin(), vt.end(), message);
    int selection = menu.getValue(message, vt.size(), 0, vt.size() - 2);
    Item * item = items[selection];

    // try to take the item
    if (player->take(item) == true) {
        // special cases 
        if (this == Game::street && item == Game::gateKey) {
            this->finished = true;
        } else if (this == Game::kitchen && item == Game::bread) {
            this->finished = false;
        }

        // remove item from the space
        items.erase(items.begin() + selection);
        cout << "You have taken '" << item->getDescription() << "'\n";
    } else {
        cout << "The bag is full. You should drop some items first.\n";
    }

}

/**
 * the player drops item
 * @param player
 */
void Space::dropItem(Player* player) {

    // drop an item 
    Item * item = player->dropItem();
    if (item == 0) {
        cout << "You don't have any items.\n";
    } else {
        // put it in the space
        this->addItem(item);
        // special conditions
        if ((this == Game::bedroom && item == Game::howToBook)
                || (this == Game::kitchen && item == Game::bread)) {
            this->finished = true;
        }
    }

}

/**
 * message about door
 * @return 
 */
vector<string> Space::doorMessage() {
    vector<string> message;
    message.push_back("What direction do you go to?");
    string line;
    const string directions[] = {
        "top", "left", "bottom", "right"
    };
    // create string and add to vector
    for (int i = 0; i < SPACE_NUM; i++) {
        Space * elem = neighbors[i];
        line = to_string(i) + ". Go to the "
                + directions[i] + " direction ";
        if (elem != 0) {
            line += "to the " + elem->getName();

        } else {
            line += "back to the " + name;
        }
        message.push_back(line);
    }
    return message;
}

/**
 * move the player to other spaces
 * @param player
 */
void Space::moveAway(Player* player) {

    // generate list of destinations
    vector<string> vt_2 = this->doorMessage();
    string message_2[vt_2.size()];
    std::copy(vt_2.begin(), vt_2.end(), message_2);

    int selection = menu.getValue(message_2,
            vt_2.size(), 0, vt_2.size() - 1);
    Space * next = getNeighbor(selection);


    // there is a way
    if (next != 0) {

        // special case 
        // the gate asks for key to open
        if ((this == Game::hall && next == Game::street)
                || (this == Game::street && next == Game::hall)) {
            if (player->hasItem(Game::gateKey)) {
                player->setSpace(next);
                if (this == Game::street) {
                    this->finished = true;
                }
            } else {
                cout << "You don't have the "
                        << Game::gateKey->getDescription() << " in your bag.\n";
            }
        } else {
            player->setSpace(next);
        }
    }
}

/**
 * action that takes in all spaces
 * @param player
 * @return 
 */
int Space::normalAction(Player* player) {

    // generate message
    vector<string> vt = this->actionMessage();
    string message[vt.size()];
    std::copy(vt.begin(), vt.end(), message);
    // get selection
    int selection = menu.getValue(message, vt.size(), 1, vt.size() - 1);

    // take action
    switch (selection) {
        case TAKE_ITEM:
            takeItem(player);
            break;
        case DROP_ITEM:
            dropItem(player);
            break;
        case SHOW_ITEM:
            player->showItems();
            break;
        case MOVE_AWAY:
            moveAway(player);
            break;

    }
    return selection;
}

/**
 * check for item in space
 * @param item
 * @return true if the item is in the space
 */
bool Space::hasItem(Item* item) {
    for (auto elem : items) {
        if (item == elem) {
            return true;
        }
    }

    return false;
}

/**
 * 
 * @return task of this space
 */
string Space::getTask() {
    return task;
}