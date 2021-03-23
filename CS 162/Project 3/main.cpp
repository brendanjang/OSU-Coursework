/******************************************************************************
** Program Name:	Project 3 - main.cpp
** Author:			Brendan Jang
** Date:			2/15/2019
** Description:		Main program file for Fantasy Comabt Game.
******************************************************************************/

#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Menu.hpp"


/*
* Count number of alive characters
* @param fighters array of fighters
* @param size number of fighter 
* @return number of alive fighter 
*/
int aliveFighter(Character ** fighters, int size);

/*
* Get a fighter 
* @param fighters array of fighters
* @param fighter_names name of all fighters
* @param size size of the array
* @return pointer to a chosen character 
*/
Character * getFighter(Character ** fighters, string * fighter_names, int size);

/*
* Attacking 
* @param a_pair array of 2 fighters 
* @param index index of attacker 
*/
void attack(Character ** a_pair, int index);

/*
* Play a round
* @param fighters array of fighters
* @param fighter_names name of all fighters 
* @param size size of the array
* 
*/
void play(Character ** fighters, string * fighter_names, int size);

int main(int argc, char** argv) {

    const int FIGHTER_NUM = 5;
    Menu menu;
    BlueMen bm;
    Barbarian bb;
    HarryPotter hp;
    Medusa ms;
    Vampire vp;
    
    // Create a list of pointers to characters 
    Character ** fighters = new Character * [FIGHTER_NUM];
    
    // Pointer to address of each character 
    fighters[0] = &vp;
    fighters[1] = &bb;
    fighters[2] = &bm;
    fighters[3] = &ms;
    fighters[4] = &hp;

    string options [] = {
        "Which do you want to do",
        "1. Play again",
        "2. Exit the game"
    };
    string fighter_names [] = {
        "0. Vampire",
        "1. Barbarian",
        "2. Blue men",
        "3. Medusa",
        "4. Harry Potter"
    };

    int selection;
    
    do {
        cout << "\n";
        play(fighters, fighter_names, FIGHTER_NUM);
        cout << "\n-------------------------------------\n";
        selection = menu.getValue(options, 3, 1, 2);
    } while (selection != 2);

    // Free the array
    delete [] fighters;
    return 0;
}

/*
* Play a round
* @param fighters array of fighters 
* @param fighter_names name of all fighters 
* @param size size of the array
*/
void play(Character ** fighters, string * fighter_names, int size) {
    
    int alive = aliveFighter(fighters, size);
    // Bad case 
    if (alive == 0) {
        cout << "There isn't any alive fighter\n";
        return;
    }
    // Bad case 
    if (alive == 1) {
        cout << "There is only one alive fighter\n";
        return;
    }
    
    // Set array of selected character 
    Character ** a_pair = new Character *[2];
    cout << "First fighter:\n";
    a_pair[0] = getFighter(fighters, fighter_names, size);
    a_pair[0]->setSelected(true);
    cout << "\n";
    cout << "Second fighter:\n";
    a_pair[1] = getFighter(fighters, fighter_names, size);
    a_pair[1]->setSelected(true);
    
    // Set the attacking order randomly 
    cout << "\n";
    int index = rand() % 2;
    
    // Do attacking
    
    cout << "First attacking:\n";
    attack(a_pair, index );
    cout << "\n";
    cout << "Second attacking:\n";
    attack(a_pair, (index + 1) % 2);
    
    // End of match 
    a_pair[0]->setSelected(false);
    a_pair[1]->setSelected(false);
    delete [] a_pair;
}

/*
* Attacking 
* @param a_pair array of 2 fighters 
* @param index index of attacker 
*/
void attack(Character ** a_pair, int index) {
    // Get pointer to both fighters 
    Character * attacker = a_pair[index];
    Character * defender = a_pair[(index + 1) % 2];

    // Get name of each fighter 
    string attacker_type(typeid (*attacker).name());
    // Clean number from heading of each string
    attacker_type.erase(
            remove_if(attacker_type.begin(),
            attacker_type.end(),
            [](char ch) {
                return !isalpha(ch);
            }
    ),
    attacker_type.end());

    // Do the same to defender's name 
    string defender_type(typeid (*defender).name());
    defender_type.erase(
            remove_if(defender_type.begin(),
            defender_type.end(),
            [](char ch) {
                return !isalpha(ch);
            }
 	),
    defender_type.end());

    // Show required information 
    cout << "Attacker type: " << attacker_type << "\n";
    cout << "Defender type: " << defender_type
            << ", armor: " << defender->getArmor()
            << ", strength point: " << defender->getStrength() << "\n";

    // Attacker should be alive 
    if (attacker->isAlive() == false) {
        cout << "Attacker has died before\n";
        return;
    }
    
    // Attacking and defending 
    int damage_attacked = attacker->attack();
    int damage_inflicted = defender->defense(damage_attacked);
    cout << "Total inflicted damage calculation: " << damage_inflicted << "\n";

    // Update defender's strength
    defender->setStrength(defender->getStrength() - damage_inflicted);
    cout << "The defender's updated strength "
            << "point amount after subtracting damage: "
            << defender->getStrength() << "\n";
    
}

/*
* Get a fighter 
* @param fighters array of fighters 
* @param fighter_names name of all fighters 
* @param size size of the array
* @return pointer to a chosen character 
*/
Character * getFighter(Character ** fighters, string * fighter_names, int size) {
    Character * ch;
    bool unsuccessful = true;
    Menu menu;
    int selection;
    // Try to get a legal fighter 
    do {
        cout << "Choose an alive and free fighter\n";
        selection = menu.getValue(fighter_names, size, 0, size - 1);
        ch = fighters[selection];
        
        // Check its states 
        if (ch->isAlive() == true) {
            if (ch->isSelected() == true) {
                cout << "The selected figher has been selected before\n";
            } else {
                unsuccessful = false;
            }
        } else {
            cout << "The selected figher died already\n";
        }
    } while (unsuccessful == true);

    return ch;
}

/*
* Count number of alive character 
* @param fighters array of fighters
* @param size number of fighter 
* @return number of alive fighter 
*/
int aliveFighter(Character ** fighters, int size) {
    int alive = 0;
    // Iterate over the array
    for (int i = 0; i < size; i++) {
        // Count it if it is alive
        if (fighters[i]->isAlive() == true) {
            alive++;
        }
    }
    return alive;
}
