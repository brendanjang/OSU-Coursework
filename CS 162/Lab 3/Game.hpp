/**************************************************************************
Program Name:	War Game with Dice Design - Game.hpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Header file for class Game. This class implements the dice-
				rolling war game.
**************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "Die.hpp"

using namespace std;

class Game
{
	public:
		Game();
		Game(const Game& orig);
		virtual ~Game();
		void start();
	private:
		void play();
		Die * getDie(string message, int sides);
		void round(Die * die_1, Die * die_2);
		// Scores of players
		int score_1;
		int score_2;
};

#endif /* GAME_HPP */
