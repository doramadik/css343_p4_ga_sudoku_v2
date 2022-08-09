#include "SudokuPopulation.h"


// generates number of sudoku from population size.
SudokuPopulation::SudokuPopulation(int population, Sudoku *sudoku) {
  popSize = population;

  // Generates sudokus by calling the create puzzle
  for (int i = 0; i < popSize; i++) {
    Puzzle *newSudoku = factory.createPuzzle(*sudoku);
    //stores Sudokus in priority queue
    members.push(newSudoku);
  }
}

// gets fitness value
SudokuFitness SudokuPopulation::getFitness() { return fitness; }

// gets factory
SudokuFactory SudokuPopulation::getFactory() { return factory; }

// getter for reproduction
SudokuOffspring SudokuPopulation::getReproduction() { return reproduction; }

// getter for prioity queue
priority_queue<Puzzle*, vector<Puzzle*>, compare> SudokuPopulation::getMembers() {
  return members;
}

// Removes the Sudokus from prioity queue based on Cull percent.
void SudokuPopulation::cull(int x) {
  priority_queue<Puzzle*, vector<Puzzle*>, compare> temp;

  int keepCount = 100 - x;

  // 
  for (int i = 0; i < keepCount; i++) {
    temp.push(members.top());
    members.pop();
  }
  members = temp;
}


// creating new Sudokus  
void SudokuPopulation::newGeneration() {
  priority_queue<Puzzle*, vector<Puzzle*>, compare> temp = members;

  Puzzle *curSudoku;
  int toFill = popSize - members.size();
  int offspringCount = toFill / members.size();

  for (int i = 0; i < toFill; i += 10) {
    for (int i = 0; i < offspringCount; i++) {
      members.push(reproduction.makeOffspring(*temp.top()));
      temp.pop();
    }
  }
}

// gives the best fitness value from the priortiy queue.
int SudokuPopulation::bestFitness() { return fitness.howFit(*members.top()); }

// gives the best Suduko from the priortiy queue
Puzzle* SudokuPopulation::bestIndividual() {
  return members.top(); 
}
