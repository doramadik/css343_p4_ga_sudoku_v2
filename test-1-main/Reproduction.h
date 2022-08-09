#include "Puzzle.h"
#pragma once

class Reproduction{
  public:
    virtual ~Reproduction(){};
    virtual Puzzle* makeOffspring( Puzzle&) = 0;
}; 