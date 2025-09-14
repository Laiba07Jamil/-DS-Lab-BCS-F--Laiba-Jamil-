#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr; 
    }
}; 

class CircularLinkedList{
    Node* head;
    public:
    CircularLinkedList() : head(nullptr){}

    void insert(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            newnode->next = head;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void print(){
        Node* temp = head;
        do{
            cout  << temp->data << "->";
            temp = temp->next;
        }while(temp != head); 
        cout << "HEAD" << endl;
    }

    int Josephus(int k){
        Node* temp = head;
        Node* prev;
        while(temp->next != temp){
        for(int i = 1 ; i < k ; i++){
            prev = temp ;
            temp = temp->next;
        }
        Node* newn = temp;
        prev->next = temp->next;
        delete newn;
        temp = prev->next;
        }
        head = temp;
        return temp->data;
    }
};

int main(){
    CircularLinkedList c1;

    int n,k;
    cout << "How many elements in Linked List: ";
    cin >> n;
    cout << "At which position want to delete: ";
    cin >> k;
    for(int i = 1 ; i <= n ; i++ ){
        c1.insert(i);
    }
    c1.print();
    int survive =  c1.Josephus(k);
    cout << "Only survivor left is: " << survive  ;
    
}