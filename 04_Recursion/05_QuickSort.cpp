#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    // Find the pivot element (first element)
    int pivot = arr[s];

    // Count how many elements are less than or equal to pivot
    int count = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place the pivot in its correct position
    int pivotIdx = s + count;
    swap(arr[pivotIdx], arr[s]);

    // Handle the left and right parts around the pivot
    int i = s, j = e;

    while (i < pivotIdx && j > pivotIdx) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotIdx && j > pivotIdx) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIdx;
}

void quickSort(int arr[], int s, int e) {
    // Base case
    if (s >= e) return;

    // Partition the array
    int p = partition(arr, s, e);

    // Recursively sort the left and right subarrays
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[5] = {2, 1, 7, 3, 5};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
