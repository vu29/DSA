#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left,*right;

    Node(int data){
        Node::data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(Node* root){
    if(!root)
        return;
    traversal(root->right);
    cout << root->data << ' ';
    traversal(root->left);
}


void zigZagTraversal(Node* root){
    if(!root)
        return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    currentLevel.push(root);
    bool l2r = false;
    while(!currentLevel.empty()){
        Node* temp = currentLevel.top();
        currentLevel.pop();
        cout << temp->data << ' ';
        if(temp->left){
            nextLevel.push( (l2r ? temp->left : temp->right) );
        }
        if(temp->right){
            nextLevel.push( (l2r ? temp->right : temp->left) );
        }

        if(currentLevel.empty()){
            swap(currentLevel,nextLevel);
            l2r = !l2r;
        }
    }
}


// void levelOrderTraversal(Node* root){
//     if(!root)
//         return;
//     queue<Node*> nextLevel;
//     nextLevel.push(root);

//     while(!nextLevel.empty()){
//         Node* temp = nextLevel.front();
//         nextLevel.pop();

//         if(temp->left){
//             nextLevel.push(temp->left);
//         }
//         if(temp->right){
//             nextLevel.push(temp->right);
//         }
//         cout << temp->data << ' ';
//     }

//     cout << '\n';
// }

void levelOrderTraversal(Node* root){
    if(!root)
        return;
    queue<Node*> tempQ;
    tempQ.push(root);
    while(!tempQ.empty()){
        Node* current = tempQ.front();
        tempQ.pop();
        cout << current->data << ' ';
        if(current->left)
            tempQ.push(current->left);
        if(current->right)
            tempQ.push(current->right);
        
    }
}


void reverseOrderTraversal(Node* root){
    if(!root)
        return;
    queue<Node*> nextLevel;
    stack<Node*> revStack;
    nextLevel.push(root);

    while(!nextLevel.empty()){
        Node* temp = nextLevel.front();
        nextLevel.pop();

        if(temp->left){
            nextLevel.push(temp->left);
        }
        if(temp->right){
            nextLevel.push(temp->right);
        }
        revStack.push(temp);
    }

    while(!revStack.empty()){
        cout << revStack.top()->data << ' ';
        revStack.pop();
    }
    cout << '\n';
}

void printLevel(Node* root, int level){
    if(!root)
        return;
    if(level == 1){
        cout << root->data << ' ';
    }
    else if(level > 1){
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

// clubbed 
void height(Node* root, int& heightVal){
    if(!root){
        return;
    }
    heightVal++;
    height(root->left, heightVal);
    height(root->right, heightVal);
}

int getHeight(Node* root){
    int heightVal = 0;
    height(root,heightVal);
    return heightVal;
}

void levelOrderT(Node *root){
    int h = getHeight(root);
    for(int i=1;i<=h;i++){
        printLevel(root,i);
    }
    cout << '\n';
}

// clubbing ends



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    //traversal(root); cout << '\n';
    //traversal(root); cout << '\n';
    levelOrderTraversal(root);cout << '\n';
    //reverseOrderTraversal(root);cout << '\n';
    //printLevel(root,3);cout << '\n';
    levelOrderT(root);
}