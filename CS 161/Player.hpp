/*************************************************************************
Author:			Brendan Jang
Date:			10/30/2018
Description:	Header file for class Player that records name, points,
				rebounds, and assists. Class Player specification file.
**************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
	private:
		// Declare four data members
		std::string name;
		int points;
		int rebounds;
		int assists;

	public:
		// Default constructor
		Player();

		// Constructor that takes four parameters
		Player(std::string userName, int userPoints, 
				int userRebounds, int userAssists);

		// Getters for each data member and setter for each stat
		std::string getName();

		void setPoints(int userPoints);
		int getPoints();

		void setRebounds(int userRebounds);
		int getRebounds();

		void setAssists(int userAssists);
		int getAssists();

		// Bool method that takes Player parameter
		bool hasMorePointsThan(Player p);
};

#endif
