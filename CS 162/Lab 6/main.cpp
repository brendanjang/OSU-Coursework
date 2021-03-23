/*****************************************************************************
** Program Name:	Lab 6 - main.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Main program file for Doubly-linked List program.
*****************************************************************************/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <climits>

#include <string>
#include "Menu.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

// Function prototypes 
void function1(DoublyLinkedList &ddl);
void function2(DoublyLinkedList &ddl);
void function3(DoublyLinkedList &ddl);
void function4(DoublyLinkedList &ddl);
void function5(DoublyLinkedList &ddl);
void function6(DoublyLinkedList &ddl);
void function7(DoublyLinkedList &ddl);
void function8(DoublyLinkedList &ddl);
void function9(DoublyLinkedList &ddl);

int main(int argc, char** argv) {
    Menu menu;
    DoublyLinkedList ddl;
    string options [] = {
        "Choose from the following options:",
        "1. Add new node to head;",
        "2. Add new node to tail;",
        "3. Delete the first node in the list;",
        "4. Delete the last node in the list;",
        "5. Traverse the list reversely;",
        "6. Exit;",
        "7. Print the value of the node the head is pointing to;",
        "8. Print the value of the node the tail is pointing to;",
        "9. Create a linked list by reading from a text file;"
    };

    cout << "Welcome to my linked list!\n";
    int selection = menu.getValue(options, 10, 1, 9);
    
    // Main loop
    while (selection != 6) {
        switch (selection) {
            case 1:
                function1(ddl);
                break;
            case 2:
                function2(ddl);
                break;
            case 3:
                function3(ddl);
                break;
            case 4:
                function4(ddl);
                break;
            case 5:
                function5(ddl);
                break;
            case 7:
                function7(ddl);
                break;
            case 8:
                function8(ddl);
                break;
            case 9:
                function9(ddl);
                break;
        }
        // get user's selection
        selection = menu.getValue(options, 10, 1, 9);
    }


    return 0;
}

/*
* Add a positive number to the head of the list
* @param ddl reference to a double linked list object
*/
void function1(DoublyLinkedList &ddl) {
    Menu menu;
    string message = "Please enter a positive integer:";
    int val = menu.getValue(&message, 1, 0, INT_MAX);
    ddl.addToHead(val);
    function6(ddl);
}

/*
* Add a positive number to the end of the list
* @param ddl reference to a double linked list object
*/
void function2(DoublyLinkedList &ddl) {
    Menu menu;
    string message = "Please enter a positive integer:";
    int val = menu.getValue(&message, 1, 0, INT_MAX);
    ddl.addToTail(val);
    function6(ddl);
}

/*
* Remove the first node in the list
* @param ddl reference to a double linked list object
*/
void function3(DoublyLinkedList &ddl) {
    ddl.deleteHead();
    function6(ddl);
}

/*
* Remove the last node in the list
* @param ddl reference to a double linked list object
*/
void function4(DoublyLinkedList &ddl) {
    ddl.deleteLast();
    function6(ddl);
}

/*
* Print all node from tail to head
* @param ddl reference to a double linked list object
*/
void function5(DoublyLinkedList &ddl) {
    cout << "Your current linked list is: ";
    if (ddl.isRmpty() == true) {
        cout << "empty\n";
    } else {
        ddl.traveseReversely();
    }
}

/*
* Print all node from head to tail
* @param ddl reference to a double linked list object
*/
void function6(DoublyLinkedList &ddl) {
    cout << "Your current linked list is: ";
    if (ddl.isRmpty() == true) {
        cout << "empty\n";
    } else {
        ddl.travese();
    }
}

/*
* EC Task 2A
* @param ddl reference to a double linked list object
*/
void function7(DoublyLinkedList &ddl) {
    if (ddl.isRmpty() == true) {
        cout << "Nothing\n";
    } else {
        cout << ddl.getHead()->getVal() << "\n";
    }
}

/*
* EC Task 2B
* @param ddl reference to a double linked list object
*/
void function8(DoublyLinkedList &ddl) {
    if (ddl.isRmpty() == true) {
        cout << "Nothing\n";
    } else {
        cout << ddl.getTail()->getVal() << "\n";
    }
}

/*
* EC Task 2
* @param ddl reference to a double linked list object
*/
void function9(DoublyLinkedList &ddl) {
    cout << "Enter file name: ";
    string path;
    getline(cin, path);
    fstream in;
    in.open(path, ios::in);
    if (in.is_open() == false) {
        cout << "File cannot be read\n";
        return;
    }
    ddl.clear();
    int val;
    while (in >> val) {
        ddl.addToTail(val);
    }
    in.close();
    function6(ddl);
}
