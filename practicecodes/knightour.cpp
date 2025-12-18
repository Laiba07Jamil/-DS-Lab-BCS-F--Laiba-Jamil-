#include <iostream>
using namespace std;

bool isValid(int** board, int n ,int row ,int col , int expectval){
    if(row < 0 || col < 0 || row > n || col > n || board[n][n] != expectval){
        return false;
    }
    if(expectval == ((n * n)-1)){
        return true;
    }
    bool ans1 = (isValid(board , n ,row - 2 ,col + 1,expectval + 1));
    bool ans2 = (isValid(board , n ,row - 1 ,col + 2, expectval + 1));
    bool ans3 = (isValid(board , n ,row - 1 ,col + 2, expectval + 1));
    bool ans4 = (isValid(board , n ,row + 2 ,col + 1, expectval + 1));
    bool ans5 = (isValid(board , n ,row + 2 ,col - 1, expectval + 1));
    bool ans6 = (isValid(board , n ,row + 1 ,col - 2, expectval + 1));
    bool ans7 = (isValid(board , n ,row - 1 ,col - 2, expectval + 1));
    bool ans8 = (isValid(board , n ,row - 2 ,col - 1, expectval + 1));
    
    return (ans1 || ans2 || ans3 || ans4 || ans4 || ans5 || ans6 ||ans7 || ans8);
}

bool isPalindrome(char str[] , int len , string occurence[] , int count){
    int i = 0 , j = len - 1;
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    occurence[count] = str;
        count++;
    return true;
}
bool isSafe(char** board , int row , int col ,int n , int** visited){
    return (row >= 0 && col >= 0 && row <= n && col <= n && visited[row][col] == 0); 
}

void Palindrome(char** board , int n , int row ,int col ,int** visited , char path[] , int index,string occurence[] , int count ){
    path[index] = board[row][col];
    path[index + 1] = '\0';
    visited[row][col] = 1;

    if(index + 1 >= 3 && isPalindrome(path , strlen(path) ,occurence , count)){
        cout << "Palindrome found. " << path << endl;
        int c = 0;
        for(int i = 0 ; i < count ; i++){
            if(occurence[i] == path){
                c++;
            }
        }
        cout << "Occurence " << c << endl;

    }
    if(isSafe(board , row , col ,n ,visited)){
        Palindrome(board , n , row , col + 1 , visited, path , index + 1 ,occurence , count);
        Palindrome(board , n , row + 1, col , visited, path , index + 1 , occurence , count);
        Palindrome(board , n , row - 1, col , visited, path , index + 1 , occurence , count);
        Palindrome(board , n , row , col - 1 , visited, path , index + 1 , occurence , count);
    }

}