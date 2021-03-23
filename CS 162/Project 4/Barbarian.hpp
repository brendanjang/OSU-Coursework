/******************************************************************************
** Program Name:	Project 4 - Barbarian.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Barbarian class.
******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"


class Barbarian : public Character{
	public:
		// constructor 
		Barbarian();
		// copy constructor
		Barbarian(const Barbarian& orig);
		// destructor 
		virtual ~Barbarian();
		// overriding method
		int attack() override;
		// overriding method
		int defense(int damage_attacked) override;

	private:

};

#endif /* BARBARIAN_HPP */
