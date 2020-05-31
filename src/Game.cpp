#include "Game.h"

Game::Game() {
    board[0][0].pos = Cell::UPLEFT;
    board[9][0].pos = Cell::UPRIGHT;
    board[9][0].pos = Cell::DOWNRIGHT;
    board[0][9].pos = Cell::DOWNLEFT;
    for (int i = 1; i < 9; i++) {
        board[i][0].pos = Cell::LEFT;
        board[0][i].pos = Cell::UP;
        board[9][i].pos = Cell::DOWN;
        board[i][9].pos = Cell::RIGHT;
    }
	po::options_description config("Configuration");
        config.add_options()
            ("max_num_of_iterations", po::value<int>(&n_iterations)->default_value(10), 
             "max number of iterations")
	    ("speed", po::value<int>(&delay_in_ms)->default_value(500),"speed of simulation");

	po::variables_map vm;
	std::ifstream ifs;
	ifs.open("../config.cfg", std::ifstream::out);
	if (!ifs.is_open()) std::cout << "Config file not found. Using default values\n";
        po::store(po::parse_config_file(ifs,config), vm);
        notify(vm);
};

void Game::printBoard() {
    for (auto &row : board) {
        std::cout << std::endl;
        for (auto &el : row) // el means element
            std::cout << el.c;

    }
}

void Game::updateBoard() {
    Cell tempBoard[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            tempBoard[i][j] = board[i][j];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            updateCell(board[i][j], tempBoard[i][j], i, j);
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = tempBoard[i][j];

    updatePrintedCharacter();
}

void Game::updatePrintedCharacter()
{
    for (auto &row : board)
        for (auto &el : row) // el means element
            el.alive ? el.c = '*' : el.c = ' ';
}

void Game::run() {

    init();
    int i = 0;
    while (i++ < n_iterations) {
	system("clear");
        updateBoard();
        printBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_ms));
    }
}

void Game::updateCell(Cell &cell, Cell &tempCell, int i, int j) {

    tempCell.neighbours = 0;

    switch (cell.pos) {
        case Cell::UPLEFT: {
            if (board[0][1].alive) tempCell.neighbours++;
            if (board[1][0].alive) tempCell.neighbours++;
            if (board[1][1].alive) tempCell.neighbours++;
            break;
        }

        case Cell::DOWNLEFT: {
            if (board[size - 2][0].alive) tempCell.neighbours++;
            if (board[size - 2][1].alive) tempCell.neighbours++;
            if (board[size - 1][1].alive) tempCell.neighbours++;
            break;
        }

        case Cell::DOWNRIGHT: {
            if (board[size - 2][size - 1].alive) tempCell.neighbours++;
            if (board[size - 1][size - 2].alive) tempCell.neighbours++;
            if (board[size - 2][size - 2].alive) tempCell.neighbours++;
            break;
        }
        case Cell::UPRIGHT: {
            if (board[0][size - 2].alive) tempCell.neighbours++;
            if (board[1][size - 1].alive) tempCell.neighbours++;
            if (board[1][size - 2].alive) tempCell.neighbours++;
            break;
        }
        case Cell::INSIDE: {
            if (board[i + 1][j + 1].alive) tempCell.neighbours++;
            if (board[i - 1][j - 1].alive) tempCell.neighbours++;
            if (board[i - 1][j + 1].alive) tempCell.neighbours++;
            if (board[i + 1][j - 1].alive) tempCell.neighbours++;
            if (board[i][j + 1].alive) tempCell.neighbours++;
            if (board[i][j - 1].alive) tempCell.neighbours++;
            if (board[i + 1][j].alive) tempCell.neighbours++;
            if (board[i - 1][j].alive) tempCell.neighbours++;
            break;
        }
        case Cell::UP: {
            if (board[0][j - 1].alive) tempCell.neighbours++;
            if (board[0][j + 1].alive) tempCell.neighbours++;
            if (board[1][j + 1].alive) tempCell.neighbours++;
            if (board[1][j - 1].alive) tempCell.neighbours++;
            if (board[1][j].alive) tempCell.neighbours++;
            break;
        }
        case Cell::DOWN: {
            if (board[size - 1][j - 1].alive) tempCell.neighbours++;
            if (board[size - 1][j + 1].alive) tempCell.neighbours++;
            if (board[size - 2][j + 1].alive) tempCell.neighbours++;
            if (board[size - 2][j - 1].alive) tempCell.neighbours++;
            if (board[size - 2][j].alive) tempCell.neighbours++;
            break;
        }
        case Cell::RIGHT: {
            if (board[i - 1][size - 1].alive) tempCell.neighbours++;
            if (board[i + 1][size - 1].alive) tempCell.neighbours++;
            if (board[i - 1][size - 2].alive) tempCell.neighbours++;
            if (board[i + 1][size - 2].alive) tempCell.neighbours++;
            if (board[i][size - 2].alive) tempCell.neighbours++;
            break;
        }
        case Cell::LEFT: {
            if (board[i - 1][0].alive) tempCell.neighbours++;
            if (board[i + 1][0].alive) tempCell.neighbours++;
            if (board[i - 1][1].alive) tempCell.neighbours++;
            if (board[i + 1][1].alive) tempCell.neighbours++;
            if (board[i][1].alive) tempCell.neighbours++;
            break;
        }
    }

    if (!tempCell.alive && tempCell.neighbours == 3) tempCell.alive = true;
    else if (tempCell.alive && (tempCell.neighbours != 2 && tempCell.neighbours != 3)) tempCell.alive = false;
}

void Game::init() {

    board[2][0].alive=true;
    board[2][1].alive=true;
    board[2][2].alive=true;
    //board[0][1].alive=true;
    //board[1][2].alive=true;
};

Cell Game::board[10][10];
