/************************************************************************
Author:			Brendan Jang
Date:			10/16/2018
Description:	Void function that takes three integer parameters by
				reference and sorts their values into ascending order.
************************************************************************/


// Set up void function header
void smallSort(int &numOne, int &numTwo, int &numThree)
{
	// Set up variable
	int number;
	
	// Switch first two numbers if they are out of order
	if(numOne > numTwo)
	{
		number = numTwo;
		numTwo = numOne;
		numOne = number;
	}

	// Compare second number with third and switch if necessary
	if(numTwo > numThree)
	{
		number = numThree;
		numThree = numTwo;
		numTwo =  number;
	}

	// Compare first and second again and switch if necessary.
	if(numOne > numTwo)
	{
		number = numTwo;
		numTwo = numOne;
		numOne = number;
	}
}
