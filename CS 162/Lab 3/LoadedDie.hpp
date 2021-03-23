/**************************************************************************
Program Name:	War Game with Dice Design - LoadedDie.hpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Header file for LoadedDie class. This class inherits the
				behavior and elemnts of Die class. However, for the die
				rolling function, the number it returns is biased such that
				the average output of rolling it for several times is
				higher than that of a Die object with the same number of
				sides.
**************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

// LoadedDie class inherits the behavior of Die
class LoadedDie : public Die
{
	public:
		// Constructor
		LoadedDie(int N);

		// Copy constructor
		LoadedDie(const LoadedDie& orig);

		// Destructor
		virtual ~LoadedDie();
		int getRandom();
	private:

};

#endif /* LOADEDDIE_HPP */
