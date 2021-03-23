/*******************************************************************************
Author:			Brendan Jang
Date:			11/5/2018
Description:	Class specification file for class Person.
*******************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

// Declare class
class Person
{
	private:
		// Declare private variables
		std::string name;
		double age;

	public:
		// Constructor that takes 2 values and initializes them to
		// the data members.
		Person(std::string name_1, double age_1);

		//Get methods for age and name parameters
		std::string getName();
		double getAge();
};

#endif
