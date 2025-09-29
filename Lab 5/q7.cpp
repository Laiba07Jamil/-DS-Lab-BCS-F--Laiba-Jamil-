/*Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.*/

#include <iostream>
using namespace std;

void printSolution(int **board , int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool issafe(int **board , int rows , int cols , int N){
    for(int i = 0 ; i < N ; i++){
        if(board[i][cols] == 1){return false;}               //vertical
    }

    for(int i = rows , j =cols ; i >= 0 && j >= 0 ; i-- , j--){
            if(board[i][j] == 1){return false;}             //left diagonal
    }

    for(int i = rows , j = cols ; i >= 0 && j < N ; i-- , j++){
            if(board[i][j] == 1){return false;}              // right diagonal
    }

    return true;
}


bool nQueens(int **board, int rows ,int N ){
    if(rows == N){
        printSolution(board , N);
        return true;
    }

    for(int j = 0 ; j < N ; j++){
        if(issafe(board , rows, j , N)){
            board[rows][j] = 1;
            nQueens(board , rows + 1 ,N );
            board[rows][j] = 0; 
        }
    }
    return false;
}



int main(){
    int N;
    cout << "Enter the number N:";
    cin >> N;

    int** board = new int*[N];
    for(int i = 0 ; i < N ; i++){
        board[i] = new int[N]{};
    }

    cout << "Possible solutions are: " << endl;
    nQueens(board , 0 , N);

    for(int i = 0 ; i < N ; i++){
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

