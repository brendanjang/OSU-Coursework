/******************************************************************************
** Author:		Brendan Jang
** Date:		7/1/2019
** Description:	Modified implementation file for insertion sort. Asks user for
**				number in range 10000-1000000 and sizes the array to that value.
**				Then sorts the values and outputs time cost to sort said values.
******************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// modified insertion sort method
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
	for (int i = 0; i < 10; i++) {
		srand(time(0));
		int size;
		int* list;
		cout << "Enter a number between 10000 and 1000000: " << endl;
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
		insertionSort(list, size);
		start = clock() - start;
		cout << endl << "It took " << double(start) / CLOCKS_PER_SEC << " seconds to sort" << endl << endl;
	
		// deallocate
		delete[] list;
	}
	return 0;
}