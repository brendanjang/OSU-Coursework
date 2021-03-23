/**************************************************************************
Author:			Brendan Jang
Date:			10/24/2018
Description:	A header file for Box class. Holds private member variables
				for height, length, and width. Also holds public function
				declaration for constructing, setting, and getting box
				dimensions.
**************************************************************************/
#ifndef BOX_HPP
#define BOX_HPP

class Box
{
	// Private member variables
	private:
		double height, length, width;
											
	public:
		// Declare functions
		// Default constructor with no params
		Box();

		// Overloaded constructor with three double params
		Box(double length, double width, double height);

		// Accessor functions to return volume and 
		// surface area fucntions (get)
		double calcVolume();
		double calcSurfaceArea();

    	// Modifier fucntions to set member variables
		// with data type as params
		void setHeight(double newHeight);
		void setWidth(double newWidth);
		void setLength(double newLength);

		// Destructor to erase data
		~Box();
};
#endif
