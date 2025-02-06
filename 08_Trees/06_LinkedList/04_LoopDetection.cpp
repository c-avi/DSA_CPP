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

// Function to detect a loop using Flyod's cycle detection algorithm
Node* flyodLoopDetection(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return slow; // Loop detected;
    }

    return NULL; // No Loop
}

// Function to get the starting node of the loop
Node* getStartingNodeOfLoop(Node* head){
    if(head == NULL) return NULL;

    Node* intersection = flyodLoopDetection(head);
    if(intersection == NULL) return NULL; // No loop

    Node* slow = head;

    while(slow != intersection){
        slow = slow-> next;
        intersection = intersection->next;
    }

    return slow; // Starting node of the loop
}

// Function to remove the loop from linked List
void removeLoop(Node*& head){
    if(head == NULL) return;

    Node* startOfLoop = getStartingNodeOfLoop(head);
    if(startOfLoop == NULL) return; // No loop to remove

    Node* temp = startOfLoop;

    // Traverse the loop to find the last node
    while(temp -> next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL; // Break the loop
}

// Function to insert a node at the end of the Linked list
void insertAtTail(Node*& head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

// Function to display the Linked list(stops at 20 to avoid infinite loop)
void display(Node* head){
    Node* temp = head;
    int count = 0; // Safety counter to prevent infinite loops

    while(temp != NULL && count < 20){
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }

    if(count >= 20){
        cout << "LOOP DETECTED... Display Stopped." << endl;
    }else{
       cout << "NULL" <<endl; 
    }
    
}

int main(){
    Node* head = NULL;

    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for(int i = 0; i < n; ++i){
        cout << "Enter value: ";
        cin >> val;
        insertAtTail(head,val);
    }

    // Create a loop for testing
    cout<<"Creating a loop for testing..."<<endl;
    Node* temp = head;
    Node* loopStart = head;
    
    for(int i = 0; i < 2; ++i){ // Move loopStart to the 2 n0de
        loopStart = loopStart->next;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = loopStart; // Creating a loop

    // Detect and remove the loop
    if(flyodLoopDetection(head)){
        cout << "Loop detected. Removing loop..." << endl;
        removeLoop(head);
    }else{
        cout << "No loop detected." << endl;
    }

    // Display tyhe linked list after removing the loop
    cout << "Linked list after removing loop: ";
    display(head);

    return 0;
}