#include "Puzzle.h"

// operator out uses print to print out the puzzle.
void operator<<(ostream& output, Puzzle* puzzle) { 
  puzzle->print(output); 
  }

// operator >> reads the input of the Puzzle.
void operator>>(istream &input, Puzzle* puzzle) {
  string data;
  input >> data;
  puzzle->read(data);
}