#include "Game.h"

Game::Game() {
	po::options_description config("Configuration");
        config.add_options()
            ("max_num_of_iterations", po::value<int>(&n_iterations)->default_value(10), 
                    "max number of iterations")
            ("size", po::value<int>(&size)->default_value(15), "width and length of board")
            ("construct_name", po::value<std::string>(&construct_name)->default_value("invalid"), "rle name")
            ("glued_edges", po::value<bool>(&is_periodic_boundary)->default_value(false), "glued edges")
            ("display", po::value<std::string>(&display_mode)->default_value("console"), "display mode")
	        ("speed", po::value<int>(&delay_in_ms)->default_value(500),"speed of simulation");

	po::variables_map vm;
	std::ifstream ifs;
	ifs.open("../config.cfg", std::ifstream::out);
	if (!ifs.is_open()) std::cout << "Config file not found. Using default values\n";
        po::store(po::parse_config_file(ifs,config), vm);
        notify(vm);

	board.resize(size, std::vector<Cell>(size));

        board[0][0].pos = Cell::UPLEFT;
        board[0][size-1].pos = Cell::UPRIGHT;
        board[size-1][size-1].pos = Cell::DOWNRIGHT;
        board[size-1][0].pos = Cell::DOWNLEFT;
        for (int i = 1; i < size-1; i++) {
            board[i][0].pos = Cell::LEFT;
            board[0][i].pos = Cell::UP;
            board[size-1][i].pos = Cell::DOWN;
            board[i][size-1].pos = Cell::RIGHT;
        }
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
    if (display_mode == "SFML")
    {
        useGraphicalDisplay();
    }
    else {
    int i = 0;
    while (i++ < n_iterations) {
            system("clear");
            updateBoard();
            printBoard();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_ms));
        }
    }
}

void Game::updateCell(Cell &cell, Cell &tempCell, int i, int j) {

    tempCell.neighbours = 0;

    switch (cell.pos) {
        case Cell::UPLEFT: {
            if (board[0][1].alive)               tempCell.neighbours++;
            if (board[1][0].alive)               tempCell.neighbours++;
            if (board[1][1].alive)               tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[size - 1][size - 1].alive) tempCell.neighbours++;
                if (board[size - 1][1].alive)        tempCell.neighbours++;
                if (board[1][size - 1].alive)        tempCell.neighbours++;
                if (board[size - 1][0].alive)        tempCell.neighbours++;
                if (board[0][size - 1].alive)        tempCell.neighbours++;
            }

            break;
        }

        case Cell::DOWNLEFT: {
            if (board[size - 2][0].alive)        tempCell.neighbours++;
            if (board[size - 2][1].alive)        tempCell.neighbours++;
            if (board[size - 1][1].alive)        tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[size - 1][size - 1].alive) tempCell.neighbours++;
                if (board[size - 2][size - 1].alive) tempCell.neighbours++;
                if (board[0][0].alive)               tempCell.neighbours++;
                if (board[0][1].alive)               tempCell.neighbours++;
                if (board[0][size -1].alive)         tempCell.neighbours++;
            }
            break;
        }

        case Cell::DOWNRIGHT: {
            if (board[size - 2][size - 1].alive) tempCell.neighbours++;
            if (board[size - 1][size - 2].alive) tempCell.neighbours++;
            if (board[size - 2][size - 2].alive) tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[0][size - 2].alive)        tempCell.neighbours++;
                if (board[0][size - 1].alive)        tempCell.neighbours++;
                if (board[0][0].alive)               tempCell.neighbours++;
                if (board[size - 1][0].alive)        tempCell.neighbours++;
                if (board[size - 2][0].alive)        tempCell.neighbours++;
            }
            break;
        }
        case Cell::UPRIGHT: {
            if (board[0][size - 2].alive)        tempCell.neighbours++;
            if (board[1][size - 1].alive)        tempCell.neighbours++;
            if (board[1][size - 2].alive)        tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[size-1][size - 2].alive)   tempCell.neighbours++;
                if (board[size-1][size - 1].alive)   tempCell.neighbours++;
                if (board[size-1][0].alive)          tempCell.neighbours++;
                if (board[0][0].alive)               tempCell.neighbours++;
                if (board[1][0].alive)               tempCell.neighbours++;
            }
            break;
        }
        case Cell::INSIDE: {
            if (board[i + 1][j + 1].alive) tempCell.neighbours++;
            if (board[i - 1][j - 1].alive) tempCell.neighbours++;
            if (board[i - 1][j + 1].alive) tempCell.neighbours++;
            if (board[i + 1][j - 1].alive) tempCell.neighbours++;
            if (board[i][j + 1].alive)     tempCell.neighbours++;
            if (board[i][j - 1].alive)     tempCell.neighbours++;
            if (board[i + 1][j].alive)     tempCell.neighbours++;
            if (board[i - 1][j].alive)     tempCell.neighbours++;
            break;
        }
        case Cell::UP: {
            if (board[0][j - 1].alive)     tempCell.neighbours++;
            if (board[0][j + 1].alive)     tempCell.neighbours++;
            if (board[1][j + 1].alive)     tempCell.neighbours++;
            if (board[1][j - 1].alive)     tempCell.neighbours++;
            if (board[1][j].alive)         tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[size-1][j-1].alive)  tempCell.neighbours++;
                if (board[size-1][j].alive)    tempCell.neighbours++;
                if (board[size-1][j+1].alive)  tempCell.neighbours++;
            }
            break;
        }
        case Cell::DOWN: {
            if (board[size - 1][j - 1].alive) tempCell.neighbours++;
            if (board[size - 1][j + 1].alive) tempCell.neighbours++;
            if (board[size - 2][j + 1].alive) tempCell.neighbours++;
            if (board[size - 2][j - 1].alive) tempCell.neighbours++;
            if (board[size - 2][j].alive)     tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[0][j-1].alive)          tempCell.neighbours++;
                if (board[0][j].alive)            tempCell.neighbours++;
                if (board[0][j+1].alive)          tempCell.neighbours++;
            }
            break;
        }
        case Cell::RIGHT: {
            if (board[i - 1][size - 1].alive) tempCell.neighbours++;
            if (board[i + 1][size - 1].alive) tempCell.neighbours++;
            if (board[i - 1][size - 2].alive) tempCell.neighbours++;
            if (board[i + 1][size - 2].alive) tempCell.neighbours++;
            if (board[  i  ][size - 2].alive) tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[i - 1][    0   ].alive) tempCell.neighbours++;
                if (board[  i  ][    0   ].alive) tempCell.neighbours++;
                if (board[i + 1][    0   ].alive) tempCell.neighbours++;
            }
            break;
        }
        case Cell::LEFT: {
            if (board[i - 1][0].alive) tempCell.neighbours++;
            if (board[i + 1][0].alive) tempCell.neighbours++;
            if (board[i - 1][1].alive) tempCell.neighbours++;
            if (board[i + 1][1].alive) tempCell.neighbours++;
            if (board[i][1].alive) tempCell.neighbours++;
            if (is_periodic_boundary){
                if (board[i-1][size-1].alive) tempCell.neighbours++;
                if (board[i][size-1].alive) tempCell.neighbours++;
                if (board[i+1][size-1].alive) tempCell.neighbours++;
            }
            break;
        }
    }

    if (!tempCell.alive && tempCell.neighbours == 3) tempCell.alive = true;
    else if (tempCell.alive && (tempCell.neighbours != 2 && tempCell.neighbours != 3)) tempCell.alive = false;
}

