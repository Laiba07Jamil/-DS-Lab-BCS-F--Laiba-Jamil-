#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

class BST{
    Node* root;
    public:
    BST() : root(nullptr){}

    Node*& getroot(){return root;}

    Node* insert(Node*& root ,int data){
        if(root == NULL){
            root =  new Node(data);
            return root;
        }

        if(data < root->data){
            root->left = insert(root->left,data);
        }
        else if(data > root->data){
            root->right = insert(root->right,data);
        }
        
        return root;
    }

    

    bool search(Node*& root ,int id){
        if(root == NULL){
            root = new Node(id);
            return true;
        }
        if(root->data == id){
            return root;
        }
        else if(id < root->data){
            return search(root->left,id);
        }
        else{
            return search(root->right,id);
        }
    }

    void inorder(Node* root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main(){
    BST bst;
    bst.insert(bst.getroot(),19);
    bst.insert(bst.getroot(),20);
    bst.insert(bst.getroot(),1);
    bst.insert(bst.getroot(),9);
    bst.insert(bst.getroot(),29);

    cout << "Initial Nodes: " << endl;
    bst.inorder(bst.getroot());
    bst.search(bst.getroot(),2);
    cout << endl;
    bst.inorder(bst.getroot());
    bool found = bst.search(bst.getroot(),1);
    cout << endl;
    if(found){cout << "Node found";}
    else{cout << "Not found.";}
    bst.search(bst.getroot(),100);
    cout << endl;
    bst.inorder(bst.getroot());
}
