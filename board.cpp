#include "board.h"

Board::Board() {
  for (int row = 0; row < numRows; row++) {
    lines[row] = Line(row);
  }
}
