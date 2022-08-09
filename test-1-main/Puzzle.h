#include <iostream>
#pragma once

using namespace std;

class Puzzle {
protected:
  string data;
  int fitness;

public:
  ~Puzzle(){};
// operating in
  friend void operator<<(ostream &, Puzzle *);
// operating out
  friend void operator>>(istream &, Puzzle *);

  string getData() const { return data; };

  virtual void read(string) = 0;
  virtual ostream &print(ostream &) = 0;

  virtual void findFitness() = 0;
};