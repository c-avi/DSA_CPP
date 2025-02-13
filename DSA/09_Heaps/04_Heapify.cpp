#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index 'i'
void heapify(int arr[], int n, int i){ // time complexity: O(log N)
    int largest = i;        // Initialize largest as root
    int left = 2 * i;       // Left child index
    int right = 2 * i + 1;  // Right child index

    // Compare with left child
    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }

    // Compare right child
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    // If the largest is not root, swap and heapify down
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursive call
    }
}



// Function to build max heap
void buildHeap(int arr[], int n){
    for (int i = n / 2; i >= 1; i--){ // Start from last non-leaf node
        heapify(arr, n, i);
    }
}

// Function to print the heap
void printHeap(int arr[], int n){
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {-1, 10, 20, 15, 30, 40}; // -1 is dummy (1-based indexing)
    int n = 5; // Number of elements in heap

    cout << "Original Array: ";
    printHeap(arr, n);

    buildHeap(arr, n);

    cout << "Max Heap: ";
    printHeap(arr, n);

    return 0;

}