void Game::init() {

    std::ifstream T("../constructs/"+construct_name+".rle");
    if (T){
        initFromRleFile(T);
    }
    else{                       // default init
        board[4][5].alive=true;
        board[5][5].alive=true;
        board[6][5].alive=true;
        board[6][6].alive=true;
        board[5][7].alive=true;
    }
};

void Game::initFromRleFile(std::ifstream& T)
{
    std::stringstream buffer;
    buffer << T.rdbuf();
    std::string rlefile = buffer.str();
    std::istringstream f(rlefile);
    std::string line;

    std::vector<std::vector<bool>> Construct(VEC_BUFF_SIZE, std::vector<bool>(VEC_BUFF_SIZE, false));

    while (std::getline(f, line)) {
        if (line.find('#') == std::string::npos && line.find("rule") == std::string::npos) {
            int curRow = 0;
            int curCol = 0;
            int counter = 0;
            char prev = 'b';
            std::string s;
            for(char& c : line) {
                if (c=='!') break;
                if (c=='$') {
                    if (prev == 'b' || prev == 'o') {
                        curRow++;
                    }
                    else
                    {
                        for (int i = 0; i< counter; i++)
                        {
                            curRow++;
                        }
                    }
                    curCol = 0;
                }
                if (c=='b' || c=='o')
                {
                    if (prev == 'b' || prev == 'o' || prev == '$')
                    {
                        Construct[curRow][curCol] =  (c != 'b');
                        curCol+=1;
                    }
                    else
                    {
                        for (int i = 0; i< counter; i++)
                        {
                            Construct[curRow][curCol] = (c != 'b');
                            curCol+=1;
                        }
                    }
                }
                if (isdigit(c))
                {
                    s = c;
                    counter = atoi(s.c_str());
                }
                prev = c;
            }
        }
    }
    mapConstructToBoard(Construct);
};

void Game::mapConstructToBoard(std::vector<std::vector<bool>>& vec)
{
    for (int i=0;i<size-1;i++)
    {
        for (int j=0;j<size-1;j++)
        {
            board[i+1][j+1].alive = vec[i][j];
        }
    }
};

void Game::useGraphicalDisplay()
{
    int counter = 0;
    const int SIZE_OF_CELL = 25;
    const sf::Vector2f CELL_VECTOR{static_cast<float>(SIZE_OF_CELL), static_cast<float>(SIZE_OF_CELL)};
    sf::RenderWindow window(sf::VideoMode(SIZE_OF_CELL * size, SIZE_OF_CELL * size + 10), "Game of Life");
    while (window.isOpen() && counter++ < n_iterations) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear(sf::Color::White);
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                // draw cell
                sf::RectangleShape cell;
                cell.setPosition(x * SIZE_OF_CELL, y * SIZE_OF_CELL);
                cell.setSize(CELL_VECTOR);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color::Black);
                if (board[y][x].alive == true)
                    cell.setFillColor(sf::Color::Blue);
                else
                    cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
        }
        window.display();
        updateBoard();
        sf::sleep(sf::milliseconds(delay_in_ms));
    }
}
