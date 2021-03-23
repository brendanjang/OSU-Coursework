/******************************************************************************
**	Program Name:	Project 2 - Zoo.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Zoo class. Zoo class has a dynamnic array for
each type of animal. Each dynamic array should have a capacity of 10 animals to start with.
If more animals are added, resize the dynamic array by doubling the starting capacity
to hold more animals.
******************************************************************************/

#include "Zoo.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* Constructor 
* @param amount amount of money which is in the bank
* @param base_food_cost base food cost
*/
Zoo::Zoo(double amount, double base_food_cost) {
    // Set up passed data
    this->amount = amount;
    this->base_food_cost = base_food_cost;

    // Initialize the capacity
    tiger_capacity = INIT_CAPACITY;
    turtle_capacity = INIT_CAPACITY;
    penguin_capacity = INIT_CAPACITY;
    camel_capacity = INIT_CAPACITY;

    // Initialize the number of each race
    tiger_num = 0;
    turtle_num = 0;
    penguin_num = 0;
    camel_num = 0;

    // Initialize array of pointer to each race
    tigers = new Tiger * [tiger_capacity];
    turtles = new Turtle * [turtle_capacity];
    penguins = new Penguin * [penguin_capacity];
    camels = new Camel * [camel_capacity];
}

/*
* Copy constructor
* @param o a zoo object
*/
Zoo::Zoo(const Zoo& o) {
    // Copy primary type data
    amount = o.amount;
    this->base_food_cost = o.base_food_cost;

    tiger_capacity = o.tiger_capacity;
    turtle_capacity = o.turtle_capacity;
    penguin_capacity = o.penguin_capacity;
    camel_capacity = o.camel_capacity;


    tiger_num = o.tiger_num;
    turtle_num = o.turtle_num;
    penguin_num = o.penguin_num;
    camel_num = o.camel_num;

    // Allocate memory 
    tigers = new Tiger * [tiger_capacity];
    turtles = new Turtle * [turtle_capacity];
    penguins = new Penguin * [penguin_capacity];
    camels = new Camel * [camel_capacity];

    // Copy contents of each object in the passed zoo
    for (int i = 0; i < tiger_num; i++) {
        tigers[i] = new Tiger(*(o.tigers[i]));
    }
    for (int i = 0; i < turtle_num; i++) {
        turtles[i] = new Turtle(*(o.turtles[i]));
    }
    for (int i = 0; i < penguin_num; i++) {
        penguins[i] = new Penguin(*(o.penguins[i]));
    }

    for (int i = 0; i < camel_num; i++) {
        camels[i] = new Camel(*(o.camels[i]));
    }
}

/*
* Destructor 
*/
Zoo::~Zoo() {
    // Free each pointer
    for (int i = 0; i < tiger_num; i++) {
        delete tigers[i];
    }
    for (int i = 0; i < turtle_num; i++) {
        delete turtles[i];
    }
    for (int i = 0; i < penguin_num; i++) {
        delete penguins[i];
    }
    for (int i = 0; i < camel_num; i++) {
        delete camels[i];
    }
    // Free arrays of pointer 
    delete [] tigers;
    delete [] turtles;
    delete [] penguins;
    delete [] camels;
}

/*
* Main function of the class
*/
void Zoo::run() {
    // Begin the game
    begin();

    // Variables
    int day = 1;
    int selection = 0;

    string questions [] = {
        "What do you want to do?",
        "0. Continue",
        "1. Stop"
    };

    string feeding_questions [] = {
        "What do you want to feed all animals?",
        "1. Cheap",
        "2. Generic",
        "3. Premium"
    };

    Menu menu;

    // Loop until receiving the right selection
    while (selection == 0) {
        cout << "--------------------------------------------------\n";
        cout << "Day " << day << ":\n";

        // Get feeding type
        feeding_type = menu.getValue(feeding_questions, 4, 1, 3);
        // Process a day
        aDay();
        day++;

        // Check the bank account
        if (amount <= 0) {
            cout << "The zoo runs out of money.\n";
            break;
        }

        cout << "You have $" << amount << " in your account.\n";

        // Let user stop the game if they want
        selection = menu.getValue(questions, 3, 0, 1);
    }

    cout << "--------------------------------------------------\n";
    cout << "Game over.\n";
}

