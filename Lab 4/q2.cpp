#include <iostream>
using namespace std;


int binarySearch(int arr[] ,int size ,int target, int &insertpos){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = left + (right - left) /2;
        if(arr[mid] == target){
            return mid + 1;
        }
        else if (arr[mid] < target){
            left = mid + 1; 
        }
        else{
            right = mid - 1;
        }
    }
    insertpos = left;
    return -1;
}

int main(){
    int n;
    cout << "Enter the num of Employeees ID:";
    cin >> n;

    int *arr = new int[n + 1];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter the Employee's ID in sorted order.";
        cin >> arr[i];
    }

    int roll;
    cout << "Enter your roll number: ";
    cin >> roll;
    int target = roll % 100;

    int insertpos = 0;
    int indx = binarySearch(arr , n , target , insertpos);
    if(indx != -1){
        cout << "Target is fouond at index " << indx << endl; 
    }
    else{
        for(int i = n ; i > insertpos ; i--){
            arr[i] = arr[i - 1];
        }
        arr[insertpos] = target;
        n++;

        cout << "Employee ID " << target << " not found ." << endl;
        cout << "Inserted at index " << insertpos  << "." << endl ;

        cout << "Updated List: " << endl;
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    delete[] arr ;
    
    return 0 ;
}

