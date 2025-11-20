#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d){
        height = 1;
        data = d;
        left = right = NULL;
    }

};

class AVL{
    Node* root;
    
    int getheight(Node* root){
        if(root == NULL){
            return 0;
        }
        return root->height;
    }

    int get_balance(Node* root){
        if(root == NULL){
            return -1;
        }
        return getheight(root->left) - getheight(root->right);
    }

    void update_height(Node* root){
        if(root == NULL){
            return ;
        }
        int l = getheight(root->left);
        int r = getheight(root->right);
        root->height = 1 + max(l ,r);
    }

    Node* leftRotation(Node* oldparent){
        Node* newleft = oldparent->right->left;
        Node* newparent = oldparent->right;

        newparent->left = oldparent;
        oldparent->right = newleft;
        update_height(oldparent);
        update_height(newparent);
        return newparent;
    }

    Node* rightRotation(Node* oldparent){
        Node* newright = oldparent->left->right;
        Node* newparent = oldparent->left;

        newparent->right = oldparent;
        oldparent->left = newright;
        update_height(newparent);
        update_height(oldparent);
        return newparent;
    }


    Node* balance(Node* root){
        int balance = get_balance(root);

        if(balance > 1 && get_balance(root->left) >= 0){
            return rightRotation(root);
        }
        if(balance > 1 && get_balance(root->left) < 0){
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        if(balance < -1 && get_balance(root->right) <= 0 ){
            return leftRotation(root);
        }

        if(balance < -1 && get_balance(root->right) > 0){
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        return root;
    }

    Node* insert(Node* root , int data){
        if(root == NULL){
            root = new Node(data);
            return root;
        }
        if(data < root->data){
            root->left = insert(root->left,data);
        }
        else if(data > root->data){
            root->right = insert(root->right,data);
        }

        update_height(root);
        return balance(root);
    }

    Node* Insertbst(Node* root , int val){
        if(root == NULL){
            return root = new Node(val);
        }
        if(val < root->data){
            root->left = insert(root->left,val);
        }
        else if(val > root->data){
            root->right = insert(root->right , val);
        }
        return root;
    }

    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    public:
    AVL() :root(nullptr){}

    Node*& getroot(){return root;}

    void insertion(int v){
        root = insert(root , v);
    }
    void Inorder(){
        inorder(root);
        cout << endl;
    }

    void insertb(int v){
        Insertbst(root,v);
    }
    
    void LR(){
        root = leftRotation(root);
    }

};

int main(){
    AVL tree;
    tree.insertion(50);
    tree.insertion(30);
    tree.insertion(70);
    tree.insertion(20);
    tree.insertion(40);
    tree.insertion(60);
    tree.insertion(80);

    cout << "AVL Tree: " << endl;
    tree.Inorder();

    tree.insertb(55);
    cout << "After inserting 55:" << endl; 
    tree.Inorder();
    cout << "Performing left rotation on root: " << endl;
    tree.LR();
    tree.Inorder();

    return 0;


}