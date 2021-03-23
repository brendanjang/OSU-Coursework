/*************************************************************************
** Program Name:	Lab 2 - main.cpp
** Author:			Brendan Jang
** Date:			1/18/2019
** Description:		Main function file for File I/O. Program asks user for
					the file the user would like to read, then read the
					file chosen by the user. The program will continue
					counting letters until the EOF character. For each
					paragraph in the input file, the program should count
					the frequency of each letters, ask user what filename
					to output to, then proceed to output the frequencies to
					each file. Each paragraph should have its own output
					file.
**************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "countLetters.hpp"
#include "outputLetters.hpp"
using namespace std;

/*
Main function
@param argc number of passed arguments
@param argv list of passed arguments
@return 1 for bad case, input file cannot be read and 0 for other case.
*/
int main(int argc, char** argv)
{
	// String to get user's input;
	string input;

	// Read the stream
	ifstream in;

	// Array of frequencies
	int * arr;

	// Get user's input
	cout << "Enter the name of input file: ";
	cin >> input;

	// Open file
	in.open(input.c_str(), ios::in);

	// Test for the opening of file
	if (in.is_open() == false)
	{
		cout << "Input file cannot be read\n";
		return 1;
	}

	// Initialize the array and allocate the memory
	arr = new int [26];

	// Call function
	count_letters(in, arr);

	// Close input file
	in.close();

	// Deallocate the memory
	delete [] arr;
	return 0;
}
