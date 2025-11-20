#include <iostream>
using namespace std;

class Combatant{
    string name;
    int HP;
    int attack_power;
    public:
    Combatant(string n , int hp , int ap){
        name = n;
        HP = hp;
        attack_power = ap;
    }
    Combatant(){}
    string getname(){return name;}
    int getHP(){return HP;}
    int attackpower(){return attack_power;}

    void sethp(int h){
        HP = h ;
    }
    
    void display(){
        cout << "Name: " << name << endl;
        cout << "HP: " << HP << endl;
        cout << "Attack Power: " << attack_power << endl;
    }
};

class Node{
    public:
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant d){
        data = d;
        left = right = NULL;
    }

};

class BST{
    Node* root;

    Node* & getroot(){return root;}

    Node* insertion(Node* root , Combatant data){
        if(root == NULL){
            root = new Node(data);
            return root;
        }
        if(data.getname() < root->data.getname()){
            root->left = insertion(root->left , data);
        }
        else if(data.getname() > root->data.getname()){
            root->right = insertion(root->right , data);
        }
        return root;
    }

    Node* min(Node* root){
        if(root == NULL){
            return NULL;
        }
        Node* temp = root;
        while(temp != NULL && temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    Node* remove(Node* root , Combatant c){
        if(root == NULL){
            return NULL;
        }
        if(c.getname() < root->data.getname()){
            root->left =  remove(root->left , c);
        }
        else if(c.getname() > root->data.getname()){
            root->right = remove(root->right , c);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left && root->right){
                Node* dup = min(root->right);
                root->data = dup->data;
                root->right = remove(root->right , dup->data);
            }
        }
        return root;
    }

    void Inorder(Node* root){
        if(root == NULL){
            return ;
        }
        Inorder(root->left);
        cout << "Name: " << root->data.getname() << endl;
        cout << "HP: " << root->data.getHP() << endl;
        cout << "Attack Power: " << root->data.attackpower() << endl;
        Inorder(root->right);
    }

    public:
    void insert(Combatant c){
        root = insertion(root,c);
    }

    void removal(Combatant c){
        root = remove(root,c);
    }

    void inorder(){
        Inorder(root);
    }

    Node* minlef(){
        return min(root);
    }

    bool isEmpty(){
        return root == NULL;
    }
    BST() : root(nullptr){}

    Node* find(Node* root, const string& name){
    if(!root) return nullptr;
    if(name == root->data.getname()) return root;
    if(name < root->data.getname()) return find(root->left, name);
    else return find(root->right, name);
}


};

void GameFlow(BST& heroes , BST& enemies){
    int round = 1;
    while(!heroes.isEmpty() && !enemies.isEmpty()){
        cout << "------Round------" << round << endl;
        heroes.inorder();
        enemies.inorder();

        Node* hero = heroes.minlef();
        Node* emeny = enemies.minlef();
        cout << "Active Attacker: "  << endl;
        hero->data.display();
        cout << "Active Defender: " << endl;
        emeny->data.display();

        int dmg = hero->data.attackpower() + 2;
        emeny->data.sethp(emeny->data.getHP() - dmg);

        
        cout << hero->data.getname() << " attacks "<< emeny->data.getname() << " for " << dmg << " damage " << endl;
        cout << "Updated HP of " << emeny->data.getname() << " is " << emeny->data.getHP() << endl;
        if(emeny->data.getHP() <= 0){
            enemies.removal(emeny->data);
            cout << "Enemy Eliminated." << endl;
        } 


        if(enemies.isEmpty()){break;}
        emeny = enemies.minlef();
        cout << "Active Attacker: "  << endl;
        emeny->data.display();
        cout << "Active Defender: " << endl;
        hero->data.display();

        dmg = emeny->data.attackpower() + 2;
        hero->data.sethp(hero->data.getHP() - dmg);
        cout << emeny->data.getname() << " attacks " << hero->data.getname() << " for " << dmg << " damage " << endl;
        cout << "Updated HP of " << hero->data.getname() << " is " << hero->data.getHP() << endl;

        if(hero->data.getHP() <= 0 ){
            heroes.removal(hero->data);
            cout << "Player Eliminated. "<< endl;
        } 
        round++;
        cout << endl;
    }

    if(heroes.isEmpty()){
        cout << "Enemeies have won the game. " << endl;
    }
    else{
        cout << "Players have won the game. " << endl;
    }
}

int main(){
    Combatant p1("Will",10,5);
    Combatant p2("Steve",10,8);
    Combatant p3("Dustin",10,7);
    Combatant p4("Mike",10,9);
    Combatant p5("EL",10,6);
    Combatant e1("Nancy",10,7);
    Combatant e2("Bob",10,3);
    Combatant e3("Lucas",10,6);
    Combatant e4("Rider",10,5);
    Combatant e5("Daniel", 10,8);
    BST player;
    BST Enemies;
    player.insert(p1);
    player.insert(p2);
    player.insert(p3);
    player.insert(p4);
    player.insert(p5);
    Enemies.insert(e1);
    Enemies.insert(e2);
    Enemies.insert(e3);
    Enemies.insert(e4);
    Enemies.insert(e5);

    GameFlow(player,Enemies);
    return 0;
}

