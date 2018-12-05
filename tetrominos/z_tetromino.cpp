#include "z_tetromino.h"

const Color ZTetromino::color = Color::Red;

const Coordinate ZTetromino::orientation1[numRows + numRows*numCols] = {
  Coordinate(0, 0, ZTetromino::color), Coordinate(0, 1, ZTetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, Color::Black)     , Coordinate(1, 1, ZTetromino::color), Coordinate(1, 2, ZTetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, Color::Black)     , Coordinate(2, 2, Color::Black)
};

const Coordinate ZTetromino::orientation2[numRows + numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, Color::Black)     , Coordinate(0, 2, ZTetromino::color),
  Coordinate(1, 0, Color::Black)     , Coordinate(1, 1, ZTetromino::color), Coordinate(1, 2, ZTetromino::color),
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, ZTetromino::color), Coordinate(2, 2, Color::Black)
};

const Coordinate ZTetromino::orientation3[numRows + numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, Color::Black)     , Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, ZTetromino::color), Coordinate(1, 1, ZTetromino::color), Coordinate(1, 2, Color::Black)     ,
  Coordinate(2, 0, Color::Black)     , Coordinate(2, 1, ZTetromino::color), Coordinate(2, 2, ZTetromino::color)
};

const Coordinate ZTetromino::orientation4[numRows + numRows*numCols] = {
  Coordinate(0, 0, Color::Black)     , Coordinate(0, 1, ZTetromino::color), Coordinate(0, 2, Color::Black)     ,
  Coordinate(1, 0, ZTetromino::color), Coordinate(1, 1, ZTetromino::color), Coordinate(1, 2, Color::Black)     ,
  Coordinate(2, 0, ZTetromino::color), Coordinate(2, 1, Color::Black)     , Coordinate(2, 2, Color::Black)
};

const Coordinate *ZTetromino::getCoordinateArray() {
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