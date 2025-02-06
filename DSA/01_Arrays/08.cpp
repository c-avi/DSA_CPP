// Question1:
// You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

// Example 1:
// Input:
// 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output:
// 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation:
// All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

// #include <iostream>
// using namespace std;

// void zerosAtEnd(int arr[], int n){
//     int idx=0;

//     for(int i = 0;i<n;i++){
//         if(arr[i]!=0){
//             if(i!=idx){
//                 swap(arr[idx],arr[i]);
//             }
//             idx++;
//         }
//     }
// }
// int main(){
//     int arr[8] = {1,0,2,3,0,4,0,1};
//     zerosAtEnd(arr,8);
//     for(int i=0;i<8;i++){
//         cout<<arr[i]<<" ";
//     }
// }

//Question 2

// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

// Example 1:
// Input:
// [1,2,4,7,7,5]
// Output:
// Second Smallest : 2
// Second Largest : 5
// Explanation:
// The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

// #include <iostream>
// #include <limits.h> // For INT_MAX and INT_MIN
// using namespace std;

// void findSecondSmallestAndLargest(int arr[], int n) {
//     if (n < 2) {
//         cout << "Second Smallest : -1" << endl;
//         cout << "Second Largest : -1" << endl;
//         return;
//     }

//     int smallest = INT_MAX;
//     int secondSmallest = INT_MAX;
//     int largest = INT_MIN;
//     int secondLargest = INT_MIN;

//     for (int i = 0; i < n; i++) {
//         // Update smallest and second smallest
//         if (arr[i] < smallest) {
//             secondSmallest = smallest;
//             smallest = arr[i];
//         } else if (arr[i] < secondSmallest && arr[i] != smallest) {
//             secondSmallest = arr[i];
//         }

//         // Update largest and second largest
//         if (arr[i] > largest) {
//             secondLargest = largest;
//             largest = arr[i];
//         } else if (arr[i] > secondLargest && arr[i] != largest) {
//             secondLargest = arr[i];
//         }
//     }

//     // Print results
//     cout << "Second Smallest : ";
//     if (secondSmallest == INT_MAX) {
//         cout << "-1" << endl;
//     } else {
//         cout << secondSmallest << endl;
//     }

//     cout << "Second Largest : ";
//     if (secondLargest == INT_MIN) {
//         cout << "-1" << endl;
//     } else {
//         cout << secondLargest << endl;
//     }
// }

// int main() {
//     int arr[] = {1, 2, 4, 7, 7, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     findSecondSmallestAndLargest(arr, n);

//     return 0;
// }




    

    