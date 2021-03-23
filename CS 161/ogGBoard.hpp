/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GBoard.hpp
 * Author: Randos
 *
 * Created on 22. novembar 2018., 23.58
 */

#ifndef GBOARD_HPP
#define GBOARD_HPP

/************************
 * Definitions of some 
 * constant values
 * *********************/
#define SIZE    15  //size of the board
#define SERIES  5   //how many symbols are a winning serie
#define EMPTY   '.' //empty character representation on board

/************************
 * Enumerated type for gameState
 * *********************/
enum GameStates {X_WON, O_WON, DRAW, UNFINISHED};


/************************
 * Class declaration
 * *********************/
class GBoard
{
private:
    char board[SIZE][SIZE];
    GameStates gameState;
public:
    GBoard();
    GameStates getGameState();
    bool makeMove(int row, int col, char sign);
    void printBoard();
};



#endif /* GBOARD_HPP */

