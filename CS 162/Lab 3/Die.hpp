/**************************************************************************
Project Name:	War Game with Dice Design - Die.hpp
Author:			Brendan Jang
Date:			1/2/42019
Description:	Header  file for Die class that has member variable of 
				integer N that represents the number of sides on the die.
				Also has a member function that returns a random integer 
				between 1 and N as the result of rolling the die once.
**************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
	public:
		// Constructor
		Die(int n);

		// Copy Constructor
		Die(const Die& orig);

		// Destructor
		virtual ~Die();

		// Member function to return a random number between 1 and N as
		// the result of rolling the die
		int getRandom();
		int getN()const;
	private:
		// Number of sides on the individual die
		int N;
};

#endif /* DIE_HPP */
