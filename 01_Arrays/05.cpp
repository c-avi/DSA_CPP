#include<iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    int s = 0;
    int e = size - 1;

    while (s < e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4,8,3,2,7,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    printArray(arr, size);

    reverseArray(arr, size);

    cout << "Reversed Array: ";
    printArray(arr, size);

    return 0;
    
}