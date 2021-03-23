/***********************************************************************
** Name:		Brendan Jang
** Date:		10/02/2018
** Description: Prompt user for integer number of cents below 100.
				Output how many of each type of coin would represent
				that amount.
***********************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Initialize variables
	int cents, quarters, dimes,
		nickels, pennies, sumCents;
	
	// Prompt user for amount in cents <= 99 and sotre in cents
	cout << "Please enter an amount in cents " 
		 << "less than a dollar." << endl;
	cin >> cents;

	// Calculate coins and store in variables.
	quarters = cents / 25;
	dimes = (cents % 25) / 10;
	sumCents = (25 * quarters) + (10 * dimes);
	nickels = (cents - sumCents) / 5;
	pennies = ((cents - sumCents) - (5 * nickels)) / 1;

	cout << "Your change will be:" << endl
		 << "Q: " << quarters << endl
		 << "D: " << dimes << endl
		 << "N: " << nickels << endl
		 << "P: " << pennies << endl;

	return 0;
}
