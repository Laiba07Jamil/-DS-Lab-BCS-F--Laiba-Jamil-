#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        next = nullptr;
    }

    ~Node(){
        delete next;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList() : head(nullptr){}

    void insert(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->" ;
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }

    bool palindrome(){
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newhead = reverse(slow->next);
        Node* first = head;
        Node* second = newhead;
        while(second != NULL){
            if(first->data != second->data){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }

    Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;

    }

    ~LinkedList(){
        delete head;

    }
};

int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(3);
    l1.insert(2);
    l1.insert(1);
    l1.display();
    if(l1.palindrome()){
        cout << "The Linked List is Palindrome." << endl;
    }
    else{
        cout << "The Linked List is not Palindrome." << endl;
    }
    return 0;
}
