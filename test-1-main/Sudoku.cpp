#include "Sudoku.h"
#include <random>

// Reads through the string the fills the grid.
Sudoku::Sudoku(string input) {
  read(input);
  
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = getValue(i, j);
      //checks if they are zeros in the string and sets the array of fixedValue to false
      fixedValue[i][j] = (curVal != 0);
    }
  }
  findFitness();
}

// get the index position that needs to be changed.
bool Sudoku::getFixedValue(int x, int y) { return fixedValue[x][y]; }

// gets the value from the grid.
int Sudoku::getValue(int x, int y) { return grid[x][y]; }
//sets the value in the grid
void Sudoku::setValue(int x, int y, int value) { grid[x][y] = value; }

// read through the string and fills in the array of grid
void Sudoku::read(string sudokuNums) {
  data = sudokuNums;
  int x = 0;
  int y = 0;

  for (char &c : sudokuNums) {
    if (x > 8) {
      y++;
      x = 0;
      if (y > 8) {
        break;
      }
    }
    if (isdigit(c)) {
      grid[y][x] = c - '0';
      x++;
    }
  }
}

// prints out the Sudoku in format
ostream &Sudoku::print(ostream &output) {
  string format = "+-------+-------+-------+\n";
  output << format;
  for (int i = 0; i < 9; i++) {
    output << '|';
    for (int j = 0; j < 9; j++) {
      output << " " << grid[i][j];
      if (j % 3 == 2) {
        output << " " << '|';
      }
    }
    if (i % 3 == 2) {
      output << '\n' << format;
    } else {
      output << '\n';
    }
  }
  return output;
}

void Sudoku::findFitness() {
  vector<int> existValues;

  // Check each row for conflicts
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = getValue(i, j);
      if (find(begin(existValues), end(existValues), curVal) ==
              end(existValues) &&
          curVal != 0) {
        existValues.push_back(curVal);
      } else {
        fitness++;
      }
    }
    existValues.clear();
  }

  //Check each column for conflicts
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int curVal = getValue(j, i);
      if (find(begin(existValues), end(existValues), curVal) ==
          end(existValues)) {
        existValues.push_back(curVal);
      } else {
        fitness++;
      }
    }
    existValues.clear();
  }
  
  // Check each 3x3 block for conflicts
  for (int row = 0; row < 9; row += 3) {
    for (int col = 0; col < 9; col += 3) {
      for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
          int curVal = getValue(i, j);
          if (find(begin(existValues), end(existValues), curVal) ==
              end(existValues)) {
            existValues.push_back(curVal);
          } else {
            fitness++;
          }
        }
      }
      existValues.clear();
    }
  }
}

int Sudoku::getFitness() { return fitness; }