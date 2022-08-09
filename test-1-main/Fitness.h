#pragma once

#include "Puzzle.h"

class Fitness {
public:
  virtual ~Fitness(){};
  virtual int howFit(Puzzle &puzzle) = 0;
};