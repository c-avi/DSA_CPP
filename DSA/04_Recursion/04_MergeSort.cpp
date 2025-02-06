#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e) {
    vector<int> temp; // Temporary array to store sorted elements

    int i = s;      // Starting index of the left subarray
    int j = mid + 1; // Starting index of the right subarray

    // Merge the two sorted subarrays
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from the right subarray
    while (j <= e) {
        temp.push_back(arr[j++]);
    }

    // Copy the sorted elements back into the original array
    for (int k = s; k <= e; k++) {
        arr[k] = temp[k - s];
    }
}

void mergeSortMethod(vector<int>& arr, int s, int e) {
    if (s >= e) return; // Base case: If the array has one or no elements, it's already sorted

    int mid = s + (e - s) / 2; // Find the middle point

    // Recursively sort the left and right halves
    mergeSortMethod(arr, s, mid);
    mergeSortMethod(arr, mid + 1, e);

    // Merge the two sorted halves
    merge(arr, s, mid, e);
}

void mergeSort(vector<int>& arr, int n) {
    mergeSortMethod(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {3, 4, 1, 6, 2, 5, 7}; // Sample input array
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, n); // Sort the array using merge sort

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
