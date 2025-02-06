#include<iostream>
using namespace std;

int main(){
    // int arr[2][3] = {1,2,3,4,5,6};

    // int arr[3][4] = {{1,2,3,4},
    //                 {5,6,7,8},
    //                 {9,10,11,12}}

    int arr[3][4];

//taking input row wise
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 4; j++){
    //         cin >> arr[i][j];
    //     }
    // }

    // taking input column wise
    // for (int j = 0; j < 4; j++) { // Outer loop iterates over columns
    // for (int i = 0; i < 3; i++) { // Inner loop iterates over rows
    //     cin >> arr[i][j];
    // }


    //print
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}