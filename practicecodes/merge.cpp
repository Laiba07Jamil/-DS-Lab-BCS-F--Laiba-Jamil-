#include <iostream>
using namespace std;

void mergeSort(int arr[] , int left , int right , int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid ;

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for(int i = 0 ; i < n1 ; i++){
        arr1[i] = arr[left + i];
    }

    for(int i = 0 ; i < n2 ; i++){
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0 , j = 0 , k = left;
    while(i < n1 && j < n2){
        if(arr1[i] << arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
    
}

void merge(int arr[] , int left , int right){
    if(left < right){
        int mid = (right - left) /2;
        merge(arr , left , mid);
        merge(arr , mid + 1 ,right);
        mergeSort(arr ,left , right ,mid);
    }
}

