#include <iostream>
using namespace std;

const int TABLE_SIZE = 7;

class Node{
    public:
    string key;
    string value;
    Node* next;
    Node(string k , const string& v){
        key = k;
        value = v;
    }
};

class HashTable{
    Node* table[TABLE_SIZE];

    public:
    HashTable(){
        for(int i = 0 ; i < TABLE_SIZE ; i++){
            table[i] = nullptr;
        }
    }

    int hashfunction(string key){
        int n = key.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            char c = key[i];
            sum += c ;
        }
        return sum % TABLE_SIZE;
    }

    void insert(string key , string value){
        int index = hashfunction(key);

        Node* temp = table[index];
        while(temp != nullptr){
            if(temp->key == key){
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        Node* newnode = new Node(key , value);
        newnode->next = table[index];
        table[index] = newnode;
    }

    void traverse(){
        for(int i = 0 ; i < TABLE_SIZE ; i++){
             Node* temp = table[i];
            if(temp == NULL){
                    continue;
                }
            cout << "[" << i << "]: " ;
           
            while(temp != NULL){
                cout << "(" << temp->key << " , " << temp->value << ")" << endl;
                temp = temp->next;
            }
            
        }
    }
};

int main(){
    HashTable h;
    h.insert("A" , "aaaaa");
    h.insert("B" , "bbbbb");
    h.insert("C" , "ccccc");
    h.traverse();
    cout << "After updating value: " << endl;
    h.insert("A" , "zzzzz");
    h.traverse();
}
