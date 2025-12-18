#include <iostream>
using namespace std;


int partition(int* arr , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }

        while (arr[j] > pivot && j >= low){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; 
}


void quickSort(int* arr, int low , int high){
    if(low < high){
        int pivot = partition(arr , low , high);
        quickSort(arr , low , pivot - 1);
        quickSort(arr , pivot + 1 , high);
    }
}


int main(){
    int arr[5] = {9,5,3,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr , 0 , n-1);
    for(int i = 0 ;i < n ; i++){
        cout << arr[i] << " " ;
    }
}