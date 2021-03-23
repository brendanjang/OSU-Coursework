/***************************************************************************** 
** Program Name:	Final Project - SpaceKitchen.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space Kitchen class.
*****************************************************************************/

#ifndef SPACEKITCHEN_HPP
#define SPACEKITCHEN_HPP

#include "Space.hpp"

class SpaceKitchen : public Space {
	public:
		SpaceKitchen();
		virtual ~SpaceKitchen();
		void action(Player* player) override;

	private:

};

#endif /* SPACEKITCHEN_HPP */