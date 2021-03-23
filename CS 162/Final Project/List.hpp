/***************************************************************************** 
** Program Name:	Final Project - List.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for List class.
*****************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <cstdint>

#include "Node.hpp"

class List {
	public:
		/**
		* constructor
		* @param capacity, a human has 2 hands so he could carry 2 items at most
		*/
		List(int capacity = 2);
		/**
		* destructor 
		*/
		virtual ~List();
		/**
		* add item to list
		* @param item
		* @return true if item could be inserted
		*/
		bool push(Item * item);
		/**
		* look for item 
		* @param item
		* @return true if item is in the list
		*/
		bool contain(const Item * item);
		/**
		* remove item from list
		* @param item
		*/
		void remove(Item * item);
		/**
		* checker
		* @return true if it's full
		*/
		bool isFull();
		/**
		* show content of the list
		*/
		void show();
		/**
		* checker
		* @return true if list is empty
		*/
		bool empty();
		/**
		* ask and return pointer to an item in the list
		* @return pointer to an item
		*/
		Item * find();
	private:
		// head of list
		Node * head;
		// size of list
		int size;
		// capacity of list
		int capacity;
};

#endif /* LIST_HPP */