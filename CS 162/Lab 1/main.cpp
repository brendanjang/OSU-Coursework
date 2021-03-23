/*****************************************************************************
** Program name:	Lab 1 - main.cpp
** Author:			Brendan Jang
** Date:			1/13/2019
** Description:		Main function file for the matrix calculator. Asks user
					to choose the size of the matrix (2x2 or 3x3), dynamically
					allocates the memory space for the matrix, using readMatrix
					to prompt the user to enter 4 or 9 integers to fill the
					matrix, calculate the determinant, and display both the
					matrix and determinant to the use.
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using namespace std;

int main(int argc, char** argv)
{
	// Declare and allocate array of 3 pointers
	int ** pointer = new int *[3];
	int size;
	size = 0;

	// Try to get the right size of the matrix
	while (size != 2 && size !=3)
	{
		cout << "Enter matrix size: ";
		cin >> size;
	}

	// Allocate memory for each pointer in the array
	for (int i = 0; i < size; i++)
	{
		pointer[i] = new int [size];
	}

	// Read matrix from console
	readMatrix(pointer, size);

	// Show result
	cout << "determinant: " << determinant(pointer, size) << "\n";
	cout << "matrix:\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << pointer[i][j] << "\t";
		}
		cout << "\n";
	}

	// Free allocated memory
	for (int i = 0; i < 3; i++)
	{
		// Free each pointer
		delete [] pointer[i];
	}

	// Free the pointer
	delete pointer;

	return 0;
}
