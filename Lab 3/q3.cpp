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

    void print(Node* temp){
        while(temp != NULL){
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    Node* findKthnode(Node* head , int k){
        Node* temp = head;
        int count = 1;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++ ;
        }
        if (temp && count == k)
            return temp ;
        else return nullptr;
    }

    Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = nullptr;
        while(temp != NULL){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;    
    }

    Node* ReverseInkthorder(int k){
        Node* temp = head;
        Node* pre = nullptr;
        Node* nxt;
        while(temp != NULL){
            Node* kth = findKthnode(temp , k);
            if(kth == NULL){
                pre->next = temp;
                break;
            }

            nxt = kth->next;
            kth->next = NULL;
            Node* reverseHead = reverse(temp);
            if(temp == head){
                head = reverseHead;
            }
            else{
                pre->next = reverseHead;
            }
            pre = temp;
            temp= nxt;
        }
        return head;
    }

    Node* gethead() const {return head;}
};

int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(3);
    l1.insert(5);
    l1.insert(2);
    l1.insert(6);
    l1.insert(4);
    
    int k = 3;
    l1.print(l1.gethead());
    cout << endl;
    Node* nh = l1.ReverseInkthorder(k);
    cout << "Reversed in groups of K." << endl;
    l1.print(nh);
}