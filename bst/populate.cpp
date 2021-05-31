#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left = NULL, *right = NULL, *next = NULL, *parent = NULL;
    Node(){}
    Node(int data){
        Node::data  = data;
    }
};

Node* insert(Node* root, int data){
    if(!root){
        return new Node(data);
    }
    if(data <= root->data){
        root->left = insert((root->left),data);
        root->left->parent = root;
    }
    else{
        root->right = insert((root->right),data);
        root->right->parent = root;
    }
    return root;
}


Node* LCA(Node* root, int n1, int n2){
    if(!root)
        return root;

    // can add search function to remove existence clause

    if(n1 < root->data && n2 < root->data){
        return LCA(root->left,n1,n2);
    }

    if(n1 > root->data && n2> root->data){
        return LCA(root->right,n1,n2);
    }

    return root;
}


void populateNext(Node *root){
    static Node *next = NULL;
    if(!root)
        return;
    
    populateNext(root->right);
    root->next = next;
    next = root;

    populateNext(root->left);
}


Node* findMin(Node* root){
    if(!root || !root->left)
        return root;
    
    return findMin(root->left);
}

int main(){
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,19);
    root = insert(root,8);
    root = insert(root,20);
    root = insert(root,13);
    root = insert(root,9);

    cout << LCA(root,13,20)->data << '\n';
}