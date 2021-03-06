#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "led-matrix.h"

#include "line.h"
#include "../tetrominos/tetromino.h"
#include "../tetrominos/coordinate.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

class Board {
 public:
  Board();
  void spawnTetromino(Tetromino *tetromino);
  bool moveTetrominoDown(Tetromino *tetromino);
  void moveTetrominoLeft(Tetromino *tetromino);
  void moveTetrominoRight(Tetromino *tetromino);
  void showBoard(Tetromino *tetromino, Canvas *panel);
  void printBoard();
 private:
  static const int numRows = 22;
  Line lines[numRows];

  bool isCollision(Tetromino *tetromino);
  void solidifyTetromino(Tetromino *tetromino);
};

#endif
