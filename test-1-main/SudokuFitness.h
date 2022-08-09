#pragma once
#include "Fitness.h"
#include "Sudoku.h"

#include <algorithm>
#include <vector>

using namespace std;

// SudokuFitness derived from fitness 
class SudokuFitness : public Fitness {
public:
// find the fitness value
  int howFit(Puzzle &puzzle) override;
};