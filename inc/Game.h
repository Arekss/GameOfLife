#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <chrono>
#include <thread>

#include "Cell.h"

class Game {
public:
    Game();

    static const int size = 10;
    static Cell board[10][10];

    void init();
    void run();
    void printBoard();
    void updateBoard();
    void updatePrintedCharacter();
    void updateCell(Cell& cell,Cell& tempCell, int i, int j);

};


#endif
