/******************************************************************************
** Program Name:	Project 3 - main.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Main program file for Fantasy Comabt Game.
******************************************************************************/

#include <cstdlib>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <climits>
using namespace std;

#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Menu.hpp"
#include "Queue.hpp"
#include "Team.hpp"
#include "Stack.hpp"


/**
 * count number of alive character 
 * @param fighters array of fighters
 * @param size number of fighter 
 * @return number of alive fighter 
 */
int aliveFighter(Character ** fighters, int size);

/**
 * get a fighter 
 * @param fighters array of fighter 
 * @param fighter_names name of all fighter 
 * @param size size of the array
 * @return pointer to a chosen character 
 */
Character * getFighter(Character ** fighters, string * fighter_names, int size);

/**
 * attacking 
 * @param a_pair array of 2 fighters 
 * @param index index of attacker 
 */
void attack(Character ** a_pair, int index);

/**
 * play a round
 * @param fighters array of fighter 
 * @param fighter_names name of all fighter 
 * @param size size of the array
 * 
 */
void play(Character ** fighters, string * fighter_names, int size);

//--------------------------------------
// project 4
//--------------------------------------

void setup(Team teams[], int teamNum);

void fight(Character * fighter_1, Character * fighter_2);
void playAGame();

/*
 * 
 */
int main(int argc, char** argv) {

    Menu menu;



    string options_1 [] = {
        "1. Play",
        "2. Exit"
    };
    string options_2 [] = {
        "1. Play again",
        "2. Exit the game"
    };

    int selection = menu.getValue(options_1, 2, 1, 2);

    if (selection == 2) {
        return 0;
    }

    do {
        cout << "\n----------------------------------------------------\n";
        playAGame();
        selection = menu.getValue(options_2, 2, 1, 2);
    } while (selection == 1);

    return 0;
}

void playAGame() {
    const int TEAM_NUM = 2;
    const int WINNER_SCORE = 2;
    const int LOSER_SCORE = -1;
    Team teams[TEAM_NUM];
    setup(teams, TEAM_NUM);

    int round = 1;
    Character * fighter_1;
    Character * fighter_2;
    Stack losers;


    while (teams[0].isEmpty() == false
            && teams[1].isEmpty() == false) {

        //  cout << "Round " << round << ":\n";
        fighter_1 = teams[0].dequeue();
        fighter_2 = teams[1].dequeue();
        fight(fighter_1, fighter_2);


        cout << "Round " << round << ": ";
        cout << "Team " << teams[0].getName() <<
                " " << fighter_1->getName();
        cout << " vs ";
        cout << "Team " << teams[1].getName() <<
                " " << fighter_2->getName();
        cout << ", ";
        if (fighter_1->isAlive()) {
            losers.push(fighter_2);
            
            // HP recovery 
            fighter_1->recovery();
            
            teams[0].enqueue(fighter_1);
            cout << fighter_1->getName();
            teams[0].addScore(WINNER_SCORE);
            teams[1].addScore(LOSER_SCORE);
        } else {
            losers.push(fighter_1);
            
            // HP recovery 
            fighter_2->recovery();
            
            teams[1].enqueue(fighter_2);
            cout << fighter_2->getName();
            teams[1].addScore(WINNER_SCORE);
            teams[0].addScore(LOSER_SCORE);
        }
        cout << " Won!\n";
        // cout << "\n";
        round++;
    }

    cout << "Result:\n";
    for (int i = 0; i < TEAM_NUM; i++) {
        cout << "Team " << teams[i].getName()
                << ": " << teams[i].getScore() << "\n";
    }
    if (teams[0].getScore() > teams[1].getScore()) {
        cout << "Team " << teams[0].getName() << " won";
    } else if (teams[0].getScore() < teams[1].getScore()) {
        cout << "Team " << teams[1].getName() << " won";
    } else {
        cout << "Tie";
    }
    cout << "\n";

    string options [] = {
        "Do you want to print loser pile",
        "1. Yes",
        "2. No"
    };
    Menu menu;


    int selection = menu.getValue(options, 3, 1, 2);

    if (selection == 1) {
        cout << "List of losers:\n";
        while (losers.isEmpty() == false) {
            fighter_1 = losers.pop();
            cout << "\t" << fighter_1->getName() << "\n";
            delete fighter_1;
        }
    } else {
        while (losers.isEmpty() == false) {
            fighter_1 = losers.pop();
            delete fighter_1;
        }
    }
    cout << "\n";

}

