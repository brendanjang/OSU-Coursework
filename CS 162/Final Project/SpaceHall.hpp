/***************************************************************************** 
** Program Name:	Final Project - SpaceHall.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space Hall class.
*****************************************************************************/

#ifndef SPACEHALL_HPP
#define SPACEHALL_HPP

#include "Space.hpp"

class SpaceHall : public Space {
	public:
		SpaceHall();
		virtual ~SpaceHall();
		void action(Player* player) override;

	private:
    
};

#endif /* SPACEHALL_HPP */