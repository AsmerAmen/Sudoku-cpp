#include <iostream>
#include <stdio.h>
using namespace std;

#define LEN 9

void printArray(int grid[LEN][LEN]){
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

bool hasEmptyCells(int grid[LEN][LEN], int& row, int& column){
    for(row=0; row<LEN; row++)
        for(column=0; column<LEN; column++)
            if(grid[row][column] == 0)
                return true;
    return false;
}

bool isInRow(int grid[LEN][LEN], int row, int num){
    for(int col=0; col<LEN; col++)
        if(grid[row][col] == num)
            return true;
    return false;
}


bool isInColumn(int grid[LEN][LEN], int column, int num){
    for(int row=0; row<LEN; row++)
        if(grid[row][column] == num)
            return true;
    return false;
}


bool isInBox(int grid[LEN][LEN], int row_start, int column_start, int num){
    for(int row=row_start; row<3; row++)
        for(int col=column_start; col<3; col++)
            if(grid[row_start+row][column_start+col] == num)
                return true;
    return false;
}

bool isToUse(int grid[LEN][LEN], int row, int column, int num){
    return ! isInColumn(grid, column, num) &&
            ! isInRow(grid, row, num) &&
            ! isInBox(grid, row - (row%3), column - (column%3), num) &&
            grid[row][column] == 0;            
}

bool solve(int grid[LEN][LEN]){
    int row, column;
    if( ! hasEmptyCells(grid, row, column))
        return true;
    
    for(int n=1; n<=LEN; n++){
        if(isToUse(grid, row, column, n)){
            grid[row][column]=n;
            if(solve(grid))
                return true;
            else
            grid[row][column]=0;
        }
    }
    return false;

}


int main(){

    int array[LEN][LEN]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };

    if(solve(array))
        printArray(array);
    else
        cout<<"Oops !"<<endl;
    
    return 0;
}