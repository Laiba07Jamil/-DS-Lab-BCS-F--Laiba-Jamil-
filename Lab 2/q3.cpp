#include <iostream>
using namespace std;

int main(){
    int students;
    cout << "Enter the number of students:";
    cin >> students;

    int *course = new int[students];
    for(int i = 0 ; i < students ; i++){
        cout << "Enter the number of courses of student " << i+1 <<":";
        cin >> course[i];
    }


    int **marks = new int*[students];

    for(int i = 0 ; i < students ; i++){
            marks[i] = new int[course[i]];
    }

    for(int i = 0 ; i < students ; i++){
        for(int j = 0 ; j < course[i] ; j++){
            cout << "Enter marks for student " << i+1 << " course " << j+1 << ":";
            cin >> marks[i][j];
        }
    }


    for(int i = 0 ; i < students ; i++){
        for(int j = 0 ; j < course[i] ; j++){
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----Printing Average of each Student----" << endl;
    for(int i = 0 ; i < students ; i++){
        int sum = 0;
        for(int j = 0 ; j < course[i] ; j++){
            sum += marks[i][j];
        }
        double average ;
        average = (double) sum/ course[i] ;
        cout << "Average marks of student " << i+1 << " is :" << average << endl;
    }



    for(int i = 0 ; i < students ; i++){
            delete[] marks[i];
    }
    delete[] marks;
}