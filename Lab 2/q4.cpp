#include <iostream>
using namespace std;

double* resizearray(double* arr , int oldsize , int newsize){
    if(oldsize == newsize){
        return arr;
    }

    double* newarr =  new double[newsize];
    int limit;
    if(oldsize < newsize){
        limit = oldsize;
    }
    else{
        limit = newsize;
    }
    for(int i = 0 ; i < limit ;i++){
        newarr[i] = arr[i];
    }
    delete[] arr;
    return newarr;
}
int main(){
    int months;
    cout << "Enter the number of months: " ;
    cin >> months;

    double *expenses = new double[months];
    for(int i = 0 ; i < months ; i++){
        cout << "Enter the number expenses of each month: ";
        cin >> expenses[i];
    }

    int newsize;
    cout << "Enter the size to reallocate: ";
    cin >> newsize;
    expenses = resizearray(expenses , months , newsize);
    for(int i = months ; i < newsize ; i++){
        cout << "Enter the new elements: " ;
        cin >> expenses[i];
    }

    int sum = 0 ;
    for(int i = 0 ; i < months ; i++){
        sum += expenses[i];
    }
    double average = double(sum) / months;
    cout << "Total: " << sum  << endl; 
    cout << "Average: " << average << endl;

    
    for(int i = 0 ; i < newsize ;i++){
        cout << expenses[i] << " " ;
    }
    delete[] expenses;
    return 0;
}