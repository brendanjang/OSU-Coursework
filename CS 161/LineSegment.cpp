/*************************************************************************
Name:			Brendan Jang
Date:			11/19/2018
Description:	Implementation file for class LineSegment that contains 
				two Point-pointers, where each holds the address of a 
				Point object that represents an endpoint of the 
				LineSegment. It should have get and set methods for both 
				fields and a constructor that takes the addresses of two 
				Point objects as parameters and initializes the data 
				members with those values. Your LineSegment constructor 
				and set and get methods should only be working with 
				Point-pointers - they shouldn't do anything with x- and 
				y-coordinates.
*************************************************************************/
#include "LineSegment.hpp"
#include <iostream>

// Default constructor
// Calls set methods to initialize coordinates
LineSegment::LineSegment()
{
	Point p1, p2;
	setEnd1(p1);
	setEnd2(p2);
}

// Constructor takes 2 parameters and passes them to get methods
LineSegment::LineSegment(Point &p1, Point &p2)
{
	setEnd1(p1);
	setEnd2(p2);
}

// Mutator function to set first end point
void LineSegment::setEnd1(Point &p)
{
	p1.setXCoord(p.getXCoord());
	p1.setYCoord(p.getYCoord());
}

// Mutator function to set second end point
void LineSegment::setEnd2(Point &p)
{
	p2.setXCoord(p.getXCoord());
	p2.setYCoord(p.getYCoord());
}

// Accessor function to get first end point
Point &LineSegment::getEnd1()
{
	return p1;
}

// Accessor function to get second end point
Point &LineSegment::getEnd2()
{
	return p2;
}

// Method to get the length of the line
// Call distanceTo function
double LineSegment::length()
{
	return p1.distanceTo(p2);
}

/**************************************************************************
Description: Method to calculate the slope of the line.
**************************************************************************/ 
double LineSegment::slope()
{
	if(p2.getXCoord() - p1.getXCoord() == 0)
	{
		return -55555;
	}
	else
	{
		return(p2.getYCoord() - p1.getYCoord()) /
				(p2.getXCoord() - p1.getXCoord());
	}
}

/*************************************************************************
Description: Method to check the line is slope or not
*************************************************************************/
bool LineSegment::isinf()
{
	if(p2.getXCoord() - p1.getXCoord() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
