#include<iostream>
using namespace std;

int main(){
    int a1 = 5;
    int a2 = 10;

    //REFERENCE
    cout << &a1 << endl; // &is going to the address where the variable is created
    // cout << &a2 << endl;

    //POINTER:is a special type of variable.
    //Pointing at some address
    //a1 = 5
    //int *ptr

    int *ptr1 = &a1; //Pointer declaration
    cout << *ptr1 << endl; //Derefrencing of Pointer:jis taraf pointer point kr rha hai uska value dega. if val assigned nhi hai to garbage val dega



}