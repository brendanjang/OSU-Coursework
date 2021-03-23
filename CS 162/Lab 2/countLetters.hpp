/**************************************************************************
** Program Name:	Lab 2 - countLetters.hpp
** Author:			Brendan Jang
** Date:			1/18/2019
** Description:		Header file for function count_letters. Takes input file					stream variable, and a pointer to an array of ints.
					Function then reads the paragraph string from the input
					file stream, the counts the letter frequencies of that
					paragraph, and store the frequencies in the array.
					Disregards upper/lower case letters.
**************************************************************************/

#ifndef COUNTLETTERS_HPP
#define COUNTLETTERS_HPP

#include <fstream>
using namespace std;

/*
Read input stream and count letter and write frequency to a new file.
@param stm input stream
@param arr array of frequencies
*/
void count_letters(ifstream & stm, int * arr);

#endif /* COUNTLETTERS_HPP */
