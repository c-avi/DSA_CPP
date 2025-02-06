// stack using a linked list
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push function
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Pop function
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek function
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // Return an invalid value
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function to test the stack
int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << endl; // Output: 30
    
    s.pop();
    cout << "Top element after pop: " << s.peek() << endl; // Output: 20

    s.pop();
    s.pop();
    s.pop(); // This should print "Stack Underflow"

    return 0;
}
