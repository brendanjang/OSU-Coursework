/******************************************************************************
**	Program Name:	Lab 7 - Circular Linked List - Queue.cpp
**	Author:			Brendan Jang
**	Date:			2/23/2019
**	Description:	Implementation file for Queue class.
******************************************************************************/

#include "Queue.hpp"
#include <iostream>
using namespace std;

/*
* Constructor 
*/
Queue::Queue() {
    head = 0; // point to null
}

/*
* Destructor
*/
Queue::~Queue() {
    
    QueueNode * tmp;
    // Stop when the head is null
    while (head != 0) {
        // Store pointer to current head
        tmp = head;
        // Alter it
        head = head->next;
        // Free the old head
        delete tmp;
    }
    // Set head to null
    head = 0;
}

/*
* @return true if head is null
*/
bool Queue::isEmpty() {
    return head == 0;
}

/*
* Add new value to back of the queue
* @param val
*/
void Queue::addBack(int val) {

    // Trivial case 
    if (isEmpty() == true) {
        // Allocate new memory      
        head = new QueueNode();
        // Set up pointers and data
        head->next = 0;
        head->prev = 0;
        head->val = val;
    } else {
        // Move to the end of the list 
        QueueNode * tmp = head;
        while (tmp->next != 0) {
            tmp = tmp->next;
        }

        // Allocate new memory        
        tmp->next = new QueueNode();
        // Set up pointers and data
        tmp->next->next = 0;
        tmp->next->prev = tmp;
        tmp->next->val = val;
    }
}

/*
* Get front of the queue
* @return an integer 
*/
int Queue::getFront() {
    
    // bad case 
    if (isEmpty() == true) {
        // throw exception
        throw "Empty queue";
    }
    return head->val;
}

/*
* Remove front of a queue 
*/
void Queue::removeFront() {
    
    // Bad case
    if (isEmpty() == true) {
        // throw exception
        throw "Empty queue";
    }
    // Get head 
    QueueNode * tmp = head;
    // Alter the current head
    head = head->next;
    
    // Alter previous pointer of the new head
    if (head != 0) {
        head->prev = 0;
    }
    // free the old head
    delete tmp;
}

/*
* Print the queue
*/
void Queue::printQueue() {
    // start from the head
    QueueNode * tmp = head;
    
    // move to the end of queue 
    while (tmp != 0) {
        // show data
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}