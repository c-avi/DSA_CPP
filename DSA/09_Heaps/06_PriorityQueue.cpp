#include <bits/stdc++.h>
using namespace std;

int main(){
    // Max heap default
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Max Heap elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Min Heap elements: ";
    while(!minheap.empty()){
        cout << minheap.top() << " ";
        minheap.pop();
    }
    cout << endl;
    

    return 0;

}