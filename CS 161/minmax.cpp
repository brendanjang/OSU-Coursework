/***********************************************************************
Author:			Brendan Jang
Date:			10/08/2018
Description:	Program that asks user how many integers they want to
				input and ask them to input that many integers. Then
				find and display min and max of those numbers.
***********************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Create variables
	int count, num, inputVal, min = 0, max = 0;

	// Prompt user for input and initialize input into num
	cout << "How many integers would you like to enter?" << endl;
	cin >> num;

	// Promput user for "num" number of integer and initialize inputVal
	cout << "Please enter " << num << " integers." << endl;
	cin >> inputVal;

	// Initialize min and max to variable
	min = inputVal;
	max = inputVal;

	// Loop to iterate over each input from user.
	for(count = 1; count < num; count++)
	{
		cin >> inputVal;

		if(inputVal < min)
		{
			min = inputVal;
		}
		else if(inputVal > max)
		{
			max = inputVal;
		}
	}
	// Print result
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;

	return 0;
}
