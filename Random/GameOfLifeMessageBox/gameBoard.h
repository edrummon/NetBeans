/* 
 * File:   gameBoard.h
 * Author: Instinct212
 *
 * Created on June 4, 2014, 3:38 PM
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H

#include <iostream>
#include <windows.h>
#include <sstream>

struct cell {
    cell() { activeNeighbors = 0; currentStatus = nextStatus = '.'; }
    void setNextStatus();
    void updateStatus() { currentStatus = nextStatus; }
    
    bool isActive() const { return currentStatus == '#'; }

    int activeNeighbors;
    char currentStatus, nextStatus;
};

class gameBoard {
public:
    gameBoard() {}
    gameBoard(int, int);
    ~gameBoard();
    
    void getNewGameBoard();
    void evaluateNeighbors();
    void updateAndPrint();
private:
    cell** board;
    int boardWidth, boardHeight;
};

#endif	/* GAMEBOARD_H */