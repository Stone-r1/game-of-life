#include "statusBar.h"

StatusBar::StatusBar(float x, float y, float width, float height) : isRunning(false) {
    button = {x, y, width, height};
}

bool StatusBar::getButtonStatus() const {
    return isRunning;
}

void StatusBar::handleButtonClick(Vector2 mousePos) {
    if (CheckCollisionPointRec(mousePos, button)) {
        isRunning = !isRunning;
    }
}

void StatusBar::draw() const {
    Color buttonColor = isRunning ? GREEN : RED;
    const char* buttonText = isRunning ? "Running" : "Paused";

    DrawRectangleRec(button, buttonColor);
    DrawText(buttonText,
             button.x + 10,
             button.y + button.height / 4,
             20,
             WHITE);
}
