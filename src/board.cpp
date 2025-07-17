#include "board.h"
#include "raylib.h"
#include <cstdlib>


Board::Board() {
    grid.assign(ROWS, std::vector<Cell>(COLS));
}

void Board::initializeBoard() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col].setStatus(false);
        }
    }
}

void Board::randomize() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col].setStatus(rand() % 2);
        }
    }
}

void Board::toggleCell(int x, int y) {
    if (x >= 0 && y >= 0 && x < ROWS && y < COLS) {
        grid[x][y].setStatus(!grid[x][y].getStatus());
    }
}

const int rowDir[8] = {-1, 0, 1, 1, 1, 0, -1, -1}, colDir[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int countNeighbors(const std::vector<std::vector<Cell>>& grid, int row, int col) {
    int count = 0;
    for (int d = 0; d < 8; d++) {
        int newRow = row + rowDir[d];
        int newCol = col + colDir[d];
        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) continue;
        if (grid[newRow][newCol].getStatus()) count++; 
    }
    return count;
}

void Board::update() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int alive = countNeighbors(grid, row, col);
            bool next = (alive == 3 || (grid[row][col].getStatus() && alive == 2));
            grid[row][col].setNextState(next);
        }
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col].advance(); 
        }
    }
}

void Board::drawCells() const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int x = i * SIZE;
            int y = j * SIZE;
            if (grid[i][j].getStatus()) {
                DrawRectangle(x, y, SIZE, SIZE, WHITE);
            } else {
                DrawRectangleLines(x, y, SIZE, SIZE, DARKGRAY);
            }
        }
    }
}
