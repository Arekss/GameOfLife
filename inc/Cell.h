
#ifndef CELL_H
#define CELL_H

class Cell {
public:

    enum Position {
        INSIDE,
        UP,
        RIGHT,
        DOWN,
        LEFT,
        UPRIGHT,
        UPLEFT,
        DOWNLEFT,
        DOWNRIGHT,
    };

    Cell() : c(' '), alive(false), pos(INSIDE), neighbours(0) {};

    Position pos;
    bool alive;
    int neighbours;
    char c;
};

#endif //CELL_H
