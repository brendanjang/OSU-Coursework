/***************************************************************************** 
** Program Name:	Final Project - SpaceStreet.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space Street class.
*****************************************************************************/

#ifndef SPACESTREET_HPP
#define SPACESTREET_HPP

#include "Space.hpp"

class SpaceStreet : public Space {
	public:
		SpaceStreet();    
		virtual ~SpaceStreet();
		void action(Player* player) override;

	private:
    
};

#endif /* SPACESTREET_HPP */