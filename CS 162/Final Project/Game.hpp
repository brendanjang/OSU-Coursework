/***************************************************************************** 
** Program Name:	Final Project - Game.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Game class.
*****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include <string>
#include <vector>
using namespace std;

class Game {
	public:
		/**
		* constructor
		* @param runtime
		*/
		Game(int runtime = 600);    
		/**
		* destructor
		*/
		virtual ~Game();
		/**
		* run the game
		*/
		void launch();
	private:
		/**
		* setup the game
		*/
		void setup();
		/**
		* check game status 
		* @return true if game is over
		*/
		bool gameover();
		/**
		* show welcome message
		*/
		void welcomeMessage();
		/**
		* show the map
		*/
		void showMap();
		/**
		* show checklist
		*/
		void showChecklist();
	public:
		// items in the game
		static Item * howToBook;
		static Item * toolBox;
		static Item * gateKey;
		static Item * bread;
		static Item * broom;
    
		// spaces in the game
		static Space * street;
		static Space * hall;
		static Space * basement;
		static Space * bedroom;
		static Space * kitchen;
		static Space * gardern;
    
	private:
		// list of spaces and items
		vector<Space *> universe;
		vector<Item *> items;
    
		// player
		Player * player;
    
		// running time 
		int runtime;
};

#endif /* GAME_HPP */