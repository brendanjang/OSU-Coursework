/*********************************************************************************
**	Program Name:	Project 2 - Menu.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Menu class.
*********************************************************************************/

#include "Menu.hpp"
#include <string>
#include <iostream>
using namespace std;

/*
* Constructor
*/
Menu::Menu() {
}

/*
* Copy constructor
* @param orig a menu
*/
Menu::Menu(const Menu& orig) {
}

/*
* Destructor
*/
Menu::~Menu() {
}

/*
* Get the valid input
* @param message array of string
* @param size number of string in the array
* @return a valid input
*/
int Menu::getSelection(string* message, int size) {
    return getValue(message, size, 1, size);
}

/*
* Get the valid input
* @param messages array of message 
* @param size number of string in the array
* @param min_val the minimum expected value
* @param max_val the maximum expected value
* @return a valid value
*/
int Menu::getValue(string* messages, int size, int min_val, int max_val) {
    int val = min_val - 1;
    string input;
    
    // Loop until getting the right input
    while (val < min_val || val > max_val) {
        // Show all messages 
        for (int i = 0; i < size; i++) {
            cout << messages[i] << "\n";
        }        
        cout << "Enter value from " << min_val << " to " << max_val << ": ";        
        // Get input
        cin >> input;
        // Try to turn input to an integer
        try {
            val = stoi(input);
        } catch (exception const & ex) {
            val = min_val - 1;
        }
    }   
    return val;
}
