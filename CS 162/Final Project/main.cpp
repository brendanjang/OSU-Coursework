/***************************************************************************** 
** Program Name:	Final Project - main.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Main implementation file for Final Project program.
*****************************************************************************/

#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <string>

#include "Game.hpp"
#include "SpaceStreet.hpp"
#include "SpaceBasement.hpp"
#include "SpaceBedroom.hpp"
#include "SpaceGarden.hpp"
#include "SpaceHall.hpp"
#include "SpaceKitchen.hpp"

using namespace std;


// static variables of Game class
Item * Game::howToBook = new Item("book","How To Fix Everything For Dummy");
Item * Game::gateKey = new Item("key", "Gate Key");
Item * Game::toolBox = new Item("box", "Tool Box");
Item * Game::bread = new Item("bread", "Texas Toast");
Item * Game::broom = new Item("broom", "Corn Broom with Solid Wood Handle");


int Space::counter = 1;


Space * Game::street = new SpaceStreet();
Space * Game::basement = new SpaceBasement();
Space * Game::bedroom = new SpaceBedroom();
Space * Game::gardern = new SpaceGarden();
Space * Game::hall = new SpaceHall();
Space * Game::kitchen = new SpaceKitchen();


int main(int argc, char** argv) {
    Menu menu;
    string message = "Enter the number of steps to run this game";
    int step = menu.getValue(&message, 1, 1, 600);
    Game game(step);
    game.launch();
    return 0;
}