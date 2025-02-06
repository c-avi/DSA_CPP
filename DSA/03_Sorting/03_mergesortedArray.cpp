// question:
// arr1={1,2,3,3}
// arr2={3,4,5,5,7,9}
// merge two sorted arrays 

// 

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1; // Last valid element in nums1
    int j = n - 1; // Last element in nums2
    int k = m + n - 1; // Last position in nums1

    // Merge in reverse order
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has space for nums2
    int m = 3; // Number of valid elements in nums1
    vector<int> nums2 = {2, 5, 6}; // nums2 elements
    int n = 3; // Number of elements in nums2

    merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
 Kadane's Algorithm
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN; // To store the maximum sum
    int currentSum = 0;   // To store the current subarray sum

    for (int num : nums) {
        currentSum += num;           // Add current element to the current sum
        maxSum = max(maxSum, currentSum); // Update the maximum sum if needed
        if (currentSum < 0) currentSum = 0; // Reset current sum if it drops below 0
    }

    return maxSum;
}

int main() {
    // Example 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << maxSubArray(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1};
    cout << "Maximum subarray sum: " << maxSubArray(nums2) << endl;

    // Example 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Maximum subarray sum: " << maxSubArray(nums3) << endl;

    return 0;
}
*/
