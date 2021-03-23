/**************************************************************************
** Program Name:	Project 1 - Menu.hpp
** Author: 			Brendan Jang
** Date:			1/19/2019
** Description:		Header file for Menu class. When the program starts,
					the menu provides 2 options: Start Langton's Ant or
					Quit. If user decides to quit, program should quit. If
					else, start the simulation. After start, the program
					should prompt user for all the information to run the
					simulation.
**************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using namespace std;

class Menu 
{
	public:
    	// Constructor
    	Menu(string * list, int size);

    	// Copy constructor
    	Menu(const Menu& orig);

    	// Destructor
    	virtual ~Menu();

    	// Getter
    	int getSelection();    
	private:
		// Array of options
    	string * list;
		// Number options
    	int size;
};

#endif /* MENU_HPP */

