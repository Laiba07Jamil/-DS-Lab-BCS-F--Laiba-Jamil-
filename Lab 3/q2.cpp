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

    Node* merged(LinkedList *l1 , LinkedList* l2){
        Node* temp1 = l1->head;
        Node* temp2 = l2->head;
        Node* mergedhead = nullptr;
        
        if(temp1->data <= temp2->data){
            mergedhead = temp1;
            temp1 = temp1->next;
        }
        else{
            mergedhead = temp2;
            temp2 = temp2->next;
        }

        Node* prev = mergedhead;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data <= temp2->data)
            {
                prev->next = temp1;
                prev = prev->next;
                temp1 = temp1->next;
            }
            else{
                prev->next = temp2;
                prev = prev->next;
                temp2 = temp2->next;
            }
        }

        if(temp1 == NULL) {
            prev->next = temp2;
        } 
        else{
            prev->next = temp1;
        }
        return mergedhead;
    }
};

int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(3);
    l1.insert(5);

    LinkedList l2;
    l2.insert(2);
    l2.insert(4);
    l2.insert(6);
    
    LinkedList mergedList;
    Node* merge = mergedList.merged(&l1 , &l2);
    mergedList.print(merge);   

}