void Zoo::aDay() {
    // Feeding and growing 
    growingAndFeeding();
    // Get bonus payment from random event
    double bonus = randomEvent();
    // "Nothing happens" task
    nothingHappen(bonus);
}

/*
* "Nothing happens" task
* @param bonus bonus payment
*/
void Zoo::nothingHappen(double bonus) {
    // Add bonus
    amount += bonus;

    // Collect all pay off
    collectPayoff();
    Menu menu;
    string questions [] = {
        "Do you want to buy an adult animal?",
        "1. Yes",
        "2. No"
    };

    // Get user's choice
    int selection = menu.getValue(questions, 3, 1, 2);
    if (selection == 2) {
        return;
    }

    string animal_question [] = {
        "Which type of animal you would like?",
        "0. Tiger",
        "1. Turtle",
        "2. Penguin",
        "3. Camel"
    };

    string another_question [] = {
        "There isn't enough money in the bank. What do you want to do?",
        "0. Choose another animal.",
        "1. Skip buying today."
    };

    // Use this temp array to get cost of each race
    Animal ** arr = new Animal * [4];
    arr[TIGER] = new Tiger(0);
    arr[TURTLE] = new Turtle(0);
    arr[PENGUIN] = new Penguin(0);
    arr[CAMEL] = new Camel(0);

    do {
        selection = menu.getValue(animal_question, 5, 0, 3);
        if (amount < arr[selection]->getCost()) {
            selection = menu.getValue(another_question, 3, 0, 1);
        } 
		else {
            addAnimal(selection, 3);
            selection = 0;
        }
    } while (selection != 0);

    // Free the temp array
    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }
    delete [] arr;
}

/*
* Collect payoff
*/
void Zoo::collectPayoff() {
    double payoff;

    // Collect from tiger
    payoff = collectPayoff((Animal **) tigers, tiger_num);
    cout << "Collect $" << payoff << " from tigers.\n";
    amount += payoff;

    // Collect from turtle
    payoff = collectPayoff((Animal **) turtles, turtle_num);
    cout << "Collect $" << payoff << " from turtles.\n";
    amount += payoff;

    // Collect from penguin
    payoff = collectPayoff((Animal **) penguins, penguin_num);
    cout << "Collect $" << payoff << " from penguins.\n";
    amount += payoff;

    // Collect from camel
    payoff = collectPayoff((Animal **) camels, camel_num);
    cout << "Collect $" << payoff << " from camels.\n";
    amount += payoff;
}

/*
* collect payoff from an animal
* @param animals array pointer to objects of the animal 
* @param num number of object
* @return payoff 
*/
double Zoo::collectPayoff(Animal** animals, int num) {
    double payoff = 0;
    // Iterate over the array
    for (int i = 0; i < num; i++) {
        // Sum up all values
        payoff += animals[i]->getPayOff();
    }
    return payoff;
}

/*
* Random event
* @return bonus payment
*/
double Zoo::randomEvent() {
    double bonus = 0;
    switch (feeding_type) {
            // Cheap case 
        case FEEDING_CHEAP:
        {
            switch (rand() % 4) {
                    // Double chance to get sickness
                case 0:
                case 3:
                    sickness();
                    break;
                case 1:
                    bonus = boom();
                    break;
                case 2:
                    babies();
                    break;
            }
            break;
        }
            // Normal case 
        case FEEDING_GENERIC:
        {
            switch (rand() % 3) {
                case 0:
                    sickness();
                    break;
                case 1:
                    bonus = boom();
                    break;
                case 2:
                    babies();
                    break;
            }
            break;
        }
            // Premium case 
        case FEEDING_PREMIUM:
        {
            switch (rand() % 5) {
                    // Half chance to get sickness
                case 0:
                    sickness();
                    break;
                case 1:
                case 3:
                    bonus = boom();
                    break;
                case 2:
                case 4:
                    babies();
                    break;
            }
            break;
        }
    }
    return bonus;
}

