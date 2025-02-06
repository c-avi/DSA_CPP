// #include <iostream>
// #include <stack>
// using namespace std;

// // Helper function to remove the middle element
// void deleteMiddleHelper(stack<int>& st, int mid) {
//     if (mid == 1) {  // Base case: remove the middle element
//         st.pop();
//         return;
//     }

//     int temp = st.top();
//     st.pop();
//     deleteMiddleHelper(st, mid - 1);
//     st.push(temp);
// }

// // Function to delete middle element from stack
// void deleteMiddle(stack<int>& st) {
//     if (st.empty()) {
//         cout << "Stack is empty!" << endl;
//         return;
//     }
    
//     int mid = (st.size() / 2) + 1;  // 1-based index for middle
//     deleteMiddleHelper(st, mid);
// }

// // Function to print stack (from bottom to top)
// void printStack(stack<int> st) {
//     if (st.empty()) {
//         cout << "Stack is empty!" << endl;
//         return;
//     }

//     stack<int> temp;
//     while (!st.empty()) {
//         temp.push(st.top());
//         st.pop();
//     }

//     while (!temp.empty()) {
//         cout << temp.top() << " ";
//         temp.pop();
//     }
//     cout << endl;
// }

// int main() {
//     stack<int> st;
//     int n, val;
    
//     cout << "Enter the number of elements: ";
//     cin >> n;

//     cout << "Enter stack elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> val;
//         st.push(val);
//     }

//     cout << "Original stack: ";
//     printStack(st);

//     deleteMiddle(st);

//     cout << "Stack after deleting middle element: ";
//     printStack(st);

//     return 0;
// }

#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

// Function to print stack without modifying it
void printStack(stack<int> st) {
    if (st.empty()) {
        cout << endl;
        return;
    }

    int temp = st.top();
    st.pop();
    
    printStack(st); // Recursive call to print remaining elements

    cout << temp << " ";  // Print element after recursive call
}

int main() {
    stack<int> st;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter stack elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        st.push(val);
    }

    cout << "Original stack: ";
    printStack(st);
    cout << endl;

    reverseStack(st);

    cout << "Reversed stack: ";
    printStack(st);
    cout << endl;

    return 0;
}

