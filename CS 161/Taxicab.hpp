/*************************************************************************
Author:			Brendan Jang
Date:			10/24/2018
Description:	A header file for class Taxicab. Holds private member
				variables xCoord, yCoord, and odometer. Also holds public
				function declaration for constructing, setting, and getting
				coordinates.
**************************************************************************/
#ifndef TAXICAB_HPP
#define TAXICAB_HPP

// Declare class
class Taxicab
{
	// Private member variables
	private:
		int xCoord;
		int yCoord;
		int odometer;

	public:
		// Declare functions
		// Default constructor with no params
		Taxicab();

		// Overloaded constructor
		Taxicab(int xCoord, int yCoord);

		// Accessor functions to return x, y coords and distance traveled.
		int getXCoord();
		int getYCoord();
		int getDistanceTraveled();
	
		// Modifier functions to move distance
		void moveX(int xCoord);
		void moveY(int yCoord);

		// Deconstructor
		~Taxicab();
};
#endif
