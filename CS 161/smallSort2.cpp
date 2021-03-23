/*********************************************************************
* Author:			Brendan Jang
* Date:			11/13/2018
* Description:		Program that takes the addresses of three int
* 					variables as parameters and sorts the ints at
* 					those addresses into ascending order.
********************************************************************/
#include <iostream>

using std::cout;
using std::endl;

// Function prototype
void smallSort2(int *first, int *second, int *third);

/*int main()
{
	int first = 14;
	int second = -90;
	int third = 2;
	smallSort2(&first, &second, &third);
	cout << first << "," << second << "," << third << endl;
	
	return 0;
}*/

/*********************************************************************
Description: Function that takes addresses of three ints as variables
ands sorts ints at the addresses in ascending order.
*********************************************************************/

// Call smartSort2 and pass addresses as arguments
void smallSort2(int *first, int *second, int *third)
{
	// Declare variable
	int temp;

	// If first > second then swap
	if(*first > *second)
	{
		temp = *first;
		*first = *second;
		*second = temp;
	}

	// If first > third then swap
	if(*first > *third)
	{
		temp = *first;
		*first = *third;
		*third = temp;
	}

	// If second > third then swap
	if(*second > *third)
	{
		temp = *second;
		*second = *third;
		*third = temp;
	}
}
