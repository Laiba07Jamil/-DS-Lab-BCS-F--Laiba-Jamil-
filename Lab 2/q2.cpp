#include <iostream>
using namespace std;

int main(){
    int **seating ;
    int benches ,seat;
    cout << "Enter the size of rows: " ;
    cin >> benches;
    cout << "Enter the size of columns: " ;
    cin >> seat ;
    
    seating = new int* [benches];
    for(int i = 0 ; i < benches ; i++){
        seating[i] = new int[seat];
    }
    
    for(int i = 0 ; i < benches ; i++){
        for(int j = 0 ; j < seat ; j++){
            while(true){
                int value;
                cout << "Enter the value for [" << i +1 << "] [" << j +1 << "] :";
                cin >> value;
                if(value == 1 || value == 0){
                     seating[i][j] = value;
                   break;
                }
                else{
                    cout<<"Invalid" << endl;
                }
            }
        }
    }
    
    for(int i = 0 ; i < benches ; i++){
        for(int j = 0 ; j < seat ; j++){
            cout  << seating[i][j] << " " ;
        }
        cout << endl;
    }
    
    for(int i = 0 ; i < benches ; i++){
        delete[] seating[i];
    }
    delete[] seating;
    
    return 0 ;
}
