#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "tetromino.h"

class OTetromino : public Tetromino {
 public:
 private:
  static const Color color;

  static const int numRows;
  static const int numCols;

  static const Coordinate orientation1[numRows][numCols];
};

#endif