/***************************************************************************** 
** Program Name:	Final Project - Item.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Game class.
*****************************************************************************/

#include "Item.hpp"

/**
 * constructor
 * @param name name
 * @param description extra information
 */
Item::Item(string name, string description) {
    this->name = name;
    this->description = description;
}

/**
 * copy constructor
 * @param orig
 */
Item::Item(const Item& orig) {
    name = orig.name;
    description = orig.description;
}

/**
 * destructor
 */
Item::~Item() {
}

/**
 * getter
 * @return name
 */
string Item::getName() {
    return name;
}

/**
 * getter
 * @return description
 */
string Item::getDescription() {
    return description;
}