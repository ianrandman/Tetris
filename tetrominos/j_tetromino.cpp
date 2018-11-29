#include "j_tetromino.h"

const Color JTetromino::color = Color::Blue;

const int numRows = 3;
const int numCols = 3;

const Coordinate JTetromino::orientation1[numRows][numCols] = {
  {Coordinate(0, 0, color),        Coordinate(0, 1, Color::Black), Coordinate(0, 2, Color::Black)},
  {Coordinate(1, 0, color),        Coordinate(1, 1, color),        Coordinate(1, 2, color)       },
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, Color::Black), Coordinate(2, 2, Color::Black)}
};

const Coordinate JTetromino::orientation2[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, color),        Coordinate(0, 2, color)       },
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, color),        Coordinate(1, 2, Color::Black)},
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, color),        Coordinate(2, 2, Color::Black)}
};

const Coordinate JTetromino::orientation3[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, Color::Black), Coordinate(0, 2, Color::Black)},
  {Coordinate(1, 0, color),        Coordinate(1, 1, color),        Coordinate(1, 2, color)       },
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, Color::Black), Coordinate(2, 2, color)       }
};

const Coordinate JTetromino::orientation4[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, color),        Coordinate(0, 2, Color::Black)},
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, color),        Coordinate(1, 2, Color::Black)},
  {Coordinate(2, 0, color),        Coordinate(2, 1, color),        Coordinate(2, 2, Color::Black)}
};

const **Coordinate JTetromino::getCoordinateArray() {
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
}
