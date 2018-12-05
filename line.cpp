#include "line.h"
#include "tetrominos/color.h"
#include <iostream>

using namespace std;

Line::Line() {}

Line::Line(int rowNum) : rowNum(rowNum) {
  for (int col = 0; col < numSpaces; col++) {
    spaces[col] = Coordinate(rowNum, col, Color::Black);
  }
}

bool Line::isOccupiedAt(int col) {
//  cout << "row: " << rowNum << endl;
//  cout << "col: " << col << endl;
//  cout << "occupied: " << spaces[col].isOccupied() << endl;

  return spaces[col].isOccupied();
}

void Line::setTetrominoLocation(Tetromino *tetromino, int col) {
  tetromino->setCurrentLocation(spaces[col]);
}

void Line::setOccupied(Color color, int col) {
  spaces[col].setColor(color);
  spaces[col].setOccupied();
}

void Line::showSpaces(Canvas *panel) {
  for (int col = 0; col < Line::numSpaces; col++) {
    Color color = spaces[col].getColor();
    panel->SetPixel(col, rowNum, color.getRed(), color.getGreen(), color.getBlue());
  }
}

void Line::printLine() {
  for (int col = 0; col < 10; col++) {
    Coordinate space = spaces[col];
    if (space.isOccupied()) {
      cout << "X";
    } else {
      cout << "O";
    }
  }
}
