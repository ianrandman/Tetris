#include "i_tetromino.h"

const Color ITetromino::color = Color::Cyan;

const int numRows = 4;
const int numCols = 4;

const Coordinate ITetromino::orientation1[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, Color::Black), Coordinate(0, 2, Color::Black), Coordinate(0, 3, Color::Black)},
  {Coordinate(1, 0, color),        Coordinate(1, 1, color),        Coordinate(1, 2, color),        Coordinate(1, 3, color)       },
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, Color::Black), Coordinate(2, 2, Color::Black), Coordinate(2, 3, Color::Black)},
  {Coordinate(3, 0, Color::Black), Coordinate(3, 1, Color::Black), Coordinate(3, 2, Color::Black), Coordinate(3, 3, Color::Black)}
};

const Coordinate ITetromino::orientation2[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, Color::Black), Coordinate(0, 2, color), Coordinate(0, 3, Color::Black)},
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, Color::Black), Coordinate(1, 2, color), Coordinate(1, 3, Color::Black)},
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, Color::Black), Coordinate(2, 2, color), Coordinate(2, 3, Color::Black)},
  {Coordinate(3, 0, Color::Black), Coordinate(3, 1, Color::Black), Coordinate(3, 2, color), Coordinate(3, 3, Color::Black)}
};

const Coordinate ITetromino::orientation3[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, Color::Black), Coordinate(0, 2, Color::Black), Coordinate(0, 3, Color::Black)},
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, Color::Black), Coordinate(1, 2, Color::Black), Coordinate(1, 3, Color::Black)},
  {Coordinate(2, 0, color),        Coordinate(2, 1, color),        Coordinate(2, 2, color),        Coordinate(2, 3, color)       },
  {Coordinate(3, 0, Color::Black), Coordinate(3, 1, Color::Black), Coordinate(3, 2, Color::Black), Coordinate(3, 3, Color::Black)}
};

const Coordinate ITetromino::orientation4[numRows][numCols] = {
  {Coordinate(0, 0, Color::Black), Coordinate(0, 1, color), Coordinate(0, 2, Color::Black), Coordinate(0, 3, Color::Black)},
  {Coordinate(1, 0, Color::Black), Coordinate(1, 1, color), Coordinate(1, 2, Color::Black), Coordinate(1, 3, Color::Black}),
  {Coordinate(2, 0, Color::Black), Coordinate(2, 1, color), Coordinate(2, 2, Color::Black), Coordinate(2, 3, Color::Black)},
  {Coordinate(3, 0, Color::Black), Coordinate(3, 1, color), Coordinate(3, 2, Color::Black), Coordinate(3, 3, Color::Black)}
};

const **Coordinate ITetromino::getCoordinateArray() {
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
