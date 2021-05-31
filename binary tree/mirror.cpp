#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int data){
        Node::data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(!root)
        return;
    
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void mirrorify(Node* root, Node** mirror){
    if(!root){
        *mirror = NULL;
        return;
    }

    *mirror = new Node(root->data);
    mirrorify(root->left,&(*mirror)->right);
    mirrorify(root->right,&(*mirror)->left);
}

int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(8);
    root->left->left = new Node(12);
    root->right->right = new Node(9);

    inorder(root); cout << '\n';
    Node* mirrorRoot;
    mirrorify(root,&mirrorRoot);
    inorder(mirrorRoot); cout << '\n';
    
}