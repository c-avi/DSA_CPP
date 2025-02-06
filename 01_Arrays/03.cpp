#include<iostream>
using namespace std;

void updateVal(int arr[],int size){
    arr[0]=5;

    cout<<"From update method"<<endl;
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nBack to main function"<<endl;
}

int main(){
    int arr[3] = {1,2,3};

    updateVal(arr,3);

    cout<<"From main method"<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
}