#include <iostream>
using namespace std;


void Linearsearch(int arr[] , int target , int size){
    bool flag = false;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == target){
             cout << "Target element is found at index " << i + 1 << "." << endl;
             flag = true;
        }
    }
    if(!flag){
        cout << "Target is not found ." << endl;
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
