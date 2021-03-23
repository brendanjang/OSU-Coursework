/*************************************************************************
** Author:		Brendan Jang
** Date:		10/02/2018
** Description: Converts Celsius temperature input by user into Fahrenheit
				temperature.
*************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Initialize variables
	double celsiusTemp, fahrenheitTemp;

	// Prompt user for Celsius tempereature and store in variable.
	cout << "Please enter a Celsius temperature." << endl;
	cin >> celsiusTemp;
	
	// Convert into fahrenheit and store in variable.
	fahrenheitTemp = (9.0/5.0) * celsiusTemp + 32;

	// Print convereted tempereature
	cout << "The equivalent Fahrenheit temperature is:" << endl
		 << fahrenheitTemp << endl;

	return 0;
}
