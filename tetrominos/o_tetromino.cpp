#include "o_tetromino.h"

const Color OTetromino::color = Color::Yellow;

const int numRows = 3;
const int numCols = 4;

const Coordinate OTetromino::orientation1[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, color),        Coordinate(0, 2, color),        Coordinate(0, 3, Color::Black)},
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, color),        Coordinate(1, 2, color),        Coordinate(1, 3, Color::Black)},
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, Color::Black), Coordinate(2, 2, Color::Black), Coordinate(2, 3, Color::Black)}
};

const **Coordinate OTetromino::getCoordinateArray() {
  return orientation1;
  }
}