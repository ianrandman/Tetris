#include "t_tetromino.h"

const Color TTetromino::color = Color::Purple;

const Coordinate TTetromino::orientation1[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, TTetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, TTetromino::color), Coordinate(1, 1, TTetromino::color), Coordinate(1, 2, TTetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, Color::Black)     , Coordinate(2, 2, Color::Black)
};

const Coordinate TTetromino::orientation2[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, TTetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, Color::Black)     , Coordinate(1, 1, TTetromino::color), Coordinate(1, 2, TTetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, TTetromino::color), Coordinate(2, 2, Color::Black)
};

const Coordinate TTetromino::orientation3[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, Color::Black)     , Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, TTetromino::color), Coordinate(1, 1, TTetromino::color), Coordinate(1, 2, TTetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, TTetromino::color), Coordinate(2, 2, Color::Black)
};

const Coordinate TTetromino::orientation4[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, TTetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, TTetromino::color), Coordinate(1, 1, TTetromino::color), Coordinate(1, 2, Color::Black)     ,
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, TTetromino::color), Coordinate(2, 2, Color::Black)
};

const Coordinate *TTetromino::getCoordinateArray() {
  switch (this->orientation) {
    case 1:
      return orientation1;
    case 2:
      return orientation2;
    case 3:
      return orientation3;
    default:
      return orientation4;
  }
}

const int TTetromino::getNumRows() {
  return TTetromino::numRows;
}

const int TTetromino::getNumCols() {
  return TTetromino::numCols;
}
