
#include "led-matrix.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

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

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

static int lastTetromino = -1;

static void playGame(Canvas *panel, Board *board);
static Canvas *setUpPanel(int argc, char *argv[]);
static Tetromino *getNextTetromino();

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

//static void DrawOnCanvas(Canvas *canvas) {
//  /*
//   * Let's create a simple animation. We use the canvas to draw
//   * pixels. We wait between each step to have a slower animation.
//   */
//  canvas->Fill(0, 0, 255);
//
//  int center_x = canvas->width() / 2;
//  int center_y = canvas->height() / 2;
//  float radius_max = canvas->width() / 2;
//  float angle_step = 1.0 / 360;
//  for (float a = 0, r = 0; r < radius_max; a += angle_step, r += angle_step) {
//    if (interrupt_received)
//      return;
//    float dot_x = cos(a * 2 * M_PI) * r;
//    float dot_y = sin(a * 2 * M_PI) * r;
//    canvas->SetPixel(center_x + dot_x, center_y + dot_y,
//                     255, 0, 0);
//    usleep(1 * 1000);  // wait a little to slow down things.
//  }
//}

static Tetromino *getNextTetromino() {
  int num = rand() % 7;
  if (num == lastTetromino) {
    num = rand() % 7;
  }
  lastTetromino = num;

  switch (num) {
    case 0:
      return new ITetromino();
    case 1:
      return new JTetromino();
    case 2:
      return new LTetromino();
    case 3:
      return new OTetromino();
    case 4:
      return new STetromino();
    case 5:
      return new TTetromino();
    default:
      return new ZTetromino();
  }
}

static void playGame(Canvas *panel, Board *board) {
  while (true) {
    if (interrupt_received)
      return;
    Tetromino *tetromino = getNextTetromino();

    board->spawnTetromino(tetromino);
    board->showBoard(tetromino, panel);
    usleep(1000);
    while (board->moveTetrominoDown(tetromino)) {
      if (interrupt_received)
        return;
      board->showBoard(tetromino, panel);
      usleep(1000);
    }
  }
}

static Canvas *setUpPanel(int argc, char *argv[]) {
  RGBMatrix::Options defaults;
  defaults.hardware_mapping = "regular";  // or e.g. "adafruit-hat"
  defaults.rows = 32;
  defaults.chain_length = 1;
  defaults.parallel = 1;
  defaults.show_refresh_rate = true;
  Canvas *canvas = rgb_matrix::CreateMatrixFromFlags(&argc, &argv, &defaults);

  // It is always good to set up a signal handler to cleanly exit when we
  // receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
  // for that.
  signal(SIGTERM, InterruptHandler);
  signal(SIGINT, InterruptHandler);

  return canvas;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  Canvas *panel = setUpPanel(argc, argv);
  if (panel == NULL) {
    return 1;
  }

  Board *board = new Board();

  playGame(panel, board);    // Using the canvas.

  // Animation finished. Shut down the RGB matrix.
  panel->Clear();
  delete panel;
  delete board;

  return 0;
}