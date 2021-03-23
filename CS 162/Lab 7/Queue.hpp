/******************************************************************************
**	Program Name:	Lab 7 - Circular Linked List - Queue.hpp
**	Author:			Brendan Jang
**	Date:			2/23/2019
**	Description:	Header file for Queue class.
******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"


class Queue {
public:
    // Constructor 
    Queue();
    // Destructor
    virtual ~Queue();
    
    // Required methods
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();

private:
    // Header of the queue
    QueueNode * head;
};

#endif /* QUEUE_HPP */