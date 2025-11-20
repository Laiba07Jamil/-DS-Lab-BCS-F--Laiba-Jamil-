
#include <iostream>
using namespace std;

class Node{
    public:
    int rollNumber;
    Node* left;
    Node* right;
    int height;
    Node(int d){
        height = 1;
        rollNumber = d;
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
        if(data < root->rollNumber){
            root->left = insert(root->left,data);
        }
        else if(data > root->rollNumber){
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
        cout << root->rollNumber << " ";
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

    int height(){
        int h = getheight(root);
        return h;
    }

};

int main(){
    AVL tree;
    tree.insertion(10);
    tree.insertion(20);
    tree.insertion(30);
    tree.insertion(40);
    tree.insertion(50);

    cout << "Initially AVL: " << endl;
    tree.Inorder();
    cout << "Height of tree: " << tree.height() << endl;

    tree.insertion(15);
    cout << "After inserting 15: " << endl;
    tree.Inorder();
    cout << "Height of tree: " << tree.height() << endl;
}

/* intitally the tree is 
          30
          /\
        20  40
        /    \
      10      50

      height = 3

      inserting 15..

      15 < 30 so move left,then 15 < 20 move left , then 15 > 10 so inserted on right
          30
          /\
        20  40
        /    \
      10      50
       \
        15

        now height = 4
        performing left rotations on 10 
          30
          /\
        20  40
        /    \
      15      50
      /
    10

    now right rotation on 20
          30
          /\
        15  40
        /\    \
      10  20    50

      now height = 3
      the tree is balanced 
      inorder traversal = 10 15 20 30 40 50
*/
