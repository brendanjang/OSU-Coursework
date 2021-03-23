/***************************************************************************** 
** Program Name:	Final Project - SpaceBedroom.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Heasder file for Space Bedroom class.
*****************************************************************************/

#ifndef SPACEBEDROOM_HPP
#define SPACEBEDROOM_HPP

#include "Space.hpp"

class SpaceBedroom : public Space{
	public:
		SpaceBedroom();
		virtual ~SpaceBedroom();
		void action(Player* player) override;

	private:

};

#endif /* SPACEBEDROOM_HPP */