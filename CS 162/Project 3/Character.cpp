/******************************************************************************
** Program Name:	Project 3 - Character.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Character class.
******************************************************************************/

#include "Character.hpp"

/*
* Constructor
*/
Character::Character() {
    selected = false;
}

/*
* Copy constructor 
* @param o a character
*/
Character::Character(const Character& o) {
    armor = o.armor;
    strength = o.strength;
    selected = o.selected;
}

/*
* Destructor 
*/
Character::~Character() {
}

/*
* Getter
* @return armor
*/
int Character::getArmor() {
    return armor;
}

/*
* Getter
* @return strength
*/
int Character::getStrength() {
    return strength;
}

/*
* Checker
* @return true if the character still has some strength point
*/
bool Character::isAlive() {
    return strength > 0;
}

/*
* Setter 
* @param strength strength
*/
void Character::setStrength(int strength) {
    this->strength = strength;
}

/*
* Checker 
* @return true if the character has been used 
*/
bool Character::isSelected() {
    return selected;
}

/*
* Setter
* @param selected state of the character 
*/
void Character::setSelected(bool selected) {
    this->selected = selected;
}
