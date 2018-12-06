#ifndef TETRIS_TETROMINO_ROTATOR_H
#define TETRIS_TETROMINO_ROTATOR_H

#include "board.h"
#include "line.h"

#include "tetrominos/tetromino.h"
#include "tetrominos/i_tetromino.h"
#include "tetrominos/j_tetromino.h"
#include "tetrominos/l_tetromino.h"
#include "tetrominos/o_tetromino.h"
#include "tetrominos/s_tetromino.h"
#include "tetrominos/t_tetromino.h"
#include "tetrominos/z_tetromino.h"
#include "tetrominos/color.h"
#include "tetrominos/coordinate.h"

class TetrominoRotator {
 public:
  TetrominoRotator(Board *board);

  void attemptRotate(Tetromino *tetromino);

 private:
  Board *board;
};

#endif