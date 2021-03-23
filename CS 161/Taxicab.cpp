/**************************************************************************
Author:			Brendan Jang
Date:			10/24/2018
Description:	File to implement class Taxicab that holds the function
				definitions from header file Taxicab.hpp. 
**************************************************************************/
#include <cmath>
#include "Taxicab.hpp"

// Default constructor
Taxicab::Taxicab()
{
	xCoord = 0;
	yCoord = 0;
	odometer = 0;
} 

// Constructor to set x and y coords
Taxicab::Taxicab(int xNew, int yNew)
{
	xCoord = xNew;
	yCoord = yNew;
	odometer = 0;
}

// Define accessor functions to get x and y coords.
int Taxicab::getXCoord()
{
	return xCoord;
}

int Taxicab::getYCoord()
{
	return yCoord;
}

// Function to return the total distance traveled.
int Taxicab::getDistanceTraveled()
{
	return odometer;
}

// Function to calculate the total moves of x and y.
void Taxicab::moveX(int displacement)
{
	xCoord += displacement;
	odometer += std::abs(displacement);
}

void Taxicab::moveY(int displacement)
{
	yCoord += displacement;
	odometer += std::abs(displacement);
}
// Deconstructor
Taxicab::~Taxicab()
{
}
