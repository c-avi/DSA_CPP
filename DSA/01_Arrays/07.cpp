#include <iostream>
using namespace std;

// Function to find the first occurrence of the key
int findFirstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;  // Update result and search the left half
            high = mid - 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of the key
int findLastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;  // Update result and search the right half
            low = mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to calculate the total occurrences of the key
int countOccurrences(int arr[], int n, int key) {
    int firstIndex = findFirstOccurrence(arr, n, key);
    if (firstIndex == -1) {
        return 0; // Key not found
    }

    int lastIndex = findLastOccurrence(arr, n, key);
    return (lastIndex - firstIndex + 1);
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int totalOccurrences = countOccurrences(arr, n, key);

    if (totalOccurrences > 0) {
        cout << "The total number of occurrences of " << key << " is " << totalOccurrences << endl;
    } else {
        cout << key << " is not present in the array." << endl;
    }

    return 0;
}
