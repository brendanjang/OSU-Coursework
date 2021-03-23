/***************************************************************************
**	Program Name:	Project 2 - Animal.hpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Header file for Animal class. Has 5 member variables:
					Age, cost Number of Babies, Base Food Cost, Payoff.
***************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

const int TIGER_BABY_NUM = 1;
const int TURTLE_BABY_NUM = 5;
const int PENGUIN_BABY_NUM = 10;
const int CAMEL_BABY_NUM = 2;

class Animal {
public:
    // Constructor
    Animal(double base_food_cost, int age = 0);
    // Copy constructor
    Animal(const Animal& orig);
    // Destructor
    virtual ~Animal();
    
    // Getter
    int getAge();
    double getCost();
    int getBabyNum();
    double getFeedingCost();
    double getPayOff();
    
    bool isAdult();
    // Increase object's age
    void getOlder();
    
protected:
    int age;
    double cost;
    int baby_num;
    double base_food_cost;
    double pay_off;    
};

#endif /* ANIMAL_HPP */
