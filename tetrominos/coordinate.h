#ifndef TETRIS_COORDINATE_H
#define TETRIS_COORDINATE_H

#include "color.h"

class Coordinate {
 public:
  Coordinate();
  Coordinate(int row, int col, Color color);
 private:
  int row, col;
  bool occupied;
  Color color;
};

#endif