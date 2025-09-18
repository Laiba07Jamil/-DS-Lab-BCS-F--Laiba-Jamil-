/*Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/

#include <iostream>
using namespace std;


void Linearsearch(int arr[] , int target , int size){
    bool flag = false;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == target){
             cout << "Element is found at index " << i + 1 << endl;
             flag = true;
        }
    }
    if(!flag){
        cout << "Target Element is not found in the array." << endl;
    }
}


int main(){
    int n;
    cout << "Enter the size of Elements :" ;
    cin >> n;

     int *arr;
    arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter Element " << i+1 << ":" ;
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    
    Linearsearch(arr , target , n);
    delete[] arr;
    return 0;
 }
