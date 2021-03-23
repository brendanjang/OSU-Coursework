#include <cstdlib>
#include <typeinfo>
#include <string>
#include <iostream>
#include <climits>
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "Menu.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Grid * grid;
    Menu menu;
    cout << "EXTRA CREDIT IS ADDED\n";
    string message;
    int row, col, ant, bug;
    int step;
    
    // get all required information    
    message = "Enter size of grid row";
    // the screen has 70 charter width
    // the grid shouldn't have size less than 3
    row = menu.getValue(&message, 1, 3, 30);
    message = "Enter size of grid column";
    col = menu.getValue(&message, 1, 3, 30);
    
    // number of ant and bug shouldn't be larger than the area of the grid
    message = "Enter number of ant";
    ant = menu.getValue(&message, 1, 1, row * col - 1);
    message = "Enter number of doodlebug";
    bug = menu.getValue(&message, 1, 1, row * col - ant);
    
    // allocate the grid
    grid = new Grid(row, col, ant, bug);

    string options [] = {
      "Enter number of time step to run"  ,
      "Enter 0 to stop"
    };
    int round = 0;
    
    // print out the starting state 
    cout << "Round " << round << "\n";
    cout << *grid << "\n";
    round++;
    // get number of step 
    step = menu.getValue(options, 2, 0, INT_MAX);
        
    while (step > 0) {    
        // taking step
        while (step > 0) {
            grid->step();
            cout << "Round "<< round << "\n";
            cout << *grid << "\n";
            step--;
            round++;
        }
        // get number of step 
        step = menu.getValue(options, 2, 0, INT_MAX);        
    }

    // free the allocated memory 
    delete grid;
    return 0;
}