/**************************************************************************
** Program Name:	Project 1 - Ant.cpp
** Author:			Brendan Jang
** Date:			1/19/2019
** Description:		Implementation file for class Ant. The ant starts at a
					user specified location on the board. For the initial 
					direction of the ant, it can be either random, or 
					fixed, or a choice from the user. During each step, the
					program should print the board. If the space is 
					occupied by an ant, no matter what the color of that 
					square is, the program should print a “*” on that space;
					otherwise, if the space is white space, print a space 
					character, and if the space is a black space, print a
					“#” character.
**************************************************************************/
#include "Ant.hpp"

/*
Constructor
*/
Ant::Ant() 
{
    x = 0;
    y = 0;
    orient = 0;
}

/*
Copy constructor
@param o
*/
Ant::Ant(const Ant& o) 
{
    x = o.x;
    y = o.y;
    orient = o.orient;
}

/*
Destructor
*/
Ant::~Ant() 
{
}

/*
Getter
@return orientation
*/
int Ant::getOrientation() const 
{
    return orient;
}

/*
Getter
@return x
*/
int Ant::getX() const 
{
    return x;
}

/*
Getter
@return y
*/
int Ant::getY() const 
{
    return y;
}

/*
Set orientation
@param orient
*/
void Ant::setOrient(int orient) 
{
    this->orient = orient;
}

/*
Set x value
@param x
*/
void Ant::setX(int x) 
{
    this->x = x;
}

/*
Set y value
@param y
*/
void Ant::setY(int y) 
{
    this->y = y;
}
