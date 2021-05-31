#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next = NULL, *prev = NULL;
    Node(int data){
        this->data = data;
    }
};

Node* append(Node* head, int data){
    Node* newNode = new Node(data);
    if(!head){
        return newNode;
    }

    Node* temp = head;
    while(temp && temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node* head){
    while(head){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

Node* reverseIterative(Node* head){
    Node* current = head, *next = NULL;
    while(current){
        Node* next = current->next;
        current->next = current->prev;
        current->prev = next;
        if(next == NULL)
            return current;
        current = next;
    }
    return NULL;
}

Node* reverseRecursive(Node* node){
    // intresting point :: this is not the termination condition 
    if(!node){
        return NULL;
    }

    Node* next = node->next;
    node->next = node->prev;
    node->prev = next;

    if(!next){
        return node;
    }

    return reverseRecursive(next);
}

int main(){
    Node* head = new Node(1);
    for(int i=2;i<10;i++){
        head = append(head,i);
    }

    printList(head);
    head = reverseRecursive(head);
    printList(head);
}