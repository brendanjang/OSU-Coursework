/*************************************************************************
Author:			Brendan Jang
Date:			10/24/2018
Description:	File to implement class Box that holds the function
				definitions from header file Box.hpp.
*************************************************************************/
#include "Box.hpp"

// Initialize data member variables to 1
Box::Box()
{
	height = 1.0;
	width = 1.0;
	length =1.0;
}

// Define constructor to access member variables
Box::Box(double heightBox, double widthBox, double lengthBox)
{
	setHeight(heightBox);
	setWidth(widthBox);
	setLength(lengthBox);
}

// Define accessor functions to get volume and surface area formulas
double Box::calcVolume()
{
	return length * width * height;
}
double Box::calcSurfaceArea()
{
	return (2 * length * width) + (2 * length * height) +
	(2 * width * height);
}

// Define setters to replace variable values with new variables
void Box::setLength(double lengthBox)
{
	length = lengthBox;
}
void Box::setWidth(double widthBox)
{
	width = widthBox;
}
void Box::setHeight(double heightBox)
{
	height = heightBox;
}
Box::~Box()
{
}
