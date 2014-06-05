#include "gameBoard.h"

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::getline;

void cell::setNextStatus() {
    if (currentStatus == '#' && (activeNeighbors < 2 || activeNeighbors > 3))
        nextStatus = '.';
    else if (currentStatus == '.' && activeNeighbors == 3)
        nextStatus = '#';
    else
        nextStatus = currentStatus;    
}

gameBoard::gameBoard(int width, int height) {
    boardWidth = width;
    boardHeight = height;
    
    board = new cell*[height];
    for (int y = 0; y < height; ++y)
        board[y] = new cell[width];
}

gameBoard::~gameBoard() {
    for (int y = 0; y < boardHeight; ++y) {
        delete[] board[y];
    }
    delete[] board;
}

void gameBoard::getNewGameBoard() {
    string line;
    int y = 0;
    
    while (getline(cin, line)) {

        for (int x = 0; x < boardWidth; ++x)
            board[y][x].currentStatus = line[x];
        ++y;
    }
}

void gameBoard::evaluateNeighbors() {
    int activeNeighbors = 0;
    for (int y = 0; y < boardHeight; ++y) {

        for (int x = 0; x < boardWidth; ++x) {

            activeNeighbors = 0;
            //left and right neighbors
            if (board[y][(x + boardWidth - 1) % boardWidth].isActive())
                ++activeNeighbors;
            if (board[y][(x + boardWidth + 1) % boardWidth].isActive())
                ++activeNeighbors;

            //top and bottom neighbors
            if (board[(y + boardHeight - 1) % boardHeight][x].isActive())
                ++activeNeighbors;
            if (board[(y + boardHeight + 1) % boardHeight][x].isActive())
                ++activeNeighbors;

            //top left and top right neighbors
            if (board[(y + boardHeight - 1) % boardHeight][(x + boardWidth - 1) % boardWidth].isActive())
                ++activeNeighbors;
            if (board[(y + boardHeight - 1) % boardHeight][(x + boardWidth + 1) % boardWidth].isActive())
                ++activeNeighbors;

            //bottom left and bottom right neighbors
            if (board[(y + boardHeight + 1) % boardHeight][(x + boardWidth - 1) % boardWidth].isActive())
                ++activeNeighbors;
            if (board[(y + boardHeight + 1) % boardHeight][(x + boardWidth + 1) % boardWidth].isActive())
                ++activeNeighbors;

            board[y][x].activeNeighbors = activeNeighbors;
            board[y][x].setNextStatus();
        }
    }
}

void gameBoard::updateAndPrint() {
    for (int y = 0; y < boardHeight; ++y) {
        
        for (int x = 0; x < boardWidth; ++x) {
            
            board[y][x].updateStatus();
            cout << board[y][x].currentStatus;
        }
        cout << endl;
    }
}