/******************************************************************************
** Program Name:	Project 4 - Queue.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Queue class.
******************************************************************************/

#include "Queue.hpp"

/**
 * constructor
*/	
Queue::Queue() {
}

/**
 * destructor
*/	
Queue::~Queue() {
}

/**
 * remove item from queue
*/	
Character* Queue::dequeue() {
    return ll.removeHead();
}

/**
 * add item to queue
*/	
void Queue::enqueue(Character* ch) {
    ll.addToTail(ch);
}

/**
 * checker
*/	
bool Queue::isEmpty() {
    return ll.isEmpty();
}
