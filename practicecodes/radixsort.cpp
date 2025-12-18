#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        data = data;
        next = NULL;
    }
};

void insertBucket(Node* &head , int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void Clearbucket(Node* &head){
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int getmax(int arr[], int n){
    int max = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] >= max){
            max = arr[i];
        }
    }
    return max;
}

void RadixSort(int arr[] , int n){
    Node* buckets[10];
    int exp = 1;
    int max = getmax(arr , n);
    while((exp / max) > 0){
        for(int i = 0 ; i < 10 ; i++){
            buckets[i] = NULL;
        }

        for(int i = 0 ; i < n ; i++){
            int digit = (arr[i] / exp) % 10;
            insertBucket(buckets[digit] , arr[i]);
        }
        int idx = 0;
        for(int i = 0; i < 10 ; i++){
            Node* temp = buckets[i];
            while(temp != NULL){
                arr[idx++] =temp->data;
                temp = temp->next;
            }
            Clearbucket(buckets[i]);
        }
        exp *= 10;
    }
}

void print(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}