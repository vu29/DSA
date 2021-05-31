#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
    
    Node(int data){
        this->data = data;
    }
    Node(){}
};

void printCircular(Node* head){
    if(!head)
        return;
    cout << head->data << ' ';
    Node* temp = head->next;
    while(temp != head){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

bool isCircular(Node* head){
    if(!head)
        return true;
    
    Node* temp = head;
    while(temp){
        temp = temp->next;
        if(temp == head)
            return true;
    }
    return false;
}

void splitCircular(Node* head, Node** headRef1, Node** headRef2){
    Node *fast = head, *slow = head;
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* h2 = slow->next;

    // breaking the link from ll1 end to ll2 head
    slow->next = head;

    // assigning headRef for ll2
    *headRef2 = h2;

    while(h2->next != head){
        h2 = h2->next;
    }

    //breaking the link from ll2 end to ll1 head
    h2->next = *headRef2;

    //assignign headRef for ll1
    *headRef1 = head;
}
 

Node* deleteNode(Node* head, int val){
    if(!head)
        return head;

    Node* temp = head;

    // head in the node to be deleted
    if(temp->data == val){
        temp = temp->next;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete head;
        return temp->next;
    }
    while(temp->next != head){
        if(temp->next->data == val){
            break;
        }
        temp = temp->next;
    }

    if(temp->next->data = val){
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
    
    return head;

}


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;

    printCircular(head);
    head = deleteNode(head,2);
    printCircular(head);


}