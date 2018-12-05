#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "tetromino.h"

class OTetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
  const int getNumRows();
  const int getNumCols();
 private:
  static const Color color;

  static const int numRows = 4;
  static const int numCols = 3;

  static const Coordinate orientation1[numRows + numRows*numCols];
};

#endif