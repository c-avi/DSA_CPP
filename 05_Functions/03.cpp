//Function overloading

#include<iostream>
using namespace std;

// void print(){
//     cout<<"1"<<endl;
// }

// void print(string name){
//     cout<<"2"<<endl;
// }

// int print(double d1){
//     return 3;
// }

// int print(double d1,int a){
//     return 4;
// }

int main(){
    // print();   

    //1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5

    // for(int i=1;i<=5;i++){//for rows
    //     for(int j=1;j<=i;j++){//for columns
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //question 2
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    
    // for(int i=5;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //pattern 3
    //     *
    //    ***
    //   *****
    //  *******
    // *********

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}