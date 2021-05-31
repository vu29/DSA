#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(){}

    Node(int data){
        Node::data = data;
    }
};

class SingleLinkedList{
public:
    Node* head;

private:    
    Node* reverseBatchUtil(Node* head, int k){
        if(!head)
            return head;
        
        Node *prev = NULL,*current = head, *next;
        int counter = 0;

        while(current && counter < k){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            counter++;
        }

        if(current){
            head->next = reverseBatchUtil(current,k);
        }

        return prev;
    }

    bool loopExists(){
        Node *fast = head, *slow = head;

        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }

        return false;
    }


    Node* reverseRUtil(Node* node, Node** head){
        if(!node){
            return node;
        }
        else if(!node->next){
            *head = node;
            return node;
        }
        Node* nodeNext = reverseRUtil(node->next,head);
        nodeNext->next = node;
        node->next = NULL;
        return node;
    }

    int addNumUtil(Node* temp,int x){
        if(!temp)
            return x;

        temp->data += addNumUtil(temp->next,x);

        if(temp->data > 9){
            int ogData = temp->data;
            temp->data = ogData%10;
            return ogData/10;
        }
        else{
            return 0;
        }
    }


public:
    SingleLinkedList(){
        head = NULL;
    }

    void append(int data){
        if(!head){
            head = new Node(data);
            return;
        }

        if(head){
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }

            temp->next = new Node(data);
        }
    }

    void reverseBatchStack(int k){
        Node* prev = NULL, *current = head;
        stack<Node*> nodeStack;

        while(current){
            int counter = 0;
            while(current && counter < k){
                nodeStack.push(current);
                current = current->next;
                counter++;
            }

            while(!nodeStack.empty()){
                if(!prev){
                    prev = nodeStack.top();
                    head = prev;
                    nodeStack.pop();
                }
                else{
                    prev->next = nodeStack.top();
                    nodeStack.pop();
                    prev = prev->next;
                }
            }

        //prev->next = NULL;
        }
    }

    void reverseBatch(int k){
        head = reverseBatchUtil(head,k);
    }

    void reverseI(){
        Node *prev = NULL, *current, *next;
        current = head;

        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void reverseR(){
        reverseRUtil(head,&head);
    }


    void printList(){
        if(!head){
            cout << "Empty List\n";
            return;
        }
        else if(loopExists()){
            cout << "ANTON : loop exists so it's better not to print :-)\n";
            cout << "ANTON : or wait maybe you can i fix it!!\n";
            cout << "vu29 : sure buddy !! here you go\n";
            removeLoop();
        }

        Node* temp = head;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    static void printList(Node* head){
        Node* temp = head;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    static Node* startingOfLoop(Node* head, bool useHash = false){
        if(useHash){
            unordered_set<Node*> nodeSet;
            Node* tempNode = head;
            while(tempNode){
                if(nodeSet.find(tempNode) != nodeSet.end()){
                    return tempNode;
                }

                nodeSet.insert(tempNode);
                tempNode = tempNode->next;
            }

            return NULL;
        }
        else{
            Node *fast = head, *slow = head;
            while(fast && slow && fast->next){
                fast = fast->next->next;
                slow = slow->next;

                if(fast == slow)
                    break;
            }

            if(slow != fast)
                return NULL;

            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    void removeLoop(){
        Node *slow = head, *fast = head, *prev = NULL;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
                break;
        }

        if(fast != slow) return;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
    }

    void removeDuplicateInSorted(){
        if(!head)
            return;
        Node* temp = head;

        while(temp && temp->next){
            if(temp->data == temp->next->data){
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
            }
            else{
                temp = temp->next;
            }
        };
    }

    void removeDuplicateInUnsorted(){
        if(!head)
            return;
        
        Node* temp = head;
        unordered_set<int> seenData;
        seenData.insert(temp->data);
        while(temp->next){
            if(seenData.find(temp->next->data) != seenData.end()){
                Node* del = temp->next;
                temp->next = del->next;
                free(del);   
            }
            else{
                seenData.insert(temp->next->data);
                temp = temp->next;
            }
        }
    }

    void last2Front(){
        if(!head || !head->next)
            return;
        
        Node* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        
        Node* newHead = temp->next;
        temp->next = NULL;
        newHead->next = head;
        head = newHead;
    }

    void add1To9ToNumber(int x){
        stack<Node*> nodeStack;
        Node* temp = head;
        while(temp){
            nodeStack.push(temp);
            temp = temp->next;
        }

        int carry = x;

        while(!nodeStack.empty()){
            Node* current = nodeStack.top();
            nodeStack.pop();
            current->data += carry;
            if(current->data > 9){
                int ogData = current->data;
                current->data = ogData%10;
                carry = ogData/10;
            }
            else
                carry = 0;
        }
        
        if(carry && carry < 10){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        else if(carry && carry > 9){
            int d = log10(carry);
            Node* newHead = new Node();
            Node* temp = newHead;
            while(1){
                int digit = carry / (pow(10,d));
                carry = carry - (digit*pow(10,d));
                temp->data = digit;
                d--;
                if(d < 0)
                    break;
                temp->next = new Node();
                temp = temp->next;
            }
            temp->next = head;
            head = newHead;
        }
    }

    void add1To9ToNumberR(int x){
        int carry = addNumUtil(head,x);
        if(carry && carry < 10){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        else if(carry && carry > 9){
            int d = log10(carry);
            Node* newHead = new Node();
            Node* temp = newHead;
            while(1){
                int digit = carry / (pow(10,d));
                carry = carry - (digit*pow(10,d));
                temp->data = digit;
                d--;
                if(d < 0)
                    break;
                temp->next = new Node();
                temp = temp->next;
            }
            temp->next = head;
            head = newHead;
        }
    }

    Node* findMiddle(){
        Node *fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void pushFront(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void intersectionFromSortedLists(Node* h1, Node* h2){
        
        Node preHead;
        Node* temp = &preHead;
        preHead.next = NULL;

        while(h1 && h2){
            if(h1->data < h2->data){
                h1 = h1->next;
            }
            else if(h1->data > h2->data){
                h2 = h2->next;
            }
            else{
                Node* newNode = new Node(h1->data);
                temp->next = newNode;
                temp = temp->next;
                h1 = h1->next;
                h2 = h2->next;
            }
        }
        head = preHead.next;
    }

    void intersectionFromUnsortedList(Node* h1, Node* h2){
        unordered_set<int> dataSet;

        while(h1){
            dataSet.insert(h1->data);
            h1 = h1->next;
        }

        while(h2){
            if(dataSet.find(h2->data)!= dataSet.end()){
                this->append(h2->data);
            }
            h2 = h2->next;
        }
    }

    static bool yIntersectionExists(Node* h1, Node* h2){

        if(!(h1 &&h2))
            return false;

        while(h1->next){
            h1 = h1->next;
        }
        while(h2->next){
            h2 = h2->next;
        }

        return h1 == h2;
    }

    static Node* findYIntersection(Node* h1, Node* h2, int method){
        if(!yIntersectionExists(h1,h2))
            return NULL;
        
        
        Node *temp1 = h1, *temp2 = h2;
        if(method == 1){
            // METHOD 1 : 2 POINTER TECHNIQUE
            while(temp1 && temp2){
                if(temp1 == temp2)
                    break;
                temp1 = temp1->next;
                temp2 = temp2->next;

                if(!temp1){
                    temp1 = h2;
                }
                if(!temp2){
                    temp2 = h1;
                }
            }
            return temp1;
        }
        if(method == 2){
            int count1 = 0, count2 = 0;
            while(temp1){
                count1++;
                temp1 = temp1->next;
            }
            while(temp2){
                count2++;
                temp2 = temp2->next;
            }
            if(count1 < count2){
                swap(h1,h2);
            }

            temp1 = h1,temp2 = h2;
            int diff = abs(count1 - count2);

            while(diff){
                temp1 = temp1->next;
                diff--;
            }

            while(temp1 != temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            return temp1;
        }
        cout << "Method to sahi select kar tau" << '\n';
        return NULL;
    }

    void addNumberRepBy2Lists(SingleLinkedList* l1, SingleLinkedList* l2){
        l1->reverseR();
        l2->reverseR();

        Node *temp1 = l1->head;
        Node *temp2 = l2->head;

        int carry = 0;

        while(temp1 || temp2){
            int sum = carry;
            if(temp1){
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if(temp2){
                sum += temp2->data;
                temp2 = temp2->next;
            }
            
            this->append(sum%10);
            carry = sum/10;
            
        }

        if(carry)
            this->append(carry);

        this->reverseR();
    }


    bool isPalindrome(int method = 1){
        if(method == 1){
            // Time complexity : O(n)
            // Space complexity : O(n)
            if(!head)
                return false;
            stack<int> nodeStack;
            Node* temp = head;
            while(temp){
                nodeStack.push(temp->data);
                temp = temp->next;
            }
            temp = head;
            int currentData;
            while(temp){
                currentData = nodeStack.top();
                nodeStack.pop();
                if(currentData != temp->data)
                    return false;
                temp = temp->next;
            }
            return true;
        }
        else if(method == 2){
            // Time complexity : O(n)
            // Space complexity : O(1)

            if(!head)
                return false;

            Node *fast = head, *slow = head;
            while(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            Node* h2 = slow->next;
            slow->next = NULL;

            // reverse ll 2
            Node *prev = NULL, * current = h2, *next;
            Node* temp2 = h2;
            while(temp2){
                next = temp2->next;
                temp2->next = prev;
                prev = temp2;
                temp2 = next;
            }
            h2 = prev;
            // rev end

            // compare both lists
            Node* temp1 = head;
            temp2 = h2;
            while(temp2){
                if(temp1->data != temp2->data)
                    return false;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            // it is a palindrome
            printList(head);
            printList(h2);
            // reverse ll 2
            prev = NULL, current = h2, next = NULL;
            temp2 = h2;
            while(temp2){
                next = temp2->next;
                temp2->next = prev;
                prev = temp2;
                temp2 = next;
            }
            h2 = prev;
            // rev end

            slow->next = h2;
            printList(head);
            return true;
        }
        else{
            cout << "Wrong method\n";
            return false;
        }
    }
};

int main(){
    SingleLinkedList l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(3);
    l.append(2);
    l.append(1);
    
    cout << l.isPalindrome(2) << '\n';
}