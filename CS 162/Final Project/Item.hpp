/***************************************************************************** 
** Program Name:	Final Project - Item.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Item class.
*****************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Item {
	public:
		/**
		* constructor
		* @param name name
		* @param description extra information
		*/
		Item(string name = "", string description = "");
		/**
		* copy constructor
		* @param orig
		*/
		Item(const Item& orig);
		/**
		* destructor
		*/
		virtual ~Item();
		/**
		* getter
		* @return  name
		*/
		string getName();
		/**
		* getter
		* @return  description
		*/
		string getDescription();
		
	protected:
		// name of item
		string name;
		// extra information of the itme
		string description;
		
	private:
    
};

#endif /* ITEM_HPP */