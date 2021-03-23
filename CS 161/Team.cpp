/*************************************************************************
Author: 			Brendan Jang
Date:				10/30/2018
Description:		Member function definition for class Team that takes
					players to assign as positions. Implementation file
					for class Team.
*************************************************************************/

#include "Team.hpp"
#include "Player.hpp"

/*************************************************************************
 Description: Constructor for class Team with params. Parameters are in
 order: point guard, shooting guard, small forward, power forward, and
 center.
 ************************************************************************/
// Constructor that takes five players
Team::Team(Player p1, Player p2, Player p3, Player p4, Player p5)
{
	pointGuard = p1;
	shootingGuard = p2;
	smallForward = p3;
	powerForward = p4;
	center = p5;
}

// Set players to positions
void Team::setPointGuard(Player newOne)
{
	pointGuard = newOne;
}

void Team::setShootingGuard(Player newTwo)
{
	shootingGuard = newTwo;
}

void Team::setSmallForward(Player newThree)
{
	smallForward = newThree;
}

void Team::setPowerForward(Player newFour)
{
	powerForward = newFour;
}

void Team::setCenter(Player newFive)
{
	center = newFive;
}

// Functions to retrieve player
Player Team::getPointGuard()
{
	return pointGuard;
}

Player Team::getShootingGuard()
{
	return shootingGuard;
}

Player Team::getSmallForward()
{
	return smallForward;
}

Player Team::getPowerForward()
{
	return powerForward;
}

Player Team::getCenter()
{
	return center;
}

/*************************************************************************
Description: Define totalPoints and it returns sums of the points
*************************************************************************/
int Team::totalPoints()
{
	return pointGuard.getPoints() + shootingGuard.getPoints()
			+ smallForward.getPoints() + powerForward.getPoints()
			+ center.getPoints();
}
