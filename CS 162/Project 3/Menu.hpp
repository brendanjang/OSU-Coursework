/******************************************************************************
** Program Name:	Project 3 - Menu.hpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Header file for Menu class.
******************************************************************************/

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
    // Get legal selection
    int getSelection(string * message, int size);
    // Get legal input value
    int getValue(string * messages, int size, int min_val, int max_val);
    double getValue(string message, double min_val, double max_val);
private:
    
};

#endif /* MENU_HPP */
