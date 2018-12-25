#include <iostream>
#include "Board.h"

using namespace std;

int main(){
  Board *board = new Board(9);

  while(true){
    char row;
    int col, value;
    cin >> row >> col >> value;
    cout << row << endl;
    board->setCoord(row - 97, col, value);
    board->printBoard();
  }

  //Play Game

  //Confirm
}
