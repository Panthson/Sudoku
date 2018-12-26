#include "Board.h"

//Constructor to create the Sudoku game board
Board::Board(int size){
  this->size = size;

  this->grid = new vector<vector<int>*>(size);
  for(int i = 0; i < size; i++){
    this->grid->at(i) = new vector<int>(size, 0);
  }

  this->fillBoard();
  this->validateBoard();
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

  for(int num = 1; num <= this->size; num++){
    //Columns and Row Sections
    for(int rowSection = 0; rowSection < this->size; rowSection += 3){
      for(int colSection = 0; colSection < this->size; colSection += 3){
        //For this section, find a valid spot for num
        int randomRowInSection = rand() % 3 + rowSection;
        int randomColInSection = rand() % 3 + colSection;
        while(!isValidRandomAssignment(randomRowInSection, randomColInSection, num)){
          //printBoard();
          randomRowInSection = rand() % 3 + rowSection;
          randomColInSection = rand() % 3 + colSection;

          if(!sectionIsPossible(rowSection, colSection, num)){
            //cout << "IMPOSSIBLE" << endl;
            this->erase(num);
            rowSection = colSection = 0;
          }
        }

        this->setCoord(randomRowInSection, randomColInSection, num);
      }
    }
  }
}

void Board::erase(int val){
  for(int row = 0; row < this->grid->size(); row++){
    for(int col = 0; col < this->grid->at(row)->size(); col++){
      if(this->grid->at(row)->at(col) == val)
        this->grid->at(row)->at(col) = 0;
    }
  }
}

bool Board::sectionIsPossible(int rowSection, int colSection, int num){
  //cout << "Checking Section: " << rowSection << ", " << colSection << " " << num << endl;
  for(int row = rowSection; row < rowSection + sqrt(this->size); row++){
    for(int col = colSection; col < colSection + sqrt(this->size); col++){
      if(isValidRandomAssignment(row, col, num))
        return true;
    }
  }
  return false;
}

bool Board::validateBoard(){
  //Loop through entire grid
  for(int row = 0; row < this->grid->size(); row++){
    for(int col = 0; col < this->grid->at(row)->size(); col++){
      int val = this->grid->at(row)->at(col);
      //zero check
      if(val == 0)
        continue;
      //Loop through row
      for(int rowCheck = 0; rowCheck < this->grid->size(); rowCheck++){
        if(this->grid->at(rowCheck)->at(col) == val && rowCheck != row){
          return false;
        }
      }
      //Loop through column
      for(int rowCheck = 0; rowCheck < this->grid->size(); rowCheck++){
        if(this->grid->at(rowCheck)->at(col) == val && rowCheck != row){
          return false;
        }
      }
    }
  }
  cout << "Valid board" << endl;
  return true;
}

bool Board::isValidRandomAssignment(int row, int col, int num){
  if(this->grid->at(row)->at(col) != 0){
    return false;
  }

  for(int i = 0; i < this->size; i++){
    if(this->grid->at(row)->at(i) == num)
      return false;
  }

  for(int i = 0; i < this->size; i++){
    if(this->grid->at(i)->at(col) == num)
      return false;
  }

  return true;
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
