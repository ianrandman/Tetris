#include "coordinate.h"

Coordinate::Coordinate() {}

Coordinate::Coordinate(int row, int col, Color color = Color::Black) : row(row), col(col), color(color) {
  if (color == Color::Black) {
    this->occupied = false;
  } else {
    this->occupied = true;
  }
}

int Coordinate::getRow() {
  return row;
}

int Coordinate::getCol() {
  return col;
}

bool Coordinate::isOccupied() {
  return occupied;
}

void Coordinate::setOccupied() {
  occupied = true;
}

Color Coordinate::getColor() {
  return color;
}

void Coordinate::setColor(Color color) {
  this->color = color;
}

void Coordinate::setRow(int row) {
  this->row = row;
}