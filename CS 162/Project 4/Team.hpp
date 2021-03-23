/******************************************************************************
** Program Name:	Project 4 - Team.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Team class.
******************************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP

#include "Queue.hpp"
#include <string>
using namespace std;

class Team : public Queue {
	public:
		Team();
		virtual ~Team();
		void addFighters(int fighterNum);
		void setName(string name);
		void addScore(int point);
    
		string getName();
		int getScore();
	private:
		void addAFighter();
	private:
		int score;
		string name;
};

#endif /* TEAM_HPP */

