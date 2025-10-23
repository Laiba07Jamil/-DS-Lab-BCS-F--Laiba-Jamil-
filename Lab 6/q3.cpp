/*Task 3 – Simple Queue Implementation
Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full*/

#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int capacity;
    int size;

    public:
    Queue(int n){
        capacity = n;
        arr = new int[capacity];
        size = 0;
    }

    bool isFull(){
        return size == capacity - 1;
    }

    bool isEmpty(){
        return size == 0 ;
    }

    void enqueue(int data){
        if(isFull()){
            cout << "Queue is full." << endl;
            return;
        }

        arr[++size] = data;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty." << endl;
            return -1;
        }

        int temp = arr[0];

        for(int i = 1 ; i <= size  ;i++){
            arr[i - 1] = arr[i];
        }
        size--;
        return temp;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is Empty. " << endl;
            return;
        }

        cout << "Queue Elements are: ";
        for(int i = 1 ; i <= size ; i++){
            cout << arr[i] <<  " ";
        }
        cout << endl;
    }

    ~Queue(){
        delete[] arr;
    }

};

int main(){
    Queue queue(6);
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(9);
    queue.enqueue(11);

    cout << "After enqueuing : " << endl;
    queue.display();
    queue.dequeue();
    cout << "Dequeuing "  << endl;
    cout << "After dequeuing :" << endl;
    queue.display();
}