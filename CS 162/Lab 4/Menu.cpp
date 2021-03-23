/****************************************************************************
**	Program Name:	Lab 4 - Menu.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Menu class. Has at least 4 
					options: 1. Prints information about all the buildings, 
					2. Prints information of everybody at the university, 
					3. Choose a person to do work, 4. Exit the program. If 
					option 3 is selected, the program should print another 
					menu that prints all the people's name and let the user
					input the choice of the person the user would like, to do
					work.
*****************************************************************************/

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
* Get valid input
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
        getline(cin, input);
        // Try to turn input to an integer
        try {
            val = stoi(input);
        } catch (exception const & ex) {
            val = min_val - 1;
        }
    }
    return val;
}

double Menu::getValue(string message, double min_val, double max_val) {
    double val;
    string input;
    do {
        cout << message << "(" << min_val << ", " << max_val << ") ";
        getline(cin, input);

        try {
            val = stod(input);
        } catch (exception const & ex) {
            val = min_val - 1;
        }

    } while (val < min_val || val > max_val);

    return val;
}
