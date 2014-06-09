#include <time.h>
#include "gameBoard.h"

using std::cout;            using std::endl;
using std::cin;             using std::string;

int main(int argc, char** argv) {
    
    int numIterations, width, height;
    cin >> numIterations >> width >> height;
    cin.ignore();
    
    gameBoard Game = gameBoard(width, height);
    Game.getNewGameBoard();
    
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        
        //count each cell's neighbors and determine their new status
        Game.evaluateNeighbors();
        
        //update each cell and print new gameBoard
        Game.updateAndPrint();
    }

    return 0;
}