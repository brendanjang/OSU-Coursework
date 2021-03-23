/******************************************************************************
** Program Name:	Project 4 - Character.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Character class.
******************************************************************************/

#include "Character.hpp"

/**
 * constructor
 */
Character::Character() {
    selected = false;
}

/**
 * copy constructor 
 * @param o a character
 */
Character::Character(const Character& o) {
    armor = o.armor;
    strength = o.strength;
    selected = o.selected;
}

/**
 * destructor 
 */
Character::~Character() {
}

/**
 * getter
 * @return armor
 */
int Character::getArmor() {
    return armor;
}

/**
 * getter
 * @return strength
 */
int Character::getStrength() {
    return strength;
}

/**
 * checker
 * @return true if the character still has some strength point
 */
bool Character::isAlive() {
    return strength > 0;
}

/**
 * setter 
 * @param strength strength
 */
void Character::setStrength(int strength) {
    this->strength = strength;
}

/**
 * checker 
 * @return true if the character has been used 
 */
bool Character::isSelected() {
    return selected;
}

/**
 * setter
 * @param selected state of the character 
 */
void Character::setSelected(bool selected) {
    this->selected = selected;
}

std::string Character::getName() {
    return name;
}

void Character::setName(std::string name) {
    this->name = name;
}

void Character::recovery() {
    double randomVal = ((double)(rand() % 100) + 1.0) / 100.0;
    int amount = (int)(randomVal * fixed_strength);
    strength += amount;
    if (strength > fixed_strength) {
        strength = fixed_strength;
    }
}
