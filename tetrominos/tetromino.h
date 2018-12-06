#ifndef TETROMINO_H
#define TETROMINO_H

#include "color.h"
#include "coordinate.h"

class Tetromino {
 public:
  Tetromino();

  virtual const Coordinate *getCoordinateArray() = 0;
  virtual const int getNumRows() = 0;
  virtual const int getNumCols() = 0;
  virtual void rotateRight() = 0;
  virtual void rotateLeft() = 0;

  Coordinate getCurrentLocation();
  void setCurrentLocation(Coordinate location);
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
 protected:
  int orientation;
  Coordinate currentLocation;


 private:


};

#endif
