#include <iostream>
using namespace std;

int main(){
    int **seating ;
    int rows ,columns;
    cout << "Enter the size of rows: " ;
    cin >> rows;
    cout << "Enter the size of columns: " ;
    cin >> columns ;
    
    seating = new int* [rows];
    for(int i = 0 ; i < rows ; i++){
        seating[i] = new int[columns];
    }
    
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            while(true){
                int value;
                cout << "Enter the value for [" << i +1 << "] [" << j +1 << "] :";
                cin >> value;
                if(value == 1 || value == 0){
                     arr[i][j] = value;
                   break;
                }
                else{
                    cout<<"Invalid" << endl;
                }
            }
        }
    }
    
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            cout  << seating[i][j] << " " ;
        }
        cout << endl;
    }
    
    
    
    
    for(int i = 0 ; i < rows ; i++){
        delete[] seating[i];
    }
    delete[] seating;
    
    return 0 ;
}
