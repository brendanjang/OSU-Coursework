/*****************************************************************************
** Program Name:	Lab 6 - Node.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for Node class. Has following member 
					variables: next - a pointer to the next Node object, 
					prev - a pointer to the previous Node object, val - integer
					value the specific Node contains.
*****************************************************************************/

#include "Node.hpp"

/*
* Constructor 
*/
Node::Node() {
    next = 0;
    prev = 0;
}

/*
* Copy constructor 
* @param o node object
*/
Node::Node(const Node& o) {
    next = o.next;
    prev = o.prev;
    val = o.val;
}

/*
* Destructor
*/
Node::~Node() {
}

/*
* Getter
* @return next pointer 
*/
Node* Node::getNext() {
    return next;
}

/**
* Getter
* @return prev pointer 
*/
Node* Node::getPrev() {
    return prev;
}

/**
* Getter
* @return value 
*/
int Node::getVal() {
    return val;
}

/*
* Setter
* @param next next pointer 
*/
void Node::setNext(Node* next) {
    this->next = next;    
}

/*
* Setter
* @param prev previous pointer 
*/
void Node::setPrev(Node* prev) {
    this->prev = prev;
}

/*
* Setter 
* @param val value
*/
void Node::setVal(int val) {
    this->val = val;
}
