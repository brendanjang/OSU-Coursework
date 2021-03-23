/******************************************************************************
** Author:		Brendan Jang
** Date:		7/1/2019
** Description:	Implementation file for insertion sort.
**				https://www.geeksforgeeks.org/insertion-sort/ used as reference.
******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// insertion sort function
void insertionSort(int list[], int size) {
	for (int x = 1; x < size; x++) {
		int current = x;
		int index = x - 1;

		// compare current value with our analyzed section
		while (index >= 0 && list[current] < list[index]) {
			int temp = list[index];
			list[index] = list[current];
			list[current] = temp;
	
			// update index
			current = index;
			index--;
		}
	}
}

int main() {
	ifstream readFile("data.txt");
	ofstream outputFile("insert.txt");

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

		// insertion sort
		insertionSort(list, size);

		// output results into insert.txt
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