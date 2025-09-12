#include <iostream>
using namespace std;

int main(){
    int n;
    cout <<"ENter the size of elemets: ";
    cin >> n;

    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter the element " << i + 1 << " :" ;
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array" << endl;
    for(int i = 0 ; i < n ; i ++){
        cout << arr[i] << " " ;
    }

    delete[] arr;
}