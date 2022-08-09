#include "SudokuFactory.h"

// creates new SudokuOffspring
SudokuFactory::SudokuFactory() {
  rep = new SudokuOffspring();
}

// creating puzzles by calling makeOffspring
Sudoku* SudokuFactory::createPuzzle(Puzzle& puzzle) {
  Sudoku sudoku = dynamic_cast<Sudoku&>(puzzle);
  return dynamic_cast<Sudoku*>(rep->makeOffspring(sudoku));
}