#include "coordinate.h"

Coordinate::Coordinate() {}

Coordinate::Coordinate(int row, int col, Color color = Color::Black) : row(row), col(col), color(color) {
  this->occupied = false;
}