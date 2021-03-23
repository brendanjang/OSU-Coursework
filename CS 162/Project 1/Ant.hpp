/**************************************************************************
** Program Name:	Project 1 - Ant.hpp
** Author:			Brendan Jang
** Date:			1/19/2019
** Description:		Header file for class Ant in Langton's Ant Program. Ant
					starts at a user specified location on the board.
					Initial direction of the ant is fixed, random or
					choice. Prints board during each step. If space is
					occupied by an ant, the program should print a "*" on
					that space. Otherwise, print a space character, and if
					the space is a black space, print a "#" character.
**************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant 
{
	public:
    	// Constructor
    	Ant();

    	// Copy constructor
    	Ant(const Ant& orig);

    	// Destructor
    	virtual ~Ant();

    	// Setter
    	void setX(int x);
    	void setY(int y);
    	void setOrient(int orient);
    
    	// Getter 
    	int getX() const;
    	int getY() const;
    	int getOrientation() const;
	private:
    	// Ant's location
    	int x;
    	int y;

    	// Ant's orientation
    	int orient;
};

#endif /* ANT_HPP */
