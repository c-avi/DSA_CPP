#include<iostream>
using  namespace std;

int main(){
    int a =5;
    int b = 10;;

    //Airtmetic opertors -> + - * / %
    // a+b;
    // a-b;
    // a*b;

    // cout<<a++<<endl;
    // cout<<++a<<endl;

    //cout<< a++ + ++a<<endl;

    //cout << ans;

    //----------------------------------------------

    //Assignment operators -> = += -= *= /= %=
    a+=b;
    cout <<a<<endl;

    //---------------------------------------------

    //Relational operators -> == != > >= < <=

    // bool ans = a < b;
    // cout << ans;

    //-----------------------------------------------

    // cond1   cond2   &&  ||
    // T       T       T   T
    // T       F       F   T 
    // F       T       F   T 
    // F       F       F   F 

    //Logical operators -> && || !(decision making)
    // bool ans = (a>10) || (b<20);
    // cout << ans << endl;

    //Design a C++ program to create a simple calculator that performs basic arithmetic operations: addition, subtraction, multiplication, division, and modulus. The program should take two numbers and an operator as input from the user and display the result based on the selected operation.


    double num1, num2;
    char op;

    cout << "Simple Calculator" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> op;

    // For modulus, both numbers need to be integers
    if (op == '%') {
        int intNum1 = static_cast<int>(num1);
        int intNum2;

        cout << "Enter second number (integer): ";
        cin >> intNum2;

        if (intNum2 == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
        } else {
            cout << "Result: " << intNum1 << " % " << intNum2 << " = " << (intNum1 % intNum2) << endl;
        }
    } else {
        cout << "Enter second number: ";
        cin >> num2;

        switch (op) {
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                break;
            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                break;
            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
                }
                break;
            default:
                cout << "Error: Invalid operator." << endl;
        }
    }

}