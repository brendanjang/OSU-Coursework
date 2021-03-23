/******************************************************************************
** Author:		Brendan Jang
** Date:		7/8/2019
** Description:	Implementation file for stooge sort.
**				https://www.geeksforgeeks.org/stooge-sort/ used as reference.
**				Base case will be when there are 2 elements. If base condition
**				is met, perform swap if necessary. ELse we recursively call on
**				2/3 of the array size. Basically we are creating 3 sub problems
**				where we focus on the initial 2/3rd of the data, then the 
**				other 2/3rd.
******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


void stoogeSort(int arr[], int first, int last) {
	int size = last - first + 1;

	// base case
	if (size == 2) {
		// check to see if we need to swap
		if (arr[first] > arr[last]) {
			int temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
		}
	}
	else if (size > 2) {
		// get the index of 2/3rd of our array
		int val = size / 3;

		// recursively sort the first 2/3rd
		stoogeSort(arr, first, last - val);

		// revursively sort the second 2/3rd
		stoogeSort(arr, first + val, last);

		// recursive call on the first 2/3rd to verify
		// if there was a swap in the second call
		stoogeSort(arr, first, last - val);
	}
}

int main() {
	ifstream readFile("data.txt");
	ofstream outputFile("stooge.txt");

	while (!readFile.eof()) {
		int size;
		int* list;

		// get number of elements
		readFile >> size;

		// allocating memory for dynamic array
		list = new int[size];

		// get elements for dynamic array
		int temp;
		for (int x = 0; x < size; x++) {
			readFile >> temp;
			list[x] = temp;
		}

		// stooge sort
		stoogeSort(list, 0, size - 1);

		// output results into stooge.txt
		for (int x = 0; x < size; x++) {
			outputFile << list[x] << " ";
		}
		outputFile << endl;

		// deallocate
		delete[] list;
	}

	// close files
	readFile.close();
	outputFile.close();

	return 0;
}