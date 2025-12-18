#include <iostream>
using namespace std;

void bubblesort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n -1  ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion(int arr[] , int n){
    for(int i = 1 ; i < n ; i++){
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


void selection(int arr[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        int minindex = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}


void combsort(int arr[] , int n){
    int gap = n;
    float shrink = 1.3;
    bool swapped = true;
    while(gap > 1 || swapped){
        gap = (int) (gap / shrink);
        if(gap < 1) {
            gap = 1;
            swapped = false;
        }

        for(int i = 0 ; i + gap < n ; i++){
            if(arr[i] > arr[gap]){
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swapped = true;
            }
        }
    }
}


void shellsort(int arr[] , int n){
    for(int gap = n / 2 ; gap > 0 ; gap /= 2){

        for(int i = gap ; i < n ; i++){
            int temp = arr[i];
            int j;

            for(j = i ; j >= gap && arr[j - gap] > temp ; j -= gap){
                arr[j] = arr[j - gap];
            } 
            arr[j] = temp;
        }
    }
}


int binarysearch(int arr[] , int n , int target){
    int left = 0 ;
    int high = n - 1;
    bool flag = false;
    while(left <= high){
        int mid = left + (high - left) /2;
        if(arr[mid] == target){
            cout << "Target is found at index" << mid + 1 << endl;
            flag = true;
            break;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            left = mid + 1;
        }
        return -1;
    }
    if(!flag){
        cout <<" Target is not found." << endl;
    }
}

int interpolationsearch(int arr[] , int n , int target){
    int left = 0 ;
    int right = n - 1;
    while(left <= right && target <= arr[right] && target >= arr[left]){
        if(left == right){
            if(arr[left] == target){
                return left;
            }
            return -1;
        }

        int pos = left + double((right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if(arr[pos] == target){
            return pos;
        }
        else if(arr[pos] > target){
            right = pos - 1;
        }
        else{
            left = pos + 1;
        }
    }
    return -1;
}