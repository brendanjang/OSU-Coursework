/*****************************************************************************
** Program Name:	Searching and sorting - Lab 8 - main.cpp
** Author:			Brendan Jang
** Date:			3/2/2019
** Description:		Main implementation file for searching and sorting. The
					program should, for each file, read the file and put the 
					values into an array at the start of program. Implement 
					a search algorithm for your program that searches for a 
					target value in your four data files. When implemented, 
					the program should first ask for target value and validate 
					user input, then output whether target value is found for 
					EACH file. The program should, for each file, ask user 
					for the output file name, then use the algorithms to sort 
					the values, and finally output the sorted values to the 
					output files.
*****************************************************************************/

#include <cstdlib>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>

#include "Menu.hpp"
using namespace std;

/**
 * read a file push data to array
 * assume that the file contains integers only
 * @param path path to file
 * @param size reference to size of the returned array
 * @return an array
 */
int * readFile(string path, int & size);

/**
 * read list of files, fill dta to list of array
 * @param paths list of path to files
 * @param sizes list of size of these arrays
 * @param arr list of arrays
 * @param number_of_input number of files to be read
 * @return false if one of these fiel cannot be read
 */
bool readFiles(string paths[], int sizes[], int *arr[], int number_of_input);

// simple search

/**
 * search on an array
 * @param arr the array
 * @param size size of the array
 * @param target the target
 * @return true if the target is found in the array
 */
bool simpleSearch(int * arr, int size, int target);

/**
 * search on all array in the list
 * @param paths list of paths
 * @param sizes list of sizes
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void simpleSearch(string paths[], int sizes[], int *arr[], int number_of_input);

/**
 * https://en.wikipedia.org/wiki/Bubble_sort
 * @param arr the array
 * @param size size of the array
 */
void bubbleSort(int * arr, int size);

/**
 * writing to fiel and to screen
 * @param path path to written file
 * @param size size of the array
 * @param arr the array
 */
void writing(string path, int size, int * arr);

/**
 * soorting all array and writing them to files and to screen
 * @param paths list of path ot input files
 * @param sizes list of size of arrays
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void sorting(string paths[], int sizes[], int *arr[], int number_of_input);

/**
 * search on an array
 * @param arr the array
 * @param size size of the array
 * @param target the target
 * @return true if the target is found in the array
 */
bool binarySearch(int * arr, int size, int target);

/**
 * search on all array in the list
 * @param paths list of paths
 * @param sizes list of sizes
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void binarySearch(string paths[], int sizes[], int *arr[], int number_of_input);

/*
 *
 */
int main(int argc, char** argv) {

	// constant value
	const int NUMBER_OF_INPUT = 4;

	// list of input files
	string paths[] = {
		"num.txt",
		"early.txt",
		"mid.txt",
		"end.txt"
	};
	int sizes[NUMBER_OF_INPUT];
	int *arr[NUMBER_OF_INPUT];


	// read files 
	if (readFiles(paths, sizes, arr, NUMBER_OF_INPUT) == false) {
		return 0;
	}

	// simple search
	cout << "Simple sorting\n";
	simpleSearch(paths, sizes, arr, NUMBER_OF_INPUT);

	// sorting
	cout << "\n";
	cout << "Sorting\n";
	sorting(paths, sizes, arr, NUMBER_OF_INPUT);

	// binary search
	cout << "\n";
	cout << "Binary search\n";
	binarySearch(paths, sizes, arr, NUMBER_OF_INPUT);


	// free all allocated data
	for (int i = 0; i < NUMBER_OF_INPUT; i++) {
		delete[] arr[i];
	}
	return 0;
}

/**
 * search on all array in the list
 * @param paths list of paths
 * @param sizes list of sizes
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void binarySearch(string paths[], int sizes[], int *arr[], int number_of_input) {


	Menu menu;
	string message = "What is target value:";
	int target = menu.getValue(&message, 1, INT_MIN / 2, INT_MAX / 2);


	for (int i = 0; i < number_of_input; i++) {
		cout << paths[i] << " target value ";
		if (binarySearch(arr[i], sizes[i], target) == false) {
			cout << "not ";
		}
		cout << "found\n";
	}
}

/**
 * search on an array
 * @param arr the array
 * @param size size of the array
 * @param target the target
 * @return true if the target is found in the array
 */
