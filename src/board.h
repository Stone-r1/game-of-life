#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <vector>

class Board {
private:
    std::vector<std::vector<Cell>> grid;
    bool gameOver;
};  

#endif
