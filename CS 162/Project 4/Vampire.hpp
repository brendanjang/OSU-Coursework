/******************************************************************************
** Program Name:	Project 4 - Vampire.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Vampire class.
******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"


class Vampire : public Character {
	public:
		// constructor
		Vampire();
		// copy constructor
		Vampire(const Vampire& orig);
		// destructor
		virtual ~Vampire();
		// overriding method
		int attack() override;
		// overriding method
		int defense(int damage_attacked) override;

	private:
    
};

#endif /* VAMPIRE_HPP */
