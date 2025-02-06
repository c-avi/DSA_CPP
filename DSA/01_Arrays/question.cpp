//Take input from user of 5 numbers, store them in an array and print the numbers

#include<iostream>
using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }


}