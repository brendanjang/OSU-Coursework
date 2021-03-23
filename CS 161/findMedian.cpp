/*************************************************************************
Author:			Brendan Jang
Date:			11/05/2018
Description:	Function called findMedian that takes two parameters - an
				array of in and the size of the array. Function returns
				median of the array.
*************************************************************************/
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
/***********************************************************************
Description: Method for finding the median. It takes array and size of
array as argument.
***********************************************************************/
double findMedian(int array[], int size)
{
	// Declare variables
	double median;

	// Sort the array
	std::sort(array, array + size);

	// For even number of values, average middle two
	if (size % 2 == 0)
	{
		median = (array[size / 2] + array[(size / 2) - 1]) / 2.0;
	}
	
	// For odd number of values
	else
	{
		median = (array[size / 2]);
	}
	return median;
}
