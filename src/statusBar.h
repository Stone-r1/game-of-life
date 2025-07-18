#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "raylib.h"

class StatusBar {
private:
    bool isRunning;
    Rectangle button;

public:
    StatusBar(float x, float y, float width, float height);
    bool getButtonStatus() const;
    bool handleButtonClick(Vector2 mousePos);
    void draw() const;
};

#endif
