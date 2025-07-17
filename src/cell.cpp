#include "cell.h"

Cell::Cell() : isActive(false), nextState(false) {};

void Cell::setStatus(bool status) {
    isActive = status;
}

bool Cell::getStatus() const {
    return isActive;
}

void Cell::setNextState(bool status) {
    nextState = status;
}

bool Cell::getNextState() const {
    return nextState;
}

void Cell::advance() {
    isActive = nextState;
}
