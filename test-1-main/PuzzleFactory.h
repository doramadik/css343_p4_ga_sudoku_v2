#include "Reproduction.h"
#pragma once

class PuzzleFactory{
  protected:
    Reproduction* rep;
  public:
    virtual ~PuzzleFactory(){};

    virtual Puzzle* createPuzzle(Puzzle&) = 0;
};