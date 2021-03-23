/*************************************************************************
Name:			Brendan Jang
Date:			11/19/2018
Description:	Implementation file for class Point that contains two 
				doubles that represent its x- and y-coordinates. It should
				have get and set methods for both fields. It should have a 
				constructor that takes two double parameters and 
				initializes its coordinates with those values. It should 
				have a default constructor that initializes both 
				coordinates to zero.  It should also contain a method 
				called distanceTo that takes as a parameter another Point 
				and returns the distance from the Point that was passed as 
				a parameter to the Point that we called the method of.
*************************************************************************/
#include "Point.hpp"

// Default constructor
// Calls set methods to initialize coordinates to 0
Point::Point()
{
	setXCoord(0.0);
	setYCoord(0.0);
}

// Overload constructor.
// Takes 2 parameters and passes them to get methods
Point::Point(double xValue, double yValue)
{
	setXCoord(xValue);
	setYCoord(yValue);
}

// Mutator function to set x coordinate
void Point::setXCoord(double xValue)
{
	x = xValue;
}

// Mutator function  to set y coordinate
void Point::setYCoord(double yValue)
{
	y = yValue;
}

// Accessor function to get x coordinate
double Point::getXCoord()
{
	return x;
}

// Accessor to get y coordinate
double Point::getYCoord()
{
	return y;
}

/**************************************************************************
Description:  Method to calculate the distance between points. Takes const
Point &p (address) as parameter.
**************************************************************************/
double Point::distanceTo(const Point &p)
{
	return sqrt(pow((x - p.x), 2) +
			pow((y - p.y), 2));
}
