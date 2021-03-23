/**************************************************************************
Program Name:	War Game with Dice Design - Game.cpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Implementation file for class Game. This class implements
				the dice-rolling war game.
**************************************************************************/

#include "Game.hpp"
#include "Menu.hpp"
#include "LoadedDie.hpp"

#include <climits>
#include <iostream>
#include <iomanip>

using namespace std;

/*
Constructor
*/
Game::Game()
{
}

/*
Copy constructor
@param orig a game
*/
Game::Game(const Game& orig)
{
}

/*
Destructor
*/
Game::~Game()
{
}

/*
Start of a game
*/
void Game::start()
{
	// Create menu
	Menu menu;
	// First ask
	string first_ask [] =
	{
		"1. Play Game",
		"2. Exit Game"
	};
	int selection;

	// Get user's first choice
	selection = menu.getSelection(first_ask, 2);
	if (selection == 1)
	{
		// Play the game if user chooses 1
		play();
	}
}

/*
Play the game
*/
void Game::play()
{
	// Create menu
	Menu menu;
	// Required questions
	string question_1 = "How many rounds will be played?";
	string question_21 = "The number of sides for die of player 1";
	string question_22 = "The number of sides for die of player 2";
	string question_31 = "Enter the type of die for player 1";
	string question_32 = "Enter the type of die for player 2";

	// Get number of rounds
	int rounds = menu.getValue(&question_1, 1, 1, INT_MAX - 2);

	// Set up die to each player
	int sides_1 = menu.getValue(&question_21, 1, 1, 100);
	Die * die_1 = getDie(question_31, sides_1);
	int sides_2 = menu.getValue(&question_22, 1, 1, 100);
	Die * die_2 = getDie(question_32, sides_2);

	// Reset score number
	score_1 = 0;
	score_2 = 0;

	// Show each round
	cout << "------------------------------------------\n";
	cout << setw(22) << "Rolling result" << setw(19) << "Score result\n";
	cout << setw(6) << "Round" << setw(9) << "Player_1"
			<< setw(9) << "Player_2" << setw(9) << "Player_1"
			<< setw(9) << "Player_2" << "\n";
	for (int i = 0; i < rounds; i++)
	{
		cout << setw(4) << i + 1;
		round(die_1, die_2);
	}

	cout << "------------------------------------------\n";

	// Free allocated Memory
	delete die_1;
	delete die_2;

	// Show final messages
	cout << "Final score:\n";
	cout << "Player_1: " << score_1 << "\n";
	cout << "Player_2: " << score_2 << "\n";
	cout << "The final winner is: ";
	if (score_1 > score_2)
	{
		cout << "Player_1";
	}
	else if (score_1 < score_2)
	{
		cout << "Player_2";
	}
	else
	{
		cout << "None";
	}
	cout << "\n";
}

/*
Play a round
@param die_1
@param die_2
*/
void Game::round(Die* die_1, Die* die_2)
{
	// Roll each die
	int val_1 = die_1->getRandom();
	int val_2 = die_2->getRandom();

	// Set up the result of a round and update total scores
	int s1, s2;
	s1 = s2 = 0;
	if (val_1 > val_2)
	{
		s1 = 1;
		score_1++;
	}
	else if (val_1 < val_2)
	{
		s2 = 1;
		score_2++;
	}

	// Show results of the current round
	cout << setw(7) << val_1 << setw(9) << val_2 << setw(9) << s1
			<< setw(9) << s2 << "\n";
}

/*
Allocate a die based on the selection of the user
@param message a part of the final message
@param sides numbe rof side of the die
@return a die or loaded die
*/
Die* Game::getDie(string message, int sides)
{
	// Create menu
	Menu menu;
	// Message
	string messages [] =
	{
		message,
		"1. Die",
		"2. Loaded Die"
	};

	// Make a die based on the selection
	Die * die;
	if (menu.getValue(messages, 3, 1, 2) == 1)
	{
		die = new Die(sides);
	}
	else
	{
		die = new LoadedDie(sides);
	}

	return die;
}
