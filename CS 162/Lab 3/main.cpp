/***************************************************************************
Program Name:	War Game with Dice Design - main.cpp
Author:			Brendan Jang
Date:			1/24/2019
Description:	Main function file for War Game with Dice Program
***************************************************************************/

#include <cstdlib>
#include "Game.hpp"

using namespace std;

int main(int argc, char** argv)
{
    // Create a game
    Game game;
    // Run the game
    game.start();
    return 0;
}
