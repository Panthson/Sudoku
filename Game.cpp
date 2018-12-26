#include <iostream>
#include "Board.h"

using namespace std;

int main(){
  Board *board = new Board(9);
  while(true){
    char row;
    int col, value;
    cin >> row >> col >> value;
    board->setCoord(row - 97, col, value);
    board->printBoard();
    board->validateBoard();
  }

  //Confirm
}
