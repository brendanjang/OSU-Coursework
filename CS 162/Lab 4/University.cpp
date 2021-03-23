/****************************************************************************
**	Program Name:	Lab 4 - University.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for University Class. Contains 3 
					member variables: name, buildings, and people. Contains
					member functions that prints prints the information on 
					all the buildings in its information system (name, 
					address, and building's size )and that prints the 
					information of all the people (name, age, GPA or Rating)
****************************************************************************/

#include "University.hpp"
#include <iostream>
using namespace std;

/*
* Constructor 
*/
University::University() {
}

/*
* Copy constructor
* @param o reference to a University object
*/
University::University(const University& o) {
    // Buildings are vector of object so 
    // we can assign it 
    buildings = o.buildings;
    
    // We cannot copy the content of pointer 
    // so we have to do it manually 
    // Iterate over the vector 
    // Allocate new memory. Push it to the vector of this object
    for (auto elem : o.people) {
        Person * p = new Person(*elem);
        people.push_back(p);
    }
}

/*
* Destructor
*/
University::~University() {
    // Clear all objects 
    buildings.clear();
    
    // Clear allocated memory of each pointer 
    for (auto elem : people) {
        delete elem;
    }
    // Clear all pointers 
    people.clear();
}

/*
* Add a building to the uni
* @param building a building
*/
void University::addBuilding(Building building) {
    buildings.push_back(building);
}

/*
* Add a person to the uni
* @param person pointer to a person object
*/
void University::addPerson(Person* person) {
    people.push_back(person);
}

/*
* Print all buildings
*/
void University::print_all_buildings() {
    
    // Bad case 
    if (buildings.empty()) {
        cout << "There is no building.\n";
    } else {
        // Iterate over the vector
        for (Building elem : buildings) {
            // Print them out
            elem.print_out();
            cout << "\n";
        }
    }
}

/*
* Print all people out
*/
void University::print_all_people() {

    // Bad case 
    if (people.empty()) {
        cout << "There isn't any person.\n";
    } else {
        // Iterate over the vector 
        for (Person * elem : people) {
            // Print the data to screen
            elem->print_out();
            cout << "\n";
        }
    }
}

/*
* Getter
* @return vector of building
*/
vector<Building> University::getBuildings() {
    return buildings;
}

/*
* Getter
* @return vector of people pointer 
*/
vector<Person*> University::getPeople() {
    return people;
}

/*
* Getter
* @return name of the uni
*/
string University::getName() const {
    return name;
}
