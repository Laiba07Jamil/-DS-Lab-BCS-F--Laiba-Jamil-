/*Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays.*/

#include <iostream>
using namespace std;


void bubblesort(int arr[] , int size){

    for(int i = 0 ; i < size ; i++){
        for(int i = 0 ; i < size - 1 ; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

}

void printing(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int* arr= new int[n];

    for(int i = 0 ; i < n ; i++){
        cout << "Enter the element " << i + 1 << ":" ;
        cin >> arr[i]; 
    }
    
    cout << "Before sorting " << endl;
    printing(arr , n);
    cout << endl;
    bubblesort(arr , n);
    cout << "After sorting " << endl;
    printing(arr , n);

    delete[] arr;
    return 0 ;
}