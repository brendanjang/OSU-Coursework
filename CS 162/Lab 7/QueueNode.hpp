/******************************************************************************
**	Program Name:	Lab 7 - Circular Linked List - QueueNode.hpp
**	Author:			Brendan Jang
**	Date:			2/23/2019
**	Description:	Header file for QueueNode struct that represents each node.
					Contains next - a pointer to the next Node object, prev -a 
					pointer to the previous Node object, and val - integer value
					the specific Node contains.
******************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode{
    QueueNode * next; // pointer to the next node
    QueueNode * prev; // pointer to the previous node
    int val; // data
};


#endif /* QUEUENODE_HPP */