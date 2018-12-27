#include <iostream>
#include "Board.h"

using namespace std;

int main(){
  Board *board = new Board(9);
  while(true){
    //Read input
    char row;
    int col, value;
    cin >> row >> col >> value;
    board->setCoord(row - 97, col, value);
    board->printBoard();
    board->isValidBoard();

    if(board->gameWon()){
      cout << "You Won!!!" << endl;
      return 1;
    }
  }
}
