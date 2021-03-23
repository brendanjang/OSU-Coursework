/***************************************************************************
**	Program Name:	Lab 4 - Building.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Building class. Contains the
					member variables: name, size, and address.
****************************************************************************/

#include "Building.hpp"
#include <iostream>

using namespace std;

/*
* Constructor 
*/
Building::Building() {
}

/*
* Copy constructor 
* @param o reference to a building object
*/
Building::Building(const Building& o) {
    address1 = o.address1;
    address2 = o.address2;
    name = o.name;
    size = o.size;
}

/*
* Destructor
*/
Building::~Building() {
}

/*
* Getter
* @return address 1
*/
string Building::getAddress1() {
    return address1;
}

/*
* Getter
* @return  address 2
*/
string Building::getAddress2() {
    return address2;
}

/*
* Getter 
* @return name
*/
string Building::getName() {
    return name;
}

/*
* Getter
* @return size
*/
int Building::getSize() {
    return size;
}

/*
* Setter
* @param address address 1
*/
void Building::setAddress1(string address) {
    this->address1 = address;
}

/*
* Setter 
* @param address address 2
*/
void Building::setAddress2(string address) {
    this->address2 = address;
}

/*
* Setter 
* @param name name of building
*/
void Building::setName(string name) {
    this->name = name;
}

/*
* Setter 
* @param size size of building
*/
void Building::setSize(double size) {
    this->size = size;
}

/*
* Print out all data of the object 
*/
void Building::print_out() {
    cout << "Name: " << name << "\n";
    cout << "Address: " << address1 <<  " " << address2 << "\n";
    cout << "Building's size: " << size << " sqft\n";
}
