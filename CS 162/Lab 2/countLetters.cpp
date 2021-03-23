/**************************************************************************
** Program Name:	Lab 2 - countLetters.cpp
** Author:			Brendan Jang
** Date:			1/18/2019
** Description:		Implementation file for function count_letters. Takes
					an input file stream variable, and a pointer to an
					array of integers. Function reads the paragraph string
					from the input file stream, then counts the letter
					frequencies of that paragraph, and store the
					frequencies in the array. Disregards upper/lower case
					letters.
**************************************************************************/

#include "countLetters.hpp"
#include "outputLetters.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*
Read input stream and count letter and write frequency to a new file.
@param stm input stream
@param arr array of frequencies
*/
void count_letters(ifstream & stm, int * arr)
{
	// Do nothing when the input file can't be read
	if (!stm)
	{
		return;
	}

	char ch;
	string str;
	int index;
	string file_name;
	int paragraph = 1;
	ofstream out;

	// Read paragraph
	while (getline(stm, str))
	{
		// Clean array and reset count
		for (int i = 0; i < 26; i++)
		{
			arr[i] = 0;
		}
		// Count frequency of all letters
		for (unsigned int i = 0; i < str.length(); i++)
		{
			// Get character
			ch = str[i];
			// If it is a letter...
			if (isalpha(ch))
			{
				// Turn it to its lower case
				ch = tolower(ch);
				// Get its index in the array
				// 'a' is at 0, 'b' is at 1, ... , 'z' is at 25
				index = ch - 'a';
				// Update the counter at the right index
				arr[index]++;
			}
		}

		// Prompt for output file name
		cout << "Enter filename to output paragraph #"
				<< paragraph << " to: ";
		cin >> file_name;

		// Open file
		out.open(file_name.c_str(), ios::out);

		// If the file can be written
		if (out.is_open())
		{
			// then write to it
			output_letters(out, arr);
			// then close it
			out.close();
		}
	
	paragraph++;
	}
}
