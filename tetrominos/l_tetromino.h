#ifndef LTETROMINO_H
#define LTETROMINO_H

#include "tetromino.h"

class LTetromino : public Tetromino {
 public:
 private:
  static const Color color;

  static const int numRows;
  static const int numCols;

  static const Coordinate orientation1[numRows][numCols];
  static const Coordinate orientation2[numRows][numCols];
  static const Coordinate orientation3[numRows][numCols];
  static const Coordinate orientation4[numRows][numCols];
};

#endif