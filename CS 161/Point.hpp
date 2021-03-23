/**************************************************************************
Name:			Brendan Jang
Date:			11/30/2018
Description:	Header file for class Point that contains two doubles that
				represents its x and y coordinates. It should have a
				constructor that takes two double params and initializes
				its coordinates with those values. It should have a default
				constructor that initializes both coordinates to zero. It
				should also contain a method called distanceTo that takes
				as a parameter to the Point that we called the method of.
*************************************************************************/
#include <cmath>
#ifndef POINT_HPP
#define POINT_HPP

// Declare class point that takes two doubles as its x and y coords.
class Point
{
	// Declare private variables for x and y
	private:
		double x;
		double y;

	// Function Prototype
	public:

		// Default constructor
		Point();

		// Overload constructor
		Point(double xValue, double yValue);

		// Mutator functions
		void setXCoord(double xValue);
		void setYCoord(double yValue);

		// Accessor functions
		double getXCoord();
		double getYCoord();
		double distanceTo(const Point &p);
};
#endif
