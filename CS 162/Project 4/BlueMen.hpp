/******************************************************************************
** Program Name:	Project 4 - BlueMen.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for BlueMen class.
******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"


class BlueMen : public Character {
	public:
		// constructor
		BlueMen();
		// copy constructor
		BlueMen(const BlueMen& orig);
		// destructor 
		virtual ~BlueMen();
		// overriding method
		int attack() override;
		// overriding method
		int defense(int damage_attacked) override;

	private:

};

#endif /* BLUEMEN_HPP */