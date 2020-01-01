#include <iostream>
#include <stdio.h>
#include <new>

#include "sudoku.h"

extern "C" {
//    void * createInstance(){
//        return new(std::nothrow) sudoku;
//    }
    bool solve(int array[LEN][LEN]){
        return sudoku.solve(array);
    }
    void print(){
        sudoku.printArray();
    }
}


//using namespace std;
//
//int main(){
//
//    int array[LEN][LEN]={
//        {5,3,0,0,7,0,0,0,0},
//        {6,0,0,1,9,5,0,0,0},
//        {0,9,8,0,0,0,0,6,0},
//        {8,0,0,0,6,0,0,0,3},
//        {4,0,0,8,0,3,0,0,1},
//        {7,0,0,0,2,0,0,0,6},
//        {0,6,0,0,0,0,2,8,0},
//        {0,0,0,4,1,9,0,0,5},
//        {0,0,0,0,8,0,0,7,9},
//    };
//    SudokuSolver s = SudokuSolver();
//    if(s.solve(array))
//        s.printArray();
//    else
//        cout<<"Oops !"<<endl;
//
//    return 0;
//}