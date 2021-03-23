/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>
#include <iostream>
#include "GBoard.hpp"

using namespace std;


/************************
 * Default constructor
 * Set an empty board
 * and gameState to UNFINISHED
 * *********************/
GBoard::GBoard()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            board[row][col] = EMPTY;
        }
    }
    gameState = UNFINISHED;
}

/************************
 * Method getGameState
 * arguments:
 * return: the state of the game as enum type GameStates
 * *********************/
GameStates GBoard::getGameState()
{
    return gameState;
}

/************************
 * Method makeMove
 * arguments: row, col as int, and sign as char
 * return true if the move is valid
 * also updates the state of the game, searches for a winning series
 * or full board for drawn
 * *********************/
bool GBoard::makeMove(int row, int col, char sign)
{
    bool result = false;
    /************************
    * Check if arguments are
    * valid
    * *********************/
    if ((row < SIZE) && (col < SIZE) && ((sign == 'x') || (sign == 'o')) && (board[row][col] == EMPTY) && (gameState == UNFINISHED))
    {
        /************************
        * Insert the new field
        * value
        * *********************/
        board[row][col] = sign;
        
        /************************
        * Check if the new field
        * is a member of winning
        * series in north-south
        * direction
        * *********************/
        int rmin = std::max(row - SERIES + 1, 0); // minimum row index that can be a member
        int rmax = std::min(row + SERIES, SIZE); // maximum row index that can be a member
        int rstart = rmin; // start from minimum and check the series
        bool win = false;
        while ((!win) && (rstart < (rmax - SERIES + 1)))
        {
            win = true;
            int r = 0;
            while ((win) && (r < SERIES))
            {
                win &= (board[rstart + r][col] == sign);
                r++;
            }
            rstart++;
        }

        /************************
        * Check if the new field
        * is a member of winning
        * series in west-east
        * direction
        * *********************/
        int cmin = std::max(col - SERIES + 1, 0);
        int cmax = std::min(col + SERIES, SIZE);
        int cstart = cmin;
        while ((!win) && (cstart < (cmax - SERIES + 1)))
        {
            win = true;
            int c = 0;
            while ((win) && (c < SERIES))
            {
                win &= (board[row][cstart + c] == sign);
                c++;
            }
            cstart++;
        }

        /************************
        * Check if the new field
        * is a member of winning
        * series in north-west -
        * south-east direction
        * *********************/
        int length = std::min(rmax - rmin, cmax - cmin);
        int l = 0;
        int startPosition = std::min(row - rmin, col - cmin); // both arguments may shorten the series
        rstart = row - startPosition ;
        cstart = col - startPosition;
        while ((!win) && (l < (length - SERIES + 1)))
        {
            win = true;
            int rc = 0;
            while ((win) && (rc < SERIES))
            {
                win &= (board[rstart + rc][cstart + rc] == sign);
                rc++;
            }
            l++;
            rstart++;
            cstart++;
        }

        /************************
        * Check if the new field
        * is a member of winning
        * series in north-east -
        * south-west direction
        * *********************/
        l = 0;
        startPosition = std::min(row - rmin, cmax - col - 1);
        rstart = row - startPosition ;
        cstart = col + startPosition;
        while ((!win) && (l < (length - SERIES + 1)))
        {
            win = true;
            int rc = 0;
            while ((win) && (rc < SERIES))
            {
                win &= (board[rstart + rc][cstart - rc] == sign);
                rc++;
            }
            l++;
            rstart++;
            cstart--;
        }

        /************************
        * Check if there is a win
        * *********************/
        if (win)
        {
            /************************
            * Check who won and update
            * gameState
            * *********************/
            if (sign == 'x')
            {
                gameState = X_WON;
            }
            else
            {
                gameState = O_WON;
            }
        }
        else 
        {
            /************************
            * Check for drawn (full board)
            * *********************/
            bool draw = true;
            int r = 0;
            while ((draw) && (r < SIZE))
            {
                int c = 0;
                while ((draw) && (c < SIZE))
                {
                    draw &= (board[r][c] != EMPTY);
                    c++;
                }
                r++;
            }
            if (draw)
            {
                gameState = DRAW;
            }
        }
        result = true;
    }
    return result;
}

/************************
 * Method printBoard
 * arguments: 
 * return nothing
 * prints the board
 * *********************/
void GBoard::printBoard()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << board[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

