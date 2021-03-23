/***************************************************************************** 
** Program Name:	Final Project - Space.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Space class.
*****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include "Item.hpp"
#include "Player.hpp"
#include "Menu.hpp"
using namespace std;

class Space {
	public:
		/**
		* constructor
		*/
		Space();
		/**
		* destructor
		*/
		virtual ~Space();
		/**
		* pure virtual method
		* @param player
		*/
		virtual void action(Player * player) = 0;
		/**
		* 
		* @param direction
		* @return pointer to a neighbor 
		*/
		Space * getNeighbor(int direction);
		/**
		* set neighbor 
		* @param direction position
		* @param space pointer 
		* @return true if we can set it
		*/
		bool setNeighbor(int direction, Space * space);
		/**
		* add item to space
		* @param item
		*/
		void addItem(Item * item);
		/**
		* check for item in space
		* @param item
		* @return true if the item is in the space
		*/
		bool hasItem(Item * item);
		/**
		* get index of the space
		* @return 
		*/
		int getIndex();
    
		/**
		* get name of space
		* @return name
		*/
		string getName();
		/**
		* checker
		* @return true if the task of this space is fulfilled
		*/
		bool isFinished();
    
		/**
		* show the space
		*/
		void show();
		/**
		* the player takes item
		* @param player
		*/
		void takeItem(Player * player);
		/**
		* the player drops item
		* @param player
		*/
		void dropItem(Player * player); 
		/**
		* 
		* @return task of this space
		*/
		string getTask();
    
	protected:
		/**
		* generate messages
		*/
		vector<string> actionMessage();
		vector<string> itemMessage();
		vector<string> doorMessage();
    
		/**
		* move player to another space
		* @param player
		*/
		void moveAway(Player * player);
    
		/**
		* action that takes in all spaces
		* @param player
		* @return 
		*/
		int normalAction(Player * player);
	public :
		static const int SPACE_NUM = 4;
		static const int SPACE_TOP = 0;
		static const int SPACE_LEFT = 1;
		static const int SPACE_BOTTOM = 2;
		static const int SPACE_RIGHT = 3;
       
		static int counter;    
    
		static const int TAKE_ITEM = 1;
		static const int DROP_ITEM = 2;
		static const int SHOW_ITEM = 3;
		static const int MOVE_AWAY = 4;    
		static const int DO_SOMETHING = 5;
   
    
	protected:    
		int index;
		string name;
		string task;
    
		Space * neighbors [SPACE_NUM];
		vector<Item *> items;
		bool finished;
		Menu menu;
};

#endif /* SPACE_HPP */