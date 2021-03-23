/*************************************************************************
Author:			Brendan Jang
Date:			10/30/2018
Description:	The Team class specification file.
*************************************************************************/
#ifndef TEAM_HPP
#define TEAM_HPP
#include "Player.hpp"

// Team class declaration
class Team
{
	// Declare five data members of type Player
	private:
		Player pointGuard, shootingGuard, smallForward,
				powerForward, center;

	// Constructor that takes five Players as params
	public:
		Team(Player, Player ,Player, Player, Player);
		
		// Getters and setters
		void setPointGuard(Player);
		Player getPointGuard();

		void setShootingGuard(Player);
		Player getShootingGuard();

		void setSmallForward(Player);
		Player getSmallForward();

		void setPowerForward(Player);
		Player getPowerForward();

		void setCenter(Player);
		Player getCenter();
		
		// Method for total points
		int totalPoints();
};

#endif
