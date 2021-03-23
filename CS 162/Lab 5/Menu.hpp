/**************************************************************************
**	Program Name:	Lab 5 - Menu.hpp
**	Author:			Brendan Jang
**	Date:			2/8/2019
**	Description:	Header file for Menu. The menu should provide user
					choices to select one of the three functions to call,
					after prompting user input for function call and the 
					function outputs results, the menu should go back to the
					first menu to let the user continue choosing functions
					to call. If user choose function #1, the menu should
					prompt the user to enter a string and your program
					reversely prints the string. If user chooses function
					#2, the menu should first prompt the user an integer
					input for the number of integers in the array, then a
					series of integers to fill the array. Afterwards, the
					program prints sum of the array of integers. If the 
					user chooses function #3, the menu should prompt the
					user an integer, then the program prints the triangular
					number of that number. In addition to the 3 function 
					options inside the first menu, the menu must also
					provide the option to quit the program.
***************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using namespace std;

class Menu {
public:
	// Constructor
	Menu();
	// Copy constructor
	Menu(const Menu& orig);
	// Destructor
	virtual ~Menu();
	// Get valid selection
	int getSelection(string * message, int size);
	// Get valid input value
	int getValue(string * messages, int size, int min_val, int max_val);
	double getValue(string message, double min_val, double max_val);
private:

};

#endif /* MENU_HPP */
