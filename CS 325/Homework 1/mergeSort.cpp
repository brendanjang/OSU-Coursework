/******************************************************************************
** Author:		Brendan Jang
** Date:		7/1/2019
** Description:	Implementation file for merge sort.
**				https://www.geeksforgeeks.org/merge-sort/ used as reference.
******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// helper function
void merge(int list[], int start, int mid, int end) {
	// temp list to hold values in sorted order
	int * tempList = new int[end];
	int index = 0;
	int x = start;
	int y = mid;

	// iterate through sub arrays
	// will compare the current index and pass the appropriate value to the temp list
	while (x < mid && y < end) {
		if (list[x] <= list[y]) {
			tempList[index] = list[x];

			// update index
			index++;
			x++;
		}
		else if (list[y] <= list[x]) {
			tempList[index] = list[y];
			index++;
			y++;
		}
	}
	
	// loops to make sure the subarrays were fully traversed
	// pass the remaining values
	while (x < mid) {
		tempList[index] = list[x];
		index++;
		x++;
	}

	while (y < end) {
		tempList[index] = list[y];
		index++;
		y++;
	}

	// copy values from temp dynamic array back to input list
	for (x = start, y = 0; y < index; x++, y++) {
		list[x] = tempList[y];
	}
	
	// deallocate
	delete[] tempList;
}

// merge sort function
void mergeSort(int list[], int start, int end) {
	if (start+1 == end) {
		return;
	}

	int mid = (start + end) / 2;
	// recursive call for first subarray
	mergeSort(list, start, mid);
	// recursive call for second subarray
	mergeSort(list, mid, end);
	// call helper function to merge in proper order.
	merge(list, start, mid, end);
}

int main() {
	ifstream readFile("data.txt");
	ofstream outputFile("merge.txt");

	while (!readFile.eof()) {
		int size;
		int* list;
		// get number of elements
		readFile >> size;
		// allocate memory for dynamic array
		list = new int[size];
		// get elements for dynamic array
		int temp;
		for (int x = 0; x < size; x++) {
			readFile >> temp;
			list[x] = temp;
		}
		
		// sort
		mergeSort(list, 0, size);

		// output the result to merge.txt file
		for (int x = 0; x < size; x++) {
			outputFile << list[x] << " ";
		}
		outputFile << endl;

		// deallocate
		delete[] list;
	}

	// closeour files 
	readFile.close();
	outputFile.close();

	return 0;
}