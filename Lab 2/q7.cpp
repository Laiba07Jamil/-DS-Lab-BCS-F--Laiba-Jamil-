#include <iostream>
using namespace std;

int main(){
    int departments;
    cout << "Enter the number of departments: ";
    cin >> departments;

    int *employees = new int [departments];
    double **salaries = new double* [departments];

    for(int i = 0 ; i < departments ; i++){
        cout << "Enter the number of employees in department " << i+1 << ": ";
        cin >> employees[i];
    }
    for(int i = 0 ; i < departments ; i++){
        salaries[i] = new double[employees[i]];
    }

    for(int i = 0 ; i < departments ; i++){
        for(int j= 0 ; j < employees[i] ; j++){
            cout << "Enter the salary for [" << i+1 << "][" << j+1 << "] : " ;
            cin >> salaries[i][j]; 
        }
    }

    for(int i = 0 ; i < departments ; i++){
        for(int j = 0 ; j < employees[i] ; j++){
            cout << salaries[i][j] << " ";
        }
    cout << endl;    
    }
    
    for(int i = 0 ; i < departments ; i++){
        double max = -1;
        for(int j = 0 ; j < employees[i] ; j++){
            if (salaries[i][j] > max){
                max = salaries[i][j];
            }
            else continue;
        }
        cout << "Maximum salary of department " << i+1 << " is : " << max << endl;
    }

    double max = -1;
    int bestDept = -1;
    for(int i = 0 ; i < departments ; i++){
        double sum = 0 ;
        for(int j = 0 ; j < employees[i] ; j++){
            sum += salaries[i][j];
        }
        double average = sum / employees[i];
        if(average > max){
            max = average;
            bestDept = i+1;
        }
        else continue;
    }
    cout << "Department " << bestDept << " has maximum average salary and that is : " << max  << endl;


    delete[] employees;
    for(int i = 0 ; i < departments ; i++){
            delete[] salaries[i];
        }
    delete[] salaries;
    return 0;
}