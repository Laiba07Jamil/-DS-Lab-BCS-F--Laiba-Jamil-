/*Task 2 – Stack with Linked List
Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
history navigation).*/

#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    string data;

    Node(string d){
        data = d;
        next = NULL;
    }
};

class Stack{
    Node* top;
    int count;

    public:
    Stack(){
        top = NULL;
        count = 0;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void push(string data){
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        count++ ;
    }

    string pop(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return "-1";
        }

        string temp = top->data;
        Node* del = top;
        top = top->next;
        delete del;
        count--;
        return temp;
    }

    int size(){
        return count;
    }

    string peek(){
        if(isEmpty()){
            cout << "Stack is empty. " << endl;
            return "-1";
        }

        return top->data;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
            cout << endl;
        }
        cout << endl;
    }

    
};

int main(){
    Stack BrowseHistory;

    BrowseHistory.push("www.google.com");
    BrowseHistory.push("www.youtube.com");
    BrowseHistory.push("www.github.com");
    BrowseHistory.push("www.Linkedin.com");
    BrowseHistory.push("www.instagram.com");
    BrowseHistory.push("www.twitter.com");

    cout << "Current page : " <<BrowseHistory.peek() << endl;
    

    cout << "Popped " << BrowseHistory.pop() << endl;
    cout << "Now at : " << BrowseHistory.peek() << endl;

    cout << "Popped " << BrowseHistory.pop() << endl;
    cout << "Now at : " << BrowseHistory.peek() << endl;    

    cout << "Displaying " << endl;
    BrowseHistory.display();
    
}

