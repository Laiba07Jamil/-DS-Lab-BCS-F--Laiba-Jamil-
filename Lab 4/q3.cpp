
#include <iostream>
using namespace std;
int interpolationSearch(int arr[], int n, int target) {
    int low=0, high=n-1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[high] == arr[low]) {
            if (arr[low] == target) return low;
            else break;
        }
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == target)
         {  return pos;}
        else if (arr[pos] < target)
            {low = pos + 1;}
        else
       {     high = pos - 1;}
    }
        return -1;
}
bool isUniform(int arr[], int n) {
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != diff){
         return false;}
    }
    return true;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }}}
}

int main() {
    int n, target;
    cout << "Enter number of account balances: ";
    cin >> n;
    int arr[100]; 
    cout << "Enter balances: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubbleSort(arr, n);
    if (!isUniform(arr, n)) {
        cout << "Data is not uniformly distributed." << endl;
        return 0;}
    cout << "Enter target balance to search"<<endl;
    cin >> target;
    int index = interpolationSearch(arr, n, target);
    if (index != -1)
    cout << "Balance " << target << " found at index " << index << endl;
    else
   cout << "Balance not found." << endl;

    return 0;
}
