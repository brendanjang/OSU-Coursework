/******************************************************************************
** Program Name:	Project 4 - LinkedList.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for LinkedList class.
******************************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Character.hpp"

/**
 * structure of a node
 */
struct Node {
    Node * next; // to the next node
    Node * prev; // to the previous node
    Character * obj; // data of the node
};

class LinkedList {
public:
	// constructor
    LinkedList();
    // destructor 
    virtual ~LinkedList();
	
	// add character to list
    void addToHead(Character * val);
    void addToTail(Character * val);
    
    // remove character from list
    Character * removeHead();
    Character * removeLast();
    
    // clear list
    void clear();
    
    // getter    
    bool isEmpty();
    Node * getHead();
    Node * getTail();
    
    
private:
    Node * head;
    Node * tail;
};

#endif /* LINKEDLIST_HPP */

