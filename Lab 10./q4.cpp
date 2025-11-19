#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap(int a[], int n) {
        size = n;
        for (int i = 0; i < n; i++)
            arr[i] = a[i];
    }

    void maxHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            int t = arr[i];
            arr[i] = arr[largest];
            arr[largest] = t;

            maxHeapify(largest);
        }
    }

    void convertToMaxHeap() {
        for (int i = (size - 2) / 2; i >= 0; i--)
            maxHeapify(i);
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Min Heap array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    Heap h(a, n);

    h.convertToMaxHeap();

    cout << "Max Heap array: ";
    h.print();

    return 0;
}
