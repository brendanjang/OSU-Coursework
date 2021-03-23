/*****************************************************************************
**	Program Name:	Lab 4 - University.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for University Class. Contains 3 member 
					variables: name, buildings, and people. Contains member 
					functions that prints prints the information on all the 
					buildings in its information system (name, address, and 
					building's size) and  that prints the information of all
					the people (name, age, GPA or Rating)
*****************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>

#include "Building.hpp"
#include "Person.hpp"
using namespace std;

class University {
public:
    // Constructor
    University();
    // Copy constructor
    University(const University& orig);
    // Destructor
    virtual ~University();
    
    // Add building to the uni
    void addBuilding(Building building);
    // Add person to the uni
    void addPerson(Person * person);
    
    // Print all buildings 
    void print_all_buildings();
    // Print all people
    void print_all_people();
    
    // Getter
    vector<Building> getBuildings();
    vector<Person *> getPeople();
    string getName() const;
    
private:
    // Name of the university is always Oregon State University
    const string name = "Oregon State University";
    vector<Building> buildings;
    vector<Person *> people;
};

#endif /* UNIVERSITY_HPP */
