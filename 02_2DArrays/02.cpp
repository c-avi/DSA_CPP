// question
// using linear search if key is present
// int arr[3][4] = {{1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,11,12}}

//question2:
//int arr[3][4] = {1,12,3,8,5,16,7,21,11,10,1,12};
//output:{1,5,11,10,16,12,3,7,1,12,21,8}

// question3:
// spiral print:
// input:
//    int arr[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
// output:
//    {1,2,3,4,5,10,15,20,25,24,23,22,21,16,11,6,7,8,9,14,19,18,17,12,13}
#include<iostream>
#include <climits>
using namespace std;

void spiralPrint(int arr[][5], int rows, int cols) {
    int topRow = 0, bottomRow = rows - 1, leftCol = 0, rightCol = cols - 1;

    while (topRow <= bottomRow && leftCol <= rightCol) {
        //toprow
        for (int i = leftCol; i <= rightCol; i++) {
            cout << arr[topRow][i]<<" ";
        }
        topRow++;

        //rightcol
        for (int i = topRow; i <= bottomRow; i++) {
            cout << arr[i][rightCol]<<" ";
        }
        rightCol--;

        //bottomrow
        if (topRow <= bottomRow) {
            for (int i = rightCol; i >= leftCol; i--) {
                cout << arr[bottomRow][i]<<" ";
            }
            bottomRow--; 
        }

        //left col
        if (leftCol <= rightCol) {
            for (int i = bottomRow; i >= topRow; i--) {
                cout << arr[i][leftCol]<<" ";
            }
            leftCol++;
            
        }
    }
}

void waveArray(int arr[][4], int rows, int cols) {

    for (int col = 0; col < cols; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col]<<" ";
            }
        } else {
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col]<<" ";
            }
        }
    }
}

bool searchKey(int arr[3][4], int key) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == key) {
                return true; // Key found
            }
        }
    }
    return false; // Key not found
}

//Find the sum of all numbers present in a 2d array
void sumArray(int arr[][4], int rows, int cols) {
    int sum = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            sum += arr[row][col];
        }
    }
    cout << sum;
}

//row having max sum. return row and row sum
void rowMax(int arr[][4], int rows, int cols) {
    int maxSum = INT_MIN,index = 0; 

    for (int r = 0; r < rows; r++) {
        int currentSum = 0; 
        for (int c = 0; c < cols; c++) {
            currentSum += arr[r][c];
        }

        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            index = r;
        }
    }
    cout << "Row: " << index << endl;
    cout << "sum: " << maxSum << endl;
 
}

int main() {
    // int arr[3][4] = {1,12,3,8,5,16,7,21,11,10,1,12};
    int arr[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    spiralPrint(arr, 5, 5);
    // waveArray(arr, 3, 4);

    // rowMax(arr, 3, 4);

    // cout<<"Enter key to search : ";
    // int key;
    // cin>>key;
    
    // if (searchKey(arr, 7)) {
    //     cout << "Key present";
    // } else {
    //     cout << "Key not present";
    // }

    return 0;
}