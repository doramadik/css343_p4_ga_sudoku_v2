#include "Fitness.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include <queue>
#include <vector>

#pragma once

class Population {
private:
  //Fitness pointer
  Fitness *fitness;
  //Puzzle Factory pointer
  PuzzleFactory *factory;
  //Reporduction pointer
  Reproduction *reproduction;

public:
  //population destructor
  virtual ~Population(){};
  // Virtual fuctions.
  virtual void cull(int) = 0;
  virtual void newGeneration() = 0;
  virtual int bestFitness() = 0;
  virtual Puzzle *bestIndividual() = 0;
};