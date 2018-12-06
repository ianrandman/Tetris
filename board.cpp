#include "board.h"
#include <iostream>

using namespace std;

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
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[col + row*numTetrominoCols];
//      cout << "tetrominocoordinaterow: " << tetrominoCoordinate.getRow() << endl;
//      cout << "tetrominocoordinatecol: " << tetrominoCoordinate.getCol() << endl;
//      cout << "currentrow: " << currentRow << endl;
//      cout << "currentcol: " << currentCol << endl;

      if (tetrominoCoordinate.isOccupied() &&
            (lines[currentRow + row].isOccupiedAt(currentCol + col) ||
            tetrominoCoordinate.getCol() + currentCol < 0 || tetrominoCoordinate.getCol() + currentCol >= Line::numSpaces ||
            tetrominoCoordinate.getRow() + currentRow >= Board::numRows)) {
        return true;
      }
    }
  }

  return false;
}

bool Board::moveTetrominoDown(Tetromino *tetromino) {
//  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
//  int currentRow = currentTetrominoLocation.getRow();
//  int currentCol = currentTetrominoLocation.getCol();

//  lines[currentRow + 1].setTetrominoLocation(tetromino, currentCol);

  tetromino->moveDown();

  if (isCollision(tetromino)) {
    //lines[currentRow].setTetrominoLocation(tetromino, currentCol);
    tetromino->moveUp();
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
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[col + row*numTetrominoCols];
      if (tetrominoCoordinate.isOccupied()) {
        lines[currentRow + row].setOccupied(tetrominoCoordinate.getColor(), currentCol + col);
      }
    }
  }

  //delete tetromino;
}



void Board::moveTetrominoLeft(Tetromino *tetromino) {
  tetromino->moveLeft();

  if (isCollision(tetromino)) {
    //lines[currentRow].setTetrominoLocation(tetromino, currentCol);
    tetromino->moveRight();
  }
}

void Board::moveTetrominoRight(Tetromino *tetromino) {
  tetromino->moveRight();

  if (isCollision(tetromino)) {
    //lines[currentRow].setTetrominoLocation(tetromino, currentCol);
    tetromino->moveLeft();
  }
}





void Board::showBoard(Tetromino *tetromino, Canvas *panel) {
  panel->Fill(0, 0, 0);

  for (int col = 0; col < 11; col++) {
    panel->SetPixel(col, 1, 255, 255, 255);
  }

  for (int row = 2; row < Board::numRows; row++) {
    lines[row].showSpaces(panel);
    panel->SetPixel(10, row, 255, 255, 255);
  }

  Coordinate currentTetrominoLocation = tetromino->getCurrentLocation();
  int currentRow = currentTetrominoLocation.getRow();
  int currentCol = currentTetrominoLocation.getCol();

  int numTetrominoRows = tetromino->getNumRows();
  int numTetrominoCols = tetromino->getNumCols();

  const Coordinate *tetrominoCoordinateArray = tetromino->getCoordinateArray();

  for (int row = 0; row < numTetrominoRows; row++) {
    for (int col = 0; col < numTetrominoCols; col++) {
      Coordinate tetrominoCoordinate = tetrominoCoordinateArray[col + row*numTetrominoCols];
      if (tetrominoCoordinate.isOccupied()) {
        Color color = tetrominoCoordinate.getColor();
        panel->SetPixel(currentCol + col, currentRow + row, color.getRed(), color.getGreen(), color.getBlue());
      }
    }
  }

  for (int col = 0; col < 11; col++) {
    panel->SetPixel(col, 22, 255, 255, 255);
  }
}

void Board::printBoard() {
  cout << "The board starts here:" << endl;
  for (int row = 0; row < 22; row++) {
    lines[row].printLine();
    cout << endl;
  }

  cout << endl;
  cout << endl;
}
