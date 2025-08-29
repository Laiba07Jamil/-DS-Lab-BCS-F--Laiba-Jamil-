#include <iostream>
using namespace std;

void update(int *arr, int n){
    char choice;
    do{
    int index;
    int value;
    cout << "Enter the index to change :" ;
    cin >> index;
    if(index < 0 || index > n){
        cout << "Error" << endl;
        return;
    }
    cout << "Enter the value to change: " ;
    cin >> value;
    arr[index] = value;
        
        cout << "Do you want to update the value again (y/n) :";
        cin >> choice ;
    }while(choice == 'y' || choice == 'Y');
}

void print(int *arr , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
}

int main(){
   int size;
   cout << "Enter the size of array: "  ;
   cin >> size;
   
   int *arr;
   arr = new int[size];
   
   for(int i = 0 ; i < size ; i++){
       cout << "Enter the element " << i+1 << ":";
       cin >> arr[i];
   }
    
   update(arr,size);
   print(arr , size);
   delete[] arr;
   return 0;
}
