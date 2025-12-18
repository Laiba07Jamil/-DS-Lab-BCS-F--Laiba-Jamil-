#include <iostream>
using namespace std;

class Node{
    public:
    int days;
    Node* left;
    Node* right;
    Node(int loan){
        days = loan;
        left = right = NULL;
    }
};

class BST{
    Node* root;

    public:
    Node* prune(Node* root , int L , int R){
        if(root == NULL){
            return root;
        }
        root->right = prune(root->right,L,R);
        root->left = prune(root->left,L,R);
        if(root->days < L){
            Node* right = root->right;
            return right;
        }
        if(root->days > R){
            Node* left = root->left;
            return left;
        }
        return root;
    }

    int close(Node* root , int target){
        int near = 1000;
        int closetvalue = -1;

        while(root != NULL){
            int diff = root->days - target;
            if(diff < 0){
                diff = -(diff);
            }
            if(diff < near){
                near = diff;
                closetvalue = root->days;
            }
            if(target < root->days){
                root = root->left;
            }
            else if(target > root->days){
                root = root->right;
            }
            else{
                return root->days;
            }
        }
    }
};