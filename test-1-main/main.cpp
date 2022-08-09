//Name: Pavan Sai Ram Korumilli, Srikar Chava, Brain
//class: CSS 343
//Purpose: To randomly fill in the Suodku by using inheritance like Base class : dervied classes.

#include "GeneticAlgorithm.h"
#include "Puzzle.h"
#include "Sudoku.h"
#include <iostream>

int main(int argc, char *argv[]) {
     int populationSize = atoi(argv[1]);
     int maxGeneration = atoi(argv[2]);

  // calls the GenticAlgo class.
   GeneticAlgorithm(populationSize, maxGeneration);


  
  

}