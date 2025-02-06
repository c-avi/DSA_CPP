#include<iostream>
using namespace std;

class Stack {
public:
    int* arr;
    int top;
    int size;

    // Constructor with default size
    Stack(int s = 10) {
        size = s; // Initialize size
        arr = new int[size];
        top = -1;
    }

    // Push function
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    // Pop function
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Peek function
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1; // Return a valid error value
        }
        return arr[top]; // Return top element
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);  // Creating stack of size 5

    s.push(10);
    s.push(20);
    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    return 0;
}
