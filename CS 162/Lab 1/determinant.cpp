/*************************************************************************
** Program name:	Lab 1 - determinant.cpp
** Author:			Brendan Jang
** Date:			1/13/2019
** Description:		Implementation file for function determinant. Has two
					params - a pointer to a 2D array and an integer as the
					size of the matrix. The function takes in the 2D array
					and calculates the determinant then returns it.
*************************************************************************/

#include "determinant.hpp"

int determinant(int ** pointer, int size)
{
	if (size ==2)
	{
		// 2x2 matrix case
		return pointer[0][0] * pointer[1][1] - pointer[0][1] 
				* pointer[1][0];
	}
	else if (size == 3)
	{
		// 3x3 matrix case
		return pointer[0][0] * (pointer[1][1] * pointer[2][2] - pointer[1][2]
				* pointer[2][1]) - pointer[0][1] * (pointer[1][0]
				* pointer[2][2] - pointer[1][2] * pointer[2][0])
				+ pointer[0][2] * (pointer[1][0] * pointer[2][1]
				- pointer[2][0] * pointer[1][1]);
	}
	// If any other case then ignore
	return 0;
}