void fight(Character * fighter_1, Character * fighter_2) {
    Character ** a_pair = new Character *[2];
    int index;
    int turn = 1;
    a_pair[0] = fighter_1;
    a_pair[1] = fighter_2;

    while (fighter_1->isAlive() == true
            && fighter_2->isAlive() == true) {
        // set the attacking order randomly         
        index = rand() % 2;
        //   cout << "\tTurn " << turn << "\n";
        // do attacking
        //   cout << "\tFirst attacking:\n";
        attack(a_pair, index);
        // cout << "\n";
        //    cout << "\tSecond attacking:\n";
        attack(a_pair, (index + 1) % 2);
        //  cout << "\n";
        turn++;
    }

    delete [] a_pair;

}

void setup(Team teams[], int teamNum) {
    string teamNames [] = {
        "A", "B"
    };
    string message = "Enter number of fighter for both team: ";
    Menu menu;
    // get number of fighter per team 
    int size = menu.getValue(&message, 1, 1, INT_MAX / 2);
    // get fighter for each team
    for (int i = 0; i < teamNum; i++) {
        teams[i].setName(teamNames[i]);
        teams[i].addFighters(size);
    }
}

/**
 * play a round
 * @param fighters array of fighter 
 * @param fighter_names name of all fighter 
 * @param size size of the array
 * 
 */
void play(Character ** fighters, string * fighter_names, int size) {

    int alive = aliveFighter(fighters, size);
    // bad case 
    if (alive == 0) {
        cout << "There isn't any alive fighter\n";
        return;
    }
    // bad case 
    if (alive == 1) {
        cout << "There is online one alive fighter\n";
        return;
    }

    // set array of selected character 
    Character ** a_pair = new Character *[2];
    //    cout << "First fighter:\n";
    a_pair[0] = getFighter(fighters, fighter_names, size);
    a_pair[0]->setSelected(true);
    /*   cout << "\n";
       cout << "Second fighter:\n";*/
    a_pair[1] = getFighter(fighters, fighter_names, size);
    a_pair[1]->setSelected(true);

    // set the attacking order randomly 
    //   cout << "\n";
    int index = rand() % 2;

    // do attacking

    //   cout << "First attacking:\n";
    attack(a_pair, index);
    /*  cout << "\n";
      cout << "Second attacking:\n";*/
    attack(a_pair, (index + 1) % 2);

    // end of match 
    a_pair[0]->setSelected(false);
    a_pair[1]->setSelected(false);
    delete [] a_pair;
}

/**
 * attacking 
 * @param a_pair array of 2 fighters 
 * @param index index of attacker 
 */
void attack(Character ** a_pair, int index) {
    // get pointer to both fighter 
    Character * attacker = a_pair[index];
    Character * defender = a_pair[(index + 1) % 2];

    // get name of each fighter 
    string attacker_type(typeid (*attacker).name());
    // clean number from heading of each string
    attacker_type.erase(
            remove_if(attacker_type.begin(),
            attacker_type.end(),
            [](char ch) {
                return !isalpha(ch);
            }
    ),
    attacker_type.end());

    // do the same to defender's name 
    string defender_type(typeid (*defender).name());
    defender_type.erase(
            remove_if(defender_type.begin(),
            defender_type.end(),
            [](char ch) {
                return !isalpha(ch);
            }
    ),
    defender_type.end());

    // show required information 
    /*  cout << "\tAttacker type: " << attacker_type << "\n";
      cout << "\tDefender type: " << defender_type
              << ", armor: " << defender->getArmor()
              << ", strength point: " << defender->getStrength() << "\n";
     */
    /// attacker should be alive 
    if (attacker->isAlive() == false) {
        //  cout << "\tAttacker has died before\n";
        return;
    }

    // attacking and defending 
    int damage_attacked = attacker->attack();
    int damage_inflicted = defender->defense(damage_attacked);
    // cout << "\tTotal inflicted damage calculation: " << damage_inflicted << "\n";

    // update defender's strength
    defender->setStrength(defender->getStrength() - damage_inflicted);
    /*  cout << "\tThe defender's updated strength "
              << "point amount after subtracting damage: "
              << defender->getStrength() << "\n";
     */
}

/**
 * get a fighter 
 * @param fighters array of fighter 
 * @param fighter_names name of all fighter 
 * @param size size of the array
 * @return pointer to a chosen character 
 */
Character * getFighter(Character ** fighters, string * fighter_names, int size) {
    Character * ch;
    bool unsuccessful = true;
    Menu menu;
    int selection;
    // try to get a legal fighter 
    do {
        cout << "Choose an alive and free fighter\n";
        selection = menu.getValue(fighter_names, size, 0, size - 1);
        ch = fighters[selection];

        // check its states 
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

/**
 * count number of alive character 
 * @param fighters array of fighters
 * @param size number of fighter 
 * @return number of alive fighter 
 */
int aliveFighter(Character ** fighters, int size) {
    int alive = 0;
    // iterate over the array
    for (int i = 0; i < size; i++) {
        // count it if it is alive
        if (fighters[i]->isAlive() == true) {
            alive++;
        }
    }
    return alive;
}
