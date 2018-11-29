#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "line.h"

class Board {
 public:
  Board();
 private:
  static const int numRows = 22;

  Line lines[numRows];
};

#endif
