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

void Tetromino::moveUp() {
  int currentRow = currentLocation.getRow();
  int currentCol = currentLocation.getCol();
  currentLocation = Coordinate(currentRow - 1, currentCol, Color::Black);
}

void Tetromino::moveDown() {
  int currentRow = currentLocation.getRow();
  int currentCol = currentLocation.getCol();
  currentLocation = Coordinate(currentRow + 1, currentCol, Color::Black);
}

void Tetromino::moveLeft() {
  int currentRow = currentLocation.getRow();
  int currentCol = currentLocation.getCol();
  currentLocation = Coordinate(currentRow, currentCol - 1, Color::Black);
}

void Tetromino::moveRight() {
  int currentRow = currentLocation.getRow();
  int currentCol = currentLocation.getCol();
  currentLocation = Coordinate(currentRow, currentCol + 1, Color::Black);
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
