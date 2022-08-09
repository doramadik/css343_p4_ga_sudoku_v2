#include "SudokuOffspring.h"
#include "Sudoku.h"
#include <ctime>
#include <random>


// sets the probability.
void SudokuOffspring::setProb(int prob) { probability = prob; }


// Makes new Sudoku, Copys from old sudoku and mutates Sudoku with rand value
Sudoku *SudokuOffspring::makeOffspring(Puzzle &sudoku) {
  Sudoku *newPuzzle = new Sudoku(sudoku.getData());
  // copy the old puzzle to new puzzle and mutating the value by using the
  // rand() value.
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (newPuzzle->getFixedValue(i, j) == false) {
        if (rand() % 100 < probability) {
          newPuzzle->setValue(i, j, (rand() % 9 + 1));
        }
      }
    }
  }
  return newPuzzle;
}