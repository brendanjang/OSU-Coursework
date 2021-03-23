/****************************************************************************
**	Program Name:	Lab 4 - Person.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Person class. Person class is polymorphic,
					a Person can hold an Instructor/Student object. The class
					contains following member variables: name and age. The
					Person class contains a function called "do_work()" that
					generates a random number that represents how many hours
					they will do work for, and then output message depending
					on if the Person is a Student or an Instructor.
*****************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using namespace std;        

class Person {
public:
    // Constructor 
    Person();
    // Copy constructor 
    Person(const Person& orig);
    // Destructor 
    virtual ~Person();
    
    // Getter
    string getName();
    int getAge();
    
    // Setter
    void setName(string name);
    void setAge(int age);
    
    // Take action, virtual declaration asks the program
    // to call child's method
    virtual int do_work();    
    virtual void print_out();
private:
    string name;
    int age;
};

#endif /* PERSON_HPP */
