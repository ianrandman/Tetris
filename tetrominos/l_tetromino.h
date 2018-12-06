#ifndef LTETROMINO_H
#define LTETROMINO_H

#include "tetromino.h"

class LTetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
  const int getNumRows();
  const int getNumCols();
  void rotateRight();
  void rotateLeft();
 private:
  static const Color color;

  static const int numRows = 3;
  static const int numCols = 3;

  static const Coordinate orientation1[numRows*numCols];
  static const Coordinate orientation2[numRows*numCols];
  static const Coordinate orientation3[numRows*numCols];
  static const Coordinate orientation4[numRows*numCols];
};

#endif