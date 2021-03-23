/*************************************************************************
Name:			Brendan Jang
Date:			11/19/2018
Description:	Header file for class LineSegment that contains two 
				Point-pointers, where each holds the address of a Point 
				object that represents an endpoint of the LineSegment. It 
				should have get and set methods for both fields and a 
				constructor that takes the addresses of two Point objects 
				as parameters and initializes the data members with those 
				values. Your LineSegment constructor and set and get 
				methods should only be working with Point-pointers - they
				shouldn't do anything with x- and y-coordinates.
**************************************************************************/
#include "Point.hpp"
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

// Declare class LineSegment
class LineSegment
{
	// Declare variables
	private:
		Point p1; 
		Point p2;
	
	// Method function declaration
	public:

		// Default constructor
		LineSegment();

		// Overload constructor
		LineSegment(Point &p1, Point &p2);

		// Mutator functions
		void setEnd1(Point &p);
		void setEnd2(Point &p);
		
		// Accessor functions
		Point &getEnd1();
		Point &getEnd2();
		double length();
		double slope();
		bool isinf();
};
#endif
