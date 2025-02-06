#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){

    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node * temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = n;
    
}

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n -> next = head;
    head = n;
}

bool search(Node* head, int key){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){
            return true;
            break;
        }
        temp = temp -> next;
    }
    return false;
}

void deltion(Node* &head, int val){
    Node* temp = head;

    if(head == NULL) return;

    while(temp->next->data != val){
        temp = temp->next;
    }

    Node* del = temp->next;
    temp -> next = temp->next->next;
    delete del;
}

void delAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

void display(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

Node* reverse(Node* &head){ // returning linked list isliye return type Node*
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = NULL;

    while (curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* kReversal(Node* &head, int k){
    if(!head ) return NULL;

    // prev, next, curr will be same
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt = NULL;

    // make a count var to count till k
    int count = 0;

    while (curr != NULL && count < k){
        nxt = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    if(nxt != NULL){
        head->next = kReversal(nxt,k);
    }
    return prev;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    cout << "Original List: ";
    display(head);

    Node* reversedHead = reverse(head);
    cout << "Reversed List: ";
    display(reversedHead);

// for k pairs reversal;
    head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    int k = 2;
    cout << "Original List for k pair reversal: ";
    display(head);

    Node* kReversalHead = kReversal(head,k);
    cout << "List after k-group reversal (k = " << k <<"): ";
    display(kReversalHead);

    return 0;
}