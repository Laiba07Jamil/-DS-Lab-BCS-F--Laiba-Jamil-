/*Task 1 – Basic Stack Implementation
Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents*/

#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int capacity;
    int top;

    public:
    Stack(int n){
        capacity = n;
        arr = new int[capacity];
        top = -1 ;
    }  

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    void push(int data){
        if(isFull()){
            cout << "Stack is full." << endl;
            return;
        }

        arr[++top] = data;
        
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack underflow. " << endl;
            return -1;
        }

        int val = arr[top];
        top-- ;
        return val;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is Empty. " << endl;
            return ; 
        }

        for(int i = 0 ; i <= top; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

    ~Stack(){
        delete[] arr;
    }
};

int main(){
    Stack st(6);
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(9);

    st.display();
    cout << "The top ELement is " << st.peek() << endl;
    st.pop();
    st.pop();
    st.display();
}
