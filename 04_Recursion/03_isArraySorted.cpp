#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    //base case
    if(size==0 || size==1) return true;

    if(arr[0]>arr[1]){
        return false;
    }else{
        return isSorted(arr+1,size-1);
    }
}

int arraySum(int arr[], int n) {
    // Base case: If the size of the array is 0, return 0
    if (n <= 0)
        return 0;

    // Recursive relation: Sum of the last element + sum of the rest of the array
    return arr[n - 1] + arraySum(arr, n - 1);
}

int main(){
    int arr[6]={3,4,5,7,8,9};
    int arr2[6]={1,4,7,2,5,8};
    cout<<isSorted(arr,6)<<endl;
    cout<<isSorted(arr2,6)<<endl;
    cout<<"Sum of the array: "<<arraySum(arr,6);
    
}