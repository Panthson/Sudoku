#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

class Board{
public:
  Board(int);
  ~Board();
  void printBoard();
  void setCoord(int, int, int);
  void setCoord(char, int, int);
  void checkBoard();
private:
  int size;
  vector<vector<int>*> *grid;
  void fillBoard();
  void printUnderline();
};
