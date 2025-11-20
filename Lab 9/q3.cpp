/*Task#3: Suppose you have an AVL tree with the following nodes: 10, 5, 15, 3, and 7 (in this
order). Perform the following steps:
1. Insert the value 12 into the tree.
2. Calculate the balance factor for each node.
3. Check the height of the tree.
4. If the tree becomes unbalanced during insertion, implement the rotations required to
5. maintain balance.
6. Provide the final balanced AVL tree.*/

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

    void insertion(int v){
        root = insert(root , v);
    }
    void Inorder(){
        inorder(root);
        cout << endl;
    }

};

int main(){
    AVL tree;
    tree.insertion(10);
    tree.insertion(5);
    tree.insertion(15);
    tree.insertion(3);
    tree.insertion(7);

    cout << "Intial AVL " << endl;
    tree.Inorder();

    tree.insertion(12);
    cout << "After inserting 12 " << endl;
    tree.Inorder();
    return 0;
}