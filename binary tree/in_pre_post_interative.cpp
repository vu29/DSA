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
    stack <Node*> nodeStack;
    Node* current = root;

    while(current || !nodeStack.empty()){
        
        while(current){
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();

        cout << current->data << ' ';

        current = current->right;
    }
}

void preorder(Node* root){
    stack <Node*> nodeStack;
    if(root){
        nodeStack.push(root);
    }

    while(!nodeStack.empty()){
        Node* current = nodeStack.top();
        nodeStack.pop();
        cout << current->data << ' ';
        if(current->right){
            nodeStack.push(current->right);
        }

        if(current->left){
            nodeStack.push(current->left);
        }
    }
}

void postorder(Node* root){
    stack <Node*> s1;
    stack <Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }

    
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root); cout << '\n';
    preorder(root); cout << '\n';
    postorder(root); cout << '\n';
}