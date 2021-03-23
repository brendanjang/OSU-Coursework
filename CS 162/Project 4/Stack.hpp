/******************************************************************************
** Program Name:	Project 4 - Stack.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Header file for Stack class.
******************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"

class Stack {
	public:
		Stack();
		virtual ~Stack();
		void push(Character * ch);
		Character * pop();
		bool isEmpty();
	private:
		LinkedList ll;
};

#endif /* STACK_HPP */