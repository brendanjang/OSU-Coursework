/****************************************************************************
**	Program Name:	Lab 4 - main.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Main implementationfile for OSU Information System program.
*****************************************************************************/

#include <string>
#include <fstream>
#include <iostream> 
#include <typeinfo>

#include "University.hpp"
#include "Menu.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

using namespace std;

// Function prototypes

/*
* Trim tab and space of head and tail of string
* @param str a string
* @return  a string 
*/
string trim(string str);

/*
* Read building form file 
* @param uni reference to university object
* @param path path to the file to be read
*/
void readBuildings(University & uni, string path);

/*
* Write building to file 
* @param uni reference to university object
* @param path path to the file to be written
*/
void writeBuildings(University & uni, string path);

/*
* Read people form file 
* @param uni reference to university object
* @param path path to the file to be read
*/
void readPeople(University & uni, string path);

/*
* Write people to file 
* @param uni reference to university object
* @param path path to the file to be written
*/
void writePeople(University & uni, string path);

/*
* Save data to file 
* @param uni reference to university object
*/
void save(University & uni);

/*
* Load data from file 
* @param uni reference to university object
*/
void load(University & uni);

/*
* Choose a person from uni then make him to work 
* @param uni reference to university object
*/
void chooseAPerson(University & uni);

/*
* Add a person to uni 
* @param uni reference to university object
*/
void addAPerson(University & uni);

/*
* Manually instantiate 1 student, 1 instructor, 2 buildings
* @param uni reference to university object
*/
void manualInstantiation(University & uni);

/*
* Main function
* @param argc
* @param argv
* @return 
*/
int main(int argc, char** argv) {

    University uni;
        
    Menu menu;
    string options [] = {
        uni.getName(),
        "1. Print information about all buildings.",
        "2. Print information of everybody at the university.",
        "3. Choose a person to do work.",
        "4. Save information to file.",
        "5. Read information from file.",
        "6. Add people to the program during runtime.",
        "7. Exit the program."
    };
    
    // Manually instantiate 1 student, 1 instructor, 2 buildings
    manualInstantiation(uni);
    
    // Get selection
    int selection = menu.getValue(options, 8, 1, 7);
    while (selection != 7) {
        
        // Take action
        switch (selection) {
            case 1:
                uni.print_all_buildings();
                break;
            case 2:
                uni.print_all_people();
                break;
            case 3:
                chooseAPerson(uni);
                break;
            case 4:
                save(uni);
                break;
            case 5:
                load(uni);
                break;
            case 6:
                addAPerson(uni);
                break;
        }
        
        cout << "\n------------------------------------------------------\n\n";
        
        // Get new selection
        selection = menu.getValue(options, 8, 1, 7);
    }


    return 0;
}

/*
* Manually instantiate 1 student, 1 instructor, 2 buildings
* @param uni reference to university object
*/
void manualInstantiation(University & uni){
    
    // Add student
    Student * st = new Student();
    st->setAge(18);
    st->setName("Tom Smith");
    st->setGPA(3.6);
    uni.addPerson(st);
    
    // Add instructor
    Instructor * ist = new Instructor();
    ist->setAge(40);
    ist->setName("Bill Clay");
    ist->setRating(4.2);
    uni.addPerson(ist);
    
    // Add buildings
    Building bd;
    bd.setAddress1("BD1 address1");
    bd.setAddress2("BD1 address2");
    bd.setName("BD1");
    bd.setSize(452);    
    uni.addBuilding(bd);
    
    bd.setAddress1("BD2 address1");
    bd.setAddress2("BD2 address2");
    bd.setName("BD2");
    bd.setSize(784);    
    uni.addBuilding(bd);
}

/*
* Add a person to uni 
* @param uni reference to university object
*/
void addAPerson(University & uni) {
    string str, name;    
    int age;
    Menu menu;
    Person * person;
    string message [] = {
        "Which type of person do you want to add:",
        "1. Student",
        "2. Instructor"
    };
    
    // Get name 
    cout << "Enter name: ";
    getline(cin, name);
    
    // Get age
    str = "Enter age: ";
    age = menu.getValue(&str, 1, 18, 100);
        
    // Get type of person
    int selection = menu.getValue(message, 3, 1, 2);
	// Student case 
    if (selection == 1) { 
        Student * student = new Student();
        str = "Enter GPA: ";
        student->setGPA(menu.getValue(str, 0.0, 4.0));
        
        // Assign the new pointer to person pointer 
        person = student;
    } else {  // Instructor  case 
        Instructor * instructor = new Instructor();
        str = "Enter rating: ";
        instructor->setRating(menu.getValue(str, 0.0, 5.0));
        
        // Assign the new pointer to person pointer 
        person = instructor;
    }    
    
    // Person class could handle setName and setAge
    person->setName(name);
    person->setAge(age);
    
    // Push the person to uni
    uni.addPerson(person);
}

/*
* Choose a person from uni then make him to work 
* @param uni reference to university object
*/
void chooseAPerson(University & uni) {
    vector<Person *> people = uni.getPeople();
    Menu menu;
    
    // Bad case 
    if (people.empty()) {
        cout << "There isn't any person.\n";
        return;
    }
    
    // Show all people
    int index = 0;
    for (Person * elem : people) {
        cout << index << ". " << elem->getName() << "\n";
        index++;
    }
    
    // Try to get the index of chosen person
    string message = "What is index of chosen person?";
    index = menu.getValue(&message, 1, 0, people.size() - 1);

    // Get the person
    Person * person = people[index];
    // Take action
    person->do_work();
}

