#include <iostream>
using namespace std;

class Circularqueue{
    private:
    int* arr ;
    int size;
    int front;
    int rear;

    public:
    Circularqueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isfull(){
        if((front == 0  && rear == size -1) || (front = rear + 1)){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        return front == -1;
    }

    void push(int x){
        if(isfull()){
            return;
        }
        if(front == -1){front = 0;}
        rear = (rear+ 1) % size;
        arr[rear] = x ;
    }

    int pop(){
        if(isEmpty()){
            return -1;
        }
        int temp = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
        return temp;
    }

    int top(){
        return arr[front];
    }

    void display(){
        if(isEmpty()){
            return;
        }

       int temp = front;
       while(true){
        cout << arr[temp] << " ";
        if(temp == rear){
            break;
        }
        temp = (temp + 1) % size;
       }
    }
};

int main(){
    Circularqueue arr(3);
    arr.push(5);
    arr.push(3);
    arr.push(56);
    arr.display();
}