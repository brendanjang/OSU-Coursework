/***************************************************************************
**	Program Name:	Project 2 - main.cpp
**	Author:			Brendan Jang
**	Date:			2/2/2019
**	Description:	Implementation file for Zoo Tycoon program. Zoo tycoon
					is a game that allows  players to run a zoo business.
					Different types of animals cost different prices, have
					different maintenance costs, and of course, return a 
					different profit at the end of each day. For this game,
					the player will be the proud owner of a virtual zoo
					that has spaces to house tigers, penguins and turtles.
***************************************************************************/

#include <cstdlib>
#include "Zoo.hpp"

using namespace std;

int main(int argc, char** argv) {
    // Declare an object 
    Zoo zoo;
    // Run
    zoo.run();
    
    return 0;
}
