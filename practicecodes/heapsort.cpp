#include <iostream>
using namespace std;

// ascending 
void heapify(int arr[] , int n , int i){
    int largest = i ;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildheap(int arr[] , int n){
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }

    for(int i = n - 1 ; i > 0 ; i--){
        swap(arr[0] , arr[i]);
        heapify(arr,i,0);
    }
}

void print(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//descending

void heapifyD(int arr[] , int n , int i){
    int largest = i ;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] < arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildheapD(int arr[] , int n){
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        heapifyD(arr,n,i);
    }

    for(int i = n - 1 ; i > 0 ; i--){
        swap(arr[0] , arr[i]);
        heapifyD(arr,i,0);
    }
}


int main(){
    int arr[7] = {7,3,45,6,8,2,1};
    buildheap(arr,7);
    print(arr,7);

    buildheapD(arr,7);
    print(arr,7);

}