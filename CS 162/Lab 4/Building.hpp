/***************************************************************************
**	Program Name:	Lab 4 - Building.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Building class. Contains the member 
					variables: name, size, and address.
****************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

using namespace std;

class Building {
public:
    // Constructor 
    Building();
    // Copy constructor 
    Building(const Building& orig);
    // Destructor
    virtual ~Building();
    
    // Setter
    void setName(string name);
    void setSize(double size);
    void setAddress1(string address);
    void setAddress2(string address);
    
    // Getter
    string getName();
    int getSize();
    string getAddress1();
    string getAddress2();
    
    // Print the building out
    void print_out();
private:
    string name;
    int size;
    // There are 2 lines of address in the sample input file
    string address1;
    string address2;

};

#endif /* BUILDING_HPP */
