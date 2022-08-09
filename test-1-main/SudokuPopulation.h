#pragma once
#include "Population.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffspring.h"


//Compares two Puzzle's by their fitness value and return bool value
struct compare {
  bool operator()(Puzzle* a, Puzzle* b) {
    Fitness* fit;
    return fit->howFit(*a) < fit->howFit(*b);
  }
};

//Sudoku Population is a derived from the population class,
class SudokuPopulation : public Population {
private:
  SudokuFitness fitness;
  SudokuFactory factory;
  SudokuOffspring reproduction; 


  int popSize;

  // min heap of priority queue
  priority_queue<Puzzle*, vector<Puzzle*>, compare> members;
public:
  SudokuPopulation(int population, Sudoku* sudoku);

  priority_queue<Puzzle*, vector<Puzzle*>, compare> getMembers();

  SudokuFitness getFitness();
  SudokuFactory getFactory();
  SudokuOffspring getReproduction();
  

  void cull(int) override;
  void newGeneration() override;
  int bestFitness() override;
  Puzzle *bestIndividual() override;
};