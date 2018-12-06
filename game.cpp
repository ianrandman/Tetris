
#include "led-matrix.h"
#include <wiringPi.h>

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

#include <iostream>
#include <thread>

using namespace std;

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

static int lastTetromino = -1;
static Tetromino *currentTetromino;

static void playGame(Canvas *panel, Board *board);
static Canvas *setUpPanel(int argc, char *argv[]);
static Tetromino *getNextTetromino();

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
  interrupt_received = true;
}

static Tetromino *getNextTetromino(int number) {
//  int num = rand() % 7;
//  if (num == lastTetromino) {
//    num = rand() % 7;
//  }
//  lastTetromino = num;

  int num = 4;

  switch (number) {
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

static void checkForMove(Canvas *panel, Board *board, Tetromino *tetromino) {
while (tetromino == currentTetromino) {
    if (digitalRead(28) == 0) {
      board->moveTetrominoLeft(tetromino);
      board->showBoard(tetromino, panel);
      usleep(150 * 1000);
    }

    while (digitalRead(28) == 0 && tetromino == currentTetromino) {
      if (digitalRead(29) == 0) {
        break;
      }

      board->moveTetrominoLeft(tetromino);
      board->showBoard(tetromino, panel);
      usleep(150 * 1000);
    }

    if (digitalRead(29) == 0) {
      board->moveTetrominoRight(tetromino);
      board->showBoard(tetromino, panel);
      usleep(150 * 1000);
    }

    while (digitalRead(29) == 0 && tetromino == currentTetromino) {
      if (digitalRead(28) == 0) {
        break;
      }

      board->moveTetrominoRight(tetromino);
      board->showBoard(tetromino, panel);
      usleep(62 * 1000);
    }
  }
}

static int moveLock = 0;
static void checkForMoveLeft(Canvas *panel, Board *board, Tetromino *tetromino) {
  bool canGrabMoveLock = true;

  while (tetromino == currentTetromino) {
    if (moveLock != 2 && canGrabMoveLock) {
      if (digitalRead(28) == 0) {

        moveLock = 1;
        canGrabMoveLock = false;


        board->moveTetrominoLeft(tetromino);
        board->showBoard(tetromino, panel);
        usleep(100 * 1000);
      }

      while (digitalRead(28) == 0 && moveLock != 2 && tetromino == currentTetromino) {
        board->moveTetrominoLeft(tetromino);
        board->showBoard(tetromino, panel);
        usleep(62 * 1000);
      }

      if (digitalRead(28) == 1) {
        moveLock = 0;
        canGrabMoveLock = true;
      }
    }
  }
}

static void checkForMoveRight(Canvas *panel, Board *board, Tetromino *tetromino) {
  bool canGrabMoveLock = true;

  while (tetromino == currentTetromino) {
    if (moveLock != 1 && canGrabMoveLock) {
      if (digitalRead(29) == 0) {

        moveLock = 2;
        canGrabMoveLock = false;


        board->moveTetrominoRight(tetromino);
        board->showBoard(tetromino, panel);
        usleep(100 * 1000);
      }

      while (digitalRead(29) == 0 && moveLock != 1 && tetromino == currentTetromino) {
        board->moveTetrominoRight(tetromino);
        board->showBoard(tetromino, panel);
        usleep(62 * 1000);
      }

      if (digitalRead(29) == 1) {
        moveLock = 0;
        canGrabMoveLock = true;
      }
    }
  }
}

static void playGame(Canvas *panel, Board *board) {
  //board->printBoard();

  for (int i = 0; i < 7; i++) {
    if (interrupt_received)
      return;
    currentTetromino = getNextTetromino(i);

    thread checkMove(checkForMove, panel, board, currentTetromino);
    checkMove.detach();

//    moveLock = 0;
//
//    thread checkMoveLeft(checkForMoveLeft, panel, board, currentTetromino);
//    checkMoveLeft.detach();
//
//    thread checkMoveRight(checkForMoveRight, panel, board, currentTetromino);
//    checkMoveRight.detach();

    //board->spawnTetromino(tetromino);
    board->showBoard(currentTetromino, panel);

    cout.flush();
    usleep(500 * 1000);
    while (board->moveTetrominoDown(currentTetromino)) {
      board->showBoard(currentTetromino, panel);
      cout.flush();
      usleep(500 * 1000);
    }

    board->showBoard(currentTetromino, panel);
  }

//  while (true) {
//    if (interrupt_received)
//      return;
//  }

//  board->printBoard();
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
  wiringPiSetup();
  pinMode(28, INPUT);
  pullUpDnControl(28, PUD_UP);
  pinMode(29, INPUT);
  pullUpDnControl(29, PUD_UP);

  srand(time(NULL));

  Canvas *panel = setUpPanel(argc, argv);
  if (panel == NULL) {
    return 1;
  }

  while (true) {
    Board *board = new Board();

    playGame(panel, board);    // Using the canvas.

    delete board;

    if (interrupt_received)
      break;
  }

  // Animation finished. Shut down the RGB matrix.
  panel->Clear();
  delete panel;
  //delete board;

  return 0;
}