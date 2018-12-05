#include "tetromino.h"
#include "coordinate.h"

Tetromino::Tetromino() {
  this->orientation = 1;
}

Coordinate Tetromino::getCurrentLocation() {
  return currentLocation;
}

void Tetromino::setCurrentLocation(Coordinate location) {
  currentLocation = location;
}

/*const Coordinate** Tetromino::getLocalArray() {
    switch (this->orientation) {
        case 1:
            return orientation1;
        case 2:
            return orientation2;
        case 3:
            return orientation3;
        case 4:
            return orientation4;
    }
}*/
