/*************************************************************************
Author:			Brendan Jang
Date:			11/26/2018
Description:	Header file for class GBoard that has 2 data members - a
				2D array of char that represents the board and an enum
				variable names gameState that holds one of the following
				values: X_WON, O_WON, DRAW, or UNFINISHED. Also has a
				method called getGameState that retunrs value of gameState.
				ALso has a method called makeMove that takes as parameters
				an int for the row, an int for the column, and a char for
				the player. The row and column will be in the range 0-14.
				The player will be either 'x' or 'o'. This method should 
				return false if the square is already occupied or the game 
				had already finished.  Otherwise it should add the move to 
				the board, update the gameState, and return true.
**************************************************************************/
#ifndef GBOARD_HPP
#define GBOARD_HPP

// Define constant values
#define SIZE 15
#define SERIES 5
#define EMPTY '.'

// Enumerated type for gameState
enum gameState{X_WON, O_WON, DRAW, UNFINISHED};

// Class declaration
class GBoard
{
	private:
		char board[SIZE][SIZE];
		gameState state;
	public:
		GBoard();
		gameState getGameState();
		bool makeMove(int row, int col, char sign);
		void printBoard();
};
#endif
