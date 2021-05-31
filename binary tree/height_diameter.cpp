#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int data){
        Node::data = data;
    }
};

int height(Node* root){
    if(!root)
        return -1;
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if(lHeight > rHeight)
        return lHeight+1;
    else 
        return rHeight+1;
}

int maxNodes(Node* root){
    if(!root)
        return 0;
    
    int lHeight = maxNodes(root->left);
    int rHeight = maxNodes(root->right);

    if(lHeight > rHeight)
        return lHeight+1;
    else 
        return rHeight+1;
}

int diameter(Node* root){
    int leftMaxNodes = maxNodes(root->left);
    int rightMaxNodes = maxNodes(root->right);
    return (leftMaxNodes + rightMaxNodes + 1);
}

int Nheight(Node* root){
    if(!root)
        return -1;
    
    return max( (1+Nheight(root->left)) , (1+Nheight(root->right)) );
}

int Ndiameter(Node* root){
    int lH = maxNodes(root->left);
    int rH = maxNodes(root->right);

    return lH + rH + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(-1);
    cout << "height : " << height(root) << '\n';
    cout << "height : " << Nheight(root) << '\n';
    cout << "diameter : " << diameter(root) << '\n';
    cout << "diameter : " << Ndiameter(root) << '\n';
}