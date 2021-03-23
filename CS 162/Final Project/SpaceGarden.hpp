/***************************************************************************** 
** Program Name:	Final Project - SpaceGarden.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space Garden class.
*****************************************************************************/

#ifndef SPACEGARDEN_HPP
#define SPACEGARDEN_HPP

#include "Space.hpp"

class SpaceGarden : public Space {
	public:
		SpaceGarden();
		virtual ~SpaceGarden();
		void action(Player* player) override;

	private:
		/**
		* watering the garden
		*/
		void watering();
};

#endif /* SPACEGARDEN_HPP */