/*
* Make babies from current animals
*/
void Zoo::babies() {

    string message = "";

    message += "A baby animal is born.\n";

    // Sum up all animals
    int total_animal = tiger_num + turtle_num + penguin_num + camel_num;
    if (total_animal <= 0) {
        message += "There isn't any animal in the zoo.\n";
        writeMessage(message);
        readFile();
        return;
    }
    // Allocate memory to pointer to all adults object
    Animal ** adults = 0;
    adults = new Animal* [total_animal];
    if (adults == 0) {
        message += "Memory runs low.\n";
        writeMessage(message);
        readFile();
        return;
    }

    // Get all adults and put into the right array
    int size = 0;
    collectAdultAnimals(adults, size, (Animal **) tigers, tiger_num);
    collectAdultAnimals(adults, size, (Animal **) turtles, turtle_num);
    collectAdultAnimals(adults, size, (Animal **) penguins, penguin_num);
    collectAdultAnimals(adults, size, (Animal **) camels, camel_num);

    // There is no adult
    if (size <= 0) {
        delete [] adults;
        message += "There isn't any adult animal in the zoo.\n";
        writeMessage(message);
        readFile();
        return;
    }

    // Find the chosen animal
    int chosen_one = rand() % size;
    string animal_type;
    Animal * the_one = adults[chosen_one];

    // Each animal has a different number of babies 
    int baby_num = the_one->getBabyNum();

    // Add babies to the right array 
    for (int i = 0; i < baby_num; i++) {
        switch (baby_num) {
            case TIGER_BABY_NUM:
                animal_type = "tiger";
                addAnimal(TIGER, 0);
                break;
            case TURTLE_BABY_NUM:
                animal_type = "turtles";
                addAnimal(TURTLE, 0);
                break;
            case PENGUIN_BABY_NUM:
                animal_type = "penguins";
                addAnimal(PENGUIN, 0);
                break;
            case CAMEL_BABY_NUM:
                animal_type = "camels";
                addAnimal(CAMEL, 0);
                break;
        }
    }

    delete adults;

    // Make message and  show it 
    message += std::to_string(baby_num) +
            " " + animal_type + " have/has been added to the zoo.\n";
    writeMessage(message);
    readFile();
}

/*
* Put adult from the animal group to the output array
* @param collection current adult array
* @param size current size of adult array
* @param animals array of animal
* @param num number of animal in the array
*/
void Zoo::collectAdultAnimals(Animal** collection, int& size,
        Animal** animals, int num) {
    for (int i = 0; i < num; i++) {
        if (animals[i]->isAdult()) {
            collection[size] = animals[i];
            size++;
        }
    }
}

/*
* Read file and print its content to screen
*/
void Zoo::readFile() {
    ifstream in;
    in.open(message_file, ios::in);
    if (in.is_open() == false) {
        cout << "Cannot open " << message_file << " for reading.\n";
        return;
    }
    // Read each line
    // Print it out
    string str;
    while (getline(in, str)) {
        cout << str << "\n";
    }
    in.close();
}

/**
* Open a file and write a string into it
* @param message the string to be written 
*/
void Zoo::writeMessage(string message) {
    ofstream out;
    out.open(message_file, ios::out);
    if (out.is_open() == false) {
        cout << "Cannot open " << message_file << " for writing.\n";
        return;
    }

    out << message;

    // Close file
    out.close();
}

/*
* Boom case
* @return bonus
*/
double Zoo::boom() {
    string message = "";
    message += "A boom in zoo attendance occurs.\n";

    // Get a random bonus
    int random_bonus = (rand() % 251) + 250;
    double extra_payoff = random_bonus * tiger_num;

    message += "We got extra $" + std::to_string(extra_payoff)
            + " because we have " + std::to_string(tiger_num) + " tiger(s).\n";
    writeMessage(message);
    readFile();
    return extra_payoff;
}

