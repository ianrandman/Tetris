#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "tetromino.h"

class OTetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
  const int getNumRows();
  const int getNumCols();
  void rotateRight();
  void rotateLeft();
 private:
  static const Color color;

  static const int numRows = 3;
  static const int numCols = 4;

  static const Coordinate orientation1[numRows*numCols];
};

#endif