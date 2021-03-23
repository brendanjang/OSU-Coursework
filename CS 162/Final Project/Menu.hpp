/***************************************************************************** 
** Program Name:	Final Project - Menu.hpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Header file for Menu class.
*****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using namespace std;

class Menu {
	public:
		// constructor
		Menu();
		// copy constructor
		Menu(const Menu& orig);
		// destructor
		virtual ~Menu();
		// get legal selection
		int getSelection(string * message, int size);
		// get legal input value
		int getValue(string * messages, int size, int min_val, int max_val);
		double getValue(string message, double min_val, double max_val);
	private:
    
};

#endif /* MENU_HPP */