/*
* Sickness case 
*/
void Zoo::sickness() {

    string message = "";

    int total_animal = tiger_num + turtle_num + penguin_num + camel_num;

    message += "A sickness occurs in the zoo.\n";
    
    // The number of animals should be greater than 0
    if (total_animal <= 0) {
        message += "There aren't any animals in the zoo.\n";
        writeMessage(message);
        readFile();
        return;
    }
    int died_one;
    int *animal_num;
    string animal_type;
    Animal ** animals;
    
    // Find the index of the one that should be dead
    died_one = rand() % total_animal;
    animal_type = "tiger";
    animals = (Animal **) tigers;
    animal_num = &tiger_num;

    // Filter its type and array 
    if (died_one >= tiger_num) {

        died_one -= tiger_num;
        animal_type = "turtle";
        animals = (Animal **) turtles;
        animal_num = &turtle_num;
        
        if (died_one >= turtle_num) {
            died_one -= turtle_num;
            animals = (Animal **) penguins;
            animal_type = "penguin";
            animal_num = &penguin_num;

            if (died_one >= penguin_num) {
                died_one -= penguin_num;
                animals = (Animal **) camels;
                animal_type = "camel";
                animal_num = &camel_num;
            }
        }
    }

    // Delete the chosen one
    delete animals[died_one];

    message += "A " + animal_type + " died.\n";
    writeMessage(message);
    readFile();

    // Shift array of the chosen one left 
    for (int i = died_one; i < (*animal_num) - 1; i++) {
        animals[i] = animals[i + 1];
    }
    
    // Update the number of animal in the array of its race 
    (*animal_num) = (*animal_num) - 1;
}

/*
* Feed all animals and make them older 
*/
void Zoo::growingAndFeeding() {
    // Work on each type 
    growingAndFeeding((Animal**) tigers, tiger_num);
    growingAndFeeding((Animal**) turtles, turtle_num);
    growingAndFeeding((Animal**) penguins, penguin_num);
    growingAndFeeding((Animal**) camels, camel_num);
}

/*
* Feed all animals of a type and make them be older 
* @param animal array of pointers to a race
* @param size number of animal in the array
*/
void Zoo::growingAndFeeding(Animal** animal, int &size) {
    // Bad case 
    if (size <= 0) {
        return;
    }
    // Get feeding cost
    double feeding_cost = animal[0]->getFeedingCost();
    
    // Each feeding type has a different feeding cost 
    switch (feeding_type) {
        case FEEDING_CHEAP:
            feeding_cost = feeding_cost / 2.0;
            break;
        case FEEDING_PREMIUM:
            feeding_cost = feeding_cost * 2.0;
            break;
    }

    // Feed all animals
    int i = 0;
    while (i < size) {
        animal[i]->getOlder();
        // Run out of money
        // Stop feeding 
        if (amount < feeding_cost) {
            break;
        }
        amount -= feeding_cost;
        i++;
    }

    // Hungry animals will die
    if (i < size) {
        for (int j = i; j < size; j++) {
            delete animal[j];
        }
        // Update the number of animals in the array
        size = i;
    }
}

/*
* Begin the game
* Add 1 or 2 animals to each array
*/
void Zoo::begin() {
    string question;
    int size;
    Menu menu;
    
    // Tiger
    question = "How many tigers do you want to buy?: ";
    size = menu.getValue(&question, 1, 1, 2);
    for (int i = 0; i < size; i++) {
        addAnimal(TIGER, 1);
    }

    // Turtle
    question = "How many turtles do you want to buy?: ";
    size = menu.getValue(&question, 1, 1, 2);
    for (int i = 0; i < size; i++) {
        addAnimal(TURTLE, 1);
    }

    // Penguin
    question = "How many penguins do you want to buy?: ";
    size = menu.getValue(&question, 1, 1, 2);
    for (int i = 0; i < size; i++) {
        addAnimal(PENGUIN, 1);
    }

    // Camel
    question = "How many camels do you want to buy?: ";
    size = menu.getValue(&question, 1, 1, 2);
    for (int i = 0; i < size; i++) {
        addAnimal(CAMEL, 1);
    }
}

