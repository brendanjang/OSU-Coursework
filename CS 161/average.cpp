/*************************************************************************
**Author:         Brendan Jang
**Date:           10/02/2018
**Description:    Program that asks the user for 5 numbers and then prints
                  an average of those numbers.
*************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// This program gets the average of the user's 5 numbers.
int main()
{
	// Initialize variables
	double  firstNumber, secondNumber, thirdNumber, 
			fourthNumber, fifthNumber, sumNumber,
			averageNumber;

	// Get user input for 5 numbers.
	cout << "Please enter five numbers." << endl;
	cin >> firstNumber >> secondNumber >> thirdNumber
		>> fourthNumber >> fifthNumber;

	// Sum of 5 numbers stored in variable sumNumber
	sumNumber = firstNumber + secondNumber + thirdNumber +
				fourthNumber + fifthNumber;
	
	// Average of 5 numbers stored in variable averageNumber
	averageNumber = sumNumber / 5;

	// Print average
	cout << "The average of those numbers is:" << endl
		 << averageNumber << endl;

	return 0;
}
