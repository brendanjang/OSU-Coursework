/******************************************************************************
** Program Name:	Project 4 - Medusa.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Medusa class.
******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
	public:
		// constructor
		Medusa();
		// copy constructor
		Medusa(const Medusa& orig);
		// destructor
		virtual ~Medusa();
		// overriding method
		int attack() override;
		// overriding method
		int defense(int damage_attacked) override;

	private:

};

#endif /* MEDUSA_HPP */

