/***************************************************************************** 
** Program Name:	Final Project - Node.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Node class.
*****************************************************************************/

#include "Node.hpp"

/**
 * constructor
 */
Node::Node() {
    item = 0;
    next = 0;
}

/**
 * constructor
 * @param item item
 * @param next next node
 */
Node::Node(Item * item, Node* next) {
    this->item = item;
    this->next = next;
}

/**
 * destructor
 */
Node::~Node() {
    // we free the memory manual in Game
}