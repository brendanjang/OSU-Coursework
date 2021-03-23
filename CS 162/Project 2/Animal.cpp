/**************************************************************************
 **	Program Name:	Project 2 - Animal.cpp
 **	Author:			Brendan Jang
 ** Date:			2/2/2019
 **	Description:	Implementation file for Animal class. Has 5 member 
 					variables: Age, Cost, Number of Babies, Base Food Cost,
					Payoff.
 **************************************************************************/

#include "Animal.hpp"

/*
* Constructor
* @param base_food_cost base food cost
* @param age age of the animal
*/
Animal::Animal(double base_food_cost, int age) {
    this->age = age;
    this->base_food_cost = base_food_cost;
}

Animal::Animal(const Animal& o) {
    this->age = o.age;
    this->baby_num = o.baby_num;
    this->base_food_cost = o.base_food_cost;
    this->cost = o.cost;
    this->pay_off = o.pay_off;           
}

Animal::~Animal() {
}

int Animal::getAge() {
    return age;
}

int Animal::getBabyNum() {
    return baby_num;
}

double Animal::getFeedingCost() {
    return base_food_cost;
}

double Animal::getCost() {
    return cost;
}

double Animal::getPayOff() {
    return pay_off;
}

bool Animal::isAdult() {
    return age >= 3;
}

void Animal::getOlder() {
    age++;
}
