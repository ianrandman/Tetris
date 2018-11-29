#include "line.h"
#include "tetrominos/color.h"

Line::Line() {}

Line::Line(int rowNum) : rowNum(rowNum) {
  for (int col = 0; col < numSpaces; col++) {
    spaces[col] = Coordinate(rowNum, col, Color::Black);
  }
}
