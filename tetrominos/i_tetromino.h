#ifndef ITETROMINO_H
#define ITETROMINO_H

#include "tetromino.h"

class ITetromino : public Tetromino {
 public:
  const Coordinate *getCoordinateArray();
 private:
  static const Color color;

  static constexpr int numRows = 4;
  static constexpr int numCols = 4;

  static const Coordinate orientation1[numRows + numRows*numCols];
  static const Coordinate orientation2[numRows + numRows*numCols];
  static const Coordinate orientation3[numRows + numRows*numCols];
  static const Coordinate orientation4[numRows + numRows*numCols];
};

#endif
