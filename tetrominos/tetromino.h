#ifndef TETROMINO_H
#define TETROMINO_H

#include "color.h"
#include "coordinate.h"

class Tetromino {
 public:
  virtual const Coordinate *getCoordinateArray() = 0;

 protected:
  int orientation;


 private:


};

#endif
