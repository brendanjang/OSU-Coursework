/****************************************************************************
**	Program Name:	Lab 4 - Student.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Student class. Contains the 
					following member variables: GPA. The range for GPA must be
					between 0.0 and 4.0. For "do_work()" in Person class, if
					the Person is a Student, then the function should output
					expected message.
*****************************************************************************/

#include "Student.hpp"
#include <iostream>

using namespace std;

/*
* Constructor
*/
Student::Student() {
}

/*
* Copy constructor
* @param o reference to a Student object
*/
Student::Student(const Student& o) : Person(o) {
    GPA = o.GPA;    
}

/*
* Destructor
*/
Student::~Student() {
}

/*
* Getter
* @return  GPA
*/
double Student::getGPA() {
    return GPA;
}

/*
* Setter 
* @param GPA the GPA
* @return false if the input is illegal 
*  true if the input is legal 
*/
bool Student::setGPA(double GPA) {
    // Check the value
    if (GPA < 0. || GPA > 4.0) {
        // If it's illegal
        return false;
    }
    // If it's legal
    this->GPA = GPA;
    return true;
}

/*
* Show the right message
* @return number of working hour
*/
int Student::do_work() {
    // Call parent's method
    int x = this->Person::do_work();
    // Show result to screen
    cout << getName() << " did " << x << "  hours of homework.\n";
    return x;
}

/*
* Print the object out
*/
void Student::print_out() {
    // Call parent's method
    this->Person::print_out();
    cout << "GPA: " << GPA << "\n";
}
