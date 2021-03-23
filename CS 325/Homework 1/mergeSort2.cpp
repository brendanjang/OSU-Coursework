/******************************************************************************
** Author:		Brendan Jang
** Date:		7/1/2019
** Description:	Modified implementation file for merge sort. Asks user for
**				number in range 10000-1000000 and sizes the array to that value.
**				Then sorts the values and outputs time cost to sort said values.
******************************************************************************/

#include <iostream>
#include <string>
#include <ctime>

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

	// copy values from temp dynamic array back to input lis
	for (x = start, y = 0; y < index; x++, y++) {
		list[x] = tempList[y];
	}
	
	// deallocate
	delete[] tempList;
}

// merge sort function
void mergeSort(int list[], int start, int end) {
	if (start + 1 == end) {
		return;
	}

	int mid = (start + end) / 2;
	// recursive call for the first subarray
	mergeSort(list, start, mid);
	// recursive call for the second subarray
	mergeSort(list, mid, end);
	// call helper function to merge in proper order.
	merge(list, start, mid, end);
}

int main() {
	for (int i = 0; i < 10; i++) {
		srand(time(0));
		int size;
		int* list;
		cout << "Enter a number between 10000 and 1000000: " << endl;
		cin >> size;
		// allocate memory for dynamic array
		list = new int[size];
		// get elements for dynamic array
		for (int x = 0; x < size; x++) {
			int temp = rand() % 10001;
			list[x] = temp;
		}
		// sort values and output time cost
		clock_t start;
		start = clock();
		mergeSort(list, 0, size);
		start = clock() - start;
		cout << endl << "It took " << double(start) / CLOCKS_PER_SEC << " seconds to sort" << endl << endl;
	
		// deallocate
		delete[] list;
	}
	return 0;
}