#include "s_tetromino.h"

const Color STetromino::color = Color::Green;

const Coordinate STetromino::orientation1[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, STetromino::color), Coordinate(0, 2, STetromino::color),
  Coordinate(1, 0, STetromino::color), Coordinate(1, 1, STetromino::color), Coordinate(1, 2, Color::Black)     ,
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, Color::Black)     , Coordinate(2, 2, Color::Black)
};

const Coordinate STetromino::orientation2[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, STetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, Color::Black)     , Coordinate(1, 1, STetromino::color), Coordinate(1, 2, STetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, Color::Black)     , Coordinate(2, 2, STetromino::color)
};

const Coordinate STetromino::orientation3[numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, Color::Black)     , Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, Color::Black)     , Coordinate(1, 1, STetromino::color), Coordinate(1, 2, STetromino::color),
  Coordinate(2, 0, STetromino::color), Coordinate(2, 1, STetromino::color), Coordinate(2, 2, Color::Black)
  };

const Coordinate STetromino::orientation4[numRows*numCols] = {
  Coordinate(0, 0, STetromino::color), Coordinate(0, 1, Color::Black)     , Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, STetromino::color), Coordinate(1, 1, STetromino::color), Coordinate(1, 2, Color::Black)     ,
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, STetromino::color), Coordinate(2, 2, Color::Black)
};

const Coordinate *STetromino::getCoordinateArray() {
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

const int STetromino::getNumRows() {
  return STetromino::numRows;
}

const int STetromino::getNumCols() {
  return STetromino::numCols;
}

void STetromino::rotateLeft() {
  switch (this->orientation) {
    case 1:
      this->orientation = 4;
    case 2:
      this->orientation = 1;
    case 3:
      this->orientation = 2;
    default:
      this->orientation = 3;
  }
}

void STetromino::rotateRight() {
  switch (this->orientation) {
    case 1:
      this->orientation = 2;
    case 2:
      this->orientation = 3;
    case 3:
      this->orientation = 4;
    default:
      this->orientation = 1;
  }
}