/*
* Add an animal to the right array
* @param animal_type type of animal
* @param age its age
*/
void Zoo::addAnimal(int animal_type, int age) {
    // Checking
    if (animal_type < TIGER || animal_type > CAMEL) {
        cout << "Invalid type of animal.\n";
        return;
    }

    Animal ** animals;
    Animal * animal = 0;
    int * num;
    int * capacity;

    // Create the right animal for the right array
    switch (animal_type) {
        case TIGER:
            animals = (Animal**) tigers;
            num = &tiger_num;
            capacity = &tiger_capacity;
            animal = new Tiger(base_food_cost, age);
            break;
        case TURTLE:
            animals = (Animal**) turtles;
            num = &turtle_num;
            capacity = &turtle_capacity;
            animal = new Turtle(base_food_cost, age);
            break;
        case PENGUIN:
            animals = (Animal**) penguins;
            num = &penguin_num;
            capacity = &penguin_capacity;
            animal = new Penguin(base_food_cost, age);
            break;
        case CAMEL:
            animals = (Animal**) camels;
            num = &camel_num;
            capacity = &camel_capacity;
            animal = new Camel(base_food_cost, age);
            break;
    }

    // Cannot allocate memory
    if (animal == 0) {
        cout << "Cannot allocate new memory.\n";
        return;
    }
    
    // There isn't enoguh money
    if (animal->getCost() > amount) {
        cout << "The animal cost $" << animal->getCost()
                << " and we don't have enough money to buy it. \n";
        // Free the animal
        delete animal;
        return;
    }
    
    // Resize the array if it's necessary 
    bool resizable = true;
    if ((*num) >= (*capacity)) {
        resizable = resize(animal_type);
    }
    
   // Get address of the right array for it may change after resizing 
    switch (animal_type) {
        case TIGER:
            animals = (Animal**) tigers;
            break;
        case TURTLE:
            animals = (Animal**) turtles;
            break;
        case PENGUIN:
            animals = (Animal**) penguins;
            break;
        case CAMEL:
            animals = (Animal**) camels;
            break;
    }

     // Add the animal to the right array if we can resize the array
    if (resizable) {
        animals[(*num)] = animal;
        // Update its number of animal
        (*num) = (*num) + 1;
    }
}

/*
* Resize the array
* @param animal_type race type
* @return 
*/
bool Zoo::resize(int animal_type) {
    int new_capacity = 0;
    Animal** new_arr = 0;
    Animal** animals;
    
    // Allocate the memory
    // Get the right array to be copied
    switch (animal_type) {
        case TIGER:
            new_capacity = tiger_capacity * 2;
            new_arr = (Animal**) (new Tiger * [new_capacity]);
            animals = (Animal **) tigers;
            break;
        case TURTLE:
            new_capacity = turtle_capacity * 2;
            new_arr = (Animal**) (new Turtle * [new_capacity]);
            animals = (Animal **) turtles;
            break;
        case PENGUIN:
            new_capacity = penguin_capacity * 2;
            new_arr = (Animal**) (new Penguin * [new_capacity]);
            animals = (Animal **) penguins;
            break;
        case CAMEL:
            new_capacity = camel_capacity * 2;
            new_arr = (Animal**) (new Camel * [new_capacity]);
            animals = (Animal **) camels;
            break;

    }

    // Bad case 
    // Can't allocate new memory 
    if (new_arr == 0) {
        cout << "Memory run low. Cannot resize the animal array.\n";
        return false;
    }

    // Copy the old array to the new array
    for (int i = 0; i < new_capacity / 2; i++) {
        new_arr[i] = animals[i];
    }
    
    // Free the old array
    delete [] animals;
    
    // Assign the new array to the right pointer to array of race 
    switch (animal_type) {
        case TIGER:
            tigers = (Tiger **) new_arr;
            tiger_capacity = new_capacity;
            break;
        case TURTLE:
            turtles = (Turtle **) new_arr;
            turtle_capacity = new_capacity;
            break;
        case PENGUIN:
            penguins = (Penguin **) new_arr;
            penguin_capacity = new_capacity;
            break;
        case CAMEL:
            camels = (Camel **) new_arr;
            camel_capacity = new_capacity;
            break;

    }
    return true;
}