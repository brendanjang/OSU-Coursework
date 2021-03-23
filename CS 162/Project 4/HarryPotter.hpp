/******************************************************************************
** Program Name:	Project 4 - HarryPotter.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for HarryPotter class.
******************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
	public:
		// constructor
		HarryPotter();
		// copy constructor
		HarryPotter(const HarryPotter& orig);
		// destructor
		virtual ~HarryPotter();
		// overriding method
		int attack() override;
		// overriding method
		int defense(int damage_attacked) override;

	private:
		int live; // number of live
};

#endif /* HARRYPOTTER_HPP */

