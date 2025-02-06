#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert at the head
void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);
    if (head != NULL) {
        head->prev = n;
        n->next = head;
    }
    head = n;
}

// Insert at the tail
void insertAtTail(Node*& head, int val) {
    Node* n = new Node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

// Delete a node with a specific value
void deletion(Node*& head, int val) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;

    // If the node to delete is at the head
    if (temp->data == val) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// Delete from the head
void delAtHead(Node*& head) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

// Search for a value
bool search(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Display the list in forward direction
void displayForward(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display the list in backward direction
void displayBackward(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }

    Node* temp = head;
    // Go to the tail of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Insert elements
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    // Display the list forward
    cout << "Doubly Linked List (Forward): ";
    displayForward(head);

    // Display the list backward
    cout << "Doubly Linked List (Backward): ";
    displayBackward(head);

    // Search for a value
    int key = 30;
    cout << "Search for " << key << ": " << (search(head, key) ? "Found" : "Not Found") << endl;

    // Delete a specific value
    deletion(head, 30);
    cout << "After deleting 30 (Forward): ";
    displayForward(head);

    // Delete from the head
    delAtHead(head);
    cout << "After deleting at head (Forward): ";
    displayForward(head);

    return 0;
}
