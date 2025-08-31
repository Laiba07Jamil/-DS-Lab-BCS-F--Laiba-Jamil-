#include <iostream>
using namespace std;

int main(){
    int rows , cols;
    cout << "Enter the number of rows: " ;
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int **sparse = new int*[rows];
    for(int i = 0 ; i < rows ; i++){
        sparse[i] = new int [cols];
    } 

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << "Enter the number of elements for [" << i+1 << "][" << j+1 << "]: " ;
            cin >> sparse[i][j];
        }
    }

    cout << endl;
    cout << "----Normal Matrix----" << endl;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << sparse[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "----Compressed Matrix (row , column ,value)----" << endl;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(sparse[i][j] != 0){
                cout << i + 1 << " " << j + 1 << " " << sparse[i][j] << endl;;
            }
        }
    }



    for(int i = 0 ; i < rows ; i++){
        delete[] sparse[i];
    }
    delete[] sparse;
    
}