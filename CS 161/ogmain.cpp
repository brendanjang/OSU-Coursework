/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tamas.sakac
 *
 * Created on 22. novembar 2018., 23.57
 */

#include <cstdlib>
#include <iostream>
#include "GBoard.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    GBoard b;
    int player = 0;
    int row, col;
    char c[] = {'x', 'o'};
    bool validMove;
    while (b.getGameState() == UNFINISHED)
    {
        b.printBoard();
        validMove = false;
        while (!validMove)
        {
            cout << "Player " << player + 1 << " move 1..15 1..15:";
            cin >> row >> col;
            validMove = b.makeMove(row - 1, col - 1, c[player]);
        }
        player = (player + 1) % 2;
    }
    switch (b.getGameState())
    {
        case X_WON:
            cout << endl << "Player 1 won!!!" << endl;
            break;
        case O_WON:
            cout << endl << "Player 2 won!!!" << endl;
            break;
        default:
            cout << endl << "DRAWN!!!" << endl;            
    }
    return 0;
}

