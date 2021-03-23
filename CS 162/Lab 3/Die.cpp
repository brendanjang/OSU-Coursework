/**************************************************************************
Program Name:	War Game with Dice Design - Die.cpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Implementation file for Die class that has a member variable
				of an integer N that represents the number of sides on the
				individual die. Also has a member function that returns a 
				random integer between 1 and N as the result of rolling the
				die once.
**************************************************************************/

#include <cstdlib>
#include "Die.hpp"

/*
Constructor
@param n Number of sides
*/
Die::Die(int n)
{
	this->N = n;
}

/*
Copy constructor
@param orig A die
*/
Die::Die(const Die& orig)
{
	N = orig.N;
}

/*
Destructor
*/
Die::~Die()
{
}

/*
Roll the die
@return a number between 1 and N
*/
int Die::getRandom()
{
	return 1 + (rand() % N);
}

/*
Getter
@return N
*/
int Die::getN() const
{
	return N;
}
