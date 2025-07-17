#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <vector>

#define ROWS  80
#define COLS  50
#define SIZE  15

class Board {
private:
    std::vector<std::vector<Cell>> grid;

public:
    Board();
    void initializeBoard();
    void randomize();
    void toggleCell(int x, int y);
    void update();
    void drawCells() const;
};  

#endif
