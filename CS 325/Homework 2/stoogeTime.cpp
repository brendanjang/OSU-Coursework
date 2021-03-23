/******************************************************************************
** Author:		Brendan Jang
** Date:		7/8/2019
** Description:	Modified implementation file for stooge sort. Asks user for
**				number in range 10000-1000000 and sizes the array to that value.
**				Then sorts the values and outputs time cost to sort said values.
******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

// modified stooge sort method
void stoogeSort(int arr[], int first, int last) {
	int size = last - first;

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
	for (int i = 0; i < 10; i++) {
		srand(time(0));
		int size;
		int* list;
		
		cout << "Enter a number between 500 and 5000: " << endl;
		cin >> size;

		// allocate memory for our dynamic array
		list = new int[size];

		// get elements for  dynamic array
		for (int x = 0; x < size; x++) {
			int temp = rand() % 10001;
			list[x] = temp;
		}

		// Sort values and output the time
		clock_t start;
		start = clock();
		stoogeSort(list, 0, size-1);
		start = clock() - start;
		cout << endl << "It took " << double(start) / CLOCKS_PER_SEC << " seconds to sort " << size << " elements." << endl << endl;

		// deallocate
		delete[] list;
	}
	return 0;
}
