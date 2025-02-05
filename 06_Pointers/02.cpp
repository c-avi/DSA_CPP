#include<iostream>
using namespace std;

//pass by value method (num):makes copy of num so there is different n in the memory so no effect will come on original n
//pass by referenxce(&num):original cheeze effect hongi

void test(int &num){
    ++num;
    cout << "Num value in test : " << num << endl;
}

int main(){
    int num;
    cin >> num;

    test(num);

    cout << "Final output : " << num << endl;
}

