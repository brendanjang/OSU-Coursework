/************************************************************************
Author:			Brendan Jang
Date:			10/16/2018
Description:	Function for hailstone sequence that starts with a
				positive integer.Returns how many steps it took to reach 0
*************************************************************************/
// Function header
int (hailstone(int num))
{
	// If num = 1, return 0 because no steps to reach 1.
	if(num == 1)
	{
		return 0;
	}
	// If even, divide num by 2 and store new value in num
	if(num % 2 == 0)
	{
		num = num / 2;
	}
	// If not even, then multiply by 3 and add 1.	
	else
	{
		num = num * 3 + 1;
	}
	return hailstone(num) + 1;
}
