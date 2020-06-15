#ifndef GAME_H
#define GAME_H

#define VEC_BUFF_SIZE 100

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstdlib>

#include "Cell.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;

class Game {
public:
    Game();

    void init();
    void run();
    void printBoard();
    void updateBoard();
    void updatePrintedCharacter();
    void updateCell(Cell& cell,Cell& tempCell, int i, int j);
    void initFromRleFile(std::ifstream& T);
    void mapConstructToBoard(std::vector<std::vector<bool>>& vec);

    int size;
    std::vector<std::vector<Cell>> board;

    private:
    int n_iterations;
    int delay_in_ms;
    std::string construct_name;
    bool is_periodic_boundary;
};


#endif
