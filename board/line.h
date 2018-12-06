#ifndef TETRIS_LINE_H
#define TETRIS_LINE_H

#include "led-matrix.h"

#include "../tetrominos/coordinate.h"
#include "../tetrominos/tetromino.h"
#include "../tetrominos/color.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

class Line {
 public:
  Line();
  Line(int rowNum);

  static const int numSpaces = 10;

  bool isOccupiedAt(int col);
  void setTetrominoLocation(Tetromino *tetromino, int col);
  void setOccupied(Color color, int col);
  void showSpaces(Canvas *panel);
  void printLine();
 private:
  int rowNum;
  Coordinate spaces[numSpaces];
};

#endif
