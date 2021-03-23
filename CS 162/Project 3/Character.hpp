/******************************************************************************
** Program Name:	Project 3 - Character.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Character class.
******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
public:
    // Constructor
    Character();
    // Copy constructor
    Character(const Character& orig);
    // Destructor
    virtual ~Character();
    // Pure virtual method
    virtual int attack() = 0;
    // Pure virtual method
    virtual int defense(int damage_attacked) = 0;
    
    // Checker
    bool isAlive();
    // Getter
    int getArmor();
    // Getter 
    int getStrength();
    
    // Setter
    void setStrength(int strength);
    // Setter
    void setSelected(bool selected);
    bool isSelected();
protected:
    int armor;
    int strength;
    bool selected; // Turn to true when the character is selected in a fight
};

#endif /* CHARACTER_HPP */
