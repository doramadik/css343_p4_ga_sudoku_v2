#pragma once
#include "Reproduction.h"
#include "Sudoku.h"


// SudokuOffSpring is dervied from the Reproduction
class SudokuOffspring : public Reproduction {
private:
  bool valueChange[9][9];
  void checkFixed(Sudoku &);
  int probability = 100;

public:
  Sudoku *makeOffspring(Puzzle&) override;
  void setProb(int);
};