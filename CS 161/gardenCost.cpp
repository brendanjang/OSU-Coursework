/****************************************************************************
** Author:		Brendan Jang
** Date:		September 25, 2018
** Description:	Ask the user for cost of soil, flower seeds, and fence then
				calculate and display the total cost.
****************************************************************************/

#include <iostream>
using std::cout;
using std::cin;

int main()
{
	// Define variables.
	double soilCost, seedCost, fenceCost, totalCost;

	// Get cost of soil.
	cout << "What does the soil cost?" << std::endl;
	cin >> soilCost;

	// Get cost of seed.
	cout << "What do the flower seeds cost?" << std::endl;
	cin >> seedCost;

	// Get cost of fence.
	cout << "What does the fence cost?" << std::endl;
	cin >> fenceCost;

	// Get total cost of garden.
	totalCost = soilCost + seedCost + fenceCost;

	// Display the total cost.
	cout << "The total cost is " << totalCost << std::endl;

	return 0;
}
