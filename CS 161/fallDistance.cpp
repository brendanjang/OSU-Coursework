/************************************************************************
Author:			Brendan Jang
Date:			10/14/2018
Description:	Function to calculate fall distance
************************************************************************/

// Function header
double fallDistance(double time)
{
	double distance;
	distance = (1/2.0) * 9.8 * (time * time);

	return distance;
}
