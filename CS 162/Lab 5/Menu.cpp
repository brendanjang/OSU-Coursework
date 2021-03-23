/***************************************************************************
**	Program Name:	Lab 5 - Menu.cpp
**	Author:			Brendan Jang
**	Date:			2/8/2019
**	Description:	Implementation file for Menu. The menu should provide
					user choices to select one of the three functions to
					call, after prompting user input for function call and
					the function outputs results, the menu should go back
					to the first menu to let the user continue choosing
					functions to call. If user choose function #1, the menu
					should prompt the user to enter a string and your
					program reversely prints the string. If user chooses
					function #2, the menu should first prompt the user an
					integer input for the number of integers in the array,
					then a series of integers to fill the array. Afterwards,
					the program prints sum of the array of integers. If the
					user chooses function #3, the menu should prompt the
					user an integer, then the program prints the triangular
					number of that number. In addition to the 3 function
					options inside the first menu, the menu must also
					provide the option to quit the program. You can add
					input validation functions into these the menu to make
					it robust.
***************************************************************************/

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
* Get legal input
* @param message array of string
* @param size number of string in the array
* @return a legal input
*/
int Menu::getSelection(string* message, int size) {
	return getValue(message, size, 1, size);
}

/*
* Get legal input
* @param messages array of message
* @param size number of string in the array
* @param min_val the minimum expected value
* @param max_val the maximum expected value
* @return a legal value
*/
int Menu::getValue(string* messages, int size, int min_val, int max_val) {
	int val = min_val - 1;
	string input;

	// Loop until receiving the right input
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
		}
		catch (exception const & ex) {
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
		}
		catch (exception const & ex) {
			val = min_val - 1;
		}

	} while (val < min_val || val > max_val);

	return val;
}
