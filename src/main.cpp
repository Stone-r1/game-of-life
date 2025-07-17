#include "raylib.h"
#include "board.h"

int main() {
    const int width = ROWS * SIZE;
    const int height = COLS * SIZE;

    InitWindow(width, height, "Game Of Life");
    SetTargetFPS(10);

    Board board;
    board.initializeBoard();
    bool paused = true;

    while(!WindowShouldClose()) {
        if (!paused) {
            board.update();
        }

        BeginDrawing();
            ClearBackground(BLACK);
            board.drawCells();
        EndDrawing();
    }
}
