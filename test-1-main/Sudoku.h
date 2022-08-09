#pragma once
#include "Puzzle.h"
#include <algorithm>
#include <vector>
using namespace std;


//Sudoku is dervied from Puzzle
class Sudoku : public Puzzle {
private:
  int grid[9][9];
  bool fixedValue[9][9];
public:
  Sudoku(){};
  Sudoku(string);
  ~Sudoku(){};

  bool getFixedValue(int, int);
  int getValue(int, int);
  void setValue(int, int, int);

  void read(string) override;
  ostream &print(ostream&) override;

  void findFitness() override;
  int getFitness();
};