/***************************************************************************** 
** Program Name:	Final Project - Player.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Player class.
*****************************************************************************/

#include "Player.hpp"

/**
 * constructor
 * @param space current space
 */
Player::Player(Space * space) {
    this->space = space;
}

/**
 * destructor 
 */
Player::~Player() {
}

/**
 * take itme
 * @param item
 * @return true if the item can be taken
 */
bool Player::take(Item* item) {
    return items.push(item);
}

/**
 * checker
 * @param item
 * @return true if player has the item 
 */
bool Player::hasItem(Item* item) {
    return items.contain(item);
}

/**
 * drop an item
 * @param item
 */
void Player::drop(Item* item) {
    items.remove(item);
}

/**
 * get current space
 * @return space
 */
Space* Player::getSpace() {
    return space;
}

/**
 * show all items
 */
void Player::showItems() {
    items.show();
}

/**
 * set space to player
 * @param space a space
 */
void Player::setSpace(Space * space) {
    this->space = space;
}

/**
 * checker 
 * @return true if the player holds some items
 */
bool Player::hasItem() {
    return !(items.empty());
}

/**
 * ask and drop the item
 * @return return dropped item
 */
Item* Player::dropItem() {
    
    // bad case 
    if (items.empty() == true) {
        return 0;
    }
    // get item
    Item * item = items.find();
    // drop it
    drop(item);
    // return it
    return item;
}