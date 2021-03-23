/**************************************************************************
** Program Name:	Project 1 - Main.cpp
** Author:			Brendan Jang
** Date:			1/19/2019
** Description:		Main function file for Langton's Ant simulation.
**************************************************************************/

#include <cstdlib>
#include <string>
#include <iostream>

#include "Menu.hpp"
#include "Ant.hpp"
using namespace std;

// Declare constant values
const char ANT = '*';
const char BLACK = '#';
const char WHITE = ' ';
const char EDGE_1 = '|';
const char EDGE_2 = '-';
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

// Function prototypes
int getValue(string message);
int getValueBelow(string message, int above);
char ** initBoard(int row, int col);
void deallocateBoard(char ** board, int row);
void printBoard(char ** board, int row, int col, Ant ant);
void moveAnt(char ** board, int row, int col, Ant & ant) ;

int main(int argc, char** argv) {
    
    // All required messages
    string list1 [] = 
	{
        "1. Start Langton's Ant simulation",
        "2. Quit"
    };
    string list2 [] = 
	{
        "1. Play again",
        "2. Quit"
    };
    string list3 [] = 
	{
        "1. Random starting location",
        "2. Entering starting location"
    };

    // Set up menu
    Menu m1(list1, 2);
    Menu m2(list2, 2);
    Menu m3(list3, 2);
    
    // All other variables 
    int row, col, x, y, step;
    Ant ant;
    char **arr;

    
    if (m1.getSelection() == 1) 
	{
        // Loop until the user wants to quit
        do 
		{   
            // Get user's input
            row = getValue("The number of row for the board: ");
            col = getValue("The number of column for the board: ");
            step = getValue("The number of step of the simulation: ");

            // Let user choose wether they want to put the ant on a random 
			// position
            if (m3.getSelection() == 1)
			{
                x = (rand() % row) + 1;
                y = (rand() % col) + 1;
            }

			// Otherwise, ask for the position
			else 
			{ 
                x = getValueBelow("The starting row of the ant ", row);
                y = getValueBelow("The starting column of the ant ", col);
            }

            // Set up the ant
            ant.setX(x);
            ant.setY(y);
            ant.setOrient(RIGHT);
            
            // Initiate the board
            arr = initBoard(row, col);
            
            // Run all steps
            for (int i = 0; i < step; i++) 
			{
                // Print board
                printBoard(arr, row, col, ant);
                // Move ant
                moveAnt(arr, row, col, ant);
            }
            
            // Free the board
            deallocateBoard(arr, row);
        } 
		while (m2.getSelection() != 2);
    }
    return 0;
}

/*
Move the ant around the board
@param board 2D board
@param row Number of row
@param col Number of column
@param ant Reference to Ant object
*/
void moveAnt(char ** board, int row, int col, Ant & ant)
{    
    // Get position of the ant
    int x, y, orientation;
    x = ant.getX();
    y = ant.getY();
    
    // Get current color of the board which is at that position 
    char color = board[x][y];
    
    // Get ant's orientation 
    orientation = ant.getOrientation();
    
    // The color is black, turn left
    if (color == BLACK) 
	{
        // Change board color
        board[x][y] = WHITE;
        // If the ant is looking right and it turns left, it will look up
        // right is 1, up is 0
        orientation--;
        // If it is looking up, then it will look to the left after 
		// turning left, left is 3
        if (orientation < 0) 
		{
            orientation = LEFT;
        }
    }
	else 
	{
        // Cange board color
        board[x][y] = BLACK;
        // Turn right
        orientation++;
        // If it reaches 4, it looks up then it is 0
        orientation = orientation % 4;
    }
    // Set ant's orientation 
    ant.setOrient(orientation);
    
    // Move the ant to the new position
    switch(orientation)
	{
        case LEFT:
            y--;
            break;
        case UP:
            x--;
            break;
        case RIGHT:
            y++;
            break;
        case DOWN:
            x++;
            break;            
    }
    
    // If the ant moves out of the board we make it to appear 
	// on the other edge of the board
    if (x < 1)
	{
        x = row;
    } 
	else if (x > row)
	{
        x = 1;
    }
    if (y < 1)
	{
        y = col;
    } 
	else if (y > col)
	{
        y = 1;
    }
    
    // Set its new position
    ant.setX(x);
    ant.setY(y);
}

/*
Put the ant on board, then print the board, then pick the ant off of board
@param board The 2D borad
@param row Number of row
@param col Number of column
@param ant Reference to Ant object
*/
void printBoard(char ** board, int row, int col, Ant ant)
{
    // Get current position of ant 
    int x, y;
    x = ant.getX();
    y = ant.getY();
    
    // Get color of cell where we assume that the ant standing in
    char color = board[x][y];
    
    // Put the ant into that position
    board[ant.getX()][ant.getY()] = ANT;
    
    // Show the board which has the ant on it 
    for (int i = 0; i < row + 2; i++)
	{
        for (int j = 0; j < col + 2; j++)
		{
            cout << board[i][j];
        }
        cout << "\n";
    }
    // Pick the ant out and restore the state of board 
    board[ant.getX()][ant.getY()] = color;
}

/*
Free allocated memory
@param board 2D array
@param row number of row
*/
void deallocateBoard(char ** board, int row)
{    
    // Free each pointer
    for (int i = 0; i < row + 2; i++)
	{
        delete [] board[i];
    }
    // Free the array of pointer 
    delete [] board;
}

/*
Allocate the memory and set up the board
@param row number of row
@param col number of column
@return a 2D array of char
*/
char ** initBoard(int row, int col)
{
    char ** arr;
    // Allocate array of char pointer 
    arr = new char*[row + 2];
    // For each pointer 
    for (int i = 0; i < row + 2; i++)
	{
        // Allocate array of char
        arr[i] = new char[col + 2];
        // Set each of char in the array to space
        for (int j = 1; j <= col; j++)
		{
            arr[i][j] = WHITE;
        }
        // Set edge value to head and tail of the array
        arr[i][0] = EDGE_1;
        arr[i][col + 1] = EDGE_1;
    }

    // set the first array and the last array to --------------
    for (int i = 0; i <= col + 1; i++)
	{
        arr[0][i] = EDGE_2;
        arr[row + 1][i] = EDGE_2;
    }
    return arr;
}

/*
Get input from user
@param message The prompt
@param above The max value 
@return a legal input
*/
int getValueBelow(string message, int above)
{
    int val = -1;
    string input;
    // Continue until getting the right input
    while (val <= 0 || val > above)
	{
        // Show prompt
        cout << message << "(" << 1 << "-" << above << "): ";
        // Get input
        cin >> input;
        // Turn input to an integer
        try 
		{
        	val = stoi(input);
        }
		catch (exception const & ex)
		{
        	val = -1;
        }
    }
    return val;
}

/*
Get input from user
@param message The prompt 
@return legal input from user 
*/
int getValue(string message)
{
    int val = -1;
    string input;
    while (val <= 0)
	{
        // Show prompt
        cout << message;
        // Get input
        cin >> input;
        // Turn input to an integer 
        try
		{
        	val = stoi(input);
        } 
		catch (exception const & ex)
		{
            val = -1;
        }
    }
    return val;
}
