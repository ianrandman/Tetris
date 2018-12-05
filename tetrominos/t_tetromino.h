#ifndef TTETROMINO_H
#define TTETROMINO_H

#include "tetromino.h"

class TTetromino : public Tetromino {
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