#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* parent = NULL;
    Node* leftC = NULL;
    Node* rightC = NULL;

    Node(){}
    Node(int data){
        Node::key = data;
    }
};

Node* insert(Node* root, int data){
    if(!root){
        return new Node(data);
    }
    if(data <= root->key){
        root->leftC = insert((root->leftC),data);
        root->leftC->parent = root;
    }
    else{
        root->rightC = insert((root->rightC),data);
        root->rightC->parent = root;
    }
    return root;
}

Node* search(Node* root, int data){
    if(!root || root->key == data){
        return root;
    }

    if(data < root->key){
        return search(root->leftC,data);
    }

    return search(root->rightC,data);
}

Node** searchRef(Node** rootRef, int data){
    Node* root = *rootRef;
    if(!root || root->key == data){
        return rootRef;
    }

    if(data < root->key){
        return searchRef(&root->leftC,data);
    }

    return searchRef(&root->rightC,data);
}

Node* minNode(Node* root){
    if(!root){
        return root;
    }
    Node* temp = root;
    while(temp->leftC){
        temp = temp->leftC;
    }

    return temp;
}

Node* maxNode(Node* root){
    if(!root || !root->rightC){
        return root;
    }
    return maxNode(root->rightC);
}

void inOrder(Node* root){
    if(!root){
        return;
    }

    inOrder(root->leftC);
    cout << root->key << " parent : " << root->parent << '\n';
    inOrder(root->rightC);
}

Node* successorWithoutParentPtr(Node* node, Node* root){
    if(!node)
        return node;
    
    if(node->rightC){
        return minNode(node->rightC);
    }

    if(!root){
        cout << "root can't be null" <<'\n';
        return NULL;
    }

    Node* succ = NULL;
    while(root){
        if(node->key < root->key){
            succ = root;
            root = root->leftC;
        }
        else if(node->key > root->key){
            root = root->rightC;
        }
        else
            break;
    }
    return succ;
}

Node* successorWithParentPtr(Node* node){
    if(!node)
        return node;
    
    if(node->rightC)
        return minNode(node->rightC);

    Node* _parent = node->parent;
    while(node && _parent->rightC == node){
        node = _parent;
        _parent = node->parent;
    }
    return _parent;
}

Node* predecessorWithoutParentPtr(Node* node, Node* root){
    if(!node)
        return node;
    
    if(node->leftC){
        return maxNode(node->leftC);
    }

    if(!root){
        cout << "root can't be NULL" << '\n';
        return root;
    }

    Node* pred = NULL;
    while(root){
        if(node->key < root->key){
            root = root->leftC;
        }
        else if(node->key > root->key){
            pred = root;
            root = root->rightC;
        }
        else break;
    }
    return pred;
}

Node* delNode(Node* root, int val){
    if(!root){
        return root;
    }

    if(val < root->key){
        root->leftC = delNode(root->leftC,val);
    }
    else if(val > root->key){
        root->rightC = delNode(root->rightC,val);
    }
    else{
        if(!root->leftC && !root->rightC){
            delete root;
            return NULL;
        }
        if(!root->leftC){
            Node* temp = root->rightC;
            delete root;
            return temp;
        }
        if(!root->rightC){
            Node* temp = root->leftC;
            delete root;
            return temp;
        }

        Node *succ = minNode(root->rightC);
        root->key = succ->key;
        root->rightC = delNode(root->rightC,root->key);
    }
    return root;
}


int _prev;
bool _isBST;
void _bstHelper(Node* root){
    if(!root)
        return;
    _bstHelper(root->leftC);

    int val = root->key;
    cout << val << ' ' << _prev << '\n';

    if(val < _prev){
       _isBST = false;
       _prev = INT32_MAX;
       return;
    }
    else{
        _prev = val;
    }

    _bstHelper(root->rightC);
}

bool bstOrNot(Node* root){
    if(!root)
        return true;
    _prev = INT32_MIN;
    _isBST = true;
    _bstHelper(root);
    return _isBST;
}

void _treeToBstHelper(Node* root, vector<int> &keys,bool put = false){
    if(!root)
        return;

    _treeToBstHelper(root->leftC,keys,put);
    if(put){
        root->key = keys.back();
        keys.pop_back();
    }
    else{
        keys.push_back(root->key);
        cout << root->key << "e ";
    }
    _treeToBstHelper(root->rightC,keys,put);
}

void treeToBst(Node* root){
    vector<int> keys;
    _treeToBstHelper(root,keys);
    sort(keys.begin(),keys.end(),greater<int>());
    _treeToBstHelper(root,keys,true);
}


int main(){
    Node* root = new Node(10);
    root = insert(root,9);
    root = insert(root,19);
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,11);
    root = insert(root,-20);
    root = insert(root,21);
    root = insert(root,0);

    Node *root1 = new Node(10);
    root1->leftC = new Node(9);
    root1->rightC = new Node(13);
    root1->leftC->leftC = new Node(11);
    root1->leftC->leftC->rightC = new Node(5);
    root1->leftC->leftC->rightC->leftC = new Node(14);
    root1->leftC->leftC->leftC = new Node(8);


    //inOrder(root);cout << '\n';
    //cout << predecessorWithoutParentPtr(search(root,10),root)->key << '\n';
    //cout << bstOrNot(root1) << '\n';
    inOrder(root1);
    treeToBst(root1);
    cout << "\n\n\n";
    inOrder(root1);    
}