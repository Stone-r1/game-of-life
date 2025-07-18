#include "raylib.h"
#include "board.h"
#include "statusBar.h"

int main() {
    const int width = ROWS * SIZE;
    const int height = COLS * SIZE;

    InitWindow(width, height, "Game Of Life");
    SetTargetFPS(10);

    Board board;
    StatusBar bar(0, 0, width, ROWS - COLS);
    board.initializeBoard();
    bool paused = true;

    while(!WindowShouldClose()) { 
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int arg = bar.handleButtonClick(mouse);
            if (arg == 1) {
                board.randomize();
            } else if (arg == 2) {
                board.clearBoard();
            }
        }

        paused = !bar.getButtonStatus();

        if (paused && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int x = mouse.x / SIZE;
            int y = mouse.y / SIZE;
            board.toggleCell(x, y);
        }

        if (paused && (IsMouseButtonDown(MOUSE_LEFT_BUTTON))) {
            int x = mouse.x / SIZE;
            int y = mouse.y / SIZE;
            board.toggleCell(x, y);
        }

        if (!paused) {
            board.update();
        }

        BeginDrawing();
            ClearBackground(BLACK);
            board.drawCells();
            bar.draw();
        EndDrawing();
    }
}
