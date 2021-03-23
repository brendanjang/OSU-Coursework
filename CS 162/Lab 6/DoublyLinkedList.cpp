/******************************************************************************
** Program Name:	Lab 6 - DoublyLinkedList.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Implementation file for doubly-linked object. It has a 
					head pointer that points to the first Node in the linked 
					list, and a tail pointer that points to the last Node in 
					the linked list. If the linked list is empty, the head 
					and tail should point to NULL. If the linked list has 
					only one Node object, the head and tail should both point 
					to that Node object.
*****************************************************************************/

#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

/*
* Constructor 
* All pointer points to null
*/
DoublyLinkedList::DoublyLinkedList() {
    head = 0;
    tail = 0;
}

/*
* Destructor
*/
DoublyLinkedList::~DoublyLinkedList() {
    // Clear all allocated memory
    clear();
}

/*
* Add to head of the list
* @param val node's value
*/
void DoublyLinkedList::addToHead(int val) {

    // Allocate memory
    Node * n = new Node();
    // Set its value
    n->setVal(val);
    // Set address of next pointer
    n->setNext(head);

    // The list is empty at the moment
    if (tail == 0) {
        tail = n;
    } else {
        // The list isn't empty at the moment
        head->setPrev(n);
    }
    // Add to head so head pointer points to the newly created node
    head = n;
}

/*
* Add to tail of the list
* @param val node's value
*/
void DoublyLinkedList::addToTail(int val) {

    // Allocate memory
    Node * n = new Node();
    // Set its value
    n->setVal(val);
    // Set address of previous pointer
    n->setPrev(tail);

    // The list is empty at the moment
    if (tail == 0) {
        head = n;
    } else {
        // The list isn't empty at the moment
        tail->setNext(n);
    }
    // Add to tail so tail pointer points to the newly created node
    tail = n;
}

/*
* Remove head of the list
*/
void DoublyLinkedList::deleteHead() {

    // Empty list
    if (head == 0) {
        return;
    }

    // Pointer points to the head
    Node * tmp = head;

    // Move head to the next node
    head = head->getNext();

    // List is empty now 
    if (head == 0) {
        tail = 0;
    } else {
        // List isn't empty 
        head->setPrev(0);
    }
    // Free a block of memory
    delete tmp;
}

/*
* Remove tail of the list
*/
void DoublyLinkedList::deleteLast() {
    // Empty list
    if (tail == 0) {
        return;
    }

    // Pointer points to the tail
    Node * tmp = tail;
    // Move head to the previous  node
    tail = tail->getPrev();

    // List is empty now 
    if (tail == 0) {
        head = 0;
    } else {
        // List isn't empty 
        tail->setNext(0);
    }
    // Free a block of memory
    delete tmp;
}

/*
* Travel from head to tail
* print value out
*/
void DoublyLinkedList::travese() {
    // Point to head
    Node * tmp = head;
    
    // Move forward until pointing to null
    while (tmp != 0) {
        cout << tmp->getVal() << " ";
        tmp = tmp->getNext();
    }
    cout << "\n";
}

/*
* Travel from tail to head
* Print value out 
*/
void DoublyLinkedList::traveseReversely() {
    Node * tmp = tail;
    
    // Move backwards until pointing to null
    while (tmp != 0) {
        cout << tmp->getVal() << " ";
        tmp = tmp->getPrev();
    }
    cout << "\n";
}

/*
* Free all allocated memory
*/
void DoublyLinkedList::clear() {
    Node * tmp;
    while (head != 0) {
        tmp = head;
        head = head->getNext();
        delete tmp;
    }
    head = 0;
    tail = 0;
}

/*
* Checker
* @return true if the list is empty
*/
bool DoublyLinkedList::isRmpty() {
    return head == 0;
}

/*
* Getter
* @return pointer to head node
*/
Node* DoublyLinkedList::getHead() {
    return head;
}

/*
* Getter
* @return pointer to tail node 
*/
Node* DoublyLinkedList::getTail() {
    return tail;
}
