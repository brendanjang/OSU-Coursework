/****************************************************************************
**	Program Name:	Lab 4 - Menu.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Menu class. Has at least 4 options:
					1. Prints information about all the buildings, 2. Prints 
					information of everybody at the university, 3. Choose a 
					person to do work, 4. Exit the program. If option 3 is 
					selected, the program should print another menu that 
					prints all the people's name and let the user input the
					choice of the person the user would like, to do work.
*****************************************************************************/

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
