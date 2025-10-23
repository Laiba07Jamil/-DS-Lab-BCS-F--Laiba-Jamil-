/*Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/

#include <iostream>
using namespace std;

#define n 5

class CircularQueue{
    int arr[n];
    int front;
    int rear;

    public:
    CircularQueue(){
        rear = -1;
        front = -1;
    }

    bool isEmpty(){
        return front == -1;
    }
    
    bool isfull(){
        if((front == rear + 1) || (rear == n - 1 && front == 0)){
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int data){
        if(isfull()){
            cout << "Queue is full. " << endl;
            return;
        }

        if(front == -1){front = 0;}
        rear = (rear + 1) % n;
        arr[rear] = data;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty. " << endl;
            return -1;
        }

        int temp = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % n;
        }
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % n;
        }
        cout << endl;
    }

};

int main (){
    CircularQueue c1;
    c1.enqueue(1);
    c1.enqueue(2);
    c1.enqueue(3);
    c1.enqueue(4);
    c1.enqueue(5);

    c1.display();

    c1.dequeue();
    c1.display();
}