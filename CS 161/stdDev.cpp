/******************************************************************************
Author:			Brendan Jang
Date:			11/05/2018
Description:	Function stdDev that takes two params - an array of Person
				objects and the size of the array - and returns the standard
				deviation of all the ages.
******************************************************************************/
#include <cmath>
#include "Person.hpp"

double stdDev(Person personArray[], int sizeArray)
{
	// Initialize 0 to variables:
	double sum = 0;
	double summation = 0;

	// Get sum of all values in array
	for(int i = 0; i < sizeArray; ++i)
	{
		sum += personArray[i].getAge();
	}

	// Get average of all values in array
	double average = sum / sizeArray;

	// Summation for standard deviation equation
	for(int k = 0; k < sizeArray; ++k)
	{
		summation += pow((personArray[k].getAge() - average), 2);
	}

	// Standard deviation equation
	double std_1 = sqrt(summation / sizeArray);

	return std_1;
}
