/*Implement a Sudoku solver using the backtracking technique. The program should take a
partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution,
backtrack by resetting the cell to 0 and trying the next number.*/


#include <iostream>
using namespace std;

#define  rows 9
#define  cols 9 

bool isSafe(int **board ,int row , int col , int dig){
    for(int j = 0 ; j < 9 ; j++){
        if(board[row][j] == dig)
            return false; 
    }

    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col] == dig)
        return false;
    }

    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for(int i = sr ; i <= sr + 2 ; i++){
        for(int j = sc ; j <= sc + 2 ; j++){
            if(board[i][j] == dig)
            return false; 
        }
    }

    return true;
}

bool SudokoSolver(int **board , int row , int col ){
    if(row == 9){
        return true;
    }

    int nextrow = row;
    int nextcol = col + 1;
    if(nextcol == 9){
        nextrow = row + 1;
        nextcol = 0;
    }

    if(board[row][col] != 0){
        return SudokoSolver(board , nextrow , nextcol);
    }

    for(int dig = 1 ; dig <= 9 ; dig++){
        if(isSafe(board , row , col , dig)){
            board[row][col] = dig;
            if(SudokoSolver(board , nextrow, nextcol))
            return true;
            board[row][col] = 0;
    }
    }
    return false;
}

void printboard(int **board){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    
    int **board =new int*[rows];
    for(int i = 0 ; i < rows ; i++){
        board[i] = new int[cols];
    }

    int input[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            board[i][j] = input[i][j];
        }
    }

    if(SudokoSolver(board , 0 , 0)){
        cout << "Sudoko is Solved." << endl;
    }
    else{
        cout << "Sudoko isn't Solved." << endl;
    }

    cout << endl;
    printboard(board);

    for(int i = 0 ; i < rows ; i++){
       delete[] board[i];
    }

    delete[] board;
    return 0 ;

}