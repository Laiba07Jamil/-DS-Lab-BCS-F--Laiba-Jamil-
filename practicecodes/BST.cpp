#include <iostream>
using namespace std;
#include <queue>

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root , int data){
    if(root == NULL){
        Node* newnode = new Node(data);
        return newnode;
    }
    if(root->data > data){
        root->left = insertBST(root->left , data);
    }
    else if(root->data < data){
        root->right = insertBST(root->right , data);
    }
    return root;
}

bool search(Node* root , int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key) {
        return true;
    }
    if(root->data > key){
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
    }
    return false;
}

void inorder(Node* root){
    if(root == NULL){return ;}
    inorder(root->left);
    cout << root->data ;
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){return ;}
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

void levelorder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data;
        if(curr->left) {
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}

Node* IS(Node* root){       //inorder succesor right subtree se leftmost element ()
    if(root == NULL){
        return root;
    }
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* IP(Node* root){          // inorder predecessor left subtree se right most element
    Node* temp = root;
    if(temp == NULL){return root;}
    while(temp != NULL && temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node* root , int key){
    if(root == NULL){return root;}
    if(root->data > key){
        root->left = deleteNode(root->left , key);
    }
    else if(root->data < key){
        root->right = deleteNode(root->right , key);
    }
    else{ //found
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else {
            Node* min = IS(root->right);
            root->data = min->data;
            root->right = deleteNode(root->right , min->data);
        }
    }
    return root;
}

int countNode(Node* root){
    if(root == NULL){return 0;}
    return 1 + countNode(root->left) + countNode(root->right);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh ,rh) +1 ;
}

bool isFullBinary(Node* root){
    if(root == NULL){
        return false;
    }

    if(root->right == NULL && root->left == NULL){
        return true;
    }

    if(root->right && root->left){
        return isFullBinary(root->left) && isFullBinary(root->right);
    }
    return false;
}

bool isComplete(Node* root){
    if(root == NULL){
        return false;
    }
    queue<Node*> q;
    bool nullfound = false;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            nullfound = true;
        }
        else{
            if(nullfound){return false;}
             q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

int main(){
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes to enter: ";
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter numbers: ";
        cin >> arr[i];
    }

    for(int i = 0 ; i < n ; i++){
        root = insertBST(root , arr[i]);
    }

    cout << "Inorder: " << endl;
    inorder(root);
    cout << endl;
    Node* temp = deleteNode(root , 9);
    cout << endl;
    cout << temp->data << endl;
    cout << "Inorder: " << endl;
    inorder(root);
}