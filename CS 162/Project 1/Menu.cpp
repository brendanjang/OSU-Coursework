/**************************************************************************
** Program Name:	Project 1 - Menu.cpp
** Author:			Brendan Jang
** Date:			1/19/2019
** Description:		Implementation file for Menu function. When the program
					starts the menu provides 2 options: Start Langton's Ant
					simulation or Quit. If user decided to quit, program
					should quit. Otherwise, start the Langton's Ant
					simulator. After simulation starts, the program should
					prompt user for all the information to run the simula-
					tion.
**************************************************************************/

#include "Menu.hpp"
#include <string>
#include <iostream>
using namespace std;

/*
Constructor
@param list array of options 
@param size number of option
*/
Menu::Menu(string* list, int size) 
{
    // Allocate memory
    this->list = new string[size];
    // Copy options
    for (int i = 0; i < size; i++) 
	{
        this->list[i] = list[i];
    }
    // Set up value of size
    this->size = size;
}

/*
Copy constructor
@param o a menu
*/
Menu::Menu(const Menu& o) 
{
    // Allocate memory
    this->list = new string[o.size];
    // Copy data
    for (int i = 0; i < o.size; i++) 
	{
        this->list[i] = o.list[i];
    }
	// Set value of size
    this->size = o.size;
}

/*
Destructor 
*/
Menu::~Menu() 
{
    // Free allocated data
    delete [] list;
}

/*
Show menu, prompt for a legal input 
@return selection
*/
int Menu::getSelection() 
{
    int selection = -1;
    string input;
    do 
	{
        // Show menu
        for (int i = 0; i < size; i++) 
		{
            cout << list[i] << "\n";
        }
        // Get input
        cout << "Enter your selection: ";
        cin >> input;
        // Confirm legal input
        try 
		{
        	selection = stoi(input);
        } 
		catch (exception const & ex) 
		{
            selection = -1;
        }
    } 
	while (selection <= 0 || selection > size);

    return selection;
}
