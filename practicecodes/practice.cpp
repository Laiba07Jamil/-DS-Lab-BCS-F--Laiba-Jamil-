#include<iostream>
#include<string>
using namespace std;

class Song{
    public:
    string name;
    Song* next;
    Song* prev;
    Song(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

// class DoublyLinkedList{
//     Song* head;
//     Song* current;
//     public:
//     DoublyLinkedList() : head(nullptr) , current(nullptr){}

//     void insertAtEnd(string name){
//         if(!head){
//             Song* newsong = new Song(name);
//             head = newsong;
//             current = head;
//             return;
//         }

//         Song* temp = head;
//         while(temp->next != NULL){
//             temp = temp->next;
//         }
//         Song* newsong = new Song(name);
//         temp->next = newsong;
//         newsong->prev = temp;
//     }

//     void removesong(string data){
//         if(!head){
//             cout << "List  is empty." << endl;
//         }
//         if(head->name == data){
//             Song* del = head;
//             head = head->next;
//             delete del;
//         }
        
//         Song* temp = head;
//         while(temp != NULL && temp->name != data){
//             temp = temp->next;
//         }
//         Song* del = temp;
//         if(temp->prev){
//             temp->prev->next = temp->next;
//         }
//         if(temp->next){
//             temp->next->prev =  temp->prev;
//         }
//         delete del;
//     }

//     void movetospecificsong (string data){
//         if(!head){
//             cout << "List is empty." << endl;
//         }
        
//         Song* temp = head;
//         while(temp != NULL && temp->name != data){
//             temp = temp->next;
//         }
//         if(temp != NULL){
//         cout << "Now playing" << temp->name << endl;}
//         else{
//             cout << "Song not found." << endl;
//         }
//     }

//     void movetonextsong (string data){
//         if(!head){
//             cout << "List is empty." << endl;
//         }
//         Song* temp = head;
//         while(temp != NULL && temp->name != data){
//             temp = temp->next;
//         }
//         if(temp != NULL){
//         cout << "Now playing" << temp->name << endl;}
//         else{
//             cout << "Song not found." << endl;
//         }
//         if(temp->next){
//         cout << "Next song " << temp->next->name << endl;
//         }
//         else{
//             cout << "There's no next song. " << endl;
//         }
//     }

//     void print(){
//         Song* temp = head;
//         cout << "NULL <--> ";
//         while(temp != NULL){
//             cout << temp->name << " <--> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }

//     void printcurrent(){
//         if(current != NULL){
//             cout << "Current song is " << current->name << endl;
//         }
//         else{
//             cout << "No song is playing ." << endl;
//         }
//     }
// };

// char* resize(char* arr , int older,int newsize){
//     if(older == newsize){return arr;}
//     char* newarr = new char[newsize];
//     int limits;
//     if(older < newsize){limits = older;}
//     else{limits = newsize;}
//     for(int i = 0 ; i < newsize ;i++){
//         newarr[i] = arr[i];
//     }

    
//     delete[] arr;
//     return newarr;
// }

// void reverse(char* arr , int older){
//     for(int i = older ; i >= 0 ; i--){
//         cout << arr[i] << " ";
//     }
// }

// int main(){
//     DoublyLinkedList d;
//     d.insertAtEnd("Kala chashma");
//     d.insertAtEnd("Fein");
//     d.insertAtEnd("jhumka");
//     d.insertAtEnd("gagrare");    
//     d.insertAtEnd("Jalebi");    
//     d.print();
//     d.removesong("Fein");
//     d.print();
//     d.movetospecificsong("jhumka");
//     d.movetonextsong("gagrare");
    
// }

class LinkedList{
    
    public:
    Song* head;
    LinkedList() : head(nullptr){}

    void insertAtEnd(string name){
        if(!head){
            Song* newsong = new Song(name);
            head = newsong;
            return;
        }

        Song* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Song* newsong = new Song(name);
        temp->next = newsong;
    }

    Song* Kthelement(Song* head , int k){
        Song* temp = head;
        int count = 1;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        } 
        if(temp && count == k){return temp;}
        else{return NULL;}
    }

    Song* reverse(Song* head){
        Song* temp = head;
        Song* prev = nullptr;
        while(temp != NULL){
            Song* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    } 

    Song* reverse(int start , int end){  // 1 2 3 4 5 6 7..start pos = 2 end = position 5  ->1 5 4 3 2 6 7
        if(!head){cout << "list is empty." << endl;}
        if(head->next == NULL || start == end){return head;}

        Song* dummy = head;
        Song* prev = nullptr;

        for(int i = 0 ; i < start ; i++){
            prev = prev->next;
        }
        Song* curr = prev->next;
        Song* kthnode = Kthelement(curr,end);
        Song* nxtseg = kthnode->next;
        Song* reversehead = reverse(curr);
        prev->next = reversehead;
        curr->next = nxtseg;
        head = dummy->next;
        return head; 
    }

    int lengthrecursive(int count , Song* head){
        Song* temp = head;
        if(temp == NULL){
            return count; 
        }
        return lengthrecursive(count+1 ,temp->next);
    }

    
    void printOdd(int n){
        if(n == 0){
            return ;
        }
        printOdd(n - 1);
        if(n % 2 != 0)
        cout << n << " ";
    }

    void printOdd(int n){
        if(n == 0){
            return ;
        }
        if(n % 2 != 0)
        cout << n << " ";
        printOdd(n - 1);   
    }

    string putCommas(int n){
        if(n < 1000){
            return to_string(n);
        }
        string left = putCommas(n / 1000);
        string right = to_string(n % 1000);
        while(right.length() < 3){
            right = "0" + right;
    }
        return right + "," + left;
    }

};
int main(){
    LinkedList d;
    d.insertAtEnd("dafa");
    d.insertAtEnd("egwa");
    d.insertAtEnd("aaa");
}