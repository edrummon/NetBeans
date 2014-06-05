/* 
 * File:   main.cpp
 * Author: Instinct212
 *
 * Created on June 4, 2014, 2:25 PM
 */

#include "gameBoard.h"
#include <time.h>

using std::cout;            using std::endl;
using std::cin;             using std::string;

void wait(int seconds) {
    int endwait = clock() + seconds * CLOCKS_PER_SEC * .5;
    while (clock() < endwait) {}
}

int main(int argc, char** argv) {
    
    int numIterations, width, height;
    cin >> numIterations >> width >> height;
    cin.ignore();
    
    gameBoard Game = gameBoard(width, height);
    Game.getNewGameBoard();
    
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        
        wait(1); cout << "\n\n";
        //count each cell's neighbors and determine their new status
        Game.evaluateNeighbors();
        
        //update each cell and print new gameBoard
        Game.updateAndPrint();
    }

    return 0;
}