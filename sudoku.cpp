#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

using namespace std;

bool SudokuSolver::hasEmptyCells(int& row, int& column){
    for(row=0; row<LEN; row++)
        for(column=0; column<LEN; column++)
            if(grid[row][column] == 0)
                return true;
    return false;
}

bool SudokuSolver::isInRow(int row, int num){
    for(int col=0; col<LEN; col++)
        if(grid[row][col] == num)
            return true;
    return false;
}


bool SudokuSolver::isInColumn(int column, int num){
    for(int row=0; row<LEN; row++)
        if(grid[row][column] == num)
            return true;
    return false;
}


bool SudokuSolver::isInBox(int row_start, int column_start, int num){
    for(int row=row_start; row<3; row++)
        for(int col=column_start; col<3; col++)
            if(grid[row_start+row][column_start+col] == num)
                return true;
    return false;
}

bool SudokuSolver::isToUse(int row, int column, int num){
    return ! isInColumn(column, num) &&
            ! isInRow(row, num) &&
            ! isInBox(row - (row%3), column - (column%3), num) &&
            grid[row][column] == 0;
}

bool SudokuSolver::solve(int array[LEN][LEN]){
//    for(int i=0; i<LEN; i++)
//        for(int j=0; j<LEN; j++)
//            grid[i][j] = array[i][j];
    memcpy(grid, array, sizeof(grid));

    int row, column;
    if( ! hasEmptyCells(row, column))
        return true;

    for(int n=1; n<=LEN; n++){
        if(isToUse(row, column, n)){
            grid[row][column]=n;
            if(solve(grid))
                return true;
            else
            grid[row][column]=0;
        }
    }
    return false;

}

void SudokuSolver::printArray(){
    for(int i=0; i<LEN; i++){
        if(i == 3 || i == 6){
            for(int j=0; j<LEN+2; j++)
                cout<<"- ";
            cout<<endl;
        }

        for(int j=0; j<LEN; j++){
            if(j == 3 || j == 6)
                cout<<"| ";
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
}

SudokuSolver sudoku = SudokuSolver();
