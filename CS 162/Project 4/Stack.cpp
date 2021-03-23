/******************************************************************************
** Program Name:	Project 4 - Stack.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Stack class.
******************************************************************************/

#include "Stack.hpp"

/**
 * constructor
*/	
Stack::Stack() {
}

/**
 * destructor
*/	
Stack::~Stack() {
}
/**
 * checker
*/	
bool Stack::isEmpty() {
    return ll.isEmpty();
}

/**
 * get item from stack
*/	
Character* Stack::pop() {
    return ll.removeHead();
}

/**
 * push item to stack
*/	
void Stack::push(Character* ch) {
    ll.addToHead(ch);
}
