/****************************************************************************
**	Program Name:	Lab 4 - Instructor.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Instructor class. Contains the following
					member variables: rating. The range for GPA must be
					between 0.0 and 5.0. For "do_work()" in Person class, if
					the Person is an Instructor, then the function should 
					output expected message.
*****************************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

class Instructor : public Person {
public:
    // Constructor
    Instructor();
    // Copy constructor
    Instructor(const Instructor& orig);
    // Destructor
    virtual ~Instructor();
    
    // Getter
    double getRating();
    // Setter
    bool setRating(double rating);
    // Overriding methods
    int do_work();
    void print_out();
private:
    double rating;
};

#endif /* INSTRUCTOR_HPP */
