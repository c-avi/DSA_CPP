#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

void reversedKElementsQueue(queue<int>& q, int k) {
    if (k > q.size() || k <= 0) {
        cout << "Invalid value of k!" << endl;
        return;
    }

    stack<int> st;
    int n = q.size();

    // Push first k elements to the stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Pop from stack and enqueue back
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Move remaining elements to maintain order
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Function to print the queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, val, k;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        q.push(val);
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Original queue: ";
    printQueue(q);

    reversedKElementsQueue(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
