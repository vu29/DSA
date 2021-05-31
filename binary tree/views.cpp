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

int maxLevel;

void leftViewUtil(Node* root, int currentLevel){

    if(!root)
        return;

    if(currentLevel > maxLevel){
        cout << root->data << ' ';
        maxLevel = currentLevel;
    }

    leftViewUtil(root->left,currentLevel+1);
    leftViewUtil(root->right,currentLevel+1);
}

void leftView(Node* root){
    maxLevel = -1;
    leftViewUtil(root,0);
    cout << '\n';
}





void rightViewUtil(Node* root,int currentLevel){
    if(!root)
        return;
    
    if(currentLevel > maxLevel){
        cout << root->data << ' ';
        maxLevel = currentLevel;
    }

    rightViewUtil(root->right,currentLevel+1);
    rightViewUtil(root->left,currentLevel+1);
}

void rightView(Node* root){
    maxLevel = -1;
    rightViewUtil(root,0);
    cout << '\n';
}

void getVerticalOrder(Node* root, int hDist, map<int,vector<int>>& hDistMap){
    if(!root)
        return;
    
    hDistMap[hDist].push_back(root->data);

    getVerticalOrder(root->left,hDist-1, hDistMap);
    getVerticalOrder(root->right,hDist+1, hDistMap);
}

void getBottomVerticalNode(Node* root, int hDist, map<int,int>& hDistMap){
    if(!root)
        return;
    
    hDistMap[hDist] = root->data;

    getBottomVerticalNode(root->left, hDist-1, hDistMap);
    getBottomVerticalNode(root->right,hDist+1,hDistMap);

}

void getTopVerticalNode(Node* root, int hDist, map<int,int>& hDistMap){
    if(!root)
        return;
    
    if( hDistMap.find(hDist) == hDistMap.end()){
        hDistMap[hDist] = root->data;
    }

    getTopVerticalNode(root->left, hDist-1, hDistMap);
    getTopVerticalNode(root->right,hDist+1,hDistMap);

}

void verticalOrderTraversal(Node* root){
    map<int,vector<int>> hDistMap;
    getVerticalOrder(root,0,hDistMap);

    for(auto it = hDistMap.begin() ; it != hDistMap.end(); it++){
        for(int i = 0;i<it->second.size();i++){
            cout << it->second[i] << ' ';
        }
        cout << '\n';
    }
}


void topView(Node* root){
    map<int,int> hDistMap;
    getTopVerticalNode(root,0,hDistMap);

    for(auto it = hDistMap.begin() ; it != hDistMap.end(); it++){
        cout << it->second << '\n';
    }
}

void bottomView(Node* root){
    map<int,int> hDistMap;
    getBottomVerticalNode(root,0,hDistMap);
    
    for(auto it = hDistMap.begin(); it != hDistMap.end(); it++){
        cout << it->second << '\n';
    }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);
    root->right->left->left->left = new Node(7);


    

    cout << "Right View\n";rightView(root);

    cout << "Left View\n";leftView(root);

    cout << "Top View\n";topView(root);
    cout << '\n';

    cout << "Bottom View\n";bottomView(root);

    cout << "Vertical Order\n";verticalOrderTraversal(root);
    cout << '\n';
}

/*
            1               -> 1
          /   \
        2       3           -> 2
              /  \
            4       5       -> 3
          /
        6
       /
      7
*/