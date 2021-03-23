/*************************************************************************
Author:			Brendan Jang
Date:			10/30/2018
Description:	Member function definitions for class Player. Records name,
				points, rebounds, and assists. Implementation file Player
				class.
**************************************************************************/
#include "Player.hpp"
#include "Team.hpp"
#include <string>
#include <iostream>

/**************************************************************************
Description: Function initializes the variables to default values. Name to
empty string and stats to -100. Default constructor to initialize variables.
**************************************************************************/
Player::Player()
{
	name = "";
	points = -100;
	rebounds = -100;
	assists = -100;
}

/**************************************************************************
Description: Function that takes four params and initializes the 
data members to those params.
***************************************************************************/
Player::Player(std::string userName, int userPoints, 
				int userRebounds, int userAssists)
{
	name = userName;
	points = userPoints;
	rebounds = userRebounds;
	assists = userAssists;
}

// Getters and setters for data members name, points, rebounds, and assists
std::string Player::getName()
{
	return name;
}

void Player::setPoints(int userPoints)
{
	points = userPoints;
}

int Player::getPoints()
{
	return points;
}

void Player::setRebounds(int userRebounds)
{
	rebounds = userRebounds;
}

int Player::getRebounds()
{
	return rebounds;
}

void Player::setAssists(int userAssists)
{
	assists = userAssists;
}

int Player::getAssists()
{
	return assists;
}

/*************************************************************************
Description: Bool method to check if user Player has more points that 
Player passed in parameter. Returns true or false depending on who has more
points.
***************************************************************************/
bool Player::hasMorePointsThan(Player p)
{
	if(points > p.getPoints())
	{
		return true;
	}
	else
	{
		return false;
	}
}
