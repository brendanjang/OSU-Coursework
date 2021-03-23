/***************************************************************************** 
** Program Name:	Final Project - Node.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Node class.
*****************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <cstdint>

#include "Item.hpp"


class Node {
	public:
		/**
		* constructor
		*/
		Node();
		/**
		* constructor
		* @param item item
		* @param next next node
		*/
		Node(Item * item, Node * next);   
		/**
		* destructor
		*/
		virtual ~Node();
	public:
		Item * item;
		Node * next;
};

#endif /* NODE_HPP */