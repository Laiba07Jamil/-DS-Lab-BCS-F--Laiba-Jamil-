#include <iostream>
using namespace std;

class Song{
    string title;
    string artist;
    string genre;
    int duration;

    public:
    Song(string t , string a ,string g ,int d){
        title = t;
        genre = g;
        artist =a ;
        duration = d;
    }

    string gettitle() {return title;}
    string getgenre() {return genre;}
    string getsrtist() {return artist;}
    int getduration() {return duration;}
    Song(){}
};

class Node{
    public:
    Song data;
    Node* next;
    Node(Song d){
        data = d;
        next = nullptr;
    }
};

class playlist{
    Node* head;
    public:
    playlist() : head(nullptr){}

    bool duplicates(string name){
        Node* temp = head;
        while(temp->next != NULL){
            if(temp->data.gettitle() == name){
                return true;
                temp = temp->next;
            }
        }
        return false;
    }

    bool adjacent(){
         Node* temp = head;
        Node* slow = head;
        Node* fast = head;
        while(temp->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            temp = temp->next;
        }
            string prev1 = slow->data.getgenre();
            string prev2 = fast->data.getgenre();
            if(prev1 == prev2){
                cout << "No consecutive Genre song are entered." << endl;
                return false;}
        return true;
    }

    bool durationrule(Song s){
        Node* temp = head;
        Node* slow = head;
        Node* fast = head;
        while(temp != NULL){
            slow = slow->next;
            fast = fast->next->next;
            temp = temp->next;
        }
        int count =0;
        if(slow != NULL && slow->data.getduration() > 600){count++;}
        if(fast != NULL && fast->data.getduration() > 600) {count++;}
        if(s.getduration() > 600){count++ ;}
        if(count == 3){
            return true;
        }
        return false;
    }

    void addsong(Song s){
        if(duplicates(s.gettitle())){
            cout << "No duplicate song are entered." << endl;
            return;
        }
        if(adjacent()){
            cout << "No consecutive genre song are entered." << endl;
            return ;
        }


        if(durationrule(s)){
            cout << "Cannot entered the song. " << endl;
            return;
        }

        Node* newnode = new Node(s);
        if(!head){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void remove (string title){
        if(!head){
            cout << "List is empty. " << endl;
        }
        if(head->data.gettitle() == title){
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "give title is deleted," << endl;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->data.gettitle() != title){
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Given title is deleetd. " << endl;

    }

    void display(){
        Node* temp = head;
        while(temp->next != NULL){
            cout << temp->data.getduration() << endl;
            cout << temp->data.getgenre() << endl;
            cout << temp->data.getsrtist() << endl;
            cout << temp->data.gettitle() << endl;
            temp = temp->next;
        }
    }

    

};