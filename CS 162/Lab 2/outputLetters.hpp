/**************************************************************************
** Program Name:	Lab 2 - outputLetters.hpp
** Author:			Brendan Jang
** Date:			1/18/2019
** Description:		Header file for function output_letters. Takes an
					output file stream variable, and a pointer to an array
					of integers that contains frequencies of letters. The
					function first asks user for the filename the user
					would like to output to, then outputs the frequencies
					of letters to the output file in the format specified
					above.
**************************************************************************/

#ifndef OUTPUTLETTERS_HPP
#define OUTPUTLETTERS_HPP

#include <fstream>
using namespace std;

/*
Write contents of the array to the output stream
@param stm output stream
@param arr the array
*/
void output_letters(ofstream & stm, int * arr);

#endif /* OUTPUTLETTERS_HPP */
