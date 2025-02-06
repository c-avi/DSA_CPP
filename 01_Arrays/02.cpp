#include<iostream>
#include<climits>
using namespace std;

int getMaxElement(int arr[], int size){
    int max = INT_MIN;
    for(int i = 0;i < size;i++){
        if(arr[i] > max){
            max=arr[i];
        }
    }
    return max;
}

int getMinElement(int arr[], int size){
    int min = INT_MAX;
    for(int i = 0;i < size;i++){
        if(arr[i] < min){
            min=arr[i];
        }
    }
    return min;
}

int main(){
    int arr[6] = {3,5,2,7,8,1};
    int size = 6;

    cout<<getMaxElement(arr, size);
    cout<<getMinElement(arr, size);
}