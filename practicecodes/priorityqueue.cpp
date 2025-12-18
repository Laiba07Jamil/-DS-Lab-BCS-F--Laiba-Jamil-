#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int priority;
    Node* next;
    Node(int val , int p){
        data = val;
        priority = p;
        next = nullptr;
    }
};

class PQ{
    Node* front;
    public:
    PQ() :front(nullptr){}

    void insert(int val , int prio){
        Node* newnode = new Node(val , prio);
        if(front == NULL || prio > front->priority){
            newnode->next = front;
            front = newnode;
        }

        Node* temp = front;
        while(temp->next != NULL && temp->next->priority >= prio){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void remove(){
        if(front == NULL){
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek(){
        if(!front){
            return;
        }
        return front->data;
    }

    bool isEmpty(){
        return front == NULL;
    }


    void display(){
        if(!front){
            return;
        }
        Node* temp = front;
        while(temp){
            cout << "(" << temp->priority << "," << temp->data << ")" << endl;
            temp = temp->next;
        }
    }

    ~PQ(){
        Node* temp = front;
        while(front){
            temp = temp->next;
            delete temp;
        }
    }
};

