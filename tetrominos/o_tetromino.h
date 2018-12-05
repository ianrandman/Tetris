#ifndef OTETROMINO_H
#define OTETROMINO_H

#include "tetromino.h"

class OTetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
 private:
  static const Color color;

  static constexpr int numRows = 4;
  static constexpr int numCols = 3;

  static const Coordinate orientation1[numRows + numRows*numCols];
};

#endif