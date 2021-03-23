/******************************************************************************
**	Program Name:	Lab 7 - Circular Linked List - main.cpp
**	Author:			Brendan Jang
**	Date:			2/23/2019
**	Description:	Main program file for Circular Linked List program.
******************************************************************************/

#include <cstdlib>
#include <string>
#include <climits>
#include <iostream>
#include "Menu.hpp"
#include "Queue.hpp"

using namespace std;

void addValue(Queue & queue);

int main(int argc, char** argv) {
    Menu menu;
    Queue queue;
    int val;

    string options[] = {
        "Choose from following options:\n",
        "1. Enter a value to be added to the back of queue",
        "2. Display first node (front) value",
        "3. Remove first node (front) value",
        "4. Display the queue contents",
        "5. Exit"
    };

    cout << "Welcome to my queue!\n\n";

    // Get user's selection
    int selection = menu.getValue(options, 6, 1, 5);
    while (selection != 5) {

        switch (selection) {
            case 1:
                addValue(queue);
                break;
            case 2:
                try {
                    val = queue.getFront();
                    cout << "The first node value is: " << val << "\n";
                } catch (const char* msg) {
                    cout << msg << "\n";
                }
                break;
            case 3:
                try {
                    queue.removeFront();
                } catch (const char* msg) {
                    cout << msg << "\n";
                }
                break;
            case 4:
                cout << "Your queue is: ";
                queue.printQueue();
                cout << "\n";
                
                break;
        }

        cout << "\n";
        selection = menu.getValue(options, 6, 1, 5);
    }



    return 0;
}

void addValue(Queue & queue) {
    Menu menu;
    // Get user's input
    string message = "Please enter a positive integer:";
    int val = menu.getValue(&message, 1, 0, INT_MAX);
    // Add value to queue 
    queue.addBack(val);
}
