#include <iostream>
using namespace std;

class Node{
    int ProductID;
    int quantity;
    public:
    Node* left;
    Node* right;
    Node(int id , int q){
        ProductID = id;
        quantity = q;
        left = right = NULL;
    }
    int getid(){return ProductID;}
    int get_quantity(){return quantity;}
    void set_quantity(int quantity){
        this->quantity = quantity;
    }
    void setid(int id){
        this->ProductID = id;
    }
};

class BST{
    Node* root;
    public:
    BST() : root(nullptr){}

    Node*& getroot(){return root;}

    Node* insert(Node*& root ,int id , int quantity){
        if(root == NULL){
            root =  new Node(id , quantity);
            return root;
        }

        if(id < root->getid()){
            root->left = insert(root->left,id , quantity);
        }
        else if(id > root->getid()){
            root->right = insert(root->right , id , quantity);
        }
        else{
            root->set_quantity(quantity);
        }
        return root;
    }

    

    Node* search(Node* root ,int id){
        if(root == NULL){
            return NULL;
        }
        if(root->getid() == id){
            return root;
        }
        else if(id < root->getid()){
            return search(root->left,id);
        }
        else{
            return search(root->right,id);
        }
        return NULL;
    }

    void update(Node*& root , int id , int quantity){
        if(root == NULL){
            return ;
        }
        if(root->getid() == id){
             root->set_quantity(quantity);
             return;
        }
        else if(id < root->getid()){
            return update(root->left,id,quantity);
        }
        else{
            return update(root->right,id,quantity);
        }
        
    }

    Node* highest(Node* root){
        if(root == NULL){
            return NULL;
        }
        Node* maxnode = root;
        Node* leftmax = highest(root->left);
        while(leftmax != NULL && leftmax->get_quantity() > maxnode->get_quantity()){
            maxnode = leftmax;
        }

        Node* rightmax = highest(root->right);
        while (rightmax != NULL && rightmax->get_quantity() > maxnode->get_quantity()){
            maxnode = rightmax;
        }
        return maxnode;
        
    }

    void inorder(Node* root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        cout << root->getid() << " " << root->get_quantity() << endl;
        inorder(root->right);
    }

    
};

int main(){
    BST tree;
    tree.insert(tree.getroot(),10,50);
    tree.insert(tree.getroot(),120,30);
    tree.insert(tree.getroot(),110,20);
    tree.insert(tree.getroot(),101,90);
    tree.insert(tree.getroot(),150,10);
    tree.insert(tree.getroot(),141,60);

    cout << "Initial Nodes: " << endl;
    tree.inorder(tree.getroot());
    cout << endl;

    Node* found = tree.search(tree.getroot() , 101);
    cout << "The Product ID that you search is " << found->getid() << " and quantity is " << found->get_quantity() << endl;

    tree.update(tree.getroot() , 150 , 40);
    cout << "---After Update---" << endl;
    tree.inorder(tree.getroot());
    cout << endl;

    Node* flag = tree.highest(tree.getroot());
    cout << "Highest Quantity Node ID " << flag->getid() << " and quantiy " << flag->get_quantity() << endl;
}