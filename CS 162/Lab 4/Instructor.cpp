/****************************************************************************
**	Program Name:	Lab 4 - Instructor.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Instructor class. Contains the 
					following member variables: rating. The range for GPA must
					be between 0.0 and 5.0. For "do_work()" in Person class,
					if the Person is an Instructor, then the function should
					output expected message.
*****************************************************************************/

#include "Instructor.hpp"
#include <iostream>

using namespace std;

/*
* Constructor 
*/
Instructor::Instructor() {
}

/*
* Copy constructor 
* @param o reference to an Instructor object
 */
Instructor::Instructor(const Instructor& o) : Person(o) {
    rating = o.rating;
}

/*
* Destructor 
*/
Instructor::~Instructor() {
}

/*
* Getter
* @return rating
*/
double Instructor::getRating() {
    return rating;
}

/*
* Setter 
* @param rating rating of the instructor 
* @return false if the input is illegal
*  true if the input is legal
*/
bool Instructor::setRating(double rating) {
    if(rating < 0.0 || rating > 5.0){
        return false;
    }
    this->rating = rating;
    return true;
}

/*
* Instructor at work
* @return amount of working time 
*/
int Instructor::do_work() {
    // Call parent's method
    int x = this->Person::do_work();
    // Print out
    cout << getName() << " graded papers for " << x << " hours.\n";
    return x;
}

/*
* Show content of this object on screen
*/
void Instructor::print_out() {
    // Call parent's method 
    this->Person::print_out();
    cout << "Rating: " << rating << "\n";
}
