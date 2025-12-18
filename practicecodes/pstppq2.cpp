#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    string data;
    int priority;
    int status;
    public:
    Node(string d , int p ,int s){
        data =d;
        priority = p;
        status = s;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
    Node* head;

    public:
    LinkedList():head(nullptr){}

    void insert(string d , int p ,int s){
        if(!head){
            Node* newnode = new Node(d,p,s);
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* newnode = new Node(d,p,s);
        temp->next = newnode;
        newnode->prev = temp;
    }

    void traverse(){
        Node* temp = head;
        while(temp->next != NULL){
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    LinkedList* serve(){
        Node* temp =head;
        LinkedList* List1;
        LinkedList* List2;
        while(temp->next != NULL){
            if(temp->priority == 1){
                List1->head->priority = temp->priority;
                temp = temp->next;
            }
            else{
                List2->head->priority = temp->priority;
                temp = temp->next;
            }
        }

        Node* curr = List1->head;

        while(curr->next != NULL){
            curr = curr->next;
    }
    curr->next = List2->head;
    return List1;
    }

    LinkedList* status(LinkedList* List){
        Node* temp = List->head;
        LinkedList* newList;
        while(temp->next != NULL){
            if(temp->status == 0){
                newList->head->status = temp->status;
            }

        }
        return newList;
    }

    void compare(LinkedList* L1 , LinkedList* L2){
        int count = 0;
        int count2 = 0;
        Node* temp = L1->head;
        Node* temp2 = L2->head;

        while(temp->next != NULL){
            count++;
            temp =temp->next;
        }
        while(temp2->next != NULL){
            count2++;
            temp2 =temp2->next;
        }

        cout << "Count of status flag with 1 is" << count << endl;
        cout << "count of status flag with 0 is " << count2 << endl;
    }
};