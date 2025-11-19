#include <iostream>
using namespace std;

#define maxsize 100

class MaxHeap {
    public:
        int heap[100];
        int size;
        MaxHeap() { 
            size = 0;
     }

        int parent(int i) { return (i-1)/2; }
        int left(int i) { return 2*i+1; }
        int right(int i) { return 2*i+2; }

        void heapifyUp(int i) {
            while (i != 0 && heap[parent(i)] < heap[i]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void heapifyDown(int i) {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if (l < size && heap[l] > heap[largest])
                largest = l;
            if (r < size && heap[r] > heap[largest])
                largest = r;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                heapifyDown(largest);
            }
        }

        void insert(int val) {
            if (size >= maxsize) {
                cout << "Heap is full" << endl;
                return;
            }

            heap[size] = val;
            size++;
            heapifyUp(size - 1);
        }

        void update_key(int index, int new_val) {
            if (index < 0 || index >= size) {
                cout << "Invalid index" << endl;
                return;
            }

            int old_val = heap[index];
            heap[index] = new_val;

            if (new_val > old_val)
                heapifyUp(index);
            else
                heapifyDown(index);
        }

     void delete_key(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }

        heap[index] = heap[size - 1];
        size--;

        heapifyUp(index);
        heapifyDown(index);
    }

    void print() 
        {
            for (int i = 0; i < size; i++)
                cout << heap[i] << " ";
            cout << endl;
    }

    int kthLargest(int k) {
    if (k <= 0 || k > size) {
        cout << "Invalid value of k" << endl;
        return -1; 
    }

    MaxHeap tempHeap = *this;  
    int result = -1;
    
    for (int i = 0; i < k; i++) {
        result = tempHeap.heap[0]; 
        tempHeap.delete_key(0);    
    }

    return result;
}

};


int main() {
    MaxHeap h;

    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    cout << "Initial max heap: ";
    h.print();
    cout << h.kthLargest(3);
}