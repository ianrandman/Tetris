#include "tetromino.h"
#include "coordinate.h"

Tetromino::Tetromino() {
  this->orientation = 1;
  this->currentLocation = Coordinate(2, 3, Color::Black); // color ignored
}

Coordinate Tetromino::getCurrentLocation() {
  return currentLocation;
}

void Tetromino::setCurrentLocation(Coordinate location) {
  currentLocation = location;
}

void Tetromino::moveCurrentLocation(int deltaRow, int deltaCol) {
  int currentRow = currentLocation.getRow();
  int currentCol = currentLocation.getCol();
  currentLocation = Coordinate(currentRow + deltaRow, currentCol + deltaCol, Color::Black);
}

void Tetromino::moveUp() {
  moveCurrentLocation(-1,0);
}

void Tetromino::moveDown() {
  moveCurrentLocation(1, 0);
}

void Tetromino::moveLeft() {
  moveCurrentLocation(0, -1);
}

void Tetromino::moveRight() {
  moveCurrentLocation(0, 1);
}

void Tetromino::rotateLeft() {
  orientation = (orientation - 1) % 4;
}

void Tetromino::rotateRight() {
  orientation = (orientation + 1) % 4;
}

int Tetromino::getOrientation() {
  return orientation;
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
