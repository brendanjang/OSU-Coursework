/******************************************************************************
** Program Name:	Project 4 - LinkedList.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for LinkedList class.
******************************************************************************/

#include "LinkedList.hpp"

/**
 * constructor
*/	
LinkedList::LinkedList() {
	// all pointers point to null
    head = 0;
    tail = 0;
}

/**
 * destructor
*/	
LinkedList::~LinkedList() {
	// clear all 
    clear();
}

/**
 * add new charater to head of list
*/	
void LinkedList::addToHead(Character* val) {
    if (val == 0) {
        throw "Null parameter";
    }
    // create new node
    Node * tmp = new Node();
    tmp->next = head;
    tmp->obj = val;
    tmp->prev = 0;
	
	// trival case 
    if (isEmpty() == true) {
        tail = tmp;
    }
    head = tmp;
}

/**
 * add to the tail of the list
*/	
void LinkedList::addToTail(Character* val) {
    if (val == 0) {
        throw "Null parameter";
    }
    // create new node
    Node * tmp = new Node();
    tmp->next = 0;
    tmp->obj = val;
    tmp->prev = tail;

	// trival case 
    if (isEmpty() == true) {
        head = tmp;
    } else {
    	// non trival case
        tail->next = tmp;        
    }
    tail = tmp;
}

/**
 * clear all node in the list
*/	
void LinkedList::clear() {
    Node * tmp = head;
    while (head != 0) {
        tmp = head;
        head = head->next;
        // clear data
        delete tmp->obj;
        /// clear node
        delete tmp;
    }
    tail = 0;
}

/**
 * remove head of list
*/	
Character * LinkedList::removeHead() {
    if (head == 0) {
        throw "Empty linked list";
    }
    Node * tmp = head;
    head = head->next;
    if (head == 0) {
        tail = 0;
    } else {
        head->prev = 0;
    }
    // set all pointers to null
    tmp->next = 0;
    tmp->prev = 0;
    // get the obj out of node
    Character * ch = tmp->obj;
    // free node
    delete tmp;
    return ch;
}

/**
 * remove last node of the list
*/	
Character * LinkedList::removeLast() {
    if (head == 0) {
        throw "Empty linked list";
    }
    // get the node
    Node * tmp = tail;
    tail = tail->prev;
    if (tail == 0) {
        head = 0;
    } else {
        tail->next = 0;
    }
    tmp->prev = 0;
    // get obj out of node
    Character * ch = tmp->obj;
    // free node
    delete tmp;
    return ch;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail;
}

bool LinkedList::isEmpty() {
    return head == 0;
}


