#include <iostream>
using namespace std;

class Card{
    string suit;
    int rank;
    public:
    Card(string s , int r){
        suit = s;
        rank = r;
    }
    Card(){}
    string getsuit(){return suit;}
    int getrank() { return rank;}
};

class Node{
    public:
    Node* next;
    Card card;
    Node(Card card){
        this->card = card;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(): head(nullptr){}

    Node* gethead() {return head;}
    void sethead(Node* head){head = head;}

    void insert(Card c){
        if(!head){
            Node* newnode = new Node(c);
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* newnode = new Node(c);
        temp->next = newnode;
    }

    void remove(Card c){
        if(!head){cout << "There are no cards." << endl;}
        Node* temp = head;
        while(temp->next != NULL){
            temp =temp->next;
        }
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    int getcount(){
        Node* temp = head;
        int count =0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class Player{
    public:
    string name;
    LinkedList L1;
    int points;
    Player(string s , int p){
        points = p ;
        name = s;
    }

};

int suitsrank(string suit){
    if(suit == "Club") return 4;
    else if(suit == "Spade") return 3;
    else if(suit == "Heart") return 2;
    else{
        return 1;
    }
}

int main(){
    Player player1("Laiba" , 0);
    Player player2("Absar" ,0);
    Card c("Club" , 5);
    Card c1("Spade" , 3);
    Card c2("Diamonds" , 2);
    Card c3("Spade" , 10);
    Card c4("Heart" , 11);
    Card c5("Club" , 14);
    Card c6("Heart" , 9);
    player1.L1.insert(c);
    player1.L1.insert(c1);
    player1.L1.insert(c2);
    player1.L1.insert(c3);
    player1.L1.insert(c4);
    player1.L1.insert(c5);
    player1.L1.insert(c6);

    player2.L1.insert(c3);
    player2.L1.insert(c1);
    player2.L1.insert(c2);
    player2.L1.insert(c5);
    player2.L1.insert(c6);
    player2.L1.insert(c);
    player2.L1.insert(c4);

    LinkedList list;
    Node* temp = player1.L1.gethead();
    Node* temp2 = player2.L1.gethead();
    if(temp->card.getsuit() == temp2->card.getsuit()){
        if(temp->card.getrank() < temp2->card.getrank()){
            list.insert(temp->card);
            temp =temp->next;
            player2.points += 2;
        }
        else if(temp->card.getrank() > temp2->card.getrank()){
            list.insert(temp2->card);
            temp2 = temp->next;
            player1.points += 2;
        }
    }

    if(temp->card.getsuit() != temp2->card.getsuit()){
        int tempsuit = suitsrank(temp->card.getsuit());
        int temp2suit = suitsrank(temp2->card.getsuit());
        if(tempsuit > temp2suit){
            player1.L1.insert(temp2->card);
            player1.L1.insert(temp2->card);
            player1.L1.insert(temp2->card);
            player1.points--;
            temp =temp->next;
        }
        else{
            player2.L1.insert(temp->card);
            player2.L1.insert(temp->card);
            player2.L1.insert(temp->card);
            player2.points--;
            temp = temp2->next;
        }
    }

    if(temp->card.getrank() == 14){
        player1.points += 5;
    }
    else{
        player2.points += 5;
    }
    if(player1.L1.getcount() > player2.L1.getcount()){
        player2.points -= 3;
    }
    else{
        player1.points -= 3;
    }
}
