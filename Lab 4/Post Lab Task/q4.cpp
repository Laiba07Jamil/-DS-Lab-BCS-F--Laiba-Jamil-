/*Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/

#include<iostream>
using namespace std;

void Insertion(int arr[] , int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void binarysearch(int arr[] , int n , int target){
    int left = 0 ;
    int right = n - 1;
    bool flag = false;
    while(left <= right){
        int mid = left + (right - left)/2 ;
        if(arr[mid] == target){
            cout << "Element is found at index " << mid + 1 << endl;
            flag = true;
            break;
        }
        else if(arr[mid] > target){
            right = mid - 1; 
        }
        else{
            left = mid + 1;
        }
    }
    if(!flag){
        cout << "Target element is not found." << endl;
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

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    Insertion(arr , n );
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    binarysearch(arr , n , target);
    delete[] arr;
    return 0;

}