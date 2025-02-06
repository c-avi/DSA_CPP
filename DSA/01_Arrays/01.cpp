#include <iostream>
using namespace std;

int main(){

    //Array declaration
    // int arr1[5];

    //Array initialization
    int arr1[5]={6,7,3,1,9};

    // cout<<arr1[7]; //garbage value because jese hi initialize krte hain vese hi blocks assign ho jate hain and they have garbage values
    // cout<<arr1[4];

    arr1[4] = 8;

    // for(int i = 0;i < 8;i++){
    //     cout << arr1[i] << " ";
    // }

    for(auto i : arr1){
        cout<<i<<" ";
    }
    

    
}