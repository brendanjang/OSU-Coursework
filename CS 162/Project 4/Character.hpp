/******************************************************************************
** Program Name:	Project 4 - Character.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Character class.
******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
	public:
		// constructor
		Character();
		// copy constructor
		Character(const Character& orig);
		// destructor
		virtual ~Character();
		// pure virtual method
		virtual int attack() = 0;
		// pure virtual method
		virtual int defense(int damage_attacked) = 0;
    
		// checker
		bool isAlive();
		// getter
		int getArmor();
		// getter 
		int getStrength();
    
		// setter
		void setStrength(int strength);
		// setter
		void setSelected(bool selected);
		bool isSelected();
		void setName(std::string name);
		std::string getName();
		
		void recovery();
    
	protected:
		int armor;
		int strength;
		int fixed_strength;
		bool selected; // turn to true when the character is selected in a fight
    
		std::string name; // project 4 character's name
};

#endif /* CHARACTER_HPP */

