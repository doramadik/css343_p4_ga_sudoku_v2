#include "SudokuFitness.h"

// checks the fitness value of the puzzle
int SudokuFitness::howFit(Puzzle &puzzle) {
  Sudoku sudoku = dynamic_cast<const Sudoku &>(puzzle);

  return sudoku.getFitness();
}
