/*************************************************************************
** Program name:	Lab 1 - readMatrix.cpp
** Author:			Brendan Jang
** Date:			1/13/2019
** Description:		Implementation file for function readMatrix that takes
					2 params - a pointer to a 2D array and an integer as
					the size of the matrix - and prompts the user for all
					the numebrs within the matrix.
*************************************************************************/

#include "readMatrix.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void readMatrix(int **pointer, int size)
{
	int item = 0;

	// Calculate number of items
	item = size * size;

	cout << "Enter " << item << " numbers: ";

	// Get numbers per row
	for (int i = 0; i < size; i++)
	{
		// per column
		for (int j = 0; j < size; j++)
		{
			cin >> pointer[i][j];
		}
	}		
}
