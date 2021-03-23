/**************************************************************************
Program Name:	War Game with Dice Design - LoadedDice.cpp
Name:			Brendan Jang
Date:			1/24/2019
Description:	Implementation file for LoadedDie class. Class inherits the
				behavior and elements of Die class. For the Die rolling
				function, the number it returns is biased such that the
				average output of rolling it for several times is higher
				than that of a Die object with the same number of sides.
**************************************************************************/

#include <cstdlib>
#include "LoadedDie.hpp"

/*
Constructor
@param N number of sides
*/
LoadedDie::LoadedDie(int N) : Die(N)
{
}

/*
Copy constructor
@param orig a loaded die
*/
LoadedDie::LoadedDie(const LoadedDie& orig) : Die(orig)
{
}

/*
Destructor
*/
LoadedDie::~LoadedDie()
{
}

/*
Get arandom value
@return a random value
*/
int LoadedDie::getRandom()
{
	// Get a random value
	int val = this->Die::getRandom();

	// Such that the average output of rolling it for several times
	// is higher than that of a Die object with the same number of size.
	if (rand() % 2 == 0)
	{
		// Happens sometimes
		if (val < this->getN())
		{
			// A loaded die cannot roll a number that is higher than the
			// number of sides it has.
			val++;
		}
	}
	return val;
}
