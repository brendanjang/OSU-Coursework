/************************************************************************** 
Program Name:	War Game with Dice Design - Menu.hpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Header file for class Menu that asks the user to select 
				from 2 choices Play game or Exit game. Ask set of questions
				if user selects Play game. If user selects Exit, exit the
				game.
**************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using namespace std;

class Menu
{
	public:
    	// Constructor
    	Menu();
    	// Copy constructor
    	Menu(const Menu& orig);
    	// Destructor
    	virtual ~Menu();
    	// Get legal selection
    	int getSelection(string * message, int size);
    	// Get legal input value
    	int getValue(string * messages, int size, int min_val, int max_val);
	private:
    
};

#endif /* MENU_HPP */
