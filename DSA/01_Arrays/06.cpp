#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Recalculate mid in every iteration

        if (arr[mid] == key) {
            return mid; // Key found, return its index
        }

        // If the key is greater than mid, search in the right part
        if (key > arr[mid]) {
            start = mid + 1;
        } else { // Otherwise, search in the left part
            end = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[5] = {3, 5, 6, 7, 8}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter the key to search: ";
    int key;
    cin >> key;

    int index = binarySearch(arr, size, key);

    if (index != -1) {
        cout << "Key found at index " << index << "." << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
