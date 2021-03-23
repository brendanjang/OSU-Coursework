/***************************************************************************** 
** Program Name:	Final Project - SpaceBasement.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space Basement class.
*****************************************************************************/

#ifndef SPACEBASEMENT_HPP
#define SPACEBASEMENT_HPP

#include "Space.hpp"
#include <iostream>
using namespace std;

class SpaceBasement : public Space {
	public:
		SpaceBasement();
		virtual ~SpaceBasement();
		void action(Player* player) override;
     
	private:
		/**
		* fixing the washing machine
		* @return 
		*/
		bool fixing();
};

#endif /* SPACEBASEMENT_HPP */