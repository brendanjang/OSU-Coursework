/**************************************************************************
** Program Name:	Lab 2 - outputLetters.cpp
** Author:			Brendan Jang
** Date:			1/18/2019
** Description:		Implementation file for function output_letters. The
					function takes an output file stream variable, and a
					pointer to an array of integers that contain
					frequencies of letters. The function asks user for the
					filename the user would like to output to, then outputs
					the frequncies of letters to the output file in the
					format specified.
**************************************************************************/

#include "outputLetters.hpp"

/*
Write content of the array to the output stream
@param stm output stream
@param arr the array
*/
void output_letters(ofstream & stm, int * arr)
{
	char ch;
	// Iterate over the array
	for (int i = 0; i < 26; i++)
	{
		// Get the right character in ASCII table
		// 'b' = 'a' + 1
		// 'c' = 'a' + 2
		ch = 'a' + i;
		// Send result to output stream
		stm << ch << ": " << arr[i] << "\n";
	}
}
