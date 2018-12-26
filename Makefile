default: *.cpp *.h
	g++ --std=c++11 *.cpp *.h -o Sudoku

run: *.cpp *.h
	g++ --std=c++11 *.cpp *.h -o Sudoku
	./Sudoku
