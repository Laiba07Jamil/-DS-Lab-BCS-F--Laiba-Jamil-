#include <iostream>
using namespace std;
    
class Node{
    public:
    Node* next;
    int data;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList() :head(nullptr){}

    Node* gethead(){return head;}

    void insert(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            return ;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void swap(Node* a , Node* b){
        if(!a || !b){
            return;
        }
        int temp = a->data; 
        a->data = b->data;
        b->data = temp;
    }

    int getsize(){
        Node* temp = head;
        int count = 0 ;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    Node* partition(Node* low , Node* high){
        int pivot = high->data;
        Node* i = low;
        Node* j = low;

        while(j != high){
            if(j->data < pivot){
                swap(i,j);
                i = i->next;
            } 
            j = j->next;
        }
        swap(i,high);
        return i;
    }

    Node* getprev(Node* head , Node* node){
        if(!head || !node){return NULL;}
        while(head && head->next != node){
            head = head->next;
        }
        return head;
    }

    void quick(Node* low , Node* high){
        if(!low || !high || low == high || high->next == low){
            return;
        }
        Node* p = partition(low,high);
        quick(low,getprev(low,p));
        quick(p->next , high);
    }

    void sort(){   
        Node* tail = head;
        while(tail && tail->next != NULL)
            tail = tail->next;
        quick(head, tail);
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next ;
        }
        cout << endl;
    }
};

int main(){
    LinkedList l1;
    int n;
    cout << "Enter the numer of nodes: " ;
    cin >> n;
    int*arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter " << i + 1 << " Element: ";
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        l1.insert(arr[i]);
    }
    cout << "Before sorting:" << endl;

    l1.print();

    l1.sort();
    cout << "After sorting: " << endl;
    l1.print();

}
