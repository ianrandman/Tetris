#include "tetromino_rotator.h"

#include <iostream>
#include <typeinfo>

using namespace std;

TetrominoRotator::TetrominoRotator(Board *board) : board(board) {}

bool TetrominoRotator::attemptRotate(Tetromino *tetromino) {
  if (typeid(*tetromino) == typeid(OTetromino)) {
  } else if (typeid(*tetromino) == typeid(ITetromino)) {
    tetromino->rotateRight();

    switch (tetromino->getOrientation()) {
      case 1:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, -2);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(0, 3);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(1, -3);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(-3, 3);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(2, -1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 2:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, -1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(0, 3);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(-2, -3);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(3, 3);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(-1, -2);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 3:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, 2);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(0, -3);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(-1, 3);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(3, -3);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(-2, 1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 4:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, 1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(0, -3);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(2, 3);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(-3, -3);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(1, 2);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;
    }
  } else {
    tetromino->rotateRight();

    switch (tetromino->getOrientation()) {
      case 1:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, -1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(-1, 0);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(3, 1);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(0, -1);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(-2, 1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 2:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, 1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(1, 0);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(-3, -1);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(0, 1);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(2, -1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 3:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, 1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(-1, 0);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(3, -1);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(0, 1);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(-2, -1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;

      case 4:
        if (board->isCollision(tetromino )) {
          tetromino->moveCurrentLocation(0, -1);
          if (board->isCollision(tetromino )) {
            tetromino->moveCurrentLocation(1, 0);
            if (board->isCollision(tetromino )) {
              tetromino->moveCurrentLocation(-3, 1);
              if (board->isCollision(tetromino )) {
                tetromino->moveCurrentLocation(0, -1);
                if (board->isCollision(tetromino )) {
                  tetromino->moveCurrentLocation(+2, 1);
                  tetromino->rotateLeft();
                  return false;
                }
              }
            }
          }
        }
        break;
    }
  }

  return true;
}