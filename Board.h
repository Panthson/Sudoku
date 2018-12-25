#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Board{
public:
  Board(int);
  void printBoard();
  void setCoord(int, int, int);
private:
  int size;
  vector<vector<int>*> *grid;

  void printUnderline();
};
