/************************************************************************
Author:			Brendan Jang
Date:			10/10/2018
Description:	Prompts user to enter filename. If file name exists, the
				program reads the list of integers by line, adds all the
				integers, and writes sum to sum.txt.
************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	// Define objects
	ifstream inFile;
	ofstream outFile;

	// Declare variables
	string fileName;
	int count, nums, sum = 0;

	// Prompt user for filename and initialize variable
	cout << "Please enter your filename." << endl;
	cin >> fileName;

	// Open files
	inFile.open(fileName);
	outFile.open("sum.txt");
 
	if(inFile)
	{	
		// Loop for each number in file
		for(int count = 0; count < 7; count++)
		{
			inFile >> nums;
			sum += nums;
		}
		outFile << sum;
		cout << "result written to sum.txt" << endl;
		
		// Close files
		inFile.close();
		outFile.close();
	}
	else
	{
		cout << "could not access file" << endl;
	}
	
	return 0;
}
