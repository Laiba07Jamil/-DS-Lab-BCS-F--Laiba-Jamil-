#include <iostream>
using namespace std;

int main(){
    int r1 , c1 ;
    int r2 , c2 ;
    while(true){
        cout << "Enter the no of rows for matrix 1: ";
        cin >> r1;
        cout << "Enter the no of columns for matrix 1: ";
        cin >> c1;
        cout << "Enter the no of rows for matrix 2: ";
        cin >> r2;
        cout << "Enter the no of columns for matrix 2: ";
        cin >> c2;
        if(r1 != r2 || c1 != c2){
            cout << "Invalid" << endl;
            continue;
        }
        else{
            break;
        }
    }
    int** matrix1 = new int* [r1];
    for(int i = 0 ; i < r1 ; i++){
        matrix1[i] = new int[c1];
    }

    int** matrix2 = new int* [r2];
    for(int i = 0 ; i < r2 ; i++){
        matrix2[i] = new int[c2];
    }

    cout << "----For Matrix 1----" << endl;
    for(int i = 0 ; i < r1 ; i++){             
        for(int j = 0 ; j < c1 ; j++){
            cout << "Enter [" << i+1 << "][" << j + 1 << "]: ";
            cin >> matrix1[i][j];
        }
    }
    
    cout << "----For Matrix 2----" << endl;
    for(int i = 0 ; i < r2 ; i++){             
        for(int j = 0 ; j < c2 ; j++){
            cout << "Enter [" << i+1 << "][" << j + 1 << "]: ";
            cin >> matrix2[i][j];
        }
    }

    int** addmatrix = new int*[r1]; 
    for(int i = 0 ; i < r1 ; i++){
        addmatrix[i] = new int[c1];
    }

    for(int i = 0 ; i < r1 ; i++){             
        for(int j = 0 ; j < c1 ; j++){
            addmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "------After Addition------" << endl;
    for(int i = 0 ; i < r1 ; i++){             
        for(int j = 0 ; j < c1 ; j++){
          cout << addmatrix[i][j] << " " ;
        }
        cout << endl;
    }

    int** submatrix = new int*[r1]; 
    for(int i = 0 ; i < r1 ; i++){
        submatrix[i] = new int[c1];
    }

    for(int i = 0 ; i < r1 ; i++){             
        for(int j = 0 ; j < c1 ; j++){
            submatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    cout << "------After Subtraction------" << endl;
    for(int i = 0 ; i < r1 ; i++){             
        for(int j = 0 ; j < c1 ; j++){
          cout << submatrix[i][j] << " " ;
        }
        cout << endl;
    }



    for(int i = 0 ; i < r1 ; i++){
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for(int i = 0 ; i < r2 ; i++){
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for(int i = 0 ; i < r1 ; i++){
        delete[] addmatrix[i];
    }
    delete[] addmatrix;

    for(int i = 0 ; i < r1 ; i++){
        delete[] submatrix[i];
    }
    delete[] submatrix;
}