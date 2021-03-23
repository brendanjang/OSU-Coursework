/***************************************************************************
Author:			Brendan Jang
Date:			11/5/2018
Description:	Implementation file for class Person. Constructor sets class
				parameters and get methods return the name and age of Person
				objects.
****************************************************************************/
#include <string>
#include "Person.hpp"

/**************************************************************************
Description: Constructor for class Person with parameters. Parameters are
in order: name and age.
**************************************************************************/
Person::Person(std::string name_1, double age_1)
{
	name = name_1;
	age = age_1;
}

// Methods for name and age private class members
std::string Person::getName()
{
	return name;
}

double Person::getAge()
{
	return age;
}
