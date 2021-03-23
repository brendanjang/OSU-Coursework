/****************************************************************************
**	Program Name:	Lab 4 - Student.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Student class. Contains the following
					member variables: GPA. The range for GPA must be
					between 0.0 and 4.0. For "do_work()" in Person class, if 
					the Person is a Student,  then the function should output
					expected message.
*****************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"


class Student : public Person {
public:
    // Constructor
    Student();
    // Copy constructor 
    Student(const Student& orig);
    // Destructor 
    virtual ~Student();
    
    // Getter
    double getGPA();
    // Setter
    bool setGPA(double GPA);
    
    // Do work
    int do_work();
    // Print object out
    void print_out();
    
private:
    double GPA;
};

#endif /* STUDENT_HPP */
