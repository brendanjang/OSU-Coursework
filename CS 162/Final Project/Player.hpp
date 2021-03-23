/***************************************************************************** 
** Program Name:	Final Project - Player.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Player class.
*****************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "List.hpp"

class Space;

class Player {
	public:
		/**
		* constructor
		* @param space current space
		*/
		Player(Space * space);
		/**
		* destructor 
		*/
		virtual ~Player();
		/**
		* take itme
		* @param item
		* @return true if the item can be taken
		*/
		bool take(Item * item);
		/**
		* checker
		* @param item
		* @return true if player has the item 
		*/
		bool hasItem(Item * item);
		/**
		* drop an item
		* @param item
		*/
		void drop(Item * item);
		/**
		* get current space
		* @return space
		*/
		Space * getSpace();
		/**
		* set space to player
		* @param space a space
		*/
		void setSpace(Space * space);
		/**
		* show all items
		*/
		void showItems();
		/**
		* checker 
		* @return true if the player holds some items
		*/
		bool hasItem();
		/**
		* ask and drop the item
		* @return return dropped item
		*/
		Item * dropItem();
	private:
		List items;
		Space * space;
};

#endif /* PLAYER_HPP */