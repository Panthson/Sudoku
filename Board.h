#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <utility>

using namespace std;

class Board{
public:
  Board(int);
  ~Board();
  void printBoard();
  void setCoord(int, int, int);
  void setCoord(char, int, int);
  bool validateBoard();
private:
  int size;
  vector<vector<int>*> *grid;

  void fillBoard();
  bool sectionIsPossible(int, int, int);
  void erase(int);
  bool isValidRandomAssignment(int, int, int);
  void printUnderline();
};
