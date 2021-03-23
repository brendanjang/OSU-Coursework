/***************************************************************************** 
** Program Name:	Final Project - List.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for List class.
*****************************************************************************/

#include "List.hpp"
#include "Menu.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * constructor
 * @param capacity, a human has 2 hands so he can carry 2 items at most
 */
List::List(int capacity) {
    head = 0;
    size = 0;
    this->capacity = capacity;
}

/**
 * destructor 
 */
List::~List() {
    Node * tmp;
    // move to the end of list
    while (head != 0) {
        tmp = head;
        head = head->next;
        // free memory
        delete tmp;
    }
    head = 0;
    size = 0;
}

/**
 * look for item 
 * @param item
 * @return true if item is in the list
 */
bool List::contain(const Item * item) {
    Node * tmp = head;
    // move to the end of list
    while (tmp != 0) {
        // found it
        if (tmp->item == item) {
            // return it
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

/**
 * add item to list
 * @param item
 * @return true if item could be inserted
 */
bool List::push(Item * item) {
    // bad case 
    if (isFull()) {
        return false;
    }
    // not contain it
    if (contain(item) == false) {
        // add it
        Node * n = new Node(item, head);
        head = n;
        size++;
        return true;
    }
    return false;
}

/**
 * remove item from list
 * @param item
 */
void List::remove(Item* item) {
    Node * curr = head;
    Node * prev = 0;

    // find it
    while (curr != 0
            && curr->item != item) {
        prev = curr;
        curr = curr->next;
    }
	
	// nothing is found
    if (curr == 0) { 
        return;
    }

    // found it
    if (curr->item == item) {
        if (prev == 0) { // remove head
            head = head->next;
        } else {
            // remove other node
            prev->next = curr->next;
        }
        delete curr;
        size--;
    }
}

/**
 * checker
 * @return true if it's full
 */
bool List::isFull() {
    return size >= capacity;
}

/**
 * show content of the list
 */
void List::show() {
    if (head == 0) {
        cout << "Empty Bag\n";
    } else {
        cout << "Bag:\n";
        // move to the end of list
        Node * tmp = head;
        while (tmp != 0) {
            // show each item in the list
            cout << "\t" << tmp->item->getName()
                    << ": " << tmp->item->getDescription() << "\n";
            tmp = tmp->next;
        }
    }
}

/**
 * checker
 * @return true if list is empty
 */
bool List::empty() {
    return head == 0;
}

/**
 * ask and return pointer to an item in the list
 * @return pointer to an item
 */
Item* List::find() {
    /// get vector of item in the list
    vector<Item *> vt;
    Node * tmp = head;
    while (tmp != 0) {
        vt.push_back(tmp->item);
        tmp = tmp->next;
    }
    
    // get vector of message
    vector<string> ms;
    ms.push_back("What item do you want to drop");
    string line;
    for (int i = 0; i < vt.size(); i++) {
        Item * item = vt[i];
        line = to_string(i) + ". "
                + item->getName() + ": " + item->getDescription();
        ms.push_back(line);
    }
    
    // turn vector in to array
    string messasge[ms.size()];
    copy(ms.begin(), ms.end(), messasge);
    Menu menu;
    
    // get the item
    int selection = menu.getValue(messasge, ms.size(), 0, ms.size() - 1);

    return vt[selection];

}