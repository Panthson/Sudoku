#include "Board.h"

//Constructor to create the Sudoku game board
Board::Board(int size){
  this->size = size;

  this->grid = new vector<vector<int>*>(size);
  for(int i = 0; i < size; i++){
    this->grid->at(i) = new vector<int>(size, 0);
  }

  this->fillBoard();

  this->printBoard();
}

Board::~Board(){
  for(int i = 0; i < size; i++){
    delete this->grid->at(i);
  }

  delete this->grid;
}

void Board::fillBoard(){
  srand(time(NULL));
  //numbers 1 ... 9?
  for(int num = 1; num <= this->size; num++){
    //Columns and Row Sections
    for(int rowSection = 0; rowSection < this->size; rowSection += 3){
      for(int colSection = 0; colSection < this->size; colSection += 3){
        //For this section, find a valid spot for num
        int randomRowInSection = rand() % 3 + rowSection;
        int randomColInSection = rand() % 3 + colSection;
        while(isInvalidRandomAssignment(randomRowInSection, randomColInSection, num)){
          randomRowInSection = rand() % 3 + rowSection;
          randomColInSection = rand() % 3 + colSection;
        }

        this->setCoord(randomRowInSection, randomColInSection, num);
      }
    }
  }

}

void Board::checkBoard(){
  cout << "Checking board coming soon..." << endl;
}

bool Board::isInvalidRandomAssignment(int row, int col, int num){
  if(this->grid->at(row)->at(col) != 0){
    cout << num << " HIT NON ZERO" << endl;
    return true;
  }

  for(int i = 0; i < this->size; i++){
    if(this->grid->at(row)->at(i) == num)
      return true;
  }

  for(int i = 0; i < this->size; i++){
    if(this->grid->at(i)->at(col) == num)
      return true;
  }

  return false;
}

void Board::printBoard(){
  system("clear");
  cout << "Welcome to Sudoku!" << endl << endl;
  //print column coordinates
  cout << " ";
  for(int i = 0; i < this->grid->size(); i++){
    if(i % 3 == 0)
      cout << "  ";
    cout << " " << i;
  }
  cout << endl;

  //Print grid
  for(int i = 0; i < this->grid->size(); i++){
    if(i % 3 == 0){
      printUnderline();
    }
    //Print row coordinates
    cout << (char)(i + 97) << " ";

    for(int j = 0; j < this->grid->at(i)->size(); j++){
      //Print box dividers
      if(j % 3 == 0)
        cout << "| ";
      //Print numbers
      cout << this->grid->at(i)->at(j) << " ";
    }
    cout << "|" << endl;
  }

  printUnderline();

  cout << endl << "Please insert input as \"ROW [SPACE] COLUMN [SPACE] VALUE\"" << endl;
  cout << "To quit, press CTRL + C" << endl;
}

void Board::printUnderline(){
  for(int i = 0; i < this->grid->size(); i++){
    cout << "---";
  }
  cout << endl;
}

void Board::setCoord(int row, int col, int value){
  this->grid->at(row)->at(col) = value;
}

void Board::setCoord(char row, int col, int value){
  this->setCoord((int)(row - 97), col, value);
}
