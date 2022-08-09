#pragma once
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

// SudokuFactory id derived from PuzzleFactory
class SudokuFactory : public PuzzleFactory{
  public:
    SudokuFactory();
    Sudoku* createPuzzle(Puzzle&) override;
};