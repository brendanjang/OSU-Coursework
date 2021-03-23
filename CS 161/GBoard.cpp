/**************************************************************************
Author:			Brendan Jang
Date:			11/26/2018
Description:	Implementation file for class GBoard.The class should have 
				two data members - a 2D array of char that represents the 
				board, and an enum variable called gameState that holds one
				of the four following values: X_WON, O_WON, DRAW, or 
				UNFINISHED. It should have a default constructor that 
				initializes all elements of the array to being empty and 
				initializes the gameState to UNFINISHED. It should have a 
				method called getGameState that returns the value of 
				gameState. It should have a method called makeMove that 
				takes as parameters an int for the row, an int for the 
				column, and a char for the player.  The row and column 
				will be in the range 0-14.  The player will be either 'x' 
				or 'o'.  This method should return false if the square is 
				already occupied or the game had already finished.
				Otherwise it should add the move to the board, update the 
				gameState, and return true.
**************************************************************************/
#include <algorithm>
#include <iostream>
#include "GBoard.hpp"

/*************************************************************************
Description: Default constructor that sets an empty board and gameState to
UNFINISHED.
*************************************************************************/
GBoard::GBoard()
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			board[row][col] = EMPTY;
		}
	}
	state = UNFINISHED;
}

// Method getGameState that returns the state of the game as enum type
gameState GBoard::getGameState()
{
	return state;
}

/**************************************************************************
Description: Method that takes 3 arguments, row and col as int and sign
as char. Returns true if the move is valid. Updates the state of the game
and searches for a winning series or full board for draw.
**************************************************************************/
bool GBoard::makeMove(int row, int col, char sign)
{
	bool result = false;

	// Check if arguments are valid
	if ((row < SIZE) && (col < SIZE) && ((sign == 'x') || 
		(sign == 'o')) && (board[row][col] == EMPTY) &&
		(state == UNFINISHED))
	{
		// Insert the new field value
		board[row][col] = sign;
		
		// Check if the new field is a member of winning series in
		// north south direction.
		// Minimum row index that can be a member.
		int rMin = std::max(row - SERIES + 1, 0);
		
		// Maximum row index that can be a member
		int rMax = std::min(row + SERIES, SIZE);

		// Start from min and check the series
		int rStart = rMin;
		
		bool win = false;
		while ((!win) && (rStart < (rMax - SERIES + 1)))
		{
			win = true;
			int rows = 0;
			while ((win) && (rows < SERIES))
			{
				win &= (board[rStart + rows][col] == sign);
				rows++;
			}
			rStart++;
		}

		// Check if the new field is a member of winning series in
		// west east direction.
		int cMin = std::max(col - SERIES + 1, 0);
		int cMax = std::min(col + SERIES, SIZE);
		int cStart = cMin;
		while ((!win) && (cStart < (cMax - SERIES + 1)))
		{
			win = true;
			int cols = 0;
			while ((win) && (cols < SERIES))
			{
				win &= (board[row][cStart + cols] == sign);
				cols++;
			}
			cStart++;
		}

		// Check if the new field is a member of winning series in
		// north west south east direction
		int length = std::min(rMax - rMin, cMax - cMin);
		int lens = 0;
		int startPosition = std::min(row - rMin, col - cMin);
		rStart = row - startPosition;
		cStart = col - startPosition;
		while ((!win) && (lens < (length - SERIES + 1)))
		{
			win = true;
			int rowCol = 0;
			while ((win) && (rowCol < SERIES))
			{
				win &= (board[rStart + rowCol][cStart + rowCol] == sign);
				rowCol++;
			}
			lens++;
			rStart++;
			cStart++;
		}

		// Check if the new field is a member of winning series in
		// north east south west direction
		lens = 0;
		startPosition = std::min(row - rMin, cMax - col - 1);
		rStart = row - startPosition;
		cStart = col + startPosition;
		while ((!win) && (lens < (length - SERIES + 1)))
		{
			win = true;
			int rowCol = 0;
			while ((win) && (rowCol < SERIES))
			{
				win &= (board[rStart + rowCol][cStart - rowCol] == sign);
				rowCol++;
			}
			lens++;
			rStart++;
			cStart--;
		}

		// Check to see if there is a win
		if (win)
		{
			// Check to see who won and update gameState
			if (sign == 'x')
			{
				state = X_WON;
			}
			else
			{
				state = O_WON;
			}
		}
		else
		{
			// Check for draw
			bool draw = true;
			int rows = 0;
			while ((draw) && (rows < SIZE))
			{
				int cols = 0;
				while ((draw) && (cols < SIZE))
				{
					draw &= (board[rows][cols] != EMPTY);
					cols++;
				}
				rows++;
			}
			if (draw)
			{
				state = DRAW;
			}
		}
		result = true;
	}
	return result;
}

/*************************************************************************
Description: Method to print the board.
*************************************************************************/
void GBoard::printBoard()
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			std::cout << board[row][col];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