/*
* Load data from file 
* @param uni reference to university object
*/
void load(University & uni) {
    Menu menu;
    string options [] = {
        "Which information do you want to load from file?",
        "1. Building",
        "2. People"
    };
    string path;
    
    // Get type of object which will be read
    int selection = menu.getValue(options, 3, 1, 2);

    // Get path to the file 
    cout << "Enter the path: ";
    getline(cin, path);
    
    // Builing case 
    if (selection == 1) {
        readBuildings(uni, path);
    } else { // People case 
        readPeople(uni, path);
    }
}

/*
* Save data to file 
* @param uni reference to university object
*/
void save(University & uni) {
    Menu menu;
    string options [] = {
        "Which information do you want to save to file?",
        "1. Building",
        "2. People"
    };
    string path;
    
    // Get type of object to be save 
    int selection = menu.getValue(options, 3, 1, 2);

    // Get path to file 
    cout << "Enter the path: ";
    getline(cin, path);

    if (selection == 1) { // Building case
        writeBuildings(uni, path);
    } else { // People case 
        writePeople(uni, path);
    }
}

/*
* Write people to file 
* @param uni reference to university object
* @param path path to the file to be written
*/
void writePeople(University & uni, string path) {
    // Open stream
    fstream out;
    out.open(path, ios::out);
    
    // Bad case, can't open stream
    if (out.is_open() == false) {
        cout << "Can't open " << path << " for writing.\n";
        return;
    }

    
    string type;
    // Iterate over the vector
    for (Person * elem : uni.getPeople()) {
        // Write the type first
        type = typeid(*elem).name();
        out << type << "\n";
        
        // Write other data 
        out << elem->getName() << "\n";
        out << elem->getAge() << "\n";
        
        // Write specific data 
        if (type == "7Student") {
            Student * stu = (Student *)elem;
            out << stu->getGPA() << "\n\n";
        } else {
            Instructor * ins = (Instructor *)elem;
            out << ins->getRating() << "\n\n";
        }
    }
    
    // Close the stream
    out.close();
}

/*
* read people form file 
* @param uni reference to university object
* @param path path to the file to be read
*/
void readPeople(University & uni, string path) {
    
    // Open stream
    fstream in;
    in.open(path, ios::in);
    
    // Bad case, can't open stream
    if (in.is_open() == false) {
        cout << "Can't open " << path << " for reading.\n";
        return;
    }
    string line1, line2, line3, line4;

    Person * person;
    
    // Get line by line
    // Read type first 
    while (getline(in, line1)) {
        // Read name
        getline(in, line2);
        // Read age
        getline(in, line3);
        // Read GPA or Rating
        getline(in, line4);
        
        // Trim all lines 
        line1 = trim(line1);
        line2 = trim(line2);
        line3 = trim(line3);
        line4 = trim(line4);
        
        // Student case 
        if (line1 == "7Student") {
            Student * stu = new Student();            
            person = stu;
            stu->setGPA(stod(line4));
        } else { // Instructor case 
            Instructor * ins = new Instructor();
            person = ins;
            ins->setRating(stod(line4));
        }
        
        // Set up common attributes 
        person->setName(line2);
        person->setAge(stod(line3));
        uni.addPerson(person);
        
        // Read an empty line 
        getline(in, line4);
    }
    // Close stream
    in.close();
}

/*
* Write building to file 
* @param uni reference to university object
* @param path path to the file to be written
*/
void writeBuildings(University & uni, string path) {
    
    // Open stream
    fstream out;
    out.open(path, ios::out);
    
    // Bad case, can't open stream
    if (out.is_open() == false) {
        cout << "Cannot open " << path << " for writing.\n";
        return;
    }

    // Iterate over the vector
    for (Building elem : uni.getBuildings()) {
        
        // Write all data
        out << elem.getName() << "\n";
        out << elem.getAddress1() << "\n";
        out << elem.getAddress2() << "\n";
        out << elem.getSize() << " sqft\n\n";
    }

    // Close stream
    out.close();
}

/*
* Read building from file 
* @param uni reference to university object
* @param path path to the file to be read
*/
void readBuildings(University & uni, string path) {
    
    // Open stream
    fstream in;
    in.open(path, ios::in);
    
    // Bad case, can't open stream
    if (in.is_open() == false) {
        cout << "Can't open " << path << " for reading.\n";
        return;
    }
    string line1, line2;

    Building bld;

    // Read name
    while (getline(in, line1)) {
        line1 = trim(line1);
        bld.setName(line1);
        
        // Read 2 address lines 
        getline(in, line1);
        getline(in, line2);

       // line1 = trim(line1);
       // line2 = trim(line2);
        bld.setAddress1(line1);
        bld.setAddress2(line2);

        // Read size 
        getline(in, line1);
        
        // We have to remove comma from size
        line2 = "";
        for (auto elem : line1) {
            if (elem != ',') {
                line2 += elem;
            }
        }
        
        // Add size to the object 
        bld.setSize(stoi(line2));
        uni.addBuilding(bld);
        
        // Read an empty line 
        getline(in, line1);
    }
    in.close();
}

/*
* Trim tab and space of head and tail of string
* @param str a string
* @return  a string 
*/
string trim(string str) {
    // Clean head
    str.erase(0, str.find_first_not_of(' '));
    str.erase(0, str.find_first_not_of('\t'));
    
    // Clean tail
    str.erase(str.find_last_not_of(' ') + 1);
    str.erase(str.find_last_not_of('\t') + 1);
    return str;
}
