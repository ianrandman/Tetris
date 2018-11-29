#ifndef TETRIS_LINE_H
#define TETRIS_LINE_H

#include "tetrominos/coordinate.h"

class Line {
 public:
  Line();
  Line(int rowNum);
 private:
  static const int numSpaces = 10;

  int rowNum;
  Coordinate spaces[numSpaces];
};

#endif
