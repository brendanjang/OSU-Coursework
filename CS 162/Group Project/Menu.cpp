#include "Menu.hpp"
#include <string>
#include <iostream>
using namespace std;

/**
 * constructor
 */
Menu::Menu() {
}

/**
 * copy constructor
 * @param orig a menu
 */
Menu::Menu(const Menu& orig) {
}

/**
 * destructor
 */
Menu::~Menu() {
}

/**
 * get the legal input
 * @param message array of string
 * @param size number of string in the array
 * @return a legal input
 */
int Menu::getSelection(string* message, int size) {
    return getValue(message, size, 1, size);
}

/**
 * get the legal input
 * @param messages array of message 
 * @param size number of string in the array
 * @param min_val the minimum expected value
 * @param max_val the maximum expected value
 * @return a legal value
 */
int Menu::getValue(string* messages, int size, int min_val, int max_val) {
    int val = min_val - 1;
    string input;

    /// looping until getting the right input
    while (val < min_val || val > max_val) {
        // show all messages 
        for (int i = 0; i < size; i++) {
            cout << messages[i] << "\n";
        }
        cout << "Enter value from " << min_val << " to " << max_val << ": ";
        // get input
        getline(cin, input);
        //cin >> input;
        // try to turn input to an integer
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