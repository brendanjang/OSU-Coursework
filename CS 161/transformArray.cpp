/**********************************************************************
Name:			Brendan Jang
Date:			11/13/2018
Description:	Function that takes two paramaters - a reference to a
				pointer to a dynamically allocated array of ints, and
				the size of that array. The function dynamically
				allocates an array that is twice as long filled with
				the values from the original array followed by each of
				those values plus 1.
***********************************************************************/
#include <iostream>

using std::cout;
using std::endl;

// Function prototype
void transformArray(int *&inputArray, int size)
{
	// Allocate memory for new array
	int *newArray = new int[size * 2];

	// For loop to get element = new array
	for (int i = 0; i < size; ++i)
	{
		newArray[i] = inputArray[i];
	}

	// Loop to transform the elements in the new array
	for (int i = 0; i < size; ++i) 
	{
		newArray[size + i] = inputArray[size - i - 1] + i;
	}

	// Delete memory for created array
	delete[] inputArray;
	inputArray = newArray;
}

/*
int main()
{
	int* myArray = new int[3];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;

	transformArray(myArray, 3);

	for (int i = 0; i < 6; i++)
		cout << myArray[i] << endl;

	delete []myArray;
}
*/