bool binarySearch(int * arr, int size, int target) {
	int left = 0;
	int right = size - 1;
	int mid;
	// we try to close the gap to get the target value
	while (left <= right) {
		// half the array
		mid = (left + right) / 2;
		// compare to close the gap
		if (arr[mid] == target) {
			return true;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

/**
 * soorting all array and writing them to files and to screen
 * @param paths list of path ot input files
 * @param sizes list of size of arrays
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void sorting(string paths[], int sizes[], int *arr[], int number_of_input) {
	string output;

	// iterate over the list
	for (int i = 0; i < number_of_input; i++) {
		// show a message
		cout << "Input file: " << paths[i] << "\n";
		// get path to output file
		cout << "Output file: ";
		getline(cin, output);

		// sort the array
		bubbleSort(arr[i], sizes[i]);

		// write it 
		writing(output, sizes[i], arr[i]);
		cout << "\n";
	}
}

/**
 * writing to fiel and to screen
 * @param path path to written file
 * @param size size of the array
 * @param arr the array
 */
void writing(string path, int size, int * arr) {
	// open output stream
	fstream out;
	out.open(path, ios::out);

	// bad case. cannot open file for writing
	if (out.is_open() == false) {
		cout << "Cannot write to " << path << "\n";
		return;
	}

	// write to file and to screen
	for (int i = 0; i < size; i++) {
		out << arr[i] << " ";
		cout << arr[i] << " ";
	}
	cout << "\n";

	// close ouput stream
	out.close();
}

/**
 * https://en.wikipedia.org/wiki/Bubble_sort
 * @param arr the array
 * @param size size of the array
 */
void bubbleSort(int * arr, int size) {
	bool swapped = true;
	int tmp;
	while (swapped == true) {
		swapped = false;
		// try to pull the biggest number to the end of the current range
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				// swap items
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				// flag it 
				swapped = true;
			}
		}
		size--;
	}
}

/**
 * search on all array in the list
 * @param paths list of paths
 * @param sizes list of sizes
 * @param arr list of arrays
 * @param number_of_input number of array
 */
void simpleSearch(string paths[], int sizes[], int *arr[], int number_of_input) {
	// simple search
	// cannot use binary search 
	// because the array hasn't been sorted
	Menu menu;
	string message = "What is target value:";
	// get target
	int target = menu.getValue(&message, 1, INT_MIN / 2, INT_MAX / 2);


	//  iterate over list of array 
	for (int i = 0; i < number_of_input; i++) {
		cout << paths[i] << " target value ";
		/// search for the target
		if (simpleSearch(arr[i], sizes[i], target) == false) {
			cout << "not ";
		}
		cout << "found\n";
	}
}

/**
 * search on an array
 * @param arr the array
 * @param size size of the array
 * @param target the target
 * @return true if the target is found in the array
 */
bool simpleSearch(int * arr, int size, int target) {

	// iterate over the array
	for (int i = 0; i < size; i++) {
		// try to find it 
		if (arr[i] == target) {
			return true;
		}
	}
	return false;
}

/**
 * read list of files, fill dta to list of array
 * @param paths list of path to files
 * @param sizes list of size of these arrays
 * @param arr list of arrays
 * @param number_of_input number of files to be read
 * @return false if one of these fiel cannot be read
 */
bool readFiles(string paths[], int sizes[], int *arr[], int number_of_input) {
	// iterate over list of files
	for (int i = 0; i < number_of_input; i++) {
		// read a file
		arr[i] = readFile(paths[i], sizes[i]);
		// nothing is read
		if (arr[i] == 0) {
			// free allocated memory
			for (int j = 0; j < i; j++) {
				delete[] arr[j];
			}
			// show error message
			cout << "Cannot open " << paths[i] << " for reading\n";
			return false;
		}
	}
	return true;
}

/**
 * read a file push data to array
 * assume that the file contains integers only
 * @param path path to file
 * @param size reference to size of the returned array
 * @return an array
 */
int * readFile(string path, int & size) {
	// reset size of the array
	size = 0;
	// try to open file at path
	fstream in;
	in.open(path, ios::in);
	// file cannot be open for reading
	if (in.is_open() == false) {
		return 0;
	}

	// we don't know how many item are there in the file
	// we have to use a vector to store them
	vector<int> vt;
	int value;

	// read each integer    
	while (in >> value) {
		// push to vector
		vt.push_back(value);
	}

	// set the size of the aray
	size = vt.size();

	// declare a dynamic array 
	int * arr = new int[size];
	// copy data from vector to array 
	for (int i = 0; i < size; i++) {
		arr[i] = vt[i];
	}
	// clear content of the vector
	vt.clear();
	// close inputing stream
	in.close();
	return arr;
}
