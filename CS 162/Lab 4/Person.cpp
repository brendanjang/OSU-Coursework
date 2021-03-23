/****************************************************************************
**	Program Name:	Lab 4 - Person.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Person class. Person class is 
					polymorphic, a Person can hold an Instructor/Student 
					object. The class contains following member variables:
					name and age. The Person class contains a function called
					"do_work()" that generates a random number that represents
					how many hours they will do work for, and then output
					message depending on if the Person is a Student or an
					Instructor.
****************************************************************************/

#include "Person.hpp"
#include <iostream>

using namespace std;

/*
* Constructor 
*/
Person::Person() {
    
    // Age is assigned randomly or by user
    age = rand() % 30;
    // Age should be realistic 
    // Student should be 18 years old
    if (age < 18) {
        age += 18;
    }
}

/*
* Copy constructor 
* @param o
*/
Person::Person(const Person& o) {
    name = o.name;
    age = o.age;
}

/*
* Destructor 
*/
Person::~Person() {
}

/*
* Getter
* @return age
*/
int Person::getAge() {
    return age;
}

/*
* Getter
* @return name
*/
string Person::getName() {
    return name;
}

/*
* Setter
* @param age age of the person
*/
void Person::setAge(int age) {
    this->age = age;
}

/*
* Setter 
* @param name name of the person
*/
void Person::setName(string name) {
    this->name = name;
}

/*
* Get random hour
* @return a random working hour
*/
int Person::do_work() {
    return (rand() % 60) + 1;
}

/*
* Print out name and age of the person
*/
void Person::print_out() {
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
}
