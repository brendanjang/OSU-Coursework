/******************************************************************************
** Program Name:	Project 4 - Team.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Implementation file for Team class.
******************************************************************************/

#include "Team.hpp"
#include "Menu.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include <iostream>
using namespace std;

/**
 * constructor
*/	
Team::Team() {
    score = 0;
}

/**
 * destructor
*/	
Team::~Team() {
}

/**
 * add a nubmer of fighter to team
*/	
void Team::addFighters(int fighterNum) {
    cout << "Team " << name << ":\n";
    // add characters to team
    for (int i = 0; i < fighterNum; i++) {
        cout << "Character #" << i + 1 << ":\n";
        addAFighter();
    }
    cout << "\n";
}

/**
 * add a fighter to team
*/	
void Team::addAFighter() {
    string fighter_names [] = {
        "Choose a fighter",
        "0. Vampire",
        "1. Barbarian",
        "2. Blue men",
        "3. Medusa",
        "4. Harry Potter"
    };
    Menu menu;
    Character * ch;
    int selection = menu.getValue(fighter_names, 6, 0, 4);

    // create a character
    switch (selection) {
        case 0:
            ch = new Vampire();
            break;
        case 1:
            ch = new Barbarian();
            break;
        case 2:
            ch = new BlueMen();
            break;
        case 3:
            ch = new Medusa();
            break;
        case 4:
            ch = new HarryPotter();
            break;
    }

    // get and set name of character 
    cout << "Enter name of the character: ";
    string name;
    getline(cin, name);
    ch->setName(name);

    // push to team
    this->enqueue(ch);
}

void Team::setName(string name) {
    this->name = name;
}

void Team::addScore(int point) {
    score += point;
}

string Team::getName() {
    return name;
}

int Team::getScore() {
    return score;
}

