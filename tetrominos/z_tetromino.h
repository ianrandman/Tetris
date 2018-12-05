#ifndef ZTETROMINO_H
#define ZTETROMINO_H

#include "tetromino.h"

class ZTetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
 private:
  static const Color color;

  static constexpr int numRows = 3;
  static constexpr int numCols = 3;

  static const Coordinate orientation1[numRows + numRows*numCols];
  static const Coordinate orientation2[numRows + numRows*numCols];
  static const Coordinate orientation3[numRows + numRows*numCols];
  static const Coordinate orientation4[numRows + numRows*numCols];
};

#endif