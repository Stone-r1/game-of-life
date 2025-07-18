#include "statusBar.h"

StatusBar::StatusBar(float x, float y, float width, float height) : isRunning(false) {
    button = {x, y, width, height};
}

bool StatusBar::getButtonStatus() const {
    return isRunning;
}

int StatusBar::handleButtonClick(Vector2 mousePos) {
    if (!CheckCollisionPointRec(mousePos, button)) return false;

    Rectangle pauseButton = {button.x, button.y, button.width / 3, button.height};
    Rectangle randomizeButton = {button.x + button.width / 3, button.y, button.width / 3, button.height};
    Rectangle clearButton = {button.x + 2 * button.width / 3, button.y, 2 * button.width / 3, button.height};

    if (CheckCollisionPointRec(mousePos, pauseButton)) {
        isRunning = !isRunning;
        return 0;
    }
    
    if (CheckCollisionPointRec(mousePos, randomizeButton) && !isRunning) {
        return 1; 
    }

    if (CheckCollisionPointRec(mousePos, clearButton) && !isRunning) {
        return 2;
    }

    return 0;
}

void StatusBar::draw() const { 

    Rectangle pauseButton = {button.x, button.y, button.width / 3, button.height};
    Rectangle randomizeButton = {button.x + button.width / 3, button.y, button.width / 3, button.height};
    Rectangle clearButton = {button.x + 2 * button.width / 3, button.y, 2 * button.width / 3, button.height};

    Color pauseButtonColor = isRunning ? GREEN : RED;
    const char* pauseButtonText = isRunning ? "Running" : "Paused";
    const char* randomizeButtonText = "Randomize";
    const char* clearButtonText = "Clear";

    DrawRectangleRec(pauseButton, pauseButtonColor);
    DrawText(pauseButtonText, pauseButton.x + 10, pauseButton.y + pauseButton.height / 4, 20, WHITE);

    DrawRectangleRec(randomizeButton, GRAY);
    DrawText(randomizeButtonText, randomizeButton.x + 10, randomizeButton.y + randomizeButton.height / 4, 20, WHITE);

    DrawRectangleRec(clearButton, GRAY);
    DrawText(clearButtonText, clearButton.x + 10, clearButton.y + clearButton.height / 4, 20, WHITE);
}
