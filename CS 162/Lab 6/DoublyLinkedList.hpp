/*****************************************************************************
** Program Name:	Lab 6 - DoublyLinkedList.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for doubly-linked object. It has a head pointer
					that points to the first Node in the linked list, and a 
					tail pointer that points to the last Node in the linked 
					list. If the linked list is empty, the head and tail should
					point to NULL. If the linked list has only one Node object
					the head and tail should both point to that Node object.
*****************************************************************************/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class DoublyLinkedList {
public:
    // Constructor 
    DoublyLinkedList();

    // Destructor 
    virtual ~DoublyLinkedList();
    
    // Required functions 
    void addToHead(int val);
    void addToTail(int val);
    void deleteHead();
    void deleteLast();
    void traveseReversely();
    void travese();
    
    // Additional function for extra credit
    void clear();    
    bool isRmpty();
    Node * getHead();
    Node * getTail();
private:
    // Pointer to head and tail node of the list
    Node * head;
    Node * tail;
};

#endif /* DOUBLYLINKEDLIST_HPP */
