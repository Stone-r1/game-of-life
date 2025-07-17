#include "cell.h"

Cell::Cell() : isActive(false) {};

void Cell::setStatus(bool status) {
    isActive = status;
}

bool Cell::getStatus() const {
    return isActive;
}
