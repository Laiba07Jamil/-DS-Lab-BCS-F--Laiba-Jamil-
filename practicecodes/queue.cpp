#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int n){
        data = n;
        next = NULL;
    }
};

class LLqueue{
    Node* front;
    Node* rear;
    int currsize;

    public:
    bool isEmpty(){
        return front == NULL;
    }

    void enqueue(int data){
        Node* newnode = new Node(data);
        if(isEmpty()){
            front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
        currsize++;
    }

    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        Node* temp = front;
        int val = temp->data;
        front = front->next;
        if(front== NULL){rear = NULL;}
        delete temp;
        currsize--;
        return val;
    }

    int size(){
        return currsize;
    }

    int getfront(){
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }

    
};


