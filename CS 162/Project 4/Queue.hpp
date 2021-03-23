/******************************************************************************
** Program Name:	Project 4 - Queue.hpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Queue class.
******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "LinkedList.hpp"

class Queue {
	public:
		// cosntructor 
		Queue();    
		// desctructor 
		virtual ~Queue();
		// add to queue
		void enqueue(Character * ch);
		// remove from queue
		Character * dequeue();
		// checker
		bool isEmpty();
	private:
		LinkedList ll;
};

#endif /* QUEUE_HPP */

