#include <iostream>
using namespace std;

#define n 4
#define N 5

void print(char board[n][N]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char board[n][N] , int row ,int col ,int visited[n][N]){
    if(row >= n && col >= N && row <= 0 && col <= 0 && visited[row][col] == 0){
        if(board[row][col] == 'A' || board[row][col] == 'D' || board[row][col] == 'E'){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}
bool sol(char board[n][N] , int row , int col , int visited[n][N] ,int solution[n][N] ,int& points){
    
    
    if(row == 'R' && col == 'R'|| row == n -1 && col == N -1){
        solution[row][col] = 1;
        visited[row][col] = 1;
        return true;
    }

    if(isSafe(board , row , col ,visited)){
        if(board[row][col] == 'A'){points += 2;}
        if(board[row][col] == 'D'){points += 1;}        

        solution[row][col] = 1;

    if(sol(board , row , col + 1 , visited , solution, points));
    if(sol(board , row , col - 1 ,visited, solution, points));
    if(sol(board , row + 1 , col , visited,solution, points));
    if(sol(board , row - 1 ,col , visited , solution, points));

    solution[row][col] = 0;
    visited[row][col]= 0;
    return false;
    }

    return false;
}

void maze(char board[n][N] , int row , int col ,int visited[n][N]){
    int solution[n][N] = {0};
    int points = 0 ;
    if(!sol(board , row , col ,visited, solution , points)){
        cout << "No solution exist" << endl;
    }
    else{
        print(board );
        cout << "Points: " << points << endl;
    }
}







int main(){
    char board[n][N] = {
    {'A','E','E','T','D'}, 
    {'D','E','A','T','T'},
    {'E','A','D','T','E'},
    {'D','D','E','T','R'}};

int visited[n][N]={0};
}