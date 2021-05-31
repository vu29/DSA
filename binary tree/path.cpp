#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left = NULL, *right = NULL;
    Node(){}
    Node(int data){
        Node::data = data;
    }
};

bool findPath(Node* root,vector<int>&path,int key){
    if(!root)
        return false;
    
    path.push_back(root->data);

    if(root->data == key)
        return true;

    if((root->left && findPath(root->left,path,key))  || 
        (root->right && findPath(root->right,path,key)))
            return true;
    
    path.pop_back();
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(8);

    vector<int>path;
    if(findPath(root,path,7))
        for(int i : path)
            cout << i << ' ';
    cout << '\n';
}