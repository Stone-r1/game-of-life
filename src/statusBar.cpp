#include "statusBar.h"

StatusBar::StatusBar(float x, float y, float width, float height) : isRunning(false) {
    button = {x, y, width, height};
}

bool StatusBar::getButtonStatus() const {
    return isRunning;
}

bool StatusBar::handleButtonClick(Vector2 mousePos) {
    if (!CheckCollisionPointRec(mousePos, button)) return false;

    Rectangle pauseButton = {button.x, button.y, button.width / 2, button.height};
    Rectangle randomizeButton = {button.x + button.width / 2, button.y, button.width / 2, button.height};

    if (CheckCollisionPointRec(mousePos, pauseButton)) {
        isRunning = !isRunning;
        return false;
    }
    
    if (CheckCollisionPointRec(mousePos, randomizeButton)) {
        return true; 
    }

    return false;
}

void StatusBar::draw() const { 
    Rectangle pauseButton = {button.x, button.y, button.width / 2, button.height};
    Rectangle randomizeButton = {button.x + button.width / 2, button.y, button.width / 2, button.height};

    Color pauseButtonColor = isRunning ? GREEN : RED;
    const char* pauseButtonText = isRunning ? "Running" : "Paused";
    const char* randomizeButtonText = "Randomize";

    DrawRectangleRec(pauseButton, pauseButtonColor);
    DrawText(pauseButtonText, pauseButton.x + 10, pauseButton.y + pauseButton.height / 4, 20, WHITE);

    DrawRectangleRec(randomizeButton, GRAY);
    DrawText(randomizeButtonText, randomizeButton.x + 10, randomizeButton.y + randomizeButton.height / 4, 20, WHITE);
}
