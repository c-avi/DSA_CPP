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

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;
    while(temp-> next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head=n;
}

void insertAtTail(Node*& head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}



void deleteAtHead(Node*& head){
    if(head == NULL) return;

    Node* temp = head;

    // If there is only one node
    if(temp->next == head){
        delete temp;
        head = NULL;
        return;
    }

    while(temp->next != head){
        temp = temp->next;
    }

    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

// delete for given position

void deleteAtPosition(Node*& head, int pos){
    if (head == NULL) return; // Empty list, nothing to delete

    if(pos == 1){ // special case for deleting the head
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count != pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    if(temp->next == head){ // Position out of bounds
        cout << "Position out of bound!" << endl;
        return;
    }

    Node* toDel = temp->next;
    temp->next = temp->next->next;
    delete toDel;
}

void display(Node* head){
    if(head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while (temp->next != head);
    cout << "HEAD" << endl;
}

int main(){
    Node* head = NULL;

    int n, val;
    cout << "Enter the number of elements to insert at tail: ";
    cin >> n;

    for(int i = 0; i < n; ++i){
        cout << "Enter value: ";
        cin >> val;
        insertAtTail(head,val);
    }

    cout << "Circular Linked List: ";
    display(head);

    cout << "Inserting at head. Enter value: ";
    cin >> val;
    insertAtHead(head,val);

    cout<<"Circular Linked List after insertion at head: ";
    display(head);

    cout << "Deleting head node." << endl;
    deleteAtHead(head);

    cout<<"Circular linked list after deleting at head: ";
    display(head);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    deleteAtPosition(head, pos);

    cout<<"Circular linked list after deletion at "<<pos<< " position: ";
    display(head);

    return 0;
   
}