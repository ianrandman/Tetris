#include "board.h"

Board::Board() {
  for (int row = 0; row < numRows; row++) {
    lines[row] = Line(row);
  }
}

void Board::spawnTetromino(Tetromino *tetromino) {
  lines[2].setTetrominoLocation(tetromino, 3);
}

bool Board::isCollision(Tetromino *tetromino) {
  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
  int currentRow = currentTetrominoLocation.getRow();
  int currentCol = currentTetrominoLocation.getCol();

  int numTetrominoRows = tetromino->getNumRows();
  int numTetrominoCols = tetromino->getNumCols();

  const Coordinate *tetrominoCoordinateArray = tetromino->getCoordinateArray();

  for (int row = 0; row < numTetrominoRows; row++) {
    for (int col = 0; col < numTetrominoCols; col++) {
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[row + row*col];
      if (tetrominoCoordinate.isOccupied() &&
            (lines[currentRow + row].isOccupiedAt(currentCol + col) ||
            tetrominoCoordinate.getCol() < 0 || tetrominoCoordinate.getCol() > Line::numSpaces ||
            tetrominoCoordinate.getRow() > Board::numRows)) {
        return false;
      }
    }
  }

  return true;
}

bool Board::moveTetrominoDown(Tetromino *tetromino) {
  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
  int currentRow = currentTetrominoLocation.getRow();
  int currentCol = currentTetrominoLocation.getCol();

  lines[currentRow + 1].setTetrominoLocation(tetromino, currentCol);

  if (isCollision(tetromino)) {
    lines[currentRow].setTetrominoLocation(tetromino, currentCol);
    solidifyTetromino(tetromino);
    return false;
  }

  return true;
}

void Board::solidifyTetromino(Tetromino *tetromino) {
  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
  int currentRow = currentTetrominoLocation.getRow();
  int currentCol = currentTetrominoLocation.getCol();

  int numTetrominoRows = tetromino->getNumRows();
  int numTetrominoCols = tetromino->getNumCols();

  const Coordinate *tetrominoCoordinateArray = tetromino->getCoordinateArray();

  for (int row = 0; row < numTetrominoRows; row++) {
    for (int col = 0; col < numTetrominoCols; col++) {
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[row + row*col];
      if (tetrominoCoordinate.isOccupied()) {
        lines[currentRow + row].setOccupied(tetrominoCoordinate.getColor(), currentCol + col);
      }
    }
  }

  delete tetromino;
}

void Board::showBoard(Tetromino *tetromino, Canvas *panel) {
  panel->Fill(0, 0, 0);

  for (int row = 2; row < Board::numRows; row++) {
    lines[row].showSpaces(panel);
  }

  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
  int currentRow = currentTetrominoLocation.getRow();
  int currentCol = currentTetrominoLocation.getCol();

  int numTetrominoRows = tetromino->getNumRows();
  int numTetrominoCols = tetromino->getNumCols();

  const Coordinate *tetrominoCoordinateArray = tetromino->getCoordinateArray();

  for (int row = 0; row < numTetrominoRows; row++) {
    for (int col = 0; col < numTetrominoCols; col++) {
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[row + row*col];
      if (tetrominoCoordinate.isOccupied()) {
        Color color = tetrominoCoordinate.getColor();
        panel->SetPixel(currentCol + col, currentRow + row, color.getRed(), color.getBlue(), color.getGreen());
      }
    }
  }
}