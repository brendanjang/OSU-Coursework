/*****************************************************************************
** Program Name:	Lab 9 - main.cpp
** Author:			Brendan Jang
** Date:			3/8/2019
** Description:		Main program file for Stack and Queue STL Containers
					program.
*****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>

#include "Menu.hpp"
using namespace std;

/**
 * @return a random number form 1 to 100
 */
int generateNumber();

/**
 * play a round
 * @param front percentage chance to take out a nubmer 
 * @param end percentage chance to put in a number
 * @param container the queue
 * @param ALi_1 previous average length of buffer 
 * @param i round number
 * @return current average length of buffer 
 */
double aRound(int front, int end, queue<int> & container, double ALi_1, int i);

/**
 * task 1
 */
void buffer();


/**
 * turn a string into a palindrome
 * @param input
 * @return a palindrome
 */
string palindrome(string input);

int main(int argc, char** argv) {

    Menu menu;

    string messages [] = {
        "1. Test the buffer",
        "2. Create a palindrome",
        "3. Quit"
    };
    string input;

    // get option
    int option = menu.getValue(messages, 3, 1, 3);
    while (option != 3) {
        
        // switching 
        switch (option) {
            case 1:
                buffer();
                break;
            case 2:
                cout << "Enter a string: ";
                getline(cin, input);
                cout << palindrome(input);
                break;
        }

        cout << "\n\n";
        // ask for option
        option = menu.getValue(messages, 3, 1, 3);
    }

    return 0;
}

/**
 * turn a string into a palindrome
 * @param input
 * @return a palindrome
 */
string palindrome(string input) {
    stack<char> container;
    string output = "";    
    char ch;
    
    // add character to stack and to the output string
    for (int i = 0; i < input.length(); i++) {
        ch = input[i];
        container.push(ch);
        output += ch;
    }

    // pop item from stack to output string
    while (container.empty() == false) {
        output += container.top();
        container.pop();
    }

    return output;
}

/**
 * task 1
 */
void buffer() {
    Menu menu;
    string message;
    
    // ger number of rounds
    message = "How many round will be simulated";
    int round = menu.getValue(&message, 1, 1, 3000);
    
    // get putting percent
    message = "The percentage chance to put a randomly "
            "generated number at the end of buffer";
    int end_percentage = menu.getValue(&message, 1, 0, 100);
    
    // get popping percent
    message = "The percentage chance to take out a randomly "
            "generated number at the front of buffer";
    int front_percentage = menu.getValue(&message, 1, 0, 100);
    
    double ALi = 0;    
    queue<int> container;
    
    // run the simulator
    for (int i = 1; i <= round; i++) {
        ALi = aRound(front_percentage, end_percentage, container, ALi, i);
    }
}

/**
 * play a round
 * @param front percentage chance to take out a nubmer 
 * @param end percentage chance to put in a number
 * @param container the queue
 * @param ALi_1 previous average length of buffer 
 * @param i round number
 * @return current average length of buffer 
 */
double aRound(int front, int end, queue<int> & container, double ALi_1, int i) {
    
    // generate a number 
    int N = generateNumber();   
    
    // consider adding it to the queue
    if (generateNumber() <= end) {
        container.push(N);
    }
    
    // consider removing a number from queue
    if (generateNumber() <= front
            // container shouldn't be empty
            && container.empty() == false) {
        container.pop();
    }

    // calculate average length
    double ALi = (ALi_1 * (i - 1) + (double) container.size()) / (double) i;

    // try to show all current values of the queue 
    queue<int > tmp;

    cout << "Round: " << i << "\n";
    cout << "\tValues: ";
    while (container.empty() == false) {
        cout << container.front() << " ";
        tmp.push(container.front());
        container.pop();
    }
    cout << "\n";

    cout << "\tLength: ";
    cout << tmp.size() << "\n";
    cout << "\tAverage: " << ALi << "\n";

    // push item back to the container  
    while (tmp.empty() == false) {
        container.push(tmp.front());
        tmp.pop();
    }
    return ALi;
}

/**
 * @return a random number form 1 to 100
 */
int generateNumber() {
    return (rand() % 100) + 1;
}