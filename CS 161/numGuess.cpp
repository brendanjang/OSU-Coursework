/*****************************************************************************
Author:			Brendan Jang
Date:			10/10/2018
Description:	Program that prompts user for an integer and has a player try
				to guess integer. If answer is too high or too low, tell the
				player and have them try again until guessed correctly. Then 
				show the player how many tries it too.
*****************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Declare variables
	int number, guess, count = 1;

	// Prompt user for the number to guess
	cout << "Enter the number for the player to guess." << endl;
	cin >> number;

	// Get the player's guess
	cout << "Enter your guess." << endl;
	do
	{
	cin >> guess;

	// Loop to see if guess too high or low
	if(guess > number)
	{
		cout << "Too high - try again." << endl;
	}
	else if(guess < number)
	{
		cout << "Too low - try again." << endl;
	}
	// If guessed correctly, tell in how many tries
	else
	{
		cout << "You guessed it in "
			 << count << " tries." << endl;
		break;
	}

	count++;
	}
	while(1);

	return 0;
}
