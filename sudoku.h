#include <iostream>
#include <stdio.h>
#define LEN 9

class SudokuSolver{
    private:
    int grid[LEN][LEN];
//    int ** grid;
    bool hasEmptyCells(int& row, int& column);
    bool isInRow(int row, int num);
    bool isInColumn(int column, int num);
    bool isInBox(int row_start, int column_start, int num);
    bool isToUse(int row, int column, int num);

    public:
    SudokuSolver(){
    }
    bool solve(int array[LEN][LEN]);
    void printArray();
};
extern SudokuSolver sudoku;