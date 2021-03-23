/**************************************************************************
**	Program Name:	Lab 5 - main.cpp
**	Author:			Brendan Jang
**	Date:			2/8/2019
**	Description:	Main implementation file for Recursive Functions
					program.
***************************************************************************/

#include <cstdlib>
#include <string>
#include <iostream>
#include <climits>

#include "Menu.hpp"
using namespace std;

// Required functions
void print(string str);
int sum(int * arr, int size);
int triangular(int n);

// Additional functions 
void function_1();
void function_2();
void function_3();

int main(int argc, char** argv) {
    Menu menu;
    // List of options of the first menu
    string options [] = {
        "1. Function #1",
        "2. Function #2",
        "3. Function #3",
        "4. Quit"
    };

    // Get selection from user  
    int selection = menu.getSelection(options, 4);
    while (selection != 4) {
        
        // Call the right function 
        switch (selection) {
            case 1:
                function_1();
                break;
            case 2:
                function_2();
                break;
            case 3:
                function_3();
                break;
        }
        
        // Get selection
        selection = menu.getSelection(options, 4);
    }

    return 0;
}

/*
* Get a number 
* print triangular number 
*/
void function_3() {
    int max_val = 20000;
    Menu menu;
    string message = "Enter an integer: ";
    int n = menu.getValue(&message, 1, 1, max_val);

    cout << "Triangular number: " << triangular(n) << "\n";

}

void function_2() {
    Menu menu;
    int min_val = INT_MIN / 100;
    int max_val = INT_MAX / 100;
    string message = "Enter number of integer: ";
    int num = menu.getValue(&message, 1, 1, max_val);
    int * arr = new int[num];

    for (int i = 0; i < num; i++) {
        message = "Enter number #" + std::to_string(i + 1);
        arr[i] = menu.getValue(&message, 1, min_val, max_val);
    }

    cout << "Sum = " << sum(arr, num) << "\n";

}

void function_1() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    print(str);
}

int triangular(int n) {
    if (n < 1) {
        return 0;
    }
    return n + triangular(n - 1);
}

int sum(int * arr, int size) {
    if (size <= 0) {
        return 0;
    }
    return arr[0] + sum(arr + 1, size - 1);
}

void print(string str) {
    if (str.length() > 0) {
        if (str[str.length() - 1] != '\n') {
            str += "\n";
            print(str);
            cout << "\n";
        } else {
            print(str.substr(1));
            if (str[0] != '\n') {
                cout << str[0];
            }
        }

    }
}
