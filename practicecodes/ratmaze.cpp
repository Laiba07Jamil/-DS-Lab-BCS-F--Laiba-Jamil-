#include <iostream>
using namespace std;

#define N 6

bool isSafe(char board[N][N] , int row , int col, int visited[N][N]){
    return (row >= 0 && row <= N && col >= 0 && col <= N && board[row][col] == 'P' && visited[row][col] == 0);
}

bool solvemazeE(char board[N][N] , int row , int col ,int solution[N][N] , int visited[N][N]){
    if(board[row][col] == 'T' && row == N-1 && col == N - 1){
        solution[row][col] = 1;
        visited[N][N] = 1;
        return true;
    }

    int energy = 100;
    if(board[row][col] == 'H') {energy -= 2;
    }

    if(isSafe(board , row , col , visited)){
        solution[N][N] = 1;
        visited[N][N] = 1;

        if(solvemazeE(board , row ,col + 1,solution,visited)) return true;
        if(solvemazeE(board , row , col - 1 ,solution , visited)) return true;
        if(solvemazeE(board , row + 1 , col ,solution ,visited)) return true;
        if(solvemazeE(board , row - 1 , col ,solution ,visited)) return true;

        solution[N][N] = 0;
        visited[N][N] = 0;
        return false;
    }

    return false;
}