#include "line.h"
#include "tetrominos/color.h"

Line::Line() {}

Line::Line(int rowNum) : rowNum(rowNum) {
  for (int col = 0; col < numSpaces; col++) {
    spaces[col] = Coordinate(rowNum, col, Color::Black);
  }
}

bool Line::isOccupiedAt(int col) {
  return spaces[col].isOccupied();
}

void Line::setTetrominoLocation(Tetromino *tetromino, int col) {
  tetromino->setCurrentLocation(spaces[col]);
}

void Line::setOccupied(Color color, int col) {
  spaces[col].setColor(color);
}

void Line::showSpaces(Canvas *panel) {
  for (int col = 0; col < Line::numSpaces; col++) {
    Color color = spaces[col].getColor();
    panel->SetPixel(col, rowNum, color.getRed(), color.getGreen(), color.getBlue());
  }
}